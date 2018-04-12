#pragma once

#include "ofMain.h"

#include "ofApp.h"
#include "QtGLWidget.h"
#include "ui_myWidget_A.h"

// include Qt always at the end or face glew error
#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>

class myWidget_A : public QWidget
{
	Q_OBJECT

public:
	myWidget_A( QWidget *parent = Q_NULLPTR);
	~myWidget_A();

	QHBoxLayout *layout;
	shared_ptr<ofApp> ofAppPtr;
	void changeEvent(QEvent *e);

private:
	Ui::myWidget_A ui;

public slots:
	void on_Size_slider_sliderMoved(int value);
	void on_FPS_slider_sliderMoved(int value);
	void on_VerticalSync_checkbox_stateChanged(int value);
};
