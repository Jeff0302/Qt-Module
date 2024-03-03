#include "ExcelObject.h"

ExcelObject::ExcelObject(QString fileName, QStringList sheetNames)
{
	file_name = fileName;
	sheets_names = sheetNames;
	QStringList sheets_names_old = xlsxW.sheetNames();
	//qDebug() << sheets_names_old;

	//刪除預設sheet
	QStringList::iterator iter;
	for ( iter = sheets_names_old.begin(); iter != sheets_names_old.end(); iter++)
	{
		xlsxW.deleteSheet(*iter);
	}
	//新增指定sheet
	for (iter = sheets_names.begin(); iter != sheets_names.end(); iter++)
	{
		xlsxW.addSheet(*iter);
	}

	

}

ExcelObject::~ExcelObject()
{
}

void ExcelObject::save()
{
	xlsxW.saveAs(file_name);
}

void ExcelObject::set_sheet_title(QString sheet_name, QStringList sheetTitles, double col_width, Format header_format)
{
	xlsxW.selectSheet(sheet_name);

	QStringList::iterator iter;
	int i = 1;
	for (iter = sheetTitles.begin(); iter != sheetTitles.end(); iter++)
	{
		xlsxW.setColumnWidth(i, col_width);
		xlsxW.write(1, i, *iter, header_format);
		i++;
	}
}

void ExcelObject::set_sheet_title(QString sheet_name, QStringList sheetTitles, double col_width)
{
	xlsxW.selectSheet(sheet_name);

	Format header;
	header.setFontBold(true);
	header.setPatternBackgroundColor(QColor(146, 205, 220));
	header.setHorizontalAlignment(Format::AlignHCenter);

	QStringList::iterator iter;
	int i = 1;
	for (iter = sheetTitles.begin(); iter != sheetTitles.end(); iter++)
	{
		xlsxW.setColumnWidth(i, col_width);
		xlsxW.write(1, i, *iter, header);
		i++;
	}
}

void ExcelObject::set_result(QString sheet_name, QList<QList<qreal>> data)
{
	xlsxW.selectSheet(sheet_name);
	int row = data.size();
	int col = data.at(0).size();
	//qDebug() << row;
	//qDebug() << col;
	Format format;
	format.setHorizontalAlignment(Format::AlignHCenter);
	for (int i = 1; i <= row; i++) 
		for (int j = 1;  j <= col;  j++)
			xlsxW.write(i + 1, j, data.at(i - 1).at(j - 1), format);
}
