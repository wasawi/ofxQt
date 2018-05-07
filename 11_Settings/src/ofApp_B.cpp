#include "ofApp_B.h"

ofApp_B::ofApp_B(QWidget *parent)
:QofApp(parent){
	ofLogVerbose() << "ofApp_B Ctor";
}

ofApp_B::~ofApp_B()
{
	ofLogVerbose() << "ofApp_B Dtor";
//	OfGUI.clear();
	imgui.close(); // important
//	stopRender();
}

//--------------------------------------------------------------
void ofApp_B::setup()
{
	ofLogVerbose() << "ofApp_B setup";

	imgui.setup(new ImguiTheme());
//	ofBackground(10);

	ofEnableAntiAliasing();
	ofBackground(ofColor::darkGrey);

	key_str = "";

	model->settings.add(size.set("size", 50, 1, 100));
	model->settings.add(angle.set("angle", 50, 0, 360));

	model->settings.add(posX.set("posX", 0.0f, 0.0f, ofGetWindowWidth()));
	model->settings.add(posY.set("posY", 0.0f, 0.0f, ofGetWindowHeight()));

	model->settings.add(color.set("color", ofColor::pink, 0, 255));
	model->settings.add(framerate.set("framerate", 60, 0, 120));
	model->settings.add(verticalSync.set("verticalSync", true));
//	OfGUI.setup(parameters);

//	framerate.addListener(this, &ofApp_B::setFramerate);
//	verticalSync.addListener(this, &ofApp_B::setVerticalSync);

	videoFBO.allocate(400, 200);

}

void ofApp_B::setFramerate(int value)
{
	getOfWindow()->setFrameRate(value);
}

void ofApp_B::setVerticalSync(bool value)
{
	getOfWindow()->setVerticalSync(value);
}

//--------------------------------------------------------------
void ofApp_B::update(){
	ofLogVerbose() << "update";

	videoFBO.begin();	//----- FBO begin
//	ofSetColor(ofColor::ghostWhite);
//	liveTexture.draw(0, 0);

	ofPushStyle();
	ofDrawBitmapStringHighlight("Hello FBOoo!", 50, 100);
	ofPopStyle();

	videoFBO.end();		//----- FBO end
}

//--------------------------------------------------------------
void ofApp_B::draw(){
	ofLogVerbose() << "draw";

	imgui.begin();
	ImGui::Text("Hello ImGui!", ofVec2f(0, 0));
	size.draw();
	angle.draw();
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
	int labelH = 10;
	for (int i = 0; i < 100; i++) {
		ofRect(
//			ofRandom(window->getWidth()),
//			ofRandom(window->getHeight()),
			ofRandom(ofGetWindowWidth() - margin * 2 - labelH) + margin,
			ofRandom(ofGetWindowHeight() - margin * 2 - labelH) + margin,
			labelH,
			labelH
		);
	}
	ofPopStyle();

	ofPushStyle();
    ofSetColor(ofColor::ghostWhite);
	ofDrawBitmapStringHighlight("fps: " + ofToString(ofGetFrameRate(),0), 20, 20);
	ofDrawBitmapStringHighlight("value from slider: " + ofToString(size), 20, 40);
	ofDrawBitmapString("value from keys: " + key_str, 20, 60);
	key_str = "";

	
// 	ofSetColor(ofColor::black, 150);
// 	ofRect(ofGetWindowWidth()/2- radius/2, ofGetWindowHeight()/2 - radius / 2, radius, radius);

	ofPushView();
		ofSetColor(color, 200);

		ofTranslate(posX, posY);
		ofRotateDeg(angle);
		ofRect(0, 0, size, size / 2);

	ofPopView();
	ofPopStyle();

//	ofSetColor(ofColor::white);
//	OfGUI.draw();
}

//void ofApp_B::exit()
//{
//	ofLogVerbose() << "exit";
//	QofApp_B::exit();// if you implement exit you need to call base class.
//}

//--------------------------------------------------------------
void ofApp_B::keyPressed(ofKeyEventArgs& key){
	key_str = key.key;
	cout << key.key <<endl;
}

//--------------------------------------------------------------
void ofApp_B::keyReleased(ofKeyEventArgs&  key){

}

//--------------------------------------------------------------
void ofApp_B::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp_B::mouseDragged(int x, int y, int button){
	posX = x;
	posY = y;
}

//--------------------------------------------------------------
void ofApp_B::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_B::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_B::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp_B::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp_B::windowResized(int w, int h){
	posX.set("posX", posX, 0.0f, ofGetWindowWidth());
	posY.set("posY", posY, 0.0f, ofGetWindowHeight());
}

//--------------------------------------------------------------
void ofApp_B::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp_B::dragEvent(ofDragInfo dragInfo){

}


