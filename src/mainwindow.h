#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtWidgets>
#include <QTimer>
#include <QSoundEffect>

#include "settings.h"
#include "settings_form.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVBoxLayout *main_layout;
    QWidget *central_widget;

    QMenu *menu;
    QAction *settings_action;
    QAction *credits_action;

    QPushButton *start_btn;

    QTimer *timer;
    int timeout_counter;

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void startTimer();
    void onTimeout();

    void openSettings();
    void openCredits();
};
#endif // MAINWINDOW_H
