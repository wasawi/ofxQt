#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>
#include <QSpinBox>
#include <QSlider>
#include <QLayout>

#include "MyWidget_autoselect.h"
#include "data_B.h"

// class Autoselect_filter : public QObject
// {
// 	Q_OBJECT
// public:
// 	Autoselect_filter(QObject *parent = nullptr)
// 		: QObject(parent) {}
// protected:
// 	bool eventFilter(QObject *obj, QEvent *event) {
// 		if (event->type() == QEvent::FocusIn) {
// 			auto *spinbox = qobject_cast<QSpinBox *>(obj);
// 			if (spinbox != NULL)
// 			{
// 				spinbox->setFocus();
// 				spinbox->selectAll();
// 			}
// 			else {
// //				Q_ASSERT(spinbox);
// 			}
// 			return true;
// 		}
// 		else {
// 			// standard event processing
// 			return QObject::eventFilter(obj, event);
// 		}
// 	}
// };

//! [0]
class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    SpinBoxDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const override;

	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

//private:
public slots :
	void onSpinboxValueChanged(int);

};

#endif
