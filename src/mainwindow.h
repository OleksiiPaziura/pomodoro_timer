#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings.h"
#include "settings_form.h"
#include <QtWidgets>
#include <QSoundEffect>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVBoxLayout *main_layout;
    QWidget *central_widget;

    QMenu *menu;
    QAction *settings_action;
    QAction *credits_action;

    QLabel *time_left;
    QDial *dial;
    QGroupBox *rounds;
    QPushButton *start_btn;
    QPushButton *stop_btn;

    QTimer *timer;
    int timeout_counter;
    int pause_counter;

public:
    MainWindow(QWidget *parent = nullptr);
    QString convertTime(int total_seconds);

public slots:
    void startTimer();
    void stopTimer();

    void onTimeout();
    void onDialChange(int value);

    void openSettings();
    void openCredits();
};
#endif // MAINWINDOW_H
