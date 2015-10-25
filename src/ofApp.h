#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxMaxim.h"
#include "ofSounds.h"
#include "ofPage.h"
#include "HomePage.h"
#include "Introduction.h"
#include "Ball.h"


class ofApp : public ofxiOSApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
        void audioReceived( float * input, int bufferSize, int nChannels );
        void audioRequested( float * output, int bufferSize, int nChannels );
        int		initialBufferSize;
        int		sampleRate;
    
        ofPage myPage;//base class
        ofSounds mySounds; 
    
        //load in pages
        HomePage myHomePage;
        Introduction myIntroduction;
    
        ofPoint vel;//for accelarometer
        ofPoint vel1;
        ofPoint vel2;
        ofPoint vel3;
        ofPoint vel4;
        ofPoint vel5;
        ofPoint vel6;
        ofPoint vel7;
        
        bool accel;
        vector<Ball> balls;

};


