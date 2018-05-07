
#include "MyModel_B.h"
#include <QDebug>

MyModel_B::MyModel_B(QObject *parent)
    : QAbstractTableModel(parent)
{
	setModuleName("Model_B");

//	ofParameter<bool> autoloadIRG;
//	settings.add(autoloadIRG.set("autoloadIRG", true));

	// setHeaderData(0, Qt::Horizontal, tr("Title"));
    // setHeaderData(1, Qt::Horizontal, tr("Genre"));
    // setHeaderData(2, Qt::Horizontal, tr("Artist"));
    // setHeaderData(3, Qt::Horizontal, tr("Rating"));

}
////-----------------------------------------------------------------
//MyModel_B::~MyModel_B()
//{
//    qDebug() << "Ctor";
//}

//-----------------------------------------------------------------
int MyModel_B::rowCount(const QModelIndex & /*parent*/) const
{
    return myData.ROWS;
}

//-----------------------------------------------------------------
int MyModel_B::columnCount(const QModelIndex & /*parent*/) const
{
    return myData.COLS;
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

