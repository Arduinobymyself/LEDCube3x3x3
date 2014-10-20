#include <LedCube.h>
#define SIZE 3
#define COLS (SIZE*SIZE)
#define TIME 2000


byte levelPins[SIZE] = {11,12,13};
//level-1, level-2, level-3
byte colPins[COLS] = {2,3,4,5,6,7,8,9,10};
// col-1, col-4, col-7, col-5, col-2, col-8, col-9, col-6, col-3 

byte level = 0;
byte col = 0;

LedCube cube(SIZE, levelPins, colPins);

void setup ()
{
  Serial.begin(9600);
  Serial.println("MpM's 3x3x3 LED Cube running.....");
}

void loop () {
  delay(100);
  cube.enableBuffer(false);
  
  // brute force functions (on/off)
  TestLevels();
  delay(TIME); 
  RandColDrop();
  delay(TIME);
  SingleRand();
  delay(TIME); 
  CircleRand();
  delay(TIME); 
  CycleDown();
  delay(TIME);
  RandCol();
  delay(TIME);
  RandSingleColOff();
  delay(TIME);
  ColInOut();
  delay(TIME);
  SinglSeq();
  delay(TIME);
  LineSeq();
  delay(TIME);
  PlaneSeq();
  delay(TIME);
  FaceToFace();
  delay(TIME);
  CircleNonRandHS();
  delay(TIME);
  ExtInt();
  delay(TIME);
  DiamondBox3x3x3();
  delay(TIME);
  //OneLevelAtATime1();
  //delay(TIME);
  Helicopter3x3x3();
  delay(TIME);
  Helicopter();
  delay(TIME);
  Swiming();
  delay(TIME);
  CircleNonRand(); 
  delay(TIME);
  OneAtTimeOff();
  delay(TIME);
  NewsEffects();
  delay(TIME);
  HorizBarrel();
  delay(TIME);
  
  
  
  //vertBarrel();
  //delay(TIME); 
  //CycleUp(); 
  // delay(TIME);
  // buffered functions (low light output) now work for 4x4x4
  //DiamondBox4x4x4();
  //Pyramids(); 
  //Wave(); 
  //Helicopter4x4x4(); I don't know what's up with this one
  //TurnOff();
  //BarrelRolls();
  //PopCorn();
  //HorizBarrel2() 
}

void OneAtTimeOff(){
  Serial.println("Turn off one LED at a time.");
  cube.enableBuffer();
  cube.fillBuffer();
  cube.drawBuffer(25);
    for(byte w=0, l, c, max = cube.getNumLights(); w<max; ){
      // lower bound is inclusive, upper is exclusive
      l = random(0, cube.getLevels());
      c = random(0, cube.getCols());
      if(cube.getBufferAt(l,c) == HIGH){
        cube.lightOff(l,c);
        cube.drawBuffer(5);
        w++;
      }
    }
    cube.enableBuffer(false);
    Serial.flush();
    delay(TIME);
}

void Swiming(){
  Serial.println("Swimming's effect, in each level.");
  byte topSeq1[8] = {0,1,2,1,0,1,2,1};
  byte botSeq1[8] = {8,7,6,7,8,7,6,7};
    for(int i=0; i<3; i++){
      for(byte loops = 0, delay = 50; loops<=8; loops++){
        for(byte s=0; s<8; s++){
          byte seq[] = {i,topSeq1[s], i,4, i,botSeq1[s]};
          cube.lightSequence(seq, sizeof(seq), delay);
        } 
        if(loops < 5) delay-=10;  else delay += 10;
      }
    }
  }

void Helicopter(){
  Serial.println("Helicopter's effect 2.");
  byte topSeq2[8] = {0,3,6,7,8,5,2,1};
  byte botSeq2[8] = {8,5,2,1,0,3,6,7};
  for(int i=0; i<3; i++){
    for(byte loops = 0, delay = 50; loops<=8; loops++){
      for(byte s=0; s<8; s++){
        byte seq[] = {i,topSeq2[s], i,4, i,botSeq2[s]};
        cube.lightSequence(seq, sizeof(seq), delay);
      }
      if(loops < 5) delay-=10;  else delay += 10;
    }
  }
}

void Helicopter3x3x3(){
  Serial.println("Helicopter's effect 1.");
  byte topSeq[8] = {0,3,6,7,8,5,2,1};
  byte botSeq[8] = {8,5,2,1,0,3,6,7};
  for(byte loops = 0, delay = 50; loops<=8; loops++){
    for(byte s=0; s<8; s++){
      byte seq[] = {2,topSeq[s], 1,4, 0,botSeq[s]};
      cube.lightSequence(seq, sizeof(seq), delay);
    }
    if(loops < 5) delay-=10;  else delay += 10;
  }
}

void DiamondBox3x3x3(){
  Serial.println("Box and Diamond.");
  byte diamond[] = {0,4,  1,1, 1,3, 1,4, 1,5, 1,7,   2,4};
  byte box[] = {
        2,0, 2,1, 2,2, 2,3, 2,5, 2,6, 2,7, 2,8,
        1,0, 1,2, 1,6, 1,8,
        0,0, 0,1, 0,2, 0,3, 0,5, 0,6, 0,7, 0,8
  };
  cube.lightSequence(box, sizeof(box), 200);
  cube.lightSequence(diamond, sizeof(diamond), 400);
}

void ExtInt(){
  Serial.println("Lights up corners columns and after internal columns vertically.");
  for(byte c=1, d=0; c<=10; c++){
    if(c%2 == 0){
      for(d=0; d<20; d++){
        cube.lightColumn(2,1);
        cube.lightColumn(4,1);
        cube.lightColumn(6,1);
        cube.lightColumn(8,1);
      }
    }
    else if(c%4 == 1){
      for(d=0; d<30; d++){
        cube.lightColumn(1,1);
        cube.lightColumn(3,1);
        cube.lightColumn(7,1);
        cube.lightColumn(9,1);
      }
    }
    else{
      for(d=0; d<70; d++){
        cube.lightColumn(5,1);
      }
    }
  }
}

void FaceToFace(){
  Serial.println("Lights up each face at time in sequence.");
  byte planes[] = {cube.getLevels()+1,cube.getLevels(),cube.getLevels()*2,1};
  for(byte i=5; i; i--){
    for(byte p=0; p<sizeof(planes); p++){
      cube.lightPlane(planes[p], 5*i);
    }
  }
}

void PlaneSeq(){
  Serial.println("Lights up each plan in sequence.");
  for(byte i=3; i; i--){
    for(byte row=1; row<=cube.getLevels()*2; row++){
      cube.lightPlane(row, 10*i);
      }
    }
}

void SinglSeq(){
  Serial.println("Lights up a single LED at a time, in sequence.");
  for(byte level=0; level<cube.getLevels(); level++){
    for(byte col=0; col<cube.getCols(); col++){
      cube.lightPulse(level, col, 50);
    }
  }
}

void LineSeq(){
  Serial.println("Lights up a line of LEDs at a time, in sequence.");
  for(byte level=1; level<=cube.getLevels(); level++){
    for(byte row=1; row<=cube.getLevels()*2; row++){
      cube.lightRow(row, level);
    }
  }
}

void CycleDown(){
  Serial.println("Cycle Down");
  int level = 0; 
  while (level < SIZE ) {
    for(col = 0; col < COLS; col++){
      cube.lightOn(level, col);
      delay(50);
      cube.lightOff(level, col);
      delay(20);
    }
    level++;
  }
}
 
void CycleUp(){
  // cycle backwards through all 64 lights (on & off)      
      int level = 0; 
    while (level < SIZE) {
       byte col=0;
       while (col < COLS) {
       for(col = 0; col <= COLS; col++)  {         
          byte level2 = 3 - level;
          byte col2 = 15 - col;
          cube.lightOn(level2, col2);
          delay(50);
          cube.lightOff(level2, col2);
          
          delay(20);
        }
        level++;
      }
    }}
  

void OneLevelAtATime1(){
  Serial.println("Lights up one level at a time, in sequence.");
  // light one level at a time, increasing speed each time 
  byte t=30; 
  while(t>2){
    for(byte l=1; l<SIZE+1; l++){
      cube.lightLevel(l,t);
      t--;
    }
  }
  /*
  int j=0;
    while( j<2000){
      cube.lightLevel((j%SIZE),1);
      j++;
    }
    */
}

void TestLevels(){
  // change t to increase or decrease velocity
  Serial.println("Test Levels");
  for (byte t=25; t>2; t-=2) {
    cube.lightLevel(0,t);
    cube.lightLevel(1,t);
    cube.lightLevel(2,t);
    cube.lightLevel(3,t);
  }
}

void SingleRand(){
  Serial.println("Lights up a single LED at a time, randomically.");
  // single random light at a time
  while(1){
    for(int i=0; i<6; i++){
      cube.randomLight(10,66); 
    }
    break;
  }   
}

void RandColDrop(){
  Serial.println("Drop a column Randomically.");
  // random column drop  -- spund adjusted in LedCube4x4.cpp
  for(int i=0; i<18; i++){
    cube.lightDrop((random(0,COLS)), random(20,100));          
  }
}

void CircleRand(){
  Serial.println("Circle a LED in each plan, randomically."); 
  // circle around cube at a random level
  byte x=0;
    while (x < COLS) {
      cube.lightPerimeter(random(0,SIZE), random(1,5), random(25,100)); 
      x++;
    } 
  }

void CircleNonRand(){
  Serial.println("Circle a LED in each plan, non randomically.");
  // circle around cube at a non-random level
  byte rotns = 1;
  byte pausetime = 100;
  byte x=0;
    while (x < COLS){
     for(byte level=0; level <  SIZE; level++) {
        cube.lightPerimeter(level, rotns, pausetime);
      x++;
     } 
      }
    pausetime = pausetime - 33;  
    }
    
void CircleNonRandHS(){
  Serial.println("Circle a LED in each plan, non randomically with high speed.");
  // circle around cube at a non-random level (high speed)
  byte rotns = 1;
  byte pausetime = 20;
  byte level = 0;
  for(int i=0; i<6; i++){
    for(byte level=0; level <  SIZE; level++){
      cube.lightPerimeter(level, rotns, pausetime);
    }
  }
}
      
void RandCol(){
  Serial.println("Lights up a column, randomically."); 
  cube.randomColumn(32,100); // (number of columns, wait duration)
 }

void RandSingleColOff() {
  Serial.println("Turn off a single column.");
  // turn off a single column randomly
  cube.enableBuffer();
  for(byte c=0; c<19; c++){
    cube.fillBuffer();
    cube.drawBuffer(10); 
    int rt=random(0,COLS);  
    for (byte lvl=0; lvl<SIZE;lvl++) cube.lightOff(lvl,rt);
    cube.drawBuffer(10);
  }
  cube.enableBuffer(false);
  cube.invertBuffer(false);  
} 

void ColInOut(){
  Serial.println("Lights up a inner and outer column, in sequence.");
  // cols in and out -- works in 4x4x4 cube 
  byte c=0, d=0;
  while (c <=20){
    if(c < 5){
      for(d=0; d<5; d++) {
        cube.lightColumn(1,35);
        cube.lightColumn(9,35);
        cube.lightColumn(7,35);
        cube.lightColumn(3,35);
      }
    } 
    else if(c >= 5 && c < 10) {
      for(d=0; d<5; d++) {
        cube.lightColumn(2,35);
        cube.lightColumn(8,35);
        cube.lightColumn(4,35);
        cube.lightColumn(6,35);
      }
    } 
    else if(c >= 10 && c < 15){
      for(d=0; d<5; d++) {
        cube.lightColumn(1,20);
        cube.lightColumn(2,20);
        cube.lightColumn(3,20);
        cube.lightColumn(6,20);
        cube.lightColumn(9,20);
        cube.lightColumn(8,20);
        cube.lightColumn(7,20);
        cube.lightColumn(4,20);            
      }
    }
    else{
      for(d=0; d<5; d++) {
        cube.lightColumn(1,20);
        cube.lightColumn(4,20);
        cube.lightColumn(7,20);
        cube.lightColumn(8,20);
        cube.lightColumn(9,20);
        cube.lightColumn(6,20);
        cube.lightColumn(3,20);
        cube.lightColumn(2,20);            
      }
    }
    c++;
  } 
}  


void HorizBarrel() {
  Serial.println("Horizontal barrel effect");
  byte pauseT=4, d=0;
  for (int i=0; i<3; i++){
    for( d=0; d<pauseT; d++) {
      cube.lightRow(1, 1, 25);
      cube.lightRow(2, 1, 25);
    }
    for(d=0; d<pauseT; d++) {
      cube.lightRow(3, 1, 25);
      cube.lightRow(3, 2, 25);
    } 
    for(d=0; d<pauseT; d++) { 
      cube.lightRow(3, 3 ,25);
      cube.lightRow(2, 3, 25);
    } 
    for(d=0; d<pauseT; d++) { 
      cube.lightRow(1, 3, 25);
      cube.lightRow(1, 2, 25);
    }                  
  }
}





//###########################################################
void VertBarrel() {
  // vertical cylinder rotating  
    

    //  for (int count=0;count<20;count++){
      byte pauseT=6, d=0;
    //  byte  d=0;
          
          for( d=0; d<pauseT; d++) {
            cube.lightColumn(9,25);
            cube.lightColumn(5,25);
          }
            
          for(d=0; d<pauseT; d++) {
            cube.lightColumn(5,25);
            cube.lightColumn(2,25);
          } 
           for(d=0; d<pauseT; d++) { 
            cube.lightColumn(2,25);
            cube.lightColumn(3,25);
           } 
           for(d=0; d<pauseT; d++) { 
            cube.lightColumn(3,25);
            cube.lightColumn(8,25);
           }
           for(d=0; d<pauseT; d++) { 
            cube.lightColumn(8,25);            
            cube.lightColumn(12,25);
           }
           for(d=0; d<pauseT; d++) { 
            cube.lightColumn(12,25);
            cube.lightColumn(15,25);
           }
            for(d=0; d<pauseT; d++) {
            cube.lightColumn(15,25);
            cube.lightColumn(14,25);
            }
            for(d=0; d<pauseT; d++) {
            cube.lightColumn(14,25);
            cube.lightColumn(9,25);
            }
       //   if (count > 10 && count < 20) { buttoncountmod = 9; HorizBarrel();}  
       }
       
         


void HorizBarrel2() {
  // horizontal cylinder rotating  

      byte pauseT=6, d=0;
    //  byte  d=0;
          
           for( d=0; d<pauseT; d++) {
            cube.lightRow(2, 1, 25);
            cube.lightRow(3, 1, 25);
           }
            
           for(d=0; d<pauseT; d++) {
            cube.lightRow(3, 1, 25);
            cube.lightRow(4, 2, 25);
           } 
          
           for(d=0; d<pauseT; d++) { 
            cube.lightRow(4, 2 ,25);
            cube.lightRow(4, 3, 25);
           } 
           for(d=0; d<pauseT; d++) { 
            cube.lightRow(4, 3, 25);
            cube.lightRow(3, 4, 25);
           }
           for(d=0; d<pauseT; d++) { 
            cube.lightRow(3, 4, 25);            
            cube.lightRow(2, 4, 25);
           }
            for(d=0; d<pauseT; d++) { 
            cube.lightRow(2, 4, 25);
            cube.lightRow(1, 3, 25);
           }
            for(d=0; d<pauseT; d++) {
            cube.lightRow(1, 3, 25);
            cube.lightRow(1, 2, 25);
           }
            for(d=0; d<pauseT; d++) {
            cube.lightRow(1, 2, 25);
            cube.lightRow(2, 1, 25);
           }           
         
}


  
  void VertBarrel2() {   
      byte pauseT=6, d=0;         
          for( d=0; d<pauseT; d++) {
            cube.lightColumn(9,25);
            cube.lightColumn(5,25);
          }
            
          for(d=0; d<pauseT; d++) {
            cube.lightColumn(5,25);
            cube.lightColumn(2,25);
          } 
           for(d=0; d<pauseT; d++) { 
            cube.lightColumn(2,25);
            cube.lightColumn(3,25);
           } 
           for(d=0; d<pauseT; d++) { 
            cube.lightColumn(3,25);
            cube.lightColumn(8,25);
           }
           for(d=0; d<pauseT; d++) { 
            cube.lightColumn(8,25);            
            cube.lightColumn(12,25);
           }
           for(d=0; d<pauseT; d++) { 
            cube.lightColumn(12,25);
            cube.lightColumn(15,25);
           }
            for(d=0; d<pauseT; d++) {
            cube.lightColumn(15,25);
            cube.lightColumn(14,25);
            }
            for(d=0; d<pauseT; d++) {
            cube.lightColumn(14,25);
            cube.lightColumn(9,25);
            }      
       }
       
         



void DiamondBox1(){
  // diamond and box--- works in 4x4x4
  byte diamond1[] = {  
    0,5, 0,6, 0,10, 0,9, 1,1, 1,2, 1,4, 1,5, 1,6, 1,7, 1,9, 1,8, 1,10, 1,11, 1,13, 1,14,
     2,1, 2,2, 2,4, 2,5, 2,6, 2,7, 2,9, 2,8, 2,10, 2,11, 2,13, 2,14, 3,6, 3,5, 3,10, 3,9 };
  byte diamond2[] = {  
    0,5, 0,6, 0,10, 0,9, 1,1, 1,2, 1,4, 1,7, 1,8, 1,11, 1,13, 1,14,
     2,1, 2,2, 2,4, 2,7, 2,8, 2,11, 2,13, 2,14, 3,6, 3,5, 3,10, 3,9 };
  byte box[] = {  
    0,0, 0,1, 0,2, 0,3, 0,4, 0,7, 0,8, 0,11, 0,12, 0,13, 0,14, 0,15, 
    1,0, 1,3, 1,15, 1,12, 2,0, 2,3, 2,15, 2,12, 
    3,0, 3,1, 3,2, 3,3, 3,4, 3,7, 3,8, 3,11, 3,12, 3,13, 3,14, 3,15
     };
  byte core[] = { 1,5,1,6,1,9,1,10,2,5,2,6,2,9,2,10 };

      cube.lightSequence(box, sizeof(box), 300);
      cube.lightSequence(diamond1, sizeof(diamond1), 300);
      cube.lightSequence(core, sizeof(core), 1300);
      delay(700);
      cube.lightSequence(core, sizeof(core), 1300);
      cube.lightSequence(diamond2, sizeof(diamond2), 300);
      
    
}

// remaining effects use the buffer

void Pyramids(){               // works in 3x3x3, needs modification for 4x4x4
//  Serial.println("Pyramids");
    cube.enableBuffer();
    cube.fillBuffer();
    cube.invertBuffer();
    cube.lightPerimeter(0,1,50);
    byte corners[] = { 
      1,0, 1,3, 1,12, 1,15  };
    cube.lightSequence(corners, sizeof(corners));
    cube.drawBuffer(1000);
    delay(100);
    cube.lightPerimeter(2,1,50);
    cube.invertBuffer(false);
    cube.lightPerimeter(0,1,50);
    cube.drawBuffer(1000);
    delay(100);  
}

void Helicopter2(){
  // helicopter effect...........huh?
  cube.enableBuffer();
  byte topSeq[8] = { 
    0,3,6,7,8,5,2,1  };
  byte midSeq[8] = { 
    5,8,7,6,3,0,1,2  };
  byte botSeq[8] = { 
    8,5,2,1,0,3,6,7  };

    for(byte q = 0; q<3; q++){
      for(byte r = 0; r<7; r++){
        for(byte s= 0; s<8; s++){
          cube.clearBuffer();
          cube.lightOn(0,botSeq[s]);
          cube.lightOn(1,midSeq[s]);
          cube.lightOn(2,topSeq[s]);
          cube.drawBuffer(100/(r+1)); 
        }
      }
    }
}



void Wave(){
  // cycle through all 64 lights
  cube.enableBuffer();
  cube.clearBuffer();
    level=0; 
    while (level < SIZE) {
    // cycle through all 64 lights (on only)
    
      
      for(col = 0; col < COLS; col++){
        cube.lightOn(level, col);
        cube.drawBuffer(10);
        
        //delay(100);
      }
      level++;
    }
    // cycle through all 64 lights (off only)
    level=0;
    while (level < SIZE) {
    
      for(col = 0; col < COLS; col++){
        cube.lightOff(level, col);
        cube.drawBuffer(10);
        //delay(100);
      }
      level++;
    }
  }

void TurnOff() {
  // turn off one light at a time
  Serial.println("extinguish randomly");
  cube.enableBuffer();
  //cube.clearBuffer();
  cube.fillBuffer();
  cube.drawBuffer(1000); 
  for( byte w=0, l, c; w<180; w++ ) {  
    l = random(0,SIZE);
    c = random(0,COLS);
  //  pacer=(15+w*2)*2);
    if(cube.getBufferAt(l,c)){     
      cube.lightOff(l,c);    
      cube.drawBuffer((15+w*2)*2);
      Serial.println(w,DEC);
      if(w>160) {delay(1000);}    
    }
  }
}

void BarrelRolls() {
  unsigned long timerD = 0;

    timerD = millis();
    while (millis()<(timerD+2000)) HorizBarrel2();
    timerD=millis();
    while (millis()<(timerD+2000)) VertBarrel2();
  
}

void PopCorn() {              // need to implement this properly using the buffer
  byte pop = random(0,COLS); 
  cube.enableBuffer();
  cube.invertBuffer(false); 
 // cube.clearBuffer();
 // cube.fillBuffer();
  
  cube.lightLevel((SIZE-1),100);
  cube.drawBuffer(random(20,200));
  cube.lightOff((SIZE-1),pop);
  
 // for(byte q=0;q<SIZE;q++) cube.lightOff(2,q);
   
   //cube.invertBuffer();
 
  for (byte jump=(SIZE-1); jump > 0; jump--) {
 
    //  if (cube.getBufferAt(3,pop))      
          
      cube.drawBuffer(10);
      cube.lightOn(jump-1,pop);
   //   if (jump-1 == 0) cube.drawBuffer(300);
      cube.drawBuffer(random(10,200));
    
    
   pop=random(0,COLS);
   cube.clearBuffer();
   
   }
}
  

void NewsEffects(){
  Serial.println("Some new effects.");
  cube.enableBuffer(false);
  //NOTE: byte x [] = {layer,column,}; they run in sequence starting at #0(lowest layer/first column)
   
// a through f draws the letter o
byte a [] = {0,0, };
byte b [] = {0,0, 1,0, };
byte c [] = {0,0, 1,0, 2,0, };
byte d [] = {0,0, 1,0, 2,0, 2,1, };
byte e [] = {0,0, 1,0, 2,0, 2,1, 2,2, };
byte ee [] ={0,0, 1,0, 2,0, 2,1, 2,2, 1,2, };
byte f [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, };
// pushes the letter around the cube
byte g [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, 0,1, };
byte h [] = {0,1, 0,2, 1,1, 2,1, 2,2, 0,5, 1,5, 2,5, };
byte i [] = {0,2, 1,2, 2,2, 0,5, 2,5, 0,8, 1,8, 2,8, };
byte j [] = {1,2, 1,5, 1,8, 2,2, 2,8, 2,1, 2,4, 2,7, };
byte k [] = {2,2, 2,5, 2,8, 2,1, 2,7, 2,0, 2,3, 2,6, };
byte l [] = {2,6, 2,7, 2,8, 1,3, 1,5, 1,0, 1,1, 1,2, };
byte m [] = {2,6, 2,7, 2,8, 1,3, 1,5, 0,0, 0,1, 0,2, };
byte n [] = {2,3, 2,4, 2,5, 1,3, 1,5, 0,3, 0,4, 0,5, };
// puts letter back at beginning
byte o [] = {2,0, 2,1, 2,2, 1,2, 1,5, 0,3, 0,4, 0,5, };
byte p [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, 0,1, };
// letter erases
byte q [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, };
byte r [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, };
byte s [] = {0,0, 1,0, 2,0, 2,1, 2,2, };
byte t [] = {0,0, 1,0, 2,0, 2,1, };
byte u [] = {0,0, 1,0, 2,0, };
byte v [] = {0,0, 1,0, };
byte w [] = {0,0, };
byte x [] = {};
byte y [] = {};
byte z [] = {};

//for weeble wobble
byte aa [] = {2,2, 2,5, 2,8, 2,1, 2,7, 2,0, 2,3, 2,6, };
byte bb [] = {2,0, 2,1, 2,2, 2,3, 2,6, 1,8, };
byte cc [] = {2,0, 2,1, 2,2, 2,5, 2,8, 1,6, };
byte dd [] = {2,8, 2,2, 2,5, 2,6, 2,7, 1,0, };
byte ff [] = {2,0, 2,8, 2,3, 2,6, 2,7, 1,2, };
byte gg [] = {};
byte hh [] = {2,0, 2,1, 2,2, 2,3, 2,6, 1,8, };
byte ii [] = {2,0, 2,1, 2,2, 2,5, 2,8, 1,6, };
byte jj [] = {2,8, 2,2, 2,5, 2,6, 2,7, 1,0, };
byte kk [] = {2,0, 2,8, 2,3, 2,6, 2,7, 1,2, };
byte ll [] = {};
byte mm [] = {2,0, 2,1, 2,2, 2,3, 2,6, 1,8, };
byte nn [] = {2,0, 2,1, 2,2, 2,5, 2,8, 1,6, };
byte oo [] = {2,8, 2,2, 2,5, 2,6, 2,7, 1,0, };
byte pp [] = {2,0, 2,8, 2,3, 2,6, 2,7, 1,2, };
byte qq [] = {};
byte rr [] = {2,0, 2,1, 2,2, 2,3, 2,7, 1,8, };
byte ss [] = {2,0, 2,1, 2,2, 2,5, 2,8, 1,6, };
byte tt [] = {2,8, 2,2, 2,5, 2,6, 2,7, 1,0, };
byte uu [] = {2,0, 2,8, 2,3, 2,6, 2,7, 1,2, };
byte vv [] = {2,2, 2,5, 2,8, 2,1, 2,7, 2,0, 2,3, 2,6, };
byte ww [] = {2,0, 2,1, 2,2, 1,2, 1,5, 0,3, 0,4, 0,5, };
byte xx [] = {0,0, 1,0, 2,0, 2,1, 2,2, 1,2, 0,2, 0,1, };
byte yy [] = {};
byte zz [] = {};

         //NOTE: cube.lightSequence(*whichever byte you are referring to* sizeof(*that byte*), *how long you want to stay lit*);

         //for the letter sequence
         cube.lightSequence(a, sizeof(a), 20);
         cube.lightSequence(b, sizeof(b), 20);
         cube.lightSequence(c, sizeof(c), 20);
         cube.lightSequence(d, sizeof(d), 20);
         cube.lightSequence(e, sizeof(e), 20);
         cube.lightSequence(ee, sizeof(ee), 20);
         cube.lightSequence(f, sizeof(f), 20);
         cube.lightSequence(g, sizeof(g), 20);
         cube.lightSequence(h, sizeof(h), 20);
         cube.lightSequence(i, sizeof(i), 20);
         cube.lightSequence(j, sizeof(j), 20);
         cube.lightSequence(k, sizeof(k), 20);
         cube.lightSequence(l, sizeof(l), 20);
         cube.lightSequence(m, sizeof(m), 20);
         cube.lightSequence(n, sizeof(n), 20);
         cube.lightSequence(o, sizeof(o), 20);
         cube.lightSequence(p, sizeof(p), 20);
         cube.lightSequence(q, sizeof(q), 20);
         cube.lightSequence(r, sizeof(r), 20);
         cube.lightSequence(s, sizeof(s), 20);
         cube.lightSequence(t, sizeof(t), 20);
         cube.lightSequence(u, sizeof(u), 20);
         cube.lightSequence(v, sizeof(v), 20);
         cube.lightSequence(w, sizeof(w), 20);
         cube.lightSequence(x, sizeof(x), 100);
         cube.lightSequence(y, sizeof(y), 100);
         cube.lightSequence(z, sizeof(z), 100);
         delay(2000);
         //for weeble wobble sequence
         cube.lightSequence(aa, sizeof(aa), 20);
         cube.lightSequence(bb, sizeof(bb), 20);
         cube.lightSequence(cc, sizeof(cc), 20);
         cube.lightSequence(dd, sizeof(dd), 20);
         cube.lightSequence(ff, sizeof(ff), 20);
         cube.lightSequence(gg, sizeof(gg), 200);
         cube.lightSequence(hh, sizeof(hh), 20);
         cube.lightSequence(ii, sizeof(ii), 20);
         cube.lightSequence(jj, sizeof(jj), 20);
         cube.lightSequence(kk, sizeof(kk), 20);
         cube.lightSequence(ll, sizeof(ll), 200);
         cube.lightSequence(mm, sizeof(mm), 20);
         cube.lightSequence(nn, sizeof(nn), 20);
         cube.lightSequence(oo, sizeof(oo), 20);
         cube.lightSequence(pp, sizeof(pp), 20);
         cube.lightSequence(qq, sizeof(qq), 200);
         cube.lightSequence(rr, sizeof(rr), 20);
         cube.lightSequence(ss, sizeof(ss), 20);
         cube.lightSequence(tt, sizeof(tt), 20);
         cube.lightSequence(uu, sizeof(uu), 20);
         cube.lightSequence(vv, sizeof(vv), 20);
         cube.lightSequence(ww, sizeof(ww), 20);
         cube.lightSequence(xx, sizeof(xx), 20);
         cube.lightSequence(yy, sizeof(yy), 200);
         cube.lightSequence(zz, sizeof(zz), 200);
         delay(2000);
         
}



//-------------end of "normal patterns"----------------------//


/* the pointer direction functions.... still need work
void NE6(){
  // northeast from pin 6
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0  };
  int horizontal[8] = {  
    6, 3, 0, 1, 2, 5, 8, 7  };  
   for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }
}

void NE0(){
  // northeast from pin 0
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0    };
  int horizontal[8] = {  
    0, 1, 2, 5, 8, 7, 6, 3    };
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }
}

void NE02(){
  // northeast from pin 0
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0      };
  int horizontal[8] = {  
    0, 3, 6, 7, 8, 5, 2, 1      };
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }
}

void NW2(){
  // northwest from pin 2
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    2, 1, 0, 3, 6, 7, 8, 5                                             }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    } 
}

void N0(){
  // north from pin 0
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    0, 0, 0, 3, 6, 6, 6, 3                                             }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }  
}

void N1(){
  // north from pin 1
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    1, 1, 1, 4, 7, 7, 7, 4                                             };
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }  
}

void N2(){
  // north from pin 2
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    2, 2, 2, 5, 8, 8, 8, 5                                             };
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    } 
}

void BK0(){
  // back from pin 0
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    0, 0, 0, 1, 2, 2, 2, 1                                             }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }  
}

void BK3(){
  // back from pin 3
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0                                             };
  int horizontal[8] = {  
    3, 3, 3, 4, 5, 5, 5, 4                                             }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    }
}

void BK6(){
  // back from pin 6
  int vertical[8] = {  
    0, 1, 2, 2, 2, 1, 0, 0   };
  int horizontal[8] = {  
    6, 6, 6, 7, 8, 8, 8, 7   }; 
    for(byte iter=0; iter<=8; iter++){
      cube.lightOn(vertical[iter],horizontal[iter]);
      delay(10);
      cube.lightOff(vertical[iter],horizontal[iter]);
    } 
}

*/  
  


//******** re-released into the public domain by Alsetalokin, February 2012********//
