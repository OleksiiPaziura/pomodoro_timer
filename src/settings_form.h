#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include "settings.h"
#include <QtWidgets>

class SettingsForm : public QDialog
{
    Q_OBJECT

private:
    /// CONSTANTS
    // Кількість відтворюваних можливих хвилин для встеновлення
    const int SLIDER_MINS = 5 * Settings::SEC_IN_MIN;

    /// LAYOUTS
    QVBoxLayout *base_layout;			// Базовий макет
    QGridLayout *main_layout;			// Макет для розміщення GUI
    QHBoxLayout *buttons_layout;		// Макет для розміщення кнопок скасування та додавання

    /// WIDGETS
    /// FOR MAIN_LAYOUT
    // Раунд
    QLabel *round_front_lbl;			// Передня позначка
    QSlider *round_time_slider;			// Слайдер обрання часу раунду
    QLabel *round_back_lbl;				// Задня позначка

    QLabel *round_sound_front_lbl;		// Передня позначка
    QPushButton *round_sound_play_btn;	// Кнопка відтворення обраного аудіо-сигналу
    QLabel *round_sound_back_lbl;		// Позначка назви файла обраного аудіо-сигналу
    QPushButton *round_sound_change_btn;// Кнопка зміни аудіо-сигналу
    QString old_round_sound_path;		// Старий путь до аудіо-сигналу

    // Коротка перерва
    QLabel *short_front_lbl;			// Передня позначка
    QSlider *short_break_slider;		// Слайдер обрання часу короткої перерви
    QLabel *short_back_lbl;				// Задня позначка

    QLabel *short_sound_front_lbl;		// Передня позначка
    QPushButton *short_sound_play_btn;	// Кнопка відтворення обраного аудіо-сигналу
    QLabel *short_sound_back_lbl;		// Позначка назви файла обраного аудіо-сигналу
    QPushButton *short_sound_change_btn;// Кнопка зміни аудіо-сигналу
    QString old_short_sound_path;		// Старий путь до аудіо-сигналу

    // Довга перерва
    QLabel *long_front_lbl;				// Передня позначка
    QSlider *long_break_slider;			// Слайдер обрання часу довгої перерви
    QLabel *long_back_lbl;				// Задня позначка

    QLabel *long_sound_front_lbl;		// Передня позначка
    QPushButton *long_sound_play_btn;	// Кнопка відтворення обраного аудіо-сигналу
    QLabel *long_sound_back_lbl;		// Позначка назви файла обраного аудіо-сигналу
    QPushButton *long_sound_change_btn;	// Кнопка зміни аудіо-сигналу
    QString old_long_sound_path;		// Старий путь до аудіо-сигналу


    QCheckBox *pull_up_settings;	// Підтягування всіх слайдерів через один з них


    /// FOR BUTTONS_LAYOUT
    QPushButton *accept_btn;		// Кнопка збереження
    QPushButton *cancel_btn;		// Кнопка скасування

public:
    explicit SettingsForm(QDialog *parent = nullptr);

public slots:
    void save_changings();					// Збереження змін
    void discard_changings();				// Скасування змін

    void play_round_sound();				// Відтворення аудіо-сигналу для раунда
    void change_round_sound();				// Змінення аудіо-сигналу раунда

    void play_short_break_sound();			// Відтворення аудіо-сигналу для короткої перерви
    void change_short_break_sound();		// Змінення аудіо-сигналу короткої перерви

    void play_long_break_sound();			// Відтворення аудіо-сигналу для довгої перерви
    void change_long_break_sound();			// Змінення аудіо-сигналу довгої перерви

    void round_slider_changed(int value);	// Обробка зміни раунду
    void short_slider_changed(int value);	// Обробка зміни короткої перерви
    void long_slider_changed(int value);	// Обробка зміни довгої перерви

    void pull_up_settings_changed(int value);	// Обробка зміни підтягування налаштувань
};

#endif // SETTINGSFORM_H
