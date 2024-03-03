#ifndef SIMPLECHART_H
#define SIMPLECHART_H

#include <QWidget>
#include <QtWidgets>
#include <QtCharts>
using namespace QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class SimpleChart; }
QT_END_NAMESPACE

class SimpleChart : public QWidget
{
    Q_OBJECT

public:
    SimpleChart(QWidget *parent = nullptr);
    void set_y2_visible(bool);
    QScatterSeries *add_line_y(QString);
    QScatterSeries *add_line_y2(QString);
    void remove_all_y_lines();
    void remove_all_y2_lines();
    void remove_line_y(QScatterSeries *);
    void remove_line_y2(QScatterSeries *);
    QList<QPointF> get_line_y_data(QScatterSeries *);
    static void append_line_y_data(QScatterSeries *, float, float);
    static void append_line_y_data(QScatterSeries *, QList<QPointF> &);
    void set_legend(bool visible, Qt::Alignment alignment, QFont font);
    void set_axes_range(qreal xmin=0.0, qreal xmax=100.0, qreal ymin=0, qreal ymax=100, qreal y2min=0, qreal y2max=100);
    void set_chart_titile(QString);
    void set_chart_title_font(QFont);
    void set_chart_title_brush(QColor);
    void set_chart_background(QColor color,qreal opacity);
    void set_label_format(QString x, QString y, QString y2);
    void set_axis_name(QString x_title, QString y_title, QString y2_title);
    void set_axis_label_font(QFont);
    void set_axis_title_font(QFont);
    QValueAxis * get_axis(QString axis="x");
    QVector<QScatterSeries *> get_line_ys();
    QVector<QScatterSeries *> get_line_y2s();


    ~SimpleChart();

private:
    Ui::SimpleChart *ui;
    QChartView *view;
    QValueAxis *axis_x;
    QValueAxis *axis_y;
    QValueAxis *axis_y2;
    QChart *chart;
    QVector<QScatterSeries *> line_ys;
    QVector<QScatterSeries *> line_y2s;
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};
#endif // SIMPLECHART_H
