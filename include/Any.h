#ifndef ANY_H
#define ANY_H

#include <vector>
#include <map>
#include <list>
#include <string>
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


        vector<double> resumEdat(int any) const;
        //Pre: --
        //Post: devuelve un vector con los promedios de edad de los distritos de ese año

        set<string> resumEstudis() const;
        //Pre: --
        //Post: devuelve un vector de strings con los estudios únicos de los habitantes en ese año del padrón

        set<string> resumEstudisDistricte(int districte) const;
        //Pre: districte > 0 && districte <=6
        //Post: devuelve un set con los niveles de estudios únicos del distrito introducido

        vector<double> resumNivellEstudis() const;
        //Pre: --
        //Post: devuelve un vector con los promedios de nivel de estudios de cada distrito de un año

        map<pair<string, int>, long> resumNacionalitats() const;
        //Pre: --
        //Post: devuelve un set con las nacionalidades de los distritos de un año

        int maxNacionalitat(int codiNacionalitat) const;
        //Pre: codiNacionalitat es un código de nacionalidad del padrón
        //Post: devuelve un int con el número del distrito con mayor concentración de habitantes de esa nacionalidad

        int maxEdat(int any) const;
        //Pre: --
        //Post: devuelve el índice del distrito con mayor media de edad de ese año

        vector<long> incrementJoves(int any) const;

        list<string> estudisEdat(int any, int districte, int edat, int CodiNacionalitat) const;

    private:
        vector<Districte> vecDistrictes;  //Almacena los distritos
};

#endif // ANY_H
