
void initialise_arm(){
thumb.attach(10);
first.attach(9);
second.attach(6);
third.attach(5);
fourth.attach(3);

 thumb.write(thumb_mid);                     //set everything to a neutral point, there shouldn't be large forces on the motors here
 delay(250);                          //small delay so as not to draw too much current by running all servos
 first.write(first_mid);
 delay(250);
 second.write(second_mid);
 delay(250);
 third.write(third_mid);
 delay(250);
 fourth.write(fourth_mid);
}


void middle_pos(){

  thumb.write(thumb_mid);                     //set everything to a neutral point, there shouldn't be large forces on the motors here
 delay(250);                          //small delay so as not to draw too much current by running all servos
 fourth.write(fourth_mid);
 delay(250);
 first.write(first_mid);
 delay(250);
 third.write(third_mid);
 delay(250);
 second.write(second_mid);
 delay(250);
 
}
void play(){
  int temp = random(0,4);
  middle_pos();
  Serial.println("Lets play!");
  delay(1000);

  Serial.println("Rock...");
  delay(500);

  Serial.println("Paper...!");
  
  delay(500);

  digitalWrite(12,HIGH);
  Serial.println("Scissors!");
  delay(500);
  digitalWrite(12,LOW);
  Serial.println("\n\n");
  
  if (temp ==1){
  rock();
  Serial.println("Rock!");
  }

  else if(temp ==2){
  paper();
  Serial.println("Paper!");
  }

  else if (temp ==3){
  scissors();
  Serial.println("Scissors!");
  }
  
}


void rock (){
first.write(rock_first);
second.write(rock_second);
third.write(rock_third);
fourth.write(rock_fourth);
thumb.write(rock_thumb);
  
}

void paper (){
first.write(paper_first);
second.write(paper_second);
third.write(paper_third);
fourth.write(paper_fourth);
thumb.write(paper_thumb);
  
}


void scissors (){
first.write(scissors_first);
second.write(scissors_second);
third.write(scissors_third);
fourth.write(scissors_fourth);
thumb.write(scissors_thumb);
  
}
void set_pos (String finger, int pos){
  if (check_limits(finger, pos)){      //check mechanically save position
    if (finger == "first"){     //check it matches an active servo
      first.write(pos);
    }
    else if(finger =="second"){
      second.write(pos);
    }
    else if(finger =="third"){
      third.write(pos);
    }
    
    else if(finger =="fourth"){
      fourth.write(pos);
    }
    
    else if(finger == "thumb"){
      thumb.write(pos);      
    }
    
  }
}

int check_limits (String finger, int pos){    //compares a position to finger limtis to avoid moving outside mechanical limtis
  if (finger == "thumb"){
    if (pos > thumb_lower && pos < thumb_upper)
      return 1;   //all good

    else 
      return 0;   //not all good
  }

  else if (finger == "first"){
    if (pos > first_lower && pos < first_upper)
      return 1;   

    else 
      return 0;  
  }

  else if (finger == "second"){
    if (pos > second_lower && pos < second_upper)
      return 1;   

    else 
      return 0;   
  }

  else if (finger == "third"){
    if (pos > third_lower && pos < third_upper)
      return 1;   
      
    else 
      return 0;   
  }
  
  else if (finger == "fourth"){
    if (pos > fourth_lower && pos < fourth_upper)
      return 1;   

    else 
      return 0;   
  }
  
  else {
    Serial.println("cannot check limtis correctly");
    return 0;
  }
  }


void increment(String finger, int increment){

  if (finger == "first"){
    int pos = first.read();
    if (check_limits(finger, pos+increment))
    first.write(increment +pos);
  }
  else if(finger =="second"){
    int pos = second.read();
    if (check_limits(finger, pos+increment))
    second.write(increment +pos);
  }
  else if(finger =="third"){
    int pos = third.read();
    if (check_limits(finger, pos+increment))
    third.write(increment+pos);
  }
  
  else if(finger =="fourth"){
    int pos = fourth.read();
    if (check_limits(finger, pos+increment))
    fourth.write(increment +pos);
  }
  
  else if(finger == "thumb"){
    int pos = thumb.read();
    if (check_limits(finger, pos+increment))
    thumb.write(increment +pos);      
  }
  else{
  }
  
}

void increment_multipul(String Finger){
  Serial.println("increment value 5 degrees");
  Serial.println("positive increment (w) or negitive(s) or exit(other)");
  
  int flag2 =0; 
  while(flag2==0){    
   
  if (Serial.available()>0){
   char temp = Serial.read();
   
   if (temp == 'w' ){
   increment (Finger, 5);
   
   }

   else if (temp == 's'){
    increment(Finger, -5);
    
   }
   else{        //break if another letter is entered
   flag2=1;
   }
  Serial.println(finger_pos(Finger));
}
} 
}



void print_pos(){

Serial.println("Finger name (thumb,  first,  second,  third,  fourth)");
Serial.print("Position");
Serial.print("\t");
Serial.print(thumb.read());
Serial.print("\t");
Serial.print(first.read());
Serial.print("\t");
Serial.print(second.read());
Serial.print("\t");
Serial.print(third.read());
Serial.print("\t");
Serial.println(fourth.read());
}

int finger_pos (String finger){
  if (finger == "thumb"){
    return(thumb.read());
  }
  
  if (finger == "first"){
    return(first.read());
  }
    
   if (finger == "second"){
     return(second.read());
    }
    
   if (finger == "third"){
     return(third.read());
    }
    
   if (finger == "fourth"){
     return(fourth.read());
    }


}


void ripple_fingers(){        //ripple finger in and out, the aim of this function design is to not use the microcontroller continuously so it needs to be called regularly

  int pos1, pos2, pos3, pos4;
  
  if (flag3 == 0)   { //first iteration only
    flag3 =1;         //set so it wont execute this again
    
    pos1 = first_mid; //set initial positions
    pos2 = second_mid;
    pos3 = third_mid;
    pos4  = fourth_mid;
    
    start_time = millis();      //find start time
    
  }
  
  else {
    
    int time_now = millis()-start_time;    //figure out how long its been since first execution of this function
    
    pos1 = first_mid + (first_range/2) * sin((time_now * 3.14159) / period + finger_lag*0);   //set positions with respect to the time based off a function 
    pos2 = second_mid + (second_range/2) * sin((time_now * 3.14159) / period + finger_lag*1); //(possibly piecewise linear function required)
    pos3 = third_mid + (third_range/2) * sin((time_now * 3.14159) / period + finger_lag*2);
    pos4 = fourth_mid + (fourth_range/2) * sin((time_now * 3.14159) / period + finger_lag*3);
  
  }
  
  first.write(pos1);
  second.write(pos2);
  third.write(pos3);
  fourth.write(pos4);
}


void in_and_out(){

int pos1, pos2, pos3, pos4, pos5;
  
  if (flag4 == 0)   { //first iteration only
    flag4 =1;         //set so it wont execute this again
    
    pos1 = first_mid; //set initial positions
    pos2 = second_mid;
    pos3 = third_mid;
    pos4  = fourth_mid;
    
    start_time = millis();      //find start time
    
  }
  
  else {
    
    int time_now = millis()-start_time;    //figure out how long its been since first execution of this function
    int temp = sin((time_now * 3.14159) / period);
    
    pos1 = first_mid + (first_range/2) * temp;    //set positions with respect to the time
    pos2 = second_mid + (second_range/2) * temp;
    pos3 = third_mid + (third_range/2) * temp;
    pos4 = fourth_mid + (fourth_range/2) * temp;
    pos5 = thumb_mid + (thumb_range/2) * temp;
  
  }
  
  first.write(pos1);
  second.write(pos2);
  third.write(pos3);
  fourth.write(pos4);
  thumb.write(pos5);
}

void reset_actions(){
  flag3 =0;
  flag4 =0;
  
}

