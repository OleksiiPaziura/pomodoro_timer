#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /// BASE INITS
    setFixedSize(300, 400);
    setPalette(Settings::round_color);

    QWidget *central_widget = new QWidget;
    main_layout = new QVBoxLayout;
    rounds_layout = new QHBoxLayout;
    setCentralWidget(central_widget);
    central_widget->setLayout(main_layout);

    Settings::round_sound.setSource(QUrl::fromLocalFile("../sounds/sound.wav"));
    timeout_counter = 0;
    pause_counter = 0;
    break_counter = 0;
    is_break = false;
    round_timer = new QTimer(this);
    break_timer = new QTimer(this);


    menu = new QMenu("File");
    settings_action = new QAction(tr("Settings"));
    credits_action = new QAction(tr("Credits"));
    menu->addAction(settings_action);
    menu->addAction(credits_action);
    menuBar()->addMenu(menu);



    /// WIDGETS
    dial = new QDial;
    dial->setMinimumHeight(250);
    dial->setRange(0, Settings::round_time);

    time_left = new QLabel(convertTime(Settings::round_time));
    time_left->setAlignment(Qt::AlignCenter);
    time_left->setFont(QFont("Arial", 20));
    time_left->setMaximumHeight(25);

    start_btn = new QPushButton(tr("Start"));
    start_btn->setMinimumWidth(150);
    start_btn->setMinimumHeight(25);
    stop_btn = new QPushButton(tr("Stop"));
    stop_btn->setMinimumWidth(150);
    stop_btn->setMinimumHeight(25);

    rounds = new QFrame;
    rounds->setLayout(rounds_layout);
    rounds->setMaximumHeight(35);
    rounds->setMaximumWidth(100);
    first_round = new QRadioButton;
    first_round->setChecked(true);
    second_round = new QRadioButton;
    third_round = new QRadioButton;
    fourth_round = new QRadioButton;



    /// LAYOUTS
    // ROUNDS_LAYOUT
    rounds_layout->addWidget(first_round);
    rounds_layout->addWidget(second_round);
    rounds_layout->addWidget(third_round);
    rounds_layout->addWidget(fourth_round);

    // MAIN_LAYOUT
    main_layout->addWidget(time_left);
    main_layout->addWidget(dial);
    main_layout->addWidget(rounds, 0, Qt::AlignCenter);
    main_layout->addWidget(start_btn, 0, Qt::AlignCenter);
    main_layout->addWidget(stop_btn, 0, Qt::AlignCenter);



    /// CONNECTIONS
    // Обробка натискання на пункти меню
    connect(settings_action, SIGNAL(triggered()), this, SLOT(openSettings()));
    connect(credits_action, SIGNAL(triggered()), this, SLOT(openCredits()));

    // Робота з таймером
    connect(start_btn, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(stop_btn, SIGNAL(clicked()), this, SLOT(stopTimer()));
    connect(round_timer, SIGNAL(timeout()), this, SLOT(onRoundTimeout()));
    connect(break_timer, SIGNAL(timeout()), this, SLOT(onBreakTimeout()));

    // Обробки змін
    connect(dial, SIGNAL(valueChanged(int)), this, SLOT(onDialChange(int)));
}

// Функція для конвертування секунд у формат mm:ss
QString MainWindow::convertTime(int total_seconds)
{
    QString minutes = QString::number(total_seconds / 60);
    QString seconds = QString::number(total_seconds % 60);

    if (minutes.size() == 1)
        minutes.push_front("0");

    if (seconds.size() == 1)
        seconds.push_front("0");

    return minutes + ":" + seconds;
}

// Старт/Пауза/Продовження таймеру
void MainWindow::startTimer()
{
    Settings::is_round = true;

    if (start_btn->text() == tr("Start"))
    {
        if (is_break)
        {
            dial->setRange(0, Settings::short_break_time);
            break_timer->start(1000);
        }
        else
        {
            dial->setRange(0, Settings::round_time);
            round_timer->start(1000);
        }

        start_btn->setText(tr("Pause"));
    }
    else
    {
        if (++pause_counter % 2 == 0)
        {
            if (is_break)
                break_timer->start(1000);
            else
                round_timer->start(1000);
            start_btn->setText(tr("Pause"));
        }
        else
        {
            break_timer->stop();
            round_timer->stop();
            start_btn->setText(tr("Continue"));
        }
    }
}

// Зупинка таймеру
void MainWindow::stopTimer()
{
    round_timer->stop();
    break_timer->stop();
    timeout_counter	= 0;
    break_counter = 0;
    time_left->setText(convertTime(Settings::round_time - timeout_counter));
    dial->setValue(0);
    start_btn->setText(tr("Start"));
    Settings::is_round = false;
}

// Головний цикл програми при включеному таймеру
void MainWindow::onRoundTimeout()
{
    setPalette(Settings::round_color);
    dial->setRange(0, Settings::round_time);

    Settings::is_round = true;
    dial->setValue(++timeout_counter);
    time_left->setText(convertTime(Settings::round_time - timeout_counter));

    if (timeout_counter > Settings::round_time)
    {
        setPalette(Settings::short_break_color);
        dial->setRange(0, Settings::short_break_time);
        is_break = true;

        if (first_round->isChecked())
        {
            first_round->setChecked(false);
            second_round->setChecked(true);

            break_timer->start(1000);
        }
        else if (second_round->isChecked())
        {
            second_round->setChecked(false);
            third_round->setChecked(true);

            break_timer->start(1000);
        }
        else if (third_round->isChecked())
        {
            third_round->setChecked(false);
            fourth_round->setChecked(true);

            break_timer->start(1000);
        }
        else if (fourth_round->isChecked())
        {
            fourth_round->setChecked(false);
            first_round->setChecked(true);
        }

        timeout_counter	= 0;
        time_left->setText(convertTime(Settings::round_time - timeout_counter));
        dial->setValue(0);
        Settings::short_break_sound.play();
        round_timer->stop();
    }
}

void MainWindow::onBreakTimeout()
{
    setPalette(Settings::short_break_color);
    dial->setRange(0, Settings::short_break_time);

    Settings::is_round = true;
    dial->setValue(++break_counter);
    time_left->setText(convertTime(Settings::short_break_time - break_counter));

    if (break_counter > Settings::short_break_time)
    {
        break_counter = 0;
        dial->setValue(0);
        start_btn->setText(tr("Start"));
        Settings::round_sound.play();
        Settings::is_round = false;
        break_timer->stop();

        setPalette(Settings::round_color);
        dial->setRange(0, Settings::round_time);
        time_left->setText(convertTime(Settings::round_time - timeout_counter));
        is_break = false;
    }
}

// Інтерактивна обробка візуального відображення таймеру
void MainWindow::onDialChange(int value)
{
    if (is_break)
    {
        break_counter = dial->value();
        time_left->setText(convertTime(Settings::short_break_time - value));
    }
    else
    {
        timeout_counter = dial->value();
        time_left->setText(convertTime(Settings::round_time - value));
    }
}

// Відкриття вікна налаштувань
void MainWindow::openSettings()
{
    Settings::round_sound.stop();
    Settings::short_break_sound.stop();
    Settings::long_break_sound.stop();

    SettingsForm *sf = new SettingsForm;
    sf->setModal(true);
    sf->show();
}

// Відкриття вікна інформації про додаток
void MainWindow::openCredits()
{
    QMessageBox::information(this, tr("Credits"), tr("Version: 0.0.1\nCreated by: Oleksii Paziura"));
}
