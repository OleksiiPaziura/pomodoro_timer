#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSoundEffect>

class Settings
{
public:
    static int round_time;
    static int short_break_time;
    static int long_break_time;
    static QSoundEffect current_sound;
    static QString locale;
    static bool is_round;
    static int current_round;

    static const int SEC_IN_MIN = 60;
    static const int DEFAULT_ROUND_TIME = 25;
    static const int DEFAULT_SHORT_BREAK_TIME = 5;
    static const int DEFAULT_LONG_BREAK_TIME = 15;
};

#endif // SETTINGS_H
