
#include "ofMain.h"
#include "ofApp.h"

#include "ofAppQtWindow.h"
#include "mainwindow.h"

int main( )
{

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogToConsole();
	
	// create Qt app
	int argc = 1;
	char *argv = "openframeworks";
	char **vptr = &argv;
	QApplication *	qtAppPtr = new QApplication(argc, vptr);

	// setup two ofQtwindows
	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>();
	mainWindow->setQtAppPointer(qtAppPtr);
	mainWindow->setIsWindow(true);
	ofSetupOpenGL(mainWindow, 400, 200, OF_WINDOW);
	mainWindow->setWindowTitle("ofAppQtWindow");
	mainWindow->setVerticalSync(true);

	ofAppQtWindow guiWindow;
//	guiWindow.setQtAppPointer(qtAppPtr);
	guiWindow.setIsWindow(true);
	ofSetupOpenGL(&guiWindow, 300, 300, OF_WINDOW);
	guiWindow.setWindowTitle("ofAppQtWindow");
	guiWindow.setVerticalSync(true);

	// create one of app
	shared_ptr<ofApp> mainApp(new ofApp);
	mainApp->setupGui();
	ofAddListener(guiWindow.events().draw, mainApp.get(), &ofApp::drawGui);

	// run using of main loop
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}
