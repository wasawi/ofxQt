#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// of
#include "ofMainLoop.h"

// ofApp
#include "device.h"
#include "ofApp.h"
#include "QtGLWidget.h"

// Qt ui
#include "ui_mainwindow.h"

// include Qt always at the end or face glew error
#include <vector>
#include <QMainWindow>
#include <QMdiSubWindow>
#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>

namespace Ui {
class MainWindow;
}

class ofApp;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	QHBoxLayout *layout;

	shared_ptr<ofApp> ofAppPtr;
	shared_ptr<ofAppQtWindow> windowPtr;

//	void changeEvent(QEvent *e);

public slots:

void on_actionAdd_OF_app_triggered() {
//	loadSubWindow(new device(this));
}

private:
	void newframe();
	Ui::MainWindow *ui;
	void loadSubWindow(QWidget* widget);

};

#endif // MAINWINDOW_H
