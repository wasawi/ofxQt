#include "QofApp.h"

QofApp::QofApp(QWidget *parent, bool _useLoop)
{
	ofLogVerbose() << "QofApp Ctor";
	windowPtr = make_shared<ofAppQtWindow>(parent, _useLoop);
	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);

	//	startRender();
	// unfortunately the ofRunApp call can't be used before this constructor has completed
}

QofApp::~QofApp(){
	ofLogVerbose() << "QofApp Dtor";
//	stopRender();
	// this wont work because in order to arrive to this destructor call
	// we first have to remove the window from the ofloop.
	// that is why QGLWidget destructor will use the exit call to remove the window from the ofloop.
	// after that we will reach this destructor call.
}

void QofApp::exit()
{
	ofLogVerbose() << "QofApp exit";
	stopRender();
}

QWidget* QofApp::getQWidgetPtr()
{
	return windowPtr->getQWidgetPtr();
}

shared_ptr<ofAppQtWindow>& QofApp::getOfWindow()
{
	return windowPtr;
}



void QofApp::startRender()
{
	ofLogVerbose() << "QofApp startRender";
	ofRunApp(windowPtr, shared_from_this());
//	ofRunApp(windowPtr, std::move(make_shared<ofBaseApp>((ofBaseApp&)*this)));
//	ofRunApp(windowPtr, std::move(getOfApp()));
}

void QofApp::stopRender()
{
	ofLogVerbose() << "QofApp stopRender";
	ofGetMainLoop()->removeWindow(windowPtr);
}


//shared_ptr<ofBaseApp>& QofApp::getOfApp()
//{
//	ofAppPtr = make_shared<ofBaseApp>((ofBaseApp&)*this);
//	return ofAppPtr;
//}