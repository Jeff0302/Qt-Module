
#ifndef TESTEXCEL_H
#define TESTEXCEL_H

#include <QWidget>

//加入Exccel操作類
#include "ExcelObject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestExcel; }
QT_END_NAMESPACE

class TestExcel : public QWidget

{
    Q_OBJECT

public:
    TestExcel(QWidget *parent = nullptr);
    ~TestExcel();

private:
    Ui::TestExcel *ui;
    ExcelObject *excel;
};

#endif // TESTEXCEL_H
