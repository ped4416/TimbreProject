/*--------------------------------------------------------------
 This app is created for a music perception project looking at musical expectance in children aged 4
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
 

 
*/
#include "ofApp.h"
#define BOUNCE_FACTOR     0.7



//--------------------------------------------------------------
void ofApp::setup(){
    
    //If you want a landscape oreintation
    ofSetOrientation(OF_ORIENTATION_90_RIGHT);
    //ofSetOrientation(OF_ORIENTATION_DEFAULT);

    myPage.setup();
    //mySounds.setup();
    //myHomePage.setup();
    //myIntroduction.setup();
    userID_s = "Anonymous";
    user_age_s = "None";
    
    save_time_s = "";
    save_date_s = "";
    
    bPermitSaveFile = true;//set to true permitting a save of the file within the update method to run once and save the file.
    bSelectUser = false;
    bSelectAge = false;
    
    balls.assign(2, Ball());
    // initialize all of the Ball particles
    for(int i=0; i<balls.size(); i++){
        balls[i].init(i);
    }
        
    //setup audio Stuff
    sampleRate 			= 44100;
    initialBufferSize	= 512;
    
    keyboard = new ofxiOSKeyboard(2,40,320,32);
    keyboard->setVisible(true);
    keyboard->setBgColor(255, 255, 255, 255);
    keyboard->setFontColor(0,0,0, 255);
    keyboard->setFontSize(26);
    
    //font setup

    keyboard_f.loadFont("fonts/Georgia.ttf", 22);
    keyboard_f.setLineHeight(18.0f);
    keyboard_f.setLetterSpacing(1.037);

    ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);
    
    /******************** APP AUDIO SETUP ******************************/
    //Single notes practice
    pianoSingle.loadOgg(ofToDataPath("sounds/PianoSingle.ogg"));
    trumpetSingle.loadOgg(ofToDataPath("sounds/TrumpetSingle.ogg"));
    
    //fx
    cheer.load(ofToDataPath("sounds/FX/PositiveFeedback.wav"));
    badLuck.load(ofToDataPath("sounds/FX/NegativeFeedback.wav"));
    
    //load all practice melodies
    testMelodys_A_Length = 2;
    ofDirectory dir;
    int nFiles = dir.listDir("sounds/practiceA");
    testMelodys_A_Length = dir.numFiles();
    if(nFiles)
    {
        testMelodys_A_v.assign(testMelodys_A_Length,maxiSample());
        for (int i = 0; i < dir.numFiles(); i++)
        {
            // add the song to the vector songs
            string filePath = dir.getPath(i);
            testMelodys_A_v[i].load(ofToDataPath(ofToString(filePath)));
        }
    } else printf("Could not find folder Trials\n");
    
    testMelodys_B_Length = 2;
    ofDirectory dir1;
    int nFiles1 = dir1.listDir("sounds/practiceB");
    testMelodys_B_Length = dir1.numFiles();
    if(nFiles1)
    {
        testMelodys_B_v.assign(testMelodys_B_Length,maxiSample());
        for (int i = 0; i < dir1.numFiles(); i++)
        {
            // add the song to the vector songs
            string filePath1 = dir1.getPath(i);
            testMelodys_B_v[i].load(ofToDataPath(ofToString(filePath1)));
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
    
    /*======================== Variable arrays setup ======================= */
    
    ap1="ap1"; ap2="ap2"; a1="a1"; a2="a2"; a3="a3"; a4="a4"; a5="a5"; a6="a6"; a7="a7"; a8="a8"; a9="a9"; a10="a10"; a11="a11"; a12="a12"; a13="a13"; a14="a14"; a15="a15"; a16="a16"; a17="a17"; a18="a18"; a19="a19"; a20="a20"; bp1="bp1"; bp2="bp2"; b1="b1"; b2="b2"; b3="b3"; b4="b4"; b5="b5"; b6="b6"; b7="b7"; b8="b8"; b9="b9"; b10="b10"; b11="b11"; b12="b12"; b13="b13"; b14="b14"; b15="b15"; b16="b16"; b17="b17"; b18="b18"; b19="b19"; b20="b20";
    
    base_1="8-321-2-original"; base_2="9-622-1-x"; base_3="1-48-3-original"; base_4="10-144-1-original"; base_5="14-225-4-original"; base_6="23-36-4-original"; base_7="25-14-7-original"; base_8="1-117-8-x"; base_9="12-584-6-x"; base_10="14-161-5-x"; base_11="14-408-4-x"; base_12="25-368-1-x"; base_13="11-61-5-original"; base_14="8-1556-3-original"; base_15="15-35-2-original"; base_16="24-118-7-original"; base_17="8-1025-1-original"; base_18="8-97-1-x"; base_19="12-584-5-x"; base_20="24-247-2-x"; base_21="25-442-3-x"; base_22="8-1025-5-x"; base_23="3-56-4-x"; base_24="3-79-10-original"; base_25="3-79-11-original"; base_26="7-130-4-original"; base_27="14-246-1-original"; base_28="8-504-1-original"; base_29="8-994-3-original"; base_30="25-442-1-x"; base_31="9-232-11-x"; base_32="7-164-2-x"; base_33="8-1035-1-x"; base_34="8-1251-6-x"; base_35="8-1467-0-original"; base_36="8-499-3-original"; base_37="8-756-0-original"; base_38="9-147-11-original"; base_39="9-673-1-original"; base_40="8-1467-4-x"; base_41="8-1505-4-x"; base_42="8-876-1-x"; base_43="13-3-3-x"; base_44="8-973-5-x";
    
    filename_1="8-321-1-original-piano-120.wav"; filename_2="9-622-1-x-trumpet-120.wav"; filename_3="1-48-3-original-piano-120.wav"; filename_4="10-144-1-original-piano-120.wav"; filename_5="14-225-4-original-piano-120.wav"; filename_6="23-36-4-original-piano-120.wav"; filename_7="25-14-7-original-piano-120.wav"; filename_8="1-117-8-x-piano-120.wav"; filename_9="12-584-6-x-piano-120.wav"; filename_10="14-161-5-x-piano-120.wav"; filename_11="14-408-4-x-piano-120.wav"; filename_12="25-368-1-x-piano-120.wav"; filename_13="11-61-5-original-trumpet-120.wav"; filename_14="8-1556-3-original-trumpet-120.wav"; filename_15="15-35-2-original-trumpet-120.wav"; filename_16="24-118-7-original-trumpet-120.wav"; filename_17="8-1025-1-original-trumpet-120.wav"; filename_18="8-97-1-x-trumpet-120.wav"; filename_19="12-584-5-x-trumpet-120.wav"; filename_20="24-247-2-x-trumpet-120.wav"; filename_21="25-442-3-x-trumpet-120.wav"; filename_22="8-1025-5-x-trumpet-120.wav"; filename_23="3-56-4-x-piano-120.wav"; filename_24="3-79-10-original-trumpet-120.wav"; filename_25="3-79-11-original-piano-120.wav"; filename_26="7-130-4-original-piano-120.wav"; filename_27="14-246-1-original-piano-120.wav"; filename_28="8-504-1-original-piano-120.wav"; filename_29="8-994-3-original-piano-120.wav"; filename_30="25-442-1-x-piano-120.wav"; filename_31="9-232-11-x-piano-120.wav"; filename_32="7-164-2-x-piano-120.wav"; filename_33="8-1035-1-x-piano-120.wav"; filename_34="8-1251-6-x-piano-120.wav"; filename_35="8-1467-0-original-trumpet-120.wav"; filename_36="8-499-3-original-trumpet-120.wav"; filename_37="8-756-0-original-trumpet-120.wav"; filename_38="9-147-11-original-trumpet-120.wav"; filename_39="9-673-1-original-trumpet-120.wav"; filename_40="8-1467-4-x-trumpet-120.wav"; filename_41="8-1505-4-x-trumpet-120.wav"; filename_42="8-876-1-x-trumpet-120.wav"; filename_43="13-3-3-x-trumpet-120.wav"; filename_44="8-973-5-x-trumpet-120.wav";
    session_A="A"; session_B="B"; practice_yes="Yes"; practice_no="No"; timbre_piano="piano"; timbre_trumpet="trumpet"; probability_high="high"; probability_low="low"; pitch_interval_small="small"; pitch_interval_large="large"; interval_direction_descending="descending"; interval_direction_ascending="ascending", correct = "correct", wrong = "wrong";
   
    //set the variable array sizes
    //Practice Session A
    practice_time_data_A_v.resize(2);//store practice timestamps - only store 2 no replacment permitted now
    number_practice_A_v.resize(2);
    ID_practice_A_v.resize(2);
    session_practice_A_v.resize(2);
    practice_practice_A_v.resize(2);
    timbre_practice_A_v.resize(2);
    probability_practice_A_v.resize(2);
    basename_practice_A_v.resize(2);
    filename_practice_A_v.resize(2);
    pitch_practice_A_v.resize(2);
    pitch_interval_practice_A_v.resize(2);
    interval_size_practice_A_v.resize(2);
    interval_direction_practice_A_v.resize(2);
    information_content_practice_A_v.resize(2);
    probe_repetitions_practice_A_v.resize(2);
    probe_octave_repetitions_practice_A_v.resize(2);
    practice_answer_A_v.resize(2);
    
    //Practice session B
    practice_time_data_B_v.resize(2);//store practice timestamps - only store 2 no replacment permitted now
    number_practice_B_v.resize(2);
    ID_practice_B_v.resize(2);
    session_practice_B_v.resize(2);
    practice_practice_B_v.resize(2);
    timbre_practice_B_v.resize(2);
    probability_practice_B_v.resize(2);
    basename_practice_B_v.resize(2);
    filename_practice_B_v.resize(2);
    pitch_practice_B_v.resize(2);
    pitch_interval_practice_B_v.resize(2);
    interval_size_practice_B_v.resize(2);
    interval_direction_practice_B_v.resize(2);
    information_content_practice_B_v.resize(2);
    probe_repetitions_practice_B_v.resize(2);
    probe_octave_repetitions_practice_B_v.resize(2);
    practice_answer_B_v.resize(2);
    
    //A SESSION
    trial_time_data_A_v.resize(20);//store timestamps from USER allow multiple tries of each index
    number_A_v.resize(20);
    ID_A_v.resize(20);
    session_A_v.resize(20);
    practice_A_v.resize(20);
    timbre_A_v.resize(20);
    probability_A_v.resize(20);
    basename_A_v.resize(20);
    filename_A_v.resize(20);
    pitch_A_v.resize(20);
    pitch_interval_A_v.resize(20);
    interval_size_A_v.resize(20);
    interval_direction_A_v.resize(20);
    information_content_A_v.resize(20);
    probe_repetitions_A_v.resize(20);
    probe_octave_repetitions_A_v.resize(20);
    trial_answer_A_v.resize(20);
    
    //B SESSION
    trial_time_data_B_v.resize(20);//store timestamps from USER allow multiple tries of each index
    number_B_v.resize(20);
    ID_B_v.resize(20);
    session_B_v.resize(20);
    practice_B_v.resize(20);
    timbre_B_v.resize(20);
    probability_B_v.resize(20);
    basename_B_v.resize(20);
    filename_B_v.resize(20);
    pitch_B_v.resize(20);
    pitch_interval_B_v.resize(20);
    interval_size_B_v.resize(20);
    interval_direction_B_v.resize(20);
    information_content_B_v.resize(20);
    probe_repetitions_B_v.resize(20);
    probe_octave_repetitions_B_v.resize(20);
    trial_answer_B_v.resize(20);
    
    //Final arrays ready to print out to file allow for 44 elements!
    userID_v.resize(44);//fill the whole array with ID
    user_age_v.resize(44);//fill the whole array with age of user in months
    session_number_v.resize(44);//A1, A2, B1 or B2 - //fill the whole array with correct user choice
    session_order_v.resize(44);//AB or BA - //fill the whole array with correct choice
    date_v.resize(44);//fill the whole array with current date
    time_v.resize(44);//fill the array with the exact time that each question is answered
    piano_left_v.resize(44);//true or false
    reaction_time_v.resize(44);
    number_v.resize(44);
    ID_v.resize(44);
    session_v.resize(44);
    practice_v.resize(44);
    timbre_v.resize(44);
    probability_v.resize(44);
    basename_v.resize(44);
    filename_v.resize(44);
    pitch_v.resize(44);
    pitch_interval_v.resize(44);
    interval_size_v.resize(44);
    interval_direction_v.resize(44);
    information_content_v.resize(44);
    probe_repetitions_v.resize(44);
    probe_octave_repetitions_v.resize(44);
    answer_v.resize(44);
    
    
    /*====================== A SESSION PRACTICE SESSIONS =========================*/
    
    for (int i = 0; i< myPage.practiceMelody_1_v.size(); i++)
    {
        if (myPage.practiceMelody_1_v[i]==0)//ellement 0
        {
            number_practice_A_v[i] = 1;
            ID_practice_A_v[i] = ap1;
            session_practice_A_v[i] = session_A;
            practice_practice_A_v[i] = practice_yes;
            timbre_practice_A_v[i] = timbre_piano;
            probability_practice_A_v[i] = probability_high;
            basename_practice_A_v[i] = base_1;
            filename_practice_A_v[i] = filename_1;
            pitch_practice_A_v[i] = 67;
            pitch_interval_practice_A_v[i] = -2;
            interval_size_practice_A_v[i] = pitch_interval_small;
            interval_direction_practice_A_v[i] = interval_direction_descending;
            information_content_practice_A_v[i] = 1.034;
            probe_repetitions_practice_A_v[i] = 0;
            probe_octave_repetitions_practice_A_v[i] = 0;
        } else if(myPage.practiceMelody_1_v[i]==1)//ellement 1
        {
            number_practice_A_v[i] = 2;
            ID_practice_A_v[i] = ap2;
            session_practice_A_v[i] = session_A;
            practice_practice_A_v[i] = practice_yes;
            timbre_practice_A_v[i] = timbre_trumpet;
            probability_practice_A_v[i] = probability_low;
            basename_practice_A_v[i] = base_2;
            filename_practice_A_v[i] = filename_2;
            pitch_practice_A_v[i] = 64;
            pitch_interval_practice_A_v[i] = -10;
            interval_size_practice_A_v[i] = pitch_interval_large;
            interval_direction_practice_A_v[i] = interval_direction_descending;
            information_content_practice_A_v[i] = 12.633;
            probe_repetitions_practice_A_v[i] = 0;
            probe_octave_repetitions_practice_A_v[i] = 0;
        }
        
//        //print out array contents for practice trials
//        for(int i = 0; i < number_practice_v.size(); i++){
            cout << "Practice Number ID = " << number_practice_A_v[i] << endl;
            cout << "Practice ID CHAR = " << ID_practice_A_v[i] << endl;
            cout << "Practice Session = " << session_practice_A_v[i] << endl;
            cout << "Practice Pracitce? " << practice_practice_A_v[i] << endl;
            cout << "Practice TIMBRE = " << timbre_practice_A_v[i] << endl;
            cout << "Practice Probabilitiy = " << probability_practice_A_v[i] << endl;
            cout << "Practice basename = " << basename_practice_A_v[i] << endl;
            cout << "Practice filename = " << filename_practice_A_v[i] << endl;
            cout << "Practice pitch = " << pitch_practice_A_v[i] << endl;
            cout << "Practice pitch interval = " << pitch_interval_practice_A_v[i] << endl;
            cout << "Practice interval size = " << interval_size_practice_A_v[i] << endl;
            cout << "Practice interval direction = " << interval_direction_practice_A_v[i] << endl;
            cout << "Practice information content = " << information_content_practice_A_v[i] << endl;
            cout << "Practice probe repetitions = " << probe_repetitions_practice_A_v[i] << endl;
            cout << "Practice probe octave repetitions = " << probe_octave_repetitions_practice_A_v[i] << endl;
        //}

    }
        
    /*====================== B SESSION PRACTICE SESSIONS =========================*/
    for (int i = 0; i< myPage.practiceMelody_2_v.size(); i++)
    {
        if(myPage.practiceMelody_2_v[i]==0)//ellement 0
        {
            number_practice_B_v[i] = 23;
            ID_practice_B_v[i] = bp1;
            session_practice_B_v[i] = session_B;
            practice_practice_B_v[i] = practice_yes;
            timbre_practice_B_v[i] = timbre_piano;
            probability_practice_B_v[i] = probability_low;
            basename_practice_B_v[i] = base_23;
            filename_practice_B_v[i] = filename_23;
            pitch_practice_B_v[i] = 81;
            pitch_interval_practice_B_v[i] = 4;
            interval_size_practice_B_v[i] = pitch_interval_small;
            interval_direction_practice_B_v[i] = interval_direction_ascending;
            information_content_practice_B_v[i] = 12.843;
            probe_repetitions_practice_B_v[i] = 0;
            probe_octave_repetitions_practice_B_v[i] = 0;
            
        } else if(myPage.practiceMelody_2_v[i]==1)//ellement 1
        {
            number_practice_B_v[i] = 24;
            ID_practice_B_v[i] = bp2;
            session_practice_B_v[i] = session_B;
            practice_practice_B_v[i] = practice_yes;
            timbre_practice_B_v[i] = timbre_trumpet;
            probability_practice_B_v[i] = probability_high;
            basename_practice_B_v[i] = base_24;
            filename_practice_B_v[i] = filename_24;
            pitch_practice_B_v[i] = 67;
            pitch_interval_practice_B_v[i] = -2;
            interval_size_practice_B_v[i] = pitch_interval_small;
            interval_direction_practice_B_v[i] = interval_direction_descending;
            information_content_practice_B_v[i] = 1.658;
            probe_repetitions_practice_B_v[i] = 0;
            probe_octave_repetitions_practice_B_v[i] = 0;
        }
        //        //print out array contents for practice trials
        //        for(int i = 0; i < number_practice_B_v.size(); i++){
        cout << "Practice Number ID = " << number_practice_B_v[i] << endl;
        cout << "Practice ID CHAR = " << ID_practice_B_v[i] << endl;
        cout << "Practice Session = " << session_practice_B_v[i] << endl;
        cout << "Practice Pracitce? " << practice_practice_B_v[i] << endl;
        cout << "Practice TIMBRE = " << timbre_practice_B_v[i] << endl;
        cout << "Practice Probabilitiy = " << probability_practice_B_v[i] << endl;
        cout << "Practice basename = " << basename_practice_B_v[i] << endl;
        cout << "Practice filename = " << filename_practice_B_v[i] << endl;
        cout << "Practice pitch = " << pitch_practice_B_v[i] << endl;
        cout << "Practice pitch interval = " << pitch_interval_practice_B_v[i] << endl;
        cout << "Practice interval size = " << interval_size_practice_B_v[i] << endl;
        cout << "Practice interval direction = " << interval_direction_practice_B_v[i] << endl;
        cout << "Practice information content = " << information_content_practice_B_v[i] << endl;
        cout << "Practice probe repetitions = " << probe_repetitions_practice_B_v[i] << endl;
        cout << "Practice probe octave repetitions = " << probe_octave_repetitions_practice_B_v[i] << endl;
        //}

    }

    
    /*====================== A MELODY TRIALS =========================*/
    //array if A melodies are playing
    for (int i = 0; i< myPage.trialMelody_1_v.size(); i++) {//ellement 0
        if (myPage.trialMelody_1_v[i]==0) {
            number_A_v[i] = 3;
            ID_A_v[i] = a1;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_3;
            filename_A_v[i] = filename_3;
            pitch_A_v[i] = 74;
            pitch_interval_A_v[i] = 1;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 0.313;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 1;
        } else if(myPage.trialMelody_1_v[i]==1) {//ellement 1
            number_A_v[i] = 4;
            ID_A_v[i] = a2;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_4;
            filename_A_v[i] = filename_4;
            pitch_A_v[i] = 69;
            pitch_interval_A_v[i] = 2;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 1.539;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==2) {//ellement 2
            number_A_v[i] = 5;
            ID_A_v[i] = a3;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_5;
            filename_A_v[i] = filename_5;
            pitch_A_v[i] = 65;
            pitch_interval_A_v[i] = -2;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 1.187;
            probe_repetitions_A_v[i] = 2;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==3) {//ellement 3
            number_A_v[i] = 6;
            ID_A_v[i] = a4;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_6;
            filename_A_v[i] = filename_6;
            pitch_A_v[i] = 67;
            pitch_interval_A_v[i] = 0;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 1.769;
            probe_repetitions_A_v[i] = 2;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==4) {//ellement 4
            number_A_v[i] = 7;
            ID_A_v[i] = a5;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_7;
            filename_A_v[i] = filename_7;
            pitch_A_v[i] = 71;
            pitch_interval_A_v[i] = 2;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 2.334;
            probe_repetitions_A_v[i] = 2;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==5) {//ellement 5
            number_A_v[i] = 8;
            ID_A_v[i] = a6;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_8;
            filename_A_v[i] = filename_8;
            pitch_A_v[i] = 65;
            pitch_interval_A_v[i] = -4;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 10.694;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==6) {//ellement 6
            number_A_v[i] = 9;
            ID_A_v[i] = a7;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_9;
            filename_A_v[i] = filename_9;
            pitch_A_v[i] = 78;
            pitch_interval_A_v[i] = 4;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 13.478;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==7) {//ellement 7
            number_A_v[i] = 10;
            ID_A_v[i] = a8;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_10;
            filename_A_v[i] = filename_10;
            pitch_A_v[i] = 77;
            pitch_interval_A_v[i] = 6;
            interval_size_A_v[i] = pitch_interval_large;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 12.199;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==8) {//ellement 8
            number_A_v[i] = 11;
            ID_A_v[i] = a9;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_11;
            filename_A_v[i] = filename_11;
            pitch_A_v[i] = 73;
            pitch_interval_A_v[i] = 1;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 10.179;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==9) {//ellement 9
            number_A_v[i] = 12;
            ID_A_v[i] = a10;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_piano;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_12;
            filename_A_v[i] = filename_12;
            pitch_A_v[i] = 73;
            pitch_interval_A_v[i] = -1;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 9.846;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==10) {//ellement 10
            number_A_v[i] = 13;
            ID_A_v[i] = a11;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_13;
            filename_A_v[i] = filename_13;
            pitch_A_v[i] = 65;
            pitch_interval_A_v[i] = -2;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 1.461;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==11) {//ellement 11
            number_A_v[i] = 14;
            ID_A_v[i] = a12;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_14;
            filename_A_v[i] = filename_14;
            pitch_A_v[i] = 69;
            pitch_interval_A_v[i] = -3;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 3.062;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==12) {//ellement 12
            number_A_v[i] = 15;
            ID_A_v[i] = a13;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_15;
            filename_A_v[i] = filename_15;
            pitch_A_v[i] = 62;
            pitch_interval_A_v[i] = 0;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 1.927;
            probe_repetitions_A_v[i] = 1;
            probe_octave_repetitions_A_v[i] = 1;
        } else if(myPage.trialMelody_1_v[i]==13) {//ellement 13
            number_A_v[i] = 16;
            ID_A_v[i] = a14;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_16;
            filename_A_v[i] = filename_16;
            pitch_A_v[i] = 74;
            pitch_interval_A_v[i] = 0;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 1.732;
            probe_repetitions_A_v[i] = 3;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==14) {//ellement 14
            number_A_v[i] = 17;
            ID_A_v[i] = a15;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_high;
            basename_A_v[i] = base_17;
            filename_A_v[i] = filename_17;
            pitch_A_v[i] = 65;
            pitch_interval_A_v[i] = -2;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 1.279;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==15) {//ellement 15
            number_A_v[i] = 18;
            ID_A_v[i] = a16;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_18;
            filename_A_v[i] = filename_18;
            pitch_A_v[i] = 68;
            pitch_interval_A_v[i] = -6;
            interval_size_A_v[i] = pitch_interval_large;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 14.404;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==16) {//ellement 16
            number_A_v[i] = 19;
            ID_A_v[i] = a17;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_19;
            filename_A_v[i] = filename_19;
            pitch_A_v[i] = 83;
            pitch_interval_A_v[i] = 7;
            interval_size_A_v[i] = pitch_interval_large;
            interval_direction_A_v[i] = interval_direction_ascending;
            information_content_A_v[i] = 14.396;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==17) {//ellement 17
            number_A_v[i] = 20;
            ID_A_v[i] = a18;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_20;
            filename_A_v[i] = filename_20;
            pitch_A_v[i] = 63;
            pitch_interval_A_v[i] = -4;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 11.01;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==18) {//ellement 18
            number_A_v[i] = 21;
            ID_A_v[i] = a19;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_21;
            filename_A_v[i] = filename_21;
            pitch_A_v[i] = 63;
            pitch_interval_A_v[i] = -9;
            interval_size_A_v[i] = pitch_interval_large;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 14.068;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        } else if(myPage.trialMelody_1_v[i]==19) {//ellement 19
            number_A_v[i] = 22;
            ID_A_v[i] = a20;
            session_A_v[i] = session_A;
            practice_A_v[i] = practice_no;
            timbre_A_v[i] = timbre_trumpet;
            probability_A_v[i] = probability_low;
            basename_A_v[i] = base_22;
            filename_A_v[i] = filename_22;
            pitch_A_v[i] = 66;
            pitch_interval_A_v[i] = -1;
            interval_size_A_v[i] = pitch_interval_small;
            interval_direction_A_v[i] = interval_direction_descending;
            information_content_A_v[i] = 8.016;
            probe_repetitions_A_v[i] = 0;
            probe_octave_repetitions_A_v[i] = 0;
        }
//        //print out array contents for Session A
//        for(int i = 0; i < number_A_v.size(); i++){
            cout << "Session A Number ID = " << number_A_v[i] << endl;
            cout << "Session A ID CHAR = " << ID_A_v[i] << endl;
            cout << "Session A Session = " << session_A_v[i] << endl;
            cout << "Session A Pracitce? " << practice_A_v[i] << endl;
            cout << "Session A TIMBRE = " << timbre_A_v[i] << endl;
            cout << "Session A Probabilitiy = " << probability_A_v[i] << endl;
            cout << "Session A basename = " << basename_A_v[i] << endl;
            cout << "Session A filename = " << filename_A_v[i] << endl;
            cout << "Session A pitch = " << pitch_A_v[i] << endl;
            cout << "Session A pitch interval = " << pitch_interval_A_v[i] << endl;
            cout << "Session A interval size = " << interval_size_A_v[i] << endl;
            cout << "Session A interval direction = " << interval_direction_A_v[i] << endl;
            cout << "Session A information content = " << information_content_A_v[i] << endl;
            cout << "Session A probe repetitions = " << probe_repetitions_A_v[i] << endl;
            cout << "Session A probe octave repetitions = " << probe_octave_repetitions_A_v[i] << endl;
       // }
    }
    /*====================== B MELODY TRIALS =========================*/
    //array if B melodies are playing
    for (int i = 0; i< myPage.trialMelody_2_v.size(); i++) {//ellement 0
        if (myPage.trialMelody_2_v[i]==0) {
            number_B_v[i] = 25;
            ID_B_v[i] = b1;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_25;
            filename_B_v[i] = filename_25;
            pitch_B_v[i] = 69;
            pitch_interval_B_v[i] = -2;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 0.469;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==1) {//ellement 1
            number_B_v[i] = 26;
            ID_B_v[i] = b2;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_26;
            filename_B_v[i] = filename_26;
            pitch_B_v[i] = 75;
            pitch_interval_B_v[i] = 1;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 0.144;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==2) {//ellement 2
            number_B_v[i] = 27;
            ID_B_v[i] = b3;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_27;
            filename_B_v[i] = filename_27;
            pitch_B_v[i] = 65;
            pitch_interval_B_v[i] = -7;
            interval_size_B_v[i] = pitch_interval_large;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 4.095;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==3) {//ellement 3
            number_B_v[i] = 28;
            ID_B_v[i] = b4;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_28;
            filename_B_v[i] = filename_28;
            pitch_B_v[i] = 67;
            pitch_interval_B_v[i] = -2;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 1.531;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==4) {//ellement 4
            number_B_v[i] = 29;
            ID_B_v[i] = b5;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_29;
            filename_B_v[i] = filename_29;
            pitch_B_v[i] = 67;
            pitch_interval_B_v[i] = 1;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 1.217;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==5) {//ellement 5
            number_B_v[i] = 30;
            ID_B_v[i] = b6;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_30;
            filename_B_v[i] = filename_30;
            pitch_B_v[i] = 75;
            pitch_interval_B_v[i] = 4;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 12.997;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==6) {//ellement 6
            number_B_v[i] = 31;
            ID_B_v[i] = b7;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_31;
            filename_B_v[i] = filename_31;
            pitch_B_v[i] = 77;
            pitch_interval_B_v[i] = 6;
            interval_size_B_v[i] = pitch_interval_large;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 13.503;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==7) {//ellement 7
            number_B_v[i] = 32;
            ID_B_v[i] = b8;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_32;
            filename_B_v[i] = filename_32;
            pitch_B_v[i] = 78;
            pitch_interval_B_v[i] = 4;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 14.358;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==8) {//ellement 8
            number_B_v[i] = 33;
            ID_B_v[i] = b9;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_33;
            filename_B_v[i] = filename_33;
            pitch_B_v[i] = 63;
            pitch_interval_B_v[i] = -9;
            interval_size_B_v[i] = pitch_interval_large;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 13.696;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==9) {//ellement 9
            number_B_v[i] = 34;
            ID_B_v[i] = b10;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_piano;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_34;
            filename_B_v[i] = filename_34;
            pitch_B_v[i] = 81;
            pitch_interval_B_v[i] = 6;
            interval_size_B_v[i] = pitch_interval_large;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 14.364;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==10) {//ellement 10
            number_B_v[i] = 35;
            ID_B_v[i] = b11;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_35;
            filename_B_v[i] = filename_35;
            pitch_B_v[i] = 62;
            pitch_interval_B_v[i] = -2;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 3.163;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==11) {//ellement 11
            number_B_v[i] = 36;
            ID_B_v[i] = b12;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_36;
            filename_B_v[i] = filename_36;
            pitch_B_v[i] = 74;
            pitch_interval_B_v[i] = -1;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 1.405;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==12) {//ellement 12
            number_B_v[i] = 37;
            ID_B_v[i] = b13;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_37;
            filename_B_v[i] = filename_37;
            pitch_B_v[i] = 70;
            pitch_interval_B_v[i] = -4;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 2.541;
            probe_repetitions_B_v[i] = 1;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==13) {//ellement 13
            number_B_v[i] = 38;
            ID_B_v[i] = b14;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_38;
            filename_B_v[i] = filename_38;
            pitch_B_v[i] = 60;
            pitch_interval_B_v[i] = 1;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 1.456;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==14) {//ellement 14
            number_B_v[i] = 39;
            ID_B_v[i] = b15;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_high;
            basename_B_v[i] = base_39;
            filename_B_v[i] = filename_39;
            pitch_B_v[i] = 70;
            pitch_interval_B_v[i] = 1;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 0.48;
            probe_repetitions_B_v[i] = 1;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==15) {//ellement 15
            number_B_v[i] = 40;
            ID_B_v[i] = b16;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_40;
            filename_B_v[i] = filename_40;
            pitch_B_v[i] = 63;
            pitch_interval_B_v[i] = -4;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 10.363;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==16) {//ellement 16
            number_B_v[i] = 41;
            ID_B_v[i] = b17;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_41;
            filename_B_v[i] = filename_41;
            pitch_B_v[i] = 59;
            pitch_interval_B_v[i] = -10;
            interval_size_B_v[i] = pitch_interval_large;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 13.004;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==17) {//ellement 17
            number_B_v[i] = 42;
            ID_B_v[i] = b18;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_42;
            filename_B_v[i] = filename_42;
            pitch_B_v[i] = 63;
            pitch_interval_B_v[i] = -9;
            interval_size_B_v[i] = pitch_interval_large;
            interval_direction_B_v[i] = interval_direction_descending;
            information_content_B_v[i] = 13.245;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==18) {//ellement 18
            number_B_v[i] = 43;
            ID_B_v[i] = b19;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_43;
            filename_B_v[i] = filename_43;
            pitch_B_v[i] = 73;
            pitch_interval_B_v[i] = 1;
            interval_size_B_v[i] = pitch_interval_small;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 9.605;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        } else if(myPage.trialMelody_2_v[i]==19) {//ellement 19
            number_B_v[i] = 44;
            ID_B_v[i] = b20;
            session_B_v[i] = session_B;
            practice_B_v[i] = practice_no;
            timbre_B_v[i] = timbre_trumpet;
            probability_B_v[i] = probability_low;
            basename_B_v[i] = base_44;
            filename_B_v[i] = filename_44;
            pitch_B_v[i] = 79;
            pitch_interval_B_v[i] = 6;
            interval_size_B_v[i] = pitch_interval_large;
            interval_direction_B_v[i] = interval_direction_ascending;
            information_content_B_v[i] = 12.422;
            probe_repetitions_B_v[i] = 0;
            probe_octave_repetitions_B_v[i] = 0;
        }
        
//        //print out array contents for Session B
//        for(int i = 0; i < number_A_v.size(); i++){
            cout << "Session B Number ID = " << number_B_v[i] << endl;
            cout << "Session B ID CHAR = " << ID_B_v[i] << endl;
            cout << "Session B Session = " << session_B_v[i] << endl;
            cout << "Session B Pracitce? " << practice_B_v[i] << endl;
            cout << "Session B TIMBRE = " << timbre_B_v[i] << endl;
            cout << "Session B Probabilitiy = " << probability_B_v[i] << endl;
            cout << "Session B basename = " << basename_B_v[i] << endl;
            cout << "Session B filename = " << filename_B_v[i] << endl;
            cout << "Session B pitch = " << pitch_B_v[i] << endl;
            cout << "Session B pitch interval = " << pitch_interval_B_v[i] << endl;
            cout << "Session B interval size = " << interval_size_B_v[i] << endl;
            cout << "Session B interval direction = " << interval_direction_B_v[i] << endl;
            cout << "Session B information content = " << information_content_B_v[i] << endl;
            cout << "Session B probe repetitions = " << probe_repetitions_B_v[i] << endl;
            cout << "Session B probe octave repetitions = " << probe_octave_repetitions_B_v[i] << endl;
  //      }

    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //cout << "my array is size: " << testMelodyNumber1.size() << endl;
    //cout << testMelodyNumber1[2] << endl;
    myPage.update();
    //    updateTimer();
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
    
//    if(myPage.bPlayGroupAMelody == true && myPage.bResetMelody == false){
//        if(myPage.playPianoMelody == true){
//            //trialMelodies_temp = sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].playOnce();
//            cout << "PIANO INDEX ARRAY = " << myPage.trialMelody_1_v[myPage.trial_melody_count] << endl;
//        } else if(myPage.playTrumpetMelody == true){
//            //trialMelodies_temp = sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].playOnce();
//            cout << "TRUMPET INDEX ARRAY = " << myPage.trialMelody_1_v[myPage.trial_melody_count] << endl;
//        }
//        
//    }
    
    //SAVE the file as soon as page 24 is reached - file is set to save first
    if(myPage.currentPage==24 && bPermitSaveFile == true)
    {
        saveFile();//store all data to file
        cout << "save text file" << endl;
        bPermitSaveFile = false;//only save the file once - we dont want a loop!
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //mySounds.draw();//to allow update of variables from parent class
    //myHomePage.draw();
    //myIntroduction.draw();
    myPage.draw();//draw last to layer ontop of other images
    userKeyboardInput();
    
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

void ofApp::userKeyboardInput(){//run in update
    
    //setup to view the keyboard
    if(myPage.currentPage >= -4  && myPage.currentPage < -1){
        if(!keyboard->isKeyboardShowing()){
            keyboard->openKeyboard();
            keyboard->setVisible(true);
            keyboard->updateOrientation();
        }
    } else if(myPage.currentPage >= -1){
        keyboard->setVisible(false);
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);//move pivot to centre
    ofRotate(90);
    
    if(myPage.currentPage == -3)
    {
        //cout << "PAGE = " << myPage.currentPage << endl;
        //update userID
        
        ofSetColor(255, 0, 0, 255);
        keyboard_f.drawString("CONTINUE", 200, -450);
        ofSetColor(0, 0, 0, 255);
        keyboard_f.drawString("Please type your first name followed by the first \n\nletter of your last name followed by your age. \n\n\n\nFor example if your name is Giles, your surname \n\nDickins and your age 13, you should enter: \n\n", -360, -300);
        ofSetColor(255, 0, 0, 255);
        keyboard_f.drawString("\n\n\n\n\n\n\n\n\n\n\n\n'GilesD12'", -360, -300);
         ofSetColor(0, 0, 0, 255);
        keyboard_f.drawString("\n\nWhen you have entered this information please \n\npress the", -360, -50);
        ofSetColor(255, 0, 0, 255);
        keyboard_f.drawString("\n\n\n\n        CONTINUE", -360, -50);
        ofSetColor(0, 0, 0, 255);
        keyboard_f.drawString("\n\n\n\n                  button above to continue.", -360, -50);
        ofSetColor(0, 0, 255, 255);
        keyboard_f.drawString("Name and age = "+  keyboard->getLabelText() , -360, 140);
        //assign userID to the input
        userID_s = keyboard->getLabelText();
        
    }
    
    if(myPage.currentPage == -2)
    {

        keyboard->getLabelText() = "";//does not work!
        ofSetColor(0, 255, 0, 255);
        keyboard_f.drawString("BACK", -350, -450);
        ofSetColor(255, 0, 0, 255);
        keyboard_f.drawString("CONTINUE", 200, -450);
        ofSetColor(0, 0, 0, 255);
        keyboard_f.drawString("You have just entered [" + userID_s + "].\n\nPress back if you need to change this.\n\n\n\nIf this is correct please press CONTINUE.\n\n\n\nPlease get ready to turn the iPad round to\n\nLandscape Mode.", -350, -300);
        ofSetColor(0, 0, 255, 255);
        //keyboard_f.drawString("User Age In Months = "+  keyboard->getLabelText() , -350, 100);
        //user_age_s = keyboard->getLabelText();
    }
    
//    if(myPage.currentPage == -2){
//        ofSetColor(0, 255, 0, 255);
//        keyboard_f.drawString("BACK", -300, -450);
//        ofSetColor(0, 0, 0, 255);
//        keyboard_f.drawString("CONTINUE", 200, -450);
//        ofSetColor(0, 0, 0, 255);
//        keyboard_f.drawString("The name and age [" + user_age_s + "] is now stored.\n\nPress back if you need to change this.\n\n\n\n\n\nUser ID = " + userID_s + "\n\nUser Age = " + user_age_s + "\n\n\n\nIf you are happy please press continue. \n\n\n\nPlease get ready to turn the iPad round to\n\nLandscape Mode.", -350, -300);
//    }

   
    ofPushMatrix();
}

//--------------------------------------------------------------

void ofApp::updateTimer(){
    //Need to store 4 practice trials into an array then if Session A is true add 20 trials to A array
    //If Session B is true then the second array will be filled
    //The session trial arrays need to replace the same element multiple times so there must
    //be a specific array index associated with each page number of the app.
    
    //cout << "\nUpdate the timer now!" << endl;
    if(myPage.hasPressed){
        //cout << "Time Stamp IN updateTIMER = " << myPage.trial_time_counter.elapsed() << endl;
    }
    
    //First set up to store the amount of time taken for the practice melodies
    //All these are on page 3
    if(myPage.currentPage == 3 && myPage.bPermitArrayTimeStamp == true)
    {
        
        
        //must replace each index of array mulitple times if required.
//        for(int i = 0; i < practice_time_data_B_v.size(); i ++)
//        {
//            if(myPage.currentPage == i+4)
//            {
            
        //check what session
        //Groups A1 and A2 will hear Melody A
        if(myPage.bSessionA1 == true || myPage.bSessionA2 == true)
        {
            
            cout << "Practice Time Stamp in SECONDS= " << myPage.trial_time_counter.elapsed()/1000000 <<  endl;
            cout << "Practice Time Stamp in Milliseconds = " << myPage.trial_time_counter.elapsed()/1000 <<  endl;
            cout << "Practice Time Stamp in SECONDS FOR REAL = " << myPage.trial_time_counter.elapsedSeconds() <<  endl;
            
            if(myPage.practice_count == 0){
                int temp = myPage.practiceMelody_1_v[0];
                cout << "TEMP [0] = " << temp << endl;
                if(temp == 1){
                    saveTime();
                    time_v[1] = save_time_s;//store current time
                    practice_time_data_A_v[1] = myPage.trial_time_counter.elapsed()/1000;
                    cout << "Practice Array Index 1 Time Stamp = " << practice_time_data_A_v[1] << endl;
                } else if(temp == 0){
                    saveTime();
                    time_v[0] = save_time_s;//store current time
                    practice_time_data_A_v[0] = myPage.trial_time_counter.elapsed()/1000;
                    cout << "Practice Array Index 0 Time Stamp = " << practice_time_data_A_v[0] << endl;
                }
                if (myPage.bGuessedWrong) {
                    if(temp == 1){
                        practice_answer_A_v[1] = wrong;
                    } else if(temp == 0){
                        practice_answer_A_v[0] = wrong;
                    }
                } else if(!myPage.bGuessedWrong){
                    if(temp == 1){
                        practice_answer_A_v[1] = correct;
                    } else if(temp == 0){
                        practice_answer_A_v[0] = correct;
                    }
                }
            } else if(myPage.practice_count == 1){
                int temp = myPage.practiceMelody_1_v[1];
                cout << "TEMP2 [1] = " << temp << endl;
                if(temp == 1){
                    saveTime();
                    time_v[1] = save_time_s;//store current time
                    practice_time_data_A_v[1] = myPage.trial_time_counter.elapsed()/1000;
                    cout << "Practice Array Index 1 Time Stamp = " << practice_time_data_A_v[1] << endl;
                } else if(temp == 0){
                    saveTime();
                    time_v[0] = save_time_s;//store current time
                    practice_time_data_A_v[0] = myPage.trial_time_counter.elapsed()/1000;
                    cout << "Practice Array Index 0 Time Stamp = " << practice_time_data_A_v[0] << endl;
                }
                if (myPage.bGuessedWrong) {
                    if(temp == 1){
                        practice_answer_A_v[1] = wrong;
                    } else if(temp == 0){
                        practice_answer_A_v[0] = wrong;
                    }
                } else if(!myPage.bGuessedWrong)
                {
                    if(temp == 1)
                    {
                        practice_answer_A_v[1] = correct;
                    } else if(temp == 0)
                    {
                        practice_answer_A_v[0] = correct;
                    }
                }
            }
            //Groups B1 and B2 will here melody session B
        } else if(myPage.bSessionB1 == true || myPage.bSessionB2 == true)
        {
            if(myPage.practice_count == 0){
        
                int temp = myPage.practiceMelody_2_v[0];
                if(temp == 1){
                    saveTime();
                    time_v[3] = save_time_s;//store current time in index 3 of main 44 length vector
                    practice_time_data_B_v[1] = myPage.trial_time_counter.elapsed()/1000;
                    cout << "Practice Array Index 0 Time Stamp = " << practice_time_data_B_v[1] << endl;
                } else if(temp == 0){
                    saveTime();
                    time_v[2] = save_time_s;//store current time in index 2 of main 44 length vector
                    practice_time_data_B_v[0] = myPage.trial_time_counter.elapsed()/1000;
                    cout << "Practice Array Index 0 Time Stamp = " << practice_time_data_B_v[0] << endl;
                }
                if (myPage.bGuessedWrong) {
                    if(temp == 1){
                        practice_answer_B_v[1] = wrong;
                    } else if(temp == 0){
                        practice_answer_B_v[0] = wrong;
                    }
                } else if(!myPage.bGuessedWrong){
                    if(temp == 1){
                        practice_answer_B_v[1] = correct;
                    } else if(temp == 0){
                        practice_answer_B_v[0] = correct;
                    }
                }
             } else if(myPage.practice_count == 1){
                
                int temp = myPage.practiceMelody_2_v[1];
                if(temp == 1){
                    saveTime();
                    time_v[3] = save_time_s;//store current time in index 3 of main 44 length vector
                    practice_time_data_B_v[1] = myPage.trial_time_counter.elapsed()/1000;
                    cout << "Practice Array Index 1 Time Stamp = " << practice_time_data_B_v[1] << endl;
                } else if(temp == 0){
                    saveTime();
                    time_v[2] = save_time_s;//store current time
                    practice_time_data_B_v[0] = myPage.trial_time_counter.elapsed()/1000;
                    cout << "Practice Array Index 1 Time Stamp = " << practice_time_data_B_v[0] << endl;
                }
                 if (myPage.bGuessedWrong) {
                     if(temp == 1){
                         practice_answer_B_v[1] = wrong;
                     } else if(temp == 0){
                         practice_answer_B_v[0] = wrong;
                     }
                 } else if(!myPage.bGuessedWrong){
                     if(temp == 1){
                         practice_answer_B_v[1] = correct;
                     } else if(temp == 0){
                         practice_answer_B_v[0] = correct;
                     }
                 }
             }
         }
         //myPage.hasPressed = false;//reset to false to stop array being filled if user presses the app again.
         myPage.bPermitArrayTimeStamp = false;

        
          //      trial_time_data_B_v[i] = myPage.trial_time_counter.elapsed()/1000;//replace the element every time an answer is given?
//                cout << "Practice Time Stamp = " << myPage.trial_time_counter.elapsed() <<  endl;//make sure the index has stored the timestamp
//                cout << "Array Index Time Stamp = " << trial_time_data_B_v[i] << endl;
//                if(myPage.bSessionA2 == true)
//                {
//                    saveTime();
//                    int temp = myPage.practice_count;
//                    if(temp == 1){
//                        time_v[3] = save_time_s;//store current time
//                    } else if(temp == 0){
//                        time_v[2] = save_time_s;//store current time
//                    }
//                } else if(myPage.bSessionB2 == true)
//                {
//                    saveTime();
//                    int temp = myPage.practice_count;
//                    if(temp == 1){
//                        time_v[3] = save_time_s;//store current time
//                    } else if(temp == 0){
//                        time_v[2] = save_time_s;//store current time
//                    }
//                }
//                if (myPage.bGuessedWrong) {
//                    int temp = myPage.practice_count;
//                    if(temp == 1){
//                        practice_answer_B_v[1] = wrong;
//                    } else if(temp == 0){
//                        practice_answer_B_v[0] = wrong;
//                    }
//                } else if(!myPage.bGuessedWrong){
//                    int temp = myPage.practice_count;
//                    if(temp == 1){
//                        practice_answer_B_v[1] = correct;
//                    } else if(temp == 0){
//                        practice_answer_B_v[0] = correct;
//                    }
//                }
            //}
            //}
      //  }
        
        
//        if(myPage.hasPressed == true)//user has given an answer
//        {
//           //cout << "Practice Time Stamp in ms = " << myPage.trial_time_counter.elapsed()/1000 << endl;
//           //float temp_time_stamp = myPage.trial_time_counter.elapsed();//get macroseconds
//           //print out the exact time of the trial_Time_Counter and add it to the array
//            if (myPage.practice_count==0) {
//                practice_time_data_v[0] = myPage.trial_time_counter.elapsed()/1000;
//                //cout << "Practice Stored Stamp in ms = " << practice_time_data_v[0] << endl;
//                saveTime();
//                time_v[0] = save_time_s;//store current time
//                if(myPage.bGuessedWrong){
//                    practice_answer_v[0] = wrong;
//                } else if (!myPage.bGuessedWrong){
//                    practice_answer_v[0] = correct;
//                }
//                
//            } else if(myPage.practice_count==1)
//            {
//                practice_time_data_v[1] = myPage.trial_time_counter.elapsed()/1000;
//                //cout << "Practice Stored Stamp in ms = " << practice_time_data_v[1] << endl;
//                saveTime();
//                time_v[1] = save_time_s;//store current time
//                if(myPage.bGuessedWrong){
//                    practice_answer_v[1] = wrong;
//                } else if (!myPage.bGuessedWrong){
//                    practice_answer_v[1] = correct;
//                }
//            } else if(myPage.practice_count==2)
//            {
//                practice_time_data_v[2] = myPage.trial_time_counter.elapsed()/1000;
//                //cout << "Practice Stored Stamp in ms = " << practice_time_data_v[2] << endl;
//                saveTime();
//                time_v[2] = save_time_s;//store current time
//                if(myPage.bGuessedWrong){
//                    practice_answer_v[2] = wrong;
//                } else if (!myPage.bGuessedWrong){
//                    practice_answer_v[2] = correct;
//                }
//            } else if(myPage.practice_count==3)
//            {
//                practice_time_data_v[3] = myPage.trial_time_counter.elapsed()/1000;
//                //cout << "Practice Stored Stamp in ms = " << practice_time_data_v[3] << endl;
//                saveTime();
//                time_v[3] = save_time_s;//store current time
//                if(myPage.bGuessedWrong){
//                    practice_answer_v[3] = wrong;
//                } else if (!myPage.bGuessedWrong){
//                    practice_answer_v[3] = correct;
//                }
//            }
//           //practice_time_data_v.push_back(myPage.trial_time_counter.elapsed());//store all draw
//           //cout << "Current Practice = " << myPage.practice_count+1 <<  endl;
//        }
       
    } else if(myPage.currentPage >= 4 && myPage.currentPage <=23 && myPage.bPermitArrayTimeStamp == true)//watch out for delay??
    {
    
        //must replace each index of array mulitple times if required.
        for(int i = 0; i < trial_time_data_A_v.size(); i ++)
        {
            if(myPage.currentPage == i+4)
            {
                //Print out session
                if(myPage.bSessionA1 == true){
                    cout << "SESSION = A1" <<  endl;
                }else if(myPage.bSessionB1 == true){
                    cout << "SESSION = B1" <<  endl;
                }else if(myPage.bSessionA2 == true){
                    cout << "SESSION = A2" <<  endl;
                }else if(myPage.bSessionB2 == true){
                    cout << "SESSION = B1" <<  endl;
                }
                
                //check what session
                if(myPage.bSessionA1 == true || myPage.bSessionA2 == true) //SESSION A MELODIES
                {
                    trial_time_data_A_v[i] = myPage.trial_time_counter.elapsed()/1000;//replace the element every time an answer is given?
                    cout << "Session AB page = " << myPage.currentPage <<  endl;
                    cout << "Current Test = " << i+1 <<  endl;
                    cout << "Melody Time Stamp in SECONDS= " << myPage.trial_time_counter.elapsed()/1000000 <<  endl;
                    cout << "Melody Time Stamp in Milliseconds = " << myPage.trial_time_counter.elapsed()/1000 <<  endl;
                    cout << "Melody Time Stamp in SECONDS FOR REAL = " << myPage.trial_time_counter.elapsedSeconds() <<  endl;
//                    cout << "Melody Time Stamp in Milliseconds = " << myPage.trial_time_counter.elapsed()/10000 <<  endl;
//                    cout << "Melody Time Stamp in microseconds = " << myPage.trial_time_counter.elapsed()/1000 <<  endl;
                    cout << "Array Index Time Stamp = " << trial_time_data_A_v[i] << endl;
//                    if(myPage.bSessionA1 == true){
//                       saveTime();
//                       time_v[i+4] = save_time_s;//store current time
//                    } else if(myPage.bSessionB1 == true)
//                    {
                       saveTime();
                       time_v[i+4] = save_time_s;//store current time (i+4 as 0-3 is the practice trials)
                    //}
                    if (myPage.bGuessedWrong) {
                        trial_answer_A_v[i] = wrong;
                    } else if(!myPage.bGuessedWrong){
                        trial_answer_A_v[i] = correct;
                    }
                } else if(myPage.bSessionB1 == true || myPage.bSessionB2 == true) //SESSION B MELODIES
                {
                    trial_time_data_B_v[i] = myPage.trial_time_counter.elapsed()/1000;//replace the element every time an answer is given?
                    cout << "Session BA page = " << myPage.currentPage <<  endl;
                    cout << "Current Test = " << i+1 <<  endl;
                    cout << "Melody Time Stamp = " << myPage.trial_time_counter.elapsed() <<  endl;//make sure the index has stored the timestamp
                    cout << "Array Index Time Stamp = " << trial_time_data_B_v[i] << endl;
//                    if(myPage.bSessionA2 == true)
//                    {
//                        saveTime();
//                        time_v[i+24] = save_time_s;//store current time
//                    } else if(myPage.bSessionB2 == true)
//                    {
                        saveTime();
                        time_v[i+24] = save_time_s;//store current time (i+44 as 0-3 is the practice trials 4-23 would be session A)
                    //}
                    if (myPage.bGuessedWrong) {
                        trial_answer_B_v[i] = wrong;
                    } else if(!myPage.bGuessedWrong){
                        trial_answer_B_v[i] = correct;
                    }
                }
            }
        }
        
        //myPage.hasPressed = false;//reset to false to stop array being filled if user presses the app again.
        myPage.bPermitArrayTimeStamp = false;
    }
}

//--------------------------------------------------------------
void ofApp::timeStampData(){
    //timestamp the data
    timeStamp_s = "DATE, " + ofToString(ofGetDay()) + "/" + ofToString(ofGetMonth()) + "/" +ofToString(ofGetYear()) + "\n" + "TIME, " + ofToString(ofGetHours()) + ":" + ofToString(ofGetMinutes()) + ":" + ofToString(ofGetSeconds()) + "\n";//print total time to screen in MS
    
}

//--------------------------------------------------------------
void ofApp::saveTime(){
    
    //create a new file stamp to name the individual files after the USER ID and DATE
    //First Accurate Date and Time allowing for 0s
    if (ofGetDay()<10) {
        day_s = "0"+ofToString(ofGetDay(), 0);
    } else {
        day_s = ofToString(ofGetDay(), 0);
    }
    if (ofGetMonth()<10) {
        month_s = "0"+ofToString(ofGetMonth(), 0);
    } else {
        month_s = ofToString(ofGetMonth(), 0);
    }
    //create a string to store the current date
    save_date_s = day_s + "-" + month_s + "-" +ofToString(ofGetYear());

    if (ofGetSeconds()<10) {
        seconds_s = "0"+ofToString(ofGetSeconds(), 0);
    } else {
        seconds_s = ofToString(ofGetSeconds(), 0);
    }
    if (ofGetMinutes()<10) {
        mins_s = "0"+ofToString(ofGetMinutes(), 0);
    } else {
        mins_s = ofToString(ofGetMinutes(), 0);
    }
    if (ofGetHours()<10) {
        hours_s = "0"+ofToString(ofGetHours(), 0);
    } else {
        hours_s = ofToString(ofGetHours(), 0);
    }

    //create a string to store the current time
    save_time_s = hours_s + "." + mins_s + "." + seconds_s;
    
}

//--------------------------------------------------------------
void ofApp::saveFile(){
    
    //if(myPage.bFinished){//make sure all answers have been given!
        if (userID_s == "\0") {
            printf("You entered nothing for ID!");
            //Assign anonymous to it
            userID_s = "Anonymous";
        }
        if (user_age_s == "\0") {
            printf("You entered nothing for age!");
            //Assign anonymous to it
            user_age_s = "No Answer";
        }
        
    
        saveTime();
        string newFileName = "USER_" + userID_s + "_DATE_" + save_date_s  + "_TIME_" + save_time_s + ".csv";
        ofFile file2(ofxiPhoneGetDocumentsDirectory() +newFileName,ofFile::WriteOnly);
        
        //assign variables to strings
        for (int i = 0; i < 44; i++) {
            userID_v[i] = userID_s;
            user_age_v[i] = user_age_s;
            date_v[i] = save_date_s;
            //time_v already filled during the user sessions
            if(myPage.bPianoLeft){
                piano_left_v[i] = "piano_left";
            } else piano_left_v[i] = "piano_right";
            
            if(myPage.bGroupAB){
                session_order_v[i] = "AB";
            } else if(myPage.bGroupBA){
                session_order_v[i] = "BA";
            }
            if(myPage.bSessionA1)
            {
              session_number_v[i] = "A1";
            } else if(myPage.bSessionA2)
            {
              session_number_v[i] = "A2";
            } else if(myPage.bSessionB1)
            {
              session_number_v[i] = "B1";
            } else if(myPage.bSessionB2)
            {
                session_number_v[i] = "B2";
            }
            
        }
        
        //Print out all time arrays to console to check them
        for (int i = 0; i < practice_time_data_A_v.size(); i++) {
           // practice_data_s = ofToString(practice_time_data_v[i]) + ",";
            cout << "PRACTICE A" << i+1 << " = " << practice_time_data_A_v[i] << "," << endl;
        }
        for (int i = 0; i < practice_time_data_B_v.size(); i++) {
            // practice_data_s = ofToString(practice_time_data_v[i]) + ",";
            cout << "PRACTICE B" << i+1 << " = " << practice_time_data_B_v[i] << "," << endl;
        }
        for (int i = 0; i < trial_time_data_A_v.size(); i++) {
            //melody_data_A_s = ofToString(trial_time_data_A_v[i]) + ",";
            cout << "MELODY A" << i+1 << " = " << trial_time_data_A_v[i] << "," << endl;
        }
        for (int i = 0; i < trial_time_data_B_v.size(); i++) {
            //melody_data_B_s = ofToString(trial_time_data_A_v[i]) + ",";
            cout << "MELODY B" << i+1 << " = " << trial_time_data_A_v[i] << "," << endl;
        }
        
        //concatinate all strings ready to add to final data file - includes time_v and all timestamps
        
        //======================= REVERSE THE ORDER TO KEEP CORRECT INDEX PLACEMENT ==================//
        //vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
        //Reaction_Time_v
        reaction_time_v.insert(reaction_time_v.begin(), trial_time_data_B_v.begin(), trial_time_data_B_v.end());
        reaction_time_v.insert(reaction_time_v.begin(), trial_time_data_A_v.begin(), trial_time_data_A_v.end());
        reaction_time_v.insert(reaction_time_v.begin(), practice_time_data_B_v.begin(), practice_time_data_B_v.end());
        reaction_time_v.insert(reaction_time_v.begin(), practice_time_data_A_v.begin(), practice_time_data_A_v.end());
        //Answer
        answer_v.insert(answer_v.begin(), trial_answer_B_v.begin(), trial_answer_B_v.end());
        answer_v.insert(answer_v.begin(), trial_answer_A_v.begin(), trial_answer_A_v.end());
        answer_v.insert(answer_v.begin(), practice_answer_B_v.begin(), practice_answer_B_v.end());
        answer_v.insert(answer_v.begin(), practice_answer_A_v.begin(), practice_answer_A_v.end());
        //Number
        number_v.insert(number_v.begin(), number_B_v.begin(), number_B_v.end());//reverse the order of arrays to add to begining of final!
        number_v.insert(number_v.begin(), number_A_v.begin(), number_A_v.end());
        number_v.insert(number_v.begin(), number_practice_B_v.begin(), number_practice_B_v.end());
        number_v.insert(number_v.begin(), number_practice_A_v.begin(), number_practice_A_v.end());
        //ID
        ID_v.insert(ID_v.begin(), ID_B_v.begin(), ID_B_v.end());
        ID_v.insert(ID_v.begin(), ID_A_v.begin(), ID_A_v.end());
        ID_v.insert(ID_v.begin(), ID_practice_B_v.begin(), ID_practice_B_v.end());
        ID_v.insert(ID_v.begin(), ID_practice_A_v.begin(), ID_practice_A_v.end());
        //Session
        session_v.insert(session_v.begin(), session_B_v.begin(), session_B_v.end());
        session_v.insert(session_v.begin(), session_A_v.begin(), session_A_v.end());
        session_v.insert(session_v.begin(), session_practice_B_v.begin(), session_practice_B_v.end());
        session_v.insert(session_v.begin(), session_practice_A_v.begin(), session_practice_A_v.end());
        //Practice
        practice_v.insert(practice_v.begin(), practice_B_v.begin(), practice_B_v.end());
        practice_v.insert(practice_v.begin(), practice_A_v.begin(), practice_A_v.end());
        practice_v.insert(practice_v.begin(), practice_practice_A_v.begin(), practice_practice_A_v.end());
        practice_v.insert(practice_v.begin(), practice_practice_B_v.begin(), practice_practice_B_v.end());
        //Timbre
        timbre_v.insert(timbre_v.begin(), timbre_B_v.begin(), timbre_B_v.end());
        timbre_v.insert(timbre_v.begin(), timbre_A_v.begin(), timbre_A_v.end());
        timbre_v.insert(timbre_v.begin(), timbre_practice_B_v.begin(), timbre_practice_B_v.end());
        timbre_v.insert(timbre_v.begin(), timbre_practice_A_v.begin(), timbre_practice_A_v.end());
        //Probability
        probability_v.insert(probability_v.begin(), probability_B_v.begin(), probability_B_v.end());
        probability_v.insert(probability_v.begin(), probability_A_v.begin(), probability_A_v.end());
        probability_v.insert(probability_v.begin(), probability_practice_B_v.begin(), probability_practice_B_v.end());
        probability_v.insert(probability_v.begin(), probability_practice_A_v.begin(), probability_practice_A_v.end());
        //Basename
        basename_v.insert(basename_v.begin(), basename_B_v.begin(), basename_B_v.end());
        basename_v.insert(basename_v.begin(), basename_A_v.begin(), basename_A_v.end());
        basename_v.insert(basename_v.begin(), basename_practice_B_v.begin(), basename_practice_B_v.end());
        basename_v.insert(basename_v.begin(), basename_practice_A_v.begin(), basename_practice_A_v.end());
        //Filename
        filename_v.insert(filename_v.begin(), filename_B_v.begin(), filename_B_v.end());
        filename_v.insert(filename_v.begin(), filename_A_v.begin(), filename_A_v.end());
        filename_v.insert(filename_v.begin(), filename_practice_B_v.begin(), filename_practice_B_v.end());
        filename_v.insert(filename_v.begin(), filename_practice_A_v.begin(), filename_practice_A_v.end());
        //Pitch
        pitch_v.insert(pitch_v.begin(), pitch_B_v.begin(), pitch_B_v.end());
        pitch_v.insert(pitch_v.begin(), pitch_A_v.begin(), pitch_A_v.end());
        pitch_v.insert(pitch_v.begin(), pitch_practice_B_v.begin(), pitch_practice_B_v.end());
        pitch_v.insert(pitch_v.begin(), pitch_practice_A_v.begin(), pitch_practice_A_v.end());
        //Pitch Interval
        pitch_interval_v.insert(pitch_interval_v.begin(), pitch_interval_B_v.begin(), pitch_interval_B_v.end());
        pitch_interval_v.insert(pitch_interval_v.begin(), pitch_interval_A_v.begin(), pitch_interval_A_v.end());
        pitch_interval_v.insert(pitch_interval_v.begin(), pitch_interval_practice_B_v.begin(), pitch_interval_practice_B_v.end());
        pitch_interval_v.insert(pitch_interval_v.begin(), pitch_interval_practice_A_v.begin(), pitch_interval_practice_A_v.end());
        //Interval size
        interval_size_v.insert(interval_size_v.begin(), interval_size_B_v.begin(), interval_size_B_v.end());
        interval_size_v.insert(interval_size_v.begin(), interval_size_A_v.begin(), interval_size_A_v.end());
        interval_size_v.insert(interval_size_v.begin(), interval_size_practice_B_v.begin(), interval_size_practice_B_v.end());
        interval_size_v.insert(interval_size_v.begin(), interval_size_practice_A_v.begin(), interval_size_practice_A_v.end());
        //Interval Direction
        interval_direction_v.insert(interval_direction_v.begin(), interval_direction_B_v.begin(), interval_direction_B_v.end());
        interval_direction_v.insert(interval_direction_v.begin(), interval_direction_A_v.begin(), interval_direction_A_v.end());
        interval_direction_v.insert(interval_direction_v.begin(), interval_direction_practice_B_v.begin(), interval_direction_practice_B_v.end());
        interval_direction_v.insert(interval_direction_v.begin(), interval_direction_practice_A_v.begin(), interval_direction_practice_A_v.end());
        //Information content
        information_content_v.insert(information_content_v.begin(), information_content_B_v.begin(), information_content_B_v.end());
        information_content_v.insert(information_content_v.begin(), information_content_A_v.begin(), information_content_A_v.end());
        information_content_v.insert(information_content_v.begin(), information_content_practice_B_v.begin(), information_content_practice_B_v.end());
        information_content_v.insert(information_content_v.begin(), information_content_practice_A_v.begin(), information_content_practice_A_v.end());
        //Probe repetitions
        probe_repetitions_v.insert(probe_repetitions_v.begin(), probe_repetitions_B_v.begin(), probe_repetitions_B_v.end());
        probe_repetitions_v.insert(probe_repetitions_v.begin(), probe_repetitions_A_v.begin(), probe_repetitions_A_v.end());
        probe_repetitions_v.insert(probe_repetitions_v.begin(), probe_repetitions_practice_B_v.begin(), probe_repetitions_practice_B_v.end());
        probe_repetitions_v.insert(probe_repetitions_v.begin(), probe_repetitions_practice_A_v.begin(), probe_repetitions_practice_A_v.end());
        //octave probe repetitions
        probe_octave_repetitions_v.insert(probe_octave_repetitions_v.begin(), probe_octave_repetitions_B_v.begin(), probe_octave_repetitions_B_v.end());
        probe_octave_repetitions_v.insert(probe_octave_repetitions_v.begin(), probe_octave_repetitions_A_v.begin(), probe_octave_repetitions_A_v.end());
        probe_octave_repetitions_v.insert(probe_octave_repetitions_v.begin(), probe_octave_repetitions_practice_B_v.begin(), probe_octave_repetitions_practice_B_v.end());
        probe_octave_repetitions_v.insert(probe_octave_repetitions_v.begin(), probe_octave_repetitions_practice_A_v.begin(), probe_octave_repetitions_practice_A_v.end());
        
        
        //print all concatinated strings to console to check
        for (int i = 0; i < 44; i++) {
            cout << "Reaction_Time " << i+1 << " = " << reaction_time_v[i] << "," << endl;
            cout << "Number " << i+1 << " = " << number_v[i] << "," << endl;
            cout << "ID " << i+1 << " = " << ID_v[i] << "," << endl;
            cout << "Session " << i+1 << " = " << session_v[i] << "," << endl;
            cout << "Practice " << i+1 << " = " << practice_v[i] << "," << endl;
            cout << "Timbre " << i+1 << " = " << timbre_v[i] << "," << endl;
            cout << "Probability " << i+1 << " = " << probability_v[i] << "," << endl;
            cout << "Basename " << i+1 << " = " << basename_v[i] << "," << endl;
            cout << "Filename " << i+1 << " = " << filename_v[i] << "," << endl;
            cout << "Pitch " << i+1 << " = " << pitch_v[i] << "," << endl;
            cout << "Pitch_interval " << i+1 << " = " << pitch_interval_v[i] << "," << endl;
            cout << "interval_size " << i+1 << " = " << interval_size_v[i] << "," << endl;
            cout << "interval_direction " << i+1 << " = " << interval_direction_v[i] << "," << endl;
            cout << "infoprmation_content " << i+1 << " = " << information_content_v[i] << "," << endl;
            cout << "probe_repetitions " << i+1 << " = " << probe_repetitions_v[i] << "," << endl;
            cout << "probe_octave_repetitions " << i+1 << " = " << probe_octave_repetitions_v[i] << "," << endl;
        }
        
        //PRINT ALL DATA TO FILE with 44 elelements
        file2 << "User_ID,User_Age,Session_Number,Session_Order,Date,Time_Completed,Piano_Position,Reaction_Time_Millis,Answer,Number,ID,Session,Practice,Timbre,Probability,Basename,Filename,Pitch,Pitch_Interval,Interval_Size,Interval_Direction,Information_Content,Probe_Repetitions,Probe_Octave_Repetitions";
        for (int i = 0; i < 44; i++) {
            file2 << "\n" << userID_v[i] << ",";//add << endl to have obvious colums
            file2 << user_age_v[i] << ",";
            file2 << session_number_v[i] << ",";
            file2 << session_order_v[i] << ",";
            file2 << date_v[i] << ",";
            file2 << time_v[i] << ",";
            file2 << piano_left_v[i] << ",";
            file2 << reaction_time_v[i] << ",";
            file2 << answer_v[i] << ",";
            file2 << number_v[i] << ",";
            file2 << ID_v[i] << ",";
            file2 << session_v[i] << ",";
            file2 << practice_v[i] << ",";
            file2 << timbre_v[i] << ",";
            file2 << probability_v[i] << ",";
            file2 << basename_v[i] << ",";
            file2 << filename_v[i] << ",";
            file2 << pitch_v[i] << ",";
            file2 << pitch_interval_v[i] << ",";
            file2 << interval_size_v[i] << ",";
            file2 << interval_direction_v[i] << ",";
            file2 << information_content_v[i] << ",";
            file2 << probe_repetitions_v[i] << ",";
            file2 << probe_octave_repetitions_v[i];
        }
        file2.close();
    //}//close bFinshed if statement Redo when app is fully working!
    
}

//--------------------------------------------------------------
void ofApp::loadFile(){
    dataFile.open(ofxiPhoneGetDocumentsDirectory() +"datafile.txt",ofFile::ReadWrite);
    buff = dataFile.readToBuffer();
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
            
            for (int i=0; i<2; i++) {
                testMelodys_A_v[i].reset();
                testMelodys_B_v[i].reset();
            }
            
            pianoMelody.reset();
            trumpetMelody.reset();
            
            if (myPage.playPianoSingle == true) {
                pianoSingle_x = pianoSingle.playOnce();
                //printf("PlayPiano");
            } else pianoSingle.reset();
            
            pianoSingle.getLength();//get the length to set playback to false
            if (pianoSingle.position == pianoSingle.length - 3000){
                myPage.playPianoSingle = false;
                pianoSingle.reset();
            }
            
            if(myPage.playTrumpetSingle == true) {
                //printf("PlayTrumpet");
                trumpetSingle_x = trumpetSingle.playOnce();
            } else trumpetSingle.reset();
            
            trumpetSingle.getLength();//get the length to set playback to false
            if (trumpetSingle.position == pianoSingle.length - 3000){
                myPage.playTrumpetSingle = false;
                trumpetSingle.reset();
            }
            x = trumpetSingle_x + pianoSingle_x + cheer_x + badLuck_x;
        }
        else if (myPage.currentPage == 3) //practice session x 4 || 2?
        {
            //reset session files
            for (int i=0; i<20; i++) {
                sessionA_Melodys_v[i].reset();
                sessionB_Melodys_v[i].reset();
            }
            
            //reset single notes
            pianoSingle.reset();
            trumpetSingle.reset();
            
            if(myPage.bPlayPracticeMelody)//stop app crashing!?? may need to constrain to practice_count < 2?
            {
                
                if(myPage.bPlayGroupAMelody == true && myPage.bResetMelody == false){
                    
                    practiceMelody_temp = testMelodys_A_v[myPage.practiceMelody_1_v[myPage.practice_count]].playOnce();
                    int temp = myPage.practiceMelody_1_v[myPage.practice_count];
                    if(temp == 0){
                        testMelodys_A_v[1].reset();
                    } else if(temp == 1){
                        testMelodys_A_v[0].reset();
                    }
                    
                } //else testMelodys_A_v[myPage.practiceMelody_1_v[myPage.practice_count]].reset();
                
                else if(myPage.bPlayGroupBMelody == true && myPage.bResetMelody == false){
                    
                    practiceMelody_temp = testMelodys_B_v[myPage.practiceMelody_2_v[myPage.practice_count]].playOnce();
                    int temp = myPage.practiceMelody_2_v[myPage.practice_count];
                    if(temp == 0){
                        testMelodys_B_v[1].reset();
                    } else if(temp == 1){
                        testMelodys_B_v[0].reset();
                    }
                } //else testMelodys_B_v[myPage.practiceMelody_2_v[myPage.practice_count]].reset();
                
            } else if(myPage.bPlayPracticeMelody == false)
            {
                for (int i=0; i<2; i++)
                {
                    testMelodys_A_v[i].getLength();
                    if (testMelodys_A_v[i].position == testMelodys_A_v[i].length-3000)
                    {
                        myPage.bResetMelody = true;
                        testMelodys_A_v[i].reset();
                    }
                    testMelodys_B_v[i].getLength();
                    if (testMelodys_B_v[i].position == testMelodys_B_v[i].length-3000)
                    {
                        myPage.bResetMelody = true;
                        testMelodys_B_v[i].reset();
                    }
                }
            }

            x = practiceMelody_temp + cheer_x + badLuck_x;
        }
        
        else if (myPage.currentPage >= 4)//&& myPage.currentPage <= 23){//trial 1 - 20
        {
            //reset practice trials
            for (int i=0; i<2; i++) {
                testMelodys_A_v[i].reset();
                testMelodys_B_v[i].reset();
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
    
            if(myPage.bPlayGroupAMelody == true && myPage.bResetMelody == false){
                if(myPage.playPianoMelody == true){
                    trialMelodies_temp = sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].playOnce();
                    //cout << "PIANO INDEX ARRAY = " << myPage.trialMelody_1_v[myPage.trial_melody_count] << endl;
                } else if(myPage.playTrumpetMelody == true){
                    trialMelodies_temp = sessionA_Melodys_v[myPage.trialMelody_1_v[myPage.trial_melody_count]].playOnce();
                }
                
            }
            else if(myPage.bPlayGroupBMelody == true && myPage.bResetMelody == false){
                if(myPage.playPianoMelody == true){
                  trialMelodies_temp = sessionB_Melodys_v[myPage.trialMelody_2_v[myPage.trial_melody_count]].playOnce();
                } else if(myPage.playTrumpetMelody == true){
                    trialMelodies_temp = sessionB_Melodys_v[myPage.trialMelody_2_v[myPage.trial_melody_count]].playOnce();
                }
            }
            
            //if(myPage.bPlayGroupAMelody == false){
            if(myPage.bResetMelody == true){
                for (int i=0; i<20; i++) {
                    sessionA_Melodys_v[i].reset();
                }
            }
            //if(myPage.bPlayGroupBMelody == false){
            if(myPage.bResetMelody == true){
                for (int i=0; i<20; i++) {
                    sessionB_Melodys_v[i].reset();
                }
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
//    ofLog(OF_LOG_VERBOSE, "touch %d down at (%d,%d)", touch.id, touch.x, touch.y);
//    cout << "Touch Position Is ... " << touch << endl;
    balls[touch.id].moveTo(touch.x, touch.y);
    balls[touch.id].bDragged = true;
    myPage.showPage(touch.x, touch.y);
    updateTimer();//update here to only run once each touch by the user.. not in the update loop!
    
//    if(myPage.currentPage==24){
//        saveFile();//store all data to file
//        cout << "save text file" << endl;
//    }
    
    if(touch.x>900 && touch.y>500 && myPage.currentPage == -4){
        //move to page -2 of app
        myPage.currentPage = -3;
        bSelectUser = true;
    } else if(touch.x>900 && touch.y>500 && myPage.currentPage == -3){
        //move to page -1 of app?
        myPage.currentPage = -2;
        bSelectAge = true;
    } else if(touch.x>900 && touch.y>500 && myPage.currentPage == -2){
        //move to page -1 of app?
        myPage.currentPage = -1;
    }
    
    if(touch.x>900 && touch.y<200 && myPage.currentPage == -3){//Go Back One Page
        //move to page -4 of app
        myPage.currentPage = -3;
    }
    
    if(touch.x>900 && touch.y<200 && myPage.currentPage == -2){//Go Back One Page
        //move to page -3 of app
        myPage.currentPage = -3;
    }
    
    //debug!
    if(myPage.bDebug){
        if(touch.x> 400 && touch.x < 600 && touch.y<100){
            //move to page 24 of the app!!
            myPage.currentPage = 24;
        }
    }
    
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

