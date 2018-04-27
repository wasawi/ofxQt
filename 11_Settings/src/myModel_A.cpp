
#include "myModel_A.h"
#include <QDebug>

MyModel_A::MyModel_A(QObject *parent)
    :QAbstractTableModel(parent)
{

    // setHeaderData(0, Qt::Horizontal, tr("Title"));
    // setHeaderData(1, Qt::Horizontal, tr("Genre"));
    // setHeaderData(2, Qt::Horizontal, tr("Artist"));
    // setHeaderData(3, Qt::Horizontal, tr("Rating"));

}
//-----------------------------------------------------------------
MyModel_A::~MyModel_A()
{
    qDebug() << "Ctor";
}

//-----------------------------------------------------------------
int MyModel_A::rowCount(const QModelIndex & /*parent*/) const
{
    return myData.ROWS;
}

//-----------------------------------------------------------------
int MyModel_A::columnCount(const QModelIndex & /*parent*/) const
{
    return myData.COLS;
}

//-----------------------------------------------------------------
QVariant MyModel_A::data(const QModelIndex &index, int role) const
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
bool MyModel_A::setData(const QModelIndex & index, const QVariant & value, int role)
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
Qt::ItemFlags MyModel_A::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

