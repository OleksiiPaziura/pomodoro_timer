#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // BASE SETTINGS
    QWidget *central_widget = new QWidget;
    main_layout = new QVBoxLayout;
    timeout_counter = 0;



    // WIDGETS
    btn = new QPushButton("Stop");
    auto_close_btn = new QPushButton("Stop in 3 seconds");



    // LAYOUTS
    setCentralWidget(central_widget);
    central_widget->setLayout(main_layout);

    main_layout->addWidget(btn);
    main_layout->addWidget(auto_close_btn);

    timer = new QTimer(this);


    // CONNECTIONS
    connect(btn, SIGNAL(clicked()), this, SLOT(close()));
    connect(auto_close_btn, SIGNAL(clicked()), this, SLOT(auto_close()));

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void MainWindow::auto_close()
{
    timer->start(1000);
}

void MainWindow::onTimeout()
{
    qDebug() << QString::number(timeout_counter);

    if (++timeout_counter >= 5)
    {
        timeout_counter	= 0;
        //close();
    }
}

