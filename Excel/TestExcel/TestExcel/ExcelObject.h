#include "xlsxdocument.h"

using namespace QXlsx;

class ExcelObject
{
public:
	ExcelObject(QString fileName, QStringList sheetNames);
	~ExcelObject();
	void save();
	void set_sheet_title(QString sheet_name, QStringList sheetTitles, double col_width, Format header_format);
	void set_sheet_title(QString sheet_name, QStringList sheetTitles, double col_width = 20.0);
	void set_result(QString sheet_name, QList<QList<qreal>> data);
private:
	QString file_name;
	QStringList sheets_names;
	Document xlsxW;
};

