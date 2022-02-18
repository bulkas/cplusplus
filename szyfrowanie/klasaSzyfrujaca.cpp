
#include <iostream>
using namespace std;

// klasa abstrakcyjna (zawiera co najmniej jedną metodę abstrakcyjną -
// czysto wirtualną)
// nie można tworzyć obiektu tej klasy 
class Szyfrowanie {
public:  
    // metoda abstrakcyjna - czysto wirtualna (pure virtual)
    // jest to deklarackja metody, bez definicji
    // definicja powinna być określona w klasie pochodnej
    // (jeśli nie jest - wtedy klasa pochodna też jest abstrakcyjna)
    virtual string szyfruj(string slowo) = 0; 
    virtual string odszyfruj(string slowo) = 0;

    // klasa abstrakcyjna może mieć również zwykłe pola i metody niewirtualne
    // (tu ich nie ma)
};

// klasa dziedzicząca po abstrakcyjnej klasie bazowej
class SzyfrGaderypoluki : public Szyfrowanie {
public:
    // implemetacje metod wirtualnych
    string szyfruj(string slowo);
    string odszyfruj(string slowo);
};

// klasa dziedzicząca po abstrakcyjnej klasie bazowej
class SzyfrCezara : public Szyfrowanie{
private:
    const int iloscPolskichLiter = 35;
    char cezarPolskieLitery[35] = { 'a','ą','b','c','ć','d','e','ę','f','g','h','i','j','k','l','ł','m','n','ń','o','ó','p','q','r','s','ś','t','u','v','w','x','y','z','ż','ź' };
    int cezarKlucz = 1;
public:
    // implemetacje metod wirtualnych
    string szyfruj(string slowo);
    //'a', 'ą', 'b', 'c', 'ć'   'a', 'ą', 'b', 'c', 'ć'
    string odszyfruj(string slowo);
};




int main()
{
    // nie można utworzyć obiektu klasy abstrkcyjnej
    // Szyfrowanie szyfrowanie;

    string doZaszyfrowania = "";
    string zaszyfrowane = "";

    cout << "podaj słowo do zaszyfrowania: \n";
    cin >> doZaszyfrowania;
    cout << "wybierz szyfr:\n"
        "[1] gaderypoluki\n"
        "[2] cezara\n\n";
    int wybor = 0;
    cin >> wybor;

    switch (wybor) {
    case 1: {
        SzyfrGaderypoluki szyfrGaderypoluki;
        zaszyfrowane = szyfrGaderypoluki.szyfruj(doZaszyfrowania);
        cout << "zaszyfrowane: " << zaszyfrowane << endl;
        cout << "test:" << endl;
        cout << "odszyfrowane: " << szyfrGaderypoluki.szyfruj(zaszyfrowane) << endl;
        break;
    }
    case 2: {
        SzyfrCezara szyfrCezara;
        zaszyfrowane = szyfrCezara.szyfruj(doZaszyfrowania);
        cout << "zaszyfrowane: " << zaszyfrowane << endl;
        cout << "test:" << endl;
        cout << "odszyfrowane: " << szyfrCezara.odszyfruj(zaszyfrowane) << endl;
        break;
    }
    default:
        cout << "nieprawidłowy wybór" << endl;
        break;
    }
        
        
}

string SzyfrGaderypoluki::szyfruj(string slowo) {

    // sprawdzamy każdą literę w słowie
    // i podmieniamy zgodnie z szyfrem,
    // gdy litery nie ma w słowie gaderypoluki
    // nie zmieniamy jej
    for (int i = 0; i < slowo.size(); i++)
    {
        switch (slowo[i]) {
        case 'g':
            slowo[i] = 'a';
            break;
        case 'a':
            slowo[i] = 'g';
            break;
        case 'd':
            slowo[i] = 'e';
            break;
        case 'e':
            slowo[i] = 'd';
            break;
        case 'r':
            slowo[i] = 'y';
            break;
        case 'y':
            slowo[i] = 'r';
            break;
        case 'p':
            slowo[i] = 'o';
            break;
        case 'o':
            slowo[i] = 'p';
            break;
        case 'l':
            slowo[i] = 'u';
            break;
        case 'u':
            slowo[i] = 'l';
            break;
        case 'k':
            slowo[i] = 'i';
            break;
        case 'i':
            slowo[i] = 'k';
        }
    }
    return slowo;
}

string SzyfrGaderypoluki::odszyfruj(string slowo) {

    // sprawdzamy każdą literę w słowie
    // i podmieniamy zgodnie z szyfrem
    // gdy litery nie ma w słowie gaderypoluki
    // nie zmieniamy jej
    for (int i = 0; i < slowo.size(); i++)
    {
        switch (slowo[i]) {
        case 'g':
            slowo[i] = 'a';
            break;
        case 'a':
            slowo[i] = 'g';
            break;
        case 'd':
            slowo[i] = 'e';
            break;
        case 'e':
            slowo[i] = 'd';
            break;
        case 'r':
            slowo[i] = 'y';
            break;
        case 'y':
            slowo[i] = 'r';
            break;
        case 'p':
            slowo[i] = 'o';
            break;
        case 'o':
            slowo[i] = 'p';
            break;
        case 'l':
            slowo[i] = 'u';
            break;
        case 'u':
            slowo[i] = 'l';
            break;
        case 'k':
            slowo[i] = 'i';
            break;
        case 'i':
            slowo[i] = 'k';
        }
    }
    return slowo;
}

string SzyfrCezara::szyfruj(string slowo)
{   
    cout << "podaj klucz 1-34" << endl;
    cin >> cezarKlucz;
    // numer litery w tablicy cezarPolskieLitery
    int numerLiteryWTablicy = 0;
    // petla po wszystkich literach w slowie w zaszyfrowania
    for (int i = 0; i < slowo.length(); i++)
    {
        // znajdujemy literę słowa w tablicy polskich liter
        // zapamietujemy jej numer w tablicy
        for (int j = 0; j < iloscPolskichLiter; j++)
        {
            if (slowo[i] == cezarPolskieLitery[j])
                numerLiteryWTablicy = j;
        }

        // znajdujemy pozycję zaszyfrowanej litery w tablicy polskich liter
        numerLiteryWTablicy = (numerLiteryWTablicy + cezarKlucz) % iloscPolskichLiter;

        // wstawiamy do slowa zaszyfrowaną literę
        slowo[i] = cezarPolskieLitery[numerLiteryWTablicy];
    }

    return slowo;
}

string SzyfrCezara::odszyfruj(string slowo)
{
    cout << "podaj klucz 1-34" << endl;
    cin >> cezarKlucz;
    // numer litery w tablicy cezarPolskieLitery
    int numerLiteryWTablicy = 0;
    // petla po wszystkich literach w slowie do odszyfrowania
    for (int i = 0; i < slowo.length(); i++)
    {
        // znajdujemy literę słowa w tablicy polskich liter
        // zapamietujemy jej numer w tablicy
        for (int j = 0; j < iloscPolskichLiter; j++)
        {
            if (slowo[i] == cezarPolskieLitery[j])
                numerLiteryWTablicy = j;
        }
        
        // znajdujemy pozycję odszyfrowanej litery w tablicy polskich liter
        numerLiteryWTablicy = (numerLiteryWTablicy - cezarKlucz) % iloscPolskichLiter;
  
        if (numerLiteryWTablicy < 0) {
            numerLiteryWTablicy += iloscPolskichLiter;
        }

        // wstawiamy do slowa odszyfrowaną literę
        slowo[i] = cezarPolskieLitery[numerLiteryWTablicy];
    }

    return slowo;
}
