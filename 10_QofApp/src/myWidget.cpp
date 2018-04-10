#include "myWidget.h"


myWidget::myWidget( QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

//	ofSetLogLevel(OF_LOG_VERBOSE);
//	ofLogToConsole();

	// create an ofApp instance
	ofAppPtr = make_shared<ofApp>(parent);
	ofAppPtr->startRender();
	// startRender() is same as:
	//ofRunApp(ofAppPtr->getOfWindow(), ofAppPtr);

	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(ofAppPtr->getQWidgetPtr());
	ui.widget_2->setLayout(layout);

	// read defaults from window
	ui.FPS_slider->setValue(ofAppPtr->getOfWindow()->getFrameRate());
	ui.VerticalSync_checkbox->setChecked(ofAppPtr->getOfWindow()->getVerticalSync());

}

myWidget::~myWidget()
{
}

void myWidget::on_Size_slider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}

void myWidget::on_FPS_slider_sliderMoved(int value)
{
	ofAppPtr->setFramerate(value);
}

void myWidget::on_VerticalSync_checkbox_stateChanged(int value)
{
	ofAppPtr->setVerticalSync(value);
}

void myWidget::changeEvent(QEvent *e)
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