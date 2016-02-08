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
    bool pageBack;
    bool pageForward;
    
    
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
    float endTime; // when do want to stop the timer
    bool  bTimerReached; // used as a trigger when we hit the timer
    bool bMelodyStart;
    bool bMelodyFinished;
    
    //timers using class
    Poco::Stopwatch greyStarCounter;
    Poco::Stopwatch melodyCounter;//only allow an answer after this timer
    int greyCounter;
    int greyCounter2;
    
    //practice note association
    bool pianoNote;
    bool trumpetNote;
    int single_count;
    
    //Practicemelody setup
    bool bPlayPracticeMelody;
    vector<int> practice_melody_v;
    int practice_count;
    
    //trial melody setup
    bool bPlayGroupAMelody;
    bool bPlayGroupBMelody;
    vector<int> trialMelody_1_v;
    vector<int> trialMelody_2_v;
    int trial_melody_count;

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
    
    ofImage greenButton;
    ofImage redButton;
}; // don't forget the semicolon!!

//#endif
