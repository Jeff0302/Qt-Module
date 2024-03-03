/********************************************************************************
** Form generated from reading UI file 'testexcel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTEXCEL_H
#define UI_TESTEXCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestExcel
{
public:

    void setupUi(QWidget *TestExcel)
    {
        if (TestExcel->objectName().isEmpty())
            TestExcel->setObjectName(QString::fromUtf8("TestExcel"));
        TestExcel->resize(800, 600);

        retranslateUi(TestExcel);

        QMetaObject::connectSlotsByName(TestExcel);
    } // setupUi

    void retranslateUi(QWidget *TestExcel)
    {
        TestExcel->setWindowTitle(QCoreApplication::translate("TestExcel", "TestExcel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestExcel: public Ui_TestExcel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTEXCEL_H
