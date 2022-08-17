using namespace std;
#include "iostream"
#include "fstream"

struct Zvire{
    string druhove_jmeno;
    string rodove_jmeno;
    int pocet;
    char sekce;
    Zvire *dalsi; //dynamicky seznam
};

void pridejZvire(Zvire* &strom, Zvire* &novy){
    if(strom == NULL){
        strom = novy;
    } else {
        if (strom->pocet < novy->pocet){
            novy->dalsi = strom;
            strom = novy;
        } else {
            Zvire *pom;
            pom = strom;
            while (pom->dalsi != NULL and pom->dalsi->pocet > novy->pocet){
                pom = pom->dalsi;
            }
            novy->dalsi = pom->dalsi;
            pom->dalsi = novy;

        }
    }
}


void vypis(Zvire* strom){
    if (strom->dalsi != NULL){
        vypis(strom->dalsi);
    }
    cout << strom->pocet << endl;
}


int main(){
    Zvire* zvire = new Zvire;
    ifstream soubor("zoo.txt");
    if(soubor.is_open()){
        while(!soubor.eof()){
            Zvire *novy;
            novy = new Zvire;
            soubor>>novy->rodove_jmeno>>novy->druhove_jmeno>>novy->pocet>>novy->sekce;
            novy->dalsi = NULL;
            pridejZvire(zvire, novy);

        }
        soubor.close();
    }else {
        cout << "Nepodarilo se otevrit soubor.";
    }
    vypis(zvire);
    return 0;
}