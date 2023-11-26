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



    // WIDGETS
    start_btn = new QPushButton("Start");



    // LAYOUTS
    central_widget = new QWidget;
    main_layout = new QVBoxLayout;
    setCentralWidget(central_widget);
    central_widget->setLayout(main_layout);

    main_layout->addWidget(start_btn);


    // CONNECTIONS
    connect(settings_action, SIGNAL(triggered()), this, SLOT(openSettings()));
    connect(credits_action, SIGNAL(triggered()), this, SLOT(openCredits()));

    connect(start_btn, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void MainWindow::startTimer()
{
    timer->start(1000);

    qDebug() << "Pomodoro: " + QString::number(Settings::pomodoro_time) + "\n";
    qDebug() << "Short: " + QString::number(Settings::short_break_time) + "\n";
    qDebug() << "Long: " + QString::number(Settings::long_break_time) + "\n";
}

void MainWindow::onTimeout()
{
    qDebug() << QString::number(timeout_counter + 1) + " sec";

    if (++timeout_counter >= Settings::pomodoro_time)
    {
        timeout_counter	= 0;
        Settings::current_sound.play();
        timer->stop();
    }
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

