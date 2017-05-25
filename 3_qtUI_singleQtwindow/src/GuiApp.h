#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "QtGuiClass.h"

class GuiApp: public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void setRadius(float& value) { ui->setRadius(value); };
	void setColor(ofColor& value) { ui->setColor(value); };

	ofParameterGroup parameters;
	ofParameter<float> radius;
	ofParameter<ofColor> color;
	ofxPanel gui;

	QtGuiClass *ui;
};

