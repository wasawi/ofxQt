#include "QtGuiClass.h"
#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"
#include <QApplication>

int main( )
{
	ofGLFWWindowSettings settings;

	settings.title = "GLFW Main window";
	settings.width = 400;
	settings.height = 200;
	settings.setPosition(ofVec2f(500, 100));
	settings.resizable = true;
//	settings.decorated = false;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	shared_ptr<ofApp> app(new ofApp);

	settings.title = "GLFW GUI window";
	settings.width = 300;
	settings.height = 300;
	settings.setPosition(ofVec2f(1100, 100));
	settings.resizable = false;
//	settings.decorated = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	app->gui = guiApp;

    int argc = 0;
    char *argv[] = {0};
    QApplication a(argc, argv);
	QtGuiClass w;

    app->ui = &w;
	guiApp->ui = &w;

    w.show();
//	a.exec(); // do not use

	ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, app);
	ofRunMainLoop();//
}
