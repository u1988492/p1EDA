#include "Estudi.h"

//Constructor de Estudis a partir de par�metros
Estudi::Estudi(int id, string nom): codiNivellEstudis(id), nivellEstudis(nom){}

//Funci�n para obtener el codigo del nivel de estudios
int Estudi::obtenirId() const{
    return codiNivellEstudis;
}

//Funci�n para obetener el nombre de los estudios
string Estudi::obtenirNom() const{
    return nivellEstudis;
}

//Funci�n para comparar dos objetos Estudi
bool Estudi::operator==(const Estudi &estudi) const{
    return (codiNivellEstudis == estudi.codiNivellEstudis) and (nivellEstudis == estudi.nivellEstudis);
}
