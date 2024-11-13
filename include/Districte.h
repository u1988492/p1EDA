#ifndef DISTRICTE_H
#define DISTRICTE_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Persona.h"

using namespace std;

class Districte
{
    public:
        Districte() {};
        void afegirDistricte(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio);
        bool existeixSeccio(int seccio);
//        void mostraDistr();
        long obtenirNumHabitants() const;
        map<int, long> obtenirNumHabitantsSeccio() const;
        //double obtenirEdatMitjana() const;
        //añadir clase: Resumestudis; CONTENIDOR resumEstudis() const;
        //añadir clase: ResumNacionalitat; CONTENIDOR resumNacionalitats() const;
        //long comptaEdatNacionalitat(int anyNaixement, int codiNacionalitat) const;

    private:
        map<int, list<Persona>> habitantsSeccio;
};

#endif // DISTRICTE_H
