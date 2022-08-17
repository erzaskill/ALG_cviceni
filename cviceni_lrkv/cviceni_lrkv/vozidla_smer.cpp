// Změňte směr jízdy lokomotivy s názvem X na opačný.
// Parametr: název_Lokomotivy

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
                X = ZiskejData("lokState", adresaLokomotivy);  //získá ze serveru kolejiště detailní informace k lokomotivě zadaného id
                if (X != NULL) {  //kontrola obdržení dat ze serveru
                    VyhledHodn(X->objekt, "direction", H); //v detailních datech ze serveru vyhledá hodnotu položky "direction"
                    cout << "Aktuální směr lokomotivy " << nazevLokomotivy << " je: " << H.retez << endl;
                    if (H.retez == "forward"){  //na základě současné hodnoty položky "direction" je vybrána nová hodnota, která bude položce nově přiřazena
                        H.retez = "backward";
                    } else {
                        H.retez = "forward";
                    }
                    PosliData("lokState", adresaLokomotivy, "direction", H);  //odeslání nové hodnoty položky na server kolejiště
                    cout << "Lokomotivě " << nazevLokomotivy << " byl změněn směr jízdy." << endl;
                    return 0;
                } else {
                    cout << "Data k lokomotivě " << nazevLokomotivy << " nebyla nalezena!" << endl;
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
        cout << "Nebyl zadán název lokomotivy!" << endl;
        return 2;
    }
}