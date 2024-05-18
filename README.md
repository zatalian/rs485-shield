# RS485 Shield

Dit arduino shield maakt gebruik van een RS485 ic namelijk de SN75176 van texas instruments om communicatie tussen 1 modbus master en meerdere modbus slaves mogelijk te maken.

## Communicatie
Om de communicatie mogelijk te maken gebruiken we een SN75176 Transceiver. Deze is met de arduino verbonden op Serial1 (dgitale pin 0 en 1) en digitale pin 6 is verbonden met de  . De shield kan verbonden worden op de bus met de screw terminals, zorg ervoor dat de A aansluiting verbonden is met alle ander A aansluitingen. De dip switch aanwezig op de shield wordt gebruikt om de terminatorweerstand in en uit te schakelen

## Randapparatuur
Op de shield zijn er ook 3 leds, 3 knoppen, een potentiometer en een WS2812B led aanwezig. Deze kunnen worden aangestuurd via modbus. Ook kunnen er nog extra leds, knoppen, ... aangesloten worden.
