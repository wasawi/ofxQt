#pragma once

#include "ofMain.h"

#include "QtGLWidget.h"

#include "ofApp_A.h"
#include "myModel_A.h"
#include "ui_myWidget_A.h"

// include Qt always at the end or face glew error
#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>
#include <QTableView>

class MyWidget_A : public QWidget
{
	Q_OBJECT

public:
	MyWidget_A( 
		QWidget *parent = Q_NULLPTR
		, MyModel_A* model_A = Q_NULLPTR
	);
	~MyWidget_A();

	MyModel_A* myModel_A;
	QTableView* tableView;

	QHBoxLayout *layout;
	shared_ptr<ofApp_A> ofAppPtr;
	void changeEvent(QEvent *e);

private:
	Ui::MyWidget_A ui;

public slots:
	void on_Size_slider_sliderMoved(int value);
	void on_FPS_slider_sliderMoved(int value);
	void on_VerticalSync_checkbox_stateChanged(int value);
	void updateUI(ofEventArgs& event);
};
