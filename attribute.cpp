#include "attribute.h"
#include "ui_attribute.h"
#include <QString>
#include <QFileDialog>
Attribute::Attribute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Attribute)
{
    ui->setupUi(this);
    connect(ui->comboBox_backgroundFontSpace,static_cast<void (QComboBox::*)(int)>(&QComboBox::activated) ,
            [=](int index)
            {
                if(index == 0)ui->doubleSpinBox_backgroundFontSpaceVal->setEnabled(false);
                else ui->doubleSpinBox_backgroundFontSpaceVal->setEnabled(true);
            });
    connect(ui->comboBox_backgroundWordSpace,static_cast<void (QComboBox::*)(int)>(&QComboBox::activated),
            [=](int index){
                if(index == 0)ui->doubleSpinBox_backgroundWordSpaceval->setEnabled(false);
                else ui->doubleSpinBox_backgroundWordSpaceval->setEnabled(true);
            });
}

Attribute::~Attribute()
{
    delete ui;
}

void Attribute::on_toolButton_backgroundPictureChoose_clicked()
{
    QString picture = QFileDialog::getOpenFileName(nullptr,"图片选择","","Images (*.png)");
    if(picture.isEmpty())return;
    ui->lineEdit_backgroundPicture->setText(picture);
}
