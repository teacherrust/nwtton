/*
   Version: 1.5
   11.2018
   cc Volker Rust
*/

#include "NwTon.h"
#include "Arduino.h"

//setzt den LautsprecherPin und die Geschwindigkeit!
//CONSTRUKTOR

NwTon::NwTon( int Lautsprecherpin, int Geschwindigkeit, int Legato)
  : LPin(Lautsprecherpin), geschw(Geschwindigkeit), legato(Legato)
{
  pinMode(LPin, OUTPUT);
}

//Das ist die eigentliche Ton-Funktion, die auf eine
//im Arduino implemenierte PWM-Funktion (tone) zurückgreift.

void NwTon::ton(int Hoehe, int Laenge) {
  this->LPin = LPin;
  tone(LPin, Hoehe);
  float laengeEinerZweiUndDreissigstel = 60000 / geschw / 8;
  delay( laengeEinerZweiUndDreissigstel * Laenge  * (float(legato)/100));
  noTone(LPin); //kleine Pause vor dem Tonwechsel (Absetzen) verbessert das H�rerlebnis
  delay( laengeEinerZweiUndDreissigstel * Laenge  * (1-(float(legato)/100)));
}

void NwTon::pause(int Laenge) {
  delay(Laenge);
}

//----------------Hilfsmethoden-------------------------//
//Festlegen der Länge der Töne:
//Viertel = Eine Minute(in Millisekunden) durch Schläge pro Minute

void NwTon::setGeschw(int Geschwindigkeit) {
  if (Geschwindigkeit > 20 && Geschwindigkeit < 500) {
    geschw = Geschwindigkeit;
  }
  else {
    geschw = 100;
  }
}
int NwTon::getGeschw() {
  return geschw;
}
void NwTon::setLPin(int Lautsprecherpin) {
  LPin = Lautsprecherpin;
}
int NwTon::getLPin() {
  return LPin;
}
void NwTon::setLegato(int Legato) {
  if (Legato > 0 && Legato <= 100) {
    legato = Legato;
  }
  else {
    legato = 95;
  }
}

int NwTon::getLegato() {
  return legato;
}
