#include "MyWidget_A.h"

MyWidget_A::MyWidget_A( 
	QWidget *parent,
	MyModel_A* model_A)
	: QWidget(parent)
{
	ui.setupUi(this);

//	ofSetLogLevel(OF_LOG_VERBOSE);
//	ofLogToConsole();

	myModel_A = model_A;

	QTableView* tableView = new QTableView(this);
	tableView->setModel(model_A);

	StarDelegate *delegate = new StarDelegate(this);
	tableView->setItemDelegate(delegate);

	ui.frame->layout()->addWidget(tableView);

	// create an ofApp instance
	ofAppPtr = make_shared<ofApp_A>(parent);
	ofAppPtr->setModel(model_A);
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


	// Add listeners
	ofAddListener(ofAppPtr->getOfWindow()->events().draw, this, &MyWidget_A::updateUI);
}

MyWidget_A::~MyWidget_A()
{
}

void MyWidget_A::on_Size_slider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}

void MyWidget_A::on_FPS_slider_sliderMoved(int value)
{
	ofAppPtr->setFramerate(value);
}

void MyWidget_A::on_VerticalSync_checkbox_stateChanged(int value)
{
	ofAppPtr->setVerticalSync(value);
}

void MyWidget_A::updateUI(ofEventArgs& event)
{
	// we need to add here all values that are changed on draw
	// e.g. those changed by ImGui
	ui.Size_slider->setValue(ofAppPtr->radius);
}

void MyWidget_A::changeEvent(QEvent *e)
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