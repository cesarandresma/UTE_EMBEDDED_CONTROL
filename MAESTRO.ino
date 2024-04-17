#include <Wire.h>

void setup() {
  // Inicializa el bus i2c (la direccion del master es opcional)
  Wire.begin(); 
}

byte x = 0;

void loop() {
  // Inicia transmisión al dispositivo #9
  Wire.beginTransmission(9); 
  // Envía un byte     
  Wire.write(x);     
  // Finaliza transmisión         
  Wire.endTransmission();    
  x++;
  delay(500);
}