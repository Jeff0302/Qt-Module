#include "simplechart.h"
#include "ui_simplechart.h"

SimpleChart::SimpleChart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SimpleChart)
{
    ui->setupUi(this);

    QVBoxLayout VB;
    VB.setContentsMargins(0,0,0,0);
    view = new QChartView();
    VB.addWidget(view);
    this->setLayout(&VB);


    chart = new QChart();
    //chart外邊界設0
    chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->setBackgroundVisible(false);
    chart->setTitle("Chart Title");
    view->setChart(chart);

    axis_x = new QValueAxis();
    axis_y = new QValueAxis();
    axis_y2 = new QValueAxis();
    set_axes_range();
    chart->addAxis(axis_x, Qt::AlignBottom);
    chart->addAxis(axis_y, Qt::AlignLeft);

    set_y2_visible(false);

    //新增資料範例
    /*
    QScatterSeries *line123 = add_line_y("林建甫");
    for(int i=1;i<20;i++)
         append_line_y_data(line123, i, i);

    QScatterSeries *line456 = add_line_y("456");
    QList<QPointF> data1;
    for(int i=1;i<20;i++)
         data1.append(QPointF(i+20,i+20));

    QScatterSeries *line458 = add_line_y2("458");
    QList<QPointF> data2;
    line458->setMarkerSize(8);
    line458->setColor(QColor(0,0,255));
    line458->setPen(QPen(Qt::NoPen));
    for(int i=1;i<20;i++)
         data2.append(QPointF(i+80,i+100));

    append_line_y_data(line458, data2);
    */

    //設定axis格線樣式
    axis_x->setGridLineVisible(true);
    axis_x->setLinePen(QPen(QBrush(QColor(0, 0 ,0)),3));
    axis_x->setLabelsColor(QColor(0, 0 ,0));
    axis_x->setTitleBrush(QBrush(QColor(0, 0 ,0)));
    axis_y->setGridLineVisible(true);
    axis_y->setLinePen(QPen(QBrush(QColor(0, 0 ,0)),3));
    axis_y->setLabelsColor(QColor(0, 0 ,0));
    axis_y->setTitleBrush(QBrush(QColor(0, 0 ,0)));
    axis_y2->setGridLineVisible(true);
    axis_y2->setLinePen(QPen(QBrush(QColor(185, 120 ,85)),3));
    axis_y2->setLabelsColor(QColor(185, 120 ,85));
    axis_y2->setTitleBrush(QBrush(QColor(180, 120 ,85)));


    axis_x->setGridLinePen(QPen(QBrush(QColor(0, 0 ,0)),1 ,Qt::DashLine));
    axis_y->setGridLinePen(QPen(QBrush(QColor(0, 0 ,0)),1 ,Qt::DashLine));
    axis_y2->setGridLinePen(QPen(QBrush(QColor(185, 120 ,85)),1 ,Qt::DashLine));
    axis_x->setTickCount(11);
    axis_y->setTickCount(9);
    axis_y2->setTickCount(9);


    //chart初始
    set_chart_titile("Chart Title");
    set_chart_title_font(QFont("Arial", 16));
    set_legend(true, Qt::AlignBottom, QFont("Arial"));
    set_axis_name("x","y","y2");
    set_axis_label_font(QFont("Arial", 10));
    set_axis_title_font(QFont("Arial", 14));
    set_label_format("%.2f", "%.2f", "%.0f");
    set_chart_background(QColor(255,255,255), 0);
    this->show();
}

void SimpleChart::set_y2_visible(bool state)
{
    if(state)
        chart->addAxis(axis_y2, Qt::AlignRight);
    else
        chart->removeAxis(axis_y2);
}

QScatterSeries * SimpleChart::add_line_y(QString line_name)
{
    QScatterSeries * new_line = new QScatterSeries();
    new_line->setName(line_name);
    chart->addSeries(new_line);
    new_line->attachAxis(axis_x);
    new_line->attachAxis(axis_y);
    new_line->setPen(QPen(Qt::NoPen));
    line_ys.append(new_line);
    return new_line;

}

QScatterSeries *SimpleChart::add_line_y2(QString line_name)
{
    QScatterSeries *new_line = new QScatterSeries();
    new_line->setName(line_name);
    chart->addSeries(new_line);
    new_line->attachAxis(axis_x);
    new_line->attachAxis(axis_y2);
    new_line->setPen(QPen(Qt::NoPen));
    line_y2s.append(new_line);
    return new_line;
}

void SimpleChart::remove_all_y2_lines()
{
  QVector<QScatterSeries *>::Iterator iter;
  for(iter = line_y2s.begin(); iter!=line_y2s.end();iter++)
      chart->removeSeries(*iter);

  line_y2s.clear();
}

void SimpleChart::remove_all_y_lines()
{
    //QVector遍歷使用
    QVector<QScatterSeries *>::Iterator iter;
    for(iter=line_ys.begin(); iter!=line_ys.end();iter++)
        chart->removeSeries(*iter);

    line_ys.clear();
}

void SimpleChart::remove_line_y(QScatterSeries * line)
{
    chart->removeSeries(line);
    line_ys.removeOne(line);
}

void SimpleChart::remove_line_y2(QScatterSeries *line)
{
    chart->removeSeries(line);
    line_y2s.removeOne(line);
}

QList<QPointF> SimpleChart::get_line_y_data(QScatterSeries *line)
{
    return line->points();
}

void SimpleChart::append_line_y_data(QScatterSeries *line, float x, float y)
{
    line->append(x, y);
}

void SimpleChart::append_line_y_data(QScatterSeries * line, QList<QPointF> & points)
{
    line->append(points);
}

void SimpleChart::set_legend(bool visible, Qt::Alignment alignment, QFont font)
{
    chart->legend()->setVisible(visible);
    chart->legend()->setAlignment(alignment);
    chart->legend()->setFont(font);
}

void SimpleChart::set_axes_range(qreal xmin, qreal xmax, qreal ymin, qreal ymax, qreal y2min, qreal y2max)
{
        axis_x->setRange(xmin, xmax);
        axis_y->setRange(ymin, ymax);
        axis_y2->setRange(y2min, y2max);
}

void SimpleChart::set_chart_titile(QString title)
{
    chart->setTitle(title);
}

void SimpleChart::set_chart_title_font(QFont font)
{
    chart->setTitleFont(font);
}

void SimpleChart::set_chart_title_brush(QColor color)
{
    chart->setTitleBrush(color);
}

void SimpleChart::set_chart_background(QColor color, qreal opacity)
{
    view->setBackgroundBrush(QBrush(color));
    view->setWindowOpacity(opacity);
}

void SimpleChart::set_label_format(QString x, QString y, QString y2)
{
    get_axis("x")->setLabelFormat(x);
    get_axis("y")->setLabelFormat(y);
    get_axis("y2")->setLabelFormat(y2);

}

void SimpleChart::set_axis_name(QString x_title, QString y_title, QString y2_title)
{
    axis_x->setTitleText(x_title);
    axis_y->setTitleText(y_title);
    axis_y2->setTitleText(y2_title);
}

void SimpleChart::set_axis_label_font(QFont font)
{
    axis_x->setLabelsFont(font);
    axis_y->setLabelsFont(font);
    axis_y2->setLabelsFont(font);

}

void SimpleChart::set_axis_title_font(QFont font)
{
    axis_x->setTitleFont(font);
    axis_y->setTitleFont(font);
    axis_y2->setTitleFont(font);
}

QValueAxis *SimpleChart::get_axis(QString axis)
{
    if(axis=="x")
        return axis_x;
    else if(axis=="y")
        return axis_y;
    else
        return axis_y2;

}

QVector<QScatterSeries *> SimpleChart::get_line_ys()
{
    return line_ys;
}

QVector<QScatterSeries *> SimpleChart::get_line_y2s()
{
    return line_y2s;
}

SimpleChart::~SimpleChart()
{
    delete ui;
}

void SimpleChart::resizeEvent(QResizeEvent *event)
{
   view->resize(this->width(), this->height());
   QWidget::resizeEvent(event);


}

