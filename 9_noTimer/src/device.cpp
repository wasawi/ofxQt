#include "device.h"


device::device( QWidget *parent)//shared_ptr<ofApp> _ofAppPtr,
	: QWidget(parent)
{
	ui.setupUi(this);

	// here we create a ofapp with an ofQtWindow
	// then we extract a pointer to QOpenGLWidget
	// and we insert it in the layout.
//	ofSetLogLevel(OF_LOG_VERBOSE);
//	ofLogToConsole();

	// create an app and a window and initialize
	// ofLoop is not used, Qt will call events
	ofAppPtr = make_shared<ofApp>();
	windowPtr = make_shared<ofAppQtWindow>(this->parentWidget());
	windowPtr->setAppPtr(ofAppPtr);
	ofAppPtr->window = windowPtr;
	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);
	
	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(windowPtr->getQOpenGLWidget());
	ui.widget_2->setLayout(layout);

	// initialize OF must be here!
	ofRunApp(windowPtr, ofAppPtr);
}

device::~device()
{
	// tell the ofMainLoop that this window has to close.
	ofAppPtr = nullptr; // this removes warnings on console
	ofGetMainLoop()->removeWindow(windowPtr);
}

void device::on_Size_slider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}