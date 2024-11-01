#include "Districte.h"
#include "Persona.h"

//Funci� para a�adir una persona a la lista de personas de la secci�n correspondiente
void Districte::afegirDistricte(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio){
    //pre: datos de padr�n v�lidos
    Persona p(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
    habitantsSeccio[seccio].push_back(p); //si no existe la secci�n, se a�adira una nueva lista de habitantes
}

//Funci�n para comprobar si una secci�n existe en el distrito o no
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
