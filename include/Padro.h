#ifndef PADRO_H
#define PADRO_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Any.h"
#include "Districte.h"
#include "eines.h"
#include "Resums.h"

using namespace std;

class Padro {
public:
    Padro();
    //Constructor vacío

    int llegirDades(const string &path);
    //Pre: path es el archivo que quiere cargar el usuario a las estructuras de datos
    //Post: devuelve el número total de datos leídos

    bool existeixAny(int any) const;
    //Pre: any es el año que quiere buscar el usuario
    //Post: devuelve true si existe en padroAnys, false si no

    map<int, long> obtenirNumHabitantsPerAny() const;
    //Pre: --
    //Post: devuelve un map con el total de habitantes de cada año

    vector<long> obtenirNumHabitantsPerDistricte(int any) const;
    //Pre: any es un año válido dentro de padroAnys
    //Post: devuelve un vector con los habitantes de cada distrito

    map<int, long> obtenirNumHabitantsPerSeccio(int any, int districte) const;
    //Pre: any y districte son el año y distrito son un año y distrito válidos de padroAnys
    //Post: devuelve un map con los habitantes por cada sección del distrito en el año introducido

    ResumEstudis resumEstudis() const;
    //Pre:
    //Post: Devuelve un ResumEstudis que contiene los estudios de los habitantes de cada año en padroAnys

    map<int,int> nombreEstudisDistricte(int districte) const;
    //Pre: districte > 0 y districte <= 6
    //Post: devuelve un map con el año y el número de estudios del distrito en ese año


    ResumNivellEstudis resumNivellEstudis() const;
    //Pre: --
    //Post: devuelve un map con un pair de distrito y promedio del distrito por cada año

    ResumNacionalitats resumNacionalitats() const;
    //Pre: --
    //Post: devuelve un map con un set de pairs de nombre de la nacionalidad y número de habitantes de esa nacionalidad, ordenados descendientemente


    map<int,string> movimentsComunitat(int codiNacionalitat) const;
    //Pre: codiNacionalitat es un código de nacionalides del padrón
    //Post: devuelve un map con el año y el nombre del distrito con más habitantes de esa nacionalidad en ese año


    ResumEdats resumEdat() const;
    //Pre: --
    //Post: devuelve un map con el promedio de edad de cada distrito, para cada año del padrón

    map<int, string> movimentVells() const;
    //Pre: --
    //Post: devuelve un map con el nombre del distrito de mayor edad promedia de cada año

    pair<string,long> mesJoves(int anyInicial, int anyFinal) const;
    //Pre: anyInicial y anyFinal > 0
    //Post: devuelve un pair con el nombre del distrito con mayor incremento de jóvenes entre los dos años, y el incremento


    list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;
    //Pre: any > 0, 0<districte<=6, edat>0, codiNacionalitat>0
    //Post: devuelve una list con los nombres de los estudios de los habitantes que cumplen las condiciones

private:
    map<int, Any> padroAnys;

};

#endif //PADRO_H
