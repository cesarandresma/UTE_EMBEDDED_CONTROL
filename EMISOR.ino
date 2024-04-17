void setup() {
  Serial.begin(9600);             //Iniciamos el puerto a esa velocidad
}

void loop() {
  Serial.print("Hola");   //Imprimimos con salto de linea ("ln")  
  delay(1000);                    //pequeña pausa de 1 segundo
}