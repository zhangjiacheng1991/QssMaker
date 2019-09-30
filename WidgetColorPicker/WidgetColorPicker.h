/*
 * Copyright 2009 EMBITEL (http://www.embitel.com)
 * 
 * This file is part of Color Picker Project.
 * 
 * Color Picker is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation
 * 
 * Color Picker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Color Picker. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __WIDGETCOLORPICKER_H_
#define __WIDGETCOLORPICKER_H_

#include <QWidget>
#include <QColor>
#include "ui_WidgetColorPicker.h"

class WidgetColorPicker : public QWidget, public Ui::WidgetColorPicker
{
    Q_OBJECT
    
    public: //Methods
        WidgetColorPicker(QWidget *parent = 0);
        ~WidgetColorPicker();

        void setColorName(QString colorName);
        QString getColorName();
        void setColor(QColor color);
        QColor getColor();

    private: //Methods
        void init();
        QIcon createIcon(QString colorName);
        void addColor(QString colorName);
        void addColor(QColor color);

    private: //Data Members
        QColor m_Color;
        QString m_ColorName;

    private slots: //Slots
        void on_comboBox_currentIndexChanged(int index);

    signals: //Signal
        void colorSelectionChanged(QString);
        void colorSelectionChanged(QColor);
};

#endif /*__WIDGETCOLORPICKER_H_*/
