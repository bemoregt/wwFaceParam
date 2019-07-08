#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){

    img1.load("/Users/mun/Desktop/ppp.png");
    // for face detection
    finder.setup("haarcascade_frontalface_default.xml");
    //finder.setPreset(ObjectFinder::Fast);
    //finder.setUseHistogramEqualization(true);
    finder.setMinSizeScale(0.1);
    finder.setMaxSizeScale(0.2);
    
    minScale=1;
    maxScale=1;
}

//--------------------------------------------------------------
void ofApp::update(){

    img1.update();
    finder.setMinSizeScale(minScale);
    finder.setMaxSizeScale(maxScale);
    
    if(img1.getWidth() >0) {
        finder.update(img1);
        if(finder.size()>0){
            roi = toCv(finder.getObject(0));
            //ofLog() << roi.x ;
        }
    }//if
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    img1.draw(0, 0, 804, 804);
    finder.draw();
    ofDrawBitmapStringHighlight(ofToString(finder.size()), 10, 20);
    
    // filled box
    ofSetColor(100, 100, 100);
    ofDrawRectangle(10, 10, 400, 70);
    
    // text
    ofSetColor(255);

    ofDrawBitmapString("MinSizeScale = " + ofToString(minScale), 20, 30);
    ofDrawBitmapString("MaxSizeScale = " + ofToString(maxScale), 20, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    minScale= x/img1.getWidth();
    maxScale= y/img1.getHeight();
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
