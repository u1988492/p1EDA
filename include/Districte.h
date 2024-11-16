#ifndef DISTRICTE_H
#define DISTRICTE_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <set>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Persona.h"
#include "Resums.h"

using namespace std;

class Districte
{
    public:
        Districte() {};
        void afegirDistricte(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio);
        bool existeixSeccio(int seccio);
        long obtenirNumHabitants() const;
        map<int, long> obtenirNumHabitantsSeccio() const;
        double obtenirEdatMitjana(int any) const;
        set<string> resumEstudis() const; //devuelve un set con los estudios de la población
        double resumNivellEstudis() const;
        map<pair<string, int>, long> resumNacionalitats() const;
        long obtenirNumHabitantsNacionalitat(int codiNacionalitat) const;
        //long comptaEdatNacionalitat(int anyNaixement, int codiNacionalitat) const;

    private:
        map<int, list<Persona>> habitantsSeccio;
};

#endif // DISTRICTE_H
