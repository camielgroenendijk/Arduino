int ButtonValue = 0;

int Button = 13;
int LED = 2;

void setup(){
  pinMode(Button, INPUT);
  pinMode(LED, OUTPUT);
}

void loop(){
  ButtonValue = digitalRead(Button);

  if (ButtonValue != 0){
    digitalWrite(LED, HIGH);
  }

  else{
    digitalWrite(LED, LOW);
  }
}
