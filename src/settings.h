#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSoundEffect>
#include <QPalette>

class Settings
{
public:
    static const int SEC_IN_MIN = 60;
    enum Pomodoro
    {
        Round,
        ShortBreak,
        LongBreak
    };
    static enum TrayEnabled
    {
        Enabled,
        Disabled,
        Postponed
    } is_tray_enabled;

    // Налаштування раунів
    static int round_time;
    static QSoundEffect round_sound;
    static const int DEFAULT_ROUND_TIME_IN_MIN = 25;
    static const int DEFAULT_ROUND_TIME_IN_SEC = 25 * SEC_IN_MIN;
    static QPalette round_color;

    // Налаштування коротких перерв
    static int short_break_time;
    static QSoundEffect short_break_sound;
    static const int DEFAULT_SHORT_BREAK_TIME_IN_MIN = 5;
    static const int DEFAULT_SHORT_BREAK_TIME_IN_SEC = 5 * SEC_IN_MIN;
    static QPalette short_break_color;

    // Налаштування довгих перерв
    static int long_break_time;
    static QSoundEffect long_break_sound;
    static const int DEFAULT_LONG_BREAK_TIME_IN_MIN = 15;
    static const int DEFAULT_LONG_BREAK_TIME_IN_SEC = 15 * SEC_IN_MIN;
    static QPalette long_break_color;

    // Теми
    static enum Themes
    {
        SimpleDark,
        SimpleLight,
        Default
    } current_theme;

    // Статистичні дані
    static int total_rounds;
    static int total_seconds;
    static int today_rounds;
    static int today_seconds;
    static int weekly_rounds;
    static int weekly_seconds;
    static int monthly_rounds;
    static int monthly_seconds;
    static int annual_rounds;
    static int annual_seconds;

    // Додаткові дані
    static QString locale;
    static bool is_notification_enabled;
};

#endif // SETTINGS_H
