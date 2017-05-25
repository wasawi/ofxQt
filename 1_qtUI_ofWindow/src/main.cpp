#include "ofMain.h"
#include "ofApp.h"

#include <QApplication>

//========================================================================
int main() {

	// Initialize Qt
	int argc = 0;
	char *argv[] = { 0 };
	QApplication a(argc, argv);

	ofSetupOpenGL(400, 200, OF_WINDOW);			// <-------- setup the GL context

												// this kicks off the running of my app
												// can be OF_WINDOW or OF_FULLSCREEN
												// pass in width and height too:
	ofRunApp(new ofApp());

}
