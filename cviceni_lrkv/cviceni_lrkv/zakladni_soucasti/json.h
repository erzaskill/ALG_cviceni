#ifndef JSON_H
#define JSON_H

#include "mtypy.h"
#include "lexatomy.h"
using namespace std;

/*V modulu lexatomy je již definováno:
typedef enum Terminal {lbracesym, rbracesym, lbrsym, rbrsym, commasym, colonsym, strsym,
                 intnumsym, realnumsym, falsesym, truesym, eofsym} Terminal;

typedef struct {
    string vs;
    unsigned int vi;
    float vr;
} TAtrib;

typedef struct {
    Terminal Symbol;
    TAtrib Value;
} Atom;

typedef enum TypStav {StavS, StavA, StavB, StavC, StavD, StavE, StavF} TypStav;

Atom AktSym;
char Z; 
extern ifstream Inf;
    
     
void CtiZnak(char &Z);
void GetAtom(Atom &Vysled);
void VypisAtom(Atom A);
string ZobrazAtom(Terminal X);

*/

UkPolozka ParseJson(string JmInf);
void VypisPam(UkPolozka H);

#endif