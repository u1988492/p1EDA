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
    double promigDistricte = 0.0;
    double totalDistricte = 0.0;
    //para cada sección del distrito, recorrer lista de habitantes y calcular promedio de nivel de estudios
    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
    while(itSeccio!=habitantsSeccio.end()){
        double promigSeccio = 0.0;
        double totalNivell = 0.0;
        list<Persona>::const_iterator itPersona = itSeccio->second.begin(); //iterador al inicio de la lista de personas del distrito
        while(itPersona!=itSeccio->second.end()){
            totalNivell += itPersona->obtenirCodiNivellEstudis();
            ++itPersona;
        }
        if(!itSeccio->second.empty()){ //evitar divisón por 0
            promigSeccio = totalNivell/itSeccio->second.size(); //promedio de la sección según el número de habitantes
            totalDistricte += promigSeccio;
        }
        ++itSeccio;
    }

    if(!habitantsSeccio.empty()){ //evitar división por 0
        promigDistricte = totalDistricte/habitantsSeccio.size(); //promedio del distrito según el número de secciones
    }

    return promigDistricte;
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



//void Districte::mostraDistr(){
//    int counter = 0;
//    map<int, list<Persona>>::const_iterator itSeccio = habitantsSeccio.begin();
//    while(itSeccio!=habitantsSeccio.end()){
//        list<Persona>const_iterator itPersona = itSeccio->second.begin();
//        while(itPersona!=itSeccio->second.end()){
//            cout << itSeccio->first << " - ";
//            itPersona.mostraPersona();
//            counter++
//            it(counter>=20) return; //limite para que no se me raye esto
//
//        }
//    }
//
//
//    for(const auto &elem: habitantsSeccio){
//        int seccio = elem.first;
//        const auto &personaList = elem.second;
//        for(const Persona &persona: personaList){
//            cout << seccio << " - ";
//            persona.mostraPersona();
//            count++;
//            if(count>=20) return;
//        }
//    }
//}
