#pragma once

#include "ofMain.h"

#include "QtGLWidget.h"

#include "ofApp_B.h"
#include "myModel_B.h"
#include "ui_myWidget_B.h"
#include "spinboxdelegate.h"

// include Qt always at the end or face glew error
#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>
#include <QTableView>

class MyWidget_B : public QWidget
{
	Q_OBJECT

public:
	MyWidget_B( 
		QWidget *parent = Q_NULLPTR
		, MyModel_B* model_B = Q_NULLPTR
	);
	~MyWidget_B();

	MyModel_B* myModel_B;

	QHBoxLayout *layout;
	shared_ptr<ofApp_B> ofAppPtr;
	void changeEvent(QEvent *e);

private:
	Ui::MyWidget_B ui;

public slots:
	void on_Size_slider_sliderMoved(int value);
	void on_Angle_slider_sliderMoved(int value);
	void on_FPS_slider_sliderMoved(int value);
	void on_VerticalSync_checkbox_stateChanged(int value);
	void updateUI(ofEventArgs& event);
};
 