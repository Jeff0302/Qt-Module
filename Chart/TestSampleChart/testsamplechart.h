#ifndef TESTSAMPLECHART_H
#define TESTSAMPLECHART_H

#include <QWidget>
#include <QRandomGenerator>


QT_BEGIN_NAMESPACE
namespace Ui { class TestSampleChart; }
QT_END_NAMESPACE

class TestSampleChart : public QWidget
{
    Q_OBJECT

public:
    TestSampleChart(QWidget *parent = nullptr);
    ~TestSampleChart();
public slots:
    void add_line();
    void add_data();
    void update_data();
    void get_data();
    void load_data();\

private:
    Ui::TestSampleChart *ui;
    QTimer *timer;
    bool timer_on;
};
#endif // TESTSAMPLECHART_H
