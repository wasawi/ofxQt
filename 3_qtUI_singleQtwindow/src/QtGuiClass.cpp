#include "QtGuiClass.h"
#include "ui_QtGuiClass.h"

QtGuiClass::QtGuiClass(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::QtGuiClass) // if using Pointer Member Variable
{
	// if using Multiple Inheritance Approach
//	setupUi(this);

// if using Pointer Member Variable
	ui->setupUi(this);
}

QtGuiClass::~QtGuiClass()
{
	// if using Pointer Member Variable
	delete ui;
}

//http://doc.qt.io/qt-4.8/designer-using-a-ui-file.html#automatic-connections
void QtGuiClass::on_Slider_valueChanged(int value)
{
	cout << "Slider " << value << endl;
	circleRadius = value;
}
void QtGuiClass::on_pushButton_pressed()
{
	cout << "Button pressed " << endl;
	color = ofColor::red;
}
void QtGuiClass::on_pushButton_released()
{
	cout << "Button released " << endl;
	color = ofColor::white;
}
