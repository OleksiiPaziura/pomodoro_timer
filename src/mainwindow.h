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
    // Стан кнопки "Старт"
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
    QMenu *edit_menu;			// Випадаючий пункт меню для налаштувань
    QAction *settings_action;	// Елемент меню для відкриття налаштувань

    QMenu *themes_menu;				// Випадаючий пункт меню для тем
    QAction *reset_theme;			// Елемент меню для скидання теми
    QMenu *set_theme;				// Випадаючий пункт меню для вибору теми
    QAction *contrast_theme;		// Тема "Contrast"
    QAction *simple_light_theme;	// Тема "SimpleLight"
    QAction *pomodoro_mode_theme;	// Тема "PomodoroMode"

    QMenu *help_menu;			// Випадаючий пункт меню для справочної інформації
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
    QSystemTrayIcon *tray;		// Трей
    QMenu *tray_menu; 			// Контекстне меню трею
    QAction *tray_exit;			// Дія контекстного меню, що закриває застосунок

    /// LOCALE
    QTranslator translator;		// Перекладач програми

public:
    MainWindow(QWidget *parent = nullptr);

    // Функція для конвертування секунд у формат mm:ss
    QString convertTime(int total_seconds, bool with_letters = false);

    void loadSettings();		// Завантаження налаштувань
    void reloadScreen();		// Оновлення екрану для роботи QTranslator
    void updateStatistics();	// Оновлення статистичних даних
    void loadStatistics();		// Завантаження статистичних даних
    void widgetsInit();			// Ініціалізація віджетів
    void connectionsInit();		// Ініціалізація сигналів і слотів
    void menuInit();			// Ініціалізація верхнього меню
    void layoutsInit();			// Ініціалізація макетів
    void layoutsFill();			// Наповенння макетів віджетами
    void timersInit();			// Ініціалізація таймерів
    void baseInit();			// Базова ініціалізація вікна і тд
    void trayInit();			// Ініціалізація трею

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

    void exitApplication();		// Вихід з застосунку

    void changeTheme(Settings::Themes theme_name); // Обробник подій для зміни теми

    // Обробник подій при натисканні на іконку трею
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

protected:
    // Обробник закриття вікна
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
