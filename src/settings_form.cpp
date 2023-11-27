#include "settings_form.h"

SettingsForm::SettingsForm(QDialog *parent)
    : QDialog{parent}
{
    // BASE SETTINGS
    setFixedSize(400, 250);

    base_layout = new QVBoxLayout;
    main_layout	= new QGridLayout;
    buttons_layout = new QHBoxLayout;
    buttons_layout->setAlignment(Qt::AlignBottom);

    setLayout(base_layout);
    base_layout->addLayout(main_layout);
    base_layout->addLayout(buttons_layout);



    // WIDGETS
    pomodoro_lbl = new QLabel(tr("Pomodoro time:"));
    pomodoro_time_slider = new QSlider(Qt::Horizontal);
    pomodoro_time_slider->setRange(0, 120);
    pomodoro_time_slider->setValue(Settings::round_time / 60);
    pomodoro_str = new QLabel(QString::number(pomodoro_time_slider->value()) + tr(" min"));

    short_lbl = new QLabel(tr("Short break time:"));
    short_break_slider = new QSlider(Qt::Horizontal);
    short_break_slider->setRange(0, 120);
    short_break_slider->setValue(Settings::short_break_time / 60);
    short_break_str = new QLabel(QString::number(short_break_slider->value()) + tr(" min"));

    long_lbl = new QLabel(tr("Long break time:"));
    long_break_slider = new QSlider(Qt::Horizontal);
    long_break_slider->setRange(0, 120);
    long_break_slider->setValue(Settings::long_break_time / 60);
    long_break_str = new QLabel(QString::number(long_break_slider->value()) + tr(" min"));

    sound = new QLabel(tr("Sound:"));
    sound_play = new QPushButton(tr("Play"));
    sound_name = new QLabel(Settings::current_sound.source().fileName());
    sound_change = new QPushButton(tr("Change sound"));
    old_sound_path = Settings::current_sound.source().path();

    auto_settings_lbl = new QLabel(tr("Auto settings"));
    auto_settings = new QCheckBox(tr("Auto set"));

    accept_btn = new QPushButton(tr("Accept"));
    cancel_btn = new QPushButton(tr("Cancel"));

    if (Settings::is_round)
    {
        pomodoro_time_slider->setEnabled(false);
        short_break_slider->setEnabled(false);
        long_break_slider->setEnabled(false);
    }
    else
    {
        pomodoro_time_slider->setEnabled(true);
        short_break_slider->setEnabled(true);
        long_break_slider->setEnabled(true);
    }


    // LAYOUTS
    main_layout->addWidget(pomodoro_lbl, 0, 0);
    main_layout->addWidget(pomodoro_time_slider, 0, 1);
    main_layout->addWidget(pomodoro_str, 0, 2);

    main_layout->addWidget(short_lbl, 1, 0);
    main_layout->addWidget(short_break_slider, 1, 1);
    main_layout->addWidget(short_break_str, 1, 2);

    main_layout->addWidget(long_lbl, 2, 0);
    main_layout->addWidget(long_break_slider, 2, 1);
    main_layout->addWidget(long_break_str, 2, 2);

    main_layout->addWidget(sound, 3, 0);
    main_layout->addWidget(sound_play, 3, 1);
    main_layout->addWidget(sound_name, 3, 2);

    main_layout->addWidget(sound_change, 4, 1);

    main_layout->addWidget(auto_settings_lbl, 5, 0);
    main_layout->addWidget(auto_settings, 5, 1);

    buttons_layout->addWidget(accept_btn);
    buttons_layout->addWidget(cancel_btn);



    // CONNECTIONS
    connect(cancel_btn, SIGNAL(clicked()), this, SLOT(discard_changings()));
    connect(accept_btn, SIGNAL(clicked()), this, SLOT(save_changings()));

    connect(sound_play, SIGNAL(clicked()), this, SLOT(play_sound()));
    connect(sound_change, SIGNAL(clicked()), this, SLOT(change_sound()));

    connect(pomodoro_time_slider, SIGNAL(valueChanged(int)), this, SLOT(pomodoro_slider_changed(int)));
    connect(short_break_slider, SIGNAL(valueChanged(int)), this, SLOT(short_slider_changed(int)));
    connect(long_break_slider, SIGNAL(valueChanged(int)), this, SLOT(long_slider_changed(int)));
}

void SettingsForm::save_changings()
{
    Settings::round_time = pomodoro_time_slider->value() * 60;
    Settings::short_break_time = short_break_slider->value() * 60;
    Settings::long_break_time = long_break_slider->value() * 60;
    close();
}

void SettingsForm::play_sound()
{
    Settings::current_sound.play();
}

void SettingsForm::change_sound()
{
    Settings::current_sound.stop();

    QFileDialog *select_file = new QFileDialog;

    Settings::current_sound.setSource(QUrl::fromLocalFile(
        select_file->getOpenFileName(this, "Sound file", "../sounds", "Sound files (*.wav)")));

    sound_name->setText(Settings::current_sound.source().fileName());
}

void SettingsForm::pomodoro_slider_changed(int value)
{
    pomodoro_str->setText(QString::number(value) + tr(" min"));
}

void SettingsForm::short_slider_changed(int value)
{
    short_break_str->setText(QString::number(value) + tr(" min"));
}

void SettingsForm::long_slider_changed(int value)
{
    long_break_str->setText(QString::number(value) + tr(" min"));
}
