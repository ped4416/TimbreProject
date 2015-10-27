////
////  Introduction.cpp
////  TimbreApp
////
////  Created by Pedro Kirk on 21/03/2015.
////
////
//#include "ofPage.h"
//#include "Introduction.h"
//
//Introduction::Introduction(){
//    
//    //inherits basic variables from page class
//    
//}
//
//void Introduction::setup(){
//    
//    bearImg.loadImage("Images/bearfull.png");
//    pianoImg.loadImage("Images/PIANO.png");
//    trumpetImg.loadImage("Images/TRUMPET.png");
//    
//}
//
//void Introduction::draw(){
//    
//    if (currentPage == 1){
//        ofEnableAlphaBlending();
//        //dim page and stop interaction and music if options are on display
//        if(showOptionsTab == true || showSettings == true){
//            ofSetColor(255, 255, 255, 100);
//        } else ofSetColor(255,255,255,255);
//        bearImg.draw(0,0,1024,768);//plus 10 pixlels to line up correctly
//        
//        currentFrame++;
//        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
//    }
//    
//    if (currentPage == 2){
//        ofEnableAlphaBlending();
//        //dim page and stop interaction and music if options are on display
//        if(showOptionsTab == true || showSettings == true){
//            ofSetColor(255, 255, 255, 100);
//        } else ofSetColor(255,255,255,255);
//       
//        pianoImg.draw(150,350);
//        trumpetImg.draw(ofGetScreenWidth()-200,350);
//        currentFrame++;
//        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
//    }
//
//    if (currentPage >= 3){// && guessedWrong == false && guessedPiano == false && guessedTrumpet == false){
//        ofEnableAlphaBlending();
//        //dim page and stop interaction and music if options are on display
//        if(showOptionsTab == true || showSettings == true){
//            ofSetColor(255, 255, 255, 100);
//        } else ofSetColor(255,255,255,255);
//        //pianoImg.draw(0,0,1024,768);
//        //trumpetImg.draw(0,0,1024,768);
//        bearImg.draw(10,0,1024,768);//plus 10 pixlels to line up correctly
//        pianoImg.draw(55,410);
//        trumpetImg.draw(ofGetScreenWidth()-380,410);
//        currentFrame++;
//        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
//    }
//    
//}//touch functionality
//
////void Introduction::touchIntro(int x, int y){
////    if(currentPage == 1){
////        playTrumpetMelody = false;
////        playPianoMelody = false;
////        playTrumpetSingle = false;
////        playPianoSingle = false;
////    }
////    
////    //press functions for Starting Melodies
////    if (currentPage == 2) {
////        countMelody = 0;//reset counter
////        playTrumpetMelody = false;
////        playPianoMelody = false;
////        
////        if (x > 130 && x < 480
////            && y < 650 && y > 320){
////            playPianoSingle = true;
////        }
////        
////        if (x > 570 && x < 890
////            && y < 650 && y > 320){
////            playTrumpetSingle = true;
////        }
////    }
////}