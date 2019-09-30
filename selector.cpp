#include "selector.h"
#include "ui_selector.h"

Selector::Selector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selector)
{
    ui->setupUi(this);
    ui->lineEdit_selectorContral->setText(ui->comboBox_SelectorContral->currentText());
}

Selector::~Selector()
{
    delete ui;
}

void Selector::on_comboBox_SelectorContral_activated(const QString &arg1)
{
    ui->lineEdit_selectorContral->setText(arg1);
}

void Selector::on_radioButton_selectorFutrue_clicked()
{
    ui->comboBox_selectorFutrue->setEnabled(true);
    ui->comboBox_selectorChild->setEnabled(false);
}

void Selector::on_radioButton_selectorChild_clicked()
{
    ui->comboBox_selectorFutrue->setEnabled(false);
    ui->comboBox_selectorChild->setEnabled(true);
}

void Selector::on_comboBox_selectorattribute_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_selectorattribute->setText(arg1);
}

void Selector::on_comboBox_SelectorContral_activated(int index)
{
    switch (index)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}

void Selector::on_buttonBox_selector_accepted()
{
    this->setEnabled(false);

}
