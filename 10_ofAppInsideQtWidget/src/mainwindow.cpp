#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	// here we create a ofapp with an ofQtWindow
	// then we extract a pointer to QOpenGLWidget
	// and we insert it in the layout.
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogToConsole();

	// create an app and a window and initialize
	// ofLoop is not used, Qt will call events
	ofAppPtr = make_shared<ofApp>();
	windowPtr = make_shared<ofAppQtWindow>(this->parentWidget());
	windowPtr->setIsWindow(true);
	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);

	// add widget to layout
	layout = ui->oflayout;
	layout->addWidget(windowPtr->getQOpenGLWidget());
	ui->ofWidget->setLayout(layout);

	// initialize OF must be here!
	ofRunApp(windowPtr, ofAppPtr);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::loadSubWindow(QWidget* widget) {
	auto window = ui->mdiArea->addSubWindow(widget);
	window->setWindowTitle(widget->windowTitle());
	window->setWindowIcon(widget->windowIcon());
	window->show();
}
