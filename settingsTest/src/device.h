#pragma once

#include "ofMain.h"

#include "ofApp.h"
#include "QtGLWidget.h"
#include "Base_window.h"
#include "ui_device.h"

// include Qt always at the end or face glew error
#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>
#include <QSettings>
#include <QStandardPaths>
#include <QFileInfo>

class device : public Base_window
{
	Q_OBJECT

public:
	device( QWidget *parent = Q_NULLPTR);
	~device();

	QHBoxLayout *layout;
	
	shared_ptr<ofApp> ofAppPtr;
	shared_ptr<ofAppQtWindow> windowPtr;

private:
	Ui::device ui;

	// overriten from Base_window
	void saveSettings() override;
	void loadSettings() override;

public slots:
	void on_Size_slider_valueChanged(int value) {
		ofAppPtr->radius.set(value);
	}
	void on_Save_Settings_clicked() {
		saveSettings();
	}
	void on_Load_Settings_clicked() {
		loadSettings();
	}
};
