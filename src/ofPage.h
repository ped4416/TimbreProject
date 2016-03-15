// =============================================================================
//
// Copyright (c) 2016 Pedro Kirk <http://www.pedrokirk.co.uk>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================



#pragma once

//#include "ofxiOS.h"
//#include "ofxiOSExtras.h"
#include <iostream>
#include "ofMain.h"
#include <math.h>
#include "Poco/Stopwatch.h"
#include "ofxMaxim.h"
#include <time.h>
#include <vector>


class ofPage { //this is the base class
    
public: // place public functions or variables declarations here
    
    //what state is the app in??
    enum state_t {
        
    };
    
    state_t state;
    
    ofPage();//constructor
    
    // methods, equivalent to specific functions of your class objects
    void setup();
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    void drawPage();
    void touchPressed(int x, int y);
    //void playSounds(float x);
    void showPage(int x, int y);//a method to show the pages of the book
    
    bool showAccelPage(int x);
    
    // variables
    int buttonSize;
    int currentPage;
    int currentFrame;//set up the timing device for the whole book!
    int fadeFrame;
    int secondTime;
    float fadeUpTime;
    float fadeDownTime;
    
    //control fade states
    bool fadePage;
    bool homeButtonBack;
    
    //page naviagation
    bool howTo;
    bool showCredits;
    bool showOptionsTab;
    bool showSettings;
    bool pressBackHome;
    bool bFinished;
    bool bDebug;
    
    
    //set up for animation
    int   appFPS;
    float sequenceFPS;
    bool  bFrameIndependent;
    float totalTime;
    float totalTime2;
    float totalTime3;
    bool back;
    
    //animation booleans
    bool showGreenDot;
    bool showRedDot;
    //store the answers to keep track of all green dots
    vector<int> answered_v;
    bool showStars;
    
    //sound booleans
    bool playPianoSingle;
    bool playTrumpetSingle;
    
    bool playPianoMelody;
    bool playTrumpetMelody;
    
    //guessed correct
    bool bGuessedPiano;
    bool bGuessedTrumpet;
    bool bGuessedWrong;
    
    //text move booleans
    bool textshow;
    bool texthide;
    bool stopPress;//to stop press functionallity when in settings
    
    //narration
    bool narrate;
    bool narrateTemp;// to stop narration when settings menu is on
    
    ofImage homeButton;//make this button public
    
    int x1;
    int x2;
    int y1;
    int y2;
    
    int trialXpos;
    int trialYpos;
    
    bool hasPressed;
    bool bPermitNextPage;
    bool bPermitGreenDot; 
    
    //fonts
    ofTrueTypeFont franklinBook14;
    ofTrueTypeFont trials;
    ofTrueTypeFont buttonText;
    ofTrueTypeFont dotsText;
    ofTrueTypeFont qm_Text;
    
    //animated dots
    bool showDots;
    bool bGroupAB;
    bool bGroupBA;
    
    //piano left or right
    bool bPianoLeft;
    bool bSessionA1;
    bool bSessionA2;
    bool bSessionB1;
    bool bSessionB2;
    
    //timer
    float startTime; // store when we start time timer
    float startDotTime; // store when we start time timer
    float current_trial_time_counter;//store the answers to all melodies 
    float endTime; // when do want to stop the timer
    bool  bTimerReached; // used as a trigger when we hit the timer
    bool bMelodyStart;
    bool bMelodyFinished;
    
    //timers using class
    Poco::Stopwatch greyStarCounter;
    Poco::Stopwatch melodyCounter;//only allow an answer after this timer
    Poco::Stopwatch practice_time_counter;//start at exactly 200000ms
    Poco::Stopwatch trial_time_counter;//start at exactly 200000ms
    int greyCounter;
    int greyCounter2;
    
    //practice note association
    bool pianoNote;
    bool trumpetNote;
    int single_count;
    
    //Practicemelody setup
    bool bPlayPracticeMelody;
    vector<int> practiceMelody_1_v;
    vector<int> practiceMelody_2_v;
    int practice_count;
    int practice_permit_count;//to permit page forward when 2 answers are given. 
    
    //trial melody setup
    bool bPlayGroupAMelody;
    bool bPlayGroupBMelody;
    int trial_melody_count;
    bool bResetMelody;
    bool bShowTrialText;
    bool bShowSingleNoteText;
    
    //vectors used to store the index for each set of melodies
    //these are randomised in ofPage.cpp every time the app launches
    //using std::random_shuffle these indexes must be used to find out exactly
    //what the other variables are that Marco gives such as expectancy, group etc
    vector<int> trialMelody_1_v;
    vector<int> trialMelody_2_v;

private: // place private functions or variables declarations here
    
    ofImage leftArrow;
    ofImage rightArrow;
    
    ofImage optionsTab;
    ofImage questionMark;
    ofImage returnArrow;
    ofImage settings;
    ofImage settingsPage;
    ofImage howToPage;
    ofImage starTouch;
    ofImage credits;
    ofImage playPage;
    //grey stars
    ofImage star1a;
    ofImage star1b;
    ofImage star1c;
    ofImage star2a;
    ofImage star2b;
    ofImage star2c;
    ofImage star3a;
    ofImage star3b;
    ofImage star3c;
    ofImage star4a;
    ofImage star4b;
    ofImage star4c;
    
    //load images for the Intro to Giles Page & The Piano + Trumpet
    ofImage bearImg;
    ofImage pianoImg;
    ofImage trumpetImg;
    ofImage cover;
    
    ofImage buttonSelect;
    ofImage buttonSelect2;
    
    string answered_all;
}; // don't forget the semicolon!!

//#endif
