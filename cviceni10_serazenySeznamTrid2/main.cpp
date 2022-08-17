// Vytvořte datový typ pro informace o žákovi, který bude obsahovat položky: jméno, příjmení, třída, pohlaví, průměrná známka a ukazatel na dalšího žáka.
// Je dán textový soubor https://user.mendelu.cz/xturcin0/zaci.txt, kde se nacházejí informace o žácích 4. tříd.
// Předpokládejte, že soubor s takovými daty je uložen v aktuálním adresáři.
// Z dat v souboru vytvořte pro každou třídu (A, B, C) samostatný lineární jednosměrný dynamický seznam seřazený podle průměru žáků.
// Takto vytvořené seznamy tříd pak vypište ve vhodné formě na standardní výstup.

#include <iostream>
#include <fstream>

using namespace std;
typedef struct Zak Zak;
struct Zak{
    string jmeno;
    string prijmeni;
    string trida;
    char pohlavi;
    float prumer;
    Zak *dalsi;
};


//podprogram pro vypis Zaka.
void vypisZaka (Zak* z){
    cout << "jmeno: " << z->jmeno << endl;
    cout << "prijmeni: " << z->prijmeni << endl;
    cout << "trida: " << z->trida << endl;
    cout << "pohlavi: " << z->pohlavi << endl;
    cout << "prumer: " << z->prumer << endl;
}

//pridani Zaka do serazeneho seznamu.
void pridejZaka (Zak* &sez, Zak* &z){
    Zak *pom;
    if (sez == NULL){
        sez = z;
    }
    else{
        if (sez->prumer > z->prumer){
            z->dalsi = sez;
            sez = z;
        }
        else{
            pom = sez;
            while (pom->dalsi != NULL and pom->dalsi->prumer < z->prumer){
                pom = pom->dalsi;
            }
            z->dalsi = pom->dalsi;
            pom->dalsi = z;
        }
    }
}

//podprogram pro vypis seznamu Zaka/.
void vypisSeznam (Zak * sez){
    while (sez != NULL){
        vypisZaka (sez);
        cout << "--------------------------------------------------" << endl;
        sez = sez->dalsi;
    }
}

//podprogram na uvolneni pameti
void vyprazdniSeznam(Zak * &sez){
    while(sez!=NULL){
        Zak* pom = sez;
        sez=sez->dalsi;
        delete pom;
    }
}

int main (){
    Zak *tridaA = NULL;
    Zak *tridaB = NULL;
    Zak *tridaC = NULL;
    Zak *aktualni;
    ifstream vstup ("zaci.txt");
    if (vstup.is_open ()){
        while (!vstup.eof()){
            aktualni = new Zak;
            vstup >> aktualni->jmeno >> aktualni->prijmeni >> aktualni->trida >> aktualni->pohlavi >> aktualni->prumer;
            aktualni->dalsi = NULL;
            if (aktualni->trida == "4.A"){
                pridejZaka (tridaA, aktualni);
            }
            else if (aktualni->trida == "4.B"){
                pridejZaka (tridaB, aktualni);
            }
            else if (aktualni->trida == "4.C"){
                pridejZaka (tridaC, aktualni);
            }
        }
        vstup.close();
    }
    else{
        cout << "Nepodarilo se otevrit soubor.";
    }
    cout << endl << "----4.A----" << endl;
    vypisSeznam (tridaA);
    cout << endl << "----4.B----" << endl;
    vypisSeznam (tridaB);
    cout << endl << "----4.C----" << endl;
    vypisSeznam (tridaC);

    vyprazdniSeznam(tridaA);
    vyprazdniSeznam(tridaB);
    vyprazdniSeznam(tridaC);
    return 0;
}