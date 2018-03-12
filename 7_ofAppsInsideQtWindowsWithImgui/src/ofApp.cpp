#include "ofApp.h"

ofApp::ofApp(){
}

ofApp::~ofApp()
{
//	OfGUI.clear();
	imgui.close(); // important
	framerate.removeListener(this, &ofApp::setFramerate);
	verticalSync.removeListener(this, &ofApp::setVerticalSync);
}

//--------------------------------------------------------------
void ofApp::setup(){


	imgui.setup(new ImguiTheme());

	ofEnableAntiAliasing();
	ofBackground(ofColor::darkGrey);

	cursor = ofPoint(
		ofGetWindowWidth() / 2, 
		ofGetWindowHeight() / 2);

	key_str = "";

	parameters.setName("parameters");
	parameters.add(radius.set("radius", 50, 1, 100));
	parameters.add(color.set("color", ofColor::yellow, 0, 255));
	parameters.add(framerate.set("framerate", 60, 1, 100));
	parameters.add(verticalSync.set("verticalSync", true));
//	OfGUI.setup(parameters);

	framerate.addListener(this, &ofApp::setFramerate);
	verticalSync.addListener(this, &ofApp::setVerticalSync);

	videoFBO.allocate(400, 200);

}

void ofApp::setFramerate(float & value)
{
	ofSetFrameRate(value);
}

void ofApp::setVerticalSync(bool & value)
{
	ofSetVerticalSync(value);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofLogVerbose() << "update";

	videoFBO.begin();	//----- FBO begin
//	liveTexture.draw(0, 0);

	ofDrawBitmapStringHighlight("Hello FBOoo!", 50, 100);

	videoFBO.end();		//----- FBO end

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofLogVerbose() << "draw";

	imgui.begin();
	ImGui::Text("Hello ImGui!", ofVec2f(0, 0));
	imgui.end();

	ofEnableAntiAliasing();

	//cout << "window w " << window->getWidth() << endl;
	//cout << "window h " << window->getHeight() << endl;
	//cout << "of w " << ofGetWindowWidth() << endl;
	//cout << "of h " << ofGetWindowHeight() << endl;

	videoFBO.draw(0,0);

	ofSetColor(ofColor::cyan, 100);
	int margin = 10;
	int size = 10;
	for (int i = 0; i < 100; i++) {
		ofRect(
//			ofRandom(window->getWidth()),
//			ofRandom(window->getHeight()),
			ofRandom(ofGetWindowWidth() - margin * 2 - size) + margin,
			ofRandom(ofGetWindowHeight() - margin * 2 - size) + margin,
			size,
			size
		);
	}

    ofPushStyle();
    ofSetColor(ofColor::ghostWhite);
	ofDrawBitmapStringHighlight("fps: " + ofToString(ofGetFrameRate(),0), 20, 20);
	ofDrawBitmapStringHighlight("value from slider: " + ofToString(radius), 20, 40);
	ofDrawBitmapString("value from keys: " + key_str, 20, 60);
	key_str = "";
    ofPopStyle();
	
	ofSetColor(ofColor::black, 150);
	ofRect(ofGetWindowWidth()/2- radius/2, ofGetWindowHeight()/2 - radius / 2, radius, radius);

	ofSetColor(color, 100);
	ofCircle(cursor.x, cursor.y, radius / 2);

	ofSetColor(ofColor::white);
//	OfGUI.draw();
}

void ofApp::exit()
{
	ofLogVerbose() << "exit";
//	ofGetMainLoop()->removeWindow(windowPtr);
}

//--------------------------------------------------------------
void ofApp::keyPressed(ofKeyEventArgs& key){
	key_str = key.key;
	cout << key.key <<endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(ofKeyEventArgs&  key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	cursor = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}


