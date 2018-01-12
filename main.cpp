#include <iostream>
#include <windows.h>
#include <fstream>


using namespace std;

struct Znajomy { //to jest uzyte pozniej jako nazwa typu danych w main
    int id;
    string imie, nazwisko, adres, telefon, mail;
};
int dodanieZnajomego(Znajomy znajomi[], int iloscZnajomych) { //tutaj oprocz podania nazwy tablicy podajemy nazwe calej struktury, przy samej deklaracji uzywamy tylko nazwy tablicy(bez nawiasow kwadratowych i nazwy struktury)
    string imie, nazwisko, ulica, nrMieszkania, kodPocztowy, miejscowosc, mail, telefon;


    cout << "Podaj imie znajomego: ";
    cin >> imie;
    system("cls");
    cout << "Podaj nazwisko znajomego " << imie <<": ";
    cin >> nazwisko;
    system("cls");

    //sprawdzenie czy taki znajomy jest juz wpisany
    for(int i=0; i<iloscZnajomych; i++) {
        if((znajomi[i].imie==imie) && (znajomi[i].nazwisko==nazwisko)) {

            cout<<"Taki znajomy juz istnieje."<<endl;
            Sleep(2000);
            system("cls");
            return(iloscZnajomych);
        }
    }

    cout << "Podaj numer telefonu znajomego " << imie <<": ";
    cin >> telefon;
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
    cin >> mail;

    string adres = ulica+" "+ nrMieszkania+" "+ kodPocztowy+" "+ miejscowosc;

    int id = iloscZnajomych+1;

    znajomi[iloscZnajomych].id = id;
    znajomi[iloscZnajomych].imie = imie;
    znajomi[iloscZnajomych].nazwisko = nazwisko;
    znajomi[iloscZnajomych].telefon = telefon;
    znajomi[iloscZnajomych].mail = mail;
    znajomi[iloscZnajomych].adres = adres;

    system("cls");

    cout << "Znajomy dodany";
    Sleep(2000);
    system("cls");

    iloscZnajomych++;

//dodawanie do pliku
    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);

    plik<<id<<endl;
    plik<<imie<<endl;
    plik<<nazwisko<<endl;
    plik<<adres<<endl;
    plik<<telefon<<endl;
    plik<<mail<<endl;

    plik.close();

    return iloscZnajomych;
}

int wyszukiwanieZnajomego(Znajomy znajomi[], int iloscZnajomych) { //tutaj oprocz podania nazwy tablicy podajemy nazwe calej struktury, przy samej deklaracji uzywamy tylko nazwy tablicy(bez nawiasow kwadratowych i nazwy struktury)
    string imie, nazwisko;
    int iloscSprawdzonychKontaktow=0;
    if(iloscZnajomych>0) {
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
            for (int i=0; i<iloscZnajomych; i++) //petla, ktora mowi do kiedy program sprawdza czy taki znajomy istnieje

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
            for (int i=0; i<iloscZnajomych; i++) //petla, ktora mowi do kiedy program sprawdza czy taki znajomy istnieje

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
    return iloscZnajomych;

}
void listaZnajomych (Znajomy znajomi[], int iloscZnajomych) {
    if(iloscZnajomych>0) {
        for(int i=0; i < iloscZnajomych; i++)
            cout<<znajomi[i].imie<<endl<<znajomi[i].nazwisko<<endl<<znajomi[i].adres<<endl<<znajomi[i].telefon<<endl<<znajomi[i].mail<<endl<<endl;

        system("pause");
        system("cls");
    } else {
        cout<<"nie masz znajomych";

        Sleep(2000);
    }
    system("cls");
}
int daneZPliku(Znajomy znajomi[], int iloscZnajomych) {
    int nrLinii=1;
    iloscZnajomych=0;
    string linia;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::in);

    while(getline(plik,linia)) {
        switch(nrLinii) {
        case 1:
            znajomi[iloscZnajomych].id = atoi(linia.c_str());
            break;
        case 2:
            znajomi[iloscZnajomych].imie = linia;
            break;
        case 3:
            znajomi[iloscZnajomych].nazwisko = linia;
            break;
        case 4:
            znajomi[iloscZnajomych].adres = linia;
            break;
        case 5:
            znajomi[iloscZnajomych].telefon = linia;
            break;
        case 6:
            znajomi[iloscZnajomych].mail = linia;
            break;
        }
        nrLinii++;
        if (nrLinii==7) {
            iloscZnajomych++;
            nrLinii=1;
        }

    }
    plik.close();
    return(iloscZnajomych);
}


int main() {
    cout << "Witaj w Twojej ksiazce adresowej!" << endl;
    Znajomy znajomi[1000];

    char wybor;

    int iloscZnajomych = daneZPliku(znajomi, iloscZnajomych);

    while(1) {

        cout << "Ilosc wpisanych znajomych: "<< iloscZnajomych << endl<<endl;
        cout << "Wybierz co chcesz teraz zrobic:" << endl;
        cout << "1. Dodaj znajomego" << endl;
        cout << "2. Znajdz znajomego" << endl;
        cout << "3. Wyswietl liste wszystkich znajomych" << endl;
        cout << "9. Zakoncz program" << endl;
        cin >> wybor;
        system("cls");
        switch (wybor) {

        case '1': {
            iloscZnajomych = dodanieZnajomego(znajomi, iloscZnajomych);
        }
        break;
        case '2': {
            wyszukiwanieZnajomego(znajomi, iloscZnajomych);
        }
        break;
        case '3': {
            listaZnajomych(znajomi, iloscZnajomych);
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
