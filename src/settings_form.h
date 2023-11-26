#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QtWidgets>
#include "settings.h"

class SettingsForm : public QDialog
{
    Q_OBJECT

private:
    QVBoxLayout *base_layout;
    QGridLayout *main_layout;
    QHBoxLayout *buttons_layout;

    QLabel *pomodoro_lbl;
    QSlider *pomodoro_time_slider;
    QLabel *pomodoro_str;

    QLabel *short_lbl;
    QSlider *short_break_slider;
    QLabel *short_break_str;

    QLabel *long_lbl;
    QSlider *long_break_slider;
    QLabel *long_break_str;

    QLabel *sound;
    QPushButton *sound_play;
    QLabel *sound_name;
    QPushButton *sound_change;
    QString old_sound_path;

    QLabel *auto_settings_lbl;
    QCheckBox *auto_settings;

    QPushButton *accept_btn;
    QPushButton *cancel_btn;

public:
    explicit SettingsForm(QDialog *parent = nullptr);

public slots:
    void save_changings();

    void play_sound();
    void change_sound();

    void pomodoro_slider_changed(int value);
    void short_slider_changed(int value);
    void long_slider_changed(int value);

signals:
};

#endif // SETTINGSFORM_H
