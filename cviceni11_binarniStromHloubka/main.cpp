#include <iostream>
#include <fstream>
using namespace std;



//Je dana definice uzlu binarniho usporadaneho stromu:

/*
struct Uzel {
    int hodnota;
    Uzel *levy;
    Uzel *pravy;
};
*/
/*
 * Implementujte podprogram hloubka, ktery urci hloubku stromu s takto definovanymi uzly
 * Samostatny koren ma hloubku 1, strom tvoreny pouze korenem a jeho nasledniky ma hloubku 2 atd.
 * */

/*
int hloubka(Uzel* u){
    if(u==NULL){
        return 0;
    } else {
        int pocetL = hloubka(u->levy);
        int pocetP = hloubka(u->pravy);
        if (pocetL > pocetP){
            return 1 + pocetL;
        } else {
            return 1 + pocetP;
        }
    }

}

void vypisABC(Uzel* strom){
    if(strom->levy != NULL) vypisABC(strom->levy);
    cout << strom->hodnota << endl;
    if(strom->pravy != NULL) vypisABC(strom->pravy);
}

void pridej(Uzel* &strom, Uzel *novy_prvek){
    if(novy_prvek->hodnota < strom->hodnota)  {
        if(strom->levy == NULL){
            strom->levy = novy_prvek;

        } else {
            pridej(strom->levy, novy_prvek);
        }
    } else {
        if (strom->pravy == NULL){
            strom->pravy = novy_prvek;
        } else {
            pridej(strom->pravy, novy_prvek);
        }
    }
}
*/
/*
int main() {
    Uzel *strom = new Uzel;
    cin >> strom->hodnota;
    strom->levy = NULL;
    strom->pravy = NULL;
    int novy;
    cin >> novy;
    while(novy != 0){
        Uzel *novy_uzel = new Uzel;
        novy_uzel->hodnota=novy;
        novy_uzel->levy = NULL;
        novy_uzel->pravy = NULL;
        pridej(strom, novy_uzel);
        cin>>novy;
    }
    vypisABC(strom);
    cout << endl;
    cout << hloubka(strom);

    return 0;
}
*/



/*
 * Na standardnim vstupu se nachazi neznamy pocet retezcu. Vyuzitim binarniho usporadaneho stromu tyto
 * retezce seradte podle delky a vypiste je do textoveho souboru (diskove retezec souboru zvolte).
 * Ve vystupnim souboru bude kazdy retezec na samostatnem radku.
*/

struct Uzel{
    string retezec;
    Uzel *prava;
    Uzel *leva;
};

void pridej(Uzel* &strom, Uzel *novy_prvek){
    if(novy_prvek->retezec.length() < strom->retezec.length())  {
        if(strom->leva == NULL){
            strom->leva = novy_prvek;

        } else {
            pridej(strom->leva, novy_prvek);
        }
    } else {
        if (strom->prava == NULL){
            strom->prava = novy_prvek;
        } else {
            pridej(strom->prava, novy_prvek);
        }
    }
}


void vypisABC(Uzel* strom, ofstream &soubor){
    if(strom->leva != NULL) vypisABC(strom->leva, soubor);

    soubor << strom->retezec << endl;
    //cout << strom->retezec << endl;
    if(strom->prava != NULL) vypisABC(strom->prava, soubor);
}



int main() {
        Uzel *trida = new Uzel;
        cin >> trida->retezec;
        trida->leva = NULL;
        trida->prava = NULL;
        string novy;
        while (cin >> novy) {
            Uzel *novy_zak = new Uzel;
            novy_zak->retezec = novy;
            novy_zak->leva = NULL;
            novy_zak->prava = NULL;
            pridej(trida, novy_zak);
        }
        ofstream soubor("retezce.txt");
        vypisABC(trida, soubor);
        soubor.close();

    return 0;
}

