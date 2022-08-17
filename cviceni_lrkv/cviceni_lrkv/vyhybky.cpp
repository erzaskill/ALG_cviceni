// Přehoďte výhybku s názvem X do opačného stavu.
// Parametr: název_Výhybky

#include "json.cpp"
#include "lexatomy.cpp"
#include "mzjisti.cpp"
#include "mptvlakyo.cpp"
#include <iostream>
using namespace std;

int main(int pocParam, char* param[]){
    unsigned int idVyhybky;
    string strId = "";
    string nazevVyhybky = "";
    Polozka H; UkPolozka X;
    if (pocParam > 1){  //kontrola zadání parametru při spuštění programu
        nazevVyhybky = param[1];  //název výhybky je zadáván jako 1. parametr z příkazového řádku
        X = ZiskejData("blocks", 0);  //získá ze serveru kolejiště "seznam" všech prvků typu block – součásti kolejiště (výhybky, rozpojovače...); seznam uloží do souboru data.jsn
        if (X != NULL){  //kontrola obdržení dat ze serveru
            strId = VyhledejIdPrvku(nazevVyhybky);  //vyhledání id prvku, který má příslušný název
            if (strId != ""){  //kontrola výskytu prvku v seznamu ze serveru kolejiště (v případě, že nebyl nalezen, je funkcí VyhledejIdPrvku(..) vrácen prázdný řetězec)
                idVyhybky = StrToInt(strId);  //převod id z řetězce na celé číslo
                X = ZiskejData("blockState", idVyhybky);  //získá ze serveru kolejiště detailní informace k bloku zadaného id
                if (X != NULL) {  //kontrola obdržení dat ze serveru
                    VyhledHodn(X->objekt, "position", H);  //v detailních datech ze serveru vyhledá hodnotu položky "position"
                    cout << "Aktuální stav výhybky " << nazevVyhybky << " je: " << H.retez << endl;
                    if (H.retez == "+"){  //na základě současné hodnoty položky "position" je vybrána nová hodnota, která bude položce nově přiřazena
                        H.retez = "-";
                    } else {
                        H.retez = "+";
                    }
                    PosliData("blockState", idVyhybky, "position", H);  //odeslání nové hodnoty položky na server kolejiště
                    cout << "Výhybka " << nazevVyhybky << " byla přehozena do stavu: " << H.retez << endl;
                    return 0;
                } else {
                    cout << "Data k výhybce " << nazevVyhybky << " nebyla nalezena!" << endl;
                    return 2;
                }
            } else {
            cout << "Zadanému názvu neodpovídá žádná výhybka!" << endl;
            return 2;
            }
        } else {
            cout << "Data výhybek nebyla nalezena!" << endl;
            return 2;
        }
    } else {
        cout << "Nebyl zadán název výhybky!" << endl;
        return 2;
    }
}