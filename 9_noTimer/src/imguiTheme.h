#pragma once
#include "BaseTheme.h"
#include "imgui.h"
//#include "ofMain.h"
//
//#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))

class ImguiTheme : public ofxImGui::BaseTheme
{
public:

	ImguiTheme();
	virtual ~ImguiTheme() {
	};

	void setup();
	void themeColorsWindow(bool isOpen);
	void updateColors();
	bool addColorEdit(string label, ofColor& color);
	ofColor convertColor(float* f);


};