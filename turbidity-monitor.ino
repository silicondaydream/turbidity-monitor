#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
int redled =6;
int greenled=7;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  u8g2.begin();
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
}

void loop(void) {
  int sensorValue = analogRead(A0);
  // print out the value you read:
  int turbidity =map(sensorValue,0,700,100,0);
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(0,10,"TURBIDITY:");	// write something to the internal memory
  u8g2.setFont(u8g2_font_7Segments_26x42_mn);	// choose a suitable font
  u8g2.setCursor(0, 60);
  u8g2.print(turbidity);
   u8g2.setFont(u8g2_font_fub14_t_symbol);	// choose a suitable font
  u8g2.setCursor(70, 60);
  u8g2.print("%");
  if (turbidity<50)
  {
    digitalWrite(redled,HIGH); 
    digitalWrite(greenled,LOW);
  }
  else {
   {
    digitalWrite(greenled,HIGH); 
    digitalWrite(redled,LOW);
  }
  }
  u8g2.sendBuffer();					// transfer internal memory to the display
  delay(1000);  

}