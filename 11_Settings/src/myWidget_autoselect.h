#pragma once

#include <QWidget>
#include <QSpinBox>
#include <QLayout>

class MyWidget_autoselect : public QWidget
{
	Q_OBJECT

public:
	MyWidget_autoselect(QWidget *parent = nullptr)
		: QWidget(parent) {}
protected:
	void focusInEvent(QFocusEvent *event) {
		auto *spinbox = static_cast<QSpinBox *>(layout()->itemAt(1)->widget());
		Q_ASSERT(spinbox);
		spinbox->setFocus();
		spinbox->selectAll();
		QWidget::focusInEvent(event);
	}
};
