#include "ofPage.h"
//#include "maximilian.h"
//#include <iostream>
//#include <time.h>

ofPage::ofPage(){
    
    //variables for all pages of Timbre App
    buttonSize = 180;
    practice_count = -1;//allow for 0 index
    trial_melody_count = -1;//allow for 0 index
    currentFrame = 0;
    fadeFrame = 0;
    currentPage = -1;//TODO - set user input..
    secondTime = 30;//20
    fadeUpTime = 0.05;
    current_trial_time_counter = 0;
   
    
    //bools for page naviagation
    fadePage = false;
    showOptionsTab = false;
    howTo = false;
    showCredits = false;
    showSettings = false;
    homeButtonBack = false;
    pressBackHome = false;
    pageBack = false;//allows correct files to load or unload
    pageForward = false;
    
    showGreenDot = false;//start as false
    showRedDot = true;//start with warning that trial must be completed
    showStars = false;
    playPianoSingle = false;
    playTrumpetSingle = false;
    playPianoMelody = false;
    playTrumpetMelody = false;
    bGuessedPiano = false;
    bGuessedTrumpet = false;
    bGuessedWrong = false;
    bShowTrialText = false;
    bShowSingleNoteText = false;

    
    //user setup
    bSessionA1 = false;
    bSessionA2 = false;
    bSessionB1 = false;
    bSessionB2 = false;
    bGroupAB = false;
    bGroupBA = false;
    
    //start button positions
    x1 = 100;
    x2 = 400;
    y1 = 100;
    y2 = 400;
    
    trialXpos = 900;
    trialYpos = 50;
    
    hasPressed = false; 
    
    //animatied dots
    showDots = false;
    
    bMelodyFinished = false;
    bPianoLeft = true;//start true!

    bTimerReached = false;
    startTime = ofGetElapsedTimeMillis();  // get the start time
    startDotTime = ofGetElapsedTimeMillis();  // get the start time to use for dots on screen
    endTime = (int)ofRandom(1000, 5000); // in milliseconds
    greyCounter = 0;
    greyCounter2 = 0;
    
    //melodies setup
    bPlayPracticeMelody = false;
    bPlayGroupAMelody = false;
    bPlayGroupBMelody = false;
    bResetMelody = false;
    
    //practice note association
    pianoNote = false;
    trumpetNote = false;
    single_count = 0;
}

void ofPage::setup(){
    
    leftArrow.loadImage("buttons/LEFTARROW.png");
    rightArrow.loadImage("buttons/RIGHTARROW.png");
    homeButton.loadImage("buttons/HOME.png");
    returnArrow.loadImage("buttons/RETURN.png");
    //settings.loadImage("rgb/buttons/tosettings.png");
    optionsTab.loadImage("Images/menu.png");//load options tab
    starTouch.loadImage("rgb/buttons/starTouch.png");
    //credits.loadImage("rgb/credits.jpg");
    
    //playPage.loadImage("Images/PlayPage.jpg");
    
    //load grey stars
    star1a.loadImage("Images/1a.png");
    star1b.loadImage("Images/1b.png");
    star1c.loadImage("Images/1c.png");
    star2a.loadImage("Images/2a.png");
    star2b.loadImage("Images/2b.png");
    star2c.loadImage("Images/2c.png");
    star3a.loadImage("Images/3a.png");
    star3b.loadImage("Images/3b.png");
    star3c.loadImage("Images/3c.png");
    star4a.loadImage("Images/4a.png");
    star4b.loadImage("Images/4b.png");
    star4c.loadImage("Images/4c.png");
    
    cover.loadImage("Images/homePage.png");
    bearImg.loadImage("Images/bearfull.png");
    pianoImg.loadImage("Images/PIANO.png");
    trumpetImg.loadImage("Images/TRUMPET.png");
    buttonSelect.loadImage("buttons/slow.png");
    buttonSelect2.loadImage("buttons/start.png");
        
    //set up fonts
    franklinBook14.loadFont("fonts/Georgia.ttf", 22);
    franklinBook14.setLineHeight(18.0f);
    franklinBook14.setLetterSpacing(1.037);
    
    trials.loadFont("fonts/Georgia.ttf", 16);
    trials.setLineHeight(18.0f);
    trials.setLetterSpacing(1.037);
    
    buttonText.loadFont("fonts/Georgia.ttf", 30);
    buttonText.setLineHeight(18.0f);
    buttonText.setLetterSpacing(1.037);
    
    dotsText.loadFont("fonts/Georgia.ttf", 200);
    dotsText.setLineHeight(18.0f);
    dotsText.setLetterSpacing(1.037);
    qm_Text.loadFont("fonts/Georgia.ttf", 200);
    dotsText.setLineHeight(18.0f);
    dotsText.setLetterSpacing(1.037);
    
    //setup random test melodies
    practice_melody_v.resize(4);
    for(int i = 0; i < practice_melody_v.size(); i++){
        practice_melody_v[i] = i;//0,1,2,3
        cout << "Test Number Is Now: "  << practice_melody_v[i] <<endl;
    }
    
    //(practice_melody_v.begin(), practice_melody_v.end());
    
    for(int i = 0; i < practice_melody_v.size(); i++){
        cout << practice_melody_v[i] << endl;
    }
    
    //setup session 1 (A1 - B1 test melodies)
    trialMelody_1_v.resize(20);
    for(int i = 0; i < trialMelody_1_v.size(); i++){
        trialMelody_1_v[i] = i;//0,1,2,3..... 20
        cout << "Session 1 Test Number Is Now: "  << trialMelody_1_v[i] <<endl;
    }
    
    std::random_shuffle (trialMelody_1_v.begin(), trialMelody_1_v.end());
    
    for(int i = 0; i < trialMelody_1_v.size(); i++){
        cout << "Session 1 Index Order: " << trialMelody_1_v[i] << endl;
    }
    
    //setup session 2 (A2 - B2 test melodies)
    trialMelody_2_v.resize(20);
    for(int i = 0; i < trialMelody_2_v.size(); i++){
        trialMelody_2_v[i] = i;//0,1,2,3
        cout << "Session 2 Test Number Is Now: "  << trialMelody_2_v[i] <<endl;
    }
    
    std::random_shuffle (trialMelody_2_v.begin(), trialMelody_2_v.end());
    
    for(int i = 0; i < trialMelody_2_v.size(); i++){
        cout << "Session 2 Index Order: " << trialMelody_2_v[i] << endl;
    }
}

void ofPage::update(){

    //update timers
    if (bMelodyStart == true) {
        melodyCounter.start();
        //cout << "MELODY TIMER IS NOW: " << melodyCounter.elapsed() << endl;
    }
    
    float current_melodyCouter = melodyCounter.elapsed();
    //cout << "MELODY TIMER IS NOW: " << current_melodyCouter << endl;

    
    //exact time for practice trials and main trials to store into arrays
    if(current_melodyCouter >= 2000000){//onset of last note
        trial_time_counter.start();
        //cout << "START TRIAL TIMER " << endl;
    }
    
    //exact time for practice trials and main trials to store into arrays
    if(hasPressed == true){//onset of last note
        cout << "TIMER IS NOW: " << trial_time_counter.elapsed() << endl;
        current_trial_time_counter = trial_time_counter.elapsed();
        hasPressed = false;//reset to store just one timestamp for each answer
    }
    
    
    
    if(melodyCounter.elapsed() > 10 && melodyCounter.elapsed() < 2050000){//50ms/50,000 microseconds)
        showStars = false;
        hasPressed = false;
        bGuessedWrong = false;
        showStars = false;
        //printf("MELODY PLAYING NOW\n");
        //cout << "SHOW STARS IS " << showStars << endl;
        //cout << "TIMER IS NOW " << melodyCounter.elapsed() << endl;
    }
    
    //timer set to 50ms after last note onset for setting the permitted start time to answer
    if(melodyCounter.elapsed() > 2050000 && greyStarCounter.elapsedSeconds() < 2000000)
    {
        //printf("MELODY FINISHED\n");
        //cout << "\nMELODY FINISHED  " << bMelodyFinished << endl;//debug?
        bMelodyFinished = true;
        bMelodyStart = false;
    }
    
    //timer to reset all the audio files once last note is heard
    if(melodyCounter.elapsed() > 4001000)
    {
        bResetMelody = true;
        bShowTrialText = true;
    } else bResetMelody = false;
//    //reset bool to allow multiple trials
//    if(melodyCounter.elapsed() > 4000000)
//    {
//        bResetMelody = false;
//    }
    
    //counter is only activated when the user presses either piano or trumpet
    if (greyStarCounter.elapsedSeconds() > 2000000)
    {
        bMelodyFinished = false;//allow 2 seconds to answer the test?
        printf("\nTIME UP\n");
        melodyCounter.reset();
        trial_time_counter.reset();
    }
    
    if(greyStarCounter.elapsed() > 100000)
    {
        //printf("STOP MELODY PLAYBACK\n");
        bPlayPracticeMelody = false;//reset
        bPlayGroupAMelody = false;
        bPlayGroupBMelody = false;
    }
    
    if(greyStarCounter.elapsed() >= 2999000)
    {//allow 3 seconds before reset
        printf("\nSTOP\n");
        bMelodyFinished = false;
        bGuessedWrong = false;
        bGuessedPiano = false;
        bGuessedTrumpet = false;
        showStars = false;
        pageForward = false;
        hasPressed = false;
        pageBack = false;
        currentFrame = 0;
        fadeFrame = 0;
        greyCounter = 0;
        greyCounter2 = 0;
        greyStarCounter.reset();//reset timer
        melodyCounter.reset();
        trial_time_counter.reset();
    }
}

bool ofPage::showAccelPage(int x) {//a method to allow accelarometer to display correctly
    
    if (currentPage >= 0 && showStars == true) {
        x = 1;
    } else x = 0;
    
    return x;
}

void ofPage::draw(){
  
    ofBackground(255, 255, 255);
    
    if(currentPage == -3)//add user ID input etc..
    {
    }
    
    if(currentPage == -2)//add group as AB or BA
    {
    }
    
    if(currentPage == -1)
    {
        ofEnableAlphaBlending();
        ofSetColor(255);
        //select AB - BA
        buttonSelect.draw(100,160,buttonSize,buttonSize);
        buttonSelect.draw(100,410,buttonSize,buttonSize);
        //select Session
        buttonSelect2.draw(500,160,buttonSize,buttonSize);
        buttonSelect2.draw(500,410,buttonSize,buttonSize);
        buttonSelect2.draw(750,160,buttonSize,buttonSize);
        buttonSelect2.draw(750,410,buttonSize,buttonSize);
        ofDisableAlphaBlending();
        
        ofSetColor(0, 0, 0, 255);
        franklinBook14.drawString("Please select the group.", 50, 130);
        franklinBook14.drawString("Please select the session.", 540, 130);
        buttonText.drawString("AB", 160, 260);
        buttonText.drawString("BA", 160, 520);
        
        buttonText.drawString("A1", 560, 260);
        buttonText.drawString("B1", 560, 510);
        buttonText.drawString("A2", 810, 260);
        buttonText.drawString("B2", 810, 510);
        
        if(bGroupAB)
        {
            franklinBook14.drawString("Group AB is selected!", 50, 650);
        } else if(bGroupBA)
        {
            franklinBook14.drawString("Group BA is selected!", 50, 650);
        }
        
        if(bSessionA1)
        {
            franklinBook14.drawString("Session A1 is seleced!", 540, 650);
        } else if(bSessionA2)
        {
            franklinBook14.drawString("Session A2 is selected!", 540, 650);
        } else if(bSessionB1)
        {
            franklinBook14.drawString("Session B1 is seleced!", 540, 650);
        } else if(bSessionB2)
        {
            franklinBook14.drawString("Sesssion B2 is selected!", 540, 650);
        }
    }
    
    if (currentPage == 0){
        ofEnableAlphaBlending();
        //dim page and stop interaction and music if options are on display
        if(showOptionsTab == true || showSettings == true){
            ofSetColor(255, 255, 255, 100);
        } else ofSetColor(255,255,255,255);
        bearImg.draw(0,0,1024,768);//plus 10 pixlels to line up correctly
        
        currentFrame++;
        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
    }
    
    if (currentPage == 1){
        ofEnableAlphaBlending();
        //dim page and stop interaction and music if options are on display
        if(showOptionsTab == true || showSettings == true){
            ofSetColor(255, 255, 255, 100);
        } else ofSetColor(255,255,255,255);
        
        if(bSessionA1 == true || bSessionB1 == true)
        {
            pianoImg.draw(150,350);
            trumpetImg.draw(ofGetScreenWidth()-200,350);
        } else if(bSessionA2 == true || bSessionB2)
        {
            trumpetImg.draw(150,350);
            pianoImg.draw(ofGetScreenWidth()-200,350);
        }
        
        currentFrame++;
        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
    }
    
    if (currentPage >= 2 && currentPage < 24){// && guessedWrong == false && guessedPiano == false && guessedTrumpet == false){
        ofEnableAlphaBlending();
        //dim page and stop interaction and music if options are on display
        if(showOptionsTab == true || showSettings == true){
            ofSetColor(255, 255, 255, 100);
        } else ofSetColor(255,255,255,255);
        //pianoImg.draw(0,0,1024,768);
        //trumpetImg.draw(0,0,1024,768);
        bearImg.draw(10,0,1024,768);//plus 10 pixlels to line up correctly
        if(bSessionA1 == true || bSessionB1 == true)
        {
            pianoImg.draw(55,410);
            trumpetImg.draw(ofGetScreenWidth()-380,410);
        } else if(bSessionA2 == true || bSessionB2)
        {
            trumpetImg.draw(55,410);;
            pianoImg.draw(ofGetScreenWidth()-380,410);
        }
        currentFrame++;
        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
    }
    
    
    if (currentPage == 24){
        ofEnableAlphaBlending();
        //dim page and stop interaction and music if options are on display
        if(showOptionsTab == true || showSettings == true){
            ofSetColor(255, 255, 255, 100);
        } else ofSetColor(255,255,255,255);
        bearImg.draw(10,0,1024,768);//plus 10 pixlels to line up correctly
        ofSetColor(0, 0, 0, 255);
        franklinBook14.drawString("Well Done! 20 Tunes are now completed!\n\n\n\n\n\nAll the data is stored. \n\nPlease exit the app now. ", 50, 130);
        currentFrame++;
        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
    }

    if(howTo == true){
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, 255);
        //howToPage.draw(0,0,1024,768);
        ofDisableAlphaBlending();
        
    }
    
    if (currentPage >= -1 && currentPage < 24){
        
       float timer = ofGetElapsedTimeMillis() - startTime;
        
       if(showStars == true && bMelodyFinished){//only permit after melody finished
           bGuessedWrong = false;
           greyStarCounter.start();
           //printf("greyStarCounter is : ""%lld\n",greyStarCounter.elapsed());
       }
        
       if (bGuessedWrong == true && bMelodyFinished) {
            showStars = false;
            greyStarCounter.start();//start timer
            ofSetColor(255);
            if (greyStarCounter.elapsed() < 500000){
                star1a.draw(ofGetWidth()/2-100,ofGetHeight()/2 -300);
                star1b.draw(ofGetWidth()/2-100,ofGetHeight()/2-300);
                star1c.draw(ofGetWidth()/2-100,ofGetHeight()/2-300);
                star2a.draw(ofGetWidth()/2-400,ofGetHeight()/2-300);
                star2b.draw(ofGetWidth()/2-400,ofGetHeight()/2-300);
                star2c.draw(ofGetWidth()/2-400,ofGetHeight()/2-300);
                star3a.draw(ofGetWidth()/2,ofGetHeight()/2-300);
                star3b.draw(ofGetWidth()/2,ofGetHeight()/2-300);
                star3c.draw(ofGetWidth()/2,ofGetHeight()/2-300);
                star4a.draw(ofGetWidth()/2-300,ofGetHeight()/2-400);
                star4b.draw(ofGetWidth()/2-300,ofGetHeight()/2-400);
                star4c.draw(ofGetWidth()/2-300,ofGetHeight()/2-400);
            }
            
            else if (greyStarCounter.elapsed() > 500000 && greyStarCounter.elapsed() <= 1000000){//explode stars
                greyCounter++;
                star1a.draw(ofGetWidth()/2-100,ofGetHeight()/2-300-greyCounter);
                star1b.draw(ofGetWidth()/2-100+greyCounter,ofGetHeight()/2-300);
                star1c.draw(ofGetWidth()/2-100-greyCounter,ofGetHeight()/2-300);
                star2a.draw(ofGetWidth()/2-400-greyCounter,ofGetHeight()/2-300);
                star2b.draw(ofGetWidth()/2-400,ofGetHeight()/2-300+greyCounter);
                star2c.draw(ofGetWidth()/2-400+greyCounter,ofGetHeight()/2-300);
                star3a.draw(ofGetWidth()/2+greyCounter,ofGetHeight()/2-300);
                star3b.draw(ofGetWidth()/2-greyCounter,ofGetHeight()/2-300);
                star3c.draw(ofGetWidth()/2,ofGetHeight()/2-300-greyCounter);
                star4a.draw(ofGetWidth()/2-300,ofGetHeight()/2-400-greyCounter);
                star4b.draw(ofGetWidth()/2-300-greyCounter,ofGetHeight()/2-400);
                star4c.draw(ofGetWidth()/2-300+greyCounter,ofGetHeight()/2-400);
                
            }
            
           if(greyStarCounter.elapsed() > 1000000){//allow fall to start early
                //printf("POSITION CHANGE IS NOW....:");
                greyCounter2+=4;
                //int rot = 20;
                //ofRotateZ(rot);
                star1a.draw((ofGetWidth()/2-100),ofGetHeight()/2-300-34+greyCounter2*1);
                star1b.draw(ofGetWidth()/2-100+33,ofGetHeight()/2-300+greyCounter2*1.9);
                star1c.draw(ofGetWidth()/2-100-33,ofGetHeight()/2-300+greyCounter2*1.3);
                star2a.draw(ofGetWidth()/2-400-33,ofGetHeight()/2-300+greyCounter2*1.6);
                star2b.draw(ofGetWidth()/2-400,ofGetHeight()/2-300+32+greyCounter2*1.5);
                star2c.draw(ofGetWidth()/2-400+33,ofGetHeight()/2-300+greyCounter2*1.21);
                star3a.draw(ofGetWidth()/2+33,ofGetHeight()/2-300+greyCounter2*1,13);
                star3b.draw(ofGetWidth()/2-33,ofGetHeight()/2-300+greyCounter2*1.23);
                star3c.draw(ofGetWidth()/2,ofGetHeight()/2-300-34+greyCounter2*1.96);
                star4a.draw(ofGetWidth()/2-300,ofGetHeight()/2-400-34+greyCounter2*1.3);
                star4b.draw(ofGetWidth()/2-300-33,ofGetHeight()/2-400+greyCounter2*1.8);
                star4c.draw(ofGetWidth()/2-300+33,ofGetHeight()/2-400+greyCounter2*1.7);
                
            }
            
            if(greyStarCounter.elapsed() > 3000000){
                bGuessedWrong = false;
            }
            
            //printf("fade counter is: ""%d\n",greyCounter);
            //printf("greyStarCounter is : ""%lld\n",greyStarCounter.elapsed());
           
        }
        
        // some information about the timer
        string  info  = "FPS:    "+ofToString(ofGetFrameRate(),0)+"\n";
        info += "Timer:"+ofToString(timer/1000.0, 1)+" seconds\n";
        ofSetColor(0);
        //ofDrawBitmapString(info, ofGetScreenWidth()-200, 20);
        
        //playPage.draw(0,0,1024,768);
        fadePage = true;
        
        //show the dots and question mark
        if(showDots == true && bResetMelody == false){
            ofSetColor(0, 0, 0, 200);
            float dotTimer = ((ofGetElapsedTimeMillis() - startDotTime));
            // some information about the timer
            if(dotTimer >= 0 && dotTimer < 3000){
                dotsText.drawString(".", 50, 350);
            }
            if(dotTimer >= 454.00 && dotTimer < 3000){
                dotsText.drawString(".", 150, 350);
            }
            if(dotTimer >= 1004.00 && dotTimer < 3000){
                dotsText.drawString(".", 250, 350);
            }
            if(dotTimer >= 1470.00 && dotTimer < 3000){
                dotsText.drawString(".", 350, 350);
            }
            if(dotTimer >= 2004.00 && dotTimer < 3000){
                dotsText.drawString("?", 450, 350);
            }
            //printf("Fade Time is:  ""%f\n",dotTimer);
           // printf("StartTime is:  ""%f\n",startTime);
            
            if(currentPage == 5){
                //float startPress = ((ofGetElapsedTimeMillis() - startDotTime));
                if(bGuessedWrong){
                    float guessTime = ((ofGetElapsedTimeMillis() - startDotTime));
                    float trial1Time = (dotTimer - guessTime);
                    printf("Trial 1 Time was:  ""%f\n",trial1Time);
                }

            }
        }
        
        //method to allow pressing back of home button top left users requested this.
        if(showOptionsTab == true){
            float delayTime = 0;
            delayTime = currentFrame*secondTime*fadeUpTime;
            if(delayTime > 200){
                homeButtonBack = true;
                delayTime = 0;
                printf("%f\n",delayTime);
            }
        }
        
        
        if(currentFrame >= secondTime*2){//&& currentFrame < secondTime*2){
            float go1 = 0;
            //float startFade = secondTime/20;
            //currentFrame = 0;
            go1 = (currentFrame-secondTime*2)*secondTime*fadeUpTime;
            
            if (go1 > 150) {
                go1 = 150;
            }
            //printf("%.1f\n", go1);
            
            //printf("%d\n",currentPage);
            ofEnableAlphaBlending();
            
            //dim page and stop interaction and music if options are on display
            if(showOptionsTab == true || showSettings == true){
                ofSetColor(255, 255, 255, 100);
                //allow homeButon to send user back to playMode
                ofEnableAlphaBlending();
                ofSetColor(255, 255, 255, 150);
                homeButton.draw(sin(ofGetElapsedTimeMillis()/100.0f) * 1 + 20, 20 + sin(ofGetElapsedTimeMillis()/100.0f));
                ofDisableAlphaBlending();
                
            } else ofSetColor(255, 255, 255, go1);
            ofEnableAlphaBlending();
            homeButton.draw(20,20);
            
            if(currentPage <25){//show right arrow up till last book page then allow home key to move on final page.
                rightArrow.draw(938,710);
            }
            
            if(currentPage >= 0){//only show left arrow from page 0
                leftArrow.draw(10,710);
            }
            
            ofDisableAlphaBlending();
        }
    }
    
    else if (showCredits == true){
        
        if(currentFrame >= 0){
            
            float go2 = 0;
            go2 = currentFrame*secondTime*fadeUpTime;
            
            if (go2 > 150) {
                go2 = 150;
            }
            //printf("%.1f\n", go2);
            
            ofSetColor(255,255,255,255);
            //credits.draw(0,0,1024,768);
            ofEnableAlphaBlending();
            ofSetColor(255, 255, 255, go2);
            homeButton.draw(sin(ofGetElapsedTimeMillis()/100.0f) * 1 + 20, 20 + sin(ofGetElapsedTimeMillis()/100.0f));
            ofDisableAlphaBlending();
            
            
        } else if(showCredits == false){
            ofSetColor(255, 255, 255, 255);
        }
        
    }
    
    
    //set up for the options tab
    if (showOptionsTab == true) {
        
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, 255);//reset page to stop bleed from previous page
        optionsTab.draw(311,56);
        returnArrow.draw(sin(ofGetElapsedTimeMillis()/105.0f) * 1+573, 232+sin(ofGetElapsedTimeMillis()/105.0f));
        homeButton.draw(sin(ofGetElapsedTimeMillis()/101.0f) * 1+574, 334+sin(ofGetElapsedTimeMillis()/101.0f));
        
        ofDisableAlphaBlending();
    }
    
    //set up for the settings tab
    if (showSettings == true) {
        
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, 255);//reset page to stop bleed from previous page
        settingsPage.draw(311,56);
        //optionsTab.draw(0,0,1024,768);
        returnArrow.draw(sin(ofGetElapsedTimeMillis()/105.0f) * 1+573, 132 + sin(ofGetElapsedTimeMillis()/105.0f));
        
        ofDisableAlphaBlending();
    }
    
    if (howTo == true || currentPage == 24){
        fadePage = false;
        showCredits = false;
        float go3 = 0;
        go3 = currentFrame*secondTime*fadeUpTime;
        
        if (go3 > 150) {
            go3 = 150;
        }
        //printf("%.1f\n", go2);
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, go3);
        homeButton.draw(sin(ofGetElapsedTimeMillis()/100.0f) * 1 + 20, 20 + sin(ofGetElapsedTimeMillis()/100.0f));
        ofDisableAlphaBlending();
        
    }
    
    if(currentPage == 24){
        float go3 = 0;
        go3 = currentFrame*secondTime*fadeUpTime;
        
        if (go3 > 150) {
            go3 = 150;
        }
        //printf("%.1f\n", go2);
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, go3);
        homeButton.draw(sin(ofGetElapsedTimeMillis()/100.0f) * 1 + 20, 20 + sin(ofGetElapsedTimeMillis()/100.0f));
        ofDisableAlphaBlending();
    }
    
    //update a star to display where needs pressing
    ofEnableAlphaBlending();
    float go = fadeFrame*secondTime*fadeUpTime;
    if (go > 180) {
        go = go*-1 + 360;//make the dot fade up and down
        if(go == 0){
            fadeFrame = 0;
        }
    }
    
    //dim page and stop interaction and music if options are on display
    if(showOptionsTab == true || showSettings == true){
        ofSetColor(255, 255, 255, 100);
    } else ofSetColor(255, 255, 255, go);
    
    //All text for pages displays here
    if(currentPage == 0 && bGuessedWrong == false && bGuessedPiano == false && bGuessedTrumpet == false){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("This is Giles the Bear! \n\n\n\nHe can't hear very well. \n\n\n\nCan you help him hear \n\nwhat the music is? ", 120, 200);
    }
    
    if(currentPage == 1){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Press the Piano! \n\nWhat do you hear?. \n\n\n\nNow press the trumpet.\n\nCan you hear it is different? ", 120, 150);
    }
    
    if(currentPage == 2 && bGuessedWrong == false && bGuessedPiano == false && bGuessedTrumpet == false && single_count == 0){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Now we are going to hear a sound, \n\neither a piano or a trumpet.\n\n\n\nAs soon as you hear what the \n\nsound is, press the correct image \n\nwith your finger as fast as you can!\n\n\n\nPress Giles's ear to hear the sound!", 100, 70);
    }
    
    //cout<< hasPressed << endl;
    
    if(currentPage == 2 && bShowSingleNoteText == true){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Press Giles's ear to hear another \n\nnote!\n\n\n\nOr press the right arrow to move \n\non.", 100, 170);
    }
    
    if(currentPage == 3 && bGuessedWrong == false && bGuessedPiano == false && bGuessedTrumpet == false && practice_count == -1){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Now we are going to hear a song. \n\n\n\nThe last sound will be either a \n\ntrumpet or a piano.\n\n\n\nAs soon as you hear what the sound\n\nis, press the correct image with \n\nyour finger as fast as you can!\n\n\n\nPress Giles's ear to hear the tune!", 100, 70);
        
    } else if(currentPage == 3 && practice_count == 3){//edit to 2 for final APP TODO ?
        if(bPlayPracticeMelody == false){
            ofSetColor(0, 0, 0);
            franklinBook14.drawString("Press on the right arrow to move \n\non to the trials.", 100, 200);
        }
    }
    
    if(currentPage == 3 && practice_count >= 0 && practice_count < 3){
        if(bPlayPracticeMelody == false){
            ofSetColor(0, 0, 0);
            franklinBook14.drawString("Press Giles's ear to hear another\n\npractice melody!\n\n\n\nOr press on the right arrow to move \n\non to the trials.", 100, 170);
        }
    }
    
    if(currentPage == 3 && practice_count == 0) {
        ofSetColor(0, 0, 0);
        trials.drawString("Practice 1", trialXpos, 50);//Trial no data kept
    }
    
    if(currentPage == 3 && practice_count == 1) {
        ofSetColor(0, 0, 0);
        trials.drawString("Practice 2", trialXpos, 50);//Trial no data kept
    }
    
    if(currentPage == 3 && practice_count == 2) {
        ofSetColor(0, 0, 0);
        trials.drawString("Practice 3", trialXpos, 50);//Trial no data kept
    }
    
    if(currentPage == 3 && practice_count == 3) {
        ofSetColor(0, 0, 0);
        trials.drawString("Practice 4", trialXpos, 50);//Trial no data kept
    }
    
    if(currentPage == 4 && showDots == false){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Are you ready to start?\n\n\n\nAs soon as you hear what the sound\n\nis, press the correct image with your \n\nfinger as fast as you can!\n\n\n\nPress Giles's ear to hear the tune!", 100, 70);
    }
    
    if(currentPage >= 4 && currentPage < 23 && bShowTrialText == true){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Press Giles's ear to hear the trial \n\nmelody again!\n\n\n\nOr press the right arrow to move \n\non to the next melody.", 100, 170);
    }
    
    if(currentPage == 23 && bShowTrialText == true){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Press Giles's ear to hear the trial \n\nmelody again!\n\n\n\nOr press the right arrow to move \n\nto the finish!", 100, 170);
    }
    
    if(currentPage >= 4){
        
        //cout<< showRedDot << endl;
        //ofSetColor(255, 255, 120);
        ofEnableSmoothing();
        if(showGreenDot == true){
            showRedDot = false;
            ofSetColor(0, 255, 0, 150);
            ofEllipse(840, 45, 50, 50);
        }
        if(showRedDot == true){
            showGreenDot = false;
            ofSetColor(255, 0, 0, 150);
            ofEllipse(840, 45, 50, 50);
            //greenButton.draw(840, 50, 50, 50);
        }
    
        ofSetColor(0, 0, 0);
            switch(currentPage){
                case 4  :
                    trials.drawString("Trial 1", trialXpos, 50);//Trial no data kept
                    break;
                case 5  :
                    trials.drawString("Trial 2", trialXpos, 50);//Trial no data kept
                    break;
                case 6  :
                    trials.drawString("Trial 3", trialXpos, trialYpos);
                    break;
                case 7  :
                    trials.drawString("Trial 4", trialXpos, trialYpos);
                    break;
                case 8  :
                    trials.drawString("Trial 5", trialXpos, trialYpos);
                    break;
                case 9  :
                    trials.drawString("Trial 6", trialXpos, trialYpos);
                    break;
                case 10  :
                    trials.drawString("Trial 7", trialXpos, trialYpos);
                    break;
                case 11  :
                    trials.drawString("Trial 8", trialXpos, trialYpos);
                    break;
                case 12  :
                    trials.drawString("Trial 9", trialXpos, trialYpos);
                    break;
                case 13  :
                    trials.drawString("Trial 10", trialXpos, trialYpos);
                    break;
                case 14  :
                    trials.drawString("Trial 11", trialXpos, trialYpos);
                    break;
                case 15  :
                    trials.drawString("Trial 12", trialXpos, trialYpos);
                    break;
                case 16  :
                    trials.drawString("Trial 13", trialXpos, trialYpos);
                    break;
                case 17  :
                    trials.drawString("Trial 14", trialXpos, trialYpos);
                    break;
                case 18  :
                    trials.drawString("Trial 15", trialXpos, trialYpos);
                    break;
                case 19  :
                    trials.drawString("Trial 16", trialXpos, trialYpos);
                    break;
                case 20  :
                    trials.drawString("Trial 17", trialXpos, trialYpos);
                    break;
                case 21  :
                    trials.drawString("Trial 18", trialXpos, trialYpos);
                    break;
                case 22  :
                    trials.drawString("Trial 19", trialXpos, trialYpos);
                    break;
                case 23  :
                    trials.drawString("Trial 20", trialXpos, trialYpos);
                    break;
            }
    }
    //currentFrame++;//counter keeps the timing of the book
    //fadeFrame ++;//all animation fades
    //printf("Page number is:  ""%d\n",currentPage);
}

void ofPage::touchPressed(int x, int y){//this is overidden in subclasses
    
}

void ofPage::showPage(int x, int y){
    
    if(currentPage == -1)
    {
        //set up for slecting the group AB or BA
        int AB_x1 = 90;
        int AB_y1 = 160;
        int AB_x2 = 274;
        int AB_y2 = 350;
        
        int BA_x1 = 90;
        int BA_y1 = 400;
        int BA_x2 = 274;
        int BA_y2 = 590;
        
        //set up for slecting session A1, A2, B1, B2
        int A1_x1 = 500;
        int A1_y1 = 160;
        int A1_x2 = 674;
        int A1_y2 = 350;
        
        int A2_x1 = 770;
        int A2_y1 = 160;
        int A2_x2 = 925;
        int A2_y2 = 350;
       
        int B1_x1 = 500;
        int B1_y1 = 400;
        int B1_x2 = 674;
        int B1_y2 = 600;
    
        int B2_x1 = 770;
        int B2_y1 = 400;
        int B2_x2 = 925;
        int B2_y2 = 600;
        
        //GROUP SELECTION
        if (x > AB_x1 && y > AB_y1 && x < AB_x2 && y < AB_y2)
        {
            bGroupAB = true;
            bGroupBA = false;
            cout << "\nAB GROUP SELECTED " << endl;
        }
        if (x > BA_x1 && y > BA_y1 && x < BA_x2 && y < BA_y2)
        {
            bGroupAB = false;
            bGroupBA = true;
            cout << "\nBA GROUP SELECTED " << endl;
        }
        //SESSION NUMBER
        if (x > A1_x1 && y > A1_y1 && x < A1_x2 && y < A1_y2)
        {
            bSessionA1 = true;
            bSessionA2 = false;
            bSessionB1 = false;
            bSessionB2 = false;
//            bPlayGroupAMelody = true;
//            bPlayGroupBMelody = false;
            cout << "\nA1 Session  " << endl;
        }
        if (x > A2_x1 && y > A2_y1 && x < A2_x2 && y < A2_y2)
        {
            bSessionA1 = false;
            bSessionA2 = true;
            bSessionB1 = false;
            bSessionB2 = false;
//            bPlayGroupAMelody = true;
//            bPlayGroupBMelody = false;
            cout << "\nA2 Session  " << endl;
        }
        if (x > B1_x1 && y > B1_y1 && x < B1_x2 && y < B1_y2)
        {
            bSessionA1 = false;
            bSessionA2 = false;
            bSessionB1 = true;
            bSessionB2 = false;
//            bPlayGroupBMelody = true;
//            bPlayGroupAMelody = false;
            cout << "\nB1 Session  " << endl;
        }
        if (x > B2_x1 && y > B2_y1 && x < B2_x2 && y < B2_y2)
        {
            bSessionA1 = false;
            bSessionA2 = false;
            bSessionB1 = false;
            bSessionB2 = true;
//            bPlayGroupBMelody = true;
//            bPlayGroupAMelody = false;
            cout << "\nB2 Session  " << endl;
        }
    }
    
    //set up page presses for all main book pages
    if (currentPage >= -1 && currentPage < 25) {//constrain the main book page presses
        if(greyStarCounter.elapsed() >= 2900000){
            showStars = false;
            bGuessedWrong = false;
            bGuessedPiano = false;
            bGuessedTrumpet = false;
            hasPressed = false;
            currentFrame = 0;
            fadeFrame = 0;
            greyStarCounter.reset();//reset timer
            greyCounter = 0;
            greyCounter2 = 0;
        }
        if(showOptionsTab == false && stopPress == false){
            //code for basic arrow function
            int pageForwardX = 960;
            int pageForwardY = 708;
            int pageBackwardX = 60;
            int pageBackwardY = 708;
            
//            if (currentPage > 3 && currentPage < 24 && x >= pageForwardX && y > pageForwardY )
//            {
//                //trial_melody_count++;//increment up 1 every page
//                printf("%d\n",currentPage);
//            }
            if(currentPage >= 4 && currentPage < 24 && x >= pageForwardX && y > pageForwardY)
            {
                showRedDot = true;
                showGreenDot = false;
            }
            if(currentPage >= 4 && x <= pageBackwardX && y > pageBackwardY){
                showRedDot = true;
                showGreenDot = false;
            }

                
            if (currentPage >= -1 && currentPage < 24 && x >= pageForwardX && y > pageForwardY )
            {
                pageForward = true;//allows correct files to load or unload
                showStars = false;
                bGuessedWrong = false;
                bGuessedPiano = false;
                bGuessedTrumpet = false;
                hasPressed = false;
                pageBack = false;
                currentPage ++;
                currentFrame = 0;
                fadeFrame = 0;
                greyStarCounter.reset();//reset timer
                greyCounter = 0;
                greyCounter2 = 0;
                bPlayGroupBMelody = false;
                bPlayGroupAMelody = false;
                showDots = false;
                bShowTrialText = false;
                bShowSingleNoteText = false;

                printf("%d\n",currentPage);
                //printf("%d\n",pageForward);
                //printf("%d\n",pageBack);
                
            } else if (currentPage > -1 && x <= pageBackwardX && y > pageBackwardY){
                pageBack = true;//allows correct files to load or unload
                showStars = false;
                bGuessedWrong = false;
                bGuessedPiano = false;
                bGuessedTrumpet = false;
                pageForward = false;
                hasPressed = false;
                currentPage --;
                currentFrame = 0;
                fadeFrame = 0;
                //reset text on each page turn
                textshow = true;
                texthide = false;
                greyStarCounter.reset();//reset timer
                greyCounter = 0;
                greyCounter2 = 0;
                bPlayGroupBMelody = false;
                bPlayGroupAMelody = false;
                showDots = false;
                bShowTrialText = false;
                bShowSingleNoteText = false;
                
                printf("Page number is:  ""%d\n",currentPage);
                //printf("%d\n",pageForward);
                //printf("%d\n",pageBack);
                
            }
            
            //press functions for the homing button within main book
            int homeButtonX1 = 0;
            int homeButtonX2 = 65;
            int homeButtonY1 = 0;
            int homeButtonY2 = 75;
            
            if (x > homeButtonX1 && x < homeButtonX2
                && y > homeButtonY1 && y < homeButtonY2 && currentPage > 0){//need to allow for home key back from credits
                showOptionsTab = true;
                showSettings = false;
                showCredits = false;
            }
            
            //options tab functionsality watch out for page touches underneath this tab?
            
        } else if (showOptionsTab == true) {
            
            int resumeX1 = 580;
            int resumeX2 = 640;
            int resumeY1 = 230;
            int resumeY2 = 300;
            
            int restartX1 = 580;
            int restartX2 = 640;
            int restartY1 = 360;
            int restartY2 = 385;
            
            int howtoX1 = 580;
            int howtoX2 = 640;
            int howtoY1 = 400;
            int howtoY2 = 475;
            
            int settingsX1 = 580;
            int settingsX2 = 640;
            int settingsY1 = 500;
            int settingsY2 = 598;
            
            //to return using home button(Users wanted this to be in)
            int homeButtonBackX1 = 0;
            int homeButtonBackX2 = 65;
            int homeButtonBackY1 = 0;
            int homeButtonBackY2 = 75;
            
            
            if (x > resumeX1 && x < resumeX2
                && y > resumeY1 && y < resumeY2){//make sure options tab remains when clicking
                showOptionsTab = false;
                howTo = false;
                
                //touch functionality to allow homeButton to restart page and music/barration
            } else if (x > homeButtonBackX1 && x < homeButtonBackX2
                       && y > homeButtonBackY1 && y < homeButtonBackY2 && homeButtonBack == true){
                homeButtonBack = false;
                showOptionsTab = false;
                showSettings = false;
                howTo = false;
                pressBackHome = true; //try this out tomorrow???
                
            } else if (x > restartX1 && x < restartX2
                       && y > restartY1 && y < restartY2 ){
                currentPage = 0;
                showOptionsTab = false;
                howTo = false;
                
            } else if (x > howtoX1 && x < howtoX2
                       && y > howtoY1 && y < howtoY2 ){
                //currentPage = 26;
                howTo = true;
                showOptionsTab = false;
            } else if (x > settingsX1 && x < settingsX2
                       && y > settingsY1 && y < settingsY2 ){
                //currentPage = 26;
                howTo = false;
                showOptionsTab = false;
                showSettings = true;
            }
        }
    }
    //if howToPage is active allow sound to be switched off
    //see how to navigate the app
    if (howTo == true) {
        
        if(showOptionsTab == false || currentPage == -1){
            
            int homeButtonX1 = 0;
            int homeButtonX2 = 65;
            int homeButtonY1 = 0;
            int homeButtonY2 = 75;
            
            if (x > homeButtonX1 && x < homeButtonX2
                && y > homeButtonY1 && y < homeButtonY2 ){
                howTo = false;
            }
        }
    }
    
    
    if(currentPage == 27){
        //press functions for the homing button from credits page
        int homeButtonX1 = 0;
        int homeButtonX2 = 65;
        int homeButtonY1 = 0;
        int homeButtonY2 = 75;
        
        if (x > homeButtonX1 && x < homeButtonX2
            && y > homeButtonY1 && y < homeButtonY2 ){
            currentPage = 0;
            showCredits = true;

        }
    }
    
    if(currentPage == 0){
        playTrumpetMelody = false;
        playPianoMelody = false;
        playTrumpetSingle = false;
        playPianoSingle = false;
    }
    
    /******** ASSOCIATE SINGLE TONES  *******/
    if (currentPage == 1) {
        single_count = 0;//reset to show text if needed
        practice_count = -1;//reset counter for 0 index
        bPlayPracticeMelody = false;
        playTrumpetMelody = false;
        playPianoMelody = false;
        
        if (x > 130 && x < 480 && y < 650 && y > 320){
            if((bSessionA1) || (bSessionB1))
            {
                playPianoSingle = true;
                playTrumpetSingle = false;
            } else if((bSessionA2) || (bSessionB2))
            {
                playPianoSingle = false;
                playTrumpetSingle = true;
            }
        }
        
        if (x > 570 && x < 890 && y < 650 && y > 320){
            if((bSessionA1) || (bSessionB1))
            {
                playPianoSingle = false;
                playTrumpetSingle = true;
            } else if((bSessionA2) || (bSessionB2))
            {
                playPianoSingle = true;
                playTrumpetSingle = false;
            }
        }
    }
    
    /******** SINGLE NOTE HEAR AND PRESS BEGIN HERE *******/
    if (currentPage == 2) {
        practice_count = -1;//reset counter for 0 index on page 3
//        cout << "Piano note is now playing " << playPianoSingle << endl;
//        cout << "Trumpet note is now playing " << playTrumpetSingle << endl;
        
        if (x > 780 && y < 290 && y > 0){//press bear to start single note
            single_count ++;
            bShowSingleNoteText = false;

            
            if(single_count > 4){
                single_count = 1;//reset the counter
            }
        
            greyStarCounter.reset();//reset timers
            melodyCounter.reset();
            trial_time_counter.reset();
            showStars = false;
            hasPressed = false;
            bGuessedWrong = false;
            showDots = false;
            bMelodyFinished = true;//stops a bug so answer can be given quicky (length of melody)
    
            cout << "\nSingle Note Counter = " << single_count << endl;
        
            if(single_count == 1 ||  single_count == 3){
                playPianoSingle = true;//play first piano note
                playTrumpetSingle = false;
                //allow longer to press the corect note
                //practice note association
                pianoNote = true;
                trumpetNote = false;
                
                printf("\nPiano Single\n");
            } else if(single_count == 2 || single_count == 4){
                playTrumpetSingle = true;
                playPianoSingle = false;
                //practice note association
                pianoNote = false;
                trumpetNote = true;
                printf("\nTrumpet Single \n");
            }
        }
        
        //PIANO LEFT
        if (x > 55 && x < 360 && y < 690 && y > 435 && pianoNote == true && hasPressed == false)
        {
            if(bSessionA1 == true || bSessionB1 == true)
            {
                bGuessedPiano = true;
                hasPressed = true;
                bShowSingleNoteText = true;
                printf("\nGUESS PIANO LEFT");
                showStars = true;//show stars!
                printf("\nWELLDONE\n");
            }
        }
        //PIANO LEFT
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && pianoNote == true && hasPressed == false)
        {
            if(bSessionA1 == true || bSessionB1 == true)
            {
                bGuessedWrong = true;
                hasPressed = true;
                bShowSingleNoteText = true;
                showStars = false;
                printf("\nWRONG IT WAS PIANO");
            }
        }
        //PIANO LEFT
        if (x > 55 && x < 360 && y < 690 && y > 435 && trumpetNote == true && hasPressed == false)
        {
            if(bSessionA1 == true || bSessionB1 == true)
            {
                bGuessedWrong = true;
                hasPressed = true;
                bShowSingleNoteText = true;
                showStars = false;
                printf("\nWRONG IT WAS TRUMPET");
            }
        }
        //PIANO LEFT=
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && trumpetNote == true)
        {
            if(bSessionA1 == true || bSessionB1 == true)
            {
                bGuessedTrumpet = true;
                hasPressed = true;
                bShowSingleNoteText = true;
                printf("\nGUESS TRUMPET RIGHT\n");
                showStars = true;//show stars!
                printf("\nWELL DONE\n");
            }
        }
        //Piano RIGHT!!
        if (x > 55 && x < 360 && y < 690 && y > 435 && pianoNote == true && hasPressed == false)
        {
            if(bSessionA2 == true || bSessionB2 == true)
            {
                bGuessedWrong = true;
                hasPressed = true;
                bShowSingleNoteText = true;
                showStars = false;
                printf("\nWRONG IT WAS PIANO\n");
            }
        }
        //Piano RIght
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && pianoNote == true && hasPressed == false)
        {
            if((bSessionA2) || (bSessionB2))
            {
                bGuessedPiano = true;
                hasPressed = true;
                bShowSingleNoteText = true;
                printf("\nGUESS PIANO LEFT\n");
                showStars = true;//show stars!
                printf("\nWELLDONE\n");
                
            }
        }
        //PIANO RIGHT
        if (x > 55 && x < 360 && y < 690 && y > 435 && trumpetNote == true && hasPressed == false)
        {
            if((bSessionA2) || (bSessionB2))
            {
                bGuessedTrumpet = true;
                hasPressed = true;
                bShowSingleNoteText = true;
                printf("\nGUESS TRUMPET RIGHT\n");
                showStars = true;//show stars!
                printf("\nWELLDONE\n");
            }
        }
        //PIANO RIGHT
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && trumpetNote == true && hasPressed == false)
        {
            if((bSessionA2) || (bSessionB2))
            {
                bGuessedWrong = true;
                hasPressed = true;
                bShowSingleNoteText = true;
                showStars = false;
                printf("\nWRONG IT WAS TRUMPET\n");
                
            }
        }
    }
    
    /******** PRACTICE TRIALS x 4 *******/
    
    if (currentPage == 3)
    {
        single_count = 0;//reset incase we want to see text on page 2 again.
        playTrumpetSingle = false;
        playPianoSingle = false;
        trial_melody_count = -1;//0 index ready for trials
        
        if (x > 780 && y < 290 && y > 0){//press bear to start melody
            practice_count ++;
            if (practice_count > 3)
            {
                practice_count = 0;
            }
            greyStarCounter.reset();//reset timers
            melodyCounter.reset();
            trial_time_counter.reset();
            bMelodyStart = true;
            showStars = false;
            hasPressed = false;
            bGuessedWrong = false;
            showDots = true;
            startDotTime = ofGetElapsedTimeMillis();  // get the start time
            bPlayPracticeMelody = true;//start the test melody
          
            cout << "\nMelodyCounter = " << practice_count << endl;
            //cout << testMelodyNumber[0] << endl;
            int tempMel = practice_melody_v[practice_count];
        
            cout << "\nPractice Melody = " << tempMel << endl;
            
            if(tempMel == 0 || tempMel == 2 ){
                playPianoMelody = true;//play first piano melody
                playTrumpetMelody = false;
                printf("\nPianoMelody\n");
            } else if(tempMel == 1 || tempMel == 3){
                playTrumpetMelody = true;
                playPianoMelody = false;
                printf("\nTrumpetMelody\n");
            }

        }
        
        if (bMelodyFinished && bMelodyStart == false)
        {
            //PIANO LEFT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedPiano = true;
                    hasPressed = true;
                    printf("\nGUESS PIANO LEFT");
                    showStars = true;//show stars!
                    printf("\nWELLDONE");
                }
            }
            //PIANO LEFT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    showStars = false;
                    printf("\nWRONG IT WAS PIANO");
                }
            }
            //PIANO LEFT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    showStars = false;
                    printf("\nWRONG IT WAS TRUMPET");
                }
            }
            //PIANO LEFT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedTrumpet = true;
                    hasPressed = true;
                    printf("\nGUESS TRUMPET RIGHT");
                    showStars = true;//show stars!
                    printf("\nWELLDONE");
                }
            }
            //Piano RIGHT!!
            if (x > 55 && x < 360 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA2 == true || bSessionB2 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    showStars = false;
                    printf("\nWRONG IT WAS PIANO");
                }
            }
            //Piano RIght
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedPiano = true;
                    hasPressed = true;
                    printf("\nGUESS PIANO LEFT");
                    showStars = true;//show stars!
                    printf("\nWELLDONE");
                    
                }
            }
            //PIANO RIGHT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedTrumpet = true;
                    hasPressed = true;
                    printf("\nGUESS TRUMPET RIGHT");
                    showStars = true;//show stars!
                    printf("\nWELLDONE");
                }
            }
            //PIANO RIGHT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    showStars = false;
                    printf("\nWRONG IT WAS TRUMPET");
                    
                }
            }
        }
    }
    
    /******** TRIALS BEGIN HERE *******/
    if (currentPage >= 4 && currentPage < 24) {//TODO trial 1 - 20
        bPlayPracticeMelody = false;
        practice_count = -1;//reset counter for 0 index
        trial_melody_count = (currentPage - 4);
        cout << "\nTrial Melody Counter = " << trial_melody_count << endl;
        if (trial_melody_count > 20) {
            trial_melody_count = 20;
        }

        //press bear head to sound.. or trial number to sound
        if (x > 780 && y < 290 && y > 0 && hasPressed == false)
        {
            greyStarCounter.reset();//reset timers
            melodyCounter.reset();
            trial_time_counter.reset();
            bMelodyStart = true;
            hasPressed = false;
            bGuessedWrong = false;
            showStars = false;
            showDots = true;
            showGreenDot = false;
            showRedDot = true;
            startDotTime = ofGetElapsedTimeMillis();  // get the start time
            bPlayPracticeMelody = false;
            bResetMelody = false;//must reset the melodies if child does not press
            bShowTrialText = false;
            
            //check what session
            if(bSessionA1 == true || bSessionB1 == true)
            {
                bPlayGroupAMelody = true;
                bPlayGroupBMelody = false;
            } else if(bSessionA2 == true || bSessionB2 == true)
            {
                bPlayGroupBMelody = true;
                bPlayGroupAMelody = false;
            }
            
            
        
            //melodies 1 - 20 for group A1 - A2
            if(bPlayGroupAMelody)
            {
                int tempTrialMel = trialMelody_1_v[trial_melody_count];
                cout << "\nTrial Melody index = " << tempTrialMel << endl;
                if(tempTrialMel >= 0 && tempTrialMel < 10 )
                {
                    playPianoMelody = true;
                    playTrumpetMelody = false;
                    printf("\nPianoMelody");
                } else if(tempTrialMel >= 10 && tempTrialMel < 20)                {
                    playTrumpetMelody = true;
                    playPianoMelody = false;
                    printf("\nTrumpetMelody");
                }
            }
            //melodies 1 - 20 for group B1 - B2
            else if(bPlayGroupBMelody)
            {
                int tempTrialMel = trialMelody_2_v[trial_melody_count];
                cout << "\nTrial Melody index = " << tempTrialMel << endl;
                if(tempTrialMel >= 0 && tempTrialMel < 10 )
                {
                    playPianoMelody = true;
                    playTrumpetMelody = false;
                    printf("\nPianoMelody");
                } else if(tempTrialMel >= 10 && tempTrialMel < 20)
                {
                    playTrumpetMelody = true;
                    playPianoMelody = false;
                    printf("\nTrumpetMelody");
                }
            }
        }
        
        if (bMelodyFinished && bMelodyStart == false)
        {
            //PIANO LEFT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedPiano = true;
                    hasPressed = true;
                    printf("\nGUESS PIANO LEFT");
                    showStars = true;//show stars!
                    showGreenDot = true;
                    printf("\nWELLDONE");
                }
            }
            //PIANO LEFT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    showStars = false;
                    showGreenDot = true;
                    printf("\nWRONG IT WAS PIANO");
                }
            }
            //PIANO LEFT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    showStars = false;
                    showGreenDot = true;
                    printf("\nWRONG IT WAS TRUMPET");
                }
            }
            //PIANO LEFT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedTrumpet = true;
                    hasPressed = true;
                    showGreenDot = true;
                    printf("\nGUESS TRUMPET RIGHT");
                    showStars = true;//show stars!
                    printf("\nWELLDONE");
                }
            }
            //Piano RIGHT!!
            if (x > 55 && x < 360 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA2 == true || bSessionB2 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    showStars = false;
                    showGreenDot = true;
                    printf("\nWRONG IT WAS PIANO");
                }
            }
            //Piano RIght
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedPiano = true;
                    hasPressed = true;
                    showGreenDot = true;
                    printf("\nGUESS PIANO LEFT");
                    showStars = true;//show stars!
                    printf("\nWELLDONE");
                    
                }
            }
            //PIANO RIGHT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedTrumpet = true;
                    hasPressed = true;
                    showGreenDot = true;
                    printf("\nGUESS TRUMPET RIGHT");
                    showStars = true;//show stars!
                    printf("\nWELLDONE");
                }
            }
            //PIANO RIGHT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    showStars = false;
                    showGreenDot = true;
                    printf("\nWRONG IT WAS TRUMPET");
                    
                }
            }
        }
    }
}






