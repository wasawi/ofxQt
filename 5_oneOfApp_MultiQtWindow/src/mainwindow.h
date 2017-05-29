#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ofMain.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

	ofEvent<int> newIntEvent;

	private slots:
	void on_Slider_valueChanged(int value);
};

/*
private:
    Ui::MainWindow *ui;
};*/

#endif // MAINWINDOW_H
