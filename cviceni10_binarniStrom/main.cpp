
#include <iostream>
#include <fstream>

using namespace std;

typedef struct Zak Zak;
struct Zak{
    string jmeno;
    Zak *prava;
    Zak *leva;
};


//domaci ukol pridej hloubku stromu
void pridej(Zak* &strom, Zak *novy_prvek, int &pocet){
    pocet = 0;
    if(novy_prvek->jmeno < strom->jmeno)  {
        if(strom->leva == NULL){
            strom->leva = novy_prvek;
            pocet++;

        } else {
            pridej(strom->leva, novy_prvek, pocet);
            pocet++;
        }
    } else {
        if (strom->prava == NULL){
            strom->prava = novy_prvek;
        } else {
            pridej(strom->prava, novy_prvek, pocet);
        }
    }
}


void vypisABC(Zak* strom){
    if(strom->leva != NULL) vypisABC(strom->leva);
    cout << strom->jmeno << endl;
    if(strom->prava != NULL) vypisABC(strom->prava);
}



int main() {
    Zak *trida = new Zak;
    cin >> trida->jmeno;
    trida->leva = NULL;
    trida->prava = NULL;
    string novy;
    cin>>novy;
    while(novy != "xxx"){
        Zak *novy_zak = new Zak;
        novy_zak->jmeno=novy;
        novy_zak->leva = NULL;
        novy_zak->prava = NULL;
        pridej(trida, novy_zak);
        cin>>novy;
    }
    vypisABC(trida);

    return 0;
}
