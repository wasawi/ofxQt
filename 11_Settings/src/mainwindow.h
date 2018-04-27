#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// of
#include "ofMainLoop.h"

// ofApp
#include "myWidget_A.h"
#include "myWidget_B.h"
#include "myModel_A.h"
#include "myModel_B.h"

// Qt ui
#include "ui_mainwindow.h"

// include Qt always at the end or face glew error
#include <vector>
#include <QMainWindow>
#include <QMdiSubWindow>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class ofApp;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

void on_action_add_Widget_A_triggered();
void on_action_add_Widget_B_triggered();


private:
	void newframe();
	Ui::MainWindow *ui;
	void loadSubWindow(QWidget* widget);

	MyModel_A *myModel_A;
	MyModel_B *myModel_B;

};

#endif // MAINWINDOW_H
