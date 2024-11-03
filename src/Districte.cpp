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
    for(const auto &seccio: habitantsSeccio){
        const auto &listaPersonas = seccio.second;
        nHabitants += listaPersonas.size();
    }
    return nHabitants;
}

//Función para obtener los habitantes de cada sección de un distrito
map<int, long> Districte::obtenirNumHabitantsSeccio() const{
    map<int, long> habitants;
    //recorrer lista de habitantes de cada sección del padron
    for(const auto &seccio: habitantsSeccio){
        int numSeccio = seccio.first;
        long nHabitants = seccio.second.size();
        habitants[numSeccio] = nHabitants; //guardar en map habitants
    }
    return habitants;
}

void Districte::mostraDistr(){
    int count = 0;
    for(const auto &elem: habitantsSeccio){
        int seccio = elem.first;
        const auto &personaList = elem.second;
        for(const Persona &persona: personaList){
            cout << seccio << " - ";
            persona.mostraPersona();
            count++;
            if(count>=20) return;
        }
    }
}
