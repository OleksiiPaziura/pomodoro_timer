#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtWidgets>
#include <QTimer>
#include <QSoundEffect>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVBoxLayout *main_layout;

    QLineEdit *time_edit;
    QPushButton *start_btn;

    QSoundEffect sound;

    QTimer *timer;
    int timeout_counter;

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void startTimer();
    void onTimeout();
};
#endif // MAINWINDOW_H
