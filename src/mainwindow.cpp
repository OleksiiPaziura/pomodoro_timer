#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // BASE SETTINGS
    QWidget *central_widget = new QWidget;
    main_layout = new QVBoxLayout;
    timeout_counter = 0;

    sound.setSource(QUrl::fromLocalFile("../sounds/sound.wav"));



    // WIDGETS
    time_edit = new QLineEdit;
    time_edit->setPlaceholderText("Set time");
    time_edit->setValidator(new QIntValidator);

    start_btn = new QPushButton("Stop in seconds");



    // LAYOUTS
    setCentralWidget(central_widget);
    central_widget->setLayout(main_layout);

    main_layout->addWidget(time_edit);
    main_layout->addWidget(start_btn);

    timer = new QTimer(this);


    // CONNECTIONS
    connect(start_btn, SIGNAL(clicked()), this, SLOT(startTimer()));

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void MainWindow::startTimer()
{
    timer->start(1000);
}

void MainWindow::onTimeout()
{
    qDebug() << QString::number(timeout_counter + 1) + " sec";

    if (++timeout_counter >= time_edit->text().toInt())
    {
        timeout_counter	= 0;
        sound.play();
        timer->stop();
    }
}

