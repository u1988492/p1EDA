#include "Padro.h"
#include "Any.h"

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
                if(!existeixAny(any)){
                    //si no existe el a�o en el mapa de Padro, crear nuevo objeto vac�o de a�o y a�adir a nueva posici�n en padroAnys
                    padroAnys[any] = Any();
                }
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
        itPadro++;
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

//Funci�n para obtener los t�tulos de los estudios de la poblaci�n de cada a�o del padr�n
//ResumEstudis Padro::resumEstudis() const{
//
//}

//void Padro::mostraPadro(int any, int districte){
//    cout << any << " - " << districte << " - ";
//    padroAnys[any].mostraAny(districte);
//}
