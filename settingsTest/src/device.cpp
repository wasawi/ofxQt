#include "device.h"


device::device( QWidget *parent)//shared_ptr<ofApp> _ofAppPtr,
	: Base_window(parent)
{
	ui.setupUi(this);

	// here we create a ofapp with an ofQtWindow
	// then we extract a pointer to QOpenGLWidget
	// and we insert it in the layout.

	// create an app and a window
	ofAppPtr = make_shared<ofApp>();
	windowPtr = make_shared<ofAppQtWindow>(this->parentWidget());
	ofAppPtr->window = windowPtr;

	// add the window to the main loop
	ofGetMainLoop()->addWindow(windowPtr);

	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);

	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(windowPtr->getQOpenGLWidget());
	ui.widget_2->setLayout(layout);

	// initialize OF
	ofRunApp(windowPtr, ofAppPtr);
}

device::~device()
{
	// tell the ofMainLoop that this window has to close.
//	ofGetMainLoop()->removeWindow(windowPtr);// this does not exist
	windowPtr->setWindowShouldClose(true);
}

void device::saveSettings()
{
	saveBaseSettings();
	beginSettings();
	p_settings->setValue(ui.Size_slider->objectName(), ui.Size_slider->value());
	endSettings();
}

void device::loadSettings()
{
	loadBaseSettings();
	beginSettings();
	auto value = p_settings->value(ui.Size_slider->objectName(), ui.Size_slider->value()).toInt();
	ui.Size_slider->setValue(value);
	endSettings();
}