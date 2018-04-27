#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	myModel_A = new MyModel_A(this);
	myModel_B = new MyModel_B(this);

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_action_add_Widget_A_triggered()
{
	loadSubWindow(new MyWidget_A(this, myModel_A));
}

void MainWindow::on_action_add_Widget_B_triggered()
{
	loadSubWindow(new MyWidget_B(this, myModel_B));
}

void MainWindow::loadSubWindow(QWidget* widget) {
	auto window = ui->mdiArea->addSubWindow(widget);
	window->setWindowTitle(widget->windowTitle());
	window->setWindowIcon(widget->windowIcon());
	window->show();
}
