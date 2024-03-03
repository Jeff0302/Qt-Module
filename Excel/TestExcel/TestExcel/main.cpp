
#include "testexcel.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestExcel w;
    w.show();
    return a.exec();
}
