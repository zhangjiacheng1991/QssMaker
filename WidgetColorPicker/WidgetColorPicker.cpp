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

#include "WidgetColorPicker.h"
#include <QColorDialog>

WidgetColorPicker::WidgetColorPicker(QWidget *parent):QWidget(parent)
{
    setupUi(this);
    init();
}

WidgetColorPicker::~WidgetColorPicker()
{

}

void WidgetColorPicker::init()
{
    comboBox->setMaxCount(21);

    disconnect(comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_currentIndexChanged(int)));
    comboBox->addItem("Custom Color..");
    comboBox->addItem(createIcon("#000000"),"#000000",QColor("#000000"));
    comboBox->addItem(createIcon("#FFFFFF"),"#FFFFFF",QColor("#FFFFFF"));
    comboBox->addItem(createIcon("#808080"),"#808080",QColor("#808080"));
    comboBox->addItem(createIcon("#800000"),"#800000",QColor("#800000"));
    comboBox->addItem(createIcon("#804040"),"#804040",QColor("#804040"));
    comboBox->addItem(createIcon("#FF8080"),"#FF8080",QColor("#FF8080"));
    comboBox->addItem(createIcon("#FF0000"),"#FF0000",QColor("#FF0000"));
    comboBox->addItem(createIcon("#FFFF80"),"#FFFF80",QColor("#FFFF80"));
    comboBox->addItem(createIcon("#FFFF00"),"#FFFF00",QColor("#FFFF00"));
    comboBox->addItem(createIcon("#FF8040"),"#FF8040",QColor("#FF8040"));
    comboBox->addItem(createIcon("#FF8000"),"#FF8000",QColor("#FF8000"));
    comboBox->addItem(createIcon("#80FF80"),"#80FF80",QColor("#80FF80"));
    comboBox->addItem(createIcon("#80FF00"),"#80FF00",QColor("#80FF00"));
    comboBox->addItem(createIcon("#00FF00"),"#00FF00",QColor("#00FF00"));
    comboBox->addItem(createIcon("#80FFFF"),"#80FFFF",QColor("#80FFFF"));
    comboBox->addItem(createIcon("#00FFFF"),"#00FFFF",QColor("#00FFFF"));
    comboBox->addItem(createIcon("#004080"),"#004080",QColor("#004080"));
    comboBox->addItem(createIcon("#0000FF"),"#0000FF",QColor("#0000FF"));
    comboBox->addItem(createIcon("#0080FF"),"#0080FF",QColor("#0080FF"));
    comboBox->addItem(createIcon("#0080C0"),"#0080C0",QColor("#0080C0"));

    m_Color = QColor("#000000");
    m_ColorName = "#000000";
    comboBox->setCurrentIndex(1);
    connect(comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_currentIndexChanged(int)));
}

QIcon WidgetColorPicker::createIcon(QString colorName)
{
    QPixmap iconPixmap(32,32);
    iconPixmap.fill(QColor(colorName));
    QIcon itemIcon(iconPixmap);
    return itemIcon;
}

void WidgetColorPicker::on_comboBox_currentIndexChanged(int index)
{
    if(index==0)
    {
        m_Color = QColorDialog::getColor(m_Color,this);
        m_ColorName = m_Color.name();
        addColor(m_Color);
    }
    else
    {
        m_ColorName = comboBox->itemText(index);
        m_Color = comboBox->itemData(index).value<QColor>();
    }

    emit colorSelectionChanged(m_ColorName);
    emit colorSelectionChanged(m_Color);
}

void WidgetColorPicker::setColorName(QString colorName)
{
    if(!colorName.isEmpty())
    {
        if(QColor(colorName).isValid())
        {
            m_ColorName = colorName;
            m_Color = QColor(colorName);
            addColor(colorName);
        }
    }
}

QString WidgetColorPicker::getColorName()
{
    return m_ColorName;
}

void WidgetColorPicker::setColor(QColor color)
{
    if(color.isValid())
    {
        m_ColorName = color.name();
        m_Color = color;
        addColor(color);
    }
}

QColor WidgetColorPicker::getColor()
{
    return m_Color;
}

void WidgetColorPicker::addColor(QColor color)
{
    int index;
    if(index = comboBox->findData(color) > -1)
        comboBox->setCurrentIndex(index);
    else
    {
        QString colorName = color.name().toUpper();
        comboBox->insertItem(1,createIcon(colorName),colorName,color);
        comboBox->setCurrentIndex(1);
    }
}

void WidgetColorPicker::addColor(QString colorName)
{
    int index;
    colorName = colorName.toUpper();
    if(index = comboBox->findText(colorName) > -1)
        comboBox->setCurrentIndex(index);
    else
    {
        comboBox->insertItem(1,createIcon(colorName),colorName,QColor(colorName));
        comboBox->setCurrentIndex(1);
    }
}
