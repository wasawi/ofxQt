#pragma once

#include "starrating.h"
#include <QVariant>

class Data_B {

	struct DataStruct {
		QString label;
		QVariant value;
	};

public:
	int COLS = 2;
	int ROWS = 5;

	Data_B() {
		myData[0] = { "width", 50 };
		myData[1] = { "height", 20 };
		myData[2] = { "xpos", 30 };
		myData[3] = { "ypos", 50 };
		myData[4] = { "angle", 20 };
	}

	QVariant getData(int row, int col) const {
		switch (col) {
		case 0: return QVariant::fromValue(myData[row].label);
		case 1: return QVariant::fromValue(myData[row].value);
		default:
			return QString("");
		}
	}

	void setData(int row, int col, const QVariant & value) {
		switch (col) {
		case 0: myData[row].label = value.toString();
			break;
		case 1: myData[row].value = value.toFloat();
			break;
		default:
			break;
		}
	}
	DataStruct myData[5];
};
