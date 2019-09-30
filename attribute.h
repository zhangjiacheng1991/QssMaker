#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QDialog>
#include <QDockWidget>

namespace Ui {
class Attribute;
}

class Attribute : public QDialog
{
    Q_OBJECT

public:
    explicit Attribute(QWidget *parent = nullptr);
    ~Attribute();

private slots:
    void on_toolButton_backgroundPictureChoose_clicked();

private:
    Ui::Attribute *ui;
};

#endif // ATTRIBUTE_H
