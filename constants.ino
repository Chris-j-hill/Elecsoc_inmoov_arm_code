#include "Servo.h"


Servo thumb;    //global objects accessable in all functions. use servo object for each finger
Servo first;
Servo second;
Servo third;
Servo fourth;


int thumb_upper = 125;      //mechanical limtis for fingers
int thumb_lower = 5;
int thumb_range = thumb_upper - thumb_lower;
int thumb_mid = thumb_lower + thumb_range/2; 


int first_upper = 155;
int first_lower = 30;
int first_range = first_upper - first_lower;
int first_mid = first_lower + first_range/2; 

int second_upper = 160;   //note, due to motor reversed in frame this motor operates in reverse direction, upper limit is closed finger
int second_lower = 10;
int second_range = second_upper - second_lower;
int second_mid = second_lower + second_range/2; 

int third_upper = 150;
int third_lower = 20;
int third_range = third_upper - third_lower;
int third_mid = third_lower + third_range/2; 

int fourth_upper = 120;
int fourth_lower = 15;
int fourth_range = fourth_upper - fourth_lower;
int fourth_mid = fourth_lower + fourth_range/2; 

int rock_first = first_lower;   //define global variables for positions of fingers for each hand movement. set these as required
int rock_second = second_upper;   //note, reverse connected
int rock_third = third_lower;
int rock_fourth = fourth_lower;
int rock_thumb = thumb_lower;

int paper_first = first_upper;
int paper_second = second_lower;
int paper_third = third_upper;
int paper_fourth = fourth_upper;
int paper_thumb = thumb_upper;

int scissors_first = first_upper;
int scissors_second = second_lower;
int scissors_third = third_lower;
int scissors_fourth = fourth_lower;
int scissors_thumb = thumb_upper;

            
int period =4000;               //4 seconds to cycle in and out
int flag3 = 0;
int flag4 = 0;
int finger_lag = (3.14159/8); 
int start_time;

