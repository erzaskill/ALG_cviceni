#include <iostream>
using namespace std;

typedef struct typStudent{
    string jmeno;
    string prijmeni;
    float vyska;
    char pohlavi;
    int rok;
    typStudent *dalsi; //ukazatel, na dalsiho studenta
};

void nactiStudenta (typStudent &s){ //Musime pridat & - aby se nacteni provedl i mimo telo podprogramu
    cout << "jmeno: " << endl;
    cin >> s.jmeno;
    cout << "prijmeni: " << endl;
    cin >> s.prijmeni;
    cout << "vyska: " << endl;
    cin >> s.vyska;
    cout << "pohlavi: " << endl;
    cin >> s.pohlavi;
    cout << "rok: " << endl;
    cin >> s.rok;
}

void pridejNaKonec(typStudent* &seznam){
    if(seznam ==NULL){
        seznam = new typStudent();
        nactiStudenta(*seznam);
    } else {
        typStudent *pom=seznam;
        while(pom->dalsi!=NULL){ // dostavame se na konec
            pom=pom->dalsi;
        }
        pom->dalsi = new typStudent; //jsme na konci, vytvarime studenta
        nactiStudenta(*pom->dalsi);
    }
}

void pridejNaZacatek(typStudent* &seznam){ //& - protoze dojde ke zmene v seznamu(pridani), kterou chceme videt
    typStudent *pom = new typStudent;
    nactiStudenta(*pom);
    pom->dalsi = seznam;
    seznam = pom;
}

void vypisStudenta (typStudent s){
    cout << "jmeno: " << s.jmeno << endl;
    cout << "prijmeni: " << s.prijmeni << endl;
    cout << "vyska: " << s.vyska << endl;
    cout << "pohlavi: " << s.pohlavi << endl;
    cout << "rok nar.: " << s.rok << endl;
}

void vypisSeznam(typStudent *seznam){
    while(seznam!=NULL){
        vypisStudenta(*seznam);
        seznam = seznam->dalsi;
    }
}

void odeberStudentaK(typStudent* &seznam){
    if(seznam ==NULL){
        cout << "Nemuzes mazat z prazdneho seznamu" << endl;
    } else {
        if(seznam->dalsi == NULL){
            delete(seznam); //odstranuje seznam z pameti, uvolnujeme pamet
            seznam=NULL; //odstranujeme adresu, ve ktere uz nic neni
        } else {
            typStudent *pom=seznam;
            while(pom->dalsi->dalsi!=NULL) { // dostavame se na prvek pred koncem
                pom = pom->dalsi;
            }
            delete(pom->dalsi);
            pom->dalsi = NULL;
        }
    }
}

void odeberStudentaZ(typStudent* &seznam){
    if(seznam == NULL){
        cout << "Nemuzu mazat z prazdneho seznamu! " << endl;
    } else {
        typStudent *pom=seznam->dalsi; //do promenne si ulozime druhy prvek
        delete(seznam); //uvolnuje se prostor
        seznam=pom;     // do adresy se zapisuje ten dalsi druhy prvek
    }
}

int main() {
    typStudent *student; //musime si vytvorit prostor pomoci "new", kde se ulozi odkaz
    student = NULL;
    /*
    cin >> student->jmeno >> student->prijmeni >> student->vyska;
    student->dalsi = new typStudent();
    cin >> student->dalsi->jmeno >> student->dalsi->prijmeni >> student->dalsi->vyska;
    cout << student->dalsi->jmeno << " " << student->dalsi->prijmeni << " " << student->dalsi->vyska;
    */

    pridejNaKonec(student);
    pridejNaZacatek(student);
    pridejNaKonec(student);
    odeberStudentaZ(student);
    odeberStudentaK(student);
    vypisSeznam(student);

}
