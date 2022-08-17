// Postavte jízdní cestu s názvem X.
// Parametr: název_Cesty

#include "json.cpp"
#include "lexatomy.cpp"
#include "mzjisti.cpp"
#include "mptvlakyo_jc.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(int pocParam, char* param[]){
    string nazevCesty = "";
    string idCesty = "";
    string koncovka = "/activate";
    Polozka H; UkPolozka X;
    if (pocParam > 1){  //kontrola zadání parametru při spuštění programu
        nazevCesty = param[1];  //název jízdní cesty je zadáván jako 1. parametr z příkazového řádku
        X = ZiskejData("jc", 0);  //získá ze serveru kolejiště "seznam" všech prvků typu jc – jízdní cesty; seznam uloží do souboru data.jsn
        if (X != NULL){  //kontrola obdržení dat ze serveru
            idCesty = VyhledejIdPrvku(nazevCesty);  //vyhledání id prvku, který má příslušný název
            if (idCesty != ""){  //kontrola výskytu prvku v seznamu ze serveru kolejiště (v případě, že nebyl nalezen, je funkcí VyhledejIdPrvku(..) vrácen prázdný řetězec)
                idCesty.append(koncovka);  //přiřazení koncovky "/activate" k řetězci s id jízdní cesty (nutné k vytvoření příkazu k postavení cesty)
                H.Nazev = "";
                H.Udaj = typretez;
                H.retez = "";
                PosliData("jc", idCesty, "", H);  //odeslání příkazu k postavení cesty na server kolejiště
                cout << "Jízdní cesta " << nazevCesty << " byla postavena." << endl;
                return 0;
            } else {
            cout << "Zadanému názvu neodpovídá žádná jízdní cesta!" << endl;
            return 2;
            }
        } else {
            cout << "Data jízdních cest nebyla nalezena!" << endl;
            return 2;
        }
    } else {
        cout << "Nebylo zadáno id jízdní cesty!" << endl;
        return 2;
    }
}