#ifndef NACIONALITAT_H
#define NACIONALITAT_H

#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

class Nacionalitat
{
    public:
        Nacionalitat(int id, string nom);
        int obtenirId() const;
        string obtenirNom() const;
        bool operator==(const Nacionalitat &nacio) const;

    private:
        int codiNacionalitat;
        string codiNacionalitat;

};

#endif // NACIONALITAT_H
