#include "MyWidget_B.h"

MyWidget_B::MyWidget_B( 
	QWidget *parent, 
	MyModel_B* model_B)
	: QWidget(parent)
{
	ui.setupUi(this);

//	ofSetLogLevel(OF_LOG_VERBOSE);
//	ofLogToConsole();

	myModel_B = model_B;

	tableView = new QTableView(this);
	tableView->setModel(model_B);
	adjustTableSize();

// connect to the model's dataChanged event
 	connect(tableView->model(), SIGNAL(dataChanged(QModelIndex, QModelIndex)),
			this, SLOT(dataChanged(QModelIndex, QModelIndex)));

// 	connect(tableView->model(), SIGNAL(dataChanged(QModelIndex, QModelIndex)),
// 		this, SLOT(dataChanged(QModelIndex, QModelIndex)));

	SpinBoxDelegate *delegate = new SpinBoxDelegate(this);
//	tableView->setItemDelegate(delegate);
	tableView->setItemDelegateForColumn(1, delegate);

	ui.frame->layout()->addWidget(tableView);

	// create an ofApp instance
	ofAppPtr = make_shared<ofApp_B>(parent);
	ofAppPtr->setModel(model_B);
	ofAppPtr->startRender();
	// startRender() is same as:
	//ofRunApp(ofAppPtr->getOfWindow(), ofAppPtr);

	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(ofAppPtr->getQWidgetPtr());
	ui.widget_2->setLayout(layout);

	// read defaults from window
	ui.FPS_slider->setValue(ofAppPtr->getOfWindow()->getFrameRate());
	ui.FPS_slider->setMaximum(ofAppPtr->framerate.getMax());
	ui.FPS_slider->setMinimum(ofAppPtr->framerate.getMin());

	ui.Angle_slider->setValue(ofAppPtr->angle);
	ui.Angle_slider->setMaximum(ofAppPtr->angle.getMax());
	ui.Angle_slider->setMinimum(ofAppPtr->angle.getMin());

	ui.VerticalSync_checkbox->setChecked(ofAppPtr->getOfWindow()->getVerticalSync());

	// Add listeners
	ofAddListener(ofAppPtr->getOfWindow()->events().draw, this, &MyWidget_B::updateUI);
	//connect(
	//	ofAppPtr.get(), &ofApp::draw,
	//	this, &MyWidget_B::redraw
	//);
}

MyWidget_B::~MyWidget_B()
{
}

void MyWidget_B::on_Size_slider_sliderMoved(int value) 
{
	ofAppPtr->size.set(value);
}
void MyWidget_B::on_Angle_slider_sliderMoved(int value) 
{
	ofAppPtr->angle.set(value);
}

void MyWidget_B::on_FPS_slider_sliderMoved(int value)
{
	ofAppPtr->setFramerate(value);
}

void MyWidget_B::on_VerticalSync_checkbox_stateChanged(int value)
{
	ofAppPtr->setVerticalSync(value);
}

void MyWidget_B::updateUI(ofEventArgs& event)
{
	// we need to add here all values that are changed on draw
	// e.g. those changed by ImGui
	ui.Size_slider->setValue(ofAppPtr->size);
	ui.Angle_slider->setValue(ofAppPtr->angle);
}

void MyWidget_B::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
	adjustTableSize();
}

void MyWidget_B::adjustTableSize()
{
	tableView->resizeColumnToContents(0);
	tableView->resizeColumnToContents(1);
//	tableView->resizeColumnToContents(2);

//	tableView->setColumnWidth(0, 100);
	tableView->setColumnWidth(1, 200);
	tableView->setMinimumHeight(30);

	QRect rect = tableView->geometry();
	rect.setWidth(2 + tableView->verticalHeader()->width() +
		tableView->columnWidth(0) + tableView->columnWidth(1) + tableView->columnWidth(2));
//	tableView->setGeometry(rect);
}

void MyWidget_B::changeEvent(QEvent *e)
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