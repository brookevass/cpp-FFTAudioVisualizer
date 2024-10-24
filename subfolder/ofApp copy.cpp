#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    sound.load("bassbounce.wav");
    sound.play();
    sound.setLoop(true);

    gui.setup();
    gui.add(audioamplitude.set("Audio Amplitude", 0.5, 0.0, 1.0));
    gui.add(visualdecay.set("Visual Decay", 0.5, 0.0, 1.0));
    gui.add(shapeRotation.set("Shape Rotation", 0.0, 0.0, 360.0));  //  control for rotation
    gui.add(shapeSize.set("Shape Size", 50.0, 10.0, 300.0));         //  control for shape size

    fft = new float[128];
    for (int i = 0; i < 128; i++){
        fft[i] = 0;
    }
    bands = 64;

    cam.setDistance(400);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();

    sound.setVolume(audioamplitude);
    float *soundSpectrum = ofSoundGetSpectrum(bands);
   
    for (int i = 0; i < bands; i++){
        fft[i] *= visualdecay;
        if (fft[i] < soundSpectrum[i]){
            fft[i] = soundSpectrum[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(10, 10, 20);  // Dark background
    ofEnableBlendMode(OF_BLENDMODE_ADD);  // Blend mode for brighter effect

    cam.begin();  //  3D camera

    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);  // Center object

    //  rotation when using GUI control
    ofRotateDeg(shapeRotation);


    for (int i = 0; i < bands; i++) {
        float angle = ofMap(i, 0, bands, 0, TWO_PI);  // shapes go in circle
        float radius = 300;

        //  positions for shapes
        float x = radius * cos(angle) * (1 + fft[i] * 2);
        float y = radius * sin(angle) * (1 + fft[i] * 2);
        float z = sin(ofGetElapsedTimef() * 0.5 + i) * 50;

        //  size based on GUI
        float shapeCurrentSize = shapeSize * (1 + fft[i]);

        // Choose a shape (rectangle or circle) and draw
        ofSetColor(255, 100 + i * 2, 200 + i * 4, fft[i] * 255);
        if (i % 2 == 0) {
            ofDrawRectangle(x, y, z, shapeCurrentSize, shapeCurrentSize);
        } else {
            ofDrawCircle(x, y, z, shapeCurrentSize);
        }
    }

    ofPopMatrix();

    cam.end();  // End the 3D camera


    gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
