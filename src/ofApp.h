#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxMaxim.h"
#include "ofSounds.h"
#include "ofPage.h"
//#include "HomePage.h"
//#include "Introduction.h"
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
    
        //get the ofPage as the route class all other pages will inherit from this.
        //set up for the sounds
    
        //load in songs for playback
        int testMelodysLength;
        int sessionA_MelodysLength;
        int sessionB_MelodysLength;
        vector <maxiSample> testMelodys_v;
        vector <maxiSample> sessionA_Melodys_v;
        vector <maxiSample> sessionB_Melodys_v;
        
        //ofxMaxiSample sound1;//theme song
        
        ofxMaxiSample pianoSingle;
        ofxMaxiSample trumpetSingle;
        ofxMaxiSample pianoMelody;
        ofxMaxiSample trumpetMelody;
        
        //Tests for first 2 then real trial starts
        ofxMaxiSample trial1_x_piano;//3-56-4-x-piano-120
        ofxMaxiSample trial2_trumpet;//3-79-10-original-trumpet-120
        ofxMaxiSample trial3_piano;//8-1127-0-original-piano-120
        ofxMaxiSample trial4_x_trumpet;//9-622-1-x-trumpet-120
        
        //real trial starts from here
        ofxMaxiSample origional2Trumpet;
        ofxMaxiSample origional2Piano;
        ofxMaxiSample x2;
        ofxMaxiSample origional3;
        ofxMaxiSample x3;
        
        //sounds fx
        ofxMaxiSample cheer;
        ofxMaxiSample badLuck;

    
        ofPage myPage;//base class
        //ofSounds mySounds;
    
        //load in pages
        //HomePage myHomePage;
        //Introduction myIntroduction;
    
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


