#pragma once

#include "ofMain.h"
// for cout
#include <iostream>
using namespace std;

#include "ui_QtGuiClass.h"

/* 
// Using a Multiple Inheritance Approach
#include <QMainWindow>
#include "ui_QtGuiClass.h"
class QtGuiClass : public QMainWindow, public Ui::QtGuiClass
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

	int circleRadius;
	ofColor color;

private slots:
	void on_Slider_valueChanged(int value);
	void on_pushButton_pressed();
	void on_pushButton_released();
};
*/


// Using a Pointer Member Variable Approach
#include <QMainWindow>
namespace Ui { 
	class QtGuiClass; 
};

class QtGuiClass : public QMainWindow
{
	Q_OBJECT

public:
	explicit QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

	void setRadius(int value) { ui->Slider->setValue(value); };
	void setColor(ofColor value) { color = value; };

	float& getRadius() {return circleRadius; };
	ofColor& getColor() { return color; };

private:
	Ui::QtGuiClass *ui;
	float circleRadius;
	ofColor color;

private slots:
	void on_Slider_valueChanged(int value);
	void on_pushButton_pressed();
	void on_pushButton_released();
};
