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
    /// LAYOUTS
    QVBoxLayout *main_layout;	// Головний макет
    QHBoxLayout *rounds_layout; // Макет для відображення раундів

    /// MENU
    QMenu *menu;				// Меню зверху програми
    QAction *settings_action;	// Елемент меню для відкриття налаштувань
    QAction *credits_action;	// Елемент меню для виведення інформації про додаток

    /// WIDGETS
    QLabel *time_left;			// Помітка скільки часу лишилось до кінця раунда чи перерви
    QDial *dial;				// Візуальне відображення статус-бару
    QPushButton *start_btn;		// Кнопка для старту таймеру
    QPushButton *stop_btn;		// Кнопка для зупинки таймеру

    QGroupBox *rounds;			// Контейнер, що містить раунди
    QRadioButton *first_round;  // Перший раунд
    QRadioButton *second_round; // Другий раунд
    QRadioButton *third_round;  // Третій раунд
    QRadioButton *fourth_round; // Четвертий раунд

    /// TIMERS
    QTimer *timer;				// Головний таймер
    int timeout_counter;		// Лічильник секунд
    int pause_counter;			// Лічильник для контролю кнопки start_btn

public:
    MainWindow(QWidget *parent = nullptr);

    // Функція для конвертування секунд у формат mm:ss
    QString convertTime(int total_seconds);

public slots:
    void startTimer();			// Старт/Пауза/Продовження таймеру
    void stopTimer();			// Зупинка таймеру

    void onTimeout();			// Головний цикл програми при включеному таймері
    void onDialChange(int);		// Інтерактивна обробка візуального відображення таймеру
    void onRoundChange(bool); 	// Обробка зміни раунду

    void openSettings();		// Відкриття вікна налаштувань
    void openCredits();			// Відкриття вікна інформації про додаток
};
#endif // MAINWINDOW_H
