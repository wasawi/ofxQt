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

	// create an app a loop and a window
	loop = make_shared<ofMainLoop>();
	ofAppPtr = make_shared<ofApp>();
	windowPtr = make_shared<ofAppQtWindow>();

	// initialize the window
	ofSetMainLoop(loop);
	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);

	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(windowPtr->getQWidgetPtr());
	ui.widget_2->setLayout(layout);

	// initialize OF
	ofRunApp(windowPtr, ofAppPtr);

	timer = new QTimer(this);
//	connect(timer, &QTimer::timeout, [=]() { newframe(); });
	connect(timer, &QTimer::timeout, this, &myWidget::newframe);

	timer->start(10);
}

myWidget::~myWidget()
{
	ofLogVerbose() << "myWidget Dtor";
	// ATTENTION HERE!!
	// we must tell the ofMainLoop that this window has to close.
	loop->removeWindow(windowPtr);
}

void myWidget::newframe()
{
//	loop->loopOnce();

	ofSetMainLoop(loop);
	ofGetMainLoop()->setCurrentWindow(windowPtr);

	windowPtr->makeCurrent();
	if (windowPtr->getWindowShouldClose()) {
		windowPtr->close();
	}
	else {
		windowPtr->update();
		windowPtr->draw();
	}
}

void myWidget::on_horizontalSlider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}
void myWidget::on_horizontalSlider_2_sliderMoved(int value) {
	timer->setInterval(1000 / value);
}