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

//Función para comprobar si hay algún dato del padrón que no sea válido
bool validarDades(int any, int districte, int codiNivellEstudis, string nivellEstudis, int anyNaixement, int codiNacionalitat, string nomNacionalitat, int seccio){
    bool dadesValides = true;
    if((any<0) || (districte<0 || districte>6) || (codiNivellEstudis<0) || (codiNacionalitat<0) || (nivellEstudis==" ") || (nomNacionalitat==" ") || (anyNaixement<0 || anyNaixement>any) || (seccio<0)){
        dadesValides = false;
    }
    return dadesValides;
}

//constructor vacío
Padro::Padro(){}

//Función para leer los datos de un archivo CSV introducido por el usuario, y cargarlos a las estructuras de datos
int Padro::llegirDades(const string &path){
    //pre: dirección del archivo "path" introducido por el usuario
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

            //comprobar que los datos sean válidos antes de cargarlos
            if(validarDades(any, districte, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat, seccio)){
                padroAnys[any].afegirAny(districte, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat, seccio); //cargar los datos leídos
                nDades++;
            }
        }
        getline(f, linea); //leer siguiente linea
    }
    f.close();
    return nDades;
}

//Función para buscar si existe o no un año en el mapa del objeto Padro
bool Padro::existeixAny(int any) const{
    return padroAnys.find(any) != padroAnys.end();
}

//Función para obtener el número de habitantes del padrón, por año
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

//Función para obtener el número de habitantes de un año en concreto, por distrito
vector<long> Padro::obtenirNumHabitantsPerDistricte(int any) const{
    vector<long> habitantsAny; //vector para guardar los habitantes de cada distrito
    map<int, Any>::const_iterator itPadro = padroAnys.find(any);
    habitantsAny = itPadro->second.obtenirNumHabitantsPerDistricte();
    return habitantsAny;
}

//Función para obtener el número de habitantes de un año y distrito concretos
map<int, long> Padro::obtenirNumHabitantsPerSeccio(int any, int districte) const{
    //llamar a función para obtener habitantes por sección de un distrito
    map<int, Any>::const_iterator itPadro = padroAnys.find(any); //se da por hecho que el año existe porque se ha validado previamente
    return itPadro->second.obtenirNumHabitantsPerSeccio(districte);
}

//Función para obtener los estudios de la población de cada año del padrón, por su nombre
ResumEstudis Padro::resumEstudis() const{
    ResumEstudis resum;

    //recorrer los años de padrón
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        set<string> resumAny = itPadro->second.resumEstudis(); //resumen de estudios de cada distrito del año
        //recorrer set de resumen año y guardar a resum
        set<string>::const_iterator itResAny = resumAny.begin();
        while(itResAny!=resumAny.end()){
            resum.afegirResumEstudis(itPadro->first, resumAny); //guardar el año y el resumen del año
            ++itResAny;
        }
        ++itPadro;
    }
    return resum;
}

//Función para obtener el número de estudios por año de un distrito
map<int,int> Padro::nombreEstudisDistricte(int districte) const{
    map<int, int> nEstudis;
    //para cada año del padrón, acceder al distrito y obtener el numero de estudios únicos
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        set<string> resDistricte = itPadro->second.resumEstudisDistricte(districte);
        nEstudis[itPadro->first] = resDistricte.size();
        ++itPadro;
    }
    return nEstudis;
}

//Función para obtener los promedios de nivel de estudios de cada distrito en cada año del padrón
ResumNivellEstudis Padro::resumNivellEstudis() const{
    ResumNivellEstudis res;
    //para cada año del padrón, obtener el promedio de estudios de cada distrito
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        vector<double> promigAny = itPadro->second.resumNivellEstudis(); //vector con el promedio de cada distrito ese año
        res.afegirPromig(itPadro->first, promigAny);
        ++itPadro;
    }
    return res;
}

//Función para obtener las nacionalidades de los habitantes de cada año del padrón, con el número de habitantes de esa nacionalidad
ResumNacionalitats Padro::resumNacionalitats() const{
    ResumNacionalitats res;
    //para cada año, obtener el resumen de nacionalidades
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        map<pair<string, int>, long> resAny = itPadro->second.resumNacionalitats();

        res.afegirNacionalitats(itPadro->first, resAny);

        ++itPadro;
    }
    return res;
}

//Función para obtener el nombre del distrito con más habitantes de una nacionalidad en cada año
map<int, string> Padro::movimentsComunitat(int codiNacionalitat) const{
    map<int, string> moviments;
    //para cada año, obtener distrito con mayor concentración de habitantes de esa nacionalidad
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        int districte = itPadro->second.maxNacionalitat(codiNacionalitat); //guardar el distrito con mayor concentración
        if(districte==-1) moviments[itPadro->first] = "No té habitants"; //si no se ha encontrado el distrito con el maximo
        else moviments[itPadro->first] = nomsDistrictes[districte]; //asignar valor de nomsDistrictes correspondiente
        ++itPadro;
    }
    return moviments;
}

ResumEdats Padro::resumEdat() const{
    ResumEdats res;
    //para cada año, obtener promedio de edad de sus distritos
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        vector<double> resAny = itPadro->second.resumEdat(itPadro->first); //obtener resumen de edades del año
        res.afegirEdats(itPadro->first, resAny); //guardar el resumen de edades del año
        ++itPadro;
    }
    return res;
}

//Función para obtener el distrito con mayor media de edad de cada año
map<int, string> Padro::movimentVells() const{
    map<int, string> moviments;
    //para cada año, obtener distrito con mayor media de edad
    map<int, Any>::const_iterator itPadro = padroAnys.begin();
    while(itPadro!=padroAnys.end()){
        int mesVell = itPadro->second.maxEdat(itPadro->first); //resumen de edades de los distritos, de menor a mayor media


        if(mesVell==-1) cout << "No hay distrito" <<endl;
        else moviments[itPadro->first] = nomsDistrictes[mesVell]; //guardar nombre del distrito y año
        ++itPadro;
    }
    return moviments;
}

//Función para obtener el distrito con mayor incremento de jóvenes
pair<string, long> Padro::mesJoves(int anyInicial, int anyFinal) const{
    pair<string, long> joves;

    vector<long> totalJoves(7);

    map<int, Any>::const_iterator itPadro = padroAnys.lower_bound(anyInicial); //iterador de padro en el año inicial o el más cercano
    map<int, Any>::const_iterator itPadroFinal = padroAnys.upper_bound(anyFinal);
    while(itPadro!=itPadroFinal){
        //para cada año a partir del año inicial, obtener incremento de población de los distritos
        vector<long> incrementAny = itPadro->second.incrementJoves(itPadro->first); //recuento de jóvenes del año

        for(size_t i = 1; i<incrementAny.size(); i++){
            totalJoves[i-1] += incrementAny[i]; //sumar incremento de jóvenes
        }
        ++itPadro;
    }

    //obtener posición maxima
    auto maxDistricte = max_element(totalJoves.begin(), totalJoves.end()); //iterador a max
    int indexMax = static_cast<int>(distance(totalJoves.begin(), maxDistricte));

    joves = {nomsDistrictes[indexMax+1], *maxDistricte};
    return joves;
}

//Función para obtener la lista de estudios de los habitantes que cumplen las condiciones introducidas
list<string> Padro::estudisEdat(int any, int districte, int edat, int CodiNacionalitat) const{
    auto itAny = padroAnys.find(any);

    if(itAny!=padroAnys.end()){
        return itAny->second.estudisEdat(any, districte, edat, CodiNacionalitat);
    }
    else{
        return {}; //devolver vacío si no existe el año
    }
}
