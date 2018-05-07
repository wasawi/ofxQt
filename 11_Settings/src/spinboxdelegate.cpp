/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

/*
    delegate.cpp

    A delegate that allows the user to change integer values from the model
    using a spin box widget.
*/

#include "spinboxdelegate.h"

#include <QSpinBox>
#include <QSlider>
#include <QLayout>

//! [0]
SpinBoxDelegate::SpinBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}
//! [0]

//! [1]
QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem & option,
    const QModelIndex & index ) const
{

	QWidget* f = new QWidget(parent);
	f->setAutoFillBackground(true);

	QSlider *editor1 = new QSlider(f);
	editor1->setOrientation(Qt::Orientation::Horizontal);
	editor1->setMinimumHeight(20);
	editor1->setMinimumWidth(100);
	editor1->setMinimum(0);
	editor1->setMaximum(100);
	QSpinBox *editor2 = new QSpinBox(f);
	editor2->setMinimumHeight(20);
	editor2->setMinimumWidth(20);
	editor2->setFrame(false);
	editor2->setMinimum(0);
	editor2->setMaximum(100);

	connect(editor1, SIGNAL(valueChanged(int)), editor2, SLOT(setValue(int)));
	connect(editor2, SIGNAL(valueChanged(int)), editor1, SLOT(setValue(int)));

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(editor1);
	layout->addWidget(editor2);
	f->setLayout(layout);

	return f;

// 	QFrame  *f = new QFrame(parent);
// 	QSlider *editor1 = new QSlider(f);
// 	editor1->setOrientation(Qt::Orientation::Horizontal);
// 	editor1->setMinimumWidth(100);
// 	editor1->setMinimum(0);
// 	editor1->setMaximum(100);
//	QSpinBox *editor2 = new QSpinBox(f);
// 	editor1->setMinimumWidth(20);
// 	editor2->setFrame(false);
//	editor2->setMinimum(0);
//	editor2->setMaximum(100);
// 	f->adjustSize();
//	return f;

// 	QSpinBox *editor = new QSpinBox(parent);
// 	editor->setFrame(false);
// 	editor->setMinimum(0);
// 	editor->setMaximum(100);

//	
//	return editor;

}
//! [1]

//! [2]
void SpinBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

	for (auto widget : editor->findChildren<QSlider*>()) {
		widget->setValue(value);
	}
	for (auto widget : editor->findChildren<QSpinBox*>()) {
		widget->setValue(value);
	}

//	QFrame *frame = static_cast<QFrame*>(editor);
//	QLayout* layout = editor->layout();
// 	QObjectList theList = editor->children();
// 	QListIterator<QObject *> i(theList);
// 	while (i.hasNext())
// 	{
// 		QSlider* slider = qobject_cast<QSlider*>(i.next());
// 		if (slider != Q_NULLPTR) {
// 			slider->setValue(value);
// 		}
// 
// 		QSpinBox* spinbox = qobject_cast<QSpinBox*>(i.next());
// 		if (spinbox != Q_NULLPTR) {
// 			spinbox->setValue(value);
// 		}
// 	}

// 	QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
// 	spinBox->setValue(value);

}
//! [2]

//! [3]
void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
	int value = index.model()->data(index, Qt::EditRole).toInt();
	for (auto widget : editor->findChildren<QSlider*>()) {
		value = widget->value();
	}
	for (auto widget : editor->findChildren<QSpinBox*>()) {
		value = widget->value();
	}
	model->setData(index, value, Qt::EditRole);

	//	QFrame *frame = static_cast<QFrame*>(editor);
	// 	QLayout* layout = editor->layout();
	// 	QObjectList theList = layout->children();
	// 	QListIterator<QObject *> i(theList);
	// 	while (i.hasNext())
	// 	{
	// 		QSlider* slider = qobject_cast<QSlider*>(i.next());
	// 		if (slider != Q_NULLPTR) {
	// 			value = slider->value();
	// 		}
	// 
	// 		QSpinBox* spinbox = qobject_cast<QSpinBox*>(i.next());
	// 		if (spinbox != Q_NULLPTR) {
	// 			value = spinbox->value();
	// 		}
	// 	}

//     QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
//     spinBox->interpretText();
//     int value = spinBox->value();
// 
//     model->setData(index, value, Qt::EditRole);
}
//! [3]

//! [4]
void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{

    editor->setGeometry(option.rect);
	editor->adjustSize();

}

QSize SpinBoxDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
//	auto hint = QStyledItemDelegate::sizeHint(option, index);
//	auto hint = QSize(200, 25);
	auto hint = option.rect.size();

	return hint;
}

//! [4]
