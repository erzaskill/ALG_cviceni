#include <iostream>
using namespace std;
int nasobeniZapornychCisel(int nasobec, int nasobitel){
    if (nasobitel < 0){
        return -nasobeniZapornychCisel(nasobec, -nasobitel);
    } else {
        int puvodniHodnota = nasobec;
        for(int x = 1; x!=nasobitel; x++){
            nasobec = nasobec + puvodniHodnota;
        }
        return nasobec;
    }

}

int nasobeni(int nasobec, int nasobitel){
    int puvodniHodnota = nasobec;
    for(int x = 1; x!=nasobitel; x++){ // x musi byt 1, protoze nezacinam od nuly a hodnotu uz tam mam od zacatku prirazenou.
        nasobec = nasobec + puvodniHodnota;
    }
    return nasobec;
}

int celociselnyPodil(int delenec, int delitel){
    int podil = 0;
    while (delenec >= delitel){
        delenec = delenec - delitel;
        podil = podil + 1;
    }
    return podil; // Ve funkci se nedelaji zadne vypisy -> funkce vraci hodnotu (return)
    // procedury delaji vypisy
}
int zbytek(int delenec, int delitel){
    while (delenec >= delitel){
        delenec = delenec - delitel;
    }
    return delenec;
}


int main() {
    int c1, c2;
    cin >> c1 >> c2;
    cout << celociselnyPodil(c1, c2) << " (" << zbytek(c1, c2) << ")" << endl;
    cout << nasobeniZapornychCisel(c1, c2);

    /* Celociselny podil
    int a;
    int b;
    int pocet = 0;

    cout << "Zapis prvni cislo. " << endl;
    cin >> a;
    cout << "Zapis druhe cislo. " << endl;
    cin >> b;

    while (a >= b) {
        a = a-b;
        pocet = pocet + 1;
    }

    cout << "Podil techto dvou cisel je: " << pocet << endl;
     */
    return 0;
}
