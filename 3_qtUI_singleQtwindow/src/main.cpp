#include "QtGuiClass.h"
#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"
#include <QApplication>

#include "ofAppQtWindow.h"

int main( )
{
	ofQtGLWindowSettings settings;
	settings.setSize(400,200);
	settings.setPosition(ofVec2f(500, 100));
	settings.resizable = true;
	settings.title = "Qt window";
//	settings.decorated = false;
	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>();
	mainWindow->createQtApp();
	mainWindow->setIsWindow(true);
	mainWindow->setup(settings);

	ofGLFWWindowSettings settings2;
	settings.setSize(300, 300);
	settings2.setPosition(ofVec2f(1100, 100));
	settings2.resizable = false;
	settings2.title = "GLFW window";
//	settings.decorated = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings2);

	// create apps
	shared_ptr<ofApp> app(new ofApp);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	app->gui = guiApp;

	// create apps
	QtGuiClass w;
    app->ui = &w;
	guiApp->ui = &w;
    w.show();
//	a.exec(); // do not use

	ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, app);
	ofRunMainLoop();//

	////////////////////////////////
	//	other ways of creating ofAppQtWindow
	////////////////////////////////
	/*
	ofAppQtWindow window;
	window.createQtApp();
	//	window.setMultiDisplayFullscreen(true);
	ofSetupOpenGL(&window, 800, 400, OF_WINDOW);
	ofRunApp(new ofApp);
	*/
	// -- or
	/*
	shared_ptr<ofApp> app = make_shared<ofApp>();
	ofAppQtWindow window;
	window.createQtApp();
	ofSetupOpenGL(&window, 800, 400, OF_WINDOW);
	ofRunApp(app);
	*/
}
