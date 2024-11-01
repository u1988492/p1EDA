#include "Districte.h"
#include "Persona.h"

//Funció para añadir una persona a la lista de personas de la sección correspondiente
void Districte::afegirDistricte(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio){
    //pre: datos de padrón válidos
    Persona p(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
    habitantsSeccio[seccio].push_back(p); //si no existe la sección, se añadira una nueva lista de habitantes
}

//Función para comprobar si una sección existe en el distrito o no
bool Districte::existeixSeccio(int seccio){
    return habitantsSeccio.find(seccio) != habitantsSeccio.end();
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
