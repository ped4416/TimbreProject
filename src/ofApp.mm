#include "ofApp.h"
#define BOUNCE_FACTOR     0.7



//--------------------------------------------------------------
void ofApp::setup(){
    
    //If you want a landscape oreintation
    ofSetOrientation(OF_ORIENTATION_90_RIGHT);

    myPage.setup();
    //mySounds.setup();
    //myHomePage.setup();
    //myIntroduction.setup();
    balls.assign(2, Ball());
    // initialize all of the Ball particles
    for(int i=0; i<balls.size(); i++){
        balls[i].init(i);
    }
        
    //setup audio Stuff
    sampleRate 			= 44100;
    initialBufferSize	= 512;

    ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);
    
    /******************** SOUND SETUP ******************************/
    //Single notes practice
    pianoSingle.loadOgg(ofToDataPath("sounds/PianoSingle.ogg"));
    trumpetSingle.loadOgg(ofToDataPath("sounds/TrumpetSingle.ogg"));
    
    //Preliminary Session 1 - 4 practice trials only (SAVE DATA?)
    //    trial1_x_piano.load(ofToDataPath("sounds/practice/3-56-4-x-piano-120.wav"));
    //    trial2_trumpet.load(ofToDataPath("sounds/practice/3-79-10-original-trumpet-120.wav"));
    //    trial3_piano.load(ofToDataPath("sounds/practice/8-1127-0-original-piano-120.wav"));
    //    trial4_x_trumpet.load(ofToDataPath("sounds/practice/9-622-1-x-trumpet-120.wav"));
    
    //Session 2 melodies 1 - 20
    origional2Trumpet.loadOgg(ofToDataPath("sounds/14-408-4-original-TrumpetEnd.ogg"));
    origional2Piano.loadOgg(ofToDataPath("sounds/14-408-4-original-PianoEnd.ogg"));
    
    //Session 3 melodies 21 - 40
    
    //fx
    cheer.load(ofToDataPath("sounds/FX/PositiveFeedback.wav"));
    badLuck.load(ofToDataPath("sounds/FX/NegativeFeedback.wav"));
    
    //load all test melodies
    testMelodysLength = 4;
    ofDirectory dir;
    int nFiles = dir.listDir("sounds/practice");
    testMelodysLength = dir.numFiles();
    if(nFiles)
    {
        testMelodys.assign(testMelodysLength,maxiSample());//needs the number of files here 9!
        for (int i = 0; i < dir.numFiles(); i++)
        {
            // add the song to the vector songs
            string filePath = dir.getPath(i);
            testMelodys[i].load(ofToDataPath(ofToString(filePath)));
        }
    } else printf("Could not find folder\n");

}

//--------------------------------------------------------------
void ofApp::update(){
    //cout << "my array is size: " << testMelodyNumber1.size() << endl;
    //cout << testMelodyNumber1[2] << endl;
    myPage.update();
//    myHomePage.update();
//    myIntroduction.update();
    //mySounds.update();
    
    //set up accelarometer calls
    vel.y += ofxAccelerometer.getForce().x*0.1;
    vel.x += ofxAccelerometer.getForce().y*0.1;
    vel1.y += ofxAccelerometer.getForce().x*0.1;
    vel1.x += ofxAccelerometer.getForce().y*0.1;
    vel2.y += ofxAccelerometer.getForce().x*0.1;
    vel2.x += ofxAccelerometer.getForce().y*0.1;
    vel3.y += ofxAccelerometer.getForce().x*0.1;
    vel3.x += ofxAccelerometer.getForce().y*0.1;
    vel4.y += ofxAccelerometer.getForce().x*0.1;
    vel4.x += ofxAccelerometer.getForce().y*0.1;
    vel5.y += ofxAccelerometer.getForce().x*0.1;
    vel5.x += ofxAccelerometer.getForce().y*0.1;
    vel6.y += ofxAccelerometer.getForce().x*0.1;
    vel6.x += ofxAccelerometer.getForce().y*0.1;
    vel7.y += ofxAccelerometer.getForce().x*0.1;
    vel7.x += ofxAccelerometer.getForce().y*0.1;
    
    
    float x;
    x = myPage.showAccelPage(1);
    
    if (x == 1) {
        
        for(int i=0; i < balls.size(); i++){
            balls[i].update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //mySounds.draw();//to allow update of variables from parent class
    //myHomePage.draw();
    //myIntroduction.draw();
    
    myPage.draw();//draw last to layer ontop of other images
    
    //display accelarometer stars
    float x;
    x = myPage.showAccelPage(1);
    
    if (x == 1) {
        
        ofPushStyle();
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        for(int i = 0; i< balls.size(); i++){
            balls[i].draw();
        }
        ofPopStyle();
    }
}

//--------------------------------------------------------------
void ofApp::audioRequested(float * output, int bufferSize, int nChannels){
    
    if( initialBufferSize != bufferSize ){
        ofLog(OF_LOG_ERROR, "your buffer size was set to %i - but the stream needs a buffer size of %i", initialBufferSize, bufferSize);
        return;
    }
    
    //setup floats to hold all sounds
    float cheer_x;
    float badLuck_x;
    float pianoSingle_x;
    float trumpetSingle_x;
    
    //Tests for first 2 / 4 then real trial starts
    float  testMelody_temp;
    float  trial1_x_piano_f;//3-56-4-x-piano-120
    float  trial2_trumpet_f;//3-79-10-original-trumpet-120
    float  trial3_piano_f;//8-1127-0-original-piano-120
    float  trial4_x_trumpet_f;//9-622-1-x-trumpet-120
    
    //real trial starts from here
    float  origional2Trumpet_x;
    float  origional2Piano_x;
    float  x2_x;
    float  origional3_x;
    float  x3_x;
    
//    //start storing the timing data from trial 3 (seen on screen)
//    return x;
    
    for (int i = 0; i < bufferSize; i++){
        float x;
        //sounds to play for guesses
        if (myPage.bGuessedWrong  && myPage.bMelodyFinished) {
            //printf("BAD_LUCK SAMPLE");
            badLuck_x = badLuck.playOnce();
        } else badLuck.reset();
        
        if (myPage.showStars && myPage.bMelodyFinished) {
            //printf("CHEER SAMPLE");
            cheer_x = cheer.playOnce();
        } else cheer.reset();
        
        if (myPage.currentPage == 0 || myPage.currentPage == 1){
            
            trial1_x_piano.reset();//3-56-4-x-piano-120
            trial2_trumpet.reset();//3-79-10-original-trumpet-120
            trial3_piano.reset();//8-1127-0-original-piano-120
            trial4_x_trumpet.reset();//9-622-1-x-trumpet-120
            
            pianoSingle.reset();
            trumpetSingle.reset();
            
            origional2Piano.reset();
            origional2Trumpet.reset();
            cheer.reset();
            badLuck.reset();
            //x = sound1.play();
        }
        
        //idividual tones
        else if (myPage.currentPage == 2){
            //sound1.reset();
            trial1_x_piano.reset();//3-56-4-x-piano-120
            trial2_trumpet.reset();//3-79-10-original-trumpet-120
            trial3_piano.reset();//8-1127-0-original-piano-120
            trial4_x_trumpet.reset();//9-622-1-x-trumpet-120
            
            pianoMelody.reset();
            trumpetMelody.reset();
            
            if (myPage.playPianoSingle == true) {
                pianoSingle_x = pianoSingle.playOnce();
                //printf("PlayPiano");
            } else pianoSingle.reset();
            
            pianoSingle.getLength();//get the length to set playback to false
            if (pianoSingle.position == pianoSingle.length - 3000){//need a plus 1 otherwise the sample is too short
                myPage.playPianoSingle = false;
                pianoSingle.reset();
            }
            
            if(myPage.playTrumpetSingle == true) {
                //printf("PlayTrumpet");
                trumpetSingle_x = trumpetSingle.playOnce();
            } else trumpetSingle.reset();
            
            trumpetSingle.getLength();//get the length to set playback to false
            if (trumpetSingle.position == pianoSingle.length - 3000){//need a plus 1 otherwise the sample is too short
                myPage.playTrumpetSingle = false;
                trumpetSingle.reset();
            }
            x = trumpetSingle_x + pianoSingle_x + cheer_x + badLuck_x;
        }
        else if (myPage.currentPage == 3){//help bear to hear
            
            //sound1.reset();
            pianoSingle.reset();
            trumpetSingle.reset();
            origional2Trumpet.reset();
            origional2Piano.reset();
            
            //        if (playPianoMelody == true) {
            //             trial1_x_piano_f = trial1_x_piano.playOnce();
            //        } else trial1_x_piano.reset();
            //
            //        pianoMelody.getLength();//get the length to set playback to false
            //        if (trial1_x_piano.position == trial1_x_piano.length){
            //            playPianoMelody = false;
            //            pianoMelody.reset();
            //        }
            //
            //        if (playTrumpetMelody == true) {
            //            trial2_trumpet_f = trial2_trumpet.playOnce();
            //        } else trial2_trumpet.reset();
            //
            //        trumpetMelody.getLength();//get the length to set playback to false
            //        if (trial2_trumpet.position == trial2_trumpet.length){
            //            playTrumpetMelody = false;
            //            trial2_trumpet.reset();
            //        }
            
            //for (int i=0; i<4; i++) {
            if(myPage.bPlayTestMelody){
                testMelody_temp = testMelodys[myPage.countMelody].playOnce();
            } //else testMelodys[countMelody].reset();
            //}
            
            x = testMelody_temp + trial1_x_piano_f + trial2_trumpet_f + cheer_x + badLuck_x;
            
        }
        
//        else if (myPage.currentPage == 4){//trial 1 play a trumpet at end
//            //sound1.reset();
//            origional2Piano.reset();
//            //reset practice trials
//            trial1_x_piano.reset();//3-56-4-x-piano-120
//            trial2_trumpet.reset();//3-79-10-original-trumpet-120
//            trial3_piano.reset();//8-1127-0-original-piano-120
//            trial4_x_trumpet.reset();//9-622-1-x-trumpet-120
//            
//            
//            if (playTest_o1 == true) {
//                origional2Trumpet_x = origional2Trumpet.playOnce();
//            }
//            x = origional2Trumpet_x + cheer_x + badLuck_x;
//        }
//        else if (currentPage == 5){//trial 2 play a piano
//            //sound1.reset();
//            origional2Trumpet.reset();
//            if (playTest_o2 == true) {
//                origional2Piano_x = trial1_x_piano.playOnce();//origional2Piano.playOnce();;
//            }
        
 //           x = origional2Piano_x + cheer_x + badLuck_x;
  //      }

    
        output[i*nChannels    ] = x;//left out
        output[i*nChannels + 1] = x;//right out
    }
    
}

//--------------------------------------------------------------
void ofApp::audioReceived(float * input, int bufferSize, int nChannels){
    
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    
    //print out touch data
    //ofLog(OF_LOG_VERBOSE, "touch %d down at (%d,%d)", touch.id, touch.x, touch.y);
    //cout << "Touch Position Is ... " << touch << endl;
    
    balls[touch.id].moveTo(touch.x, touch.y);
    balls[touch.id].bDragged = true;
    myPage.showPage(touch.x, touch.y);
    //mySounds.showPage(touch.x, touch.y);
    
    
    //myHomePage.showPage(touch.x, touch.y);
    //myIntroduction.showPage(touch.x, touch.y);
    //inheritance bug with vector arrays stopped showPage being inheritable
//    mySounds.touchSounds(touch.x, touch.y);
//    myHomePage.touchHome(touch.x, touch.y);
//    myIntroduction.touchIntro(touch.x, touch.y);
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
    //ofLog(OF_LOG_VERBOSE, "touch %d moved at (%d,%d)", touch.id, touch.x, touch.y);
    balls[touch.id].moveTo(touch.x, touch.y);
    balls[touch.id].bDragged = true;

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d up at (%d,%d)", touch.id, touch.x, touch.y);
    balls[touch.id].bDragged = false;
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}

