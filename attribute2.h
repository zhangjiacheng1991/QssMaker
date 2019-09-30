#ifndef ATTRIBUTE2_H
#define ATTRIBUTE2_H

#include <QWidget>

namespace Ui {
class Attribute2;
}

class Attribute2 : public QWidget
{
    Q_OBJECT

public:
    explicit Attribute2(QWidget *parent = nullptr);
    ~Attribute2();

private:
    Ui::Attribute2 *ui;
};

#endif // ATTRIBUTE2_H
