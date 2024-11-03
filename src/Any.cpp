#include "Any.h"
#include "Districte.h"

//Constructor con 6 distritos, numero fijo de distritos
Any::Any(){
    vecDistrictes = vector<Districte>(7);
}

//Función para añadir datos a vector de distritos
void Any::afegirAny(int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio){
    //pre: datos correctos del padrón
    if(districte<1 ||districte>6){
        cerr << "Error: indice de distrito no valido" << endl;
        return;
    }
    vecDistrictes[districte].afegirDistricte(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat, seccio);
}

//Función para consultar el total de habitantes por distrito en un año
vector<long> Any::obtenirNumHabitantsPerDistricte() const{
    vector<long> habitants;
    for(int i = 1; i<vecDistrictes.size(); i++){
        habitants.push_back(vecDistrictes[i].obtenirNumHabitants());
    }
    return habitants;
}

//Función para consultar el total de habitantes por sección, de un distrito
map<int, long> Any::obtenirNumHabitantsPerSeccio(int districte) const{
    //acceder a distrito del objeto
    //guardar en un map los habitantes de cada seccion del distrito mediante funcion
    return vecDistrictes[districte].obtenirNumHabitantsSeccio();
}


void Any::mostraAny(int districte){
    vecDistrictes[districte].mostraDistr();
}
