#include "GuiApp.h"

void GuiApp::setup(){
	parameters.setName("parameters");
	parameters.add(radius.set("radius",50,50,150));
	parameters.add(color.set("color",100,ofColor(0,0),255));
	gui.setup(parameters);
	ofBackground(0);
	ofSetVerticalSync(false);

	radius.addListener(this, &GuiApp::setRadius);
	color.addListener(this, &GuiApp::setColor);
}

void GuiApp::update(){
	radius = ui->getRadius();
	color = ui->getColor();
}

void GuiApp::draw(){
	gui.draw();
}
