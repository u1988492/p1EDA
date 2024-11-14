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

//    map<int,int> nombreEstudisDistricte(int districte) const;
//    ResumNivellEstudis resumNivellEstudis() const;
//    ResumNacionalitats resumNacionalitats() const;
//    map<int,string> movimentsComunitat(int codiNacionalitat) const;
//    ResumEdats resumEdat() const;
//    map<int, string> movimentVells() const;
//    pair<string,long> mesJoves(int anyInicial, int anyFinal) const;
//    list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;

private:
    map<int, Any> padroAnys;


//public:
//    class ResumEstudis{
//        public:
//            ResumEstudis(){};
//        private:
//            map<int, list<string>> estudisAny;
//    };
//
//    class ResumNacionalitats{
//    };
};

#endif //PADRO_H
