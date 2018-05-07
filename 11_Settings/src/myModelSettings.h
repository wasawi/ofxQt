#pragma once

// OF
#include "ofMain.h"

class MyModelSettings
{
public:
	MyModelSettings();
	~MyModelSettings();
	void setModuleName(string filename);
	string getModuleName() { return moduleName; }

	bool				loadSettings();
	bool				saveSettings();

	ofParameterGroup	settings;

private:
	string				moduleName;
	string				path;
};