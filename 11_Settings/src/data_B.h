#pragma once

#include "ofParameterGroup.h"
#include <QVariant>

enum MyRoles {
	maxRange = Qt::UserRole
	, minRange
	, myRole3
};

class Data_B {

// 	Data_B() {
// 	}

// 	struct DataStruct {
// 		QString label;
// 		QVariant value;
// 	};

public:
	ofParameterGroup paramGroup;

	int getColumnCount() const {
		return 2;
	}

	int getRowCount() const {
		return paramGroup.size();
	}


	QVariant getData(int row, int col) const {
		switch (col) {
		case 0: 
			return QVariant::fromValue(QString(paramGroup[row].getName().c_str()));
		case 1: 
			return QVariant::fromValue(paramGroup[row].cast<float>().get());
		default:
			return QString("");
		}
	}

	QVariant getMax(int row) const {
		auto max = paramGroup[row].cast<float>().getMax();
		return QVariant(max);
	}

	void setData(int row, int col, const QVariant & value) {
		switch (col) {
		case 0: 
			paramGroup[row].setName(value.toString().toStdString());
			break;
		case 1: 
			paramGroup[row].cast<float>() = value.toFloat();
			break;
		default:
			break;
		}
	}

	ofAbstractParameter & getOfParameter(int row, int col) {
		switch (col) {
		case 0: 
			return paramGroup[row];
		case 1: 
			return paramGroup[row];
//		default:
//			return QString("");
		}
	};
};
