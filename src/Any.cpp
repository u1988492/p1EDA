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
    habitants.reserve(vecDistrictes.size());
    for(size_t i = 1; i<vecDistrictes.size(); i++){
        habitants.push_back(vecDistrictes[i].obtenirNumHabitants());
    }
    return habitants;
}

//Función para consultar el total de habitantes por sección, de un distrito
map<int, long> Any::obtenirNumHabitantsPerSeccio(int districte) const{
    return vecDistrictes[districte].obtenirNumHabitantsSeccio();
}

//Función para obtener el resumen de estudios de la población de un año
set<string> Any::resumEstudis() const{
    //guardar set de strings con los estudios únicos del año
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

//Función para obtener el resumen de estudios para un único distrito
set<string> Any::resumEstudisDistricte(int districte)const{

    return vecDistrictes[districte].resumEstudis(); //resumen estudios del distrito;
}

//Función para obtener el promedio de nivel de un año
vector<double> Any::resumNivellEstudis() const{
    vector<double> promigDistrictes(vecDistrictes.size()); //vector para guardar el promedio de cada distrito
    for(size_t i=1; i<vecDistrictes.size(); i++){
        double promig = vecDistrictes[i].resumNivellEstudis();
        promigDistrictes[i] = promig;
    }
    return promigDistrictes;
}

//Función para obtener el resumen de nacionalidades de un año
map<pair<string, int>, long> Any::resumNacionalitats() const{
    map<pair<string, int>, long> res; //map para guardar resumen
    //para cada distrito, guardar el resumen de nacionalidades
    for(size_t i=1; i<vecDistrictes.size(); i++){
        //obtener mapas de nacionalidades de cada distrito y unirlos en uno único
        map<pair<string, int>, long> resumDistricte = vecDistrictes[i].resumNacionalitats();

        map<pair<string, int>, long>::const_iterator itResDis = resumDistricte.begin();
        while(itResDis!=resumDistricte.end()){
            res[itResDis->first] += itResDis->second; //si existe la nacionalidad, actualizar contador; si no, añade nueva
            itResDis++;
        }
    }
    return res;
}

//Función para obtener el índice del distrito con la mayor concentración de habitantes de una nacionalidad
int Any::maxNacionalitat(int codiNacionalitat) const{
    int maxDistricte;
    vector<long>nacionalitatDistricte;
    nacionalitatDistricte.reserve(vecDistrictes.size()-1); //6 posiciones
    //para cada distrito, guardar el número de habitantes de esa nacionalidad
    for(size_t i=1; i<vecDistrictes.size(); i++){
        long numHabitants = vecDistrictes[i].obtenirNumHabitantsNacionalitat(codiNacionalitat);
        nacionalitatDistricte.push_back(numHabitants);
    }

    //obtener posición del distrito con el máximo
    auto itMaxDistricte = max_element(nacionalitatDistricte.begin(), nacionalitatDistricte.end());
    if(itMaxDistricte!=nacionalitatDistricte.end()){
        size_t indexDistricte = distance(nacionalitatDistricte.begin(), itMaxDistricte); //es 0 si el maximo en ese año es 0
        if(indexDistricte==0){
            maxDistricte = -1;
        }

        else maxDistricte = static_cast<int>(indexDistricte)+1; //static cast para poder devolver un int de la posición
    }
    return maxDistricte;
}

//Función para obtener el promedio de edades de cada distrito del año
vector<double> Any::resumEdat(int any) const{
    vector<double> resumDistrictes(vecDistrictes.size()-1);
    //para cada distrito, calcular promedio
    for(size_t i=1; i<vecDistrictes.size(); i++){
        resumDistrictes[i-1] = vecDistrictes[i].obtenirEdatMitjana(any);
    }

    return resumDistrictes;
}

//Función para obtener el distrito con mayor media de edad del año
int Any::maxEdat(int any) const{
    const vector<double> resumEdats = resumEdat(any); //vector de promedios de edad por distrito

    if(resumEdats.empty()){
        return -1;
    }
    auto maxDistricte = max_element(resumEdats.begin(), resumEdats.end()); //iterador al elemento maximo

    int indexMax = static_cast<int>(distance(resumEdats.begin(), maxDistricte));

    return indexMax+1;
}

//Función para obtener el incremento de jóvenes de cada distrito de un año
vector<long> Any::incrementJoves(int any) const{
    vector<long> joves(vecDistrictes.size());

    for(size_t i=1; i<vecDistrictes.size(); i++){
        joves[i] = vecDistrictes[i].obtenirNumJoves(any);
    }
    return joves;
}

//Función para obtener la lista de estudios de los habitantes que cumplan las condiciones introducidas
list<string> Any::estudisEdat(int any, int districte, int edat, int CodiNacionalitat) const{
    if(districte < 0 || districte>=vecDistrictes.size()){
        return {}; //devolver vacío si los datos no son válidos
    }

    set<string> estudisUnics = vecDistrictes[districte].estudisEdat(any, edat, CodiNacionalitat);
    list<string> estudis(estudisUnics.begin(), estudisUnics.end());

    return estudis;
}
