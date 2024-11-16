#include "Padro.h"
#include "Any.h"

vector<string> nomsDistrictes{
    "",
    "Carme, Vila-roja",
    "Eixample, Montilivi",
    "Santa Eugenia, Mas Xirgu",
    "Casc Antic",
    "Montjuic, Pont major",
    "Sant Ponc, Domeny, Taiala"
};

int stringToInt(string s) {
    if (s.length()==0) return -1;
        for(char c: s ) {
            if(c<'0' || c>'9') return -1;
        }
    return stoi( s );
}

//Funci�n para comprobar si hay alg�n dato del padr�n que no sea v�lido
bool validarDades(int any, int districte, int codiNivellEstudis, string nivellEstudis, int anyNaixement, int codiNacionalitat, string nomNacionalitat, int seccio){
    bool dadesValides = true;
    if((any<0) || (districte<0 || districte>6) || (codiNivellEstudis<0) || (codiNacionalitat<0) || (nivellEstudis==" ") || (nomNacionalitat==" ") || (anyNaixement<0 || anyNaixement>any) || (seccio<0)){
        dadesValides = false;
    }
    return dadesValides;
}

//constructor vac�o
Padro::Padro(){}

//Funci�n para leer los datos de un archivo CSV introducido por el usuario, y cargarlos a las estructuras de datos
int Padro::llegirDades(const string &path){
    //pre: direcci�n del archivo "path" introducido por el usuario
    ifstream f;
    f.open(path);

    if(!f.is_open()){
        cerr << "No se pudo abrir el archivo " << path << endl;
        return -1;
    }

    //si se pudo abrir el archivo, leer y procesar datos
    string linea;
    vector<string> campos;
    int nDades = 0;
    getline(f, linea); //saltar linea de la cabecera
    getline(f, linea); //leer segunda linea del archivo
    while(!f.eof()){
        campos = tokens(linea, ',', true);
        if(campos.size()>=12){ //solo procesar lineas que tengan al menos los datos necesarios
            //procesar los campos de interes
            int any = stringToInt(campos[0]);
            int districte = stringToInt(campos[1]);
            int seccio = stringToInt(campos[2]);
            int codiNivellEstudis = stringToInt(campos[4]);
            string nivellEstudis = campos[5];
            int anyNaixement = stringToInt(campos[6]);
            int codiNacionalitat = stringToInt(campos[11]);
            string nomNacionalitat = campos[12];

            //comprobar que los datos sean v�lidos antes de cargarlos
            if(validarDades(any, districte, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat, seccio)){
                padroAnys[any].afegirAny(districte, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat, seccio); //cargar los datos le�dos
                nDades++;
            }
        }
        getline(f, linea); //leer siguiente linea
    }
    f.close();
    return nDades;
}

//Funci�n para buscar si existe o no un a�o en el mapa del objeto Padro
bool Padro::existeixAny(int any) const{
    return padroAnys.find(any) != padroAnys.end();
}

//Funci�n para obtener el n�mero de habitantes del padr�n, por a�o
map<int, long> Padro::obtenirNumHabitantsPerAny() const{
    map<int, long> habitants;
    map<int, Any>::const_iterator itPadro = padroAnys.begin();

    while(itPadro!=padroAnys.end()){
        long totalAny = 0;
        vector<long> districtesTotal = itPadro->second.obtenirNumHabitantsPerDistricte();

        for(unsigned i=0; i<districtesTotal.size(); i++){
            totalAny += districtesTotal[i];
        }
        habitants[itPadro->first] = totalAny;
        ++itPadro;
    }
    return habitants;
}

//Funci�n para obtener el n�mero de habitantes de un a�o en concreto, por distrito
vector<long> Padro::obtenirNumHabitantsPerDistricte(int any) const{
    vector<long> habitantsAny; //vector para guardar los habitantes de cada distrito
    map<int, Any>::const_iterator itPadro = padroAnys.find(any);
    habitantsAny = itPadro->second.obtenirNumHabitantsPerDistricte();
    return habitantsAny;
}

//Funci�n para obtener el n�mero de habitantes de un a�o y distrito concretos
map<int, long> Padro::obtenirNumHabitantsPerSeccio(int any, int districte) const{
    //llamar a funci�n para obtener habitantes por secci�n de un distrito
    map<int, Any>::const_iterator itPadro = padroAnys.find(any); //se da por hecho que el a�o existe porque se ha validado previamente
    return itPadro->second.obtenirNumHabitantsPerSeccio(districte);
}

//Funci�n para obtener los estudios de la poblaci�n de cada a�o del padr�n, por su nombre
ResumEstudis Padro::resumEstudis() const{
    ResumEstudis resum;

    //recorrer los a�os de padr�n
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        set<string> resumAny = itPadro->second.resumEstudis(); //resumen de estudios de cada distrito del a�o
        //recorrer set de resumen a�o y guardar a resum
        set<string>::const_iterator itResAny = resumAny.begin();
        while(itResAny!=resumAny.end()){
            resum.afegirResumEstudis(itPadro->first, resumAny); //guardar el a�o y el resumen del a�o
            ++itResAny;
        }
        ++itPadro;
    }
    return resum;
}

//Funci�n para obtener el n�mero de estudios por a�o de un distrito
map<int,int> Padro::nombreEstudisDistricte(int districte) const{
    map<int, int> nEstudis;
    //para cada a�o del padr�n, acceder al distrito y obtener el numero de estudios �nicos
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        set<string> resDistricte = itPadro->second.resumEstudisDistricte(districte);
        nEstudis[itPadro->first] = resDistricte.size();
        ++itPadro;
    }
    return nEstudis;
}

//Funci�n para obtener los promedios de nivel de estudios de cada distrito en cada a�o del padr�n
ResumNivellEstudis Padro::resumNivellEstudis() const{
    ResumNivellEstudis res;
    //para cada a�o del padr�n, obtener el promedio de estudios de cada distrito
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        vector<double> promigAny = itPadro->second.resumNivellEstudis(); //vector con el promedio de cada distrito ese a�o
        res.afegirPromig(itPadro->first, promigAny);
        ++itPadro;
    }
    return res;
}

//Funci�n para obtener las nacionalidades de los habitantes de cada a�o del padr�n, con el n�mero de habitantes de esa nacionalidad
ResumNacionalitats Padro::resumNacionalitats() const{
    ResumNacionalitats res;
    //para cada a�o, obtener el resumen de nacionalidades
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        map<pair<string, int>, long> resAny = itPadro->second.resumNacionalitats();

        res.afegirNacionalitats(itPadro->first, resAny);

        ++itPadro;
    }
    return res;
}

//Funci�n para obtener el nombre del distrito con m�s habitantes de una nacionalidad en cada a�o
map<int, string> Padro::movimentsComunitat(int codiNacionalitat) const{
    map<int, string> moviments;
    //para cada a�o, obtener distrito con mayor concentraci�n de habitantes de esa nacionalidad
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        int districte = itPadro->second.maxNacionalitat(codiNacionalitat); //guardar el distrito con mayor concentraci�n
        if(districte==-1) moviments[itPadro->first] = "No t� habitants"; //si no se ha encontrado el distrito con el maximo
        else moviments[itPadro->first] = nomsDistrictes[districte]; //asignar valor de nomsDistrictes correspondiente
        ++itPadro;
    }
    return moviments;
}

ResumEdats Padro::resumEdat() const{
    ResumEdats res;
    //para cada a�o, obtener promedio de edad de sus distritos
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        vector<double> resAny = itPadro->second.resumEdat(itPadro->first); //obtener resumen de edades del a�o
        res.afegirEdats(itPadro->first, resAny); //guardar el resumen de edades del a�o
        ++itPadro;
    }
    return res;
}

//void Padro::mostraPadro(int any, int districte){
//    cout << any << " - " << districte << " - ";
//    padroAnys[any].mostraAny(districte);
//}
