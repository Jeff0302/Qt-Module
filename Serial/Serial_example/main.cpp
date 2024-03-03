#include <QCoreApplication>
#include "serialTools.h"
#include <QDebug>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //獲取可用comports
    QStringList avail_ports = get_all_comport();

    qDebug()<<avail_ports[0];

    //創建 QSerialPort對象
    QSerialPort my_serial(avail_ports[0]);
    //buadRate設置方式
    my_serial.setBaudRate(QSerialPort::BaudRate::Baud115200);
    //serial port的打開方式
    if(my_serial.open(QIODevice::ReadWrite))
    {
        //serial port寫入字串
        QTextStream cin(stdin,QIODevice::ReadOnly);
        QString a;
        bool run = true;
        while(run)
        {
                    a = cin.readLine();
                    if(a == "exit")
                    {
                        break;
                    }
                    else if(a=="read_hex"){
                        qDebug() << read_hex_from_comport(my_serial);
                    }
                    else if(a=="read_ascii"){
                        qDebug() << read_ascii_from_comport(my_serial);
                    }
                    else
                    {
                        if(reg_hex_only(a))
                        {
                            //需要調用waitForBytesWritten()方法，這樣在沒有事件循環的情況下，才能寫入
                            //my_serial.waitForBytesWritten();
                            //write只有在進入事件循環才會執行
                            //send hex
                            //my_serial.write(hexStr_to_qbyteArray(a));
                            write_hex_to_comport(my_serial, a);
                        }
                        else {
                            write_str_to_comport(my_serial, a);
                            //my_serial.waitForBytesWritten();
                            //QString轉const char*
                            //send ascii
                            //my_serial.write(a.toLocal8Bit().constData());

                        }

                    }
        }
    }
    //serial.close();


    //常用設置，一般情況下只會改buadRate
    /*
        qDebug()<< serial.baudRate();
        qDebug()<< serial.dataBits();
        qDebug()<< serial.stopBits();
        qDebug()<< serial.parity();
        qDebug()<< serial.flowControl();
    */
    return a.exec();
}
