#include "testsamplechart.h"
#include "ui_testsamplechart.h"

TestSampleChart::TestSampleChart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestSampleChart)
{
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(100);
    timer_on = false;
    connect(timer, &QTimer::timeout, this, &TestSampleChart::update_data);
    connect(ui->add_btn, &QPushButton::clicked, this, &TestSampleChart::add_line);
    connect(ui->add_data, &QPushButton::clicked, this, &TestSampleChart::add_data);
    connect(ui->get_data, &QPushButton::clicked, this, &TestSampleChart::get_data);
    connect(ui->load_data, &QPushButton::clicked, this, &TestSampleChart::load_data);



}

TestSampleChart::~TestSampleChart()
{
    delete ui;
}

void TestSampleChart::add_line()
{
    QString new_line_name = QInputDialog::getText(this,"輸入新增資料名","New line name");
    if(new_line_name=="")
        return;
    else
        //qDebug()<<new_line_name;
        ui->chartwidget->add_line_y(new_line_name);
}

void TestSampleChart::add_data()
{
       if(!timer_on)
       {
           ui->spinBox->setDisabled(true);
           timer->start();
           timer_on = true;
       }
       else
       {
           ui->spinBox->setDisabled(false);
           timer->stop();
           timer_on = false;
       }
}

void TestSampleChart::update_data()
{
    int line_index = ui->spinBox->value();
    //qDebug() << ui->chartwidget->get_line_ys().isEmpty();

    if(ui->chartwidget->get_line_ys().isEmpty())
    {
        timer->stop();
        timer_on = false;
        return;
    }
    else
    {
         QScatterSeries *line = ui->chartwidget->get_line_ys().takeAt(line_index);
         if(ui->chartwidget->get_line_y_data(line).isEmpty())
         {
             ui->chartwidget->append_line_y_data(line, 0, QRandomGenerator::global()->bounded(100.0));
             ui->chartwidget->set_axes_range(0,100,0,100);
         }
         else
         {
             int final_x = ui->chartwidget->get_line_y_data(line).takeLast().rx();
             ui->chartwidget->append_line_y_data(line, final_x + 1, QRandomGenerator::global()->bounded(100.0));
             ui->chartwidget->set_axes_range(0,final_x + 1,0,100);
         }

    }


}

void TestSampleChart::get_data()
{
    int line_index = ui->spinBox->value();
    QScatterSeries *line = ui->chartwidget->get_line_ys().takeAt(line_index);
    QList<QPointF> datas = ui->chartwidget->get_line_y_data(line);

    QFile file(QDateTime::currentDateTime().toString("yyyyMMddHHmmss") + ".csv");
    file.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream out(&file);

    QList<QPointF>::Iterator iter;
    for(iter = datas.begin(); iter!=datas.end();iter++)
    {
       QString text = QString::number((*iter).rx())+ "," + QString::number((*iter).ry())+"\n";
       out << text;
    }
    file.close();
}

void TestSampleChart::load_data()
{
    QFile file("20230422203156.csv");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    QString temp = in.readAll();
    QStringList data = temp.split("\n");
    data.removeLast();

    QScatterSeries *line = ui->chartwidget->get_line_ys().takeAt(ui->spinBox->value());
    line->clear();

    QList<QPointF> points;

    QStringList xy;
    QStringList::Iterator iter;
    for(iter = data.begin(); iter!=data.end(); iter++)
    {
        xy = (*iter).split(",");
        points.append(QPointF(xy.at(0).toFloat(), xy.at(1).toFloat()));
    }

    ui->chartwidget->append_line_y_data(line, points);
    file.close();

}

