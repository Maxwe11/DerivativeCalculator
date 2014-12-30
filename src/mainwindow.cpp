#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QMessageBox>
#include <QtCore/QDebug>
#include <SWI-cpp.h>

#ifdef Q_OS_WIN
    #define LIB_SWI "libswipl.dll"
#endif

#define PROLOG_DERIVATIVE "derivative.pl"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_engine(const_cast<char*>(LIB_SWI))
    , m_functionValidator(QRegExp("[a-z0-9+-/*^()]+"))
    , m_variableValidator(QRegExp("[a-z]+"))
{
    ui->setupUi(this);

    PlTermv termv(1);
    termv[0] = PROLOG_DERIVATIVE;
    PlQuery query("consult", termv);
    if (query.next_solution())
        qDebug() << "derivative.pl successfully consulted";
    else
        qDebug() << "derivative.pl not found";

    ui->inputFunction->setValidator(&m_functionValidator);
    ui->inputVariable->setValidator(&m_variableValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    QString func = ui->inputFunction->text();
    QString var1 = ui->inputVariable->text();

    if (func.isEmpty())
    {
        QMessageBox::warning(this, QObject::tr("Помилка вводу"), QObject::tr("Ви не ввели функцію"));
        return;
    }

    if (var1.isEmpty())
    {
        QMessageBox::warning(this, "Помилка вводу", "Ви не ввели змінну диференціювання");
        return;
    }

    try
    {
        PlTermv termv(3);
        termv[0] = PlCompound(func.toStdString().c_str());
        termv[1] = PlCompound(var1.toStdString().c_str());

        PlQuery query("derivative", termv);

        if (query.next_solution())
        {
            ui->outputDerivative->setText(termv[2].operator char *());

        }
        else
        {
            ui->outputDerivative->setText(QObject::tr("Немає рішення"));
        }

        while (query.next_solution())
            qDebug() << "BUG: " << termv[2].operator char *();
    }
    catch (...)
    {
        QMessageBox::warning(this, "Помилка обчислення", "Перевірте правильність введенних даних");
        qDebug() << "some exception thrown";
    }
}
