#include "Estudi.h"

//Constructor de Estudis a partir de parámetros
Estudi::Estudi(int id, string nom): codiNivellEstudis(id), nivellEstudis(nom){}

//Función para obtener el codigo del nivel de estudios
int Estudi::obtenirId() const{
    return codiNivellEstudis;
}

//Función para obetener el nombre de los estudios
string Estudi::obtenirNom() const{
    return nivellEstudis;
}

//Función para comparar dos objetos Estudi
bool Estudi::operator==(const Estudi &estudi) const{
    return (codiNivellEstudis == estudi.codiNivellEstudis) and (nivellEstudis == estudi.nivellEstudis);
}
