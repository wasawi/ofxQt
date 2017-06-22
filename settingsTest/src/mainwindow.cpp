#include "mainwindow.h"
#include "device.h"	// do NOT move!

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	// create one single  ofLoop
	// windows are added to the loop from the device code
	loop = make_shared<ofMainLoop>();
	ofSetMainLoop(loop);

	// create one single timer to run the main loop
	// this could be triggered from a Qt callback too
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &MainWindow::newframe);
	timer->start(10);
}

MainWindow::~MainWindow()
{
	loop->exit();
	delete ui;
}

void MainWindow::loadSubWindow(QWidget* widget) {
	auto window = ui->mdiArea->addSubWindow(widget);
	window->setWindowTitle(widget->windowTitle());
	window->setWindowIcon(widget->windowIcon());
	window->show();
}


void MainWindow::newframe()
{
	loop->loopOnce();
}