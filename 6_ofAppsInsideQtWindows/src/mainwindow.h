#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ofMain.h"

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
	void on_actionAdd_OF_app_triggered();

private:
	Ui::MainWindow *ui;
	void loadSubWindow(QWidget* widget);
};

#endif // MAINWINDOW_H
