#include "myWidget.h"


myWidget::myWidget( QWidget *parent)//shared_ptr<ofApp> _ofAppPtr,
	: QWidget(parent)
{
	ui.setupUi(this);

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogToConsole();

	// here we create a ofapp with an ofQtWindow
	// then we extract a pointer to QOpenGLWidget
	// and we insert it in the layout.

	// create an app and a window
	ofAppPtr = make_shared<ofApp>();
	windowPtr = make_shared<ofAppQtWindow>();

	// add the window to the main loop
	ofGetMainLoop()->addWindow(windowPtr);

	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);

	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(windowPtr->getQWidgetPtr());
	ui.widget_2->setLayout(layout);

	// initialize OF
	ofRunApp(windowPtr, ofAppPtr);

}

myWidget::~myWidget()
{
	// tell the ofMainLoop that this window has to close.
	windowPtr->setWindowShouldClose(true);
}

void myWidget::on_Size_slider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}