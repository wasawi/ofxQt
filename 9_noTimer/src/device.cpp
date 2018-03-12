#include "device.h"


device::device( QWidget *parent)//shared_ptr<ofApp> _ofAppPtr,
	: QWidget(parent)
{
	ui.setupUi(this);

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogToConsole();

	// here we create a ofapp with an ofQtWindow
	// then we extract a pointer to QOpenGLWidget
	// and we insert it in the layout.

	// create an app and a window and initialize
	// ofLoop is not used, Qt will call events
	ofAppPtr = make_shared<ofApp>();
	windowPtr = make_shared<ofAppQtWindow>(this->parentWidget());
	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);
	
	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(windowPtr->getQWidgetPtr());
	ui.widget_2->setLayout(layout);

	// initialize OF must be here!
	ofRunApp(windowPtr, ofAppPtr);
}

device::~device()
{
	// ATTENTION HERE!!
	// we must tell the ofMainLoop that this window has to close.
	ofGetMainLoop()->removeWindow(windowPtr);

//	ofAppPtr = nullptr; // this removes warnings on console
}

void device::on_Size_slider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}

void device::changeEvent(QEvent *e)
{
	if (e->type() == QEvent::WindowStateChange) {

		if (isMinimized()) {
			ofLogVerbose() << "MINIMIZED";
		}
		else if (isMaximized()){
			ofLogVerbose() << "MAXIMIZED ETC";
			windowPtr->paint();
		}
		else {
			ofLogVerbose() << "NORMA ETC";
			windowPtr->paint();
		}
	}

	e->accept();
}