#pragma once

// OF
#include "ofMain.h"

class MyModelSettings
{
public:
	MyModelSettings();
	~MyModelSettings();
	void setModuleName(string filename, ofParameterGroup& settings);
	string getModuleName() { return moduleName; }

	bool				loadSettings(ofParameterGroup& settings);
	bool				saveSettings(ofParameterGroup& settings);

//	ofParameterGroup	settings;

private:
	string				moduleName;
	string				path;
};