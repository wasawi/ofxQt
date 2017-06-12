#pragma once

#include "ofMain.h"

#include "ofApp.h"
#include "QtGLWidget.h"
#include "ui_device.h"

#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>

class device : public QWidget
{
	Q_OBJECT

public:
	device( QWidget *parent = Q_NULLPTR);
	~device();

	QHBoxLayout *layout;
	QTimer *timer;
	
	shared_ptr<ofApp> ofAppPtr;
	shared_ptr<ofMainLoop> loop;
	shared_ptr<ofAppQtWindow> windowPtr;

private:
	Ui::device ui;

public slots:
	void on_horizontalSlider_sliderMoved(int value);
	void on_horizontalSlider_2_sliderMoved(int value);
	void newframe();
};
