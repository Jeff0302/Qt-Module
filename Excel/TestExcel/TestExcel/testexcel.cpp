
#include "testexcel.h"
#include "ui_testexcel.h"


TestExcel::TestExcel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestExcel)
{
    ui->setupUi(this);

    QStringList names;
    names << "Result1" << "Result2" << "Result3";
    excel = new ExcelObject("mytest.xlsx", names);

    //設定指定sheet的title及其格式
    QStringList titles;
    titles << "Channel" << "Sensitivity" << "PER";
    excel->set_sheet_title("Result1", titles, 10.0);

    QList<qreal> data_row;
    QList<QList<qreal>> data;

    for (int i = 0; i < 10; i++)
    {
        data_row.clear();
        data_row.append(1);
        data_row.append(-97.0);
        data_row.append(23.1);
        data.append(data_row);
    }
    //qDebug() << data;

    excel->set_result("Result1", data);

    excel->save();
}

TestExcel::~TestExcel()
{
    delete ui;
}


