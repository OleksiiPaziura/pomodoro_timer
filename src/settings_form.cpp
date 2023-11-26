#include "settings_form.h"

SettingsForm::SettingsForm(QDialog *parent)
    : QDialog{parent}
{
    base_layout = new QVBoxLayout;
    main_layout	= new QGridLayout;
    buttons_layout = new QHBoxLayout;
    buttons_layout->setAlignment(Qt::AlignBottom);

    setLayout(base_layout);
    base_layout->addLayout(main_layout);
    base_layout->addLayout(buttons_layout);



    // WIDGETS
    pomodoro_lbl = new QLabel("Pomodoro time:");
    pomodoro_time_slider = new QSlider(Qt::Horizontal);
    pomodoro_time_slider->setRange(0, 120);
    pomodoro_str = new QLabel(QString::number(pomodoro_time_slider->value()));

    short_lbl = new QLabel("Short break time:");
    short_break_slider = new QSlider(Qt::Horizontal);
    short_break_slider->setRange(0, 120);
    short_break_str = new QLabel(QString::number(short_break_slider->value()));

    long_lbl = new QLabel("Long break time:");
    long_break_slider = new QSlider(Qt::Horizontal);
    long_break_slider->setRange(0, 120);
    long_break_str = new QLabel(QString::number(long_break_slider->value()));

    auto_settings_lbl = new QLabel("Auto settings");
    auto_settings = new QCheckBox("Auto set");

    accept_btn = new QPushButton("Accept");
    cancel_btn = new QPushButton("Cancel");

    main_layout->addWidget(pomodoro_lbl, 0, 0);
    main_layout->addWidget(pomodoro_time_slider, 0, 1);
    main_layout->addWidget(pomodoro_str, 0, 2);

    main_layout->addWidget(short_lbl, 1, 0);
    main_layout->addWidget(short_break_slider, 1, 1);
    main_layout->addWidget(short_break_str, 1, 2);

    main_layout->addWidget(long_lbl, 2, 0);
    main_layout->addWidget(long_break_slider, 2, 1);
    main_layout->addWidget(long_break_str, 2, 2);

    main_layout->addWidget(auto_settings_lbl, 3, 0);
    main_layout->addWidget(auto_settings, 3, 1);

    buttons_layout->addWidget(accept_btn);
    buttons_layout->addWidget(cancel_btn);



    // CONNECTIONS
    connect(cancel_btn, SIGNAL(clicked()), this, SLOT(discard_changings()));
    connect(accept_btn, SIGNAL(clicked()), this, SLOT(save_changings()));

    connect(pomodoro_time_slider, SIGNAL(valueChanged(int)), this, SLOT(pomodoro_slider_changed(int)));
    connect(short_break_slider, SIGNAL(valueChanged(int)), this, SLOT(short_slider_changed(int)));
    connect(long_break_slider, SIGNAL(valueChanged(int)), this, SLOT(long_slider_changed(int)));
}

void SettingsForm::save_changings()
{
    Settings::pomodoro_time = 2;
    close();
}

void SettingsForm::discard_changings()
{
    Settings::pomodoro_time = 5;
    close();
}

void SettingsForm::pomodoro_slider_changed(int value)
{
    pomodoro_str->setText(QString::number(value) + " min");
}

void SettingsForm::short_slider_changed(int value)
{
    short_break_str->setText(QString::number(value) + " min");
}

void SettingsForm::long_slider_changed(int value)
{
    long_break_str->setText(QString::number(value) + " min");
}
