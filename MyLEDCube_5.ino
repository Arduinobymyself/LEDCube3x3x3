/*******************************************************************************************
  3 X 3 X 3  Single Color LED Cube
  cube built by Hassan Ali
  Started on June 26 2012
  www.islandByte.com
  Cube built for multiplexing - using 3 pins and 3 transistors to contorl the rows 1-3
  And using 9 pins to control the Coloums 1-9
  This gives Arduino control of 27 LEDS by using only 12 pins.
 *******************************************************************************************/
 
/* 
  Layout for the 3x3x3 cube
  Row 1 = Top layer, 9 LEDs
  Row 2 = Middle Layer, 9 LEDs
  Row 3 = Bottom layer, 9 LEDs
  
  Col 1 = Front Left 3 LEDS 1 top, 2 middle, 3 bottom
  Col 2 = Front Middle 3 LEDS 4 top, 5 middle, 6 bottom
  Col 3 = Front Right 3 LEDS 7 top, 8 middle, 9 bottom
  
  ****need to complete this documentation 
  Col 4 = Middle Right 3 LEDS - 8 top, 9 middle, 10 bottom
  Col 3 = Front Right 3 LEDS 7 top, 8 middle, 9 bottom
  Col 3 = Front Right 3 LEDS 7 top, 8 middle, 9 bottom
  Col 3 = Front Right 3 LEDS 7 top, 8 middle, 9 bottom
  Col 3 = Front Right 3 LEDS 7 top, 8 middle, 9 bottom
  Col 3 = Front Right 3 LEDS 7 top, 8 middle, 9 bottom
*/
 
 
// Row control
int ledRow1 = 13;  //Row 1
int ledRow2 = 12;  //Row 2
int ledRow3 = 11;  //Row 3


//Cols 1,2,3 + Rows can control LEDS 1-9
int ledCol1 = 2;
int ledCol2 = 3;
int ledCol3 = 4;

//Cols 4,5,6 + Rows can control LEDS 10-12
int ledCol4 = 5;
int ledCol5 = 6;
int ledCol6 = 7;

//Cols 4,5,6 + Rows can control LEDS 10-12
int ledCol7 = 8;
int ledCol8 = 9;
int ledCol9 = 10;


//define the LED cube size
int rowmax = 3;
int colmax = 9;
//making an array
int ledCol[9];
int ledRow[3];

// the setup routine runs once when you press reset:
void setup() {                
  
  //used for random value
  //Serial.begin(9600);
  // initialize the digital pin as an output.
  
  //3 rows
  pinMode(ledRow1, OUTPUT); //Top
  pinMode(ledRow2, OUTPUT); //Middle
  pinMode(ledRow3, OUTPUT); //Bottom
  
  //9 Columns
  pinMode(ledCol1, OUTPUT); //Left
  pinMode(ledCol2, OUTPUT); //Middle
  pinMode(ledCol3, OUTPUT); //Right
  pinMode(ledCol4, OUTPUT); //Left
  pinMode(ledCol5, OUTPUT); //Middle
  pinMode(ledCol6, OUTPUT); //Right
  pinMode(ledCol7, OUTPUT); //Left
  pinMode(ledCol8, OUTPUT); //Middle
  pinMode(ledCol9, OUTPUT); //Right
  
  
  //fill array
  ledCol[0] = ledCol1;
  ledCol[1] = ledCol2;
  ledCol[2] = ledCol3;
  ledCol[3] = ledCol4;
  ledCol[4] = ledCol5;
  ledCol[5] = ledCol6;
  ledCol[6] = ledCol7;
  ledCol[7] = ledCol8;
  ledCol[8] = ledCol9;
  
  ledRow[0] = ledRow1;
  ledRow[1] = ledRow2;
  ledRow[2] = ledRow3;

  testAllLEDs(); //checks all the LEDS make sure they can all light. 
}

// the loop routine runs over and over again forever:
void loop() {
  
  frontPaneFigure8();
  rightPaneFigure8();
  backPaneFigure8();
  leftPaneFigure8();
  middleUpDown();
  
  antiClockwise(50);
  antiClockwise(60);
  antiClockwise(70);

 
  clockwise(70);
  clockwise(60);
  clockwise(50);
  
  
  frontToBackPane();
  rightToLeftPane();
  backToFrontPane();
  leftToRightPane();
  //bottomToTopPanel();
  topToBottomPanel();
  
  panelRotateCW();
  panelRotateCW();
  panelRotateCW();
  panelRotateCW();
  panelRotateCW();
  panelRotateCW();
  panelRotateCW();
  
  panelRotateAntiCW();
  panelRotateAntiCW();
  panelRotateAntiCW();
  panelRotateAntiCW();
  panelRotateAntiCW();
  panelRotateAntiCW();
  panelRotateAntiCW();
  
  delay(100);
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  paneFTR();
  paneRTB();
  paneBTL();
  paneLTF();
  
  delay(100);
  rainLight();
  lightning();
  rainMed();
  lightning();
  rainHeavy();
  
  delay(300);
}
//end main loop




//All helper functions used to create designs and patters throughout the loop
//LED movements

//flashes both top and bottom panes
void lightning(){
    topPaneOn();
    bottomPaneOn();
    delay(25);
    topPaneOff();
    bottomPaneOff();
    delay(100);
    topPaneOn();
    bottomPaneOn();
    delay(25);
    topPaneOff();
    bottomPaneOff();
    topPaneOn();
    bottomPaneOn();
    delay(25);
    topPaneOff();
    bottomPaneOff();
    delay(100);
}



//animate
void rndUpDown(){
    randomSeed(analogRead(0)%100);
    int row = random(0,100);
    
}

//animate
//Heavy rain
void rainHeavy(){
  int del = 80;
  int del2 = 60;
  randomSeed(analogRead(0)%10);
  //Serial.println("Analog input"); //testing
  //Serial.println(analogRead(0)%10); //testing
  for(int x= 0; x<50; x++){
    int stCol = random(0,colmax);
    int stCol2 = random(0,colmax);
    int stCol3 = random(0,colmax);
    int stCol4 = random(0,colmax);
    
    int dropNum = random(0,9);
    
    //Serial.println(dropNum); //testing

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 80;  //if first row
      onLED(ledRow[y], ledCol[stCol]);
      if(dropNum>=4){
        onLED(ledRow[y], ledCol[stCol2]);
      }
      if(dropNum>=7){
        onLED(ledRow[y], ledCol[stCol3]);
      }
      if(dropNum>=8){
        onLED(ledRow[y], ledCol[stCol4]);
      }
      
      delay(del2);
      
      //turn off all even if they wern't turned on.
      offLED(ledRow[y], ledCol[stCol]);
      offLED(ledRow[y], ledCol[stCol2]);
      offLED(ledRow[y], ledCol[stCol3]);
      offLED(ledRow[y], ledCol[stCol4]);
      
      
      del2=30;
    }
    delay(del);

  }
}



//animate
//light rain
void rainLight(){
  int del = 170;
  int del2 = 70;
  
  for(int x= 0; x<20; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 110; 
      onLED(ledRow[y], ledCol[stCol]);
      delay(del2);
      offLED(ledRow[y], ledCol[stCol]);
      del2=70;
    }
    delay(del);

  }
}

//animate
//Medium rain
void rainMed(){
  int del = 70;
  int del2 = 35;
  
  for(int x= 0; x<25; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 85; 
      onLED(ledRow[y], ledCol[stCol]);
      delay(del2);
      offLED(ledRow[y], ledCol[stCol]);
      del2=35;
    }
    delay(del);

  }
}


//animate
//light rain
void rain(){
  int del = 150;
  int del2 = 50;
  
  for(int x= 0; x<40; x++){
    int stCol = random(0,colmax);

    for(int y=rowmax-1;y>-1;y--){
      if(y==rowmax-1) del2 = 90; 
      onLED(ledRow[y], ledCol[stCol]);
      delay(del2);
      offLED(ledRow[y], ledCol[stCol]);
      del2=50;
    }
    delay(del);

  }
}


//animate
void paneLTF(){
  int del = 100;
    leftPaneOn();
    delay(del);
    leftPaneOff();
    diagonalFTBPaneOn();
    delay(del);
    diagonalFTBPaneOff();
    frontPaneOn();
    delay(del);
    frontPaneOff();
}


//animate
void paneBTL(){
  int del = 100;
    backPaneOn();
    delay(del);
    backPaneOff();
    diagonalBTFPaneOn();
    delay(del);
    diagonalBTFPaneOff();
    leftPaneOn();
    delay(del);
    leftPaneOff();
}

//animate
void paneRTB(){
  int del = 100;
    rightPaneOn();
    delay(del);
    rightPaneOff();
    diagonalFTBPaneOn();
    delay(del);
    diagonalFTBPaneOff();
    backPaneOn();
    delay(del);
    backPaneOff();
}

//animate
void paneFTR(){
  int del = 100;
    frontPaneOn();
    delay(del);
    frontPaneOff();
    diagonalBTFPaneOn();
    delay(del);
    diagonalBTFPaneOff();
    rightPaneOn();
    delay(del);
    rightPaneOff();
}


void panelRotateCW(){
    int del = 80;
    
    middlePaneOn();
    delay(del);
    middlePaneOff();
    
    diagonalBTFPaneOn();
    delay(del);
    diagonalBTFPaneOff();
    
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    
    diagonalFTBPaneOn();
    delay(del);
    diagonalFTBPaneOff();
    
    
    //back to start.
    //middlePaneOn();
    //delay(del);
    //middlePaneOff();
    
}


void panelRotateAntiCW(){
    int del = 80;
    
    middlePaneOn();
    delay(del);
    middlePaneOff();
    
    diagonalFTBPaneOn();
    delay(del);
    diagonalFTBPaneOff();
    
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    
    diagonalBTFPaneOn();
    delay(del);
    diagonalBTFPaneOff();
    
    
    //back to start.
    //middlePaneOn();
    //delay(del);
    //middlePaneOff();
    
}


void diagonalBTFPaneOn(){
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol7, HIGH);
    digitalWrite(ledCol9, HIGH);
    digitalWrite(ledCol3, HIGH);
}

void diagonalBTFPaneOff(){
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, LOW);
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol3, LOW);
    digitalWrite(ledCol9, LOW);
    digitalWrite(ledCol7, LOW);
}

void diagonalFTBPaneOn(){
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol1, HIGH);
    digitalWrite(ledCol9, HIGH);
    digitalWrite(ledCol5, HIGH);

}
void diagonalFTBPaneOff(){
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, LOW);
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol5, LOW);
    digitalWrite(ledCol9, LOW);
    digitalWrite(ledCol1, LOW);

}

void frontToBackPane(){
    int del = 250;
    frontPaneOn();
    delay(del);
    frontPaneOff();
    middlePaneOn();
    delay(del);
    middlePaneOff();
    backPaneOn();
    delay(del);
    backPaneOff();
    middlePaneOn();
    delay(del);
    middlePaneOff();
    frontPaneOn();
    delay(del);
    frontPaneOff();
}

//animation
void rightToLeftPane(){
    int del = 250;
    rightPaneOn();
    delay(del);
    rightPaneOff();
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    leftPaneOn();
    delay(del);
    leftPaneOff();
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    rightPaneOn();
    delay(del);
    rightPaneOff();
}

//animation
void backToFrontPane(){
    int del = 250;
    backPaneOn();
    delay(del);
    backPaneOff();
    middlePaneOn();
    delay(del);
    middlePaneOff();
    frontPaneOn();
    delay(del);
    frontPaneOff();
    middlePaneOn();
    delay(del);
    middlePaneOff();
    backPaneOn();
    delay(del);
    backPaneOff();
}

//animation
void leftToRightPane(){
    int del = 250;
    leftPaneOn();
    delay(del);
    leftPaneOff();
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    rightPaneOn();
    delay(del);
    rightPaneOff();
    middleLRPaneOn();
    delay(del);
    middleLRPaneOff();
    leftPaneOn();
    delay(del);
    leftPaneOff();
}

//animation
void topToBottomPanel(){
    int del = 250;
    topPaneOn();
    delay(del);
    topPaneOff();
    middleTBPaneOn();
    delay(del);
    middleTBPaneOff();
    bottomPaneOn();
    delay(del);
    bottomPaneOff();
    middleTBPaneOn();
    delay(del);
    middleTBPaneOff();
    topPaneOn();
    delay(del);
    topPaneOff();

}

//animation
void bottomToTopPanel(){
    int del = 250;
    bottomPaneOn();
    delay(del);
    bottomPaneOff();
    middleTBPaneOn();
    delay(del);
    middleTBPaneOff();
    topPaneOn();
    delay(del);
    topPaneOff();
    middleTBPaneOn();
    delay(del);
    middleTBPaneOff();
    bottomPaneOn();
    delay(del);
    bottomPaneOff();

}


//static
void topPaneOn(){
    digitalWrite(ledRow1, HIGH);
    
    digitalWrite(ledCol1, HIGH);
    digitalWrite(ledCol2, HIGH);
    digitalWrite(ledCol3, HIGH);
    digitalWrite(ledCol4, HIGH);
    digitalWrite(ledCol5, HIGH);
    digitalWrite(ledCol6, HIGH);
    digitalWrite(ledCol7, HIGH);
    digitalWrite(ledCol8, HIGH);
    digitalWrite(ledCol9, HIGH);
}

void topPaneOff(){
    digitalWrite(ledRow1, LOW);
    
    digitalWrite(ledCol1, LOW);
    digitalWrite(ledCol2, LOW);
    digitalWrite(ledCol3, LOW);
    digitalWrite(ledCol4, LOW);
    digitalWrite(ledCol5, LOW);
    digitalWrite(ledCol6, LOW);
    digitalWrite(ledCol7, LOW);
    digitalWrite(ledCol8, LOW);
    digitalWrite(ledCol9, LOW);
}

//static
void middleTBPaneOn(){
    digitalWrite(ledRow2, HIGH);
    
    digitalWrite(ledCol1, HIGH);
    digitalWrite(ledCol2, HIGH);
    digitalWrite(ledCol3, HIGH);
    digitalWrite(ledCol4, HIGH);
    digitalWrite(ledCol5, HIGH);
    digitalWrite(ledCol6, HIGH);
    digitalWrite(ledCol7, HIGH);
    digitalWrite(ledCol8, HIGH);
    digitalWrite(ledCol9, HIGH);
}

void middleTBPaneOff(){
    digitalWrite(ledRow2, LOW);
    
    digitalWrite(ledCol1, LOW);
    digitalWrite(ledCol2, LOW);
    digitalWrite(ledCol3, LOW);
    digitalWrite(ledCol4, LOW);
    digitalWrite(ledCol5, LOW);
    digitalWrite(ledCol6, LOW);
    digitalWrite(ledCol7, LOW);
    digitalWrite(ledCol8, LOW);
    digitalWrite(ledCol9, LOW);
}

void bottomPaneOn(){
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol1, HIGH);
    digitalWrite(ledCol2, HIGH);
    digitalWrite(ledCol3, HIGH);
    digitalWrite(ledCol4, HIGH);
    digitalWrite(ledCol5, HIGH);
    digitalWrite(ledCol6, HIGH);
    digitalWrite(ledCol7, HIGH);
    digitalWrite(ledCol8, HIGH);
    digitalWrite(ledCol9, HIGH);
}

void bottomPaneOff(){
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol1, LOW);
    digitalWrite(ledCol2, LOW);
    digitalWrite(ledCol3, LOW);
    digitalWrite(ledCol4, LOW);
    digitalWrite(ledCol5, LOW);
    digitalWrite(ledCol6, LOW);
    digitalWrite(ledCol7, LOW);
    digitalWrite(ledCol8, LOW);
    digitalWrite(ledCol9, LOW);
}


void rightPaneOn(){
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol3, HIGH);
    digitalWrite(ledCol4, HIGH);
    digitalWrite(ledCol5, HIGH);
}

void rightPaneOff(){
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, LOW);
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol3, LOW);
    digitalWrite(ledCol4, LOW);
    digitalWrite(ledCol5, LOW);
}

void middleLRPaneOn(){
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol2, HIGH);
    digitalWrite(ledCol9, HIGH);
    digitalWrite(ledCol6, HIGH);
}

void middleLRPaneOff(){
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, LOW);
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol2, LOW);
    digitalWrite(ledCol9, LOW);
    digitalWrite(ledCol6, LOW);
}

void leftPaneOn(){
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol7, HIGH);
    digitalWrite(ledCol8, HIGH);
    digitalWrite(ledCol1, HIGH);
}

void leftPaneOff(){
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, LOW);
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol7, LOW);
    digitalWrite(ledCol8, LOW);
    digitalWrite(ledCol1, LOW);
}


void backPaneOn(){
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol5, HIGH);
    digitalWrite(ledCol6, HIGH);
    digitalWrite(ledCol7, HIGH);
}


void backPaneOff(){
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, LOW);
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol5, LOW);
    digitalWrite(ledCol6, LOW);
    digitalWrite(ledCol7, LOW);
}
//-------------------------------

void middlePaneOn(){
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol4, HIGH);
    digitalWrite(ledCol8, HIGH);
    digitalWrite(ledCol9, HIGH);
}

void middlePaneOff(){
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, LOW);
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol4, LOW);
    digitalWrite(ledCol8, LOW);
    digitalWrite(ledCol9, LOW);
}



void frontPaneOn(){
    digitalWrite(ledRow1, HIGH);
    digitalWrite(ledRow2, HIGH);
    digitalWrite(ledRow3, HIGH);
    
    digitalWrite(ledCol1, HIGH);
    digitalWrite(ledCol2, HIGH);
    digitalWrite(ledCol3, HIGH);
}

void frontPaneOff(){
    digitalWrite(ledRow1, LOW);
    digitalWrite(ledRow2, LOW);
    digitalWrite(ledRow3, LOW);
    
    digitalWrite(ledCol1, LOW);
    digitalWrite(ledCol2, LOW);
    digitalWrite(ledCol3, LOW);
}



void antiClockwise(int movSpeed){
    int delVal = movSpeed;
   
    for(int x=0; x<3; x++){
      for(int y=0; y<8; y++){
        onLED(ledRow[x],ledCol[y]);
        delay(delVal);
        offLED(ledRow[x],ledCol[y]);
      }
    }
}


void clockwise(int movSpeed){
    int delVal = movSpeed;
    
    for(int x=2; x>-1; x--){
      for(int y=7; y>-1; y--){
        onLED(ledRow[x],ledCol[y]);
        delay(delVal);
        offLED(ledRow[x],ledCol[y]);
      }
    }
}



//snake movement on front pane only
void frontPaneFigure8(){
  
  int delVal = 130;

    for(int y=0;y<3;y++){
      onLED(ledRow[0],ledCol[y]);
      delay(delVal);
      offLED(ledRow[0],ledCol[y]);
    }
    for(int y=2;y>-1;y--){
      onLED(ledRow[1],ledCol[y]);
      delay(delVal);
      offLED(ledRow[1],ledCol[y]);
    }
    for(int y=0;y<3;y++){
      onLED(ledRow[2],ledCol[y]);
      delay(delVal);
      offLED(ledRow[2],ledCol[y]);
    }
    for(int y=2;y>-1;y--){
      onLED(ledRow[1],ledCol[y]);
      delay(delVal);
      offLED(ledRow[1],ledCol[y]);
    }

}


void rightPaneFigure8(){
  
  int delVal = 130;

    for(int y=2;y<5;y++){
      onLED(ledRow[0],ledCol[y]);
      delay(delVal);
      offLED(ledRow[0],ledCol[y]);
    }
    for(int y=4;y>1;y--){
      onLED(ledRow[1],ledCol[y]);
      delay(delVal);
      offLED(ledRow[1],ledCol[y]);
    }
    for(int y=2;y<5;y++){
      onLED(ledRow[2],ledCol[y]);
      delay(delVal);
      offLED(ledRow[2],ledCol[y]);
    }
    for(int y=4;y>1;y--){
      onLED(ledRow[1],ledCol[y]);
      delay(delVal);
      offLED(ledRow[1],ledCol[y]);
    }

}

void backPaneFigure8(){
  
  int delVal = 130;

    for(int y=4;y<7;y++){
      onLED(ledRow[0],ledCol[y]);
      delay(delVal);
      offLED(ledRow[0],ledCol[y]);
    }
    for(int y=6;y>3;y--){
      onLED(ledRow[1],ledCol[y]);
      delay(delVal);
      offLED(ledRow[1],ledCol[y]);
    }
    for(int y=4;y<7;y++){
      onLED(ledRow[2],ledCol[y]);
      delay(delVal);
      offLED(ledRow[2],ledCol[y]);
    }
    for(int y=6;y>3;y--){
      onLED(ledRow[1],ledCol[y]);
      delay(delVal);
      offLED(ledRow[1],ledCol[y]);
    }

}

void leftPaneFigure8(){
  
  int delVal = 130;

    for(int y=6;y<8;y++){
      onLED(ledRow[0],ledCol[y]);
      delay(delVal);
      offLED(ledRow[0],ledCol[y]);
    }
      
      //back to first
      onLED(ledRow[0],ledCol[0]);
      delay(delVal);
      offLED(ledRow[0],ledCol[0]);
    
    
      //back to first
      onLED(ledRow[1],ledCol[0]);
      delay(delVal);
      offLED(ledRow[1],ledCol[0]);
    
    
    for(int y=7;y>5;y--){
      onLED(ledRow[1],ledCol[y]);
      delay(delVal);
      offLED(ledRow[1],ledCol[y]);
    }
    
    for(int y=6;y<8;y++){
      onLED(ledRow[2],ledCol[y]);
      delay(delVal);
      offLED(ledRow[2],ledCol[y]);
    }
    
      //back to first
      onLED(ledRow[2],ledCol[0]);
      delay(delVal);
      offLED(ledRow[2],ledCol[0]);
    
    
      //back to first
      onLED(ledRow[1],ledCol[0]);
      delay(delVal);
      offLED(ledRow[1],ledCol[0]);
    
    for(int y=6;y>5;y--){
      onLED(ledRow[1],ledCol[y]);
      delay(delVal);
      offLED(ledRow[1],ledCol[y]);
    }

}



void middleUpDown(){
      int delVal = 130;
      onLED(ledRow[0],ledCol[8]);
      delay(delVal);
      offLED(ledRow[0],ledCol[8]);
      
      onLED(ledRow[1],ledCol[8]);
      delay(delVal);
      offLED(ledRow[1],ledCol[8]);
      
      onLED(ledRow[2],ledCol[8]);
      delay(delVal);
      offLED(ledRow[2],ledCol[8]);
      
      onLED(ledRow[1],ledCol[8]);
      delay(delVal);
      offLED(ledRow[1],ledCol[8]);
      
      onLED(ledRow[0],ledCol[8]);
      delay(delVal);
      offLED(ledRow[0],ledCol[8]);
}

//turn on all LEDs one by one.
void testAllLEDs(){
    int delVal = 500;
    
    for(int x=0;x<3;x++){
      for(int y=0;y<9;y++){
        //Serial.print(x + " " + y);
        onLED(ledRow[x],ledCol[y]);
        delay(delVal);
        offLED(ledRow[x],ledCol[y]);
        delay(200);
      }
    }
}




//turn on LED based on row number and column number
void onLED(int row, int col){
  
  digitalWrite(row, HIGH); //turn on row
  digitalWrite(col, HIGH); //turn on col
  
}

//overload funtion - used to turn LED on with certain intensity
void onLED(int row, int col, int value){
  digitalWrite(row, HIGH); //turn on row
  analogWrite(col, value); //turn on col
}


//turn off LED based on row number and column number
void offLED(int row, int col){
  digitalWrite(row, LOW); //turn on row
  digitalWrite(col, LOW); //turn on col
}
