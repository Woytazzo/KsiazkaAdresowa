#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Znajomy //to jest uzyte pozniej jako nazwa typu danych w main
{
    int id;
    string imie, nazwisko, ulica, nrMieszkania, kodPocztowy, miejscowosc, telefon, mail;
    string nazwa=imie+nazwisko;
    string wszystko = imie+" "+ nazwisko+" "+ ulica+" "+ nrMieszkania+" "+ kodPocztowy+" "+ miejscowosc+" "+ telefon+" "+ mail;
};
int dodanieZnajomego(Znajomy znajomi[], int iloscZnajomych) //tutaj oprocz podania nazwy tablicy podajemy nazwe calej struktury, przy samej deklaracji uzywamy tylko nazwy tablicy(bez nawiasow kwadratowych i nazwy struktury)
{
string imie, nazwisko, ulica, nrMieszkania, kodPocztowy, miejscowosc,  mail, telefon;
string nazwa=imie+nazwisko;
string wszystko = imie+" "+ nazwisko+" "+ ulica+" "+ nrMieszkania+" "+ kodPocztowy+" "+ miejscowosc+" "+ telefon+" "+ mail;//do pozniejszego wyswietlenia wszystkiego w wierszu

    cout << "Podaj imie znajomego: ";
    cin >> imie;
    system("cls");
    cout << "Podaj nazwisko znajomego " << imie <<": ";
    cin >> nazwisko;
    system("cls");
int i=0;
while (i< iloscZnajomych)
{
    if(znajomi[i].nazwa == nazwa)  //sprawdzenie czy taki znajomy jest juz zapisany
    {
        cout << "Ten znajomy jest juz wpisany";
        Sleep(2000);
        system("cls");
        return(0);
    }
    else
    {
        i++;
    }
}
    cout << "Podaj ulice, przy ktorej mieszka " << imie <<": ";
    cin >> ulica;
    system("cls");
    cout << "Podaj numer domu, w ktorym mieszka " << imie <<"(nr domu/nr mieszkania): ";
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
    znajomi[iloscZnajomych].nazwa = nazwa;
    znajomi[iloscZnajomych].wszystko = wszystko;
    znajomi[iloscZnajomych].id = iloscZnajomych+1;

    system("cls");

    cout << "Znajomy dodany";
        Sleep(2000);
        system("cls");

   return iloscZnajomych+1;
    }


int wyszukiwanieZnajomego(Znajomy znajomi[], int iloscZnajomych) //tutaj oprocz podania nazwy tablicy podajemy nazwe calej struktury, przy samej deklaracji uzywamy tylko nazwy tablicy(bez nawiasow kwadratowych i nazwy struktury)
{
  string imie, nazwisko;
  string nazwa = imie+nazwisko;
  cout<<"podaj imie znajomego"<<endl;
  cin>>imie;
  cout<<"podaj nazwisko znajomego o imieniu "<< imie <<endl;
  cin>>nazwisko;
  int i=0;
  while (i<iloscZnajomych) //petla, ktora mowi do kiedy program sprawdza czy taki znajomy istnieje
  {
      if (znajomi[i].nazwa == nazwa)
      {
          cout<<znajomi[i].wszystko<<endl;
          Sleep(3000);

      }
      else
        cout<<"nie ma takiego znajomego";
      return(0);

  }

}
void listaZnajomych (Znajomy znajomi[], int iloscZnajomych)
  {
   for(int i=0; i < iloscZnajomych; i++)
        cout<<znajomi[i].wszystko<<endl;

  }


int main()
{
    cout << "Witaj w Twojej ksiazce adresowej!" << endl;
    Znajomy znajomi[100];
    int idZnajomego = 0;
    int iloscZnajomych = 0;

    char wybor;

    while(1)
    {


    cout << "Wybierz co chcesz teraz zrobic:" << endl;
    cout << "1. Dodaj znajomego" << endl;
    cout << "2. Znajdz znajomego" << endl;
    cout << "3. Wyswietl liste wszystkich znajomych" << endl;
    cout << "9. Zakoncz program" << endl;
    cin >> wybor;
system("cls");
switch (wybor)
{

            case '1':
                {
    iloscZnajomych = dodanieZnajomego(znajomi, iloscZnajomych);
                }                               break;
            case '2':
                {
    idZnajomego = wyszukiwanieZnajomego(znajomi, iloscZnajomych);
                }                               break;
            case '3':
                {
    listaZnajomych(znajomi, iloscZnajomych);
                }                               break;
            case '9':
                {
                cout << "Do zobaczenia!";
                Sleep(1000);
                exit(0);
                }                               break;
            default:
                {
                cout << "Blad!! Sprobuj jeszcze raz" <<endl;;

                }                               break;
}        } return (0);}
/*

{
    string imie, nazwisko, ulica, nrMieszkania, kodPocztowy, miejscowosc,  mail, telefon, wszystko, nazwa, linia;
    int id;
    fstream plik;
    plik.open("ksiazka.txt",ios::out | ios::app);
    system("cls");

    cout << "Podaj imie znajomego: ";
    cin >> imie;
    system("cls");
    cout << "Podaj nazwisko znajomego " << imie <<": ";
    cin >> nazwisko;
    system("cls");
    cout << "Podaj ulice, przy ktorej mieszka " << nazwa <<": ";
    cin >> ulica;
    system("cls");
    cout << "Podaj numer domu, w ktorym mieszka " << nazwa <<"(nr domu/nr mieszkania): ";
    cin >> nrMieszkania;
    system("cls");
    cout << "Podaj kod pocztowy dla miejsca, gdzie mieszka " << nazwa <<": ";
    cin >> kodPocztowy;
    system("cls");
    cout << "Podaj miejscowosc, w ktorej mieszka " << nazwa <<": ";
    cin >> miejscowosc;
    system("cls");
    cout << "Podaj e-mail znajomego " << nazwa <<": ";
    cin >> mail;
    system("cls");
for (int i = 0; i < iloscZnajomych; i++ )
        if(znajomi[i].wszystko == wszystko)
    {
        cout << "Ten znajomy jest juz wpisany";
        Sleep(2000);

        return(0);
    }
    while(getline(plik, linia))
    {
        for (int i = 0; i < iloscZnajomych; i++ )
        {
         if(znajomi[i].wszystko == linia)
         {
             cout << "Ten znajomy jest juz wpisany";
        Sleep(2000);

        return(0);
         }
         }
        }
        znajomi[iloscZnajomych].wszystko = wszystko;
        znajomi[iloscZnajomych].id = iloscZnajomych+1;

        cout << "Znajomy dodany";
        Sleep(2000);
        system("cls");

        plik<<id<<" "<<imie<<" "<<nazwisko<<" "<<ulica<<" "<< nrMieszkania<<" "<< kodPocztowy<<" "<< miejscowosc<<" "<< telefon<< " "<< mail<<endl;
        plik.close();

        return iloscZnajomych+1;
    }
/*int wyszukiwanieZnajomego(Znajomy znajomi[], int iloscZnajomych)
{
       string nazwisko;
       string imie;
       string wynik;

        cout << "Podaj nazwisko wyszukiwanej osoby: ";
        cin >> nazwisko;
        cout << "Podaj imie wyszukiwanej osoby: ";
        cin >> imie;
    for (int i = 0; i < iloscZnajomych; i++ )

        if (znajomi[i].nazwisko == nazwisko && znajomi[i].imie == imie)
        {

return iloscZnajomych+1;
        }
}*//*
int wyswietlanieZnajomych()
{
    char wybor;
    fstream plik;
    plik.open("ksiazka.txt",ios::in);

    if(plik.good()==false)
    {
        cout<<"plik nie istnieje!";
    }

    string linia;
    Znajomy znajomi[100];
    int iloscZnajomych = 0;

    while(getline(plik, linia))
    {
                    cout<<linia<<endl;
    }
       plik.close();
        cout << "Wybierz co chcesz teraz zrobic:" << endl;
    cout << "1. Dodaj znajomego" << endl;
    cout << "2. Edytuj/usun znajomego" << endl;
    cout << "9. Zakoncz program" << endl;
    cin>>wybor;

    switch(wybor)
    {
    case 1:
        {
           iloscZnajomych = dodanieZnajomego(znajomi, iloscZnajomych);
        } break;
    case 2:
        {

        } break;
    case 3:
        {

        } break;
    }
       //return(0);
    }



int main()
{
    cout << "Witaj w Twojej ksiazce adresowej!" << endl;
    Znajomy znajomi[100];
    int idZnajomego = 0;
    int iloscZnajomych = 0;
    string znalezionyZnajomy;
    char wybor;

    while(1)
    {
    system("cls");
    for(;;)
        {
    cout << "Wybierz co chcesz teraz zrobic:" << endl;
    cout << "1. Dodaj znajomego" << endl;
    cout << "2. Znajdz znajomego" << endl;
    cout << "3. Wyswietl liste wszystkich znajomych" << endl;
    cout << "9. Zakoncz program" << endl;
    cin >> wybor;
system("cls");
            if (wybor=='1')
                {
                iloscZnajomych = dodanieZnajomego(znajomi, iloscZnajomych);

                }
                else if (wybor=='2')
                {
                //znalezionyZnajomy = wyszukiwanieZnajomego(znajomi, iloscZnajomych);
                }
                else if (wybor=='3')
                {
                 wyswietlanieZnajomych();
                }
                else if (wybor=='9')
                {
                cout << "Do zobaczenia!";
                Sleep(2000);
                exit(0);
                }
                else
                {
                cout << "Blad!! Sprobuj jeszcze raz" <<endl;;

                }
        }
    }

    return 0;
}
  */
