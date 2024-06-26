#include "SPI.h"

char str[ ]="Hola\n";

void setup() {
  Serial.begin(115200); // velocidad en baudios en 115200 para UART
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8); //divide el reloj por 8
  Serial.println("MAESTRO");
} 

void loop (void) {
  digitalWrite(SS, LOW); // habilitar selección de esclavo
  // enviar cadena de prueba
  for(int i=0; i< sizeof(str); i++){ 
    SPI.transfer(str[i]);
  }
  digitalWrite(SS, HIGH); // desactivar la selección de esclavo
  delay(2000);
}