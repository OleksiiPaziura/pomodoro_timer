#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSoundEffect>

class Settings
{
public:
    static const int SEC_IN_MIN = 60;

    // Налаштування раунів
    static int round_time;
    static QSoundEffect round_sound;
    static const int DEFAULT_ROUND_TIME_IN_MIN = 25;
    static const int DEFAULT_ROUND_TIME_IN_SEC = 25 * SEC_IN_MIN;

    // Налаштування коротких перерв
    static int short_break_time;
    static QSoundEffect short_break_sound;
    static const int DEFAULT_SHORT_BREAK_TIME_IN_MIN = 5;
    static const int DEFAULT_SHORT_BREAK_TIME_IN_SEC = 5 * SEC_IN_MIN;

    // Налаштування довгих перерв
    static int long_break_time;
    static QSoundEffect long_break_sound;
    static const int DEFAULT_LONG_BREAK_TIME_IN_MIN = 15;
    static const int DEFAULT_LONG_BREAK_TIME_IN_SEC = 15 * SEC_IN_MIN;

    // Додаткові дані
    static bool is_round;
    static int current_round;
    static QString locale;
};

#endif // SETTINGS_H
