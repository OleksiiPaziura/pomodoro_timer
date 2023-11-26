#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSoundEffect>

class Settings : QObject
{
    Q_OBJECT

public:
    static int pomodoro_time;
    static int short_break_time;
    static int long_break_time;
    static QSoundEffect current_sound;
};

#endif // SETTINGS_H
