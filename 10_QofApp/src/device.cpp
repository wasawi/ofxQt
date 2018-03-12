#include "device.h"


device::device( QWidget *parent)//shared_ptr<ofApp> _ofAppPtr,
	: QWidget(parent)
{
	ui.setupUi(this);

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogToConsole();

	// create an ofApp instance
	ofAppPtr = make_shared<ofApp>(parent);
	ofAppPtr->startRender();
	// startRender() is same as:
	//ofRunApp(ofAppPtr->getOfWindow(), ofAppPtr);

// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(ofAppPtr->getQWidgetPtr());
	ui.widget_2->setLayout(layout);
}

device::~device()
{
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
			ofAppPtr->getOfWindow()->paint();
		}
		else {
			ofLogVerbose() << "NORMA ETC";
			ofAppPtr->getOfWindow()->paint();
		}
	}

	e->accept();
}