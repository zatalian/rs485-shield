#include "ModbusSlave.h"

#define SLAVE_ID 1                  // kies hier de slave address
#define CTRL_PIN 6                  // kies hier de pin die de RE en DE van de RS485 gaan bedienen.
#define BAUDRATE 115200             // kies hier de baudrate (dit moet het zelfde zijn als deze van de master)
#define SERIALPORT Serial1          // kies welke Serial gebruikt wordt (Serial of Serial1)

// maak de slave aan
Modbus slave(SERIALPORT,SLAVE_ID, CTRL_PIN);

void setup()
{
  // maak van pin 2 tot en met pin 4 een output (hier hangen de leds aan)
  for (int i = 2; i < 5; i++)
    pinMode(i, OUTPUT);

  // maak van pin 8 tot en met pin 10 een input (hier hangen de drukknoppen aan)
  for (int i = 8; i < 11; i++)
    pinMode(i, INPUT); 
  
  // maak de functies aan die worden op geroepen bij een overeenkomende functie code
  slave.cbVector[CB_READ_DISCRETE_INPUTS] = readDigitalIn;
  slave.cbVector[CB_WRITE_COILS] = writeDigitalOut;
  
  // start de seriele poort en slave met de juiste baudrate
  SERIALPORT.begin(BAUDRATE, SERIAL_8E1);
  slave.begin(BAUDRATE);
}

void loop()
{
  // luister voor Modbus requests op de seriele poort
  slave.poll();
}

// functie code "read descrete inputs"
// hier worden de drie drukknoppen uitgelezen doorgestuurd naar de master
uint8_t readDigitalIn(uint8_t fc, uint16_t offset, uint16_t length)
{
  if (offset + length <= 3)
    for (int i = 0; i < length; i++)
      slave.writeCoilToBuffer(i, digitalRead(offset + i + 8));
  else return STATUS_ILLEGAL_DATA_ADDRESS;
        
  return STATUS_OK;
}

// functie code "write (multiple) coils"
// hier worden de leds aangestuurd met de informatie die van de master komt
uint8_t writeDigitalOut(uint8_t fc, uint16_t offset, uint16_t length)
{
  if (offset + length <= 3)
    for (int i = 0; i < length; i++)
      digitalWrite(offset + i + 2, slave.readCoilFromBuffer(i));
  else return STATUS_ILLEGAL_DATA_ADDRESS;
  
  return STATUS_OK;
}
       

