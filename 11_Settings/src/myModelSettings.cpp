#include "myModelSettings.h"

MyModelSettings::MyModelSettings(){

}

MyModelSettings::~MyModelSettings()
{
}

//--------------------------------------------------------------
void MyModelSettings::setModuleName(string _filename, ofParameterGroup& settings) {
	settings.setName(_filename);
	moduleName = _filename;
	ofLogVerbose() << moduleName;
	path = "settings/" + moduleName + ".json";
	ofLogVerbose() << path;
	// This gets the position of the string to find
	size_t f = path.find(" ");
	// And this replaces the text
	if (f != string::npos) path.replace(f, std::string(" ").length(), "_");
	ofLogVerbose() << path;
//	string settingsAbsolutepath = ofFilePath().getAbsolutePath(path);
}
//--------------------------------------------------------------
bool MyModelSettings::loadSettings(ofParameterGroup& settings){
	ofLogVerbose() << "Loading JSON";
	ofJson json;
	bool success = false;

	ofLogVerbose() << path;
	//				APP_VERBOSE << settingsAbsolutepath;
	json = ofLoadJson(path);
	if (json.is_null()) {
		ofLogVerbose() << "failed to load";
	}
	else {
		success = true;
		ofDeserialize(json, settings);
	}
	ofLogVerbose() << "Loading returns " << success;
	return success;
}

//--------------------------------------------------------------
bool MyModelSettings::saveSettings(ofParameterGroup& settings) {
	settings.setName(moduleName);
	ofLogVerbose() << "Saving JSON";
	ofJson json;
	bool success = false;

	ofSerialize(json, settings);
	ofLogVerbose() << path;
	//				APP_VERBOSE << settingsAbsolutepath;
	success = ofSavePrettyJson(path, json);
	ofLogVerbose() << "Saving returns " << success;
	return success;
}
