#pragma once
#include <QVariant>

class Data {

	struct DataStruct {
		QString title;
		QString genre;
		QString artist;
		int rating;
	};

public:
	int COLS = 4;
	int ROWS = 4;

	Data() {
		myData[0] = { "Mass in B-Minor", "Baroque", "J.S. Bach", 5 };
		myData[1] = { "Three More Foxes", "Jazz", "Maynard Ferguson", 4 };
		myData[2] = { "Sex Bomb", "Pop", "Tom Jones", 3 };
		myData[3] = { "Barbie Girl", "Pop", "Aqua", 5 };
	}


	QVariant getData(int row, int col) const {
		switch (col) {
		case 0: return QVariant::fromValue(myData[row].title);
		case 1: return QVariant::fromValue(myData[row].genre);
		case 2: return QVariant::fromValue(myData[row].artist);
			//    case 3: return QVariant::fromValue(StarRating(myData[row].rating));
		default:
			return QString("");
		}
	}

	void setData(int row, int col, const QVariant & value) {
		switch (col) {
		case 0: myData[row].title = value.toString();
			break;
		case 1: myData[row].genre = value.toString();
			break;
		case 2: myData[row].artist = value.toString();
			break;
			//QVariant::fromValue(StarRating(row, col).toInt());
			//QVariant::fromValue(StarRating(value.toInt())).toInt()
		case 3: myData[row].rating = value.toInt();
			break;
		default:
			break;
		}
	}
	DataStruct myData[4];
};