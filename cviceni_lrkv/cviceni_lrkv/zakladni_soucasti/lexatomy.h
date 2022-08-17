#ifndef LEXATOMY_H
#define LEXATOMY_H

#include <fstream>
using namespace std;

/* Gramatika symbolů:
 lbracesym, rbracesym, lbrsym, rbrsym, commasym, colonsym:
   S -> { | } | [ | ] | , | :
   
 strsym:
   S -> "A
   A -> zA | "
   
 intnumsym, realnumsym:
   S -> cC | +B | -B
   B -> cC
   C -> cC | .D | @
   D -> cE
   E -> cE | @
   
 truesym:
   S -> true
   
 falsesym:
   S -> false  
   
Automat: M = (Q, T, d, q0, F)

d:

    (q0, X) = qF; X = {}[],:
    (q0, ") = qA
    (qA, z) = qA; z = lib. znak mimo "
    (qA, ") = qF
    (q0, +) = qB
    (q0, -) = qB
    (q0, c) = qC
    (qB, c) = qC
    (qC, c) = qC
    (qC, .) = qD
    (qD, c) = qE
    (qE, c) = qE
    (q0, f) = qG, H, I, J, F (neřešeno jako další stavy)
    (q0, t) = qK, L, M, F (neřešeno jako další stavy)
*/

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

// const Final : set of TypStav = [StavC, StavE, StavF];
      
Atom AktSym;
char Z; 
extern ifstream Inf;
    
     
void CtiZnak(char &Z);
void GetAtom(Atom &Vysled);
void VypisAtom(Atom A);
string ZobrazAtom(Terminal X);

unsigned int StrToInt(string X);
#endif