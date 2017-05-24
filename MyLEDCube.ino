#include <LedCube.h>

#define SIZE 3
#define COLS (SIZE*SIZE)
#define TIME 1000

byte levelPins[SIZE] = {11,12,13};
byte colPins[COLS] = {2,3,4,5,6,7,8,9,10};

LedCube cube(SIZE, levelPins, colPins);

void setup ()
{
  Serial.begin(9600);
}


void loop ()
{
    delay(TIME);
    
    // acende LED um de cada vez
    Serial.println("Um LED de cada vez");
    for(byte level=0; level<cube.getLevels(); level++)
    {
        for(byte col=0; col<cube.getCols(); col++)
        {
            cube.lightPulse(level, col, 50);
        }
    }
    delay(TIME);
    
     // acende um nível por vez, aumentando a velocidade a cada vez
    Serial.println("Um nivel por vez, aumentando a velocidade");
    for(byte d=25; d>2; d-=2)
    {
        for(byte l=1; l <= cube.getLevels(); l++)
        {
            cube.lightLevel(l, d);
        }
    }
    delay(TIME);
    
    // acende cada linha em cada nível
    Serial.println("Uma linha de cada vez em cada nivel");
    for(byte level=1; level<=cube.getLevels(); level++)
    {
        for(byte row=1; row<=cube.getLevels()*2; row++)
        {
            cube.lightRow(row, level); 
        }
    }
    delay(TIME);
    
    // acende cada plano
    Serial.println("Plano a plano");
    for(byte i=3; i; i--)
    {
        for(byte row=1; row<=cube.getLevels()*2; row++)
        {
            cube.lightPlane(row, 10*i);
        }
    }
    delay(TIME);
    
    // acende LED randomicamente
    Serial.println("LED randomicamente");
    cube.randomLight(random(25,100),100);
    delay(TIME);
    
    // dropa randomicamente por coluna
    Serial.println("Dropa Randomicamente Colunas");
    for(byte x=0; x<=15; x++)
    {
        cube.lightDrop(random(0,cube.getCols()), random(50,150));
    }
    delay(TIME);
    
    // circulo externo nível randomico
    Serial.println("Circulo externo randomicamente");
    for(byte x=0; x<=5; x++)
    {
        cube.lightPerimeter(random(0,cube.getLevels()), random(1,5), random(25,100));
    }
    delay(TIME);
    
    // acende cada face de uma vez
    Serial.println("Uma face de cada vez");
    byte planes[] = {cube.getLevels()+1,cube.getLevels(),cube.getLevels()*2,1};
    for(byte i=5; i; i--)
    {
        for(byte p=0; p<sizeof(planes); p++)
        {
            cube.lightPlane(planes[p], 5*i);
        }
    }
    delay(TIME);
    
    // colunas randomicas
    Serial.println("Colunas randomicamente");
    cube.randomColumn(25);
    delay(TIME);
    
    // colunas dentro e fora
    Serial.println("Colunas, externa e interna");
    for(byte c=1, d=0; c<=10; c++)
    {
        if(c%2 == 0)
        {
            for(d=0; d<20; d++)
            {
                cube.lightColumn(2,1);
                cube.lightColumn(4,1);
                cube.lightColumn(6,1);
                cube.lightColumn(8,1);
            }
        }
        else if(c%4 == 1)
        {
            for(d=0; d<30; d++)
            {
                cube.lightColumn(1,1);
                cube.lightColumn(3,1);
                cube.lightColumn(7,1);
                cube.lightColumn(9,1);
            }
        }
        else
        {
            for(d=0; d<70; d++)
            {
                cube.lightColumn(5,1);
            }
        }
    }
    delay(TIME);
    
    // diamante e caixa
    Serial.println("Diamente e Caixa");
    byte diamond[] = {0,4,  1,1, 1,3, 1,4, 1,5, 1,7,   2,4};
    byte box[] = {
        2,0, 2,1, 2,2, 2,3, 2,5, 2,6, 2,7, 2,8,
        1,0, 1,2, 1,6, 1,8,
        0,0, 0,1, 0,2, 0,3, 0,5, 0,6, 0,7, 0,8
    };
    cube.lightSequence(box, sizeof(box), 200);
    cube.lightSequence(diamond, sizeof(diamond), 400);
    delay(TIME);
    
    // turn off one light at a time
    cube.lightsOut();
    delay(TIME);
    
    // efeito helicoptero 1
    Serial.println("Helicoptero 1");
    byte topSeq[8] = {0,3,6,7,8,5,2,1};
    byte botSeq[8] = {8,5,2,1,0,3,6,7};
    for(byte loops = 0, delay = 50; loops<=8; loops++)
    {
        for(byte s=0; s<8; s++)
        {
            byte seq[] = {2,topSeq[s], 1,4, 0,botSeq[s]};
            cube.lightSequence(seq, sizeof(seq), delay);
        } 
        if(loops < 5) delay-=10;  else delay += 10;
    }
    delay(TIME);
    
    // efeito helicoptero 2
    Serial.println("Helicoptero 2");
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
    delay(TIME);
    
    // efeito nadando
    Serial.println("Nadando");
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
    delay(TIME);
    
    // desliga um LED de cada vez
    Serial.println("Desliga um LED de cada vez");
    cube.enableBuffer();
    cube.fillBuffer();
    cube.drawBuffer(25);
    for(byte w=0, l, c, max = cube.getNumLights(); w<max; )
    {
        // lower bound is inclusive, upper is exclusive
        l = random(0, cube.getLevels());
        c = random(0, cube.getCols());
        
        if(cube.getBufferAt(l,c) == HIGH)
        {
            cube.lightOff(l,c);
            cube.drawBuffer(5);
            w++;
        }
    }
    cube.enableBuffer(false);
    Serial.flush();
    delay(TIME);
}
    
    
    
    
    
    
    

