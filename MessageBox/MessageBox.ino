#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 16, /* data=*/ 17);   // ESP32 Thing, HW I2C with pin remapping


const int swPin =12;
const int VrxPin = 1;
const int VryPin = 0;

int xDirection = 0;
int yDirection = 0;
int switchState = 0;

void setup(void) {
  Serial.begin(9600);
  
  pinMode(swPin, INPUT);

  digitalWrite(swPin, HIGH);
  
  u8g2.begin();  
}

void loop(void) {
  u8g2.firstPage();
  xDirection = analogRead(VryPin);
  yDirection = analogRead(VrxPin);

  switchState = digitalRead(swPin);

  Serial.print("Schakelaar:  ");
  Serial.println(switchState);

  Serial.print("X=as:     ");
  Serial.println(xDirection);

  Serial.print("y=as:     ");
  Serial.println(yDirection);

  if (!switchState) {
    Serial.println("Schakelaar ingedrukt");
    do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0,12,"Schakelaar Ingedrukt");
  } while ( u8g2.nextPage() );
  } else if (switchState) {
      Serial.println("schakelaar niet ingedrukt");
      u8g2.clear();
  }    


  if (yDirection < 480) {
    Serial.println("Omlaag");
    do {
      u8g2.setFont(u8g2_font_ncenB10_tr);
      u8g2.drawStr(0,24,"Omlaag");
    } while (u8g2.nextPage() );    
  } else if (yDirection > 525) {
    Serial.println("Omhoog");
    do {
      u8g2.setFont(u8g2_font_ncenB10_tr);
      u8g2.drawStr(0,24,"Omhoog");
    } while (u8g2.nextPage() );
    
  }

//
//    } else if (yDirection > 525) {
//    Serial.println("Omhoog");      
//    } else if ((xDirection < 480) && (yDirection < 480)) {
//      Serial.println("Links Onder");¨
//    } else if (yDirection < 480) {
//    Serial.println("Omlaag");
//    } else if (xDirection < 480) {
//      Serial.println("Links");
//    }
//  
//if ((xDirection > 540) && (yDirection > 540)) {
//      Serial.println("RechtsBoven");
//    } else if ((xDirection > 540) && (yDirection < 480)) {
//      Serial.println("Rechts Onder");
//    } else if (xDirection > 540) {
//      Serial.println("Rechts");
//    }
//         
//if ((xDirection < 480) && (yDirection > 540)) {    
//    Serial.println("LinksBoven");

//if ((xDirection < 480) && (yDirection > 540)) {    
//    Serial.println("LinksBoven");
//    } else if (yDirection > 525) {
//    Serial.println("Omhoog");      
//    } else if ((xDirection < 480) && (yDirection < 480)) {
//      Serial.println("Links Onder");
//    } else if (yDirection < 480) {
//    Serial.println("Omlaag");
//    } else if (xDirection < 480) {
//      Serial.println("Links");
//    }
//  
//if ((xDirection > 540) && (yDirection > 540)) {
//      Serial.println("RechtsBoven");
//    } else if ((xDirection > 540) && (yDirection < 480)) {
//      Serial.println("Rechts Onder");
//    } else if (xDirection > 540) {
//      Serial.println("Rechts");
//    }
           

delay(1000);


  

}
