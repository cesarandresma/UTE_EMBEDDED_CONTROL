#include <Wire.h>

void setup() {
// Inicializa bus i2c con la direccion #9
  Wire.begin(9);  
  // Manejador de eventos para I2C             
  Wire.onReceive(recibeDatoI2C);
  // Inicializa el puerto serie
  Serial.begin(9600);           
}

void loop() {
  // Hacer nada... 
  delay(100);
}

// Cada vez que se reciba un dato en el bus I2C 
// se activa esta función
void recibeDatoI2C(int num_datos) {
   // Recibe el dato como un entero
  int x = Wire.read();    
  // Envia el entero al puerto serie
  Serial.println(x);         
}