int camada[3] ={11,12,13};
int ledPin[9] = {2,3,4,5,6,7,8,9,10};// pinos de dados

byte aux[4] = {B00000000, B00000000, B00000000, B00000000};

                   // camada 0   camada 1  camada 2       
                                                     //012  camada
               //led  01234567   01234567   01234567   888 ultimo led de cada camada
byte efeito1[16] = { B10010010, B01000001, B00100100, B00100000,
                     B00000000, B11110111, B00000000, B01000000,
                     B00100100, B01000001, B10010010, B10000000,
                     B01001001, B01000001, B01001001, B00000000};
                     
byte efeito2[12] = { B11111111, B00000000, B00000000, B10000000,
                     B00000000, B11111111, B00000000, B01000000,
                     B00000000, B00000000, B11111111, B00100000};
                     
byte efeito3[8] = { B01011101, B01011101, B01011101, B00000000,
                    B10101010, B10101010, B10101010, B11100000};
                    
byte efeito4[16] = {B00011011, B00011011, B00011011, B00000000,
                    B11011000, B11011000, B11011000, B00000000,
                    B01101100, B01101100, B01101100, B00000000,
                    B00001101, B00001101, B00001101, B11100000};
                    
byte efeito5[32] = {B11100000, B11100000, B11100000, B00000000,
                    B11100000, B00011100, B00000011, B00100000,
                    B11111111, B00000000, B00000000, B10000000,
                    B00000011, B00011100, B11100000, B10000000,
                    B00000011, B00000011, B00000011, B11100000,
                    B00000011, B00011100, B11100000, B10000000,
                    B11111111, B00000000, B00000000, B10000000,
                    B11100000, B00011100, B00000011, B00100000};
                    
                    
byte efeito6[40] ={B00000011, B00010100, B11100000, B10000000,
                   B10010010, B01000001, B00100100, B00100000,
                   B00000000, B11110111, B00000000, B01000000,
                   B00100100, B01000001, B10010010, B10000000,
                   B01000001, B01000001, B01001001, B00000000,
                   B11100000, B00010100, B00000011, B00100000,
                   B10010010, B01000001, B00100100, B00100000,
                   B00000000, B11110111, B00000000, B01000000,
                   B00100100, B01000001, B10010010, B10000000,
                   B01000001, B01000001, B01001001, B00000000};
                   
byte efeito7[64] ={B10010000,B10010000,B10010000,B00000000,
                   B10001000,B10001000,B10001000,B00000000,
                   B11000000,B11000000,B11000000,B00000000,
                   B01001000,B01001000,B01001000,B00000000,
                   B01100000,B01100000,B01100000,B00000000,
                   B00101000,B00101000,B00101000,B00000000,
                   B00100100,B00100100,B00100100,B00000000,
                   B00001100,B00001100,B00001100,B00000000,
                   B00000100,B00000100,B00000100,B11100000,
                   B00001000,B00001000,B00001000,B11100000,
                   B00000001,B00000001,B00000001,B11100000,
                   B00001001,B00001001,B00001001,B00000000,
                   B00000011,B00000011,B00000011,B00000000,
                   B00001010,B00001010,B00001010,B00000000,
                   B00010010,B00010010,B00010010,B00000000,
                   B00011000,B00011000,B00011000,B00000000};
                    
int i =0;
int j=0;
int a =0;
int frame_time = 10;   // quantidade de iteracoes da cada frame
                                                           
void setup()                   
{
  int i;
  for(i=0;i<3;i++)
  pinMode(camada[i], OUTPUT);  // pinos como saida
  
  for(i=0;i<9;i++)
  pinMode(ledPin[i], OUTPUT);  // pinos como saida

}


void loop() // laço principal
{ 
 cubo(efeito1, 16, 10);  // vetor de efeito, qtd de bytes, numero de repeticoes de exibicao
 cubo(efeito2, 12, 10);
 cubo(efeito3, 8, 10);
 cubo(efeito4, 16, 10); 
 cubo(efeito5, 32, 10);
 cubo(efeito6, 40, 5);
 cubo(efeito7, 64, 10);
 
}  // fim do laço principal

   
 void cubo(byte *efeito, int tamanho, int repet)
 {
    while(repet > 0)
    {
         /* copia os bytes 4 a 4 para o vetor auxilias 
         na primeira iteração copia os 4 primeiros bytes do vetor efeito escolhido
         na segunda os 4 bytes seguintes
         repete até o final do vetor */
         
     for(int cnt1 =0; cnt1 < tamanho;)
      {   
       for(int cnt2 =0; cnt2 < 4; cnt2 ++)  // copia 4 bytes 
        {                                   
         aux[cnt2] = efeito[cnt1];          
         cnt1 ++;                           
        }                           
      mostra_frame();//acende os leds correspondentes aos 4 bytes         
     } 
     repet --;
   }                     
 }
 
                      
  void mostra_frame()
  {
    for(int cnt=0; cnt< frame_time; cnt++)
    {
       for(j=0; j< 3; j++) // seleciona a camada
       {
         digitalWrite(camada[j], HIGH); // polariza o transistor correspondente a camada j 
                                        // o que liga os catodos desta camadaao GND
         for(a=0; a< 8; a++) // verifica bit a bit o byte correspondente a camada ativa 
         {
           if(bitRead(aux[j] , a) == 1)  // se o bit for 1 
             digitalWrite( ledPin[7-a], HIGH); //acende o led correspondente
           else
             digitalWrite( ledPin[7-a], LOW); // se for 0 apaga
    
           if(bitRead(aux[3] , 7-j) == 1)  // verifica o bit do nono led que está no quarto byte
             digitalWrite( ledPin[8], HIGH);
           else
            digitalWrite( ledPin[8], LOW); 
        }
        delay(7);
        digitalWrite(camada[j], LOW);
      }
   }             
 }
