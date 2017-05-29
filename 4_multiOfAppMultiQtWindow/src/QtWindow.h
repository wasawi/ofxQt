#pragma once

#include "ofBaseApp.h"
#include "ofApp.h"
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QComboBox>
#include <QtGui>
#include <QMainWindow>
#include <QApplication>

/*
class QtGLWidget;

class QtWindow : public QMainWindow
	{
	Q_OBJECT
		
	public:
		QtWindow(shared_ptr<ofAppPtr> app);
		
		shared_ptr<ofAppPtr> app;
		void setApp(shared_ptr<ofAppPtr> app);
		void update();

		int getGlWidth();
		int getGlHeight();
		float getGlFrameRate();
//		QTabWidget * tab;
//		QComboBox * viewCombo;
		QSettings * settings;

	private:
		QtGLWidget *glWidget;

		//    QSlider *xSlider;
		//   QSlider *rotateSlider;
		QLabel *fpsLabel;
		QLabel *testLabel;
		QAction * lock;
		QToolBar *toolbar;

		void keyPressEvent(QKeyEvent *event);
		void KeyReleaseEvent(QKeyEvent *event);

		
	public slots:
		void saveSettings();
		void loadSettings();
		void toggleLock();
	
	signals:
		void updateQt();
};
*/