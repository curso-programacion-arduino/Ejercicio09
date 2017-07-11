#define pin 3 // pin de boton
int flanco = 0; // variable para detectar cambios de estado
#define led 4


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (detectarFlanco(digitalRead(pin))){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}

boolean detectarFlanco(boolean estado) { // funcion para detectar el cambio de estado del pin
  if (estado == true && flanco == 0) {
    flanco = 1;
    //pulsaciones += 10;
    Serial.println("Flanco ascendente!");
    return true;
  }
  if (estado == false && flanco == 1) { // si pin deja de estar high ponemos el flanco a 0
    flanco = 0;
    Serial.println("Flanco descendente!");
    return false;
  }
}
