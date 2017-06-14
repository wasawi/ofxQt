
#include "ofMain.h"
#include "ofApp.h"

#include "ofAppQtWindow.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	// create Qt app
	QApplication *	qtAppPtr = new QApplication(argc, argv);
	MainWindow w;
	w.show();
	return qtAppPtr->exec();

	// find of app in device.h
}
