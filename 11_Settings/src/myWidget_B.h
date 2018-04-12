#pragma once

#include "ofMain.h"

#include "ofApp.h"
#include "QtGLWidget.h"
#include "ui_myWidget_B.h"

// include Qt always at the end or face glew error
#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>

class myWidget_B : public QWidget
{
	Q_OBJECT

public:
	myWidget_B( QWidget *parent = Q_NULLPTR);
	~myWidget_B();

	QHBoxLayout *layout;
	shared_ptr<ofApp> ofAppPtr;
	void changeEvent(QEvent *e);

private:
	Ui::myWidget_B ui;

public slots:
	void on_Size_slider_sliderMoved(int value);
	void on_FPS_slider_sliderMoved(int value);
	void on_VerticalSync_checkbox_stateChanged(int value);
};
