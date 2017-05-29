#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// init ui
	ui->show();
	ui->setRadius(100);
	ui->setColor(ofColor::white);

	cursor = ofPoint(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushStyle();
	ofSetColor(255,100);
	ofDrawBitmapString("value from slider: " + ofToString(ui->getRadius()), 20, 20);
	ofPopStyle();



	int radius = ui->getRadius();
	ofSetColor(ofColor::grey);
	ofRect(ofGetWindowWidth() / 2 - radius / 2, ofGetWindowHeight() / 2 - radius / 2, radius, radius);
	ofSetColor(ui->getColor(), 100);
	ofEllipse(cursor.x, cursor.y, radius, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
