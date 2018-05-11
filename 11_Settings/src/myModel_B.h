#pragma once
#include "data_B.h"
#include "myModelSettings.h"
#include "ofxImGuiWidgets.h"

#include <QAbstractTableModel>

class MyModel_B : 
	public QAbstractTableModel,
	public MyModelSettings
{
    Q_OBJECT

public:
    MyModel_B(QObject *parent);
    ~MyModel_B();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex & index) const override ;

	ofAbstractParameter & getOfParameter(const QModelIndex &index);

//private:
    Data_B myData;

	SliderFloat size;
	SliderFloat angle;
	SliderFloat posX;
	SliderFloat posY;

signals:
//    void editCompleted(const QString &);
};
