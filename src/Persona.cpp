#include "Persona.h"
#include "Estudi.h"
#include "Nacionalitat.h"

//Constructor de Persona a partir de par�metros
Persona::Persona(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiPaisNaixement, const string &paisNaixement)
:a_anyNaixement(anyNaixement), a_estudis(codiNivellEstudis, nivellEstudis), a_nacionalitat(codiPaisNaixement, paisNaixement){}

//Funci�n para obtener fecha de nacimiento de la persona
int Persona::obtenirAnyNaixement() const{
    return a_anyNaixement;
}

//Funci�n para obtener los estudios de la persona
string Persona::obtenirNivellEstudis() const{
    return a_estudis.obtenirNom();
}

//Funci�n para obtener el c�digo del nivel de estudios de la persona
int Persona::obtenirCodiNivellEstudis() const{
    return a_estudis.obtenirId();
}

//Funci�n para obtener el codigo de nacionalidad de la persona
int Persona::obtenirCodiPaisNaixement() const{
    return a_nacionalitat.obtenirId();
}

void Persona::mostraPersona() const{
    int codiEstudis = a_estudis.obtenirId();
    string nivellEstudis = a_estudis.obtenirNom();
    int codiNacionalitat = a_nacionalitat.obtenirId();
    string nacionalitat = a_nacionalitat.obtenirNom();

    cout << a_anyNaixement << " - " << codiEstudis << ", " << nivellEstudis << " - " << codiNacionalitat << ", " << nacionalitat << endl;
}
