#include <TM1637.h>

#define clk  2
#define dio  3

TM1637 tm(clk, dio);

void setup() {
  tm.init();

  //Difinir o brilho: 0-7
  tm.set(4);
}

void loop() {
  //Exemplo 12:ab
  //tm.display(posição, caractere);

  tm.display(0,1);
  tm.display(1,7);
  tm.point(1); //Dois pontos
  tm.display(2,1);
  tm.display(3,9);
  

}
