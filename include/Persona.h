#ifndef PERSONA_H
#define PERSONA_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Estudi.h"
#include "Nacionalitat.h"

using namespace std;

class Persona
{
    public:
        Persona(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiPaisNaixement, const string &paisNaixement);
        void mostraPersona() const;
        int obtenirAnyNaixement() const;
        string obtenirNivellEstudis() const;
        int obtenirCodiPaisNaixement() const;

    private:
        int a_anyNaixement;
        Estudi a_estudis;
        Nacionalitat a_nacionalitat;

};

#endif // PERSONA_H
