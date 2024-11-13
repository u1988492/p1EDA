#ifndef ANY_H
#define ANY_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Districte.h"


using namespace std;

class Any {
    public:
        Any();
        void afegirAny(int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio);
//        void mostraAny(int districte);
        vector<long> obtenirNumHabitantsPerDistricte() const;
        map<int, long> obtenirNumHabitantsPerSeccio(int districte) const;
        //vector<pair<int, double>> resumEdat() const;
        //vector<string> resumEstudis() const;
        //vector<pair<int, int>> edatNacioPerDistricte(int edat, int codiNacionalitat) const;
        //pair<vector<string>, vector<string>> diferentsNacionalitats(int districte1, int districte2) const;

    private:
        vector<Districte> vecDistrictes;  //Almacena los distritos
};

#endif // ANY_H
