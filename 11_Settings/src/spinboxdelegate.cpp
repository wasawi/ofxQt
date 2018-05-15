#include "spinboxdelegate.h"

SpinBoxDelegate::SpinBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem & option,
    const QModelIndex & index ) const
{
	MyWidget_autoselect* editor = new MyWidget_autoselect(parent);
	editor->setAutoFillBackground(true);

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
	
// 	Autoselect_filter *autoselect_filter = new Autoselect_filter(parent);
// 	spinbox->installEventFilter(autoselect_filter);

	connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
	connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(onSpinboxValueChanged(int)));
//	connect(editor, SIGNAL(focusInEvent(QFocusEvent *)), this, SLOT(focusInEvent(QFocusEvent *)));

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(slider);
	layout->addWidget(spinbox);
	layout->setMargin(0);
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
