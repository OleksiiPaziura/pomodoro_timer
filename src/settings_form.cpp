#include "settings_form.h"

SettingsForm::SettingsForm(QDialog *parent)
    : QDialog{parent}
{
    /// WINDOW SETTINGS
    setFixedSize(400, 400);

    base_layout = new QVBoxLayout;
    main_layout	= new QGridLayout;
    buttons_layout = new QHBoxLayout;
    buttons_layout->setAlignment(Qt::AlignBottom);

    setLayout(base_layout);
    base_layout->addLayout(main_layout);
    base_layout->addLayout(buttons_layout);



    /// WIDGETS
    // FOR MAIN_LAYOUT
    // Раунд
    round_front_lbl = new QLabel(tr("Round time:"));
    round_time_slider = new QSlider(Qt::Horizontal);
    round_time_slider->setRange(0, SLIDER_MINS);
    round_time_slider->setValue(Settings::round_time / Settings::SEC_IN_MIN);
    round_back_lbl = new QLabel(QString::number(round_time_slider->value()) + tr(" min"));

    round_sound_front_lbl = new QLabel(tr("Sound:"));
    round_sound_play_btn = new QPushButton(tr("Play"));
    round_sound_back_lbl = new QLabel(Settings::round_sound.source().fileName());
    round_sound_change_btn = new QPushButton(tr("Change sound"));
    old_round_sound_path = Settings::round_sound.source().path();

    // Коротка перерва
    short_front_lbl = new QLabel(tr("Short break time:"));
    short_break_slider = new QSlider(Qt::Horizontal);
    short_break_slider->setRange(0, SLIDER_MINS);
    short_break_slider->setValue(Settings::short_break_time / Settings::SEC_IN_MIN);
    short_back_lbl = new QLabel(QString::number(short_break_slider->value()) + tr(" min"));

    short_sound_front_lbl = new QLabel(tr("Sound:"));
    short_sound_play_btn = new QPushButton(tr("Play"));
    short_sound_back_lbl = new QLabel(Settings::short_break_sound.source().fileName());
    short_sound_change_btn = new QPushButton(tr("Change sound"));
    old_short_sound_path = Settings::short_break_sound.source().path();

    // Довга перерва
    long_front_lbl = new QLabel(tr("Long break time:"));
    long_break_slider = new QSlider(Qt::Horizontal);
    long_break_slider->setRange(0, SLIDER_MINS);
    long_break_slider->setValue(Settings::long_break_time / Settings::SEC_IN_MIN);
    long_back_lbl = new QLabel(QString::number(long_break_slider->value()) + tr(" min"));

    long_sound_front_lbl = new QLabel(tr("Sound:"));
    long_sound_play_btn = new QPushButton(tr("Play"));
    long_sound_back_lbl = new QLabel(Settings::long_break_sound.source().fileName());
    long_sound_change_btn = new QPushButton(tr("Change sound"));
    old_long_sound_path = Settings::long_break_sound.source().path();

    // Інші налаштування
    if (Settings::is_round)
    {
        round_time_slider->setEnabled(false);
        short_break_slider->setEnabled(false);
        long_break_slider->setEnabled(false);
    }
    else
    {
        round_time_slider->setEnabled(true);
        short_break_slider->setEnabled(true);
        long_break_slider->setEnabled(true);
    }

    pull_up_settings = new QCheckBox(tr("Pull-up settings"));


    // FOR BUTTONS_LAYOUT
    accept_btn = new QPushButton(tr("Accept"));
    cancel_btn = new QPushButton(tr("Cancel"));



    // LAYOUTS
    // Main layout
    main_layout->addWidget(round_front_lbl, 0, 0);
    main_layout->addWidget(round_time_slider, 0, 1);
    main_layout->addWidget(round_back_lbl, 0, 2);

    main_layout->addWidget(round_sound_front_lbl, 1, 0);
    main_layout->addWidget(round_sound_play_btn, 1, 1);
    main_layout->addWidget(round_sound_back_lbl, 1, 2);
    main_layout->addWidget(round_sound_change_btn, 2, 1);


    main_layout->addWidget(short_front_lbl, 3, 0);
    main_layout->addWidget(short_break_slider, 3, 1);
    main_layout->addWidget(short_back_lbl, 3, 2);

    main_layout->addWidget(short_sound_front_lbl, 4, 0);
    main_layout->addWidget(short_sound_play_btn, 4, 1);
    main_layout->addWidget(short_sound_back_lbl, 4, 2);
    main_layout->addWidget(short_sound_change_btn, 5, 1);


    main_layout->addWidget(long_front_lbl, 6, 0);
    main_layout->addWidget(long_break_slider, 6, 1);
    main_layout->addWidget(long_back_lbl, 6, 2);

    main_layout->addWidget(long_sound_front_lbl, 7, 0);
    main_layout->addWidget(long_sound_play_btn, 7, 1);
    main_layout->addWidget(long_sound_back_lbl, 7, 2);
    main_layout->addWidget(long_sound_change_btn, 8, 1);


    main_layout->addWidget(pull_up_settings, 9, 1);

    // Buttons layout
    buttons_layout->addWidget(accept_btn);
    buttons_layout->addWidget(cancel_btn);



    // CONNECTIONS
    // Обробка збереження і скасування
    connect(accept_btn, SIGNAL(clicked()), this, SLOT(save_changings()));
    connect(cancel_btn, SIGNAL(clicked()), this, SLOT(discard_changings()));

    // Обробка звукової частини
    // Раунд
    connect(round_sound_play_btn, SIGNAL(clicked()), this, SLOT(play_round_sound()));
    connect(round_sound_change_btn, SIGNAL(clicked()), this, SLOT(change_round_sound()));
    // Коротка перерва
    connect(short_sound_play_btn, SIGNAL(clicked()), this, SLOT(play_short_break_sound()));
    connect(short_sound_change_btn, SIGNAL(clicked()), this, SLOT(change_short_break_sound()));
    // Довга перерва
    connect(long_sound_play_btn, SIGNAL(clicked()), this, SLOT(play_long_break_sound()));
    connect(long_sound_change_btn, SIGNAL(clicked()), this, SLOT(change_long_break_sound()));

    // Обробка зміни слайдерів часу
    connect(round_time_slider, SIGNAL(valueChanged(int)), this, SLOT(round_slider_changed(int)));
    connect(short_break_slider, SIGNAL(valueChanged(int)), this, SLOT(short_slider_changed(int)));
    connect(long_break_slider, SIGNAL(valueChanged(int)), this, SLOT(long_slider_changed(int)));
}

// Збереження налаштувань при натисканні кнопки "Зберігти"
void SettingsForm::save_changings()
{
    Settings::round_time = round_time_slider->value() * Settings::SEC_IN_MIN;
    Settings::short_break_time = short_break_slider->value() * Settings::SEC_IN_MIN;
    Settings::long_break_time = long_break_slider->value() * Settings::SEC_IN_MIN;
    close();
}

// Скасування налаштувань при натисканні кнопки "Скасувати"
void SettingsForm::discard_changings()
{
    Settings::round_sound.setSource(QUrl::fromLocalFile(old_round_sound_path));
    Settings::short_break_sound.setSource(QUrl::fromLocalFile(old_short_sound_path));
    Settings::long_break_sound.setSource(QUrl::fromLocalFile(old_long_sound_path));
    close();
}

// Відтворення аудіо-сигналу раунда
void SettingsForm::play_round_sound()
{
    Settings::round_sound.play();
}

// Зміна аудіо-сигналу раунда
void SettingsForm::change_round_sound()
{
    Settings::round_sound.stop();

    QFileDialog *select_file = new QFileDialog;
    QUrl new_path = QUrl::fromLocalFile(select_file->getOpenFileName(this, "Sound file", "../sounds", "Sound files (*.wav)"));

    if (!new_path.isEmpty())
        Settings::round_sound.setSource(new_path);

    round_sound_back_lbl->setText(Settings::round_sound.source().fileName());
}

// Відтворення аудіо-сигналу короткої перерви
void SettingsForm::play_short_break_sound()
{
    Settings::short_break_sound.play();
}

// Зміна аудіо-сигналу короткої перерви
void SettingsForm::change_short_break_sound()
{
    Settings::short_break_sound.stop();

    QFileDialog *select_file = new QFileDialog;
    QUrl new_path = QUrl::fromLocalFile(select_file->getOpenFileName(this, "Sound file", "../sounds", "Sound files (*.wav)"));

    if (!new_path.isEmpty())
        Settings::short_break_sound.setSource(new_path);

    short_sound_back_lbl->setText(Settings::short_break_sound.source().fileName());
}

// Відтворення аудіо-сигналу довгої перерви
void SettingsForm::play_long_break_sound()
{
    Settings::long_break_sound.play();
}

// Зміна аудіо-сигналу довгої перерви
void SettingsForm::change_long_break_sound()
{
    Settings::long_break_sound.stop();

    QFileDialog *select_file = new QFileDialog;
    QUrl new_path = QUrl::fromLocalFile(select_file->getOpenFileName(this, "Sound file", "../sounds", "Sound files (*.wav)"));

    if (!new_path.isEmpty())
        Settings::long_break_sound.setSource(new_path);

    long_sound_back_lbl->setText(Settings::long_break_sound.source().fileName());
}

// Обробка зміни часу раунда
void SettingsForm::round_slider_changed(int value)
{
    round_back_lbl->setText(QString::number(value) + tr(" min"));
}

// Обробка зміни часу короткої перерви
void SettingsForm::short_slider_changed(int value)
{
    short_back_lbl->setText(QString::number(value) + tr(" min"));
}

// Обробка зміни часу довгої перерви
void SettingsForm::long_slider_changed(int value)
{
    long_back_lbl->setText(QString::number(value) + tr(" min"));
}
