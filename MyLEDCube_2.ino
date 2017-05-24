#include <LedCube.h>


//This is just a little something, Notice I stay off of LED's 0,7, and 0,6, that is because I could not get them to be controlled. They are in working condition,
//but despite my best efforts I could not control whether they turned off or on. 0,7, just stays dimly lit and 0,6, does nothing. (mind you they both are in working condition)
#define SIZE 3
#define COLS (SIZE*SIZE)

byte levelPins[SIZE] = {11,12,13};
byte colPins[COLS] = {2,3,4,5,6,7,8,9,10};

LedCube cube(3, levelPins, colPins);

void setup ()
{
//    Serial.begin(9600);
}

void loop ()
{
    //delay(10);
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
//helicopter
byte aaa [] = {2,4, 2,1, 2,7, };
byte bbb [] = {2,4, 2,2, 2,6, };
byte ccc [] = {2,5, 2,3, };
byte ddd [] = {2,4, 2,8, 2,0, };
byte eee [] = {2,4, 2,1, 2,7, };
byte fff [] = {2,4, 2,2, 2,6, };
byte ggg [] = {2,5, 2,3, };
byte hhh [] = {2,4, 2,8, 2,0, };
byte iii [] = {2,4, 2,1, 2,7, };
byte jjj [] = {2,4, 2,2, 2,6, };
byte kkk [] = {2,5, 2,3, };
byte lll [] = {2,4, 2,8, 2,0, };
byte mmm [] = {2,4, 2,1, 2,7, };
byte nnn [] = {2,4, 2,2, 2,6, };
byte ooo [] = {2,5, 2,3, };
byte ppp [] = {2,4, 2,8, 2,0, };
byte qqq [] = {2,4, 2,1, 2,7, };
byte rrr [] = {2,4, 2,2, 2,6, };
byte sss [] = {2,5, 2,3, };
byte ttt [] = {2,4, 2,8, 2,0, };
byte uuu [] = {2,4, 2,1, 2,7, };
byte vvv [] = {2,4, 2,2, 2,6, };
byte www [] = {2,5, 2,3, };
byte xxx [] = {2,4, 2,8, 2,0, };
byte yyy [] = {2,4, };
byte zzz [] = {2,4, };


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
         //for helicopter
         cube.lightSequence(aaa, sizeof(aaa), 50);
         cube.lightSequence(bbb, sizeof(bbb), 50);
         cube.lightSequence(ccc, sizeof(ccc), 50);
         cube.lightSequence(ddd, sizeof(ddd), 50);
         cube.lightSequence(eee, sizeof(eee), 50);
         cube.lightSequence(fff, sizeof(fff), 50);
         cube.lightSequence(ggg, sizeof(ggg), 50);
         cube.lightSequence(hhh, sizeof(hhh), 50);
         cube.lightSequence(iii, sizeof(iii), 50);
         cube.lightSequence(jjj, sizeof(jjj), 50);
         cube.lightSequence(kkk, sizeof(kkk), 50);
         cube.lightSequence(lll, sizeof(lll), 50);
         cube.lightSequence(mmm, sizeof(mmm), 50);
         cube.lightSequence(nnn, sizeof(nnn), 50);
         cube.lightSequence(ooo, sizeof(ooo), 50);
         cube.lightSequence(ppp, sizeof(ppp), 50);
         cube.lightSequence(qqq, sizeof(qqq), 50);
         cube.lightSequence(rrr, sizeof(rrr), 50);
         cube.lightSequence(sss, sizeof(sss), 50);
         cube.lightSequence(ttt, sizeof(ttt), 50);
         cube.lightSequence(uuu, sizeof(uuu), 50);
         cube.lightSequence(vvv, sizeof(vvv), 50);
         cube.lightSequence(www, sizeof(www), 50);
         cube.lightSequence(xxx, sizeof(xxx), 50);
         cube.lightSequence(yyy, sizeof(yyy), 50);
         cube.lightSequence(zzz, sizeof(zzz), 50);
         delay(2000);
}
