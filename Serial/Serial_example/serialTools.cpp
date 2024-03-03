#include "serialTools.h"
QStringList get_all_comport()
{
    QStringList avail_ports;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        avail_ports.append(info.portName());
    }

    return avail_ports;
}

bool reg_hex_only(QString &hexStr)
{
    QRegExp reg_hex_only("([0-9A-F][0-9A-F])+");
    //qDebug() << "Is RegExp correct? "<< reg_hex_only.exactMatch(hexStr);
    return reg_hex_only.exactMatch(hexStr);
}

QByteArray hexStr_to_qbyteArray(QString &hexStr){
    QByteArray temp;
    bool ok = false;
    for(int i=0;i<hexStr.length();i=i+2)
    {
        temp.append(hexStr.midRef(i,2).toInt(&ok,16));
    }
    return temp;
}

QString qbyteArray_to_hexStr(QByteArray &array){
    QString temp;
    for(char c: array)
        temp = temp + QString::number((int)(c),16);

    return temp;
}

void write_hex_to_comport(QSerialPort& port, QString &hex_str){
    //需要調用waitForBytesWritten()方法，這樣在沒有事件循環的情況下，才能寫入
    port.waitForBytesWritten();
    port.write(hexStr_to_qbyteArray(hex_str));

}

void write_str_to_comport(QSerialPort& port, QString &str){
    //需要調用waitForBytesWritten()方法，這樣在沒有事件循環的情況下，才能寫入
    port.waitForBytesWritten();
    port.write(str.toLocal8Bit().constData());
}

QString read_hex_from_comport(QSerialPort& port, int ms){
    QByteArray temp;

    port.waitForReadyRead(ms);
    //qDebug()<<"Available: " <<port.bytesAvailable();
    temp = port.readAll();
    //qDebug()<<"Available: " <<port.bytesAvailable();

    return qbyteArray_to_hexStr(temp);
}

QString read_ascii_from_comport(QSerialPort& port, int ms){
    QByteArray temp;

    port.waitForReadyRead(ms);
    //qDebug()<<"Available: " <<port.bytesAvailable();
    temp = port.readAll();
    //qDebug()<<"Available: " <<port.bytesAvailable();

    return QString::fromLocal8Bit(temp);
}
