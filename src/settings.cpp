#include "settings.h"

// Налаштування раунів
int Settings::round_time = Settings::DEFAULT_ROUND_TIME_IN_SEC;
QSoundEffect Settings::round_sound;

// Налаштування коротких перерв
int Settings::short_break_time = Settings::DEFAULT_SHORT_BREAK_TIME_IN_SEC;
QSoundEffect Settings::short_break_sound;

// Налаштування довгих перерв
int Settings::long_break_time = Settings::DEFAULT_LONG_BREAK_TIME_IN_SEC;
QSoundEffect Settings::long_break_sound;

// Додаткові дані
bool Settings::is_round = false;
int Settings::current_round = 0;
QString Settings::locale = "en";
