// Nastavte lokomotivě s názvem X rychlostní stupeň Y.
// Parametry: název_Lokomotivy, rychlostní_Stupeň

#include "json.cpp"
#include "lexatomy.cpp"
#include "mzjisti.cpp"
#include "mptvlakyo_loko.cpp"
#include <iostream>
using namespace std;

int main(int pocParam, char* param[]){
    unsigned int adresaLokomotivy;
    string strAdresa = "";
    string nazevLokomotivy = "";
    Polozka H; UkPolozka X;
    if (pocParam > 1){  //kontrola zadání parametru při spuštění programu
        nazevLokomotivy = param[1];  //název lokomotivy je zadáván jako 1. parametr z příkazového řádku
        X = ZiskejData("loks", 0);  //získá ze serveru kolejiště "seznam" všech prvků typu lok – lokomotivy; seznam uloží do souboru data.jsn
        if (X != NULL){  //kontrola obdržení dat ze serveru
            strAdresa = VyhledejIdLokomotivy(nazevLokomotivy);  //vyhledání id prvku, který má příslušný název
            if (strAdresa != ""){  //kontrola výskytu prvku v seznamu ze serveru kolejiště (v případě, že nebyl nalezen, je funkcí VyhledejIdLokomotivy(..) vrácen prázdný řetězec)
                adresaLokomotivy = StrToInt(strAdresa);  //převod id z řetězce na celé číslo
                H.Nazev = "speedStep";  //název položky jejíž hdnotu bedeme měnit
                H.Udaj = typretez;
                H.retez = "";
                if (pocParam > 2){  //kontrola zadání 2. parametru při spuštění programu
                    H.retez = param[2];  //rychlostní stupeň je zadáván jako 2. parametr z příkazového řádku
                    PosliData("lokState", adresaLokomotivy, "speedStep", H);  //odeslání nové hodnoty položky na server kolejiště
                    cout << "Lokomotivě " << nazevLokomotivy << " byl nastaven rychlostní stupeň: " << H.retez << "." << endl;
                    return 0;
                } else {
                    cout << "Nebyl zadán rychlostní stupeň, na nějž má být lokomotiva " << nazevLokomotivy << " rozjeta!" << endl;
                    return 2;
                }
            } else {
            cout << "Zadanému názvu neodpovídá žádná lokomotiva!" << endl;
            return 2;
            }
        } else {
            cout << "Data lokomotiv nebyla nalezena!" << endl;
            return 2;
        }
    } else {
        cout << "Nebyla zadána adresa lokomotivy!" << endl;
        return 2;
    }
}