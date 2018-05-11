
#include "MyModel_B.h"
#include <QDebug>
#include <QTableView>

MyModel_B::MyModel_B(QObject *parent)
    : QAbstractTableModel(parent)
{
	qDebug() << "Ctor";
	setModuleName("Model_B");

	myData.paramGroup.add(size.set("size", 50, 1, 100));
	myData.paramGroup.add(angle.set("angle", 50, 0, 360));
	myData.paramGroup.add(posX.set("posX", 0.0f, 0.0f, 100));
	myData.paramGroup.add(posY.set("posY", 0.0f, 0.0f, 100));

//	loadSettings(myData.paramGroup);

}
//-----------------------------------------------------------------
MyModel_B::~MyModel_B()
{
	qDebug() << "Dtor";
	saveSettings(myData.paramGroup);
}

//-----------------------------------------------------------------
int MyModel_B::rowCount(const QModelIndex & /*parent*/) const
{
    return myData.getRowCount();
}

//-----------------------------------------------------------------
int MyModel_B::columnCount(const QModelIndex & /*parent*/) const
{
    return myData.getColumnCount();
}

//-----------------------------------------------------------------
QVariant MyModel_B::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
//        return m_gridData[index.row()][index.column()];
        return myData.getData(index.row(),index.column());
    }
    // this gets called when we are in edit mode.
    // we want to get the last value when we start editing
    if (role == Qt::EditRole){
        return myData.getData(index.row(),index.column());
    }
    return QVariant();
}

//-----------------------------------------------------------------
bool MyModel_B::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        //save value from editor to member m_gridData
//        m_gridData[index.row()][index.column()] = value.toString();
        qDebug() << value;
		if (index.column() == 0) return false;

		myData.setData(index.row(),index.column(),value);

        // automatically update views
        dataChanged(index, index);
    }
    return true;
}

//-----------------------------------------------------------------
Qt::ItemFlags MyModel_B::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

ofAbstractParameter & MyModel_B::getOfParameter(const QModelIndex &index)
{
	return myData.getOfParameter(index.row(), index.column());
}

