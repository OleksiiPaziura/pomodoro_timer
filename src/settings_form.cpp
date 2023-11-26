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
    accept_btn = new QPushButton("Accept");
    cancel_btn = new QPushButton("Cancel");


    buttons_layout->addWidget(accept_btn);
    buttons_layout->addWidget(cancel_btn);



    // CONNECTIONS
    connect(cancel_btn, SIGNAL(clicked()), this, SLOT(discard_changings()));
    connect(accept_btn, SIGNAL(clicked()), this, SLOT(save_changings()));
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
