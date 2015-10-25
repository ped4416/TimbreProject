
#include "ofPage.h"
#include "ofSounds.h"


ofSounds::ofSounds(){
    
}

void ofSounds::setup(){
    //inherits basic variables from page class
    //load sounds in constructor
    sound1.loadOgg(ofToDataPath("sounds/Theme1_Stem1.ogg"));
    origional1.loadOgg(ofToDataPath("sounds/3-56-4-original.ogg"));
    x1.loadOgg(ofToDataPath("sounds/3-56-4-x.ogg"));
    
    //Preliminary Session 1 - 4 practice trials only (SAVE DATA?)
    pianoSingle.loadOgg(ofToDataPath("sounds/PianoSingle.ogg"));
    trumpetSingle.loadOgg(ofToDataPath("sounds/TrumpetSingle.ogg"));
    pianoMelody.loadOgg(ofToDataPath("sounds/PianoMelody.ogg"));
    trumpetMelody.loadOgg(ofToDataPath("sounds/TrumpetMelody.ogg"));
    
    //Session 2 melodies 1 - 20
    origional2Trumpet.loadOgg(ofToDataPath("sounds/14-408-4-original-TrumpetEnd.ogg"));
    origional2Piano.loadOgg(ofToDataPath("sounds/14-408-4-original-PianoEnd.ogg"));
    
    //Session 3 melodies 21 - 40
    
    
    
    //fx
    cheer.loadOgg(ofToDataPath("sounds/FX/CrowdCheer.ogg"));
    badLuck.loadOgg(ofToDataPath("sounds/FX/PartyblowerSad.ogg"));
    tom1.loadOgg(ofToDataPath("sounds/FX/tom1.ogg"));
    tom2.loadOgg(ofToDataPath("sounds/FX/tom2.ogg"));
    
}

void ofSounds::update(){
}

float ofSounds::playSounds(float x){//let channel of music
    
    //setup floats to hold all sounds
    float tom1_x;
    float tom2_x;
    float cheer_x;
    float badLuck_x;
    float pianoSingle_x;
    float trumpetSingle_x;
    float pianoMelody_x;
    float trumpetMelody_x;
    
    //Tests for first 2 then real trial starts
    float  origional1_x;
    float  x1_x;
    
    //real trial starts from here
    float  origional2Trumpet_x;
    float  origional2Piano_x;
    float  x2_x;
    float  origional3_x;
    float  x3_x;
    
    //cout << "\nMELODY FINISHED  " << bMelodyFinished << endl;
    //cout << "\nNO NO NO NO NO  " << bGuessedWrong << endl;
    //cout << "\nMELODY FINISHED  " << bMelodyFinished << endl;//debug?

    //sounds to play for guesses
    if (bGuessedWrong == true){// && bMelodyFinished) {
        //printf("BAD_LUCK SAMPLE");
        badLuck_x = badLuck.playOnce();
    } else badLuck.reset();
    
//    badLuck.getLength();//get the length to set playback to false
//    if (badLuck.position == badLuck.length){
//        bGuessedWrong = false;
//        badLuck.reset();
//    }
    
    if (showStars == true){//&& bMelodyFinished) {
        //printf("CHEER SAMPLE");
        cheer_x = cheer.playOnce();
    } else cheer.reset();
    
    if (tom1play == true) {
        tom1_x = tom1.playOnce();
    } else tom1.reset();
    
    if (tom2play == true) {
        tom2_x = tom2.playOnce();
    } else tom2.reset();
    
//    cheer.getLength();//get the length to set playback to false
//    if (cheer.position == cheer.length){
//        //showStars = false;
//        cheer.reset();
//    }
    
    tom1.getLength();//get the length to set playback to false
    if (tom1.position == 3000){
         tom1play = false;
         tom1.reset();
    }
    
    tom2.getLength();//get the length to set playback to false
    if (tom2.position == 3000){
        tom2play = false;
        tom2.reset();
    }

    if (currentPage == 0 || currentPage == 1){
       
        //test
        //x = trumpetSingle.playOnce();
        origional1.reset();//reset all the audio files
        x1.reset();
        pianoSingle.reset();
        trumpetSingle.reset();
        origional2Piano.reset();
        origional2Trumpet.reset();
        cheer.reset();
        badLuck.reset();
        x = sound1.play();
    }
    
    //idividual tones
    else if (currentPage == 2){
        sound1.reset();
        origional1.reset();
        x1.reset();
        pianoMelody.reset();
        trumpetMelody.reset();
        
        if (playPianoSingle == true) {
            pianoSingle_x = pianoSingle.playOnce();
            //printf("PlayPiano");
        } else pianoSingle.reset();
        
        pianoSingle.getLength();//get the length to set playback to false
        if (pianoSingle.position == pianoSingle.length - 3000){//need a plus 1 otherwise the sample is too short
            playPianoSingle = false;
            pianoSingle.reset();
        }
        
        if(playTrumpetSingle == true) {
            //printf("PlayTrumpet");
            trumpetSingle_x = trumpetSingle.playOnce();
        } else trumpetSingle.reset();
        
        trumpetSingle.getLength();//get the length to set playback to false
        if (trumpetSingle.position == pianoSingle.length - 3000){//need a plus 1 otherwise the sample is too short
            playTrumpetSingle = false;
            trumpetSingle.reset();
        }
        x = trumpetSingle_x + pianoSingle_x + cheer_x + badLuck_x + tom1_x + tom2_x;
    }
    else if (currentPage == 3){//help bear to hear
        sound1.reset();
        pianoSingle.reset();
        trumpetSingle.reset();
        origional2Trumpet.reset();
        origional2Piano.reset();
      
        
        if (playPianoMelody == true) {
             pianoMelody_x = pianoMelody.playOnce();
        } else pianoMelody.reset();
        
        pianoMelody.getLength();//get the length to set playback to false
        if (pianoMelody.position == pianoMelody.length){
            playPianoMelody = false;
            pianoMelody.reset();
        }
        
        if (playTrumpetMelody == true) {
            trumpetMelody_x = trumpetMelody.playOnce();
        } else trumpetMelody.reset();
        
        trumpetMelody.getLength();//get the length to set playback to false
        if (trumpetMelody.position == trumpetMelody.length){
            playTrumpetMelody = false;
            trumpetMelody.reset();
        }
        
        x = trumpetMelody_x + pianoMelody_x + cheer_x + badLuck_x + tom1_x +tom2_x;
      
    }
    
    else if (currentPage == 4){//trial 1 play a trumpet at end
        sound1.reset();
        origional2Piano.reset();
        x1.reset();
        
        if (playTest_o1 == true) {
            origional2Trumpet_x = origional2Trumpet.playOnce();
        }
        x = origional2Trumpet_x + cheer_x + badLuck_x + tom1_x + tom2_x;
    }
    else if (currentPage == 5){//trial 2 play a piano
        sound1.reset();
        origional2Trumpet.reset();
        if (playTest_o2 == true) {
            origional2Piano_x = origional2Piano.playOnce();;
        }
        
        x = origional2Piano_x + cheer_x + badLuck_x + tom1_x + tom2_x;
    }
    
   
    //start storing the timing data from trial 3 (seen on screen)
    return x;
}


