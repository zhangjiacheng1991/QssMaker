#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "attribute.h"
#include <QDockWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDockWidget m_docWidget;


};

#endif // MAINWINDOW_H
