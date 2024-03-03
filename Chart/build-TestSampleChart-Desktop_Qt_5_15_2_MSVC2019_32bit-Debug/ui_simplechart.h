/********************************************************************************
** Form generated from reading UI file 'simplechart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLECHART_H
#define UI_SIMPLECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleChart
{
public:

    void setupUi(QWidget *SimpleChart)
    {
        if (SimpleChart->objectName().isEmpty())
            SimpleChart->setObjectName(QString::fromUtf8("SimpleChart"));
        SimpleChart->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SimpleChart->sizePolicy().hasHeightForWidth());
        SimpleChart->setSizePolicy(sizePolicy);
        SimpleChart->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(SimpleChart);

        QMetaObject::connectSlotsByName(SimpleChart);
    } // setupUi

    void retranslateUi(QWidget *SimpleChart)
    {
        SimpleChart->setWindowTitle(QCoreApplication::translate("SimpleChart", "SimpleChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimpleChart: public Ui_SimpleChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLECHART_H
