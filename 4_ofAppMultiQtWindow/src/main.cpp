#include "QtGuiClass.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofAppQtWindow.h"

int main( )
{
	// create Qt app
	int argc = 1;
	char *argv = "openframeworks";
	char **vptr = &argv;
	QApplication *	qtAppPtr = new QApplication(argc, vptr);

	// create windows
	ofQtGLWindowSettings settings;
	settings.width = 400;
	settings.height = 200;
	settings.setPosition(ofVec2f(500, 100));
	settings.resizable = true;
	settings.title = "Qt window";

	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>();
	mainWindow->setIsWindow(true);
	mainWindow->setup(settings);

	ofQtGLWindowSettings settings2;
	settings2.width = 300;
	settings2.height = 300;
	settings2.setPosition(ofVec2f(1100, 100));
	settings2.resizable = false;
	settings.title = "Qt GUI window";

	shared_ptr<ofAppQtWindow> guiWindow = make_shared<ofAppQtWindow>();
	guiWindow->setIsWindow(true);
	guiWindow->setup(settings2);

	// create apps
	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	mainApp->gui = guiApp;

	//create Qt gui and pass pointer to apps
	QtGuiClass w;
	mainApp->ui = &w;
	guiApp->ui = &w;
	w.show();

	// resgister windows to main loop and run
	ofRunApp(mainWindow, mainApp);
	ofRunApp(guiWindow, guiApp);
	ofRunMainLoop();
}

/*
int main()
{
	// create Qt app
	int argc = 1;
	char *argv = "openframeworks";
	char **vptr = &argv;
	QApplication *	qtAppPtr = new QApplication(argc, vptr);


	ofQtGLWindowSettings settings;
	settings.width = 400;
	settings.height = 200;
	settings.setPosition(ofVec2f(500, 100));
	settings.resizable = true;
	settings.title = "Qt window";

	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>();
	mainWindow->setIsWindow(true);
	mainWindow->setup(settings);

	ofAppQtWindow guiWindow;
	ofSetupOpenGL(&guiWindow, 300, 300, OF_WINDOW);
	guiWindow.setWindowTitle("GUI Qt widow");

	// create apps
	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<GuiApp> guiApp(new GuiApp);

	//create Qt gui and pass pointer to apps
	QtGuiClass w;
	mainApp->ui = &w;
	guiApp->ui = &w;
	w.show();

	mainApp->gui = guiApp;
	guiApp->setup();
	//	ofAddListener(guiWindow.events().draw, guiApp.get(), &GuiApp::draw);

	//	ofRunApp(guiWindow, guiApp);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}
*/