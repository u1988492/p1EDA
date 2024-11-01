#include "Nacionalitat.h"

//Constructor de Nacionalitat a partir de par�metros
Nacionalitat::Nacionalitat(int id, string nom): codiNacionalitat(id), nacionalitat(nom){}

//Funci�n para obtener codigo de nacionalidad
int Nacionalitat::obtenirId() const{
    return codiNacionalitat;
}

//Funci�n para obtener nacionalidad
string Nacionalitat::obtenirNom() const{
    return nacionalitat;
}

bool Nacionalitat::operator==(const Nacionalitat &nacio) const{
    return (nacionalitat==nacio.nacionalitat) and (codiNacionalitat==nacio.codiNacionalitat);
}
