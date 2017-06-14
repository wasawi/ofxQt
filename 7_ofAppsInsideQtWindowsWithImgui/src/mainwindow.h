#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ofMain.h"
#include "ui_mainwindow.h"
#include "device.h"

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

void on_actionAdd_OF_app_triggered() {
	loadSubWindow(new device(this));
}

private:
	Ui::MainWindow *ui;
	void loadSubWindow(QWidget* widget);
};

#endif // MAINWINDOW_H
