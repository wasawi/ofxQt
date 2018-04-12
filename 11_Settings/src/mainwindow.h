#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// of
#include "ofMainLoop.h"

// ofApp
#include "myWidget_A.h"
#include "myWidget_B.h"

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

void on_action_add_Widget_A_triggered() {
	loadSubWindow(new myWidget_A(this));
}

void on_action_add_Widget_B_triggered() {
	loadSubWindow(new myWidget_B(this));
}


private:
	void newframe();
	Ui::MainWindow *ui;
	void loadSubWindow(QWidget* widget);

};

#endif // MAINWINDOW_H
