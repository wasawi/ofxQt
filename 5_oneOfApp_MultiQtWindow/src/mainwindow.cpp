#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	setWindowTitle(tr("Qt GUI"));

	//connect(ui->Slider,
	//	SIGNAL(ui->Slider->valueChanged(int)),
	//	this,
	//	SLOT(on_Slider_valueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Slider_valueChanged(int value)
{
	cout << "from Qt in MainWindow: " << value << endl;
	ofNotifyEvent(newIntEvent, value, this);
}