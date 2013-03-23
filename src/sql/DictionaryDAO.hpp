#ifndef _DICTDAO_
#define _DICTDAO_

#include "DictionaryVO.hpp"
#include <QDir>
#include <bb/data/SqlDataAccess>
using namespace bb::data;



class DictionaryDAO{
private:
	QString table;
	QString extra_sql;
	SqlDataAccess *sda;

	QVariantList getDictionaryAll();
	QVariantMap getDictionaryByChar(QString ch);
	DictionaryVO getVO(QVariantMap map);
	
public:
	DictionaryDAO(){
		table = "dictionary";
		sda = new SqlDataAccess(QDir::currentPath() + "/app/native/assets/lazy_scholar.sqlite");
	}
	~DictionaryDAO(){
		delete sda;
	}

	DictionaryVO getDictionaryByCharVO(QString ch);
	vector<DictionaryVO> getDictionaryByLanguageAndLevelVO(QString language, QString level);
	vector<DictionaryVO> getDictionaryAllVO();


};

#endif
