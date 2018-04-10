#pragma once

// ofxQt
#include "ofAppQtWindow.h"

// Qt
#include <QWidget>

// std
#include <memory>

class QofApp 
	: public ofBaseApp
	, public std::enable_shared_from_this<QofApp>
{
public:
	QofApp(QWidget *parent = Q_NULLPTR, bool _useLoop = true);
	virtual ~QofApp();

	void startRender();
	void stopRender();
	void exit() override;

	QWidget* getQWidgetPtr();
	shared_ptr<ofAppQtWindow>& getOfWindow();

protected:
private:
	shared_ptr<ofAppQtWindow> windowPtr;
};
