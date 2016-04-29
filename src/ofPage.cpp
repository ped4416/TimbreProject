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



#include "ofPage.h"
//#include "maximilian.h"
//#include <iostream>
//#include <time.h>

ofPage::ofPage(){
    
    bDebug = false;//Change to true to permit jumping to the final page of the app quickly Press top middle of screen
    
    //variables for all pages of Timbre App
    buttonSize = 180;
    practice_count = -1;//allow for 0 index
    trial_melody_count = -1;//allow for 0 index
    currentFrame = 0;
    fadeFrame = 0;
    currentPage = -3;//TODO - set user input..
    secondTime = 30;//20
    fadeUpTime = 0.05;
    current_trial_time_counter = 0;
    practice_permit_count = 0;
   
    
    //bools for page naviagation
    bPermitNextPage = true;//permit next page navigation from start
    bPermitArrayTimeStamp = false;
    fadePage = false;
    showOptionsTab = false;
    howTo = false;
    showCredits = false;
    showSettings = false;
    homeButtonBack = false;
    pressBackHome = false;
    bFinished = false;
    
    showGreenDot = false;//start as false
    showRedDot = true;//start with warning that trial must be completed
    bPermitGreenDot = false;//bool to store dots in the array
    answered_v.resize(20);//store 1 for green dot and 0 for red dot!
    for(int i = 0; i <20; i++){
        answered_v[i] = 0;//fill array with 0s
    }
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
    bPermitSecondTrial = false;

    
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
    answered_all = "";
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
    
    //setup session 1 (A1 - B1 test melodies)
    //setup random test melodies
    practiceMelody_1_v.resize(2);// only need 2 vectors now!
    for(int i = 0; i < practiceMelody_1_v.size(); i++){
        practiceMelody_1_v[i] = i;//0,1,2,3
        cout << "Session 1 Practice Test Number Is Now: "  << practiceMelody_1_v[i] <<endl;
    }
    
    std::random_shuffle (practiceMelody_1_v.begin(), practiceMelody_1_v.end());
    
    for(int i = 0; i < practiceMelody_1_v.size(); i++){
        cout << "Session 1 Practice Index Order: " << practiceMelody_1_v[i] << endl;
    }
    
    
    
    //setup session 2 (A2 - B2 test melodies)
    practiceMelody_2_v.resize(2);// only need 2 vectors now!
    for(int i = 0; i < practiceMelody_2_v.size(); i++){
        practiceMelody_2_v[i] = i;//0,1,2,3
        cout << "Session 1 Practice Test Number Is Now: "  << practiceMelody_2_v[i] <<endl;
    }
    
    std::random_shuffle (practiceMelody_2_v.begin(), practiceMelody_2_v.end());
    
    for(int i = 0; i < practiceMelody_2_v.size(); i++){
        cout << "Session 2 Practice Index Order: " << practiceMelody_2_v[i] << endl;
    }
    
    //(practice_melody_v.begin(), practice_melody_v.end());
    
//    for(int i = 0; i < practice_melody_v.size(); i++){
//        cout << practice_melody_v[i] << endl;
//    }
    
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
//    //udate green dot to permit retakes of pages easily
    for (int i = 0; i < 20; i++) {
        if(currentPage == i+4){
            if(answered_v[i] == 1){
                showGreenDot = true;
                showRedDot = false;
                //cout << "SHOW GREEN DOT!" << endl;
            } else if(answered_v[i] == 0){
                showRedDot = true;
                showGreenDot = false;
                //cout << "SHOW RED DOT!" << endl;
            }
        }
    }
    
    //cout << "PRACTICE COUNT = " << practice_count << endl;
//    cout << "PPAGE = " << currentPage << endl;
//    cout << "PERMIT PAGE? = " << bPermitNextPage << endl;
    
    //cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
    //update timers
    if (bMelodyStart == true) {
        melodyCounter.start();
        finish_page_counter.start();
        //cout << "MELODY TIMER IS NOW: " << melodyCounter.elapsed()/1000 << endl;
    }
    
    float current_melodyCounter = melodyCounter.elapsed()/1000;
    //cout << "MELODY TIMER IS NOW: " << current_melodyCounter << endl;

    
    //exact time for practice trials and main trials to store into arrays
    if(current_melodyCounter >= 2000 && current_melodyCounter < 2050){//onset of last note
        trial_time_counter.start();
        cout << "START REACTION TIMER NOW" << endl;
    }
    
    if(hasPressed == true){//onset of last note
        trial_time_counter.stop();//stop at current time stamp position
        //hasPressed = false;//reset to store just one timestamp for each answer
    }

    
//    //exact time for practice trials and main trials to store into arrays
//    if(hasPressed == true){//onset of last note
////        current_trial_time_counter = trial_time_counter.elapsed();
////        cout << "TIMER IS NOW: " << trial_time_counter.elapsed() << endl;
////        cout << "TIMER IS NOW 2: " << current_trial_time_counter << endl;
//        trial_time_counter.stop();//stop at current time stamp position
//       // hasPressed = false;//reset to store just one timestamp for each answer
//    }
    
    
    
    if(melodyCounter.elapsed() > 10 && melodyCounter.elapsed() < 2050000){//50ms/50,000 microseconds)
        showStars = false;
        bGuessedWrong = false;
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
    
//    //counter is only activated when the user presses either piano or trumpet
    
    //permit practice page to move on even if people press too soon?
    if (currentPage == 3 && practice_count == 1 && (bPlayPracticeMelody == false))
    {
        bPermitNextPage = true;//only allow next page if 2 practice answers are given
    }
    
    //permit multiple trial takes only if 7 sconds have elaped
    if (currentPage >= 4 && currentPage < 24 && trial_time_counter.elapsed() >= 7000000)
    {
        bPermitSecondTrial = true;//allow another press of giles ear
        cout << "NEXT TRIAL IS : " << bPermitSecondTrial << endl;
        franklinBook14.drawString("Please try again!", 100, 170);
    } else bPermitSecondTrial = false;
    
//    if(hasPressed){
//        bPermitSecondTrial = false;//reset
//    }
    
    if (greyStarCounter.elapsed() >= 2999000)//was 2000000 before for user navigated)
    {
        //bMelodyFinished = false;//allow 2 seconds to answer the test?
        //printf("\nTIME UP\n");
        //melodyCounter.reset();
        //trial_time_counter.reset();
        //bPermitNextPage = true; //TODO
        if (currentPage == 3 && practice_count == 1) {
            bPermitNextPage = true;//only allow next page if 2 practice answers are given
            if(bPermitNextPage)
            {
                currentPage ++;//move up 1 page
            }
            bPermitNextPage = false;//reset to false!
        } else if(currentPage >= 4){
            bPermitNextPage = true;//remain true until the next page is reached..
            if(bPermitNextPage)
            {
                currentPage ++;//move up 1 page
            }
            bPermitNextPage = false;
        }
        
        //reset all the timers and variables as soon as the page increments to next trial!
        trumpetNote = false;
        pianoNote = false;
        showStars = false;
        bGuessedWrong = false;
        bGuessedPiano = false;
        bGuessedTrumpet = false;
        //hasPressed = false;
        bPermitGreenDot = false;
        currentFrame = 0;
        fadeFrame = 0;
        //text_counter.reset();
        greyStarCounter.reset();//reset timers
        melodyCounter.reset();
        trial_time_counter.reset();
        finish_page_counter.reset();//reset reay for next bear press -
        greyCounter = 0;
        greyCounter2 = 0;
        bPlayGroupBMelody = false;
        bPlayGroupAMelody = false;
        showDots = false;
        bShowTrialText = false;
        //bShowSingleNoteText = false;//no need for this as text was dissapearing too soon
    }
    
    if(greyStarCounter.elapsed() > 100000)
    {
        //printf("STOP MELODY PLAYBACK\n");
        bPlayPracticeMelody = false;//reset
        bPlayGroupAMelody = false;
        bPlayGroupBMelody = false;
    }
    
//    if(greyStarCounter.elapsed() >= 2999000)
//    {//allow 3 seconds before reset
//        printf("\nSTOP\n");
//        bMelodyFinished = false;
//        bGuessedWrong = false;
//        bGuessedPiano = false;
//        bGuessedTrumpet = false;
//        showStars = false;
//        //hasPressed = false;
//        currentFrame = 0;
//        fadeFrame = 0;
//        greyCounter = 0;
//        greyCounter2 = 0;
//        greyStarCounter.reset();//reset timer
//        melodyCounter.reset();
//        trial_time_counter.reset();
//    }
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
        
        if((bGroupAB || bGroupBA) && (bSessionB2 || bSessionA2 || bSessionB1 || bSessionA1)){
            franklinBook14.drawString("Press right arrow to continue.", 250, 730);
        }
        currentFrame++;
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
        
        currentFrame++;
   
        if(find(answered_v.begin(), answered_v.end(), 0) != answered_v.end())
        {
        
            ofSetColor(0, 0, 0, 255);
            franklinBook14.drawString("It seems like you have not answered all \n\nthe trial numbers.\n\n\n\nPlease navigate back and retake any \n\ntrials with a red circle above them. \n\n\n\nMake sure the dot turns green!\n\n\n\nPress Giles's ear to go back to trial 1 \n\nand check everything is in order!", 50, 130);
            bFinished = false;
            showRedDot = true;
            showGreenDot = false;
            bPermitNextPage = true;//allow user to navigate back

            
        } else {
            ofSetColor(0, 0, 0, 255);
            franklinBook14.drawString("Well Done! \n\n\n\n\n\n20 songs are now completed!\n\nAll the data is stored. \n\n\n\nPlease tell the researcher you have finished.\n\n\n\n\n\nPlease press the square button on the \n\niPad to exit the app now. ", 50, 130);
            bFinished = true;
            showGreenDot = true;
            showRedDot = false;
            bPermitNextPage = true;//allow user to navigate back 
        }
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
       
       if(bShowSingleNoteText){
           text_counter.start();//make sure single notes show text
       }
        
       if(showStars == true && bMelodyFinished){//only permit after melody finished
           bGuessedWrong = false;
           greyStarCounter.start();
           text_counter.start();
           //printf("greyStarCounter is : ""%lld\n",greyStarCounter.elapsed());
       }
        
       if (bGuessedWrong == true && bMelodyFinished) {
            showStars = false;
            greyStarCounter.start();//start timer
            text_counter.start();
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
//            if(practice_count > 1){
//                bResetMelody = true;
//            }
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
            
//            if(currentPage == 5){
//                //float startPress = ((ofGetElapsedTimeMillis() - startDotTime));
//                if(bGuessedWrong){
//                    float guessTime = ((ofGetElapsedTimeMillis() - startDotTime));
//                    float trial1Time = (dotTimer - guessTime);
//                    printf("Trial 1 Time was:  ""%f\n",trial1Time);
//                }
//
//            }
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
        
        
        
        
//        if(currentFrame >= secondTime*2){//&& currentFrame < secondTime*2){
//            float go1 = 0;
//            //float startFade = secondTime/20;
//            //currentFrame = 0;
//            go1 = (currentFrame-secondTime*2)*secondTime*fadeUpTime;
//            
//            if (go1 > 150) {
//                go1 = 150;
//            }
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
                
            } else ofSetColor(255, 255, 255, 255);//was go1 for alpha
            ofEnableAlphaBlending();
            homeButton.draw(20,20);
            
            if(currentPage >= -1 && currentPage < 2){//show right arrow up till last book page then allow home key to move on final page.
                //cout << "SHOW RIGHT ARROW NOW!!!" << endl;
                rightArrow.draw(938,710);
            }
            
            if(currentPage == 2 && text_counter.elapsed() >= 1900000){//show right arrow up till last book page then allow home key to move on final page.
                //cout << "SHOW RIGHT ARROW NOW!!!" << endl;
                rightArrow.draw(938,710);
            }
            
            if(currentPage >= -1 && currentPage < 3){//only show back arrow up until the trials
                leftArrow.draw(10,710);
            }
            
            ofDisableAlphaBlending();
       // }
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
    
//    //set up for the settings tab
//    if (showSettings == true) {
//        
//        ofEnableAlphaBlending();
//        ofSetColor(255, 255, 255, 255);//reset page to stop bleed from previous page
//        settingsPage.draw(311,56);
//        //optionsTab.draw(0,0,1024,768);
//        returnArrow.draw(sin(ofGetElapsedTimeMillis()/105.0f) * 1+573, 132 + sin(ofGetElapsedTimeMillis()/105.0f));
//        
//        ofDisableAlphaBlending();
//    }
    
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
        leftArrow.draw(10,710);
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
        franklinBook14.drawString("This is Giles the Bear! \n\n\n\nHe can't hear very well. \n\n\n\nCan you help him hear \n\nwhat the music is? \n\n\n\nPress the right arrow to continue.", 120, 200);
    }
    
    if(currentPage == 1){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Press the Piano! \n\nWhat do you hear?. \n\n\n\nNow press the trumpet.\n\nCan you hear it is different? \n\n\n\nPress the right arrow to continue.", 120, 100);
    }
    
    if(currentPage == 2 && bGuessedWrong == false && bGuessedPiano == false && bGuessedTrumpet == false && single_count == 0){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Now we are going to hear a sound, \n\neither a piano or a trumpet.\n\n\n\nAs soon as you hear what the \n\nsound is, press the correct image \n\nwith your finger as fast as you can!\n\n\n\nPress Giles's ear to hear the sound!", 100, 70);
    }
    
    //cout<< hasPressed << endl;
    
    if(currentPage == 2 && bShowSingleNoteText == true && text_counter.elapsed() >= 1900000){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Press Giles's ear to hear another \n\nnote!\n\n\n\nOr press the right arrow to move \n\non.", 100, 170);
    }
    
    if(currentPage == 3 && bGuessedWrong == false && bGuessedPiano == false && bGuessedTrumpet == false && practice_count == -1){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Now we are going to hear a song. \n\n\n\nThe last sound will be either a \n\ntrumpet or a piano.\n\n\n\nAs soon as you hear what the last \n\nsound is, press the correct image with \n\nyour finger as fast as you can!\n\n\n\nPress Giles's ear to hear the song!", 100, 70);
        
    }
    
//    if(currentPage == 3 && practice_count >= 1){//edit to 2 for final APP TODO ?
//        if(bPlayPracticeMelody == false){
//            ofSetColor(0, 0, 0);
//            franklinBook14.drawString("Press on the right arrow to move \n\non to the trials.", 100, 200);
//        }
//    }
    
    if(currentPage == 3 && practice_count == 0) {
        ofSetColor(0, 0, 0);
        trials.drawString("Practice 1", trialXpos, 50);//Trial no data kept
    }
    
    if(currentPage == 3 && practice_count == 1) {
        ofSetColor(0, 0, 0);
        trials.drawString("Practice 2", trialXpos, 50);//Trial no data kept
    }

    
    if(currentPage == 3 && practice_count <= 2 && text_counter.elapsed() >= 1900000){
        if(bPlayPracticeMelody == false && practice_count == 0){
            ofSetColor(0, 0, 0);
            franklinBook14.drawString("Press Giles's ear to hear another\n\npractice melody!", 100, 170);
        }
        
        if(bPlayPracticeMelody == false && practice_count == 1){
            ofSetColor(0, 0, 0);
            //franklinBook14.drawString("Please press the right arrow to \n\nmove on.", 100, 300);
        }
        
//        if(currentPage == 3 && practice_count == 0) {
//            ofSetColor(0, 0, 0);
//            trials.drawString("Practice 1", trialXpos, 50);//Trial no data kept
//        }
//        
//        if(currentPage == 3 && practice_count == 1) {
//            ofSetColor(0, 0, 0);
//            trials.drawString("Practice 2", trialXpos, 50);//Trial no data kept
//        }
        
//        if(currentPage == 3 && practice_count == 2) {
//            ofSetColor(0, 0, 0);
//            trials.drawString("Practice 3", trialXpos, 50);//Trial no data kept
//        }
//        
//        if(currentPage == 3 && practice_count >= 3) {
//            ofSetColor(0, 0, 0);
//            trials.drawString("Practice 4", trialXpos, 50);//Trial no data kept
//        }

    }
    
    if(currentPage == 4 && showDots == false){
        //bPlayPracticeMelody = true;//
        bShowTrialText = false;//make sure the post trial text is not seen here
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Are you ready to start?\n\n\n\nAs soon as you hear what the last \n\nsound is, press the correct image with \n\nyour finger as fast as you can!\n\n\n\nPress Giles's ear to hear the song!", 100, 170);
    }
    
    if(currentPage >= 4 && currentPage < 24 && bShowTrialText == true){
        ofSetColor(0, 0, 0);
        //franklinBook14.drawString("Please press the right arrow to move \n\non to the next melody.", 100, 300);
    } else if(currentPage >= 5 && currentPage < 24 && bShowTrialText == false && showDots == false){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Press the correct image with your \n\nfinger as fast as you can!\n\n\n\nPress Giles's ear to hear the song!", 100, 170);
    }
    
//    if(currentPage == 23 && bShowTrialText == true){
//        ofSetColor(0, 0, 0);
//        franklinBook14.drawString("Press Giles's ear to hear the trial \n\nmelody again!\n\n\n\nOr press the right arrow to move \n\nto the finish!", 100, 170);
//    }
    
    if(currentPage >= 4){
        
        if (bPermitSecondTrial)
        {
            //cout << "NEXT TRIAL IS : " << bPermitSecondTrial << endl;
            franklinBook14.drawString("Please try again!\n\n\n\nPress Giles's ear to hear the song!", 100, 170);
        }
        
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
    
    //permit any page changes
    if(currentPage <= 1){
        bPermitNextPage = true;
    }
    
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
            bPianoLeft = true;
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
            bPianoLeft = false;//piano right
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
            bPianoLeft = true;
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
            bPianoLeft = false;
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
            //hasPressed = false;
            currentFrame = 0;
            fadeFrame = 0;
            //greyStarCounter.reset();//reset timer ?
            greyCounter = 0;
            greyCounter2 = 0;
        }
        if(showOptionsTab == false && stopPress == false){
            //code for basic arrow function
            int pageForwardX = 920;
            int pageForwardY = 700;
            int pageBackwardX = 80;
            int pageBackwardY = 700;
            
//            if (currentPage > 3 && currentPage < 24 && x >= pageForwardX && y > pageForwardY )
//            {
//                //trial_melody_count++;//increment up 1 every page
//                printf("%d\n",currentPage);
//            }
//            if(currentPage >= 4 && currentPage < 24 && x >= pageForwardX && y > pageForwardY)
//            {
//                //showRedDot = true;
//                //showGreenDot = false;
//            }
//            if(currentPage >= 4 && x <= pageBackwardX && y > pageBackwardY){
//                //showRedDot = true;
//                //showGreenDot = false;
//            }

            //<24 for user naviagated
            if (currentPage >= -3 && currentPage < 3 && x >= pageForwardX && y > pageForwardY && (bPermitNextPage || showGreenDot))
            {
                
                //if(bPermitNextPage){//only stop sounds when the next page is permitted
//                    trumpetNote = false;
//                    pianoNote = false;
//                    showStars = false;
//                    bGuessedWrong = false;
//                    bGuessedPiano = false;
//                    bGuessedTrumpet = false;
//                    //hasPressed = false;
//                    bPermitGreenDot = false;
                //}
                
                if((currentPage == -1) && (bGroupAB || bGroupBA) && (bSessionB2 || bSessionA2 || bSessionB1 || bSessionA1))
                {
                    cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
                    currentPage ++;
                    bPermitNextPage = true;
                }
                
                //permit user to navigate these pages at any time
                if(currentPage < -1 || currentPage == 0 || currentPage == 1){
                    trumpetNote = false;
                    pianoNote = false;
                    showStars = false;
                    bGuessedWrong = false;
                    bGuessedPiano = false;
                    bGuessedTrumpet = false;
                    //hasPressed = false;
                    bPermitGreenDot = false;
                    currentPage ++;
                    bPermitNextPage = true;
                    cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
                    currentFrame = 0;
                    fadeFrame = 0;
                    text_counter.reset();
                    greyStarCounter.reset();//reset timers
                    melodyCounter.reset();
                    trial_time_counter.reset();
                    finish_page_counter.reset();//reset reay for next bear press -
                    greyCounter = 0;
                    greyCounter2 = 0;
                    bPlayGroupBMelody = false;
                    bPlayGroupAMelody = false;
                    showDots = false;
                    bShowTrialText = false;
                    bShowSingleNoteText = false;
                }
                
                //constrain pages to only move forward if the answer is given and feedback displayed
                else if (currentPage == 2 && bPermitNextPage && text_counter.elapsed() >= 1900000) {
                     trumpetNote = false;
                     pianoNote = false;
                     showStars = false;
                     bGuessedWrong = false;
                     bGuessedPiano = false;
                     bGuessedTrumpet = false;
                     //hasPressed = false;
                     bPermitGreenDot = false;
                     currentPage ++;
                     bPermitNextPage = true;
                     cout << "JUMP???????? " << endl;
                     cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
                     currentFrame = 0;
                     fadeFrame = 0;
                     text_counter.reset();
                     greyStarCounter.reset();//reset timers
                     melodyCounter.reset();
                     trial_time_counter.reset();
                     finish_page_counter.reset();//reset reay for next bear press -
                     greyCounter = 0;
                     greyCounter2 = 0;
                     bPlayGroupBMelody = false;
                     bPlayGroupAMelody = false;
                     showDots = false;
                     bShowTrialText = false;
                     bShowSingleNoteText = false;
                    
                //constrain the practice trials so 2 must be acheived!
                }
                
                //add in again for user naviagted pages!
                
//                else if(currentPage == 3 && practice_permit_count >= 2 && bPermitNextPage)
//                {
//                     currentPage ++;
//                     bPermitNextPage = false;
//                     cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
//                     cout << "PRACTICE COUNT " << practice_count << endl;
//                    
////                } else if(currentPage == 3 && practice_count >= 2)
////                {
////                        currentPage ++;
////                        bPermitNextPage = true;
////                        cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
////                        cout << "PRACTICE COUNT " << practice_count << endl;
//
//                } else if (currentPage >= 4 && currentPage < 24 && (bPermitNextPage || showGreenDot)) {
//                     currentPage ++;
//                     bPermitNextPage = false;
//                     cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
//                }
                
                //if(bPermitNextPage){//only stop sounds
//                    currentFrame = 0;
//                    fadeFrame = 0;
//                    text_counter.reset();
//                    greyStarCounter.reset();//reset timers
//                    melodyCounter.reset();
//                    trial_time_counter.reset();
//                    finish_page_counter.reset();//reset reay for next bear press -
//                    greyCounter = 0;
//                    greyCounter2 = 0;
//                    bPlayGroupBMelody = false;
//                    bPlayGroupAMelody = false;
//                    showDots = false;
//                    bShowTrialText = false;
//                    bShowSingleNoteText = false;
                //}

                printf("Page number is:  ""%d\n",currentPage);
                //printf("%d\n",pageForward);
                //printf("%d\n",pageBack);
                //bPermitNextPage = false;
                
            } else if (currentPage > -3 && currentPage < 3 &&x <= pageBackwardX && y > pageBackwardY && (bPermitNextPage || showGreenDot))
            {
                
                trumpetNote = false;
                pianoNote = false;
                showStars = false;
                bGuessedWrong = false;
                bGuessedPiano = false;
                bGuessedTrumpet = false;
                //hasPressed = false;
                bPermitGreenDot = false;
                
                //permit user to navigate these pages at any time
                if(currentPage <= 2){
                    currentPage --;
                    bPermitNextPage = true;
                    cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
                } else if (currentPage == 3 && bPermitNextPage) {
                    currentPage --;
                    bPermitNextPage = false;//set to false ready for timer to permit moving back
                    cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
                }
                
                //only permit back page presses if the debug setting is on!
                else if (currentPage >= 4 && bDebug == true && currentPage < 24 && (bPermitNextPage || showGreenDot)) {
                    currentPage --;
                    bPermitNextPage = false;//set to false ready for timer to permit moving back
                    cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
                } else if(currentPage == 24 && bDebug == true){
                    currentPage --;
                    cout << "PERMIT PAGE MOVE? " << bPermitNextPage << endl;
                    bPermitNextPage = true;
                }
                currentFrame = 0;
                fadeFrame = 0;
                //reset text on each page turn
                textshow = true;
                texthide = false;
                text_counter.reset();
                greyStarCounter.reset();//reset timers
                melodyCounter.reset();
                trial_time_counter.reset();
                finish_page_counter.reset();
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
                //bPermitNextPage = false;

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
                bPermitNextPage = true;//failsafe to allow continuation.
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
        practice_permit_count = 0;
        practice_count = -1;//reset counter for 0 index on page 3
//        cout << "Piano note is now playing " << playPianoSingle << endl;
//        cout << "Trumpet note is now playing " << playTrumpetSingle << endl;
        
        if (x > 780 && y < 290 && y > 0){//press bear to start single note
            
            //single_count ++;//change to randoimise
            single_count = rand() % 4 + 1;//create a random number 1 - 4
            
            bShowSingleNoteText = false;
            if(single_count > 4){
                single_count = 1;//reset the counter
            }
            text_counter.reset();
            greyStarCounter.reset();//reset timers
            melodyCounter.reset();
            trial_time_counter.reset();
            finish_page_counter.reset();
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
                bPermitArrayTimeStamp = true;
                bPermitGreenDot = true;
                bShowSingleNoteText = true;
                printf("\nGUESS PIANO LEFT\n");
                showStars = true;//show stars!
                //printf("\nWELLDONE\n");
            }
        }
        //PIANO LEFT
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && pianoNote == true && hasPressed == false)
        {
            if(bSessionA1 == true || bSessionB1 == true)
            {
                bGuessedWrong = true;
                hasPressed = true;
                bPermitArrayTimeStamp = true;
                bPermitGreenDot = true;
                bShowSingleNoteText = true;
                showStars = false;
                printf("\nWRONG IT WAS PIANO\n");
            }
        }
        //PIANO LEFT
        if (x > 55 && x < 360 && y < 690 && y > 435 && trumpetNote == true && hasPressed == false)
        {
            if(bSessionA1 == true || bSessionB1 == true)
            {
                bGuessedWrong = true;
                hasPressed = true;
                bPermitArrayTimeStamp = true;
                bPermitGreenDot = true;
                bShowSingleNoteText = true;
                showStars = false;
                printf("\nWRONG IT WAS TRUMPET\n");
            }
        }
        //PIANO LEFT=
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && trumpetNote == true)
        {
            if(bSessionA1 == true || bSessionB1 == true)
            {
                bGuessedTrumpet = true;
                hasPressed = true;
                bPermitArrayTimeStamp = true;
                bPermitGreenDot = true;
                bShowSingleNoteText = true;
                printf("\nGUESS TRUMPET RIGHT\n");
                showStars = true;//show stars!
                //printf("\nWELL DONE\n");
            }
        }
        //Piano RIGHT!!
        if (x > 55 && x < 360 && y < 690 && y > 435 && pianoNote == true && hasPressed == false)
        {
            if(bSessionA2 == true || bSessionB2 == true)
            {
                bGuessedWrong = true;
                hasPressed = true;
                bPermitArrayTimeStamp = true;
                bPermitGreenDot = true;
                bShowSingleNoteText = true;
                showStars = false;
                printf("\nWRONG IT WAS PIANO\n");
            }
        }
        //Piano Right
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && pianoNote == true && hasPressed == false)
        {
            if((bSessionA2) || (bSessionB2))
            {
                bGuessedPiano = true;
                hasPressed = true;
                bPermitArrayTimeStamp = true;
                bPermitGreenDot = true;
                bShowSingleNoteText = true;
                printf("\nGUESS PIANO RIGHT\n");
                showStars = true;//show stars!
                //printf("\nWELLDONE\n");
                
            }
        }
        //PIANO RIGHT
        if (x > 55 && x < 360 && y < 690 && y > 435 && trumpetNote == true && hasPressed == false)
        {
            if((bSessionA2) || (bSessionB2))
            {
                bGuessedTrumpet = true;
                hasPressed = true;
                bPermitArrayTimeStamp = true;
                bPermitGreenDot = true;
                bShowSingleNoteText = true;
                printf("\nGUESS TRUMPET LEFT\n");
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
                bPermitArrayTimeStamp = true;
                bPermitGreenDot = true;
                bShowSingleNoteText = true;
                showStars = false;
                printf("\nWRONG IT WAS TRUMPET\n");
                
            }
        }
    }
    
    /******** PRACTICE TRIALS x 2 *******/
    
    if (currentPage == 3)
    {
        single_count = 0;//reset incase we want to see text on page 2 again.
        playTrumpetSingle = false;
        playPianoSingle = false;
        trial_melody_count = -1;//0 index ready for trials
                //practice_count = -1;//0 index
        //practice_count = 0;//
        
//        if (practice_count > 3)
//        {
//            practice_count = 100;//set to a differnt number to stop animations etc.
//        }
        
//        if(practice_count >= 4){
//            //stop all animation and sound
//            cout << "PRACTICE COUNTER" << practice_count << endl;
//            showDots = false, playPianoMelody = false, playTrumpetMelody = false;
//        }
        
        if (x > 780 && y < 290 && y > 0 && bPlayPracticeMelody == false && finish_page_counter.elapsed() <= 1)//press bear to start melody
        {
            
            practice_permit_count ++;//up to 1 then 2
            cout << "PERMIT PRACTICE COUNT" << practice_permit_count << endl;
            practice_count ++;//up to 0 index first then 1
            if(practice_count > 1){
                //bResetMelody = true;
                practice_count = 0;//reset to start at 0
            }
//            if (practice_count > 3)
//            {
//                cout << "PRACTICE COUNTER" << practice_count << endl;
//                showDots = false, bPlayPracticeMelody = false;
//                //practice_count = -1;
//            } else if(practice_count <= 3)
//            {
            text_counter.reset();
            finish_page_counter.reset();
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
            bResetMelody = false;//must reset the melodies if child does not press
            //bShowTrialText = false;//?
        
            //check what session
            if(bSessionA1 == true || bSessionA2 == true)
            {
                bPlayGroupAMelody = true;
                bPlayGroupBMelody = false;
            } else if(bSessionB1 == true || bSessionB2 == true)
            {
                bPlayGroupBMelody = true;
                bPlayGroupAMelody = false;
            }
        
            //melodies 1 - 2 for group A1 - B1
            if(bPlayGroupAMelody)
            {
                int tempTrialMel = practiceMelody_1_v[practice_count];
                cout << "\nPractice Melody index = " << tempTrialMel << endl;
                if(tempTrialMel == 0)
                {
                    playPianoMelody = true;
                    playTrumpetMelody = false;
                    printf("\nPianoMelody");
                } else if(tempTrialMel == 1)
                {
                    playTrumpetMelody = true;
                    playPianoMelody = false;
                    printf("\nTrumpetMelody");
                }
            }
            //melodies 23 & 24 for group A2 & B2
            else if(bPlayGroupBMelody)
            {
                int tempTrialMel = practiceMelody_2_v[practice_count];
                cout << "\nPractice Melody index = " << tempTrialMel << endl;
                if(tempTrialMel == 0)
                {
                    playPianoMelody = true;
                    playTrumpetMelody = false;
                    printf("\nPianoMelody\n");
                } else if(tempTrialMel == 1)
                {
                    playTrumpetMelody = true;
                    playPianoMelody = false;
                    printf("\nTrumpetMelody\n");
                }
            }
            
            
            
//                cout << "\nMelodyCounter = " << practice_count << endl;
//                //cout << testMelodyNumber[0] << endl;
//                int tempMel = practice_melody_v[practice_count];
//            
//                cout << "\nPractice Melody = " << tempMel << endl;
//                
//                if(tempMel == 0 || tempMel == 2 ){
//                    playPianoMelody = true;//play first piano melody
//                    playTrumpetMelody = false;
//                    printf("\nPianoMelody\n");
//                } else if(tempMel == 1 || tempMel == 3){
//                    playTrumpetMelody = true;
//                    playPianoMelody = false;
//                    printf("\nTrumpetMelody\n");
//                }
            //}
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
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    printf("\nGUESS PIANO LEFT\n");
                    showStars = true;//show stars!
                    //printf("\nWELLDONE");
                }
            }
            //PIANO LEFT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    showStars = false;
                    printf("\nWRONG IT WAS PIANO\n");
                }
            }
            //PIANO LEFT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
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
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    printf("\nGUESS TRUMPET RIGHT\n");
                    showStars = true;//show stars!
                    //printf("\nWELLDONE");
                }
            }
            //Piano RIGHT!!
            if (x > 55 && x < 360 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA2 == true || bSessionB2 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    showStars = false;
                    printf("\nWRONG IT WAS PIANO\n");
                }
            }
            //Piano RIght
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedPiano = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    printf("\nGUESS PIANO RIGHT");
                    showStars = true;//show stars!
                    //printf("\nWELLDONE");
                    
                }
            }
            //PIANO RIGHT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedTrumpet = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    printf("\nGUESS TRUMPET LEFT");
                    showStars = true;//show stars!
                    //printf("\nWELLDONE");
                }
            }
            //PIANO RIGHT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    showStars = false;
                    printf("\nWRONG IT WAS TRUMPET");
                    
                }
            }
        }
    }
    
    /******** TRIALS BEGIN HERE *******/
    if (currentPage >= 4 && currentPage < 24) {//TODO trial 1 - 20
        practice_permit_count = 0;
        bPlayPracticeMelody = false;
        practice_count = -1;//reset counter for 0 index
        trial_melody_count = (currentPage - 4);//had set to 4 this was wrong - fixed bug to match up melodies and indexes.
        cout << "\nCurrent Trial = " << trial_melody_count + 1 << endl;
        if (trial_melody_count > 20) {
            trial_melody_count = 20;
        }

        //press bear head to sound.. or trial number to sound
        if (x > 780 && y < 290 && y > 0 && (finish_page_counter.elapsed() <= 1 || bPermitSecondTrial))
        {
            //cout << "PRESS PRESS PRESS PRESS = " << endl;
            text_counter.reset();
            greyStarCounter.reset();//reset timers
            melodyCounter.reset();
            trial_time_counter.reset();
            finish_page_counter.reset();
            bMelodyStart = true;
            hasPressed = false;
            bGuessedWrong = false;
            showStars = false;
            showDots = true;
            //showGreenDot = false;
            //showRedDot = true;
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
            
            
        
            //melodies 1 - 20 for group A1 - B1
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
            //melodies 1 - 20 for group A2 - B2
            else if(bPlayGroupBMelody)
            {
                int tempTrialMel = trialMelody_2_v[trial_melody_count];
                cout << "\nTrial Melody index = " << tempTrialMel << endl;
                if(tempTrialMel >= 0 && tempTrialMel < 10 )
                {
                    playPianoMelody = true;
                    playTrumpetMelody = false;
                    printf("\nPianoMelody\n");
                } else if(tempTrialMel >= 10 && tempTrialMel < 20)
                {
                    playTrumpetMelody = true;
                    playPianoMelody = false;
                    printf("\nTrumpetMelody\n");
                }
            }
            
            //bPermitSecondTrial = false;//reset
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
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    printf("\nGUESS PIANO LEFT\n");
                    showStars = true;//show stars!
                    //showGreenDot = true;
                    printf("\nWELLDONE\n");
                }
            }
            //PIANO LEFT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    showStars = false;
                    //showGreenDot = true;
                    printf("\nWRONG IT WAS PIANO\n");
                }
            }
            //PIANO LEFT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    showStars = false;
                    //showGreenDot = true;
                    printf("\nWRONG IT WAS TRUMPET\n");
                }
            }
            //PIANO LEFT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if(bSessionA1 == true || bSessionB1 == true)
                {
                    bGuessedTrumpet = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    //showGreenDot = true;
                    printf("\nGUESS TRUMPET RIGHT\n");
                    showStars = true;//show stars!
                    printf("\nWELLDONE\n");
                }
            }
            //Piano RIGHT!!
            if (x > 55 && x < 360 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if(bSessionA2 == true || bSessionB2 == true)
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    showStars = false;
                    //showGreenDot = true;
                    printf("\nWRONG IT WAS PIANO\n");
                }
            }
            //Piano Right
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedPiano = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    //showGreenDot = true;
                    printf("\nGUESS PIANO RIGHT\n");
                    showStars = true;//show stars!
                    printf("\nWELLDONE\n");
                    
                }
            }
            //PIANO RIGHT
            if (x > 55 && x < 360 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedTrumpet = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    //showGreenDot = true;
                    printf("\nGUESS TRUMPET LEFT\n");
                    showStars = true;//show stars!
                    printf("\nWELLDONE\n");
                }
            }
            //PIANO RIGHT
            if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false)
            {
                if((bSessionA2) || (bSessionB2))
                {
                    bGuessedWrong = true;
                    hasPressed = true;
                    bPermitArrayTimeStamp = true;
                    bPermitGreenDot = true;
                    showStars = false;
                    //showGreenDot = true;
                    printf("\nWRONG IT WAS TRUMPET\n");
                    
                }
            }
        }
    }
    
    if (currentPage >= 4 && currentPage < 24)
    {
        //allow user to know if they have answered any of the trials with a green or red dot
        for (int i = 0; i < 20; i++) {
            if(currentPage == i+4){
                if(bPermitGreenDot){
                    answered_v[i] = 1;//assign 1 to the current index
                } //else answered_v[i] = 0;
            }
            //cout << "CURRENT TRIALS ANSWERED = " << answered_v[i] << endl;
        }
        for (int i = 0; i < 20; i++) {
            if(currentPage == i+4){
                if(answered_v[i] == 1){
                    showGreenDot = true;
                    showRedDot = false;
                    cout << "SHOW GREEN DOT!" << endl;
                } else if(answered_v[i] == 0){
                    showRedDot = true;
                    showGreenDot = false;
                    //cout << "SHOW RED DOT!" << endl;
                }
            }
        }
    }

    if (currentPage == 24)
    {
        for(int i = 0; i <20; i ++)
        {
            if (answered_v[i] == 0) {
                answered_all = ofToString(answered_v[i]) + ",";
                cout << "answered_v index " << i << " = "<< answered_v[i] << " so not answered" << endl;
            } else bFinished = true;//make sure the file saves!
            
        }
        
        //press bear head to return to trial 1!!!!
        if (x > 780 && y < 290 && y > 0 && bDebug == true)//only permit if debugging is true!
        {
            currentPage = 4;
        }
    }
    
    //permit any page changes
    if(currentPage <= 1){
        bPermitNextPage = true;
    }
}






