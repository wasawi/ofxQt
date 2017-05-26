#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	// init ui
	ui->show();
	ui->setRadius(100);
	ui->setColor(ofColor::white);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofPushStyle();
	ofSetColor(255);
	ofDrawBitmapString("value from slider: " + ofToString(ui->getRadius()), 20, 20);
	ofPopStyle();

	ofSetColor(ui->getColor());
	ofEllipse(ofGetWidth() / 2, ofGetHeight() / 2, ui->getRadius(), ui->getRadius());
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
