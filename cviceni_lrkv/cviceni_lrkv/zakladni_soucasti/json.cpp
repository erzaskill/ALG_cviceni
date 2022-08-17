#include "json.h"
#include <fstream>
#include <iostream>
using namespace std;

// type SymSet = set of Terminal;


string DispSymset(string SS){
  return SS;
}
          
void ErrorSyn(string Expect, Terminal Skut){
 cerr << "Error: očekává se " << DispSymset(Expect) << "ale na vstupu je " <<
    ZobrazAtom(Skut) << endl;
}
 
void ErrorSem(string S){
 cerr << "Error: " << S << endl;
}
 
void Lex(Terminal Expected){
 if (AktSym.Symbol!=Expected) ErrorSyn(ZobrazAtom(Expected), AktSym.Symbol);
 GetAtom(AktSym);
}
 
/************** Sémantické procedury ****************/

typedef enum TypGenPrvek {ZacObjekt, ZacPole, StrConst, IntConst, RealConst,
                          BoolConst, KonSeznamu} TypGenPrvek;

/*procedure Gen(Prvek: TypGenPrvek);
 var B: byte;
 begin B:=ord(Prvek);
       case Prvek of
         ZacObjekt: BlockWrite(OutF, B, 1);
         ZacPole: BlockWrite(OutF, B, 1);
         StrConst: begin BlockWrite(OutF, B, 1); 
                         BlockWrite(OutF, AktSym.Value.vs, Length(AktSym.Value.vs)+1);
                   end;
         IntConst: begin BlockWrite(OutF, B, 1);
                         BlockWrite(OutF, AktSym.Value.vi, 2);
                   end;
         RealConst: begin BlockWrite(OutF, B, 1);
                          BlockWrite(OutF, AktSym.Value.vr, 4);
                    end;
         BoolConst:begin BlockWrite(OutF, B, 1);
                         B:=byte(AktSym.Symbol=truesym);
                         BlockWrite(OutF, B, 1);
                   end;
         KonSeznamu: begin B:=255;
                           BlockWrite(OutF, B, 1);
                     end;          
       end  
 end;
*/
 
/* Gramatika:
<sobjekt>   --> lbracesym <slozka><slozka1> rbracesym
<slozka>    --> strsym colonsym <shodnota> | <spole> | <sobjekt>
<slozka1>   --> commasym <slozka><slozka1> | @
<shodnota>  --> strsym | intnumsym | realnumsym | falsesym | truesym | <spole> | <sobjekt>
<spole>     --> lbrsym <shodnota><shodnota1> rbrsym
<shodnota1> --> commasym <shodnota><shodnota1> | @



*/

/************** Syntaktické procedury ***************/
 
UkPolozka SObjekt();
void Slozka(UkPolozka UP);
void Slozka1(UkPolozka &UP);
void SHodnota(UkPolozka UP);
UkPolozka SHodnota1();
UkPolozka SPole();

//------------------------

UkPolozka SObjekt(){
 UkPolozka Pom = new Polozka;
 Lex(lbracesym); Slozka(Pom); Slozka1(Pom->Dalsi); Lex(rbracesym);
 return Pom;
}
 
void Slozka(UkPolozka UP){ 
 switch (AktSym.Symbol) {
  case strsym:  UP->Nazev=AktSym.Value.vs; 
                  Lex(strsym); Lex(colonsym); 
                  SHodnota(UP);
                break;
  case lbrsym:  UP->Udaj = typpole;
                UP->pole = SPole();
                break;
  case lbracesym: UP->Udaj = typobjekt;
                  UP->objekt = SObjekt();
                break;
  default: ErrorSyn("strsym, lbrsym, lbracesym", AktSym.Symbol);
 }
}
 
void Slozka1(UkPolozka &UP){
 switch (AktSym.Symbol) {
  case commasym: Lex(commasym); UP=new Polozka; Slozka(UP); Slozka1(UP->Dalsi);
                 break;
  case rbracesym:
  case rbrsym: UP=NULL; break;
  default: ErrorSyn("commasym, rbracesym, rbrsym", AktSym.Symbol);
 }
}
 
void SHodnota(UkPolozka UP){
 switch (AktSym.Symbol) {
  case strsym:     UP->Udaj=typretez; UP->retez=AktSym.Value.vs; 
                       Lex(strsym); break;
  case intnumsym:  UP->Udaj=typcele; UP->cele=AktSym.Value.vi;
                       Lex(intnumsym); break;
  case realnumsym: UP->Udaj=typrealne; UP->realne=AktSym.Value.vr;
                       Lex(realnumsym); break;
  case falsesym:   UP->Udaj=typlogik; UP->logik=false;
                       Lex(falsesym); break;
  case truesym:    UP->Udaj=typlogik; UP->logik=true;
                       Lex(truesym); break;
  case lbrsym:     UP->Udaj=typpole; UP->pole=SPole(); break;
  case lbracesym:  UP->Udaj=typobjekt; UP->objekt=SObjekt(); break;
  default: ErrorSyn("strsym, intnumsym, realnumsym, falsesym, truesym, lbrsym, lbracesym", AktSym.Symbol);
  }
}
 
UkPolozka SPole(){ 
 UkPolozka Pom = new Polozka;
 Pom->Nazev="";
 Lex(lbrsym); 
 if (AktSym.Symbol!=rbrsym) {
          SHodnota(Pom); 
          Pom->Dalsi=SHodnota1();
 }
 Lex(rbrsym);
 return Pom;    
}
 
UkPolozka SHodnota1(){
 UkPolozka Pom;
 switch (AktSym.Symbol) {
  case commasym:  Pom=new Polozka; Pom->Nazev=""; Lex(commasym); 
                  SHodnota(Pom); 
                  Pom->Dalsi=SHodnota1();
                  return Pom;
  case rbrsym: return NULL;
  default: ErrorSyn("commasym, rbrsym", AktSym.Symbol);
 }
}
 
UkPolozka ParseJson(string JmInF){
  Inf.close();
  Inf.open(JmInF.c_str(), ios::in);
  CtiZnak(Z);
  GetAtom(AktSym);
  return SObjekt();
  Inf.close();
}

int PocMezer=0;

string Odsaz(){
  string Pom="";
  for (int i=1; i<PocMezer; i++) Pom+=" ";
  return Pom;
}

void VypisPole(UkPolozka H);
void VypisPam(UkPolozka H);

void VypisVZ(UkPolozka VZ){
  cerr << Odsaz()<<"Hodnota -- ";
  switch (VZ->Udaj) {
    case typretez: cerr << "řetěz, " << VZ->retez << endl; break;
    case typcele:  cerr << "celé,  " << VZ->cele << endl;  break;
    case typrealne: cerr << "reálné, "<<VZ->realne<< endl; break;
    case typlogik: cerr << "logik, " << VZ->logik << endl; break;
    case typpole:  cerr << "pole, "; VypisPole(VZ->pole);  break;
    case typobjekt: cerr << "objekt, "; VypisPam(VZ->objekt);
  }
}

void VypisPole(UkPolozka H){
  UkPolozka Pom = H;
  while (Pom!=NULL) {
    VypisVZ(Pom);
    Pom=Pom->Dalsi;
  }
}

void VypisPam(UkPolozka H){
  UkPolozka Pom = H;
  cerr << Odsaz()<<"Nová úroveň --- " << endl;
  PocMezer+=2;
  while (Pom!=0){
    cerr <<Odsaz()<< "Položka: " << Pom->Nazev << endl;
    VypisVZ(Pom);
    Pom=Pom->Dalsi;
  }
  PocMezer-=2;
  cerr <<Odsaz()<< "Konec úrovně ---" << endl;
}