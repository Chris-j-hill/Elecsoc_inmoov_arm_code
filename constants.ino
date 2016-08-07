#include "Servo.h"


Servo thumb;    //global objects accessable in all functions. use servo object for each finger
Servo first;
Servo second;
Servo third;
Servo fourth;

int rock_first = 40;   //define global variables for positions of fingers for each hand movement. set these as required
int rock_second = 50;
int rock_third = 60;
int rock_fourth = 70;
int rock_thumb = 80;

int paper_first = 90;
int paper_second = 100;
int paper_third = 110;
int paper_fourth = 120;
int paper_thumb = 130;

int scissors_first = 160;
int scissors_second = 150;
int scissors_third = 140;
int scissors_fourth = 130;
int scissors_thumb = 120;

int thumb_upper = 180;      //mechanical limtis for fingers
int thumb_lower = 0;
int thumb_range = thumb_upper - thumb_lower;
int thumb_mid = thumb_lower + thumb_range/2; 


int first_upper = 180;
int first_lower = 0;
int first_range = first_upper - first_lower;
int first_mid = first_lower + first_range/2; 

int second_upper = 180;
int second_lower = 0;
int second_range = second_upper - second_lower;
int second_mid = second_lower + second_range/2; 

int third_upper = 180;
int third_lower = 0;
int third_range = third_upper - third_lower;
int third_mid = third_lower + third_range/2; 

int fourth_upper = 180;
int fourth_lower = 0;
int fourth_range = fourth_upper - fourth_lower;
int fourth_mid = fourth_lower + fourth_range/2; 
            
int period =4000;               //4 seconds to cycle in and out
int flag3 = 0;
int flag4 = 0;
int finger_lag = (3.14159/8); 
int start_time;

