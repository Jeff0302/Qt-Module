#include <QCoreApplication>
#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#ifndef SERIALTOOLS_H
#define SERIALTOOLS_H
#endif // SERIALTOOLS_H

/*
    get available comports

    return: portNames --> QStringList
*/
QStringList get_all_comport();

/*
    判斷是否為偶數長度的16進字串

    return: bool
*/
bool reg_hex_only(QString &hexStr);

/*
    16進字串轉 QByteArray

    return: QByteArray
*/
QByteArray hexStr_to_qbyteArray(QString &hexStr);

/*
    QByteArray轉16進字串 (QString::number(int, base))

    return: QByteArray
*/
QString qbyteArray_to_hexStr(QByteArray &array);

void write_hex_to_comport(QSerialPort& port, QString &hex_str);

void write_str_to_comport(QSerialPort& port, QString &str);

/*
    以16進制讀取指定comport

    return: QString
*/
QString read_hex_from_comport(QSerialPort& port, int ms=100);

/*
    以ascii讀取指定comport

    return: QString
*/
QString read_ascii_from_comport(QSerialPort& port, int ms=100);
