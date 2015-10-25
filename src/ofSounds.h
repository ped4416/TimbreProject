#pragma once
#include <iostream>
#include "ofMain.h"
#include "ofPage.h"
#include "ofxMaxim.h"

class ofSounds : public ofPage{//
    
    //get the ofPage as the route class all other pages will inherit from this.
    //set up for the sounds
    ofxMaxiSample sound1;//theme song
    
    ofxMaxiSample pianoSingle;
    ofxMaxiSample trumpetSingle;
    ofxMaxiSample pianoMelody;
    ofxMaxiSample trumpetMelody;
    
    //Tests for first 2 then real trial starts
    ofxMaxiSample origional1;
    ofxMaxiSample x1;
    
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