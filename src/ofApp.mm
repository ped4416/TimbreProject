#include "ofApp.h"
#define BOUNCE_FACTOR     0.7



//--------------------------------------------------------------
void ofApp::setup(){
    
    //If you want a landscape oreintation
    ofSetOrientation(OF_ORIENTATION_90_RIGHT);

    //sound1.loadOgg(ofToDataPath("sounds/Theme1_Stem1.ogg"));
    myPage.setup();
    mySounds.setup();
    myHomePage.setup();
    myIntroduction.setup();
    balls.assign(2, Ball());
    // initialize all of the Ball particles
    for(int i=0; i<balls.size(); i++){
        balls[i].init(i);
    }
    
        
    //setup audio Stuff
    sampleRate 			= 44100;
    initialBufferSize	= 512;

    ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);

}

//--------------------------------------------------------------
void ofApp::update(){
    myHomePage.update();
    myIntroduction.update();
    myPage.update();
    mySounds.update();
    
    //set up accelarometer calls
    vel.y += ofxAccelerometer.getForce().x*0.1;
    vel.x += ofxAccelerometer.getForce().y*0.1;
    vel1.y += ofxAccelerometer.getForce().x*0.1;
    vel1.x += ofxAccelerometer.getForce().y*0.1;
    vel2.y += ofxAccelerometer.getForce().x*0.1;
    vel2.x += ofxAccelerometer.getForce().y*0.1;
    vel3.y += ofxAccelerometer.getForce().x*0.1;
    vel3.x += ofxAccelerometer.getForce().y*0.1;
    vel4.y += ofxAccelerometer.getForce().x*0.1;
    vel4.x += ofxAccelerometer.getForce().y*0.1;
    vel5.y += ofxAccelerometer.getForce().x*0.1;
    vel5.x += ofxAccelerometer.getForce().y*0.1;
    vel6.y += ofxAccelerometer.getForce().x*0.1;
    vel6.x += ofxAccelerometer.getForce().y*0.1;
    vel7.y += ofxAccelerometer.getForce().x*0.1;
    vel7.x += ofxAccelerometer.getForce().y*0.1;
    
    
    float x;
    x = myPage.showAccelPage(1);
    
    if (x == 1) {
        
        for(int i=0; i < balls.size(); i++){
            balls[i].update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myHomePage.draw();
    myIntroduction.draw();
    
    //display page 8 accelarometer info
    float x;
    x = myPage.showAccelPage(1);//is page 9 displaying?
    
    if (x == 1) {
        
        ofPushStyle();
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        for(int i = 0; i< balls.size(); i++){
            balls[i].draw();
        }
        ofPopStyle();
        
    }

    myPage.draw();//draw last to layer ontop of other images
}

//--------------------------------------------------------------
void ofApp::audioRequested(float * output, int bufferSize, int nChannels){
    
    if( initialBufferSize != bufferSize ){
        ofLog(OF_LOG_ERROR, "your buffer size was set to %i - but the stream needs a buffer size of %i", initialBufferSize, bufferSize);
        return;
    }
    
    for (int i = 0; i < bufferSize; i++){
        
        float x;
        //float y;
        
        
        x = mySounds.playSounds(*output)*0.8;//left channel in
        //y = mySounds.playSounds1(*output)*0.9;//right channel in
        //x = sound1.play();
    
        output[i*nChannels    ] = x;//left out
        output[i*nChannels + 1] = x;//right out
    }
    
}

//--------------------------------------------------------------
void ofApp::audioReceived(float * input, int bufferSize, int nChannels){
    
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    
    //print out touch data
    ofLog(OF_LOG_VERBOSE, "touch %d down at (%d,%d)", touch.id, touch.x, touch.y);
    cout << "Touch Position Is ... " << touch << endl;
    
    balls[touch.id].moveTo(touch.x, touch.y);
    balls[touch.id].bDragged = true;
    mySounds.showPage(touch.x, touch.y);
    myPage.showPage(touch.x, touch.y);
    myHomePage.showPage(touch.x, touch.y);
    myIntroduction.showPage(touch.x, touch.y);
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d moved at (%d,%d)", touch.id, touch.x, touch.y);
    balls[touch.id].moveTo(touch.x, touch.y);
    balls[touch.id].bDragged = true;

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d up at (%d,%d)", touch.id, touch.x, touch.y);
    balls[touch.id].bDragged = false;
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}

