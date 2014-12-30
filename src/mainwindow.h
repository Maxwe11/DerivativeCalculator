#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QRegExpValidator>
#include <SWI-cpp.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void calculate();
private:
    Ui::MainWindow*     ui;
    PlEngine            m_engine;
    QRegExpValidator    m_functionValidator;
    QRegExpValidator    m_variableValidator;
};

#endif // MAINWINDOW_H
