#include "ofSounds.h"


ofSounds::ofSounds(){
    
}

void ofSounds::setup(){
    //inherits basic variables from page class
    //load sounds in constructor
    //sound1.loadOgg(ofToDataPath("sounds/Theme1_Stem1.ogg"));
    
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
//    tom1.loadOgg(ofToDataPath("sounds/FX/tom1.ogg"));
//    tom2.loadOgg(ofToDataPath("sounds/FX/tom2.ogg"));
    
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

//void ofSounds::update(){
//}

float ofSounds::playSounds(float x){//left channel of music
    
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
    
    //cout << "\nMELODY FINISHED  " << bMelodyFinished << endl;
    //cout << "\nNO NO NO NO NO  " << bGuessedWrong << endl;
    //cout << "\nMELODY FINISHED  " << bMelodyFinished << endl;//debug?

    //sounds to play for guesses
    if (bGuessedWrong && bMelodyFinished) {
        //printf("BAD_LUCK SAMPLE");
        badLuck_x = badLuck.playOnce();
    } else badLuck.reset();
    
//    badLuck.getLength();//get the length to set playback to false
//    if (badLuck.position == badLuck.length){
//        bGuessedWrong = false;
//        badLuck.reset();
//    }
    
    if (showStars && bMelodyFinished) {
        //printf("CHEER SAMPLE");
        cheer_x = cheer.playOnce();
    } else cheer.reset();

    if (currentPage == 0 || currentPage == 1){
        //test
        //x = trumpetSingle.playOnce();
        //reset all audio
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
    else if (currentPage == 2){
        //sound1.reset();
        trial1_x_piano.reset();//3-56-4-x-piano-120
        trial2_trumpet.reset();//3-79-10-original-trumpet-120
        trial3_piano.reset();//8-1127-0-original-piano-120
        trial4_x_trumpet.reset();//9-622-1-x-trumpet-120

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
        x = trumpetSingle_x + pianoSingle_x + cheer_x + badLuck_x;
    }
    else if (currentPage == 3){//help bear to hear
        
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
            if(bPlayTestMelody){
                testMelody_temp = testMelodys[countMelody].playOnce();
            } //else testMelodys[countMelody].reset();
        //}
        
        x = testMelody_temp + trial1_x_piano_f + trial2_trumpet_f + cheer_x + badLuck_x;

    }
    
    else if (currentPage == 4){//trial 1 play a trumpet at end
        //sound1.reset();
        origional2Piano.reset();
        //reset practice trials
        trial1_x_piano.reset();//3-56-4-x-piano-120
        trial2_trumpet.reset();//3-79-10-original-trumpet-120
        trial3_piano.reset();//8-1127-0-original-piano-120
        trial4_x_trumpet.reset();//9-622-1-x-trumpet-120

        
        if (playTest_o1 == true) {
            origional2Trumpet_x = origional2Trumpet.playOnce();
        }
        x = origional2Trumpet_x + cheer_x + badLuck_x;
    }
    else if (currentPage == 5){//trial 2 play a piano
        //sound1.reset();
        origional2Trumpet.reset();
        if (playTest_o2 == true) {
            origional2Piano_x = trial1_x_piano.playOnce();//origional2Piano.playOnce();;
        }
        
        x = origional2Piano_x + cheer_x + badLuck_x;
    }
    
   
    //start storing the timing data from trial 3 (seen on screen)
    return x;
}


