#include "mptvlakyo.h"
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstdio>

string IntToStr(unsigned int N){
 string Pom;
 fstream f; f.open("pom.txt", ios::out);
  if (f) {
     f << N;
     f.close();
     f.open("pom.txt",ios::in);
     f >> Pom;
  } else {cerr << "nebylo otevřeno."<< endl; Pom="XX";}
  return Pom;
}

string FloatToStrF(float R, int Pozic, int Prec){
 string Pom;
 fstream f; f.open("pom.txt", ios::out);
  if (f) {
     f << setw(Pozic) << setprecision(Prec) << R << endl;
     f.close();
     f.open("pom.txt",ios::in);
     getline(f, Pom);
  } else {cerr << "nebylo otevřeno."<< endl; Pom="XX";}
  return Pom;
}


string GenHod(Polozka X){
  switch (X.Udaj){
     case typretez:  return "\""+X.retez+"\"";
     case typcele:   return IntToStr(X.cele);
     case typrealne: return FloatToStrF(X.realne, 15, 3);
     case typlogik:  if (X.logik) return "true"; else return "false";
     case typpole:   return "";
     case typobjekt: return "";
  }
}

void GenData(string OutName, string T, string F, Polozka H){
 ofstream outs;
 outs.open(OutName.c_str(),ios::out);
 outs << "{\""+T+"\":{\""+F+"\":"+GenHod(H)+"}}"<<endl;
 outs.close();
}

UkPolozka ZiskejData(string T, unsigned int AdrId){
 UkPolozka Pom;
 int kod;
 string Param;
 string StrAdrId;
 if (AdrId==0) StrAdrId="";
    else StrAdrId="/"+IntToStr(AdrId);
 remove("data.jsn");
 Param="/usr/bin/wget "+ Server+"/"+T+StrAdrId+" -O data.jsn -q";
 kod=system(Param.c_str());
 if (kod==0) Pom=ParseJson("data.jsn");
    else Pom=NULL;
 return Pom;
}

void PosliData(string T, string AdrId, string fce, Polozka hod){
// T: URL (blockState, lokState); fce: název položky; hod: požadovaná hodnota
 int kod; string Param;
 GenData("odata.jsn", T, fce, hod);
 Param="/usr/bin/curl -T odata.jsn -H \"Authorization: Basic bHJrdjp5MlF0Qms5cmp1UWhmN2VG\" -H \"Content-type: application/json\" "+Server+"/"+T+"/"+AdrId;
 kod=system(Param.c_str());
 cerr << "posláno na /" << T << "/" << AdrId<<":"<<endl;
 if (kod==0) T="";
}

