#include "lexatomy.h"
#include <iostream>
#include <fstream>
using namespace std;

bool NeniEof=true;
ifstream Inf;

unsigned int StrToInt(string X){
 unsigned int vysl;
 fstream soub; soub.open("pom.txt",ios::out);
 soub << X;
 soub.close();
 soub.open("pom.txt",ios::in);
 soub >> vysl;
 soub.close();
 return vysl;
}

float StrToFloat(string X){
 float vysl;
 fstream soub; soub.open("pom.txt",ios::out);
 soub << X;
 soub.close();
 soub.open("pom.txt",ios::in);
 soub >> vysl;
 soub.close();
 return vysl;
}


string ZobrazAtom(Terminal X){
 switch (X){
     case lbracesym  : return "lbracesym";
     case rbracesym  : return "rbracesym";
     case lbrsym     : return "lbrsym";
     case rbrsym     : return "lbrsym";
     case commasym   : return "commasym";
     case colonsym   : return "colonsym";
     case strsym     : return "strsym";
     case intnumsym  : return "intnumsym";
     case realnumsym : return "realnumsym";
     case falsesym   : return "falsesym";
     case truesym    : return "truesym";
     case eofsym     : return "eof";
  }
}

void VypisAtom(Atom A){
 switch (A.Symbol) {
   case  strsym: cerr << ZobrazAtom(A.Symbol) << ", " << A.Value.vs << endl; break;
   case  intnumsym: cerr << ZobrazAtom(A.Symbol) << ", " << A.Value.vi << endl; break;
   case  realnumsym: cerr << ZobrazAtom(A.Symbol) << ", " << A.Value.vr << endl; break;
   default: cerr << ZobrazAtom(A.Symbol) << ", --" << endl;
  }
}

void LexError(string X){
 cerr << "Error: " << X << endl;
}

void CtiZnak(char &Z){
 // řešení opisu zdrojového textu, indikace pozice, indikace chyby 
  if (not Inf.eof()) {
          Inf.get(Z); 
          // cerr.put(Z); kontrolní opis vypnut
          NeniEof=true;
       } else {
          NeniEof=false;   
          AktSym.Symbol=eofsym;
          AktSym.Value.vs="";
  }
}
 
void GetAtom(Atom  &Vysled){
 TypStav S;
 bool Konec;
 unsigned int PomInt;
 float PomReal;
 int Kod;

 S=StavS; // počáteční stav 
 Konec=false;
 while (not Konec) {
         
    switch (S) {
       case StavS: 
            switch (Z) {
               case '"': S=StavA;
                         Vysled.Symbol=strsym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);
                         break;      
               case 'f':
               case 'F': S=StavF;
                         Vysled.Symbol=falsesym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);CtiZnak(Z);CtiZnak(Z);CtiZnak(Z);CtiZnak(Z);
                         Konec=true;
                         break;
               case 't':
               case 'T': S=StavF;
                         Vysled.Symbol=truesym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);CtiZnak(Z);CtiZnak(Z);CtiZnak(Z);
                         Konec=true;
                         break;
               case '+':
               case '-': S=StavB;
                         Vysled.Symbol=intnumsym;
                         Vysled.Value.vs=Z;
                         CtiZnak(Z);
                         break;
               case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':
               case '9': S=StavC;
                         Vysled.Symbol=intnumsym;
                         Vysled.Value.vs=Z;                
                         CtiZnak(Z);
                         break;      
               case ',': S=StavF;
                         Vysled.Symbol=commasym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);
                         Konec=true;
                         break;
               case ':': S=StavF;
                         Vysled.Symbol=colonsym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);
                         Konec=true;
                         break;
               case '{': S=StavF;
                         Vysled.Symbol=lbracesym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);
                         Konec=true;
                         break;
               case '}': S=StavF;
                         Vysled.Symbol=rbracesym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);
                         Konec=true;
                         break;
               case '[': S=StavF;
                         Vysled.Symbol=lbrsym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);
                         Konec=true;
                         break;
               case ']': S=StavF;
                         Vysled.Symbol=rbrsym;
                         Vysled.Value.vs="";
                         CtiZnak(Z);
                         Konec=true;
                         break;
               case ' ':
               case '\n':
               case '\x9': CtiZnak(Z); break;
               case '\x4': Konec=true; break;
               default: {string Pom="Nepovolený znak na vstupu: \"";
                         Pom+=Z;
                         Pom+="\"";
                         LexError(Pom); 
                         CtiZnak(Z);
                    }
              }; break;
           
           case StavF: break;
           case StavA: 
             switch (Z) {
               case '"': S=StavF;
                         CtiZnak(Z);
                         Konec=true;
                         break;
               default: {Vysled.Value.vs+=Z;
                     CtiZnak(Z);
                     }
              }; break;
           case StavB: if (Z>='0' and Z<='9'){
                           S=StavC;
                           Vysled.Value.vs+=Z;
                           CtiZnak(Z);
                       } break;    
           case StavC: if (Z>='0' and Z<='9'){
                           Vysled.Value.vs+=Z;
                           CtiZnak(Z);
                       } else if (Z=='.'){
                           S=StavD;
                           Vysled.Symbol=realnumsym;
                           Vysled.Value.vs+=Z;
                           CtiZnak(Z);
                       } else {Konec=true;
                               Vysled.Value.vi=StrToInt(Vysled.Value.vs);
                       }; break;
           case StavD: if (Z>='0' and Z<='9'){
                           S=StavE;
                           Vysled.Value.vs+=Z;
                           CtiZnak(Z);
                       } break;
           case StavE: if (Z>='0' and Z<='9'){
                           Vysled.Value.vs+=Z;
                           CtiZnak(Z);
                       } else {Konec=true;
                           Vysled.Value.vr=StrToFloat(Vysled.Value.vs);
                       }; break;
           };
           if (not NeniEof) Konec=true;
       } 
}
 
