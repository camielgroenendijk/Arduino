int potPin = 2;
int ledPin = LED_BUILTIN;
int potVal = 0;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);

  digitalWrite(ledPin, HIGH);
  delay(potVal);

  digitalWrite(ledPin, LOW);
  delay(potVal);
} 
