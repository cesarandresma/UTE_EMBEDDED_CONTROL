void setup() {
  Serial.begin(9600);             //Iniciamos el puerto a esa velocidad
}

void loop() {
  if(Serial.available()){         //Solo leemos en caso de que llegue algo nuevo
    char letra = Serial.read();   //Guardamos el dato recibido en la variable letra
    Serial.println(letra);          //Imprimimos lo que acabamos de leer
  }
}