/********************************************************************************
** Form generated from reading UI file 'testsamplechart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSAMPLECHART_H
#define UI_TESTSAMPLECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "simplechart.h"

QT_BEGIN_NAMESPACE

class Ui_TestSampleChart
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    SimpleChart *chartwidget;
    QSpinBox *spinBox;
    QPushButton *add_btn;
    QPushButton *add_data;
    QPushButton *get_data;
    QPushButton *load_data;

    void setupUi(QWidget *TestSampleChart)
    {
        if (TestSampleChart->objectName().isEmpty())
            TestSampleChart->setObjectName(QString::fromUtf8("TestSampleChart"));
        TestSampleChart->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(TestSampleChart);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chartwidget = new SimpleChart(TestSampleChart);
        chartwidget->setObjectName(QString::fromUtf8("chartwidget"));

        verticalLayout->addWidget(chartwidget);

        spinBox = new QSpinBox(TestSampleChart);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(spinBox);

        add_btn = new QPushButton(TestSampleChart);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));

        verticalLayout->addWidget(add_btn);

        add_data = new QPushButton(TestSampleChart);
        add_data->setObjectName(QString::fromUtf8("add_data"));

        verticalLayout->addWidget(add_data);

        get_data = new QPushButton(TestSampleChart);
        get_data->setObjectName(QString::fromUtf8("get_data"));

        verticalLayout->addWidget(get_data);

        load_data = new QPushButton(TestSampleChart);
        load_data->setObjectName(QString::fromUtf8("load_data"));

        verticalLayout->addWidget(load_data);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(TestSampleChart);

        QMetaObject::connectSlotsByName(TestSampleChart);
    } // setupUi

    void retranslateUi(QWidget *TestSampleChart)
    {
        TestSampleChart->setWindowTitle(QCoreApplication::translate("TestSampleChart", "TestSampleChart", nullptr));
        add_btn->setText(QCoreApplication::translate("TestSampleChart", "ADD", nullptr));
        add_data->setText(QCoreApplication::translate("TestSampleChart", "random data", nullptr));
        get_data->setText(QCoreApplication::translate("TestSampleChart", "get data", nullptr));
        load_data->setText(QCoreApplication::translate("TestSampleChart", "load data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestSampleChart: public Ui_TestSampleChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSAMPLECHART_H
