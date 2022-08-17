//using namespace std;

/*
#include "iostream"
#include "cmath"
#include "iomanip"

//priklad 1
float prumer_cteni(float pole[],int pocet){

    int soucet=0;
    for(int i=0;i<pocet;i++){
        cin>>pole[i];
        soucet+= pole[i];

    }
    return soucet/pocet;

};


//  Předpokládejme, že na vstupu je nezáporné celé číslo N a za ním následuje N desetinných čísel. Vypočtěte směrodatnou odchylku
//zadané řady. Pro výpočet lze použít výraz (v sesite), kde je průměrná hodnota vstupních čísel.

int main() {

    unsigned int N;
    cin>>N;
    float pole[N];
    float prumer = prumer_cteni(pole,N);
    float kvadranty =0;

    for(int i = 0;i<N;i++){
        kvadranty+= (pole[i]-prumer)*(pole[i]-prumer);
    }
    cout<<setw(10)<<setprecision(2)<<sqrt(kvadranty/(N-1))<<endl;
    cout<<"ahoj"<<endl;


    return 0;
}
*/

/*
//priklad 2
//Na standardním vstupu se nachází řada celočíselných hodnot. Vypište ze vstupní řady dvě hodnoty s největším ciferným součtem.
#include "iomanip"
#include "iostream"

int ciferny_soucet(int cislo){
    int soucet = 0;
    cislo = abs(cislo);
    while(cislo > 10){
        soucet += cislo % 10;
        cislo = cislo / 10;
    }
    return soucet+cislo;
}


int main() {
    int max1 = 0, max2, cislo;
    while(cin>>cislo){
        if(ciferny_soucet(cislo) > ciferny_soucet(max1)){
            max2 = max1;
            max1 = cislo;
        } else {
            if (ciferny_soucet(cislo) > ciferny_soucet(max2)){
                max2 = cislo;
            }
        }
    }

    cout << max1 << endl;
    cout << max2 << endl;


    return 0;
}
*/


//priklad3
//Předpokládejte, že se na disku nachází textový soubor, v němž jsou uloženy údaje o zaměstnancích – na každém řádku je dvojice údajů:
// jméno jako jeden řetězec zakončený mezerou a plat jako celočíselná hodnota.
// Čtěte tento soubor a na standardní výstup vypište jména všech zaměstnanců s platem nad 30 tisíc Kč.
//Jméno souboru je zadáno jako parametr programu z příkazového řádku. Pokud parametr chybí nebo soubor nelze otevřít, program nebude dělat nic.
/*
#include "iostream"
#include "fstream"
int main(int argc, char* argv[]) {
    cout << argc << endl;
    cout << argv[0] << endl;
    if (argc > 1){
        ifstream soubor(argv[1]);
        if(soubor.is_open()){
            string jmeno;
            int plat;
            while(!soubor.eof()){
                soubor >> jmeno >> plat;
                if(plat > 30000){
                    cout << jmeno << endl;
                    //cout << plat << endl;
                }
            }
            soubor.close();
        } else {
            cerr << "Soubor nejde otevrit" << endl;
        }
    } else {
        cerr << "Nezadal si parametr souboru" << endl;
    }

    return 0;
}
*/

//priklad4
//Je dána definice uzlu binárního uspořádaného stromu:
//
//struct Uzel {
//   int hodnota;
//   Uzel *levy;
//   Uzel *pravy;
//};
//
//Implementujte podprogram hloubka, který určí hloubku stromu s takto definovanými uzly.
// Samostatný kořen má hloubku 1, strom tvořený pouze kořenem a jeho následníky má hloubku 2 atd.

/*
using namespace std;
#include "iostream"


struct Uzel {
    int hodnota;
    Uzel *levy;
    Uzel *pravy;
};

int hloubka(Uzel* u){
    if(u == NULL){
        return 0;
    } else {
        int pocetL = hloubka(u->levy);
        int pocetP = hloubka(u->pravy);
        if(pocetL > pocetP){
            return 1 + pocetL;
        } else {
            return 1 + pocetP;
        }
    }
}

int main(){
    Uzel *strom = new Uzel;
    cin >> strom->hodnota; //koren

    cout << hloubka(strom);

    return 0;
}
*/

//test
//priklad4
//Je dána definice uzlu binárního uspořádaného stromu:
//
//struct Uzel {
//   int hodnota;
//   Uzel *levy;
//   Uzel *pravy;
//};
//
//Implementujte podprogram hloubka, který určí hloubku stromu s takto definovanými uzly.
// Samostatný kořen má hloubku 1, strom tvořený pouze kořenem a jeho následníky má hloubku 2 atd.

/*
using namespace std;
#include "iostream"


struct Uzel {
    int hodnota;
    Uzel *levy;
    Uzel *pravy;
};

int hloubka(Uzel* u){
    if(u == NULL){
        return 0;
    } else {
        int pocetL = hloubka(u->levy);
        int pocetP = hloubka(u->pravy);
        if(pocetL > pocetP){
            return 1 + pocetL;
        } else {
            return 1 + pocetP;
        }
    }
}

void pridej(Uzel* &strom, Uzel *novy_prvek){
    if(strom==NULL){
        strom=novy_prvek; //koren
    } else {

        if(novy_prvek->hodnota < strom->hodnota){
            pridej(strom->levy, novy_prvek);
        } else {
            pridej(strom->pravy, novy_prvek);
        }
    }
}

void vypis(Uzel* strom){

    if(strom->levy != NULL){
        vypis(strom->levy);
    }

    cout << "hodnota: " << strom->hodnota << endl;

    if(strom->pravy != NULL){
        vypis(strom->pravy);
    }
}

int main(){

    Uzel *strom = new Uzel;

    strom = NULL;


    int novy;
    while(cin >> novy) {
        Uzel *nova_hodnota = new Uzel;
        nova_hodnota->hodnota = novy;
        nova_hodnota->levy = NULL;
        nova_hodnota->pravy = NULL;
        pridej(strom, nova_hodnota);
    }
    vypis(strom);
    cout << "hloubka: " << hloubka(strom)<<endl;
    cout << "Pocet pravych nasledovniku:" << hloubka(strom->pravy)<<endl;

    return 0;
}
*/



//priklad5
//Mame soubor se zviraty -> Rodove jmeno, pocet, skupina.
//Vytvorte datovy typ zvire, obsahuje: druhove jmeno, rodove jmeno, pocet, sekce v Zoo.
//Je dan textovy soubor - zvire.txt. Pro kazdou sekci urcite nejpocetnejsi zvire a uvedte jeho rodove a druhove jmeno.
//vypiste nadprumerny pocet zvirat.
//Vytvorte dynamicky serazeny seznam.
/*
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
int main(){
    int maxA=0, maxB=0, maxC=0;
    string rodoveA, rodoveB, rodoveC;
    string druhoveA, druhoveB, druhoveC;
    //artimeticky prumer
    float soucet = 0;
    int pocet = 0;
    float prumer = 0;
    Zvire* zvire = new Zvire;
    ifstream soubor("zoo.txt");
    if(soubor.is_open()){
        while(soubor>>zvire->rodove_jmeno>>zvire->druhove_jmeno>>zvire->pocet>>zvire->sekce){
            pocet++;
            soucet += zvire->pocet;
            cout << zvire->rodove_jmeno << " " << zvire->druhove_jmeno << endl;
            if(zvire->sekce == 'A'){
                if(zvire->pocet>maxA){
                    maxA = zvire->pocet;
                    rodoveA = zvire->rodove_jmeno;
                    druhoveA = zvire->druhove_jmeno;
                }
            } else if(zvire->sekce == 'B'){
                if(zvire->pocet>maxB){
                    maxB = zvire->pocet;
                    rodoveB = zvire->rodove_jmeno;
                    druhoveB = zvire->druhove_jmeno;
                }
            } else if(zvire->sekce == 'C'){
                if(zvire->pocet>maxC){
                    maxC = zvire->pocet;
                    rodoveC = zvire->rodove_jmeno;
                    druhoveC = zvire->druhove_jmeno;
                }
            }
        }
        prumer = soucet / pocet;
        cout << "prumer: " << prumer << endl;
        cout << "A: " << rodoveA << " " << druhoveA << " " << maxA << endl;
        cout << "B: " << rodoveB << " " << druhoveB << " " << maxB << endl;
        cout << "C: " << rodoveC << " " << druhoveC << " " << maxC << endl;
        soubor.close();
    } else{
        cerr << "Nepodarilo se oteverit soubor.";
    }
    //vypis zvirat: pocet zvirat vetsi nez aritmeticky prumer vsech zvirat
    ifstream soubor2("zoo.txt");
    if(soubor2.is_open()){
        while(soubor2>>zvire->rodove_jmeno>>zvire->druhove_jmeno>>zvire->pocet>>zvire->sekce){
            if(zvire->pocet > prumer){
                cout << zvire->rodove_jmeno << " " << zvire->druhove_jmeno << endl;
            }
        }
        soubor2.close();
    } else {
        cerr << "Nepodarilo se oteverit soubor.";
    }
}
*/

//Dynamicky serazeny seznam.
/*
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
 */




//priklad 6
//rekurentni rady
using namespace std;
#include "iostream"
#include "cmath"



float enax(float x){
    int i = 1;float T=1; float S = 0;
    while(abs(T)>0.00000001){
        S=S+T;
        T=T*x/i;
        i= i+1;
    }


    return S;
}

float enax2(float x, float e){
    int i = 1; float s=1; float sum = x;
    while(abs(s)>e){
        s = s*x/i;
        sum += s;
        i++;
    }
    return sum;
}

float sinus(float x, float e){
    int i = 3; float s=x; float sum = x;
    while(abs(s)>e){

        s=-s*(x*x)/(i*(i-1));
        sum += s;
        i=i+2;

    }
    return sum;
}

float cosinus2(float x, float e){
    int i = 2; float s=1; float sum = 1;
    while(abs(s)>e){
        s = -s*(x*x)/(i*(i-1)); //*(i-n) n= o kolik se posouva jmenovatel
        sum += s;
        i=i+2;
    }
    return sum;
}

float fakt(float cislo){
    if(cislo == 0 or cislo == 1){
        return 1;
    } else {
        return cislo * fakt(cislo-1);
    }
}

int main(){
    cout << cos(0.5)<< endl;
    cout << cosinus2(0.5, 0.00001)<< endl;

    cout << fakt(4)<<endl;


    cout << sin(1)<< endl;
    cout << sinus(1, 0.0000000001)<< endl;

    cout << enax(1)<<endl;
    cout << enax2(1, 0.0000000001)<<endl;
    cout << exp(1) << endl;


    return 0;
}

/*
1.
Na standardním vstupu se nachází neznámý počet řetězců.
 Využitím binárního uspořádaného stromu tyto řetězce seřaďte podle délky a vypište je do textového souboru (diskové jméno souboru zvolte).
 Ve výstupním souboru bude každý řetězec na samostatném řádku.

Na tuto otázku můžete odpovědět libovolně dlouhým textem. Odpověď bude vyhodnocena zkoušejícím ručně.*/
//priklad7

/*
using namespace std;
#include "iostream"
#include "fstream"

struct Uzel {
    string retezec;
    Uzel *levy;
    Uzel *pravy;
};

void init(Uzel* &koren){
    koren->retezec="";
    koren->levy = NULL;
    koren->pravy = NULL;
}


void Pridej(Uzel* &strom, Uzel* &novy){
    if(strom == NULL){
        strom = novy;
    } else {
        if(novy->retezec.length() < strom->retezec.length()){
            Pridej(strom->levy, novy);
        } else {
            Pridej(strom->pravy, novy);
        }
    }
}

void Vypis(Uzel* strom, ofstream &soubor){
    if(strom->levy != NULL){
        Vypis(strom->levy, soubor);
    }

    soubor << strom->retezec << endl;

    if(strom->pravy != NULL){
        Vypis(strom->pravy, soubor);
    }
}

void fib(int pocet){
    int a = 0; int b = 1;
    for (int i = 0; i < pocet; i++) {
        cout << a << endl;
        b= a+b;
        a= b-a;
    }


}

int main(){

    Uzel* strom = new Uzel;
    strom = NULL;
    string novy_retezec;
    while(cin >> novy_retezec){
        Uzel* prvek = new Uzel;
        prvek->levy = NULL;
        prvek->pravy = NULL;
        prvek->retezec =novy_retezec;
        Pridej(strom, prvek);
    }
    ofstream soubor("text.txt");
    if(soubor.is_open()){
        Vypis(strom,soubor);
    }else{
        cerr << "Chyba" << endl;
    }


    //fib(5);
    return 0;


}
*/
/*
 * 2.
Vstupní data jsou tvořena dvojicemi údajů o cenách určité akcie na burze. Je vždy zadáno datum
 a za ním uzavírací cena daného obchodního dne (desetinné číslo). Místo poslední dvojice je pouze jeden řetězec s hodnotou "X".
 Vypište na výstup datum, kdy došlo k největšímu nárůstu ceny akcie proti předchozímu obchodnímu dni. (Pozn.: hodnoceno bude pouze řešení bez použití pole.)

Na tuto otázku můžete odpovědět libovolně dlouhým textem. Odpověď bude vyhodnocena zkoušejícím ručně.
 *
 */
/*
using namespace std;
#include "iostream"

int main(){
    string datum;
    float cena;
    string predchozi_datum;
    float predchozi_cena;
    string datumMax;
    float rozdilMax = 0;

    datumMax = datum;
    cin >> datum;
    if(datum != "X"){
        cin >> cena;
    }
    predchozi_datum = datum;
    predchozi_cena = cena;
    while(datum != "X"){
        if(datum.length()==8){
            if((cena-predchozi_cena) > rozdilMax){
                rozdilMax = cena-predchozi_cena;
                datumMax = datum;
            }
            predchozi_datum=datum;
            predchozi_cena=cena;
            cin >> datum;

            if(datum != "X"){
                cin >> cena;
            }
        } else {
            cout << "Datum musi byt 8znakovy retezec. Tvuj retezec je: " << datum.length() << endl;
            datum = "X";
        }
    }

    cout << datumMax << endl;
    return 0;
}
*/
//4.
//Na standardním vstupu se nacházejí tyto údaje o pracovnících velké organizace: číslo pracovníka (řetězcová hodnota),
// jeho plat (celočíselná hodnota) a číslo jeho pracoviště (hodnota v intervalu 100 až 999).
// Vypište na standardní výstup seznam pracovišť s průměrnými platy jejich zaměstnanců.
// Množství vstupních údajů není známo.
//
//Na tuto otázku můžete odpovědět libovolně dlouhým textem. Odpověď bude vyhodnocena zkoušejícím ručně.
*/
/*
using namespace std;
#include "iostream"

struct pracovnik{
    string id;
    int plat;
    int pracoviste;
};
struct pracoviste{
    int suma;
    int pocet;
};

int main(){
    pracovnik pom;
    pracoviste pole[1000];
    float prumer = 0;
    //vynulovani pole
    for (int i = 0; i <= 1000; i++) {
        pole[i].pocet = 0;
        pole[i].suma = 0;
    }
    while(cin >> pom.id && cin >> pom.plat && cin >> pom.pracoviste){
        pole[pom.pracoviste].pocet++;
        pole[pom.pracoviste].suma += pom.plat;
    }

    //vypis prumeru
    for (int i = 0; i < 1000; i++) {
        if(pole[i].pocet > 0){
            prumer = pole[i].suma/pole[i].pocet;
            cout << "Prumerna mzda na pracovisti " << i << " je: " << prumer << endl;
        }
    }

    return 0;
}
*/








