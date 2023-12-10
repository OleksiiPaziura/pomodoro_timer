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
    enum StartButtonState
    {
        Start,
        Pause,
        Continue
    } start_btn_state;

    Settings::Pomodoro current_round; // Раунд, що зараз триває

    /// LAYOUTS
    QVBoxLayout *main_layout;	// Головний макет
    QHBoxLayout *rounds_layout; // Макет для відображення раундів

    /// MENU
    QMenu *menu;				// Меню зверху програми
    QAction *settings_action;	// Елемент меню для відкриття налаштувань
    QAction *credits_action;	// Елемент меню для виведення інформації про додаток
    QAction *statistics_action;	// Елемент меню для виведення інформації про поточні статистичні дані

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

    /// TRAY
    QSystemTrayIcon *tray;
    QMenu *tray_menu;
    QAction *tray_exit;

    /// LOCALE
    QTranslator translator;

public:
    MainWindow(QWidget *parent = nullptr);

    // Функція для конвертування секунд у формат mm:ss
    QString convertTime(int total_seconds, bool with_letters = false);
    void loadSettings();
    void reloadScreen();
    void checkDate();

public slots:
    void startTimer();			// Старт/Пауза/Продовження таймеру
    void stopTimer();			// Зупинка таймеру

    void onRoundTimeout();		// Цикл програми під час раунда
    void onShortBreakTimeout();	// Цикл програми під час короткої перерви
    void onLongBreakTimeout();	// Цикл програми під час довгої перерви
    void onDialChange(int);		// Інтерактивна обробка візуального відображення таймеру

    void openSettings();		// Відкриття вікна налаштувань
    void openCredits();			// Відкриття вікна інформації про додаток
    void openStatistics();		// Відкриття вікна статистичних даних

    void exitApplication();

    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
