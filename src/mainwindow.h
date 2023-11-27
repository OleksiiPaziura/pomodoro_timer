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
    Settings::Pomodoro current_round; // Раунд, що зараз триває

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

    QFrame *rounds;				// Контейнер, що містить раунди
    QRadioButton *first_round;  // Перший раунд
    QRadioButton *second_round; // Другий раунд
    QRadioButton *third_round;  // Третій раунд
    QRadioButton *fourth_round; // Четвертий раунд

    /// TIMERS
    QTimer *round_timer;		// Таймер для раундів
    QTimer *short_break_timer;	// Таймер для коротких перерв
    QTimer *long_break_timer;	// Таймер для довгих перерв
    int timeout_counter;		// Лічильник секунд таймеру раундів
    int pause_counter;			// Лічильник для контролю кнопки start_btn

public:
    MainWindow(QWidget *parent = nullptr);

    // Функція для конвертування секунд у формат mm:ss
    QString convertTime(int total_seconds);

public slots:
    void startTimer();			// Старт/Пауза/Продовження таймеру
    void stopTimer();			// Зупинка таймеру

    void onRoundTimeout();		// Цикл програми під час раунда
    void onShortBreakTimeout();	// Цикл програми під час короткої перерви
    void onLongBreakTimeout();	// Цикл програми під час довгої перерви
    void onDialChange(int);		// Інтерактивна обробка візуального відображення таймеру

    void openSettings();		// Відкриття вікна налаштувань
    void openCredits();			// Відкриття вікна інформації про додаток
};
#endif // MAINWINDOW_H
