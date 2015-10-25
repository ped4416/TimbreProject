#include "ofPage.h"
//#include "maximilian.h"
//#include <iostream>
//#include <time.h>

ofPage::ofPage(){
    
    //variables for all pages of Timbre App
    countMelody = 0;
    currentFrame = 0;
    fadeFrame = 0;
    currentPage = 0;
    secondTime = 30;//20
    fadeUpTime = 0.05;
    
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

    
    
    showStars = false;
    playPianoSingle = false;
    playTrumpetSingle = false;
    playPianoMelody = false;
    playTrumpetMelody = false;
    
    
    //set sounds
    tom1play = false;
    tom2play = false;
    playMusic = true; //default load mode is music on
    playMusicTemp = true;// to stop music when settings menu is on
    
    playTest_o1 = false;
    playTest_x1 = false;
    playTest_o2 = false;
    playTest_x2 = false;
    
    bGuessedPiano = false;
    bGuessedTrumpet = false;
    bGuessedWrong = false;
    
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
    displayDot1 = false;
    displayDot2 = false;
    displayDot3 = false;
    displayDot4 = false;
    displayQM = false;
    
    //bools for text
    texthide = false;
    textshow = true;
    
    bMelodyFinished = false;
    bPianoLeft = true;//start true!

    bTimerReached = false;
    startTime = ofGetElapsedTimeMillis();  // get the start time
    startDotTime = ofGetElapsedTimeMillis();  // get the start time to use for dots on screen
    endTime = (int)ofRandom(1000, 5000); // in milliseconds
    greyCounter = 0;
    greyCounter2 = 0;
}

void ofPage::setup(){//implementation of the update() function of our object
    
    
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
    
}

void ofPage::update(){
    
    //cout << "\nMELODY FINISHED  " << bMelodyFinished << endl;//debug?
    
    //update timers
    if (bMelodyStart == true) {
        melodyCounter.start();
        //printf("MELODY START\n");
        //bMelodyFinished = false;
    }
    
    if(melodyCounter.elapsed() > 2200000){//set to 200ms after last note onset?
        //printf("MELODY FINISHED\n");
        //cout << "\nMELODY FINISHED  " << bMelodyFinished << endl;//debug?
        bMelodyFinished = true;
        //bMelodyStart = false;
        //melodyCounter.reset();//bug?
    }
    
    if (greyStarCounter.elapsedSeconds() > 2000000) {
        bMelodyFinished = false;//allow 2 seconds to answer the test?
        printf("TIME UP\n");
        melodyCounter.reset();
    }
    
    if(greyStarCounter.elapsed() >= 2999000){
        //printf("STOP STOP STOP STOP STOP");
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
    }
}

bool ofPage::showAccelPage(int x) {//a method to allow accelarometer to display correctly
    
    if (currentPage >= 0 && showStars == true) {
        x = 1;
    } else x = 0;
    
    return x;
}

void ofPage::draw(){
    
    if(melodyCounter.elapsed() > 2200000){//set to 200ms after last note onset?
        //printf("MELODY FINISHED\n");
        //cout << "\nMELODY FINISHED  " << bMelodyFinished << endl;//debug?
        //cout << "\nMELODY TIME = " << melodyCounter.elapsed() << endl;//debug?
        bMelodyFinished = true;
        //bMelodyStart = false;
        //melodyCounter.reset();//bug?
    }
    
    if(currentPage == 0){
        showStars = false;
        ofEnableAlphaBlending();
        ofSetColor(0, 0, 0);
        buttonText.drawString("Playtime",sin(ofGetElapsedTimeMillis()/102.0f) * 1 +79,382+sin(ofGetElapsedTimeMillis()/102.0f));
        buttonText.drawString("Credits",sin(ofGetElapsedTimeMillis()/102.0f) * 1 +716,500+sin(ofGetElapsedTimeMillis()/102.0f));
        buttonText.drawString("Practice",sin(ofGetElapsedTimeMillis()/102.0f) * 1 +79,500+sin(ofGetElapsedTimeMillis()/102.0f));
        buttonText.drawString("Options",sin(ofGetElapsedTimeMillis()/102.0f) * 1 +716,382+sin(ofGetElapsedTimeMillis()/102.0f));
        
        ofDisableAlphaBlending();
        
        playTrumpetSingle = false;
        playPianoSingle = false;
        playTrumpetMelody = false;
        playPianoMelody = false;
    
    }

    if(howTo == true){
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, 255);
        //howToPage.draw(0,0,1024,768);
        ofDisableAlphaBlending();
        
    }
    
    if (currentPage > 0 && currentPage < 28){
        
       float timer = ofGetElapsedTimeMillis() - startTime;
        
       if(showStars == true && bMelodyFinished){//only permit after melody finished
           bGuessedWrong = false;
           greyStarCounter.start();
           //printf("greyStarCounter is : ""%lld\n",greyStarCounter.elapsed());
       } else tom1play = false, tom2play = false;
       
        
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
            
            
            ofSetColor(0);
            franklinBook14.drawString("Better Luck Next Time!", 100, 400);
        }
        
        // some information about the timer
        string  info  = "FPS:    "+ofToString(ofGetFrameRate(),0)+"\n";
        info += "Timer:"+ofToString(timer/1000.0, 1)+" seconds\n";
        ofSetColor(0);
        //ofDrawBitmapString(info, ofGetScreenWidth()-200, 20);
        
        //playPage.draw(0,0,1024,768);
        fadePage = true;
        
        //show the dots and question mark
        if(showDots == true){
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
            if(dotTimer >= 2004.00 && dotTimer < 4000){
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
            
            if(currentPage <27){//show right arrow up till last book page then allow home key to move on final page.
                rightArrow.draw(938,710);
            }
            
            if(currentPage > 1){//only show left arrow from page 2
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
    
    if (howTo == true || currentPage == 27){
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
    
    if(currentPage == 27){
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
    if(currentPage == 1 && bGuessedWrong == false && bGuessedPiano == false && bGuessedTrumpet == false){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("This is Giles the Bear! \n\n\n\nHe can't hear very well. \n\n\n\nCan you help him hear \n\nwhat the music is? ", 120, 200);
    }
    
    if(currentPage == 2){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Press the Piano! \n\nWhat do you hear?. \n\n\n\nNow press the trumpet.\n\nCan you hear it is different? ", 120, 150);
    }
    
    if(currentPage == 3 && bGuessedWrong == false && bGuessedPiano == false && bGuessedTrumpet == false){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Can you tell Giles what \n\ninstrument is playing?\n\n\n\nIs it a piano?\n\n\n\nOr is it a trumpet? \n\n\n\nPress Giles's ear to hear the tune!", 100, 70);
    }
    
    if(currentPage == 4 && showDots == false){
        ofSetColor(0, 0, 0);
        franklinBook14.drawString("Are you ready to start?\n\n\n\nListen out for the last note. \n\n\n\nCan you tell Giles what \n\nthe instrument is?", 100, 70);
    }
    
    if(currentPage >= 4){
    ofSetColor(0, 0, 0);
        switch(currentPage){
            case 4  :
                trials.drawString("Trial 1", trialXpos, 50);//Trial no data kept
                break;
            case 5  :
                trials.drawString("Trial 2", trialXpos, 50);//Trial no data kept
                break;
                
            //*** START COLLECTING TIME DATA HERE ***
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
    currentFrame++;//counter keeps the timing of the book
    fadeFrame ++;//all animation fades
    //printf("Page number is:  ""%d\n",currentPage);
}

void ofPage::touchPressed(int x, int y){//this is overidden in subclasses
    
}

void ofPage::showPage(int x, int y){
    
    //set up presses for the Title Page
    if (currentPage == 0){
        
        textshow = true;//fixed a display bug
        texthide = false;//fixed a display bug
        
        //set up for pressing the PLAYTIME page - starts from the begining (introduction to Bear etc)
        int playtimeX1 = 70;
        int playtimeY1 = 320;
        int playtimeX2 = 274;
        int playtimeY2 = 424;
        
        //set up for pressing the PRACTICE Page (jump straight to the practice page Number 3 (0 index)
        int practiceX1 = 70;
        int practiceY1 = 458;
        int practiceX2 = 263;
        int practiceY2 = 560;
        
        //set up for pressing the Read To Myself Version
        int optionsX1 = 760;
        int optionsY1 = 458;
        int optionsX2 = 915;
        int optionsY2 = 580;
        
        //set up for seeing the Credits
        int creditsX1 = 720;
        int creditsY1 = 320;
        int creditsX2 = 960;
        int creditsY2 = 490;
        
        
        if (x > playtimeX1 && y > playtimeY1
            && x < playtimeX2 && y < playtimeY2){
            currentFrame = 0;
            currentPage = 1;//move to introduction page
            //showCredits = true;
            //fadeFrame = 0;
            //howTo = false;
            printf("Introduce me to Giles Please\n");
            printf("%d\n",currentPage);
        } else showCredits = false;
        
        if (x > practiceX1 && y > practiceY1
            && x < practiceX2 && y < practiceY2){
            currentPage = 3;//straight to the Practice Page!
            currentFrame = 0;
            printf("PRACTICE PAGE\n");
            printf("%d\n",currentPage);
        }
        
        if (x > creditsX1 && y > creditsY1
            && x < creditsX2 && y < creditsY2){
            showCredits = true;
            currentFrame = 0;
            fadeFrame = 0;
            howTo = false;//bug?
            printf("Credits\n");
            printf("%d\n",currentPage);
            

        }
        
        if (x > optionsX1 && y > optionsY1
                   && x < optionsX2 && y < optionsY2){
            showOptionsTab = true;
            currentFrame = 0;
            fadeFrame = 0;
            narrate = false;// no narration read to myself!
            printf("OPTIONS\n");
            printf("%d\n",currentPage);
        }
    }
    
    //set up page presses for all main book pages
    if (currentPage >= 0 && currentPage < 27) {//constrain the main book page presses
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
            
            if (currentPage > 0 && currentPage < 27 && x >= pageForwardX && y > pageForwardY ){
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
                
                //narrate = false;//this is to stop narration coming in too soon.
                //reset text on each page turn
                textshow = true;
                texthide = false;
//                printf("%d\n",currentPage);
//                printf("%d\n",pageForward);
//                printf("%d\n",pageBack);
                
            } else if (currentPage > 1 && x <= pageBackwardX && y > pageBackwardY){
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
                printf("Page number is:  ""%d\n",currentPage);
                printf("%d\n",pageForward);
                printf("%d\n",pageBack);
                
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
        
        //all touch for settings of music on/off and narration on or off
        if (showSettings == true) {
            stopPress = true;
            showOptionsTab = false;//must run first to stop interference of buttons.
            howTo = false;
            
            //back to options tab
            int resumeX1 = 580;
            int resumeX2 = 640;
            int resumeY1 = 130;
            int resumeY2 = 200;
            
            //press top right to stop music
            int musicOffX1 = 580;
            int musicOffX2 = 640;
            int musicOffY1 = 240;
            int musicOffY2 = 295;
            
            int toMyselfX1 = 580;
            int toMyselfX2 = 640;
            int toMyselfY1 = 320;
            int toMyselfY2 = 400;
            
            int toMeX1 = 580;
            int toMeX2 = 640;
            int toMeY1 = 420;
            int toMeY2 = 496;
            
            if (x > resumeX1 && x < resumeX2
                && y > resumeY1 && y < resumeY2 ){
                showSettings = false;
                stopPress = false;
                
                
            } else if (x > musicOffX1 && x < musicOffX2
                       && y > musicOffY1 && y < musicOffY2 ){
                playMusic = !playMusic;
                printf("sound on and off?");
                
            } else if (x > toMyselfX1 && x < toMyselfX2
                       && y > toMyselfY1 && y < toMyselfY2 ){
                narrate = false;
                //readToMe = false;
                printf("narrate off?");
                
            } else if (x > toMeX1 && x < toMeX2
                       && y > toMeY1 && y < toMeY2 ){
                narrate = true;
                printf("narrate true?");
                
            }
            
        }
    }
    
    //make sure music is turned off when options tab is up
    if(showOptionsTab == true || showSettings == true || howTo == true){
        playMusicTemp = false;
        narrateTemp = false;
    } else playMusicTemp = true, narrateTemp = true;
    
    //if howToPage is active allow sound to be switched off
    //see how to navigate the app
    if (howTo == true) {
        
        if(showOptionsTab == false || currentPage == 0){
            
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
    
    if(currentPage == 1){
        playTrumpetMelody = false;
        playPianoMelody = false;
        playTrumpetSingle = false;
        playPianoSingle = false;
    }
    
    //press functions for Starting Melodies
    if (currentPage == 2) {
        
        playTrumpetMelody = false;
        playPianoMelody = false;
        
        if (x > 130 && x < 480
            && y < 650 && y > 320){
            playPianoSingle = true;
        }
        
        if (x > 570 && x < 890
            && y < 650 && y > 320){
            playTrumpetSingle = true;
        }
    }
    
    if (currentPage == 3) {
        playTrumpetSingle = false;
        playPianoSingle = false;
        playTest_o1 = false;
        playTest_x1 = false;
        
        if (x > 780 && y < 290 && y > 0){//press bear to start melody
            bMelodyStart = true;
            //melodyCounter.start();
            showStars = false;
            hasPressed = false;
            bGuessedWrong = false;
            showStars = false;
            showDots = false;
            playTrumpetMelody = true;
            playPianoMelody = false;

            countMelody ++;//make random??
            if (countMelody > 4) {
                countMelody = 1;
            }
            if(countMelody == 1 || countMelody == 3 ){
                playPianoMelody = true;//play first piano melody
                playTrumpetMelody = false;
                printf("\nPianoMelody\n");
            }else if(countMelody == 2 || countMelody == 4){
                playTrumpetMelody = true;
                playPianoMelody = false;
                printf("\nTrumpetMelody\n");
            }
        }
        //cout << "\nMelodyCounter  " << countMelody;
        //if (bMelodyFinished) {
            //printf("\nMELODY HAS FINISHED MELODY HAS FINSHED MELODY HAS FINISHED");
            //pressing for stars!
            if (x > 55 && x < 360
                && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false){//&&bMelodyFinished
                //greyStarCounter.start();
                //bMelodyFinished = true;//bug stopping bool getting to trigger sounds..
                bGuessedPiano = true;
                hasPressed = true;
                printf("\nGUESS PIANO");
                showStars = true;//show stars!
                printf("\nWELLDONE");
            }
            
            if (x > ofGetScreenWidth()-380 && x < 711
                && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false){
                //greyStarCounter.start();
                bGuessedTrumpet = true;
                hasPressed = true;
                printf("\nGUESS TRUMPET");
                showStars = true;//show stars!
                printf("\nWELLDONE");
            }
            
            //wrong guess
            if (x > 55 && x < 360
                && y < 690 && y > 435 && playTrumpetMelody == true && hasPressed == false){
                bGuessedWrong = true;
                hasPressed = true;
                showStars = false;
                printf("\nWRONG IT WAS TRUMPET");

            }
            
            if (x > ofGetScreenWidth()-380 && x < 711
                && y < 690 && y > 435 && playPianoMelody == true && hasPressed == false){
                bGuessedWrong = true;
                hasPressed = true;
                showStars = false;
                printf("\nWRONG IT WAS PIANO");

            }
        //}
    }
    
    if (currentPage == 4) {//trial 1
        playTest_x1 = false;//reset bool
        playTest_o2 = false;
        //press bear head to sound.. or trial number to sound
        if (x > 780 && y < 290 && y > 0 && hasPressed == false){
            bMelodyStart = true;
            //melodyCounter.start();
            bGuessedWrong = false;
            showStars = false;
            showDots = true;
            startDotTime = ofGetElapsedTimeMillis();  // get the start time
            playTest_o1 = true; //play expected melody with trumpet
            printf("\nTest1-PlayNOW");
            playTrumpetMelody = false;
            playPianoMelody = false;
        }
        
        //pressing for stars!
        if (x > 55 && x < 360 && y < 690 && y > 435 && playTest_o1 == true && hasPressed == false){// && bMelodyFinished == true){
            bGuessedTrumpet = false;
            bGuessedWrong = true;
            showStars = false;
            printf("\nGUESS Piano");
            printf("\nSorry Better Luck Next Time");
            hasPressed = true;
            
        }
        
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTest_o1 == true && hasPressed == false){// && bMelodyFinished == true){
            bGuessedTrumpet = true;
            printf("\nGUESS Trumpet");
            showStars = true;//show stars!
            printf("\nWELLDONE");
            hasPressed = true;
        }
        
    }
    if (currentPage == 5){//trial 2
        playTest_o1 = false;//reset bool
        playTest_x1 = false;
        //press bear head to sound.. or trial number to sound
        if (x > 780 && y < 290 && y > 0 && hasPressed == false){
            bMelodyStart = true;
            bGuessedWrong = false;
            showStars = false;
            showDots = true;
            startDotTime = ofGetElapsedTimeMillis();  // get the start time
            playTest_o2 = true; //play expected melody with piano
            printf("\nTest 2 PlayNOW");
        }
        
        //pressing for stars!
        if (x > 55 && x < 360 && y < 690 && y > 435 && playTest_o2 == true && hasPressed == false){
            bGuessedPiano = true;
            printf("\nGUESS Piano");
            showStars = true;//show stars!
            printf("\nWELLDONE");
            hasPressed = true;
            
        }
        
        if (x > ofGetScreenWidth()-380 && x < 711 && y < 690 && y > 435 && playTest_o2 == true && hasPressed == false){
            bGuessedPiano = false;
            bGuessedWrong = true;
            printf("\nGUESS Trumpet");
            printf("\nSorry Better Luck Next Time");
            hasPressed = true;
        }
    }
    if (currentPage > 5 || currentPage == 0){//edit as we add more trials..
        playTest_o1 = false;//reset bool
        playTest_x1 = false;//reset bool
        playTest_o2 = false;//reset bool
        playTest_x2 = false;//reset bool
    }
    
    if(showStars == true && x > ofGetScreenWidth()/2){
        tom1play = true;
        bGuessedWrong = false;
    } else tom1play = false;
    
    if(showStars == true && x < ofGetScreenWidth()/2){
        tom2play = true;
        bGuessedWrong = false;
    } else tom2play = false;
    
    //printf("%d\n",currentPage);
}






