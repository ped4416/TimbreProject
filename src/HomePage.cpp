//
//  HomePage.cpp
//  TimbreApp
//
//  Created by Pedro Kirk on 15/03/2015.
//
//
#include "ofPage.h"
#include "HomePage.h"

HomePage::HomePage(){
    
    //inherits basic variables from page class
    
}

void HomePage::setup(){
    cover.loadImage("Images/homePage.png");
    
}

void HomePage::draw(){
    
    ofBackground(255, 255, 255);
    if (currentPage == 0){
        showStars = false;
        ofEnableAlphaBlending();
        //dim page and stop interaction and music if options are on display
        if(showOptionsTab == true || showSettings == true){
            ofSetColor(255, 255, 255, 100);
        } else ofSetColor(255,255,255,255);
        cover.draw(0,0,1024,768);//plus 10 pixlels to line up correctly
        currentFrame++;
        //printf("%d\n",currentFrame);//keep track of timer as each page is clicked.
    }
    
}//touch functionality