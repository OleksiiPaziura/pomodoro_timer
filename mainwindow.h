#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtWidgets>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVBoxLayout *main_layout;
    QPushButton *btn;
    QPushButton *auto_close_btn;

    QTimer *timer;
    int timeout_counter;

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void auto_close();
    void onTimeout();
};
#endif // MAINWINDOW_H
