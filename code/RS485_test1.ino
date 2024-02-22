#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(4,OUTPUT);
  mySerial.begin(9600);
  pinMode(3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == 1)
  {
    digitalWrite(4, 1);
    mySerial.println("LED2");
  }
  else if(mySerial.available())
  {
    String boodschap = mySerial.readStringUntil('\n');
    boodschap.trim();
    
    if(boodschap.equals("LED1"))
    {
      digitalWrite(3, 1);
      delay(1);
    }
  }
  else
  {
    digitalWrite(4, 0);
    digitalWrite(3, 0);
  }
}