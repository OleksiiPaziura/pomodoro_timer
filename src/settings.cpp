#include "settings.h"

// Налаштування раунів
int Settings::round_time = Settings::DEFAULT_ROUND_TIME_IN_SEC;
QSoundEffect Settings::round_sound;
QPalette Settings::round_color = QPalette("#5499DE");

// Налаштування коротких перерв
int Settings::short_break_time = Settings::DEFAULT_SHORT_BREAK_TIME_IN_SEC;
QSoundEffect Settings::short_break_sound;
QPalette Settings::short_break_color = QPalette("#66DE6C");

// Налаштування довгих перерв
int Settings::long_break_time = Settings::DEFAULT_LONG_BREAK_TIME_IN_SEC;
QSoundEffect Settings::long_break_sound;
QPalette Settings::long_break_color = QPalette("#DCDE66");

// Додаткові дані
bool Settings::is_round = false;
Settings::TrayEnabled Settings::is_tray_enabled = Settings::Postponed;
QString Settings::locale = "en";
