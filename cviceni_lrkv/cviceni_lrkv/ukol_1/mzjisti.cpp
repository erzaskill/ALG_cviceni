#include <iostream>
#include <fstream>
#include "mtypy.h"

// Při implementaci lze využít již připravenou převodní funkci StrToInt("řetězec znaků"), jejímž parametrem je řetězec znaků (string), který má být převeden na celočíselnou kladnou hodnotu (unsigned int).
// Příklad použití všech níže uvedených funkcí lze vidět v "hlavních řídících programech" – vyhybky.cpp, vozidla_smer.cpp...


string VyhledejIdPrvku(string nazevPrvku){

// Funkce VyhledejIdPrvku(..) má za úkol vyhledat hodnotu id prvku s příslušným názvem nazevPrvku v souboru data.jsn.
// K přípravě funkce využijte soubory s názvem bloky.jsn a jc.jsn – jedná se o vzory souboru data.jsn, v němž budou data ve výsledném programu hledána.
// Příklad použití: VyhledejIdPrvku("Bs 1") vrátí při hledání v souboru bloky.jsn hodnotu id 120.




}

string VyhledejIdLokomotivy(string nazevLokomotivy){

// Funkce VyhledejIdLokomotivy(..) má za úkol vyhledat hodnotu id lokomotivy s příslušným názvem nazevLokomotivy v souboru data.jsn.
// K přípravě funkce využijte soubor s názvem loko.jsn – jedná se o vzor souboru data.jsn, v němž budou data ve výsledném programu hledána.
// Funkce VyhledejIdLokomotivy(..) bude shodná s funkcí VyhledejIdPrvku(..). V případě, že Vámi navržená implementace funkce VyhledejIdPrvku(..) bude funkční i při hledání hodnot v souboru loko.jsn, můžete ji přímo využít k implementaci funkce VyhledejIdLokomotivy(..).

}

void VyhledHodn(UkPolozka H, string HlPol, Polozka &Pol){
   Polozka NulPol={"", typretez, "", 0, 0.0, false, NULL, NULL, NULL};
   UkPolozka Pom=H;
   while (Pom!=NULL and Pom->Nazev!=HlPol) Pom=Pom->Dalsi;
   if (Pom!=NULL) Pol=*Pom;
   else Pol=NulPol;
}