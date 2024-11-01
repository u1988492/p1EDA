#ifndef ANY_H
#define ANY_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include "Districte.h"


using namespace std;

class Padro {
    public:
        Padro();

        int afegir(int any, int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
        //vector<int> obtenirNumHabitantsPerDistricte() const;
        //vector<pair<int, double>> resumEdat() const;
        //vector<string> resumEstudis() const;
        //vector<pair<int, int>> edatNacioPerDistricte(int edat, int codiNacionalitat) const;
        //pair<vector<string>, vector<string>> diferentsNacionalitats(int districte1, int districte2) const;

    private:
        vector<Districte> vecDistrictes;  // Almacena los distritos
};

#endif // ANY_H
