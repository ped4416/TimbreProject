#pragma once
#include <iostream>
#include "ofMain.h"
#include "ofPage.h"
#include "ofxMaxim.h"
#include "Poco/Stopwatch.h"

class ofSounds : public ofPage{//
    
    //get the ofPage as the route class all other pages will inherit from this.
    //set up for the sounds
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
    ofxMaxiSample tom1;
    ofxMaxiSample tom2;
    
public: // place public functions or variables declarations here
    
    ofSounds();//constructor
    
    // methods, equivalent to specific functions of your class objects
    void setup();
    void update();
    float playSounds(float x);//left channel
    float playSounds1(float y);//right channel

    
private: // place private functions or variables declarations here
    
    
}; // dont't forget the semicolon!!

//#endif