#pragma once

#include "ofConstants.h"
#include "ofAppBaseWindow.h"
#include "ofGLProgrammableRenderer.h"
#include "ofGLRenderer.h"

#include <QApplication>
#include "QtGLWidget.h"

class QtGLWidget;

#ifdef TARGET_OPENGLES
class ofQtGLWindowSettings : public ofGLESWindowSettings{
#else
class ofQtGLWindowSettings : public ofGLWindowSettings{
#endif

public:
	ofQtGLWindowSettings() {}

#ifdef TARGET_OPENGLES
	ofGLFWWindowSettings(const ofGLESWindowSettings & settings)
		:ofGLESWindowSettings(settings) {}
#else
	ofQtGLWindowSettings(const ofGLWindowSettings & settings)
		: ofGLWindowSettings(settings) {}
#endif

	int numSamples = 4;
	bool doubleBuffering = true;
	int redBits = 8;
	int greenBits = 8;
	int blueBits = 8;
	int alphaBits = 8;
	int depthBits = 24;
	int stencilBits = 0;
	bool stereo = false;
	bool visible = true;
	bool iconified = false;
	bool decorated = true;
	bool resizable = true;
	int monitor = 0;
	bool multiMonitorFullScreen = false;
	shared_ptr<ofAppBaseWindow> shareContextWith;
};

class ofAppQtWindow : public ofAppBaseGLWindow{

public:

//	ofAppQtWindow(QApplication * qtApp = 0);
	ofAppQtWindow(QWidget *parent = 0);
	~ofAppQtWindow();

	// Can't be copied, use shared_ptr
	ofAppQtWindow(ofAppQtWindow & w) = delete;
	ofAppQtWindow & operator=(ofAppQtWindow & w) = delete;

	void createQtApp();
	void setQtAppPointer(QApplication * qtApp);
	void setIsWindow(bool value);

	static void loop() {};
	static bool doesLoop() { return false; }
	static bool allowsMultiWindow() { return true; }
	static bool needsPolling() { return true; }
	static void pollEvents() { }

	using ofAppBaseWindow::setup;
#ifdef TARGET_OPENGLES
	void setup(const ofGLESWindowSettings & settings);
#else
	void setup(const ofGLWindowSettings & settings);
#endif
	void setup(const ofQtGLWindowSettings & settings);
	void update();
	void draw();
	void paint();

//	void paintEvent(QPaintEvent * event) override;

	bool getWindowShouldClose() { return bShouldClose; };
	void setWindowShouldClose(bool value) { bShouldClose = value; };

	void close();

	void hideCursor();
	void showCursor();

	int getHeight();
	int getWidth();

	ofCoreEvents & events();
	shared_ptr<ofBaseRenderer> & renderer();

//	QtWindow* getQtWindow();
//	void * getWindowContext() { return getQtWindow(); }
	ofGLWindowSettings getSettings() { return settings; };
	QWidget* getQOpenGLWidget();

	glm::vec2 	getWindowPosition();
	glm::vec2	getWindowSize();
	glm::vec2	getScreenSize();

	void setWindowTitle(string title);
	void setWindowPosition(int x, int y);
	void setWindowShape(int w, int h);

//	void			setOrientation(ofOrientation orientation);
//	ofOrientation	getOrientation();
	ofWindowMode	getWindowMode();

//	void		setFullscreen(bool fullscreen);
//	void		toggleFullscreen();

	void		enableSetupScreen();
	void		disableSetupScreen();

//	void		setVerticalSync(bool bSync);

//	void        setClipboardString(const string& text);
//	string      getClipboardString();

//	int         getPixelScreenCoordScale();

	void 		makeCurrent();
	void		swapBuffers();
	void		startRender();
	void		finishRender();

//	static void listVideoModes();
//	static void listMonitors();
//	bool isWindowIconified();
//	bool isWindowActive();
//	bool isWindowResizeable();
//	void iconify(bool bIconify);

	///----- from GLUT example
	void setAppPtr(shared_ptr<ofBaseApp> appPtr);
	static void exitApp();

//	int			getFrameNum();
//	float		getFrameRate();
//	void		setFrameRate(float targetRate);


	ofCoreEvents coreEvents;
	shared_ptr<ofBaseRenderer> currentRenderer;
	ofQtGLWindowSettings settings;

	ofWindowMode	windowMode;
	ofRectangle		windowRect;
	ofOrientation	orientation;

	int				windowW, windowH;		// physical pixels width
	int				currentW, currentH;		// scaled pixels width
	int				buttonInUse;
	int				pixelScreenCoordScale;
	bool			buttonPressed;
	bool			bEnableSetupScreen;
	bool			bSetupSucceded;

private:
	int 			nFramesSinceWindowResized;
	bool			bWindowNeedsShowing;
	bool			iconSet;
	bool			bShouldClose;
	bool			hasQtApp;
	bool			bIsWindow;


	// Of App Ptr
	shared_ptr<ofBaseApp>		ofAppPtr;
	// Qt Stuff
	QApplication *				qtAppPtr;
	QWidget*					parentWidget;
	QtGLWidget*					qtWidgetPtr;

	void setStatusMessage(string s);


};