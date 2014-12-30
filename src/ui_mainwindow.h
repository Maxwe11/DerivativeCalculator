/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 10. Jan 23:41:26 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_1;
    QLineEdit *inputFunction;
    QLabel *label_2;
    QLineEdit *inputVariable;
    QLabel *label_3;
    QLineEdit *outputDerivative;
    QPushButton *calculateButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(538, 141);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 521, 81));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_1);

        inputFunction = new QLineEdit(layoutWidget);
        inputFunction->setObjectName(QString::fromUtf8("inputFunction"));
        inputFunction->setInputMethodHints(Qt::ImhLowercaseOnly);

        formLayout->setWidget(0, QFormLayout::FieldRole, inputFunction);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        inputVariable = new QLineEdit(layoutWidget);
        inputVariable->setObjectName(QString::fromUtf8("inputVariable"));

        formLayout->setWidget(1, QFormLayout::FieldRole, inputVariable);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        outputDerivative = new QLineEdit(layoutWidget);
        outputDerivative->setObjectName(QString::fromUtf8("outputDerivative"));
        outputDerivative->setEchoMode(QLineEdit::Normal);
        outputDerivative->setReadOnly(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, outputDerivative);

        calculateButton = new QPushButton(centralWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(10, 100, 521, 31));
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(inputFunction, inputVariable);
        QWidget::setTabOrder(inputVariable, calculateButton);
        QWidget::setTabOrder(calculateButton, outputDerivative);

        retranslateUi(MainWindow);
        QObject::connect(calculateButton, SIGNAL(clicked()), MainWindow, SLOT(calculate()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 \320\277\320\276\321\205\321\226\320\264\320\275\320\270\321\205", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\321\226\321\217:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\227\320\274\321\226\320\275\320\275\320\260 \320\264\320\270\321\204.:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\205\321\226\320\264\320\275\320\260:", 0, QApplication::UnicodeUTF8));
        calculateButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\207\320\270\321\201\320\273\320\270\321\202\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
