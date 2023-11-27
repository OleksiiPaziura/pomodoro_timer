#include "settings.h"

int Settings::round_time = Settings::DEFAULT_ROUND_TIME * Settings::SEC_IN_MIN;
int Settings::short_break_time = Settings::DEFAULT_SHORT_BREAK_TIME * Settings::SEC_IN_MIN;
int Settings::long_break_time = Settings::DEFAULT_LONG_BREAK_TIME * Settings::SEC_IN_MIN;
QSoundEffect Settings::current_sound;
QString Settings::locale = "en";
bool Settings::is_round = false;
int Settings::current_round = 0;
