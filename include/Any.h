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
        //Pre: --
        //Post: se ha construido el objeto Any con un vector de 7 posiciones

        void afegirAny(int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio);
        //Pre: parámetros válidos (según la función validarDades en Padro)
        //Post: se ha añadido al objeto Any, en el distrito y sección correspondientes, una nueva persona a la lista de habitantes

//        void mostraAny(int districte);

        vector<long> obtenirNumHabitantsPerDistricte() const;
        //Pre: --
        //Post: se devuelve un vector de longs con el número de habitantes que tiene cada distrito


        map<int, long> obtenirNumHabitantsPerSeccio(int districte) const;
        //Pre: districte > 0 y districte <=6
        //Post: devuelve un map con la sección y el número de habitantes de esa sección, de un distrito introducido


        //vector<pair<int, double>> resumEdat() const;
        //Pre:
        //Post: devuelve un vector con pairs de

        set<string> resumEstudis() const;
        //Pre: --
        //Post: devuelve un vector de strings con los estudios únicos de los habitantes en ese año del padrón

        set<string> resumEstudisDistricte(int districte) const;

        //vector<pair<int, int>> edatNacioPerDistricte(int edat, int codiNacionalitat) const;


        //pair<vector<string>, vector<string>> diferentsNacionalitats(int districte1, int districte2) const;

    private:
        vector<Districte> vecDistrictes;  //Almacena los distritos
};

#endif // ANY_H
