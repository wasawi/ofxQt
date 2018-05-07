#pragma once

#include "starrating.h"
#include <QVariant>

class Data_A {

	struct DataStruct {
		QString label;
		QVariant value;
	};

public:
	int COLS = 2;
	int ROWS = 3;

	Data_A() {
		myData[0] = { "scale", 50 };
		myData[1] = { "xpos", 30 };
		myData[2] = { "ypos", 50 };
	}

	QVariant getData(int row, int col) const {
		switch (col) {
		case 0: return QVariant::fromValue(myData[row].label);
//		case 1: return QVariant::fromValue(myData[row].value);
		case 1: return QVariant::fromValue(StarRating(myData[row].value.toInt()));
		default:
			return QString("");
		}
	}

	void setData(int row, int col, const QVariant & value) {
		switch (col) {
		case 0: myData[row].label = value.toString();
			break;
		case 1: myData[row].value = value.toInt();
			break;
		default:
			break;
		}
	}
	DataStruct myData[4];
};
