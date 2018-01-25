#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Znajomy { //to jest uzyte pozniej jako nazwa typu danych w main
    Znajomy()
    {
     id=0;
    imie="nowy";
    nazwisko="nowy";
    adres="nowy";
    telefon="nowy";
    mail="nowy";
    }
    int id;
    string imie, nazwisko, adres, telefon, mail;
};


Znajomy pobranieZnajomegoZJednejLinii(string liniaZPliku)
{
//string liniaZPliku="1|imie|nazwisko|adres|telefon|mail|";
string roboczy;
int iloscPrzerywnikow=0;
string literaDoDodania;
Znajomy adresatDoDodania;
int id;
string imie, nazwisko, adres, telefon, mail;
//pobiera po kolei literki i dodaje do zmiennej roboczy
for (int i=0; i<liniaZPliku.length(); i++)
{
    if (liniaZPliku[i]!=124)
    {
        literaDoDodania=liniaZPliku[i];
        roboczy.insert(roboczy.length(), literaDoDodania);
    }
    else if (liniaZPliku[i]==124)
        {
        iloscPrzerywnikow++;
//w zaleznosci od liczby przerywnikow przypisujemy roboczy do odpowiedniej zmiennej ze struktury
        switch(iloscPrzerywnikow) {
        case 1:
            adresatDoDodania.id = atoi(roboczy.c_str());
            break;
        case 2:
            adresatDoDodania.imie = roboczy;
            break;
        case 3:
            adresatDoDodania.nazwisko = roboczy;
            break;
        case 4:
            adresatDoDodania.adres = roboczy;
            break;
        case 5:
            adresatDoDodania.telefon = roboczy;
            break;
        case 6:
            adresatDoDodania.mail = roboczy;
            break;
        }
        roboczy="";
        }
}

    return adresatDoDodania;
}

vector <Znajomy> pobranieWszystkichZnajomychZPliku ()
{
Znajomy znajomyRoboczy;
vector <Znajomy> znajomi;
string liniaZPliku;
fstream plik;
plik.open("KsiazkaAdresowa.txt", ios::in);

 if (plik.good() == true)
 {
while(getline(plik,liniaZPliku)) {
    znajomyRoboczy=pobranieZnajomegoZJednejLinii(liniaZPliku);
    znajomi.push_back(znajomyRoboczy);

    }
   plik.close();
}
return znajomi;
}


int dodanieZnajomego(vector <Znajomy> znajomi) { //tutaj oprocz podania nazwy tablicy podajemy nazwe calej struktury, przy samej deklaracji uzywamy tylko nazwy tablicy(bez nawiasow kwadratowych i nazwy struktury)
    string imie, nazwisko, ulica, nrMieszkania, kodPocztowy, miejscowosc, mail, telefon;

    Znajomy nowy;
    cout << "Podaj imie znajomego: ";
    cin >> imie;
    system("cls");
    cout << "Podaj nazwisko znajomego " << imie <<": ";
    cin >> nazwisko;
    system("cls");

    //sprawdzenie czy taki znajomy jest juz wpisany
   for(int i=0; i<znajomi.size(); i++) {
       if((znajomi[i].imie==imie) && (znajomi[i].nazwisko==nazwisko)) {

           cout<<"Taki znajomy juz istnieje."<<endl;
           Sleep(2000);
           system("cls");
           return(znajomi.size());
    }
   }

    cout << "Podaj numer telefonu znajomego " << imie <<": ";
    cin >> nowy.telefon;
    system("cls");
    cout << "Podaj ulice, przy ktorej mieszka " << imie <<": ";
    cin >> ulica;
    system("cls");
    cout << "Podaj numer domu i mieszkania, w ktorym mieszka " << imie <<"(nr domu/nr mieszkania): ";
    cin >> nrMieszkania;
    system("cls");
    cout << "Podaj kod pocztowy dla miejsca, gdzie mieszka " << imie <<": ";
    cin >> kodPocztowy;
    system("cls");
    cout << "Podaj miejscowosc, w ktorej mieszka " << imie <<": ";
    cin >> miejscowosc;
    system("cls");
    cout << "Podaj e-mail znajomego " << imie <<": ";
    cin >> nowy.mail;

    nowy.adres = ulica+" "+ nrMieszkania+" "+ kodPocztowy+" "+ miejscowosc;

    nowy.id = znajomi.size()+1;


    znajomi.push_back(nowy);

    system("cls");

    cout << "Znajomy dodany";
    Sleep(2000);
    system("cls");

//dodawanie do pliku
    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);

    plik<<nowy.id<<"|"<<nowy.imie<<"|"<<nowy.nazwisko<<"|"<<nowy.adres<<"|"<<nowy.telefon<<"|"<<nowy.mail<<endl;

    plik.close();

    return znajomi.size();
}


int wyszukiwanieZnajomego(vector <Znajomy> znajomi) { //tutaj oprocz podania nazwy tablicy podajemy nazwe calej struktury, przy samej deklaracji uzywamy tylko nazwy tablicy(bez nawiasow kwadratowych i nazwy struktury)
    string imie, nazwisko;
    int iloscSprawdzonychKontaktow=0;
    if(znajomi.size()>0) {
        cout << "Jak chcesz wyszukac znajomego? " << endl;
        cout << "1. podajac imie" << endl;
        cout << "2. podajac nazwisko" << endl;
        char szukanieZnajomego;
        cin>>szukanieZnajomego;
        system("cls");
        switch(szukanieZnajomego) {
        case '1': {
            cout<<"Podaj imie wyszukiwanego znajomego"<<endl;
            cin>>imie;

            char pierwszaLitera = imie[0];
            char wielkaLitera=toupper(pierwszaLitera);
            imie[0] = wielkaLitera;

            for (int i=0; i<znajomi.size(); i++) //petla, ktora mowi do kiedy program sprawdza czy taki znajomy istnieje
                if (znajomi[i].imie == imie ) {
                    cout<<endl<<znajomi[i].imie<<endl<<znajomi[i].nazwisko<<endl<<znajomi[i].adres<<endl<<znajomi[i].telefon<<endl<<znajomi[i].mail<<endl<<endl;
                    iloscSprawdzonychKontaktow++;
                }
            cout<<"ilosc wyszukanych osob: "<<iloscSprawdzonychKontaktow<<endl;
        }
        break;
        case '2': {


            cout<<"Podaj nazwisko wyszukiwanego znajomego"<<endl;
            cin>>nazwisko;

            //sprawdzenie, gdy ktos wpisze z malej litery;
            char pierwszaLitera = nazwisko[0];
            char wielkaLitera=toupper(pierwszaLitera);
            nazwisko[0] = wielkaLitera;

            for (int i=0; i<znajomi.size(); i++) //petla, ktora mowi do kiedy program sprawdza czy taki znajomy istnieje

                if (znajomi[i].nazwisko == nazwisko) {
                    cout<<endl<<znajomi[i].imie<<endl<<znajomi[i].nazwisko<<endl<<znajomi[i].adres<<endl<<znajomi[i].telefon<<endl<<znajomi[i].mail<<endl<<endl;
                    iloscSprawdzonychKontaktow++;
                }
            cout<<"ilosc wyszukanych osob: "<<iloscSprawdzonychKontaktow<<endl;
        }
        break;
        default: {
            cout << "Blad!! Sprobuj jeszcze raz" <<endl;;

        }
        break;
        }
    } else
        cout<<"nie masz znajomych"<<endl;
    system("pause");
    system("cls");
    return znajomi.size();

}
void listaZnajomych (vector<Znajomy> znajomi) {
    if(znajomi.size()>0) {
        for(int i=0; i < znajomi.size(); i++)
            cout<<znajomi[i].imie<<endl<<znajomi[i].nazwisko<<endl<<znajomi[i].adres<<endl<<znajomi[i].telefon<<endl<<znajomi[i].mail<<endl<<endl;

        system("pause");
        system("cls");
    } else {
        cout<<"nie masz znajomych";

        Sleep(2000);
    }
    system("cls");
}
//int daneZPliku(vector<Znajomy> znajomi) {
//    int nrLinii=1;
//    string linia;
//    Znajomy nowy;
//    int id;
//    string imie, nazwisko, adres, telefon, mail;
//
//    fstream plik;
//    plik.open("KsiazkaAdresowa.txt", ios::in);
//
////    while(getline(plik,linia)) {
////        switch(nrLinii) {
////        case 1:
////            id = atoi(linia.c_str());
////            break;
////        case 2:
////            imie = linia;
////            break;
////        case 3:
////            nazwisko = linia;
////            break;
////        case 4:
////            adres = linia;
////            break;
////        case 5:
////            telefon = linia;
////            break;
////        case 6:
////            mail = linia;
////            break;
////        }
////        nrLinii++;
////        if (nrLinii==7) {
////
////        nowy = {id, imie, nazwisko, adres, telefon, mail};
////
////
////    znajomi.push_back(nowy);
////
////            iloscZnajomych++;
////            nrLinii=1;
////        }
//    }
//    plik.close();
//    return(iloscZnajomych);
//}

int main() {
    cout << "Witaj w Twojej ksiazce adresowej!" << endl;
    vector <Znajomy> znajomi=pobranieWszystkichZnajomychZPliku ();

    char wybor;

    //daneZPliku(znajomi, iloscZnajomych);

    while(1) {
        znajomi=pobranieWszystkichZnajomychZPliku ();

        cout << "Ilosc wpisanych znajomych: "<< znajomi.size() << endl<<endl;
        cout << "Wybierz co chcesz teraz zrobic:" << endl;
        cout << "1. Dodaj znajomego" << endl;
        cout << "2. Znajdz znajomego" << endl;
        cout << "3. Wyswietl liste wszystkich znajomych" << endl;
        cout << "9. Zakoncz program" << endl;
        cin >> wybor;
        system("cls");
        switch (wybor) {

        case '1': {
            dodanieZnajomego(znajomi);
        }
        break;
        case '2': {
            wyszukiwanieZnajomego(znajomi);
        }
        break;
        case '3': {
            listaZnajomych(znajomi);
        }
        break;
        case '9': {
            cout << "Do zobaczenia!";
            Sleep(1000);
            exit(0);
        }
        break;
        default: {
            cout << "Blad!! Sprobuj jeszcze raz" <<endl;;

        }
        break;
        }
    }


    return (0);
}
