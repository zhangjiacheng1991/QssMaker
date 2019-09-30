#include "attribute2.h"
#include "ui_attribute2.h"

Attribute2::Attribute2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Attribute2)
{
    ui->setupUi(this);
}

Attribute2::~Attribute2()
{
    delete ui;
}
