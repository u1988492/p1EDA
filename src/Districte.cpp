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
        itSeccio++;
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
        itSeccio++;
    }
    return habitants;
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
