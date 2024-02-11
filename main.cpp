//Zadanie 1 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string pass[200];

int policzCyfry(){
    int licznik = 0;
    for(int i=0; i<200; i++){
        bool isNum = true;
        for(int j=0; j<pass[i].length(); j++){
            int kod = pass[i][j];
            if(!(kod >=48 && kod<=57)){
                isNum=false;
                break;
            }
        }
        if(isNum){
            licznik++;
        }
    }
    return licznik;
}

void wczytajDane(){
    fstream hasla;
    string bufor;
    int i=0;
    hasla.open("hasla.txt",ios::in);

    if(!hasla.good()){
        cout<<"cos nie dziala";
    }else{
    while(getline(hasla, bufor)){
        pass[i]=bufor;
        i++;
    }
    hasla.close();
    }
}

int main()
{
    wczytajDane();
    cout<<policzCyfry();
    return 0;
}


//Zadanie 2

#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
    fstream plik("hasla.txt");
    if(!plik.good()){
        cout<<"nie działa";
    }
    set<string> hasla;
    set<string> powtorzenie;
    string haslo;
    while (getline(plik, haslo)) {
        if(hasla.find(haslo) != hasla.end()) {
            powtorzenie.insert(haslo);
        }else{
            hasla.insert(haslo);
        }
    }
    plik.close();

    if(powtorzenie.empty()) {
        cout<<"W pliku nie ma żadnych powtórzeń \n";
    }else{
        cout<<"Hasła użyte przez co najmniej dwóch użytkowników: \n";
       for(int i=0; i < powtorzenie.size(); i++) {
        cout<<*next(powtorzenie.begin(), i)<<endl;
        }
    }
    return 0;
}


//Zadanie 3

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool ascii(string haslo){
    string sortHaslo = haslo;
    sort(sortHaslo.begin(),sortHaslo.end());
    for(int i=0;i<sortHaslo.length()-3;i++){
        if(sortHaslo[i]+1==sortHaslo[i+1] &&
            sortHaslo[i]+2==sortHaslo[i+2] &&
            sortHaslo[i]+3==sortHaslo[i+3]){
            return true;
        }
    }
    return false;
}

int main(){
    fstream plik("hasla.txt");
    if(!plik.good()) {
        cout<< "nie dziala";
    }
    set<string> hasla;
    string haslo;
    while(getline(plik, haslo)) {
        if(ascii(haslo)) {
            hasla.insert(haslo);
        }
    }
    plik.close();
    cout<<"Liczba użytkowników posiadających hasła z czterema kolejnymi znakami ascii: "<<hasla.size()<<endl;
    return 0;
}


//Zadanie 4

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool cyfra(string haslo){
    for(char a : haslo){
        if(isdigit(a)){
            return true;
        }
    }
    return false;
}

bool malalitera(string haslo){
    for(char a : haslo) {
        if(islower(a)){
            return true;
        }
    }
    return false;
}

bool duzalitera(string haslo) {
    for(char a : haslo){
        if(isupper(a)){
            return true;
        }
    }
    return false;
}

int main() {
    fstream plik("hasla.txt");
    if(!plik.good()) {
        cout<<"nie dziala";
    }
    int ilosc = 0;
    string haslo;
    while(getline(plik, haslo)) {
        if(cyfra(haslo) && malalitera(haslo) && duzalitera(haslo)) {
            ilosc++;
        }
    }
    plik.close();
    cout<<"Liczba haseł spełniających warunki: "<<ilosc<<endl;
    return 0;
}

