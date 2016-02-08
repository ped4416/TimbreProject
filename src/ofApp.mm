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
    
    /******************** APP AUDIO SETUP ******************************/
    //Single notes practice
    pianoSingle.loadOgg(ofToDataPath("sounds/PianoSingle.ogg"));
    trumpetSingle.loadOgg(ofToDataPath("sounds/TrumpetSingle.ogg"));
    
    //fx
    cheer.load(ofToDataPath("sounds/FX/PositiveFeedback.wav"));
    badLuck.load(ofToDataPath("sounds/FX/NegativeFeedback.wav"));
    
    //load all practice melodies
    testMelodysLength = 4;
    ofDirectory dir;
    int nFiles = dir.listDir("sounds/practice");
    testMelodysLength = dir.numFiles();
    if(nFiles)
    {
        testMelodys_v.assign(testMelodysLength,maxiSample());
        for (int i = 0; i < dir.numFiles(); i++)
        {
            // add the song to the vector songs
            string filePath = dir.getPath(i);
            testMelodys_v[i].load(ofToDataPath(ofToString(filePath)));
        }
    } else printf("Could not find folder Trials\n");
    
    //load all session A melodies
    sessionA_MelodysLength = 20;
    ofDirectory dir2;
    int nFiles2 = dir2.listDir("sounds/sessionA");
    sessionA_MelodysLength = dir2.numFiles();
    if(nFiles2)
    {
        sessionA_Melodys_v.assign(sessionA_MelodysLength,maxiSample());
        for (int i = 0; i < dir2.numFiles(); i++)
        {
            // add the song to the vector songs
            string filePath2 = dir2.getPath(i);
            sessionA_Melodys_v[i].load(ofToDataPath(ofToString(filePath2)));
        }
    } else printf("Could not find folder Session A\n");
    
    //load all session B melodies
    sessionB_MelodysLength = 20;
    ofDirectory dir3;
    int nFiles3 = dir3.listDir("sounds/sessionB");
    sessionB_MelodysLength = dir3.numFiles();
    if(nFiles3)
    {
        sessionB_Melodys_v.assign(sessionB_MelodysLength,maxiSample());
        for (int i = 0; i < dir3.numFiles(); i++)
        {
            // add the song to the vector songs
            string filePath3 = dir3.getPath(i);
            sessionB_Melodys_v[i].load(ofToDataPath(ofToString(filePath3)));
        }
    } else printf("Could not find folder Session B\n");

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
    float practiceMelody_temp;
    float trialMelodies_temp;

    
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
        
        if (myPage.currentPage == 0){
            
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
        else if (myPage.currentPage == 1 || myPage.currentPage == 2){
            
            for (int i=0; i<4; i++) {
                testMelodys_v[i].reset();
            }
            
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
        else if (myPage.currentPage == 3){//practice session x 4 || 2?
            //reset session files
            for (int i=0; i<20; i++) {
                sessionA_Melodys_v[i].reset();
                sessionB_Melodys_v[i].reset();
            }
            
            pianoSingle.reset();
            trumpetSingle.reset();

            if(myPage.bPlayPracticeMelody){
                practiceMelody_temp = testMelodys_v[myPage.practice_melody_v[myPage.practice_count]].playOnce();
            }
            else if(myPage.bPlayGroupBMelody){
                for (int i=0; i<4; i++) {
                    testMelodys_v[i].reset();
                }
            }
            x = practiceMelody_temp + cheer_x + badLuck_x;
        }
        
        else if (myPage.currentPage >= 4)//&& myPage.currentPage <= 23){//trial 1 - 20
        {
            //reset practice trials
            for (int i=0; i<4; i++) {
                testMelodys_v[i].reset();
            }
            
            if(myPage.bPlayGroupAMelody == false){
                for (int i=0; i<20; i++) {
                    sessionA_Melodys_v[i].reset();
                }
            }
            if(myPage.bPlayGroupBMelody == false){
                for (int i=0; i<20; i++) {
                    sessionB_Melodys_v[i].reset();
                }
            }

            pianoSingle.reset();
            trumpetSingle.reset();
            
//            sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].getLength();//get the length to set playback to false
//            if (sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].position == sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].length){
//                myPage.bPlayGroupAMelody = false;
//                sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].reset();
//            }
//            
//            sessionB_Melodys_v[myPage.trialMelody_2_v[myPage.trial_melody_count]].getLength();//get the length to set playback to false
//            if (sessionB_Melodys_v[myPage.trialMelody_2_v[myPage.trial_melody_count]].position == sessionA_Melodys_v[myPage.trialMelody_2_v[myPage.trial_melody_count]].length){
//                myPage.bPlayGroupBMelody = false;
//                sessionB_Melodys_v[myPage.trialMelody_2_v[myPage.trial_melody_count]].reset();
//            }
    
            if(myPage.bPlayGroupAMelody){
                trialMelodies_temp = sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].playOnce();
            }
            else if(myPage.bPlayGroupBMelody == true){
                trialMelodies_temp = sessionB_Melodys_v[myPage.trialMelody_2_v[myPage.trial_melody_count]].playOnce();
            }
            x = trialMelodies_temp + cheer_x + badLuck_x;
        }
        
        else if (myPage.currentPage == 24){//trial 1 - 20
            //reset session trials
            for (int i=0; i<20; i++) {
                sessionA_Melodys_v[i].reset();
                sessionB_Melodys_v[i].reset();
            }
            
            
            x = trialMelodies_temp + cheer_x + badLuck_x;
        }
    
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

