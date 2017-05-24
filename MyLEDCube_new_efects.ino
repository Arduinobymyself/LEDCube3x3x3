#include <LedCube.h>

#define SIZE 3
#define COLS (SIZE*SIZE)
#define TIME 500

byte levelPins[SIZE] = {11,12,13};
byte colPins[COLS] = {2,3,4,5,6,7,8,9,10};

LedCube cube(SIZE, levelPins, colPins);

void setup ()
{
  Serial.begin(9600);
}


void loop (){
    ColLevelUp();
    delay(TIME);
    OneCol();
    delay(TIME);
    RandCol();
    delay(TIME);
    CircleNonRandHS();
    delay(TIME);
    CircleNonRand();
    delay(TIME);
    CircleRand();
    delay(TIME);
    CycleDown();
    delay(TIME);
    SingleRand();
    delay(TIME);
    TestLevels();
    delay(TIME);
    
    
    // this session needs improvements
    
    //RandSingleColOff();
    //RandColDrop();
    //OneLevelAtATime1();
    //CycleUp();
    //alphabet();
    //VertBarrel(); 
    //Pyramids();
    //Helicopter();
    //Wave();
    //ColInOut();   
}


//##################### set of functions #####################
void ColLevelUp(){
  // rise entire level column
  for(byte row=1; row<=cube.getLevels(); row++){
    for(byte level=1; level<=cube.getLevels(); level++){
      cube.lightRow(row, level);
    }
  }
}

void OneCol(){
  // rise one col at time
  for(byte col=0; col<=cube.getCols(); col++){
    cube.lightRise(col,50);
  }
}

void RandCol(){
  cube.randomColumn(32,100); // (number of columns, wait duration)
 }
 
// circle around cube at a non-random level (high speed)
void CircleNonRandHS(){
  byte rotns = 1;
  byte pausetime = 20;
  byte level = 0;
  for(int i=0; i<6; i++){
    for(byte level=0; level <  SIZE; level++){
      cube.lightPerimeter(level, rotns, pausetime);
    }
  }
}

// circle around cube at a non-random level
void CircleNonRand(){
  byte rotns = 1;
  byte pausetime = 100;
  byte x=0;
    while (x < COLS) {
     for(byte level=0; level <  SIZE; level++) {

        cube.lightPerimeter(level, rotns, pausetime);
      x++;
     } 
      }
    pausetime = pausetime - 33;     
}

// circle around cube at a random level
void CircleRand(){
  
  byte x=0;
    while (x < COLS) {
    
      cube.lightPerimeter(random(0,SIZE), random(1,5), random(25,100)); 
      x++;
    } 
  }
  
// single random light at a time
void SingleRand(){
  while(1){
    for(int i=0; i<6; i++){
      cube.randomLight(10,66); 
    }
    break;
  }   
}
  
// cycle through all 64 lights (on & off)
void CycleDown(){
  int level = 0;
  int col = 0; 
  while (level < SIZE ) {
    //      if(level < 2) Serial.println("Cycle Down");     
    for(col = 0; col < COLS; col++){
      cube.lightOn(level, col);
      delay(50);
      cube.lightOff(level, col);
      delay(20);
    }
    level++;
  }
}

void TestLevels(){
  for (byte t=25; t>2; t-=2) {
    cube.lightLevel(0,t);
    cube.lightLevel(1,t);
    cube.lightLevel(2,t);
    cube.lightLevel(3,t);
  }
}




/*
// needs improvement
//cols in and out 
void ColInOut(){
    byte c=0, d=0;
    while (c <=20) {
  //    for(byte c=1, d=0; c<=20; c++){
        if(c%2 == 0){
          for(d=0; d<20; d++) {
            cube.lightColumn(6,25);
            cube.lightColumn(7,25);
            cube.lightColumn(10,25);
            cube.lightColumn(11,25);
          }
        } 
        else if(c%3 == 1) {
          for(d=0; d<40; d++) {
            cube.lightColumn(1,25);
            cube.lightColumn(4,25);
            cube.lightColumn(13,25);
            cube.lightColumn(16,25);
          }
        } 
        else {
          for(d=0; d<30; d++) {
            cube.lightColumn(2,20);
            cube.lightColumn(3,20);
            cube.lightColumn(8,20);
            cube.lightColumn(12,20);
            cube.lightColumn(15,20);
            cube.lightColumn(14,20);
            cube.lightColumn(9,20);
            cube.lightColumn(5,20);            
          }
        }
        c++;
      }
      
    }
// cycle through all 64 lights
void Wave(){
  
  cube.enableBuffer();
  cube.clearBuffer();
    int level=0;
   int col = 0; 
    while (level < SIZE) {
    // cycle through all 64 lights (on only)
    
      if (level==0) Serial.println("waves");
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
// helicopter effect...........huh?
void Helicopter(){
  
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
// works in 3x3x3
void Pyramids(){ 
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
// vertical cylinder rotating  
void VertBarrel() {
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
// turn off a single column randomly
void RandSingleColOff() {
  cube.enableBuffer();
  for(byte c=0; c<64; c++){
      cube.fillBuffer();
      cube.drawBuffer(100,0); 
      int rt=random(0,COLS);  
      for (byte lvl=0; lvl<SIZE;lvl++) cube.lightOff(lvl,rt);
      cube.drawBuffer(100,0); 
      
     }
    cube.enableBuffer(false);
    cube.invertBuffer(false);
  }
// random column drop
void RandColDrop(){
      cube.lightDrop((random(0,COLS)), random(20,100));
}
// light one level at a time, increasing speed each time 
void OneLevelAtATime1(){
  byte t=500; 
  while(t>2) { 
// if (t>497) Serial.println("One Level at a Time");   
    for(byte l=0; l<SIZE; l++){
      cube.lightLevel(l,t);
      t--;
      
          delayMicroseconds(t*43);
          
          delayMicroseconds(t*43);   
    }
  }
  int j=0;
   while( j<2000) {
    cube.lightLevel((j%SIZE),1);
         
          delayMicroseconds(200);
         
          delayMicroseconds(200);
          j++;
    }
}

// cycle backwards through all 64 lights (on & off)
void CycleUp(){
  int level = 0;
  int col = 0; 
  while (level < SIZE) {
    if(level < 2) Serial.println("Cycle UP");
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
  }
}
  
  


void alphabet()
{
  int interval = 100;
  for (int plane=0;plane<=9;plane+=3)
  {
  byte A[] = {0,0+plane, 0,2+plane, 1,0+plane, 1,1+plane, 1,2+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte B[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,0+plane,  1,1+plane, 1,2+plane, 2,0+plane};
  byte C[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,0+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte D[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,0+plane, 1,1+plane, 1,2+plane, 2,2+plane};
  byte E[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,0+plane, 1,1+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte F[] = {0,0+plane, 1,0+plane, 1,1+plane, 1,2+plane, 2,0+plane, 2,1+plane};
  byte G[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,1+plane, 1,2+plane, 2,1+plane, 2,2+plane};
  byte H[] = {0,0+plane, 0,2+plane, 1,0+plane, 1,1+plane, 1,2+plane, 2,0+plane, 2,2+plane};
  byte I[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,1+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte J[] = {0,0+plane, 0,1+plane, 1,1+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte K[] = {0,0+plane, 0,2+plane, 1,0+plane, 1,1+plane, 2,0+plane, 2,2+plane};
  byte L[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,0+plane, 2,0+plane};
  byte M[] = {0,0+plane, 0,2+plane, 1,0+plane, 1,2+plane, 2,0+plane, 2,1+plane, 2,2+plane}; //sucky M but only 3x3 :D
  byte N[] = {0,0+plane, 0,2+plane, 1,0+plane, 1,1+plane, 1,2+plane};
  byte O[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,0+plane, 1,2+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte P[] = {0,0+plane, 1,0+plane, 1,1+plane, 1,2+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte Q[] = {0,2+plane, 1,0+plane, 1,1+plane, 1,2+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte R[] = {2,0+plane, 2,1+plane, 2,2+plane, 1,0+plane, 0,0+plane};  
  byte S[] = {0,0+plane, 0,1+plane, 1,1+plane, 2,1+plane, 2,2+plane};  
  byte T[] = {0,1+plane, 1,1+plane, 2,0+plane, 2,1+plane, 2,2+plane};
  byte U[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,0+plane, 1,2+plane, 2,0+plane, 2,2+plane};
  byte V[] = {0,1+plane, 1,0+plane, 1,2+plane, 2,0+plane, 2,2+plane};
  byte W[] = {0,0+plane, 0,1+plane, 0,2+plane, 1,0+plane, 1,1+plane, 1,2+plane, 2,0+plane, 2,2+plane};
  byte X[] = {0,0+plane, 0,2+plane, 1,1+plane, 2,0+plane, 2,2+plane};
  byte Y[] = {0,1+plane, 1,0+plane, 1,1+plane, 1,2+plane, 2,0+plane, 2,2+plane};
  byte Z[] = {0,1+plane, 0,2+plane, 1,1+plane, 2,0+plane, 2,1+plane};
  
  
  cube.lightSequence(A,sizeof(A),interval);
  cube.lightSequence(B,sizeof(B),interval);
  cube.lightSequence(C,sizeof(C),interval);
  cube.lightSequence(D,sizeof(D),interval);
  cube.lightSequence(E,sizeof(E),interval);
  cube.lightSequence(F,sizeof(F),interval);
  cube.lightSequence(G,sizeof(G),interval);
  cube.lightSequence(H,sizeof(H),interval);
  cube.lightSequence(I,sizeof(I),interval);
  cube.lightSequence(J,sizeof(J),interval);
  cube.lightSequence(K,sizeof(K),interval);
  cube.lightSequence(L,sizeof(L),interval);
  cube.lightSequence(M,sizeof(M),interval);
  cube.lightSequence(N,sizeof(N),interval);
  cube.lightSequence(O,sizeof(O),interval);
  cube.lightSequence(P,sizeof(P),interval);
  cube.lightSequence(Q,sizeof(Q),interval);
  cube.lightSequence(R,sizeof(R),interval);
  cube.lightSequence(S,sizeof(S),interval);
  cube.lightSequence(T,sizeof(T),interval);
  cube.lightSequence(U,sizeof(U),interval);
  cube.lightSequence(V,sizeof(V),interval);
  cube.lightSequence(W,sizeof(W),interval);
  cube.lightSequence(X,sizeof(X),interval);
  cube.lightSequence(Y,sizeof(Y),interval);
  cube.lightSequence(Z,sizeof(Z),interval);
  }
}
*/
