#pragma once

#include "ofMain.h"
// for cout
#include <iostream>
using namespace std;

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
namespace Ui { class QtGuiClass; };

class QtGuiClass : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

	int circleRadius;
	ofColor color;

private:
	Ui::QtGuiClass *ui;

private slots:
	void on_Slider_valueChanged(int value);
	void on_pushButton_pressed();
	void on_pushButton_released();
};
