#include "ofApp.h"
ofFbo fbo;
//--------------------------------------------------------------
void ofApp::setup(){
    
    fbo.allocate(ofGetWidth(),ofGetHeight());
    
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();
    
}
float rX = 0;
float rY = 0;
float rZ = 0;
float dScaleX = 1; // delta scale
float dScaleY = 1;
float dScaleZ = 1;



//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.5, time * 0.5, time * 0.5) * 400.0;  // rotate +- 400deg
    rY = ofSignedNoise(time * 0.3) * 400.0;
    rZ = ofSignedNoise(time * 0.9) * 400.0;
    dScaleX = ofNoise(time * 0.2);
    dScaleY = ofNoise(time * 0.4);
    //   dScaleZ = ofNoise(time * 0.6);
    
    
    //-----------------
    //    rX++;
    //    if(ofGetFrameNum()%3 ==0)
    //        rY++;
    //    if(ofGetFrameNum()%7 ==0)
    //        rZ++;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
     fbo.begin();
    ofSetColor(255,255,255,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPushMatrix();
  
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(dScaleX, dScaleY);  // can be 3 dimensional
    // ofScale(0.3,0.3,0.3);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofSetColor(188, 20, 38);
//    for(int i = 0  ; i < 10 ; i++){
//        float t = i *10;
//        float y = ofNoise (t) ;
        ofDrawLine(20 , 200 , -20,200);
//    }

    

    ofPopMatrix();
       fbo.end();
    fbo.draw(0,0);
 
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
