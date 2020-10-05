const int swPin =12;
const int VrxPin = 5;
const int VryPin = 0;

int xDirection = 0;
int yDirection = 0;
int switchState = 0;


void setup(){
  Serial.begin(9600);

  pinMode(swPin, INPUT);

  digitalWrite(swPin, HIGH);
}

void loop(){
  xDirection = analogRead(VryPin);
  yDirection = analogRead(VrxPin);

  switchState = digitalRead(swPin);

  Serial.print("Schakelaar:  ");
  Serial.println(switchState);

  Serial.print("X=as:     ");
  Serial.println(xDirection);

  Serial.print("y=as:     ");
  Serial.println(xDirection);

  if (!switchState) {
    Serial.println("Schakelaar ingedrukt");
  } else if (switchState) {
      Serial.println("schakelaar niet ingedrukt");
  }    

  if (xDirection < 480) {
    Serial.println("Links");
  } else if (xDirection > 520) {
    Serial.println("Rechts");
  }

  if (yDirection < 480) {
    Serial.println("Omlaag");
  } else if (yDirection > 525) {
    Serial.println("Omhoog");
  }


  delay(2000);
}
