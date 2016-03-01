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
        //vectors to hold both A and B melodies. The index of playback is set
        //using the variable trialMelody_1_v & trialMelody_2_v these same random
        //index values are used to place all other data output lined up for analysis
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
    
        /*======================== variabels to store all data to text file =====================*/
    
        string userID_s;
        string userAge_s;
        string sessionNumber_s;//either A1, A2, B1 or B2
        string sessionOrder_s;//either AB or BA
        string dateOfTest_s;
        string timeofTest_s;
        string pianoLeft_s;//print out TRUE or FALSE
    
        //arrays to store floats of practice trial times in milliseconds
        vector<float> baselineTimeData_v;
        //arrays to store floats of all full trial times in milliseconds
        vector<float> trialTimeData_A_v;
        vector<float> trialTimeData_B_v;
        //vectors to store the answers to the random order of trials
        vector<int> baseline_accuracy_v;//store as a true or false text!
        vector<int> trial_accuracy_A_v;//store as true or false
        vector<int> trial_accuracy_B_v;//store as true or false
    
        //vectors to store all the variables Marco has made available
        vector<int> number_v;
        vector<string> ID_v;
        vector<int> session_v;
        vector<int> practice_v;
        vector<int> timbre_v;
        vector<int> probability_v;
        vector<int> basename_v;
        vector<int> filename_v;
        vector<int> pitch_v;
        vector<int> pitch_intercal_v;
        vector<int> interval_size_v;
        vector<int> interval_direction_v;
        vector<int> information_content_v;
        vector<int> probe_repetitions_v;
        vector<int> probe_octave_repetitions_v;
    
        //create all the char's needed to fill the arrays apropriatley.
        string ap1, ap2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, bp1, bp2, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20;
    
    
};


