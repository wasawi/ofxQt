#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "imguiTheme.h"
#include "ofxImGuiWidgets.h"

#include "QofApp.h"

namespace Ui {
    class MainWindow;
}

class ofApp_B : public QofApp {
public:
	ofApp_B(QWidget *parent = Q_NULLPTR);
	~ofApp_B();

        void setup() override;
        void update() override;
        void draw() override;
		//void exit() override;

        void keyPressed(ofKeyEventArgs& key) override;
        void keyReleased(ofKeyEventArgs& key) override;
        void mouseMoved(int x, int y) override;
        void mouseDragged(int x, int y, int button) override;
        void mousePressed(int x, int y, int button) override;
        void mouseReleased(int x, int y, int button)override;
        void mouseEntered(int x, int y) override;
        void mouseExited(int x, int y) override;
        void windowResized(int w, int h) override;
        void dragEvent(ofDragInfo dragInfo) override;
        void gotMessage(ofMessage msg) override;
		
		string key_str;

		ofParameterGroup parameters;
		SliderFloat radius;
		SliderFloat angle;
		SliderFloat posX;
		SliderFloat posY;
		ofParameter<ofColor> color;
		ofParameter<float> framerate;
		ofParameter<bool> verticalSync;

//		ofxPanel OfGUI;
		ofxImGui::Gui imgui;

		void setFramerate(int value);
		void setVerticalSync(bool value);

		ofTexture		liveTexture;
		ofFbo			videoFBO;
};
