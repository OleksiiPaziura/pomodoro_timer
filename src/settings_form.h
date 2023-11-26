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

    QPushButton *accept_btn;
    QPushButton *cancel_btn;

public:
    explicit SettingsForm(QDialog *parent = nullptr);

public slots:
    void save_changings();
    void discard_changings();

signals:
};

#endif // SETTINGSFORM_H
