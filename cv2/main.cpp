#include <iostream>
#include <valarray>
#include <cmath>
#include <fstream> // prace se soubory

using namespace std;


//Program bude nacitat cisla, do te doby dokud se nezada prvni zadane cislo, pote vypise nejvetsi a druhe nejvetsi cislo
void max1max2(){
    int prvni, c2, max1, max2, cislo;
    cin >> prvni;
    max1 = prvni;
    cin >> c2;
    if (c2>max1){
        max1 = max2;
        max1 = c2;
    } else {
        c2 = max2;
    }
    cin >> cislo;
    while (cislo != prvni){
        if (cislo > max1){
            max2 = max1;
            max1 = cislo;
        } else {
            if (cislo > max2){
                max2 = cislo;
            }
        }
        cin >> cislo;
    }
    cout << max1 << endl << max2 << endl;
}


// Vstupni data jsou tvorena dvojicemi udaju o cenach urcite akcie na burze. Je vzdy zadano datum (jako 8znakovy retezec)
// a za nim uzaviraci cena daneho obchodniho dne (desetinne cislo). Misto posledni dvojice je pouze jeden retezec s hodnotou
// "X". Vypiste na vystup datum, kdy doslo k nejvetsimu narustu ceny akcie proti predchozimu obchodnimu dni.
void akcie(){
    float akt_h, pred_h, max_narust;
    string akt_datum, max_datum;

    cin >> pred_h >> akt_datum;
    cin >> max_datum >> akt_h;
    max_narust= akt_h - pred_h;
    cin >> akt_datum;
    while(akt_datum != "X"){
        pred_h=akt_h;
        cin>>akt_h;
        if (akt_h-pred_h>max_narust){
            max_narust = akt_h-pred_h;
            max_datum=akt_datum;
        }
        cin >> akt_datum;
    }
    cout << max_datum;


}


//Na standardnim vstupu se nachazi rada celociselnych hodnot. Vypiste ze vstupni rady dve hodnoty s nejvetsim cifernym souctem.
unsigned int cif_soucet(int x){
    unsigned int soucet = 0;
    if (x < 0) {x = -x;}
    while (x > 0) {
        soucet += x % 10;
        x /= 10;
    }
    return soucet;
}

void max1max2_cif_soucet(){
    int cislo, max1=0, max2=0;
    while (cin >> cislo) {
        if (cif_soucet(cislo)> cif_soucet(max1)) {
            max2 = max1;
            max1 = cislo;
        } else if (cif_soucet(cislo) > cif_soucet(max2)) {
            max2 = cislo;
        }

    }
    cout << max1 << endl << max2 << endl;
}

//Na standardnim vstupu jsou pripraveny trojice realnych hodnot. Tyto trojice reprezentuji namerene denni teploty (rano, poledne,
// vecer). Jako ukonceni rady je misto posledni trojice pouze jedna hodnota -1000. Urcete a vypiste prumernou poledni teplotu a
// a dale vypiste, v kolika dnech bylo vecer chladneji nez rano.

//Zeptej se jestli je reseni spravne - po zadani -1000 hned ze startu
void teplota(){
    float rano, poledne, vecer = 0;
    int kolikatyDen = 1;
    float prumer = 0;
    int pocetChl = 0; //pocet kdy vecer bylo chladneji nez rano
    float soucetPol = 0;
    int pocet = 0;

    cout << "Zadej teploty " << kolikatyDen << ". dne." << endl;
    kolikatyDen++;
    cin >> rano;
    if (rano!=-1000){
        cin >> poledne; cin >> vecer;


        while (rano != -1000) { // dokud neni vlozena pouze jedna hodnota - nejsem si jisty spravnosti podminkou - ZEPTEJ SE
            if(vecer < rano) {pocetChl++;}
            pocet++;
            soucetPol+= poledne;
            cout << "Zadej teploty " << kolikatyDen << ". dne." << endl;
            kolikatyDen++;
            cin >> rano;
            if (rano!=-1000){
                cin >> poledne; cin >> vecer;
            }
        }
        prumer = soucetPol/pocet;
        cout << "Prumerna poledni teplota: " << prumer << endl;
        cout << "V " << pocetChl << " dnech bylo chladneji, vecer nez rano." << endl;
    } else {
        cout << "Na vstupu nejsou zadne hodnoty!" << endl;
    }


}

//Napište podprogram, který přečte ze standardního vstupu řadu desetinných hodnot zakončenou nulou
//a jako dvě výstupní hodnoty vydá průměr přečtené řady a počet záporných hodnot.
void AvgAndZapCisla(){
    int pocet = 0;
    float soucet = 0.0;
    int pocetZ = 0;
    float cislo;
    float prumer;
    cout << "Zadej cislo: " << endl;
    cin >> cislo;
    if (cislo < 0) {
        pocetZ++;
    }
    soucet += cislo;
    pocet++;
    while (cislo != 0.0){
        cout << "Zadej cislo: " << endl;
        cin >> cislo;
        if (cislo < 0) {
            pocetZ++;
        }
        soucet += cislo;
        pocet++;


    }
    prumer = soucet/pocet;
    cout << "Prumer: " << prumer << endl;
    cout << "Pocet zap. cisel: " << pocetZ << endl;

}




//Vrati ciselnou radu v obracenem poradi - rekurze

//ZEPTEJ SE JESTLI TO CHAPES SPRAVNE
void Obrat(){
    float c;
    if (cin >> c) {
        Obrat(); //bude nacitat cisla

        //Jak se to dostane k tomu vypisu vubec?
        cout << c << " "; //postupne se zacne vynorovat obsahy promenne v opacnem poradi
    }
}

//Na vstupu je rada celych cisel. Urcete aritmeticky prumer lichych cisel.
void aritmetickyPrumer(){
    int cisla;
    cin >> cisla;
    float soucet; //musi byt float, aby prumer nevysel celociselny (pokud delime dve cele cisla, tak vyjde cele cislo..)
    int licheCislaPocet;
    float prumer;
    if(abs(cisla) % 2 == 1) {
        soucet += cisla;
        licheCislaPocet++;
    }
    while(cin >> cisla){
        if(abs(cisla) % 2 == 1) {
            soucet += cisla;
            licheCislaPocet++;
        }
    }
    if (licheCislaPocet > 0) {
        prumer = soucet / licheCislaPocet;
        cout << "Prumer lichych cisel je: " << prumer << endl;
    } else {
        cout << "Nezadal si zadne liche cislo!" << endl;
    }
}

//Nactete prirozene cislo N, ktere je vetsi nez 2. Vypiste N prvnich clenu Fibonacciho posloupnosti.
void fibonaccihoPosloupnost(){
    unsigned int c1 = 0;
    unsigned int c2 = 1;
    unsigned int pocet;
    cout << "Nacti pocet: " << endl;
    cin >> pocet;
    if (pocet > 2){
        cout << "fibonacciho posloupnost: " << endl;
        for(int i=1; i<=pocet; i++){
            cout << c1 << ", ";
            c2 += c1;
            c1 = c2-c1;
        }
    } else {
        cout << "Pocet musi byt vetsi nez 2!" << endl;
    }
}

//Na vstupu je rada prirozenych cisel. Vypiste to, ve kterem se po sobe nejcasteji vyskytuje stejna cifra.
// Priklad vstupu: 231 2344 2453 122241 999899 277771 872422 325 88 253553
// Odpovidajici vystup: 277771




/* spatne
void stejnaCifra(){
    unsigned int pocetStejnychCifer = 1;
    unsigned int cislo;
    unsigned int cifra = cislo % 10;
    unsigned int cifra2;
    unsigned int max = 0;
    cislo /= 10;
    while (cislo > 0){
        cifra2 = cislo % 10;
        cislo /= 10;
        if(cifra == cifra2) {
            pocetStejnychCifer++;

        } else {
            pocetStejnychCifer=1;
        }
        if (pocetStejnychCifer > max) {
            max = pocetStejnychCifer;
        }
        cifra = cifra2;
    }
}
 */

//oprava
int cifryPoSobe(unsigned int cislo){
    int poc=1, maxPoc= 0, cislice;
    cislice=cislo%10;
    cislo/=10;
    while(cislo>0){
        if (cislo%10==cislice){
            poc++;
        } else {
            cislice=cislo%10;
            if(poc>maxPoc) {
                maxPoc = poc;
            }
            poc=1;
        }
        cislo /=10;
    }
    if(poc>maxPoc) {
        maxPoc = poc;
    }
    return maxPoc;
}

void stejnaCisla(){
    unsigned int cisla;
    int maxC = 0;
    while(cin >> cisla){
        if(cifryPoSobe(cisla) > cifryPoSobe(maxC)){
            maxC = cisla;
        }

    }
    cout << maxC << endl;
}

//Předpokládejme, že na vstupu je nezáporné celé číslo N a za ním následuje N desetinných čísel. Vypočtěte směrodatnou odchylku
//zadané řady. Pro výpočet lze použít výraz (v sesite), kde je průměrná hodnota vstupních čísel.

void smerodatnaOdchylka(){
    unsigned int pocet;
    cout << "Zadej pocet cisel v rade: " << endl;
    cin >> pocet;
    float pole[pocet];
    float soucet = 0;
    float prumer;
    float vysledek = 0;

    //vypocitani prumeru z nactenych cisel
    for (unsigned int i = 0; i<= pocet-1; i++){
        cin >> pole[i];
        soucet += pole[i];
    }
    prumer = soucet/pocet;
    //vypocitani smerodatne odchylky
    for (unsigned int i = 0; i<= pocet-1; i++) {
       vysledek += (pole[i] - prumer)*(pole[i] - prumer);
    }

    cout << "Smerodatna odchylka: " << sqrt(vysledek/(pocet-1)) << endl;



}

// Na standardnim vstupu se nachazeji tyto udaje o pracovnicich velke organizace: cislo pracovnika (retezcova hodnota), jeho plat
// (celosciselna hodnota) a cislo jeho pracoviste (hodnota v intervalu 100 az 999).
// Vypiste na standardni vystup seznam pracovist s prumernymi platy jejich zamestnancu. Mnozstvi vstupnich udaje neni znamo.

void seznamPracovistPrumerPlat(){
    string pracovnik;
    unsigned int plat, pracoviste;
    int sumy[900];
    int pocty[900];

    //vynulovani pole sumy a pocty
    for (int i = 0; i<900; i++) {
        sumy[i] = 0;
        pocty[i] = 0;
    }

    //Nacitam
    while (cin >> pracovnik >> plat >> pracoviste){
        sumy[pracoviste-100] += plat;
        pocty[pracoviste-100]++;

    }

    //Vypocitam prumer
    for (int i = 0; i<900; i++){
        if(pocty[i] > 0){
            cout << (i+100) << ": " << float(sumy[i])/pocty[i] << endl;
        }
    }
}

// Na vstupu je rada celych (kladnych i zapornych) cisel, jejich pocet ani posledni hodnota neni znama.
// Cisla mohou byt oddelena vsemi beznymi ciselnymi oddelovaci. Urcete pocty jednotlivych cifer, ktere se vyskytovaly v cislech zadane rady.

void PocetCiferZeSeznamuCisel(){
    int cifry[10];
    int cislo;

    //Vynulovani pole
    for (int i = 0; i<10; i++) {
        cifry[i] = 0;
    }

    //Dokud je co nacitat
    while (cin >> cislo) {
        cislo = abs(cislo);
        if (cislo == 0) {
            cifry[cislo]++;
        }
        while (cislo > 0) {
            cifry[cislo % 10]++;
            cislo /= 10;
        }

    }
    for (int i = 0; i < 10; i++){
        cout << "Pocet cifer: " << i << " :" <<cifry[i] << endl;
    }
}

//Na standardnim vstupu je rada desetinnych cisel. Tato cisla predstavuji hodnoty dvou ctvercovych matic
// zadanych po radcich. Vasim ukolem je nacist tyto dve matice, secist je a vysledek vypsat na standardni vystup.
// Rad matic (pocert radku/sloupcu) je zadan jako prvni parametr z prikazoveho radku.
// Predpokladejte, ze cisel na vstupu je vzdy dostatecne mnozstvi.

//vytvareni datoveho typu
typedef float typPole[10]; //matice 10x10
typedef typPole typMatice[10]; //10 prvku
//typedef float typMatice[10][10] //v teto variante nejsem schopny pracovat s celym radkem najednou

void nactiPole(typPole p, int n){
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
}

void nactiMatici(typMatice m, int r, int s){
    for (int i = 0; i < r; i++){
        nactiPole(m[i], s);
    }
}

void vypisPole(typPole p, int n){
    for(int i = 0; i< n; i++){
        cout << p[i] << " ";
    }
    cout << endl;
}

void vypisMatici(typMatice m, int r, int s){
    for (int i = 0; i < r; i++){
        vypisPole(m[i],s);
    }
    cout << endl;
}

void sectiMatice(typMatice m1, typMatice m2, typMatice vysledek, int r, int s){
    for (int i = 0; i < r; i++)
        for (int j = 0; j<s; j++){
            vysledek[i][j] = m1[i][j] + m2[i][j];
        }
}

//Predpokladejte, ze se na disku nachazi textovy soubor, v nemz jsou ulozeny udaje o zamestnancich
// - na kazdem radku je dvojice udaju: jmeno jako jeden retezec zakonceny mezerou a plat jako celociselna hodnota.
// Ctete tento soubor a na standardni vystup vypiste jmena vsech zamestnancu s platem nad 30 tisic Kc.

void zamestanci(){
    ifstream soubor("zamestnanci.txt");
    if (soubor.is_open()){
        string jmeno;
        int plat;
        while(!soubor.eof()){
            soubor >> jmeno >> plat;
            if(plat > 30000){
                cout << "Jmeno zamestnance: " << jmeno << endl;
            }
        }
        soubor.close();
    } else {
        cerr << "Soubor neni citelny" << endl;
    }
}

//V textovem souboru "hokej.liga" v aktualnim adresasri je na kazdem radku dvojice udaju o hokejistech: identifikacni retezec (10 znaku)
// a pocet vstrelenych branek. Pokud je soubor v poradku, prectete z nej vsechny udaje a vypiste na standardni vystup seznam hracu,
// kteri se netrefili ani jednou a jednoho hrace s nejvetsim spoctem vstrelenych branek. Nebude-li soubor zpracovany,
// vypiste odpovidajici chybove hlaseni a nastavte nenulovy vystupni kod programu

void hokejLiga(){
    ifstream soubor("hokej.liga");
    if(soubor.is_open()){
        string id;
        string maxID;
        int pocet;
        int maxPocet = 0;
        while(!soubor.eof()){
            soubor >> id >> pocet;
            if (pocet > maxPocet){
                maxPocet = pocet;
                maxID = id;
            } else if(pocet == 0) {
                cout << "Hokejista co netrefil ani jednu branku: " << id << endl;
            }
        }
        cout << "Hokejista co vstrelil nejvetsi pocet branek: " << maxID << endl;
        soubor.close();
    } else {
        cerr << "Soubor neni citelny" << endl;
        //return 2;
    }
}



/*
 * CO BUDE NA PRUBEZNEM TESTU V ALGU:
 * Zakladni pojmy: "co je algoritmus atd"
 * Vyznamy konstrukci co znamena typedef aatd..
 * Trasovaci tabulka - zjistit co v ktery okamzik bude v nejake promene
 * Doplnovacka na nejaky algortimus
 * Kompletni priklad - na nejaky jednopruchodovy algoritmus - bez pole.
 * A jeste jeden priklad - na dvoupruchodovy algoritmus - pole ci nejaka datova struktura
 *
*/

//Načtěte celé číslo a, které reprezentuje první člen geometrické posloupnosti. Dále načtěte reálné číslo (nenulové) q,
// které představuje podíl mezi jednotlivými členy geometrické posloupnosti.
// Vypište 50 prvních členů této geometrické posloupnosti (výpis proveďte tak, aby na řádku bylo vždy 10 členů).

void geometrickaPosloupnost(){
    int c;
    cin >> c;
    double q;
    cin >> q;
    for (int i=0; i<5; i++){
        for (int j=0; j<10; j++) {
            cout << c << " ";
            c *= q;
        }
        cout << endl;
    }
}

//Načtěte celé číslo a, které reprezentuje první člen aritmetické posloupnosti.
// Dále načtěte celé číslo (nenulové) d, které představuje rozdíl mezi jednotlivými členy aritmetické posloupnosti.
// Vypište 50 prvních členů této aritmetické posloupnosti (výpis proveďte tak, aby na řádku bylo vždy 10 členů).
void aritmetickaPosloupnost(){
    int c;
    cin >> c;
    double d;
    cin >> d;
    for (int i=0; i<5; i++){
        for (int j=0; j<10; j++) {
            cout << c << " ";
            c += d;
        }
        cout << endl;
    }
}


void jePrvocislo(){
    int cislo;
    bool prvocislo = true;
    cin >> cislo;

    if (cislo <= 1){
        cout << "Cislo neni prvocislo" << endl;
    }

    for (int i=2; i < cislo; i++){
        if (cislo % i == 0) {
            prvocislo = false;
        }
    }

    if (prvocislo==true){
        cout << "Cislo je prvocislo" << endl;
    } else {
        cout << "Cislo neni prvocislo" << endl;
    }
}

//Na vstupu je řada celých čísel ukončené číslem -333 (toto číslo do řady nepatří). Určete počet čísel větších než první zadané číslo řady.
void radaCisel1(){
    int cislo;
    cin >> cislo;
    int prvniCislo = cislo;
    int pocetVetsich = 0;
    while (cislo != -333){
        if (cislo > prvniCislo) {
            pocetVetsich++;
        }
        cout << "Zadej cislo: " << endl;
        cin >> cislo;
    }
    cout << pocetVetsich << endl;
}

//Na vstupu je řada celých čísel ukončené číslem -333 (toto číslo do řady nepatří). Určete aritmetický průměr lichých čísel.
void radaCisel2(){
    int cislo;
    cin >> cislo;
    int soucet = 0;
    int pocet = 0;
    float prumer;
    while (cislo != -333){
        if (cislo % 2 == 1){
            soucet += cislo;
            pocet++;
        }
        cout << "Zadej cislo: " << endl;
        cin >> cislo;
    }
    prumer = soucet/pocet;
    cout << prumer << endl;
}

//Na vstupu je řada celých čísel ukončené číslem -333 (toto číslo do řady nepatří). Určete počet sudých čísel4
void radaCisel3(){
    int cislo;
    cin >> cislo;
    int pocet = 0;
    while (cislo != -333){
        if (cislo % 2 == 0){
            pocet++;
        }
        cout << "Zadej cislo: " << endl;
        cin >> cislo;
    }
    cout << pocet << endl;
}

//Na vstupu je řada znaků. Určete kolik procent znaků tvoří jiné znaky než malá a velká písmena anglické abecedy. Řada je ukončena znakem ‘*‘.
void radaZnaku1(){
    char z;
    cin>>z;
    int pocj,poc=0;
    int celkem = 0;
    float vysledek;


    while(z!='*'){
        if((z>='a' and z<='z') or (z>='A' and z<='Z')){poc++;}else{pocj++;}
        cin>>z;
    }

    celkem = poc+pocj;
    vysledek = (100*pocj)/celkem;
    cout<<vysledek;
};

//Na vstupu je řada znaků. Určete kolik se v ní nachází malých písmen anglické abecedy před první tečkou.
void radaZnaku2(){
    char z;
    cin>>z;
    int poc=0;

    while(z!='.'){
        if((z>='a' and z<='z')){poc++;}
        cin>>z;
    }
    cout<<poc;
};

//Na vstupu je řada znaků ukončená znakem ‘!‘. Určete počet přirozených čísel, které se v řadě nachází.
void radaZnaku3(){
    char z;
    cin>>z;
    int poc=0;

    while(z!='!'){
        if((z>='1' and z<='9')){poc++;}
        cin>>z;
    }
    cout<<poc;
};

//Na vstupu je řada znaků ukončená znakem ‘!‘. Nalezněte v ní největší číslo (uvažujte jen celá čísla).
void radaZnaku4(){

};


//Na vstupu je řada celých čísel ukončená číslem -333 (toto číslo do řady již nepatří).
// Určete, kolik čísel bylo menších něž poslední číslo z řady.
void radaCisel4(){
    int pole[50];
    int c; //cislo
    cin>>c;
    int poc = 0; //pocet mensich hodnot
    int i=0; //pocitadlo
    int pos; //posledni hodnota
    int pocet=0; //pocet hodnot v poli

    //Vynulovani pole - aby tam nebyly random hodnoty z defaultu
    for(int j=0;j<50;j++){
        pole[j]=0;
    }

    while(c!=-333){
        pos =c;
        pocet++;
        pole[i]=c;
        cin>>c;
        i++;
    }

    //Nacitani hodnot pole
    for(int j=0;j<pocet;j++){
        if(pole[j]<pos){poc++;}
    }

    cout<<poc;
}

//Na vstupu je řada celých čísel ukončená číslem -333 (toto číslo do řady již nepatří). Vypište všechna nadprůměrná čísla z řady.
void radaCisel5(){
    int pole[50];
    int c; //cislo
    cin>>c;
    int i=0; //pocitadlo
    int soucet=0; //posledni hodnota
    int pocet=0; //pocet hodnot v poli
    int prumer;

    //Vynulovani pole - aby tam nebyly random hodnoty z defaultu
    for(int j=0;j<50;j++){
        pole[j]=0;
    }

    while(c!=-333){
        soucet += c;
        pocet++;
        pole[i]=c;
        cin>>c;
        i++;
    }
    prumer = soucet/pocet;
    cout << "prumer: " << prumer << endl;

    //Nacitani hodnot pole
    for(int j=0;j<pocet;j++){
        if(pole[j]>prumer){cout << pole[j] << endl;}
    }
}

//Vytvořte funkci, která spočítá součet všech hodnot v poli předaném jako parametr.
int soucetHodnotPole(int pole[], int pocet){
    int soucet = 0;
    for (int i = 0; i < pocet; i++){
        soucet += pole[i];
    }
    return soucet;

}

//Vytvořte funkci, která spočítá aritmetický průměr všech hodnot v poli předaném jako parametr
int prumerHodnotPole(int pole[], int pocet){
    int soucet = 0;
    for (int i = 0; i < pocet; i++){
        soucet += pole[i];
    }
    return soucet/pocet;
}

//Vytvořte funkci pro výpočet skalárního součinu dvou stejně velkých celočíselných vektorů.
int skalarniSoucin(int pole1[], int pole2[], int pocet){
    int vysledek = 0;
    for (int i = 0; i < pocet; i++){
        vysledek += pole1[i] * pole2[i];
    }
    return vysledek;
}

//Na vstupu jsou dvojice hodnot, řada končí dvojicí 0 0.
// Hodnoty rozdělte do dvou vektorů a spočítejte jejich skalární součin. Dále určete, který z vektorů má větší aritmetický průměr.
void dvaVektory(){
    int c1, c2, p1=0, p2=0, s1=0, s2=0;

}

//rada znaku, procentualni podil malych pismen. nacitani je ukonceno !
void radaZnakuTestuni(){
    char z;
    cin >> z;
    int pocJinych = 0;
    int pocMal = 0;
    int celkem = 0;
    float vysledek;


    while(z != '!'){
        if (z >= 'a' and z <= 'z'){
            pocMal++;
        } else {
            pocJinych++;
        }
        cin >> z;
    }
    celkem = pocJinych+pocMal;
    vysledek = (100*pocMal)/celkem;
    cout << vysledek;
}

//Vytvorte datovy typ pro informace o zakovi, ktery bude obsahovat polozky:
// jmeno, prijmeni, trida, pohlavi, prumerna znamka. Je dan textovy soubor xx
//kde se nachazeji informace o zacich 4. trid. Predpokladejte, ze soubor s takovymi daty je ulozen v aktualnim adresari.
// Z dat v souboru vytvorte pro kazdou tridu (A, B, C) samostatne pole serazene podle prumeru zaku
// (ve tride je maximalne 30 zaku). Takto vytvorene seznamy trid pak vypiste ve vhodne forme na standardni vystup.


// trizeni X razeni
// Trizeni - rozdelovani do skupin
// Razeni - serazovani


typedef struct { //novy datovy typ
    string jmeno;
    string prijmeni;
    string trida;
    char pohlavi;
    float prumer;
}typZak;

typedef typZak typPoleZaku[30];


void vypisZaku(typZak zak){
    cout << zak.jmeno << endl;
    cout << zak.prijmeni << endl;
    cout << zak.trida << endl;
    cout << zak.pohlavi << endl;
    cout << zak.prumer << endl;
}

void pridejZaka(typZak zak, typPoleZaku trida, int &pocetZaku){ //& - pridame k poctu zaku, aby se zmena pocet++ projevila i venku z procedury.
    int pocitadlo = 0;
    while (zak.prumer > trida[pocitadlo].prumer and pocitadlo < pocetZaku){
        pocitadlo++;
    }
    for (int i = pocetZaku; i > pocitadlo; i--){
        trida[i] = trida[i-1];
    }

    trida[pocitadlo] = zak;
    pocetZaku++;
}

//Procedura pro vypis seznamu zaku
void vypisTridu(typPoleZaku trida, int pocetZaku){
    for (int i = 0; i < pocetZaku; i++){
        vypisZaku(trida[i]);
        cout << "------------------------------" << endl;
    }
}

void serazeniDlePrumeru(typPoleZaku trida, typZak zak, int pocetZaku){
    int pocitadlo = 0;
    while (zak.prumer > trida[pocitadlo].prumer and pocitadlo < pocetZaku){
        pocitadlo++;
    }
    for (int i = pocetZaku; i > pocitadlo; i--){
        trida[i] = trida[i-1];
    }

    trida[pocitadlo] = zak;

}

//Vytvořte funkci n-té mocniny reálného čísla pomocí rekurze
int MocninaRekurze(int cislo, int pocet){

    if (pocet == 0){
        return 1;
    } else {
        return cislo * MocninaRekurze(cislo, pocet-1);
    }
}




//Pomocí rekurze vytvořte funkci pro výpočet ciferného součtu celého nezáporného čísla
int cifernySoucetRekurze(int cislo){
    if (cislo < 10){
        return cislo;
    } else {
        return cislo%10 + cif_soucet(cislo/10);
    }

}


/*
 * Vytvořte program, který bude umožní uchovávat seznam studentů, o kterých známe, jméno, příjmení, výsku v m, pohlaví a rok narození.
 * Program bude implementovat následující funkcionalitu:
Přidej studenta (za začátek seznamu, na konec seznamu).
Odeber studenta (ze začátku seznamu, z konce seznamu).
Vypiš studenty v seznamu.
Vypiš počet studentu v seznamu.
Vyhledej studenta podle:
jména,
příjmení,
výšky (vyšší, nižší, roven),
roku narození (mladší, starší, roven).
 */

typedef struct {
    string jmeno;
    string prijmeni;
    float vyska;
    char pohlavi;
    int rok;
} typStudent;

typedef typStudent typPoleStudent[30];

//podprogram pro vypis Studenta
void vypisStudenta (typStudent s){
    cout << "jmeno: " << s.jmeno << endl;
    cout << "prijmeni: " << s.prijmeni << endl;
    cout << "vyska: " << s.vyska << endl;
    cout << "pohlavi: " << s.pohlavi << endl;
    cout << "rok nar.: " << s.rok << endl;
}
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

void pridejStudentaNaKonec(typPoleStudent trida, int &pocetStudentu){
    nactiStudenta(trida[pocetStudentu]);
    pocetStudentu++;
}
void pridejNaZacatek(typPoleStudent trida, int &pocetStudentu){
    //posunuti studentu, aby jsme neprepsali
    for (int i = pocetStudentu; i > 0; i--){
        trida[i] = trida[i-1];
    }
    nactiStudenta(trida[0]);
    pocetStudentu++;
}

void vypisSeznamStudentu(typPoleStudent trida, int pocetStudentu){
    for (int i = 0; i < pocetStudentu; i++){
        vypisStudenta(trida[i]);
        cout << "------------------------------" << endl;
    }
}

void odeberStudentaK(int &pocetStudentu){
    pocetStudentu--;
}

void odeberStudentaZ(typPoleStudent trida, int &pocetStudentu){
    for (int i = 1; i < pocetStudentu; i++){
        trida[i-1]=trida[i];
    }
    pocetStudentu--;
}

void vyhledejPodleJmena(typPoleStudent trida, int pocetStudentu, string jmeno){
    for (int i=0; i < pocetStudentu; i++){
        if (trida[i].jmeno==jmeno){
            vypisStudenta(trida[i]);
        }
    }
}

void vyhledejPodlePrijmeni(typPoleStudent trida, int pocetStudentu, string prijmeni){
    for (int i=0; i < pocetStudentu; i++){
        if (trida[i].prijmeni==prijmeni){
            vypisStudenta(trida[i]);
        }
    }
}

void vyhledejPodleVyskyVyssi(typPoleStudent trida, int pocetStudentu, int vyska){
    for (int i = 0; i < pocetStudentu; i++){
        if (trida[i].vyska > vyska){
            vypisStudenta(trida[i]);
        }
    }
}
void vyhledejPodleVyskyNizsi(typPoleStudent trida, int pocetStudentu, int vyska){
    for (int i = 0; i < pocetStudentu; i++){
        if (trida[i].vyska < vyska){
            vypisStudenta(trida[i]);
        }
    }
}

void vyhledejPodleVyskyRoven(typPoleStudent trida, int pocetStudentu, int vyska){
    for (int i = 0; i < pocetStudentu; i++){
        if (trida[i].vyska == vyska){
            vypisStudenta(trida[i]);
        }
    }
}

void vyhledejPodleRokuNarozeniMladsi(typPoleStudent trida, int pocetStudentu, int rok_narozeni){
    for (int i = 0; i < pocetStudentu; i++){
        if (trida[i].rok > rok_narozeni){
            vypisStudenta(trida[i]);
        }
    }
}

void vyhledejPodleRokuNarozeniStarsi(typPoleStudent trida, int pocetStudentu, int rok_narozeni){
    for (int i = 0; i < pocetStudentu; i++){
        if (trida[i].rok < rok_narozeni){
            vypisStudenta(trida[i]);
        }
    }
}

void vyhledejPodleRokuNarozeniRoven(typPoleStudent trida, int pocetStudentu, int rok_narozeni){
    for (int i = 0; i < pocetStudentu; i++){
        if (trida[i].rok == rok_narozeni){
            vypisStudenta(trida[i]);
        }
    }
}

int menu(){ //menu pro ukol se seznamy studentu
    int co;
    cout<<"1. pridej na zacatek"<<endl;
    cout<<"2. pridej na konec"<<endl;
    cout<<"3. odeber ze zacatku"<<endl;
    cout<<"4. odeber z konce"<<endl;
    cout<<"5. vypis seznam"<<endl;
    cout<<"6. vypis pocet studentu"<<endl;
    cout<<"7. vyhledej podle jmena"<<endl;
    cout<<"8. vyhledej podle prijmeni"<<endl;
    cout<<"9. vyhledej podle vysky - vyssi nez"<<endl;
    cout<<"10. vyhledej podle vysky - nizsi nez"<<endl;
    cout<<"11. vyhledej podle vysky - roven"<<endl;
    cout<<"12. vyhledej podle roku narozeni - mladsi nez rok"<<endl;
    cout<<"13. vyhledej podle roku narozeni - starsi nez rok"<<endl;
    cout<<"14. vyhledej podle roku narozeni - roven roku"<<endl;

    cout<<"0. konec"<<endl;
    cin >>co;
    return co;

}


//Stejny priklad ale dynamickou strukturou



int main() {
    //max1max2();
    //akcie();
    //max1max2_cif_soucet();
    //AvgAndZapCisla();
    //teplota();
    //Obrat();
    //aritmetickyPrumer();
    //fibonaccihoPosloupnost();
    //stejnaCisla();
    //smerodatnaOdchylka();
    //PocetCiferZeSeznamuCisel();

    /*
    typMatice mat1, mat2, vysledek;
    int n;
    cin >> n;
    nactiMatici(mat1, n , n);
    nactiMatici(mat2, n, n);
    vypisMatici(mat1, n, n);
    vypisMatici(mat2, n, n);

    sectiMatice(mat1, mat2, vysledek, n, n);
    vypisMatici(vysledek, n, n);
     */

    //zamestanci();
    //hokejLiga();
    //geometrickaPosloupnost();
    //jePrvocislo();
    //radaCisel1();
    //radaCisel2();
    //radaCisel3();
    //radaZnaku1();
    //radaZnaku2();
    //radaZnaku3();
    //radaCisel4();
    //radaCisel5();



    /*
    int pole[5];
    int pole2[5];
    for (int i=0; i < 5; i++){
        pole[i] = 0;
        pole2[i] = 0;
    }
    for (int i=0; i < 5; i++){
        cin >> pole[i];
    }

    for (int i=0; i < 5; i++){
        cin >> pole2[i];
    }
     */

    //cout << soucetHodnotPole(pole, 5);
    //cout << prumerHodnotPole(pole, 5);
    //cout << skalarniSoucin(pole, pole2, 5);

    //radaZnakuTestuni();
    //jePrvocislo();

    /*
    typPoleZaku tridaA, tridaB, tridaC;
    int pocetA = 0, pocetB = 0, pocetC = 0;
    typZak aktualniZak;
    ifstream soubor("zaci.txt");
    if(soubor.is_open()){

        while(!soubor.eof()){
            soubor >> aktualniZak.jmeno >> aktualniZak.prijmeni >> aktualniZak.trida >> aktualniZak.pohlavi >> aktualniZak.prumer;
            //vypisZaku(aktualniZak);

            //Trizeni zaku do trid
            if (aktualniZak.trida == "4.A"){
                pridejZaka (aktualniZak, tridaA, pocetA);


            } else if (aktualniZak.trida == "4.B"){
                pridejZaka (aktualniZak, tridaB, pocetB);


            } else if (aktualniZak.trida == "4.C"){
                pridejZaka (aktualniZak, tridaC, pocetC);

            }
        }


        cout << "Trida A: " << endl << endl;
        vypisTridu(tridaA, pocetA);
        cout << "Trida B: " << endl << endl;
        vypisTridu(tridaB, pocetB);
        cout << "Trida C: " << endl << endl;
        vypisTridu(tridaC, pocetC);
        soubor.close();
    } else {
        cerr << "Soubor neni citelny" << endl;
        return 2;
    }
    */
    //DU zkus seradit od nejhorsiho zaka


    //cout << MocninaRekurze(3,2);
    //cout << cifernySoucetRekurze(783);




    //Priklad Seznam Studentu
    //typStudent  student;
    typPoleStudent trida;
    int pocet = 0;
    string jmeno = "";
    string prijmeni = "";
    int vyska = 0;
    int rok_narozeni = 0;

    /*
    pridejNaZacatek(trida, pocet);
    pridejNaZacatek(trida, pocet);
    pridejStudentaNaKonec(trida, pocet);
    pridejNaZacatek(trida, pocet);
    odeberStudentaK(pocet);
    vypisSeznamStudentu(trida, pocet);
    cout << "Pocet studentu v seznamu: " << pocet << endl; //pocet studentu v seznamu:
    cout << "Vyhledavani: " << endl << "////////////////" << endl;

    cout << "Podle ktereho jmena chces vyhledat: " << endl;
    cin >> jmeno;
    vyhledejPodleJmena(trida, pocet, jmeno);

    cout << "Podle ktereho jmena chces vyhledat: " << endl;
    cin >> jmeno;
    vyhledejPodleJmena(trida, pocet, jmeno);

    cout << "Podle ktereho prijmeni chces vyhledat: " << endl;
    cin >> prijmeni;
    vyhledejPodlePrijmeni(trida, pocet, prijmeni);

    cout << "Vyhledej studenta podle vysky nizsi nez: " << endl;
    cin >> vyska;
    vyhledejPodleVyskyNizsi(trida, pocet, vyska);

    cout << "Vyhledej studenta podle vysky vyssi nez: " << endl;
    cin >> vyska;
    vyhledejPodleVyskyVyssi(trida, pocet, vyska);

    cout << "Vyhledej studenta podle vysky, ktera je rovna: " << endl;
    cin >> vyska;
    vyhledejPodleVyskyRoven(trida, pocet, vyska);

    cout << "Vyhledej studenta podle roku narozeni - mladsi nez:  " << endl;
    cin >> rok_narozeni;
    vyhledejPodleRokuNarozeniMladsi(trida, pocet, rok_narozeni);

    cout << "Vyhledej studenta podle roku narozeni - roven roku:  " << endl;
    cin >> rok_narozeni;
    vyhledejPodleRokuNarozeniRoven(trida, pocet, rok_narozeni);

    cout << "Vyhledej studenta podle roku narozeni - starsi nez:  " << endl;
    cin >> rok_narozeni;
    vyhledejPodleRokuNarozeniStarsi(trida, pocet, rok_narozeni);
    */

    int ukol=menu();
    while(ukol!=0){
        if (ukol == 1) {
            pridejNaZacatek(trida, pocet);
        } else if (ukol == 2){
            pridejStudentaNaKonec(trida, pocet);
        } else if (ukol == 3){
            odeberStudentaZ(trida, pocet);
        } else if (ukol == 4){
            odeberStudentaK(pocet);
        } else if (ukol == 5){
            vypisSeznamStudentu(trida, pocet);
        } else if (ukol == 6){
            cout << "Pocet studentu v seznamu: " << pocet << endl; //pocet studentu v seznamu:
        } else if (ukol == 7){
            cout << "Podle ktereho jmena chces vyhledat: " << endl;
            cin >> jmeno;
            vyhledejPodleJmena(trida, pocet, jmeno);
        } else if (ukol == 8){
            cout << "Podle ktereho prijmeni chces vyhledat: " << endl;
            cin >> prijmeni;
            vyhledejPodlePrijmeni(trida, pocet, prijmeni);
        } else if (ukol == 9){
            cout << "Vyhledej studenta podle vysky vyssi nez: " << endl;
            cin >> vyska;
            vyhledejPodleVyskyVyssi(trida, pocet, vyska);
        } else if (ukol == 10){
            cout << "Vyhledej studenta podle vysky nizsi nez: " << endl;
            cin >> vyska;
            vyhledejPodleVyskyNizsi(trida, pocet, vyska);
        } else if (ukol == 11){
            cout << "Vyhledej studenta podle vysky, ktera je rovna: " << endl;
            cin >> vyska;
            vyhledejPodleVyskyRoven(trida, pocet, vyska);
        } else if (ukol == 12){
            cout << "Vyhledej studenta podle roku narozeni - mladsi nez:  " << endl;
            cin >> rok_narozeni;
            vyhledejPodleRokuNarozeniMladsi(trida, pocet, rok_narozeni);
        } else if (ukol == 13){
            cout << "Vyhledej studenta podle roku narozeni - starsi nez:  " << endl;
            cin >> rok_narozeni;
            vyhledejPodleRokuNarozeniStarsi(trida, pocet, rok_narozeni);
        } else if (ukol == 14){
            cout << "Vyhledej studenta podle roku narozeni - roven roku:  " << endl;
            cin >> rok_narozeni;
            vyhledejPodleRokuNarozeniRoven(trida, pocet, rok_narozeni);
        } else {
            cout << "Nezadal si hodnotu z menu: " << endl;
        }
        ukol=menu();
    }




    //nactiStudenta(student);
    //vypisStudenta(student);

    return 0;
}
