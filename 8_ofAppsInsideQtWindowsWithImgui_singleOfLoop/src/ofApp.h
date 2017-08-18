#pragma once

#include "ofMain.h"
//#include "ofxGui.h"
#include "ofxImGui.h"
#include "imguiTheme.h"

// include Qt always at the end or face glew error
#include <QSettings>

namespace Ui {
    class MainWindow;
}

class ofApp : public ofBaseApp{
public:
	ofApp();
	~ofApp();

	shared_ptr<ofAppBaseWindow> window;

        void setup();
        void update();
        void draw();

        void keyPressed(ofKeyEventArgs& key);
        void keyReleased(ofKeyEventArgs& key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
		
		ofPoint cursor;
		string key_str;

		ofParameterGroup parameters;
		ofParameter<float> radius;
		ofParameter<ofColor> color;
		ofParameter<float> framerate;
		ofParameter<bool> verticalSync;
//		ofxPanel OfGUI;

		ofxImGui::Gui imgui;

		void setFramerate(float& value);
		void setVerticalSync(bool& value);
};
