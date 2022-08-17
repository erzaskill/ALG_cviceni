#ifndef MTYPY_H
#define MTYPY_H
#include <iostream>
using namespace std;

typedef enum TypUdaj {typretez, typcele, typrealne, typlogik, typpole, typobjekt} TypUdaj;

typedef struct Polozka {
    string Nazev;
    TypUdaj Udaj;
    string retez;
    unsigned int cele;
    float realne;
    bool logik;
    Polozka* pole;
    Polozka* objekt;
    Polozka* Dalsi;
} Polozka;

typedef Polozka* UkPolozka;

#endif
