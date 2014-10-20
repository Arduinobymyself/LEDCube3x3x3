

#include <avr/pgmspace.h>        // allows use of PROGMEM to store patterns in flash

#define CUBESIZE 3
#define PLANESIZE CUBESIZE*CUBESIZE
#define PLANETIME 3333          // time each plane is displayed in us -> 100 Hz refresh
#define TIMECONST 5          // multiplies DisplayTime to get ms - why not =100?

// LED Pattern Table in PROGMEM - last column is display time in 100ms units
// TODO this could be a lot more compact but not with binary pattern representation
// L3, L3, L3, L2, L2, L2, L1, L1, L1, T,
// C1C2C3, C4C5C6, C7C8C9,....
prog_uchar PROGMEM PatternTable[] = {
 
  
// Cubes  
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30, 
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30, 
 B000, B110, B110, B000, B110, B110, B000, B000, B000, 30, 
 B000, B000, B000, B011, B011, B000, B011, B011, B000, 30,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30, 
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30, 
 B000, B110, B110, B000, B110, B110, B000, B000, B000, 30, 
 B000, B000, B000, B011, B011, B000, B011, B011, B000, 30,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30, 
 B000, B110, B110, B000, B110, B110, B000, B000, B000, 30, 
 B000, B000, B000, B011, B011, B000, B011, B011, B000, 30, 
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30, 
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30, 
 B000, B110, B110, B000, B110, B110, B000, B000, B000, 30, 
 B000, B000, B000, B011, B011, B000, B011, B011, B000, 30,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30, 
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30, 
 B000, B110, B110, B000, B110, B110, B000, B000, B000, 30, 
 B000, B000, B000, B011, B011, B000, B011, B011, B000, 30,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30, 
 B000, B110, B110, B000, B110, B110, B000, B000, B000, 30, 
 B000, B000, B000, B011, B011, B000, B011, B011, B000, 30,
 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,
 // Rain up to down and vice-versa
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 30,
 B011, B111, B111, B000, B000, B000, B100, B000, B000, 30,
 B011, B110, B111, B000, B000, B000, B100, B001, B000, 30,
 B011, B110, B011, B000, B000, B000, B100, B001, B100, 30,
 B010, B110, B011, B000, B000, B000, B101, B001, B100, 30,
 B010, B010, B011, B000, B000, B000, B101, B101, B100, 30,
 B010, B010, B001, B000, B000, B000, B101, B101, B110, 30,
 B000, B010, B000, B000, B000, B000, B111, B101, B111, 30,
 B000, B000, B000, B000, B000, B000, B111, B111, B111, 30,
 B000, B000, B000, B000, B000, B000, B111, B111, B111, 60,
 B000, B010, B000, B000, B000, B000, B111, B101, B111, 30,
 B010, B010, B001, B000, B000, B000, B101, B101, B110, 30,
 B010, B010, B011, B000, B000, B000, B101, B101, B100, 30,
 B010, B110, B011, B000, B000, B000, B101, B001, B100, 30,
 B011, B110, B011, B000, B000, B000, B100, B001, B100, 30,
 B011, B110, B111, B000, B000, B000, B100, B001, B000, 30,
 B011, B111, B111, B000, B000, B000, B100, B000, B000, 30,
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 30,
 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,

 // rain left to right and vice-versa
 B111, B000, B000, B111, B000, B000, B111, B000, B000, 30,
 B011, B000, B100, B111, B000, B000, B111, B000, B000, 30, 
 B011, B000, B100, B011, B000, B100, B111, B000, B000, 30, 
 B011, B000, B100, B011, B000, B100, B101, B000, B010, 30, 
 B011, B000, B100, B010, B000, B101, B101, B000, B010, 30, 
 B010, B000, B101, B010, B000, B101, B101, B000, B010, 30, 
 B010, B000, B101, B010, B000, B101, B100, B000, B011, 30, 
 B000, B000, B111, B010, B000, B101, B100, B000, B011, 30, 
 B000, B000, B111, B010, B000, B101, B000, B000, B111, 30,
 B000, B000, B111, B000, B000, B111, B000, B000, B111, 30, 
 B000, B000, B111, B000, B000, B111, B000, B000, B111, 60,
 B000, B000, B111, B010, B000, B101, B000, B000, B111, 30,
 B000, B000, B111, B010, B000, B101, B100, B000, B011, 30,  
 B010, B000, B101, B010, B000, B101, B100, B000, B011, 30,  
 B010, B000, B101, B010, B000, B101, B101, B000, B010, 30,  
 B011, B000, B100, B010, B000, B101, B101, B000, B010, 30,  
 B011, B000, B100, B011, B000, B100, B101, B000, B010, 30,  
 B011, B000, B100, B011, B000, B100, B111, B000, B000, 30,  
 B011, B000, B100, B111, B000, B000, B111, B000, B000, 30,  
 B111, B000, B000, B111, B000, B000, B111, B000, B000, 30, 
 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,
 
 //Python Snake
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 20, 
 B000, B000, B000, B000, B000, B001, B000, B000, B001, 20, 
 B000, B000, B001, B000, B000, B001, B000, B000, B001, 20, 
 B000, B000, B011, B000, B000, B001, B000, B000, B001, 20, 
 B000, B000, B111, B000, B000, B001, B000, B000, B000, 20, 
 B000, B100, B111, B000, B000, B000, B000, B000, B000, 20, 
 B100, B100, B110, B000, B000, B000, B000, B000, B000, 20, 
 B100, B100, B100, B100, B000, B000, B000, B000, B000, 20, 
 B100, B100, B000, B100, B000, B000, B100, B000, B000, 20, 
 B100, B000, B000, B100, B000, B000, B110, B000, B000, 20, 
 B000, B000, B000, B100, B000, B000, B110, B010, B000, 20, 
 B000, B000, B000, B000, B000, B000, B110, B010, B010, 20, 
 B000, B000, B000, B000, B000, B010, B010, B010, B010, 20, 
 B000, B000, B010, B000, B000, B010, B000, B010, B010, 20, 
 B000, B010, B010, B000, B000, B010, B000, B000, B010, 20, 
 B010, B010, B010, B000, B000, B010, B000, B000, B000, 20, 
 B011, B010, B010, B000, B000, B000, B000, B000, B000, 20, 
 B011, B010, B000, B001, B000, B000, B000, B000, B000, 20, 
 B011, B000, B000, B001, B000, B000, B001, B000, B000, 20, 
 B001, B000, B000, B001, B000, B000, B011, B000, B000, 20, 
 B000, B000, B000, B001, B000, B000, B111, B000, B000, 20, 
 B000, B000, B000, B100, B000, B000, B111, B000, B000, 20, 
 B100, B000, B000, B100, B000, B000, B100, B000, B000, 20, 
 B100, B000, B000, B100, B000, B000, B000, B000, B000, 20, 
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 20, 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 20, 
 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,
 
 //walking
 B100, B100, B100, B000, B000, B000, B001, B001, B001, 15, 
 B010, B010, B010, B000, B000, B000, B010, B010, B010, 15, 
 B001, B001, B001, B000, B000, B000, B100, B100, B100, 15, 
 B000, B000, B000, B101, B101, B101, B000, B000, B000, 15,
 B100, B100, B100, B000, B000, B000, B001, B001, B001, 15, 
 B010, B010, B010, B000, B000, B000, B010, B010, B010, 15, 
 B001, B001, B001, B000, B000, B000, B100, B100, B100, 15, 
 B000, B000, B000, B101, B101, B101, B000, B000, B000, 15,
 B100, B100, B100, B000, B000, B000, B001, B001, B001, 15, 
 B010, B010, B010, B000, B000, B000, B010, B010, B010, 15, 
 B001, B001, B001, B000, B000, B000, B100, B100, B100, 15, 
 B000, B000, B000, B101, B101, B101, B000, B000, B000, 15,
 B100, B100, B100, B000, B000, B000, B001, B001, B001, 15, 
 B010, B010, B010, B000, B000, B000, B010, B010, B010, 15, 
 B001, B001, B001, B000, B000, B000, B100, B100, B100, 15, 
 B000, B000, B000, B101, B101, B101, B000, B000, B000, 15,
 B100, B100, B100, B000, B000, B000, B001, B001, B001, 15, 
 B010, B010, B010, B000, B000, B000, B010, B010, B010, 15, 
 B001, B001, B001, B000, B000, B000, B100, B100, B100, 15, 
 B000, B000, B000, B101, B101, B101, B000, B000, B000, 15,
 B100, B100, B100, B000, B000, B000, B001, B001, B001, 15, 
 B010, B010, B010, B000, B000, B000, B010, B010, B010, 15, 
 B001, B001, B001, B000, B000, B000, B100, B100, B100, 15, 
 B000, B000, B000, B101, B101, B101, B000, B000, B000, 15,
 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,
 
 // barrel
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 15, 
 B001, B001, B001, B001, B001, B001, B001, B001, B001, 15, 
 B000, B000, B000, B000, B000, B000, B111, B111, B111, 15, 
 B100, B100, B100, B100, B100, B100, B100, B100, B100, 15, 
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 15, 
 B001, B001, B001, B001, B001, B001, B001, B001, B001, 15, 
 B000, B000, B000, B000, B000, B000, B111, B111, B111, 15, 
 B100, B100, B100, B100, B100, B100, B100, B100, B100, 15, 
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 15, 
 B001, B001, B001, B001, B001, B001, B001, B001, B001, 15, 
 B000, B000, B000, B000, B000, B000, B111, B111, B111, 15, 
 B100, B100, B100, B100, B100, B100, B100, B100, B100, 15, 
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 15,
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 15, 
 B001, B001, B001, B001, B001, B001, B001, B001, B001, 15, 
 B000, B000, B000, B000, B000, B000, B111, B111, B111, 15, 
 B100, B100, B100, B100, B100, B100, B100, B100, B100, 15, 
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 15, 
 B001, B001, B001, B001, B001, B001, B001, B001, B001, 15, 
 B000, B000, B000, B000, B000, B000, B111, B111, B111, 15, 
 B100, B100, B100, B100, B100, B100, B100, B100, B100, 15, 
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 15, 
 B001, B001, B001, B001, B001, B001, B001, B001, B001, 15, 
 B000, B000, B000, B000, B000, B000, B111, B111, B111, 15, 
 B100, B100, B100, B100, B100, B100, B100, B100, B100, 15, 
 B111, B111, B111, B000, B000, B000, B000, B000, B000, 15,
 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,
 
 // blink whole cube
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,
  
 // flash each LED in sequence: 
 // Left->Right column, then Top->Bottom row, then Upper->Lower plane
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 B010, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 B001, B000, B000, B000, B000, B000, B000, B000, B000, 5,
 B000, B100, B000, B000, B000, B000, B000, B000, B000, 5,
 B000, B010, B000, B000, B000, B000, B000, B000, B000, 5,
 B000, B001, B000, B000, B000, B000, B000, B000, B000, 5,
 B000, B000, B100, B000, B000, B000, B000, B000, B000, 5,
 B000, B000, B010, B000, B000, B000, B000, B000, B000, 5,
 B000, B000, B001, B000, B000, B000, B000, B000, B000, 5,
 B000, B000, B000, B100, B000, B000, B000, B000, B000, 5,
 B000, B000, B000, B010, B000, B000, B000, B000, B000, 5,
 B000, B000, B000, B001, B000, B000, B000, B000, B000, 5,
 B000, B000, B000, B000, B100, B000, B000, B000, B000, 5,
 B000, B000, B000, B000, B010, B000, B000, B000, B000, 5,
 B000, B000, B000, B000, B001, B000, B000, B000, B000, 5,
 B000, B000, B000, B000, B000, B100, B000, B000, B000, 5,
 B000, B000, B000, B000, B000, B010, B000, B000, B000, 5,
 B000, B000, B000, B000, B000, B001, B000, B000, B000, 5,
 B000, B000, B000, B000, B000, B000, B100, B000, B000, 5,
 B000, B000, B000, B000, B000, B000, B010, B000, B000, 5,
 B000, B000, B000, B000, B000, B000, B001, B000, B000, 5,
 B000, B000, B000, B000, B000, B000, B000, B100, B000, 5,
 B000, B000, B000, B000, B000, B000, B000, B010, B000, 5,
 B000, B000, B000, B000, B000, B000, B000, B001, B000, 5,
 B000, B000, B000, B000, B000, B000, B000, B000, B100, 5,
 B000, B000, B000, B000, B000, B000, B000, B000, B010, 5,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 5,

 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,

 // Some little cube - big cube
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 100,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 100,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 100,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 100,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 100,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 100,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 100,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 100,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 100,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 60,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 60,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 60,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 60,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 60,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 60,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 30,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 30,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 30,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 30,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 30,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 30,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 30,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 10,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 10,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 10,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 10,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B001, 10,
 B000, B000, B000, B000, B011, B011, B000, B011, B011, 10,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,  
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 100,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 100,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 100,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 100,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 100,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 100,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 100,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 100,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 100,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 60,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 60,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 60,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 60,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 60,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 60,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 60,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 60,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 60,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 30,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 30,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 30,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 30,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 30,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 30,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 30,    
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 10,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 10,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 10,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 10,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B100, B000, B000, B000, B000, B000, B000, B000, B000, 10,
 B110, B110, B000, B110, B110, B000, B000, B000, B000, 10,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
    
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,

 // Diagonal wipe, starting in the center
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B111, B111, B111, B111, B111, B111, B111, B101, B111, 10,
 B111, B111, B111, B111, B101, B111, B111, B101, B111, 10,
 B111, B111, B111, B111, B101, B111, B111, B100, B111, 10,
 B111, B101, B111, B111, B100, B111, B111, B100, B110, 10,
 B111, B101, B111, B111, B100, B111, B111, B100, B110, 10,
 B111, B011, B111, B111, B100, B110, B111, B100, B100, 10,
 B111, B100, B110, B111, B100, B100, B111, B100, B000, 10,
 B111, B100, B100, B111, B100, B000, B111, B000, B000, 10,
 B111, B100, B000, B111, B000, B000, B011, B000, B000, 10,
 B111, B000, B000, B011, B000, B000, B001, B001, B000, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 100,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B111, B111, B111, B111, B111, B111, B111, B101, B111, 10,
 B111, B111, B111, B111, B101, B111, B111, B101, B111, 10,
 B111, B111, B111, B111, B101, B111, B111, B100, B111, 10,
 B111, B101, B111, B111, B100, B111, B111, B100, B110, 10,
 B111, B101, B111, B111, B100, B111, B111, B100, B110, 10,
 B111, B011, B111, B111, B100, B110, B111, B100, B100, 10,
 B111, B100, B110, B111, B100, B100, B111, B100, B000, 10,
 B111, B100, B100, B111, B100, B000, B111, B000, B000, 10,
 B111, B100, B000, B111, B000, B000, B011, B000, B000, 10,
 B111, B000, B000, B011, B000, B000, B001, B001, B000, 10,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 100,
 B111, B111, B111, B111, B111, B111, B111, B111, B111, 10,
 B111, B111, B111, B111, B111, B111, B111, B101, B111, 10,
 B111, B111, B111, B111, B101, B111, B111, B101, B111, 10,
 B111, B111, B111, B111, B101, B111, B111, B100, B111, 10,
 B111, B101, B111, B111, B100, B111, B111, B100, B110, 10,
 B111, B101, B111, B111, B100, B111, B111, B100, B110, 10,
 B111, B011, B111, B111, B100, B110, B111, B100, B100, 10,
 B111, B100, B110, B111, B100, B100, B111, B100, B000, 10,
 B111, B100, B100, B111, B100, B000, B111, B000, B000, 10,
 B111, B100, B000, B111, B000, B000, B011, B000, B000, 10,
 B111, B000, B000, B011, B000, B000, B001, B001, B000, 10,

 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,

 // 2-LED wide diaginal stripe that orbits the cube
 B011, B000, B000, B001, B001, B000, B000, B001, B001, 10,
 B001, B001, B000, B000, B001, B001, B000, B000, B011, 10,
 B000, B001, B001, B000, B000, B011, B000, B000, B110, 10,
 B000, B000, B011, B000, B000, B110, B000, B100, B100, 10,
 B000, B000, B110, B000, B100, B100, B100, B100, B000, 10,
 B000, B100, B100, B100, B100, B000, B110, B000, B000, 10,
 B100, B100, B000, B110, B000, B000, B011, B000, B000, 10,
 B110, B000, B000, B011, B000, B000, B001, B001, B000, 10,
 B011, B000, B000, B001, B001, B000, B000, B001, B001, 10,
 B001, B001, B000, B000, B001, B001, B000, B000, B011, 10,
 B000, B001, B001, B000, B000, B011, B000, B000, B110, 10,
 B000, B000, B011, B000, B000, B110, B000, B100, B100, 10,
 B000, B000, B110, B000, B100, B100, B100, B100, B000, 10,
 B000, B100, B100, B100, B100, B000, B110, B000, B000, 10,
 B100, B100, B000, B110, B000, B000, B011, B000, B000, 10,
 B110, B000, B000, B011, B000, B000, B001, B001, B000, 10,
 B011, B000, B000, B001, B001, B000, B000, B001, B001, 10,
 B001, B001, B000, B000, B001, B001, B000, B000, B011, 10,
 B000, B001, B001, B000, B000, B011, B000, B000, B110, 10,
 B000, B000, B011, B000, B000, B110, B000, B100, B100, 10,
 B000, B000, B110, B000, B100, B100, B100, B100, B000, 10,
 B000, B100, B100, B100, B100, B000, B110, B000, B000, 10,
 B100, B100, B000, B110, B000, B000, B011, B000, B000, 10,
 B110, B000, B000, B011, B000, B000, B001, B001, B000, 10,

 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,

 // Now, with center flashies, for flavor  
 B011, B000, B000, B001, B001, B000, B000, B011, B001, 10,
 B001, B001, B000, B000, B001, B001, B000, B000, B011, 10,
 B000, B001, B001, B000, B000, B011, B000, B010, B110, 10,
 B000, B000, B011, B000, B000, B110, B000, B100, B100, 10,
 B000, B000, B110, B000, B100, B100, B100, B110, B000, 10,
 B000, B100, B100, B100, B100, B000, B110, B000, B000, 10,
 B100, B100, B000, B110, B000, B000, B011, B010, B000, 10,
 B110, B000, B000, B011, B000, B000, B001, B001, B000, 10,
 B011, B000, B000, B001, B011, B000, B000, B001, B001, 10,
 B001, B001, B000, B000, B001, B001, B000, B000, B011, 10,
 B000, B001, B001, B000, B010, B011, B000, B000, B110, 10,
 B000, B000, B011, B000, B000, B110, B000, B100, B100, 10,
 B000, B000, B110, B000, B110, B100, B100, B100, B000, 10,
 B000, B100, B100, B100, B100, B000, B110, B000, B000, 10,
 B100, B100, B000, B110, B010, B000, B011, B000, B000, 10,
 B110, B000, B000, B011, B000, B000, B001, B001, B000, 10,
 B011, B010, B000, B001, B001, B000, B000, B001, B001, 10,
 B001, B001, B000, B000, B001, B001, B000, B000, B011, 10,
 B000, B011, B001, B000, B000, B011, B000, B000, B110, 10,
 B000, B000, B011, B000, B000, B110, B000, B100, B100, 10,
 B000, B010, B110, B000, B100, B100, B100, B100, B000, 10,
 B000, B100, B100, B100, B100, B000, B110, B000, B000, 10,
 B100, B110, B000, B110, B000, B000, B011, B000, B000, 10,
 B110, B000, B000, B011, B000, B000, B001, B001, B000, 10,

 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,

 // Wrapping up
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 200,
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 15,
 B000, B111, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B000, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B000, B000, B000, B000, B111, B000, B000, B111, 30,
 B000, B000, B000, B000, B000, B000, B000, B000, B111, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B111, 60,
 B000, B000, B000, B000, B000, B111, B000, B000, B111, 30,
 B000, B000, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B111, B111, B000, B000, B111, B000, B000, B111, 15,
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 15,
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 200,
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 15,
 B000, B111, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B000, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B000, B000, B000, B000, B111, B000, B000, B111, 30,
 B000, B000, B000, B000, B000, B000, B000, B000, B111, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B111, 60,
 B000, B000, B000, B000, B000, B111, B000, B000, B111, 30,
 B000, B000, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B111, B111, B000, B000, B111, B000, B000, B111, 15,
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 15,
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 200,
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 15,
 B000, B111, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B000, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B000, B000, B000, B000, B111, B000, B000, B111, 30,
 B000, B000, B000, B000, B000, B000, B000, B000, B111, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 60,
 B000, B000, B000, B000, B000, B000, B000, B000, B111, 60,
 B000, B000, B000, B000, B000, B111, B000, B000, B111, 30,
 B000, B000, B111, B000, B000, B111, B000, B000, B111, 15,
 B000, B111, B111, B000, B000, B111, B000, B000, B111, 15,
 B111, B111, B111, B000, B111, B111, B000, B000, B111, 15,
 
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 2000,
 
 // this is a dummy element for end of table (duration=0)
 B000, B000, B000, B000, B000, B000, B000, B000, B000, 0
 } ;


//int LEDPin[] = {16, 3, 1, 15, 4, 6, 14, 5, 7};
int LEDPin[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10};

//int PlanePin[] = {19, 18, 17};
int PlanePin[] = {13, 12, 11};

// initialization
void setup()
{
  int pin;      // loop counter
  // set up LED pins as output (active HIGH)
  for (pin=0; pin<PLANESIZE; pin++) {
    pinMode( LEDPin[pin], OUTPUT );
  }
  // set up plane pins as outputs (active LOW)
  for (pin=0; pin<CUBESIZE; pin++) {
    pinMode( PlanePin[pin], OUTPUT );
  }
}

// display pattern in table until DisplayTime is zero (then repeat)
void loop()
{
  // declare variables
  byte PatternBuf[ PLANESIZE ];      // saves current pattern from PatternTable
  int PatternIdx;
  byte DisplayTime;        // time*100ms to display pattern
  unsigned long EndTime;
  int plane;      // loop counter for cube refresh
  int patbufidx;   // indexes which byte from pattern buffer
  int ledrow;    // counts LEDs in refresh loop
  int ledcol;    // counts LEDs in refresh loop
  int ledpin;    // counts LEDs in refresh loop

  // Initialize PatternIdx to beginning of pattern table
  PatternIdx = 0;
  // loop over entries in pattern table - while DisplayTime>0
  do {
    // read pattern from PROGMEM and save in array
    memcpy_P( PatternBuf, PatternTable+PatternIdx, PLANESIZE );
    PatternIdx += PLANESIZE;
    // read DisplayTime from PROGMEM and increment index
    DisplayTime = pgm_read_byte_near( PatternTable + PatternIdx++ );   
    // compute EndTime from current time (ms) and DisplayTime
    EndTime = millis() + ((unsigned long) DisplayTime) * TIMECONST;

    // loop while DisplayTime>0 and current time < EndTime
    while ( millis() < EndTime ) {
      patbufidx = 0;    // reset index counter to beginning of buffer
      // loop over planes
      for (plane=0; plane<CUBESIZE; plane++) {
        // turn previous plane off
        if (plane==0) {
          digitalWrite( PlanePin[CUBESIZE-1], LOW );
        } else {
          digitalWrite( PlanePin[plane-1], LOW );
        }

        // load current plane pattern data into ports
        ledpin = 0;
        for (ledrow=0; ledrow<CUBESIZE; ledrow++) {
          for (ledcol=0; ledcol<CUBESIZE; ledcol++) {
            digitalWrite( LEDPin[ledpin++], PatternBuf[patbufidx] & (1 << ledcol) );
          }
          patbufidx++;
        }

        // turn current plane on
        digitalWrite( PlanePin[plane], HIGH );
        // delay PLANETIME us
        delayMicroseconds( PLANETIME );
      }    // for plane
    }    // while <EndTime
  } while (DisplayTime > 0);        // read patterns until time=0 which signals end
}
