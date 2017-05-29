#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofLogLevel(OF_LOG_VERBOSE);
	ofLogToConsole();
	ofEnableAlphaBlending();

	// init ui
	ui->show();
	ui->setRadius(100);
	ui->setColor(ofColor::cyan);

	cursor = ofPoint(ofGetWindowWidth() / 2 - ui->getRadius() / 2, ofGetWindowHeight() / 2 - ui->getRadius() / 2);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(ofColor::gray);
	ofRect(ofGetWindowWidth() / 2 - ui->getRadius() / 2, ofGetWindowHeight() / 2 - ui->getRadius() / 2, ui->getRadius(), ui->getRadius());
	ofSetColor(ui->getColor(), 50);
	ofCircle(cursor.x, cursor.y, ui->getRadius() / 2);
	ofDrawBitmapString("value from slider: " + ofToString(ui->getRadius()), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	cursor = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
