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

QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem & option,
    const QModelIndex & index ) const
{

	QWidget* editor = new QWidget(parent);

	QSlider *slider = new QSlider(editor);
	slider->setOrientation(Qt::Orientation::Horizontal);
	slider->setMinimumHeight(20);
	slider->setMinimumWidth(100);
	// Todo: 
	// find a way to get properties from QModelIndex
	// so that we can set dynamic ranges...		
	slider->setMinimum(0);
	slider->setMaximum(100);


	QSpinBox *spinbox = new QSpinBox(editor);
	spinbox->setMinimumWidth(20);
	spinbox->setFrame(false);
	spinbox->setMinimum(0);
	spinbox->setMaximum(100);
	spinbox->selectAll(); //<- not working!

	connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
	connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(onSpinboxValueChanged(int)));

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(slider);
	layout->addWidget(spinbox);
	editor->setLayout(layout);

	return editor;
}

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
}

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
}

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

void SpinBoxDelegate::onSpinboxValueChanged(int)
{
	QSpinBox* sb = static_cast<QSpinBox*>(sender());
	if (sb) {
		QWidget* w = static_cast<QWidget*>(sb->parent());
		if (w) {
			emit commitData(w);
		}
	}
}

//! [4]
