/*
 * Bibliothek zur
 * Erzeugung von Tönen
 * Erstellt für den NwT-Unterricht in Baden Württemberg
 *
 * Version: 1.5
 * 11.2018
 * cc Volker Rust
 * Lizenzbedingungen: siehe LICENSE-Datei
 */

#ifndef NwTon_h
#define NwTon_h

#include "Arduino.h"

//Das sind die Frequenzen zu den Tönen die global in jedem Sketch 
//verfügbar sein müssen!

static int C = 130, D = 147, E = 165, F = 175, G = 196, A = 220, H = 247;
static int Cis = 138, Dis = 156, Fis = 185, Gis = 207, Ais = 233, B = 233;

static int c = 262, d = 294, e = 330, f = 349, g = 392, a = 440, h = 493;
static int cis = 277, dis = 311, fis = 370, gis = 415, ais = 466, b = 466;

static int c2 = 523, d2 = 587, e2 = 659, f2 = 698, g2 = 784, a2 = 880, h2 = 988;
static int cis2 = 554, dis2 = 622, fis2 = 740, gis2 = 831, ais2 = 932, b2 = 932;

//Länge der Noten als Vielfache einer Zweiunddreisigstel!
//Wichtig, damit auch Länge mal 1.5 noch ein "int" ist.
static int viertel=8, achtel=4, sechzehntel=2, halbe=16, ganze=32;
static int vi=viertel, ac=achtel, se=sechzehntel, ha=halbe, ga=ganze;

//für punktierte Noten und Pausen
static float punkt = 1.5;
static int viertelpunkt=viertel*punkt, achtelpunkt=achtel*punkt, sechzehntelpunkt=sechzehntel*punkt; 
static int halbepunkt=halbe*punkt, ganzepunkt=ganze*punkt;
static int vip=viertelpunkt, acp=achtelpunkt, sep=sechzehntelpunkt, hap=halbepunkt, gap=ganzepunkt;

class NwTon {

  private:
    int geschw;
    int LPin;
    int legato;

  public:     
    //Construktor des Objekts mit DEFAULT-Werten
    NwTon(int Lautsprecherpin, int Geschwindigkeit=80, int Legato=95);
    
    //von außen zugängliche Funktionen
    void ton(int Hoehe, int Laenge);
    void pause(int Laenge);
    void setzteGeschw(int Geschwindigkeit);

    int getGeschw();
    void setGeschw(int Geschwindigkeit);
    int getLPin();
    void setLPin(int Lautsprecherpin);
    int getLegato();
    void setLegato(int Legato);
};

#endif
