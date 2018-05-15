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

	// add a QSlider through a QDataWidgetMapper
	QLabel* sliderLabel = new QLabel(tr("Size:"), this);
	QSlider *mappedSlider = new QSlider(this);
	mappedSlider->setOrientation(Qt::Orientation::Horizontal);
	mappedSlider->setMinimumHeight(20);
	mappedSlider->setMinimumWidth(100);
	connect(mappedSlider, SIGNAL(valueChanged(int)), this, SLOT(on_Size_slider_sliderMoved(int)));

	QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
	mapper->setModel(model_B);
	mapper->addMapping(mappedSlider, 1);
	mapper->toFirst();

// connect to the model's dataChanged event
 	connect(tableView->model(), SIGNAL(dataChanged(QModelIndex, QModelIndex)),
			this, SLOT(dataChanged(QModelIndex, QModelIndex)));

	SpinBoxDelegate *delegate = new SpinBoxDelegate(this);
	tableView->setItemDelegateForColumn(1, delegate);

	ui.frame->layout()->addWidget(tableView);
	ui.frame->layout()->addWidget(sliderLabel);
	ui.frame->layout()->addWidget(mappedSlider);

	// create an ofApp instance
	ofAppPtr = make_shared<ofApp_B>(parent);
	ofAppPtr->setModel(model_B);
	ofAppPtr->startRender();

	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(ofAppPtr->getQWidgetPtr());
	ui.widget_2->setLayout(layout);

	// read defaults from window
	ui.FPS_slider->setValue(ofAppPtr->getOfWindow()->getFrameRate());
	ui.FPS_slider->setMaximum(ofAppPtr->framerate.getMax());
	ui.FPS_slider->setMinimum(ofAppPtr->framerate.getMin());

	ui.Angle_slider->setValue(model_B->angle);
	ui.Angle_slider->setMaximum(model_B->angle.getMax());
	ui.Angle_slider->setMinimum(model_B->angle.getMin());

	ui.VerticalSync_checkbox->setChecked(ofAppPtr->getOfWindow()->getVerticalSync());

	// Add listeners
	ofAddListener(ofAppPtr->guiEvent, this, &MyWidget_B::guiEvent);
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
//	myModel_B->size.set(value);
	myModel_B->setData(myModel_B->index(0, 1), value, Qt::EditRole);
}
void MyWidget_B::on_Angle_slider_sliderMoved(int value) 
{
//	myModel_B->angle.set(value);
	myModel_B->setData(myModel_B->index(1, 1), value, Qt::EditRole);

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
	ui.Size_slider->setValue(myModel_B->size);
	ui.Angle_slider->setValue(myModel_B->angle);
//	myModel_B->setData(myModel_B->index(0, 1), ui.Size_slider->value(), Qt::EditRole);
}

void MyWidget_B::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
	adjustTableSize();
}

void MyWidget_B::adjustTableSize()
{

//	tableView->resizeRowsToContents();

	tableView->resizeColumnToContents(0);
	tableView->resizeColumnToContents(1);
//	tableView->resizeColumnToContents(2);

//	tableView->setColumnWidth(0, 100);
	tableView->setColumnWidth(1, 200);

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

void MyWidget_B::guiEvent(ofAbstractParameter &e)
{
	if (e.getName() == "size") {
		float value = e.cast<float>();
		myModel_B->setData(myModel_B->index(0, 1), value, Qt::EditRole);
		ui.Size_slider->setValue(value);
	}
	if (e.getName() == "angle") {
		float value = e.cast<float>();
		myModel_B->setData(myModel_B->index(1, 1), value, Qt::EditRole);
		ui.Angle_slider->setValue(value);
	}
	if (e.getName() == "posX") {
		float value = e.cast<float>();
		myModel_B->setData(myModel_B->index(2, 1), value, Qt::EditRole);
	}
	if (e.getName() == "posY") {
		float value = e.cast<float>();
		myModel_B->setData(myModel_B->index(3, 1), value, Qt::EditRole);
	}
}
