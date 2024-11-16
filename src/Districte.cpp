#include "Districte.h"
#include "Persona.h"

//Función para añadir una persona a la lista de personas de la sección correspondiente
void Districte::afegirDistricte(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio){
    //pre: datos de padrón válidos
    Persona p(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
    habitantsSeccio[seccio].push_back(p); //si no existe la sección, se añadira una nueva lista de habitantes
}

//Función para comprobar si una sección existe en el distrito o no
bool Districte::existeixSeccio(int seccio){
    return habitantsSeccio.find(seccio) != habitantsSeccio.end();
}

//Función para obtener el número de habitantes del distrito
long Districte::obtenirNumHabitants() const{
    long nHabitants = 0;
    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        nHabitants += itSeccio->second.size();
        ++itSeccio;
    }
    return nHabitants;
}

//Función para obtener los habitantes de cada sección de un distrito
map<int, long> Districte::obtenirNumHabitantsSeccio() const{
    map<int, long> habitants;
    //recorrer lista de habitantes de cada sección del padron
    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        habitants[itSeccio->first] = itSeccio->second.size();
        ++itSeccio;
    }
    return habitants;
}

//Función para obtener un set que almacena los estudios únicos de los habitantes del distrito
set<string> Districte::resumEstudis() const{
    set<string> estudisDistricte;
    //para cada sección del distrito, recorrer lista de habitantes e insertar estudios en el set
    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        list<Persona>::const_iterator itPersona = itSeccio->second.begin(); //iterador al inicio de la lista de personas del distrito
        while(itPersona!=itSeccio->second.end()){
            //guardar nombre del nivel de estudios en el set
            estudisDistricte.insert(itPersona->obtenirNivellEstudis());
            ++itPersona;
        }
        ++itSeccio;
    }
    return estudisDistricte;
}

//Función para obtener el promedio de nivel de estudios de la población en un distrito
double Districte::resumNivellEstudis() const{
    double totalNivell = 0.0;
    size_t totalPersonas = 0;
    //para cada sección del distrito, recorrer lista de habitantes y calcular promedio de nivel de estudios
    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        list<Persona>::const_iterator itPersona = itSeccio->second.begin();
        //recorrer lista de personas
        while(itPersona!=itSeccio->second.end()){
            totalNivell += itPersona->obtenirCodiNivellEstudis();
            ++itPersona;
        }
        totalPersonas += itSeccio->second.size();
        ++itSeccio;
    }

    return totalPersonas > 0? double(totalNivell)/totalPersonas : 0.0;
}

//Función para obtener el resumen de las nacionalidades de un distrito
map<pair<string, int>, long> Districte::resumNacionalitats() const{
    map<pair<string, int>, long> res;

    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    //para cada sección, obtener las nacionalidades de sus habitantes
    while(itSeccio!=habitantsSeccio.end()){
        list<Persona>::const_iterator itPersona = itSeccio->second.begin(); //iterador al inicio de la lista de personas del distrito
        //recorrer lista de personas
        while(itPersona!=itSeccio->second.end()){
            pair<string, int> nacionalitat = {itPersona->obtenirNacionalitat(), itPersona->obtenirCodiPaisNaixement()}; //obtener nombre y codi nacionalitat
            res[nacionalitat] += 1; //aumentar contador de nacionalidad o añadir nueva
            ++itPersona;
        }
        ++itSeccio;
    }
    return res;
}

//Función para obtener el número de habitantes de una nacionalidad que hay en el distrito
long Districte::obtenirNumHabitantsNacionalitat(int codiNacionalitat) const{
    long nHabitants = 0;
    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        list<Persona>::const_iterator itPersona = itSeccio->second.begin();
        while(itPersona!=itSeccio->second.end()){
            if(itPersona->obtenirCodiPaisNaixement() == codiNacionalitat) nHabitants++;
            ++itPersona;
        }
        ++itSeccio;
    }
    return nHabitants;
}

//Función para obtener la media de edad de los habitantes del distrito
double Districte::obtenirEdatMitjana(int any) const{
    double edatTotal = 0.0;
    size_t totalPersonas = 0;
    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        //recorrer lista de personas
        list<Persona>::const_iterator itPersona = itSeccio->second.begin();
        while(itPersona!=itSeccio->second.end()){
            int edat = any - itPersona->obtenirAnyNaixement();
            edatTotal += edat;
            ++itPersona;
        }
        totalPersonas += itSeccio->second.size();
        ++itSeccio;
    }

    return totalPersonas > 0? double(edatTotal)/totalPersonas : 0.0; //si totalPersonas>0, devuelve el promedio de edad del distrito; si no, devuelve 0.0
}

//Función para obtener la cantidad de jóvenes del distrito
long Districte::obtenirNumJoves(int any) const{
    long nJoves = 0;

    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        //recorrer lista de personas
        list<Persona>::const_iterator itPersona = itSeccio->second.begin();
        while(itPersona!=itSeccio->second.end()){
            //comprobar si es "joven" (20<=edad<=30)
            int edat = any - itPersona->obtenirAnyNaixement();
            if(edat>= 20 && edat <=30) nJoves++;
            ++itPersona;
        }
        ++itSeccio;
    }
    return nJoves;
}

set<string> Districte::estudisEdat(int any, int edat, int codiNacionalitat) const{
    set<string> estudis;
    //recorrer secciones
    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        //recorrer lista de personas
        list<Persona>::const_iterator itPersona = itSeccio->second.begin();
        while(itPersona!=itSeccio->second.end()){
            int edatPersona = any - itPersona->obtenirAnyNaixement();
            int codiNacio = itPersona->obtenirCodiPaisNaixement();
            if(edatPersona==edat && codiNacio==codiNacionalitat){
                 estudis.insert(itPersona->obtenirNivellEstudis()); //añadir estudios al set la persona cumple los requisitos
            }
            ++itPersona;
        }
        ++itSeccio;
    }
    return estudis;
}
