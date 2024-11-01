#ifndef PERSONA_H
#define PERSONA_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include "Estudi.h"
#include "Nacionalitat.h"

using namespace std;

class Persona
{
    public:
        Persona(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiPaisNaixement, const string &paisNaixement);
        int obtenirAnyNaixement() const;
        string obtenirNivellEstudis() const;
        int obtenirCodiPaisNaixement() const;

    private:
        int anyNaixement;
        Estudi estudis;
        Nacionalitat nacionalitat;

};

#endif // PERSONA_H
