/***************************************************************************
 * This file is part of the TTK qmmp plugin project
 * Copyright (C) 2015 - 2024 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "ui_settingsdialog.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = nullptr);

public slots:
    virtual void accept() override final;
    virtual void reject() override final;

private slots:
    void on_delaySlider_valueChanged(int value);
    void on_feedSlider_valueChanged(int value);
    void on_volumeSlider_valueChanged(int value);

private:
    Ui::SettingsDialog m_ui;
    int m_delay = 0;
    int m_feedback = 0;
    int m_volume = 0;

};

#endif
