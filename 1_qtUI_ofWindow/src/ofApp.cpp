#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// init ui
	ui.show();
	ui.circleRadius = 100;
	ui.color = ofColor::white;

}

//--------------------------------------------------------------
void ofApp::update(){
	// nothing done here. 
	// ui values are updated on QtGuiClass callbacks
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushStyle();
    ofSetColor(255);
    ofDrawBitmapString("value from slider: " + ofToString(ui.circleRadius), 20, 20);
    ofPopStyle();

	ofSetColor(ui.color);
    ofEllipse(ofGetWidth()/2, ofGetHeight()/2, ui.circleRadius, ui.circleRadius);
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
