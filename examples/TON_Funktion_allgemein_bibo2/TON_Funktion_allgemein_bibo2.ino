/*****************************************************************************
     BEISPIEL EXAMPLE BEISPIEL EXAMPLE BEISPIEL EXAMPLE BEISPIEL EXAMPLE
  ****************************************************************************                                        *
  |                                                                          |
  |  Die TON-Funktion und die Variablen sind in eine Bibliothek ausgelagert! |
  |                                                                          |
  |   Version: 1.5                                                           |
  |   11.2018                                                                |
  |   cc Volker Rust                                                         |
  |                                                                          |
  ****************************************************************************
    Töne gibt es in 3 Oktaven: C, Cis, D, Dis, ... B, H
                               c, cis, d, dis, ... B, H   (hier ist a=440 HZ)
                              c2, cis2, d2, dis2, ... b2, h2

    Ton-Längen: ganze - ga, halbe - ha, viertel - vi, achtel - ac, sechzehntel, se
                ganzepunkt - gap, halbepunkt - hap, etc.
                "Tonlängepunkt" entspricht punktierter Note.

    Legato-Stakkato: Ein "Legato"-Wert zwischen 1 und 100 gibt an,
                    wie breit ein Ton ist .
                    100 entspricht sehr breit - Legato
                    1   entspricht sehr kurz  - Stakkato
                    Üblich: zwichen 30 und 100

    Die Geschwindigkeit kann in Viertel-bpm zwischen 20 und 500 gewählt werden.

*/

#include <NwTon.h>

//Erstellt das NwTon-Objekt "t" mit den Paramtern:
//(int Lautsprecherpin, int Geschwindigkeit (in bpm (beats per minute - Viertel)), int Legato (Breite);
//Die Anfangsgeschwindigkeit beträgt DEFALUT 80 bpm (beats per minute - Viertel)
//Der "Legato"-Wert beträgt default 95.
//Werden die Werte nicht übergeben, gelten die DEFAULT-Werte
//
// Man könnte auch NwTon t(11,180,50) initialisieren.

NwTon t(11);

void setup() {
}

void loop() {

  //Alle meine Endchen
  t.ton(c, viertel);
  t.ton(d, viertel);
  t.ton(e, viertel);
  t.ton(f, viertel);
  t.ton(g, halbe); //das ist zu lang, verdeutlicht aber
  t.ton(g, halbe); //die Nutzung punktierter Noten
  t.pause( ganze);

  //schneller und andere Schreibweise
  t.setGeschw(140);
  t.ton(c, vi);
  t.ton(d, vi);
  t.ton(e, vi);
  t.ton(f, vi);
  t.ton(g, ha);
  t.ton(g, ha);
  t.pause( ga);

  //--BSP: Punktierte Noten und Stakkato bzw Legato -> 3/4-Takt//
  t.setGeschw(60);

  t.setLegato(98); // spielt breite Noten
  t.ton(d, ha);
  t.ton(d, vi);
  t.ton(a, ac);
  t.ton(a, viertelpunkt); //ausführliche Schreibweise für punktierte Noten.
  t.ton(a, vi);
  t.ton(e, vip); //abgekürzte Schreibweise für punktierte Noten.
  t.ton(f, ac);
  t.ton(e, vi);
  t.ton(d, hap);

  t.setLegato(40); // spielt Stakkato-Noten
  t.ton(d, ha);
  t.ton(d, vi);
  t.ton(a, ac);
  t.ton(a, viertelpunkt); //ausführliche Schreibweise für punktierte Noten.
  t.ton(a, vi);
  t.ton(e, vip); //abgekürzte Schreibweise für punktierte Noten.
  t.ton(f, ac);
  t.ton(e, vi);
  t.ton(d, hap);
}
