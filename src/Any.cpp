#include "Any.h"
#include "Districte.h"

//Constructor con 6 distritos, numero fijo de distritos
Any::Any(){
    vecDistrictes = vector<Districte>(7);
}

//Funci�n para a�adir datos a vector de distritos
void Any::afegirAny(int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio){
    //pre: datos correctos del padr�n
    if(districte<1 ||districte>6){
        cerr << "Error: indice de distrito no valido" << endl;
        return;
    }
    vecDistrictes[districte].afegirDistricte(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat, seccio);
}

//Funci�n para consultar el total de habitantes por distrito en un a�o
vector<long> Any::obtenirNumHabitantsPerDistricte() const{
    vector<long> habitants;
    for(size_t i = 1; i<vecDistrictes.size(); i++){
        habitants.push_back(vecDistrictes[i].obtenirNumHabitants());
    }
    return habitants;
}

//Funci�n para consultar el total de habitantes por secci�n, de un distrito
map<int, long> Any::obtenirNumHabitantsPerSeccio(int districte) const{
    return vecDistrictes[districte].obtenirNumHabitantsSeccio();
}

//Funci�n para obtener el resumen de estudios de la poblaci�n de un a�o
set<string> Any::resumEstudis() const{
    //guardar set de strings con los estudios �nicos del a�o
    set<string> resum;

    for(size_t i=1; i<vecDistrictes.size(); i++){
        set<string> resumDistricte = vecDistrictes[i].resumEstudis(); //resumen estudios del distrito

        //recorrer set del distrito y guardar
        set<string>::const_iterator itResDis = resumDistricte.begin();
        while(itResDis!=resumDistricte.end()){
            resum.insert(*itResDis);
            ++itResDis;
        }
    }

    return resum;
}

//Funci�n para obtener el resumen de estudios para un �nico distrito
set<string> Any::resumEstudisDistricte(int districte)const{

    return vecDistrictes[districte].resumEstudis(); //resumen estudios del distrito;
}

//Funci�n para obtener el promedio de nivel de un a�o
vector<double> Any::resumNivellEstudis() const{
    vector<double> promigDistrictes(vecDistrictes.size()); //vector para guardar el promedio de cada distrito

    for(size_t i=1; i<vecDistrictes.size(); i++){
        double promig = vecDistrictes[i].resumNivellEstudis();
        promigDistrictes[i] = promig;
    }
    return promigDistrictes;
}

//Funci�n para obtener el resumen de nacionalidades de un a�o
map<pair<string, int>, long> Any::resumNacionalitats() const{
    map<string, long> res; //set para guardar resumen
    //para cada distrito, guardar el resumen de nacionalidades
    for(size_t i=1; i<vecDistrictes.size(); i++){
        //obtener mapas de nacionalidades de cada distrito y unirlos en uno �nico
        map<pair<string, int>, long> resumDistricte = vecDistrictes[i].resumNacionalitats();

        map<pair<string, int> long>::const_iterator itResDis = resumDistricte.begin();
        while(itResDis!=resumDistricte.end()){
            res[itResDis->first] += itResDis->second; //si existe la nacionalidad, actualizar contador; si no, a�ade nueva
            itResDis++;
        }
    }
    return res;
}


//void Any::mostraAny(int districte){
//    vecDistrictes[districte].mostraDistr();
//}
