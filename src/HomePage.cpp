////
////  HomePage.cpp
////  TimbreApp
////
////  Created by Pedro Kirk on 15/03/2015.
////
////
//#include "ofPage.h"
//#include "HomePage.h"
//
//HomePage::HomePage(){
//    
//    //inherits basic variables from page class
//    
//}
//
//void HomePage::setup(){
//    cover.loadImage("Images/homePage.png");
//}
//
//void HomePage::draw(){
//    
//    //cout << "my array is size: " << testMelodyNumber.size() << endl;
//    //printf("Page number is:  ""%d\n",ofPage().currentPage);
//    ofBackground(255, 255, 255);
//    if (currentPage == 1){
//        //printf("HOME PAGE");
//        showStars = false;
//        ofEnableAlphaBlending();
//        //dim page and stop interaction and music if options are on display
//        if(showOptionsTab == true || showSettings == true){
//            ofSetColor(255, 255, 255, 100);
//        } else ofSetColor(255,255,255,255);
//        cover.draw(0,0,1024,768);//plus 10 pixlels to line up correctly
//        currentFrame++;
//        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
//    }
//    
//}//touch functionality
////
////void HomePage::touchHome(int x, int y){
////    //set up presses for the Title Page
////    if (currentPage == 0){
////     
////        //set up for pressing the PLAYTIME page - starts from the begining (introduction to Bear etc)
////        int playtimeX1 = 70;
////        int playtimeY1 = 320;
////        int playtimeX2 = 274;
////        int playtimeY2 = 424;
////        
////        //set up for pressing the PRACTICE Page (jump straight to the practice page Number 3 (0 index)
////        int practiceX1 = 70;
////        int practiceY1 = 458;
////        int practiceX2 = 263;
////        int practiceY2 = 560;
////        
////        //set up for pressing the Read To Myself Version
////        int optionsX1 = 760;
////        int optionsY1 = 458;
////        int optionsX2 = 915;
////        int optionsY2 = 580;
////        
////        //set up for seeing the Credits
////        int creditsX1 = 720;
////        int creditsY1 = 320;
////        int creditsX2 = 960;
////        int creditsY2 = 490;
////        
////        
////        if (x > playtimeX1 && y > playtimeY1
////            && x < playtimeX2 && y < playtimeY2){
////            //            cout << "\nMelody Counter Array Length = " << testMelodyNumber.size();
////            
////            currentFrame = 0;
////            currentPage = 1;//move to introduction page
////            //showCredits = true;
////            //fadeFrame = 0;
////            //howTo = false;
////            printf("Introduce me to Giles Please\n");
////            printf("%d\n",currentPage);
////        } else showCredits = false;
////        
////        if (x > practiceX1 && y > practiceY1
////            && x < practiceX2 && y < practiceY2){
////            currentPage = 3;//straight to the Practice Page!
////            currentFrame = 0;
////            printf("PRACTICE PAGE\n");
////            printf("%d\n",currentPage);
////        }
////        
////        if (x > creditsX1 && y > creditsY1
////            && x < creditsX2 && y < creditsY2){
////            showCredits = true;
////            currentFrame = 0;
////            fadeFrame = 0;
////            howTo = false;//bug?
////            printf("Credits\n");
////            printf("%d\n",currentPage);
////            
////            
////        }
////        
////        if (x > optionsX1 && y > optionsY1
////            && x < optionsX2 && y < optionsY2){
////            showOptionsTab = true;
////            currentFrame = 0;
////            fadeFrame = 0;
////            narrate = false;// no narration read to myself!
////            printf("OPTIONS\n");
////            printf("%d\n",currentPage);
////        }
////    }
////
////}