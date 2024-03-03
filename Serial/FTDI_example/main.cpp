
#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>
#include "ftd2xx.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "FTDI_example_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    FT_STATUS ftStatus;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    DWORD numDevs; // create the device information list
    ftStatus = FT_CreateDeviceInfoList(&numDevs);
    if (ftStatus == FT_OK)
    {
        printf("Number of devices is %d\n",numDevs);
    }
    if (numDevs > 0)
    {
        // allocate storage for list based on numDevs
        devInfo = (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs);
        // get the device information list
        ftStatus = FT_GetDeviceInfoList(devInfo,&numDevs);
        if (ftStatus == FT_OK)
        {
            for (int i = 0; i < numDevs; i++)
            {
              printf("Dev %d:\n",i);
              printf(" Flags=0x%x\n",devInfo[i].Flags);
              printf(" Type=0x%x\n",devInfo[i].Type);
              printf(" ID=0x%x\n",devInfo[i].ID);
              printf(" LocId=0x%x\n",devInfo[i].LocId);
              printf(" SerialNumber=%s\n",devInfo[i].SerialNumber);
              printf(" Description=%s\n",devInfo[i].Description);
              printf(" ftHandle=0x%x\n",devInfo[i].ftHandle);
            }
        }
    }
    return a.exec();
}
