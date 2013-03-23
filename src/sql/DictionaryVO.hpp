#ifndef _DICTVO_
#define _DICTVO_

#include <QObject>
#include <QVariant>
#include <vector>
using namespace std;

//dictionary value object
class DictionaryVO{
protected:
	QString character;
	QString language;
	QString translate;
	QString pronun;
	QString image;
	int strokes;
	int level;

	vector<QString> errors;

public:
	bool isValid();

	vector<QString>getErrors(){
		return errors;
	}

	//Setters
	void setCharacter(QString s){
		character = s;
	}

	//Setters
	void setLanguage(QString s){
		language = s;
	}

	//Setters
	void setTranslate(QString s){
		translate = s;
	}

	//Setters
	void setPronunciation(QString s){
		pronun = s;
	}

	//Setters
	void setImage(QString s){
		image = s;
	}

	//Setters
	void setStrokes(int i){
		strokes = i;
	}

	//Setters
	void setLevel(int i){
		level = i;
	}

	//Getters
		QString getCharacter(){
			return character;
		}

		//Getters
		QString getLanguage(){
			return language;
		}

		//Getters
		QString getTranslate(){
			return translate;
		}

		//Getters
		QString getPronunciation(){
			return pronun;
		}

		//Getters
		QString getImage(){
			return image;
		}

		//Getters
		int getStrokes(){
			return strokes;
		}

		//Getters
		int getLevel(){
			return level;
		}

		QVariantMap toQVariantMap(){
			QVariantMap res;
			res["character"] = character;
			res["language"] = language;
			res["translate"] = translate;
			res["pronun"] = pronun;
			res["image"] = image;
			res["strokes"] = strokes;
			res["level"] = level;

			return res;
		}






};


#endif
