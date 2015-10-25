//
//  Ball.h
//  TimbreApp
//
//  Created by Pedro Kirk on 31/03/2015.
//
//

#ifndef TimbreApp_Ball_h
#define TimbreApp_Ball_h
#pragma once

#define BOUNCE_FACTOR			0.7
#define ACCELEROMETER_FORCE		0.7
#define RADIUS					100


class Ball{
    
public:
    
    ofPoint pos;
    ofPoint pos1;
    ofPoint pos2;
    ofPoint pos3;
    ofPoint pos4;
    ofPoint pos5;
    ofPoint pos6;
    ofPoint pos7;
    
    ofPoint vel;
    ofPoint vel1;
    ofPoint vel2;
    ofPoint vel3;
    ofPoint vel4;
    ofPoint vel5;
    ofPoint vel6;
    ofPoint vel7;
    
    
    bool bDragged;
    
    ofImage star1;
    ofImage star2;
    ofImage star3;
    ofImage star4;
    ofImage star5;
    ofImage star6;
    ofImage star7;
    ofImage star8;
    ofImage arrow;
    
    //----------------------------------------------------------------
    void init(int id) {
        star1.loadImage("rgb/STARS1.png");
        star2.loadImage("rgb/STARS2.png");
        star3.loadImage("rgb/STARS3.png");
        star4.loadImage("rgb/STARS4.png");
        star5.loadImage("rgb/STARS5.png");
        star6.loadImage("rgb/STARS6.png");
        star7.loadImage("rgb/STARS7.png");
        star8.loadImage("rgb/STARS8.png");
        
        pos.set(ofRandomWidth(), ofRandomHeight(), 0);
        vel.set(ofRandomf(), ofRandomf(), 0);
        pos1.set(ofRandomWidth(), ofRandomHeight(), 0);
        vel1.set(ofRandomf(), ofRandomf(), 0);
        pos2.set(ofRandomWidth(), ofRandomHeight(), 0);
        vel2.set(ofRandomf(), ofRandomf(), 0);
        pos3.set(ofRandomWidth(), ofRandomHeight(), 0);
        vel3.set(ofRandomf(), ofRandomf(), 0);
        pos4.set(ofRandomWidth(), ofRandomHeight(), 0);
        vel4.set(ofRandomf(), ofRandomf(), 0);
        pos5.set(ofRandomWidth(), ofRandomHeight(), 0);
        vel5.set(ofRandomf(), ofRandomf(), 0);
        pos6.set(ofRandomWidth(), ofRandomHeight(), 0);
        vel6.set(ofRandomf(), ofRandomf(), 0);
        pos7.set(ofRandomWidth(), ofRandomHeight(), 0);
        vel7.set(ofRandomf(), ofRandomf(), 0);
        
        
        bDragged = false;
    }
    
    //----------------------------------------------------------------
    void update() {
        vel.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();
        vel.y += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
        vel1.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();
        vel1.y += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
        
        vel2.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();
        vel2.y += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
        
        vel3.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();
        vel3.y += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
        vel4.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();
        vel4.y += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
        vel5.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();
        vel5.y += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
        vel6.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();
        vel6.y += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
        vel7.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();
        vel7.y += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
        
        
        
        // add vel to pos
        pos += vel;
        pos1 += vel1;
        pos2 += vel2;
        pos3 += vel3;
        pos4 += vel4;
        pos5 += vel5;
        pos6 += vel6;
        pos7 += vel7;
        
        // check boundaries
        if(pos.x < RADIUS) {
            pos.x = RADIUS;
            vel.x *= -BOUNCE_FACTOR;
        } else if(pos.x >= ofGetWidth() - RADIUS) {
            pos.x = ofGetWidth() - RADIUS;
            vel.x *= -BOUNCE_FACTOR;
        }
        
        if(pos.y < RADIUS) {
            pos.y = RADIUS;
            vel.y *= -BOUNCE_FACTOR;
        } else if(pos1.y >= ofGetHeight() - RADIUS) {
            pos.y = ofGetHeight() - RADIUS;
            vel.y *= -BOUNCE_FACTOR;
        }
        
        //check 2
        if(pos1.x < RADIUS) {
            pos1.x = RADIUS;
            vel1.x *= -BOUNCE_FACTOR;
        } else if(pos.x >= ofGetWidth() - RADIUS) {
            pos1.x = ofGetWidth() - RADIUS;
            vel1.x *= -BOUNCE_FACTOR;
        }
        
        if(pos1.y < RADIUS) {
            pos1.y = RADIUS;
            vel1.y *= -BOUNCE_FACTOR;
        } else if(pos1.y >= ofGetHeight() - RADIUS) {
            pos1.y = ofGetHeight() - RADIUS;
            vel1.y *= -BOUNCE_FACTOR;
        }
        
        //check 3
        if(pos2.x < RADIUS) {
            pos2.x = RADIUS;
            vel2.x *= -BOUNCE_FACTOR;
        } else if(pos.x >= ofGetWidth() - RADIUS) {
            pos2.x = ofGetWidth() - RADIUS;
            vel2.x *= -BOUNCE_FACTOR;
        }
        
        if(pos2.y < RADIUS) {
            pos2.y = RADIUS;
            vel2.y *= -BOUNCE_FACTOR;
        } else if(pos2.y >= ofGetHeight() - RADIUS) {
            pos2.y = ofGetHeight() - RADIUS;
            vel2.y *= -BOUNCE_FACTOR;
        }
        
        //check 4
        if(pos3.x < RADIUS) {
            pos3.x = RADIUS;
            vel3.x *= -BOUNCE_FACTOR;
        } else if(pos3.x >= ofGetWidth() - RADIUS) {
            pos3.x = ofGetWidth() - RADIUS;
            vel3.x *= -BOUNCE_FACTOR;
        }
        
        if(pos3.y < RADIUS) {
            pos3.y = RADIUS;
            vel3.y *= -BOUNCE_FACTOR;
        } else if(pos3.y >= ofGetHeight() - RADIUS) {
            pos3.y = ofGetHeight() - RADIUS;
            vel3.y *= -BOUNCE_FACTOR;
        }
        
        //check 5
        if(pos4.x < RADIUS) {
            pos4.x = RADIUS;
            vel4.x *= -BOUNCE_FACTOR;
        } else if(pos4.x >= ofGetWidth() - RADIUS) {
            pos4.x = ofGetWidth() - RADIUS;
            vel4.x *= -BOUNCE_FACTOR;
        }
        
        if(pos4.y < RADIUS) {
            pos4.y = RADIUS;
            vel4.y *= -BOUNCE_FACTOR;
        } else if(pos4.y >= ofGetHeight() - RADIUS) {
            pos4.y = ofGetHeight() - RADIUS;
            vel4.y *= -BOUNCE_FACTOR;
        }
        
        //check 6
        if(pos5.x < RADIUS) {
            pos5.x = RADIUS;
            vel5.x *= -BOUNCE_FACTOR;
        } else if(pos5.x >= ofGetWidth() - RADIUS) {
            pos5.x = ofGetWidth() - RADIUS;
            vel5.x *= -BOUNCE_FACTOR;
        }
        
        if(pos5.y < RADIUS) {
            pos5.y = RADIUS;
            vel5.y *= -BOUNCE_FACTOR;
        } else if(pos5.y >= ofGetHeight() - RADIUS) {
            pos5.y = ofGetHeight() - RADIUS;
            vel5.y *= -BOUNCE_FACTOR;
        }
        
        //check 7
        if(pos6.x < RADIUS) {
            pos6.x = RADIUS;
            vel6.x *= -BOUNCE_FACTOR;
        } else if(pos6.x >= ofGetWidth() - RADIUS) {
            pos6.x = ofGetWidth() - RADIUS;
            vel6.x *= -BOUNCE_FACTOR;
        }
        
        if(pos6.y < RADIUS) {
            pos6.y = RADIUS;
            vel6.y *= -BOUNCE_FACTOR;
        } else if(pos6.y >= ofGetHeight() - RADIUS) {
            pos6.y = ofGetHeight() - RADIUS;
            vel6.y *= -BOUNCE_FACTOR;
        }
        
        //check 8
        if(pos7.x < RADIUS) {
            pos7.x = RADIUS;
            vel7.x *= -BOUNCE_FACTOR;
        } else if(pos7.x >= ofGetWidth() - RADIUS) {
            pos7.x = ofGetWidth() - RADIUS;
            vel7.x *= -BOUNCE_FACTOR;
        }
        
        if(pos7.y < RADIUS) {
            pos7.y = RADIUS;
            vel7.y *= -BOUNCE_FACTOR;
        } else if(pos7.y >= ofGetHeight() - RADIUS) {
            pos7.y = ofGetHeight() - RADIUS;
            vel7.y *= -BOUNCE_FACTOR;
        }
        
        
        
        
        
    }
    
    //----------------------------------------------------------------
    void draw() {
        if( bDragged ){
            
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            ofPushMatrix();
            ofTranslate(pos.x, pos.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .1, ofGetFrameNum() * .9, ofGetFrameNum() * .9, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos.x,-pos.y,0);//move back by the centre offset
            star1.draw(pos.x, pos.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos1.x, pos1.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .2, 0, ofGetFrameNum() * .9, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos1.x,-pos1.y,0);//move back by the centre offset
            star2.draw(pos1.x, pos1.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos2.x, pos2.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .3, ofGetFrameNum() * .9, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos2.x,-pos2.y,0);//move back by the centre offset
            star3.draw(pos2.x, pos2.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos3.x, pos3.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .4, 0, ofGetFrameNum() * .3, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos3.x,-pos3.y,0);//move back by the centre offset
            star4.draw(pos3.x, pos3.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos4.x, pos4.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .5, ofGetFrameNum() * .2, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos4.x,-pos4.y,0);//move back by the centre offset
            star5.draw(pos4.x, pos4.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos5.x, pos5.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .6, 0, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos5.x,-pos5.y,0);//move back by the centre offset
            star6.draw(pos5.x, pos5.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos6.x, pos6.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .7, 0, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos6.x,-pos6.y,0);//move back by the centre offset
            star7.draw(pos6.x, pos6.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos7.x, pos7.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .9, 0, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos7.x,-pos7.y,0);//move back by the centre offset
            star8.draw(pos7.x, pos7.y);
            ofPopMatrix();
            ofPopMatrix();
            ofDisableAlphaBlending();
            
            
            //                ofEnableAlphaBlending();
            //                star1.draw(pos.x-RADIUS, pos.y-RADIUS, RADIUS*2,RADIUS*2);
            //                star2.draw(pos1.x, pos1.y, RADIUS,RADIUS);
            //                star3.draw(pos2.x, pos2.y, RADIUS,RADIUS);
            //                star4.draw(pos3.x, pos3.y, RADIUS,RADIUS);
            //                star5.draw(pos4.x, pos4.y, RADIUS,RADIUS);
            //                star6.draw(pos5.x, pos5.y, RADIUS,RADIUS);
            //                star7.draw(pos6.x, pos6.y, RADIUS,RADIUS);
            //                star8.draw(pos7.x, pos7.y, RADIUS,RADIUS);
            // ofDisableAlphaBlending();
        }else{
            
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            ofPushMatrix();
            ofTranslate(pos.x, pos.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .1, ofGetFrameNum() * .9, ofGetFrameNum() * .9, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos.x,-pos.y,0);//move back by the centre offset
            star1.draw(pos.x, pos.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos1.x, pos1.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .2, 0, ofGetFrameNum() * .9, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos1.x,-pos1.y,0);//move back by the centre offset
            star2.draw(pos1.x, pos1.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos2.x, pos2.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .3, ofGetFrameNum() * .9, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos2.x,-pos2.y,0);//move back by the centre offset
            star3.draw(pos2.x, pos2.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos3.x, pos3.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .4, 0, ofGetFrameNum() * .3, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos3.x,-pos3.y,0);//move back by the centre offset
            star4.draw(pos3.x, pos3.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos4.x, pos4.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .5, ofGetFrameNum() * .2, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos4.x,-pos4.y,0);//move back by the centre offset
            star5.draw(pos4.x, pos4.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos5.x, pos5.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .6, 0, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos5.x,-pos5.y,0);//move back by the centre offset
            star6.draw(pos5.x, pos5.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos6.x, pos6.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .7, 0, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos6.x,-pos6.y,0);//move back by the centre offset
            star7.draw(pos6.x, pos6.y);
            ofPopMatrix();
            ofPopMatrix();
            
            ofPushMatrix();
            ofTranslate(pos7.x, pos7.y, 0);//move pivot to centre
            ofRotate(ofGetFrameNum() * .9, 0, 0, 1);//rotate from centre
            ofPushMatrix();
            ofTranslate(-pos7.x,-pos7.y,0);//move back by the centre offset
            star8.draw(pos7.x, pos7.y);
            ofPopMatrix();
            ofPopMatrix();
            ofEnableAlphaBlending();
            
            //                star1.draw(pos.x, pos.y, RADIUS,RADIUS);
            //                star2.draw(pos1.x, pos1.y, RADIUS,RADIUS);
            //                star3.draw(pos2.x, pos2.y, RADIUS,RADIUS);
            //                star4.draw(pos3.x, pos3.y, RADIUS,RADIUS);
            //                star5.draw(pos4.x, pos4.y, RADIUS,RADIUS);
            //                star6.draw(pos5.x, pos5.y, RADIUS,RADIUS);
            //                star7.draw(pos6.x, pos6.y, RADIUS,RADIUS);
            //                star8.draw(pos7.x, pos7.y, RADIUS,RADIUS);
            ofDisableAlphaBlending();
        }
    }
    
    //----------------------------------------------------------------
    void moveTo(int x, int y) {
        
        pos.set(x, y, 0);
        vel.set(0, 0, 0);
        pos1.set(x, y, 0);
        vel1.set(0, 0, 0);
        pos2.set(x, y, 0);
        vel2.set(0, 0, 0);
        pos3.set(x, y, 0);
        vel3.set(0, 0, 0);
        pos4.set(x, y, 0);
        vel4.set(0, 0, 0);
        pos5.set(x, y, 0);
        vel5.set(0, 0, 0);
        pos6.set(x, y, 0);
        vel6.set(0, 0, 0);
        pos7.set(x, y, 0);
        vel7.set(0, 0, 0);
    }
};


#endif
