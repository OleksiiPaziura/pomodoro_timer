#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // WINDOW SETTINGS
    setFixedSize(400, 400);

    timer = new QTimer(this);
    menu = new QMenu("File");
    settings_action = new QAction("Settings");
    credits_action = new QAction("Credits");
    menu->addAction(settings_action);
    menu->addAction(credits_action);
    menuBar()->addMenu(menu);




    // SETTINGS
    Settings::pomodoro_time = 5;
    Settings::current_sound.setSource(QUrl::fromLocalFile("../sounds/sound.wav"));
    timeout_counter = 0;
    pause_counter = 0;



    // WIDGETS
    dial = new QDial;
    dial->setRange(0, Settings::pomodoro_time);

    time_left = new QLabel;
    time_left->setAlignment(Qt::AlignCenter);
    time_left->setFont(QFont("Arial", 20));
    time_left->setMaximumHeight(25);

    start_btn = new QPushButton("Start");
    stop_btn = new QPushButton("Stop");



    // LAYOUTS
    central_widget = new QWidget;
    main_layout = new QVBoxLayout;
    setCentralWidget(central_widget);
    central_widget->setLayout(main_layout);

    main_layout->addWidget(time_left);
    main_layout->addWidget(dial);
    main_layout->addWidget(start_btn);
    main_layout->addWidget(stop_btn);


    // CONNECTIONS
    connect(settings_action, SIGNAL(triggered()), this, SLOT(openSettings()));
    connect(credits_action, SIGNAL(triggered()), this, SLOT(openCredits()));

    connect(start_btn, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(stop_btn, SIGNAL(clicked()), this, SLOT(stopTimer()));
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    connect(dial, SIGNAL(valueChanged(int)), this, SLOT(onDialChange(int)));
}

void MainWindow::startTimer()
{

//    if (timeout_counter == 0)
//    {
//        timer->start(1000);
//        start_btn->setText("Pause");
//    }
    ++pause_counter;
    if (timeout_counter == 0 || pause_counter % 2 == 0)
    {
        timer->start(1000);
        start_btn->setText("Pause");
    }
    else if (pause_counter % 2 != 0)
    {
        timer->stop();
        start_btn->setText("Continue");
    }
}

void MainWindow::stopTimer()
{
    timer->stop();
    timeout_counter	= 0;
    time_left->setText("0");
    dial->setValue(0);
    start_btn->setText("Start");
}

void MainWindow::onTimeout()
{
    dial->setValue(++timeout_counter);
    time_left->setText(QString::number(Settings::pomodoro_time - timeout_counter));

    if (timeout_counter > Settings::pomodoro_time)
    {
        timeout_counter	= 0;
        time_left->setText("0");
        dial->setValue(0);
        start_btn->setText("Start");

        Settings::current_sound.play();
        timer->stop();
    }
}

void MainWindow::onDialChange(int value)
{
    timeout_counter = dial->value();
    time_left->setText(QString::number(Settings::pomodoro_time - timeout_counter));
}

void MainWindow::openSettings()
{
    Settings::current_sound.stop();
    SettingsForm *sf = new SettingsForm;
    sf->setModal(true);
    sf->show();
}

void MainWindow::openCredits()
{
    QMessageBox::information(this, "Credits", "Version: 0.0.1\nCreated by: Oleksii Paziura");
}

