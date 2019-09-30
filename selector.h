#ifndef SELECTOR_H
#define SELECTOR_H

#include <QWidget>
#include <QAbstractButton>
namespace Ui {
class Selector;
}

class Selector : public QWidget
{
    Q_OBJECT

public:
    explicit Selector(QWidget *parent = nullptr);
    ~Selector();

private slots:
    void on_comboBox_SelectorContral_activated(const QString &arg1);

    void on_radioButton_selectorFutrue_clicked();

    void on_radioButton_selectorChild_clicked();

    void on_comboBox_selectorattribute_currentIndexChanged(const QString &arg1);

    void on_comboBox_SelectorContral_activated(int index);

    void on_buttonBox_selector_accepted();

private:
    Ui::Selector *ui;
};

#endif // SELECTOR_H
