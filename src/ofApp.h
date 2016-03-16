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


#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxMaxim.h"
#include "ofPage.h"
#include "Ball.h"


class ofApp : public ofxiOSApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
        void audioReceived( float * input, int bufferSize, int nChannels );
        void audioRequested( float * output, int bufferSize, int nChannels );
        int		initialBufferSize;
        int		sampleRate;
    
        void updateTimer();//method to store all timeing data ready for analysis
        void saveFile();
        void loadFile();
        void timeStampData();
        void saveTime();
        void userKeyboardInput();
        ofxiOSKeyboard * keyboard;
        ofTrueTypeFont keyboard_f;
        bool bSelectUser;
        bool bSelectAge;
        bool bPermitSaveFile;     
    
    
        string save_time_s, save_date_s;
    
        //get the ofPage as the route class all other pages will inherit from this.
        //set up for the sounds
    
        //load in songs for playback
        int testMelodys_A_Length;
        int testMelodys_B_Length;
        int sessionA_MelodysLength;
        int sessionB_MelodysLength;
    
        vector <maxiSample> testMelodys_A_v;
        vector <maxiSample> testMelodys_B_v;
        //vectors to hold both A and B melodies. The index of playback is set
        //using the variable trialMelody_1_v & trialMelody_2_v these same random
        //index values are used to place all other data output lined up for analysis
        vector <maxiSample> sessionA_Melodys_v;
        vector <maxiSample> sessionB_Melodys_v;
        
        //ofxMaxiSample sound1;//theme song
        
        ofxMaxiSample pianoSingle;
        ofxMaxiSample trumpetSingle;
        ofxMaxiSample pianoMelody;
        ofxMaxiSample trumpetMelody;
        
        //Tests for first 2 then real trial starts
        ofxMaxiSample trial1_x_piano;//3-56-4-x-piano-120
        ofxMaxiSample trial2_trumpet;//3-79-10-original-trumpet-120
        ofxMaxiSample trial3_piano;//8-1127-0-original-piano-120
        ofxMaxiSample trial4_x_trumpet;//9-622-1-x-trumpet-120
        
        //real trial starts from here
        ofxMaxiSample origional2Trumpet;
        ofxMaxiSample origional2Piano;
        ofxMaxiSample x2;
        ofxMaxiSample origional3;
        ofxMaxiSample x3;
        
        //sounds fx
        ofxMaxiSample cheer;
        ofxMaxiSample badLuck;

    
        ofPage myPage;//base class
        //ofSounds mySounds;
    
        //load in pages
        //HomePage myHomePage;
        //Introduction myIntroduction;
    
        ofPoint vel;//for accelarometer
        ofPoint vel1;
        ofPoint vel2;
        ofPoint vel3;
        ofPoint vel4;
        ofPoint vel5;
        ofPoint vel6;
        ofPoint vel7;
        
        bool accel;
        vector<Ball> balls;
    
        /*======================== variabels to store all data to text file =====================*/
    
    
        //string data
        string day_s;
        string month_s;
        string year_s;
        string hours_s;
        string seconds_s;
        string mins_s;
        string millis_s;
    
        ofFile dataFile;//load a file? use this
        string timeStamp_s;
        ofBuffer buff;
    
        string userID_s;
        string user_age_s;
        string sessionNumber_s;//either A1, A2, B1 or B2
        string time_s;
        string pianoLeft_s;//print out TRUE or FALSE
    
        //arrays to store floats of practice trial times in milliseconds
        vector<float> practice_time_data_A_v;//Number 1 and 2
        vector<float> practice_time_data_B_v;//Number 23 and 24
        //arrays to store floats of all full trial times in milliseconds
        vector<float> trial_time_data_A_v;
        vector<float> trial_time_data_B_v;
    
        //store true or false for answers
        vector<string> practice_answer_A_v;
        vector<string> practice_answer_B_v;
        vector<string> trial_answer_A_v;
        vector<string> trial_answer_B_v;

    
        //vectors to store the answers to the random order of trials
        vector<int> baseline_accuracy_A_v;//store as a true or false text!
        vector<int> baseline_accuracy_B_v;
        vector<int> trial_accuracy_A_v;//store as true or false
        vector<int> trial_accuracy_B_v;//store as true or false
    
        //vectors to store all the variables Marco has made available
        //Practice A
        vector<int> number_practice_A_v;
        vector<string> ID_practice_A_v;
        vector<string> session_practice_A_v;
        vector<string> practice_practice_A_v;
        vector<string> timbre_practice_A_v;
        vector<string> probability_practice_A_v;
        vector<string> basename_practice_A_v;
        vector<string> filename_practice_A_v;
        vector<int> pitch_practice_A_v;
        vector<int> pitch_interval_practice_A_v;
        vector<string> interval_size_practice_A_v;
        vector<string> interval_direction_practice_A_v;
        vector<float> information_content_practice_A_v;
        vector<int> probe_repetitions_practice_A_v;
        vector<int> probe_octave_repetitions_practice_A_v;
    
        //Practice B
        vector<int> number_practice_B_v;
        vector<string> ID_practice_B_v;
        vector<string> session_practice_B_v;
        vector<string> practice_practice_B_v;
        vector<string> timbre_practice_B_v;
        vector<string> probability_practice_B_v;
        vector<string> basename_practice_B_v;
        vector<string> filename_practice_B_v;
        vector<int> pitch_practice_B_v;
        vector<int> pitch_interval_practice_B_v;
        vector<string> interval_size_practice_B_v;
        vector<string> interval_direction_practice_B_v;
        vector<float> information_content_practice_B_v;
        vector<int> probe_repetitions_practice_B_v;
        vector<int> probe_octave_repetitions_practice_B_v;
        
        //A SESSION
        vector<int> number_A_v;
        vector<string> ID_A_v;
        vector<string> session_A_v;
        vector<string> practice_A_v;
        vector<string> timbre_A_v;
        vector<string> probability_A_v;
        vector<string> basename_A_v;
        vector<string> filename_A_v;
        vector<int> pitch_A_v;
        vector<int> pitch_interval_A_v;
        vector<string> interval_size_A_v;
        vector<string> interval_direction_A_v;
        vector<float> information_content_A_v;
        vector<int> probe_repetitions_A_v;
        vector<int> probe_octave_repetitions_A_v;
        //B SESSION
        vector<int> number_B_v;
        vector<string> ID_B_v;
        vector<string> session_B_v;
        vector<string> practice_B_v;
        vector<string> timbre_B_v;
        vector<string> probability_B_v;
        vector<string> basename_B_v;
        vector<string> filename_B_v;
        vector<int> pitch_B_v;
        vector<int> pitch_interval_B_v;
        vector<string> interval_size_B_v;
        vector<string> interval_direction_B_v;
        vector<float> information_content_B_v;
        vector<int> probe_repetitions_B_v;
        vector<int> probe_octave_repetitions_B_v;
    
        //final vectors to concatinate all the variables
        vector<string> userID_v;
        vector<string> user_age_v;
        vector<string> session_number_v;//A1, A2, B1 or B2
        vector<string> session_order_v;//AB or BA
        vector<string> date_v;
        vector<string> time_v;
        vector<string> piano_left_v;//true or false
        vector<float> reaction_time_v;
        vector<string> answer_v;
        vector<int> number_v;
        vector<string> ID_v;
        vector<string> session_v;
        vector<string> practice_v;
        vector<string> timbre_v;
        vector<string> probability_v;
        vector<string> basename_v;
        vector<string> filename_v;
        vector<int> pitch_v;
        vector<int> pitch_interval_v;
        vector<string> interval_size_v;
        vector<string> interval_direction_v;
        vector<float> information_content_v;
        vector<int> probe_repetitions_v;
        vector<int> probe_octave_repetitions_v;
    
    
    
        //create all the char's needed to fill the arrays apropriatley.
        string ap1, ap2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, bp1, bp2, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, session_A, session_B, practice_yes, practice_no, timbre_piano, timbre_trumpet, probability_high, probability_low, base_1, base_2, base_3, base_4, base_5, base_6, base_7, base_8, base_9, base_10, base_11, base_12, base_13, base_14, base_15, base_16, base_17, base_18, base_19, base_20, base_21, base_22, base_23, base_24, base_25, base_26, base_27, base_28, base_29, base_30, base_31, base_32, base_33, base_34, base_35, base_36, base_37, base_38, base_39, base_40, base_41, base_42, base_43, base_44, filename_1, filename_2, filename_3, filename_4, filename_5, filename_6, filename_7, filename_8, filename_9, filename_10, filename_11, filename_12, filename_13, filename_14, filename_15, filename_16, filename_17, filename_18, filename_19, filename_20, filename_21, filename_22, filename_23, filename_24, filename_25, filename_26, filename_27, filename_28, filename_29, filename_30, filename_31, filename_32, filename_33, filename_34, filename_35, filename_36, filename_37, filename_38, filename_39, filename_40, filename_41, filename_42, filename_43, filename_44, pitch_interval_small, pitch_interval_large, interval_direction_descending, interval_direction_ascending, correct, wrong;
        //store completed data in strings
        string practice_data_s, melody_data_A_s, melody_data_B_s;
    
    

};


