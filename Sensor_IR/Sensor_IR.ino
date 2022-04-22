#include <IRremote.h>
#define receptor 11
float valor;

IRrecv recIR(receptor);
decode_results resultado;

void setup() {
  Serial.begin(9600);
  recIR.enableIRIn(); //Inicializa o receptor IR

}

void loop() {
  if(recIR.decode(&resultado)){
    //valor=(resultado.value);
    Serial.print("Valor: ");
    Serial.println(resultado.value, HEX);
    recIR.resume();
  }
  

}
