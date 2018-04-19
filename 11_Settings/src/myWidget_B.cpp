#include "myWidget_B.h"


myWidget_B::myWidget_B( QWidget *parent)
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

	ofAddListener(ofAppPtr->getOfWindow()->events().draw, this, &myWidget_B::redraw);
	//connect(
	//	ofAppPtr.get(), &ofApp::draw,
	//	this, &myWidget_B::redraw
	//);
}

myWidget_B::~myWidget_B()
{
}

void myWidget_B::on_Size_slider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}

void myWidget_B::on_FPS_slider_sliderMoved(int value)
{
	ofAppPtr->setFramerate(value);
}

void myWidget_B::on_VerticalSync_checkbox_stateChanged(int value)
{
	ofAppPtr->setVerticalSync(value);
}

void myWidget_B::redraw(ofEventArgs& event)
{
	// we need to add here all values that are changed on draw
	// e.g. those changed by ImGui
	ui.Size_slider->setValue(ofAppPtr->radius);
}

void myWidget_B::changeEvent(QEvent *e)
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