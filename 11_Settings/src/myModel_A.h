#pragma once
#include "data_A.h"
#include "myModelSettings.h"

#include <QAbstractTableModel>

class MyModel_A : 
	public QAbstractTableModel,
	public MyModelSettings
{
    Q_OBJECT

public:
	MyModel_A(QObject *parent);
	~MyModel_A();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex & index) const override ;

private:
    Data_A myData;

signals:
//    void editCompleted(const QString &);
};
