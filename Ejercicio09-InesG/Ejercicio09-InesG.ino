#define PIN_BOTON_A 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int flanco = detectaFlanco(PIN_BOTON_A);
  if (flanco == 1)
    Serial.println("Detecto flaco ascendente");
  else if (flanco == -1)
    Serial.println("Detecto flaco descendente");
    delay(50);
}
int detectaFlanco(int PIN) {
  static boolean anterior = digitalRead(PIN);
  boolean estado = digitalRead(PIN);

  if (anterior != estado) {
    if (estado == LOW) {  //flanco descendente pull-up
      anterior = estado;
      return -1;
      
    }
    else  {  //flanco ascendente pull-up
      anterior = estado;
      return 1;
      
    }
  }
  else {
    return 0;
  }
}



