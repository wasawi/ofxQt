#include "ofApp_A.h"

//--------------------------------------------------------------
ofApp_A::ofApp_A(QWidget *parent)
:QofApp(parent){
	ofLogVerbose() << "ofApp_A Ctor";
}

//--------------------------------------------------------------
ofApp_A::~ofApp_A()
{
	ofLogVerbose() << "ofApp_A Dtor";
//	OfGUI.clear();
	imgui.close(); // important
//	stopRender();
}

//--------------------------------------------------------------
void ofApp_A::setup()
{
	ofLogVerbose() << "ofApp_A setup";

	imgui.setup(new ImguiTheme());
//	ofBackground(10);

	ofEnableAntiAliasing();
	ofBackground(ofColor::darkGrey);

	key_str = "";

// 	parameters.setName("parameters");
// 	parameters.settings.add(radius.set("radius", 50, 1, 100));
// 	parameters.add(posX.set("posX", 0.0f, 0.0f, ofGetWindowWidth()));
// 	parameters.add(posY.set("posY", 0.0f, 0.0f, ofGetWindowHeight()));
// 
// 	parameters.add(color.set("color", ofColor::yellow, 0, 255));
// 	parameters.add(framerate.set("framerate", 60, 0, 120));
// 	parameters.add(verticalSync.set("verticalSync", true));
//	OfGUI.setup(parameters);


	model->settings.add(radius.set("radius", 50, 1, 100));
	model->settings.add(posX.set("posX", 0.0f, 0.0f, ofGetWindowWidth()));
	model->settings.add(posY.set("posY", 0.0f, 0.0f, ofGetWindowHeight()));

	model->settings.add(color.set("color", ofColor::yellow, 0, 255));
	model->settings.add(framerate.set("framerate", 60, 0, 120));
	model->settings.add(verticalSync.set("verticalSync", true));



//	framerate.addListener(this, &ofApp_A::setFramerate);
//	verticalSync.addListener(this, &ofApp_A::setVerticalSync);

	videoFBO.allocate(400, 200);

}

//--------------------------------------------------------------
void ofApp_A::setFramerate(int value)
{
	getOfWindow()->setFrameRate(value);
}

//--------------------------------------------------------------
void ofApp_A::setVerticalSync(bool value)
{
	getOfWindow()->setVerticalSync(value);
}

//--------------------------------------------------------------
void ofApp_A::update(){
	ofLogVerbose() << "update";

	videoFBO.begin();	//----- FBO begin
//	ofSetColor(ofColor::ghostWhite);
//	liveTexture.draw(0, 0);

	ofPushStyle();
	ofSetColor(ofColor::yellow, 50);
	ofDrawBitmapStringHighlight("Hello FBOoo!", 50, 100);
	ofPopStyle();

	videoFBO.end();		//----- FBO end
}

//--------------------------------------------------------------
void ofApp_A::draw(){
	ofLogVerbose() << "draw";

	imgui.begin();
	ImGui::Text("Hello ImGui!", ofVec2f(0, 0));
	radius.draw();
	posX.draw();
	posY.draw();
	imgui.end();

// 	cout << "window w " << getOfWindow()->getWidth() << endl;
// 	cout << "window h " << getOfWindow()->getHeight() << endl;
// 	cout << "of w " << ofGetWindowWidth() << endl;
// 	cout << "of h " << ofGetWindowHeight() << endl;

//	ofEnableAntiAliasing();
	
	videoFBO.draw(0,0);

	ofPushStyle();
	ofSetColor(ofColor::white, 50);
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
	ofPopStyle();

	ofPushStyle();
    ofSetColor(ofColor::ghostWhite);
	ofDrawBitmapStringHighlight("fps: " + ofToString(ofGetFrameRate(),0), 20, 20);
	ofDrawBitmapStringHighlight("value from slider: " + ofToString(radius), 20, 40);
	ofDrawBitmapString("value from keys: " + key_str, 20, 60);
	key_str = "";

// 	ofSetColor(ofColor::black, 150);
// 	ofRect(ofGetWindowWidth()/2- radius/2, ofGetWindowHeight()/2 - radius / 2, radius, radius);


	ofSetColor(color, 100);
	ofCircle(posX, posY, radius / 2);
	ofPopStyle();

//	ofSetColor(ofColor::white);
//	OfGUI.draw();
}

//void ofApp_A::exit()
//{
//	ofLogVerbose() << "exit";
//	QofApp_A::exit();// if you implement exit you need to call base class.
//}

//--------------------------------------------------------------
void ofApp_A::keyPressed(ofKeyEventArgs& key){
	key_str = key.key;
	cout << key.key <<endl;
}

//--------------------------------------------------------------
void ofApp_A::keyReleased(ofKeyEventArgs&  key){

}

//--------------------------------------------------------------
void ofApp_A::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp_A::mouseDragged(int x, int y, int button){
	posX = x;
	posY = y;
}

//--------------------------------------------------------------
void ofApp_A::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_A::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_A::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp_A::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp_A::windowResized(int w, int h){
	posX.set("posX", posX, 0.0f, ofGetWindowWidth());
	posY.set("posY", posY, 0.0f, ofGetWindowHeight());
}

//--------------------------------------------------------------
void ofApp_A::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp_A::dragEvent(ofDragInfo dragInfo){

}


