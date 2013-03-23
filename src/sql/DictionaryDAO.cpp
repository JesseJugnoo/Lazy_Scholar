#include "DictionaryDAO.hpp"
#include "DictionaryVO.hpp"


QVariantList DictionaryDAO::getDictionaryAll(){
	QString sql = "SELECT character,"
						"language,"
						"translate,"
						"pronun,"
						"strokes,"
						"level,"
						"image"
						" FROM " + table + extra_sql;


	QVariant result = sda->execute(sql);

	if (sda->hasError()){
		qDebug() << sda->error() << endl;
	}
	return result.value<QVariantList>();
}

QVariantMap DictionaryDAO::getDictionaryByChar(QString ch){
	extra_sql = "WHERE character=" + ch;
	QVariantList result = getDictionaryAll();

	QVariantMap map;

	switch(result.size()){
	case 0:
		//nothing, return empty map
		break;
	case 1:
		map = result[0].toMap();
		break;
	default:
		throw "Data has more than one character " + ch;

	}

	return map;

}

DictionaryVO DictionaryDAO::getVO(QVariantMap map){
	DictionaryVO dict;

	if (map.contains("character")){
		dict.setCharacter(map["character"].toString());
	}

	if (map.contains("language")){
		dict.setLanguage(map["language"].toString());
	}

	if (map.contains("translate")){
		dict.setTranslate(map["translate"].toString());
	}

	if (map.contains("pronun")){
		dict.setPronunciation(map["pronun"].toString());
	}

	if (map.contains("image")){
		dict.setImage(map["image"].toString());
	}

	if (map.contains("strokes")){
		dict.setStrokes(map["strokes"].toInt());
	}

	if (map.contains("level")){
		dict.setLevel(map["level"].toInt());
	}
	return dict;

}

DictionaryVO DictionaryDAO::getDictionaryByCharVO(QString ch){
	DictionaryVO result;

	QVariantMap map = getDictionaryByChar(ch);
	if (map.size() != 0){
		result = getVO(map);
	}
	return result;

}

vector<DictionaryVO> DictionaryDAO::getDictionaryAllVO(){
	vector<DictionaryVO> result;

	QVariantList list = getDictionaryAll();

	for(int i = 0; i < list.size(); i++){
		DictionaryVO dict = getVO(list[i].toMap());
		result.push_back(dict);
	}
	return result;
}


vector<DictionaryVO> DictionaryDAO::getDictionaryByLanguageAndLevelVO(QString language, QString level){

	extra_sql = " WHERE language='"+language+ "' AND level="+level;

	vector<DictionaryVO> result = getDictionaryAllVO();

	return result;

}

