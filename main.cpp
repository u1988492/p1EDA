/**
 * \file main.cpp
 * \brief Programa que gestiona la consulta de datos sobre los habitantes de un padrón de Girona.
 *
 * Este programa lee, consulta y presenta datos sobre la población de un padrón en Girona, como el número de
 * habitantes por año, estudios, edades, movimientos y más.
 *
 * \author Claudia Rebeca Hodoroga (u1988492)
 * \date 2024/2025
 */

#include <vector>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include "Padro.h"
#include "Resums.h"

using namespace std;

//FUNCIONES GENERALES

/**
 * \brief Muestra el título de una sección con un formato especial.
 *
 * Esta función recibe un título y lo muestra rodeado por asteriscos para destacarlo en la consola.
 *
 * \param titol El título que se mostrará.
 */

//Mostrar título de menú
void mostraTitol(const string &titol){
    int ancho = titol.size() + 4;
    cout << string(ancho, '*') << endl;
    cout << "* " << titol << " *" << endl;
    cout << string(ancho, '*') << endl;
}

/**
 * \brief Muestra una línea de caracteres repetidos.
 *
 * Esta función muestra una línea de un carácter específico repetido 15 veces.
 *
 * \param c El carácter que se repetirá.
 */

void lineaChar(char c){
    int ancho = 15;
    cout << string(ancho, c) << endl;
}


//GESTIÓN DE INTERACCIÓN CON EL USUARIO


/**
 * \brief Carga los datos del padrón desde un archivo.
 *
 * Esta función solicita al usuario el nombre del archivo desde el cual se cargarán los datos
 * y luego procesa los datos de dicho archivo.
 *
 * \param p Un objeto de la clase Padro donde se almacenarán los datos cargados.
 */

//01: CARGAR DATOS
void cargarDatos(Padro &p){
    mostraTitol("01. Llegir dades");
    string fitxer;
    cin >> fitxer;
//    string fitxer = "padroCurt.csv";
    int lectura = p.llegirDades(fitxer);
    if(lectura==-1){
        cerr << "No se ha leido el archivo correctamente." << endl;
        return;
    }
    else cout << "Numero de linies: " << lectura << endl;
}

/**
 * \brief Consulta si existe un año en los datos cargados.
 *
 * Esta función permite al usuario consultar si un año determinado existe en los datos cargados.
 *
 * \param p Un objeto de la clase Padro que contiene los datos del padrón.
 */

//02: EXISTE AÑO
void existeixAny(Padro &p){
    mostraTitol("02. Existeix any");
    int any;
    cin >> any;
    cout << "Any: " << any << endl;
    if(!p.existeixAny(any)){
        cout << "Any inexistent" << endl;
    }
    else{
        cout << "Any existent" << endl;
    }
}

/**
 * \brief Obtiene el número de habitantes por año y muestra el promedio.
 *
 * Esta función muestra el número de habitantes por año y calcula el promedio de habitantes.
 *
 * \param p Un objeto de la clase Padro que contiene los datos del padrón.
 */

//03: NÚMERO DE HABITANTES DEL PADRÓN, POR AÑO, Y PROMEDIO
void numHabitants(const Padro &p){
    mostraTitol("03. Obtenir nombre d'habitants");

    map<int, long>habitants = p.obtenirNumHabitantsPerAny();
    double totalPadro = 0.0;

    map<int, long>::const_iterator itHab = habitants.begin();
    while(itHab!=habitants.end()){

        long total = itHab->second;

        cout << setw(3) << itHab->first << setw(6) << "habitants: " <<itHab->second << endl;

        totalPadro += total;
        ++itHab;
    }

    double promig = (habitants.size()>0) ? double(totalPadro)/habitants.size(): 0; //comprobar si habitants>0 antes de operar para evitar errores
    cout << "PROMIG : " << setprecision(2) << promig << endl;
}

/**
 * \brief Obtiene el número de habitantes de un año específico.
 *
 * Esta función permite al usuario consultar el número de habitantes de un año en específico.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//04: NÚMERO DE HABITANTES DE UN AÑO
void numHabitantsAny(Padro &p){
    mostraTitol("04: Obtenir nombre d'habitants d'un any");
    int any;
    cin >> any;

    if(p.existeixAny(any)){

        cout << "Any: " << any << endl;

        vector<long> habitants = p.obtenirNumHabitantsPerDistricte(any); //vector de 0 a 6 con los habitantes de cada distrito
        long total = 0;

        if(!habitants.empty()){
            //mostrar si hay elementos
            for(size_t i=0; i<habitants.size(); i++){
                cout << "Districte: " << i+1 << setw(3) << "habitants: " << setw(7) << habitants[i] << endl;
                total += habitants[i];
            }
        }
        else{
            cout << endl;
        }
        cout << "TOTAL: " << total << endl;
    }
    else{
        cerr << "ERROR: Any inexistent" << endl;
    }
}

/**
 * \brief Obtiene el número de habitantes de un año y un distrito.
 *
 * Esta función permite al usuario consultar el número de habitantes de un año y un distrito específico.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//05: NÚMERO DE HABITANTES DE UN AÑO Y DISTRITO
void numHabitantsAnyDistricte(Padro &p){
    mostraTitol("05: Obtenir nombre d'habitants d'un any i districte");
    int any, districte;
    cin >> any;
    cin >> districte;

    //validar año y distrito
    if(p.existeixAny(any)){
        if(districte>0 && districte<=6){

            cout << "Any: " << any << setw(4) << "Districte: " << districte << endl;

            map<int, long> habitants = p.obtenirNumHabitantsPerSeccio(any, districte);
            long total = 0;

            //recorrer map y mostrar
            map<int, long>::const_iterator itHabitants = habitants.begin();
            while(itHabitants!=habitants.end()){
                cout << "Seccio " << itHabitants->first << setw(3) << " habitants: " << setw(7) << itHabitants->second << endl;
                total += itHabitants->second;
                ++itHabitants;
            }
            cout << "TOTAL : " << total << endl;
        }
       else cerr << "ERROR: Districte " << districte  << " invalid" << endl;
    }
    else cerr << "ERROR: Any " << any << " inexistent" << endl;
}

/**
 * \brief Muestra un resumen de los estudios de la población por año.
 *
 * Esta función muestra un resumen de los estudios de la población por año.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//06: RESUMEN DE ESTUDIOS DE LA POBLACIÓN POR AÑO
void resumEstudisPoblacio(Padro &p){
    mostraTitol("06. Resum per estudis");
    //guardar el resultado de la funcion de padro
    ResumEstudis res = p.resumEstudis();
    res.mostrarResumEstudis();
}

/**
 * \brief Consulta el número de estudios de un distrito por año.
 *
 * Esta función permite al usuario consultar el número de estudios de un distrito por año.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//07: NÚMERO DE ESTUDIOS DE UN DISTRITO, POR AÑO
void numEstudisDistricte(Padro &p){
    mostraTitol("07. Nombre d'estudis per districte");

    int districte; cin >> districte;

    if(districte>0 && districte<=6){
        cout << "Districte: " << districte << endl;

        map<int, int> nEstudis = p.nombreEstudisDistricte(districte);
        //recorrer resultado y mostrar
        map<int, int>::const_iterator itEstudis = nEstudis.begin();
        while(itEstudis!=nEstudis.end()){
            cout << "Any " << itEstudis->first << setw(3) << "Num Estudis: " << itEstudis->second << endl;
            ++itEstudis;
        }
    }
    else{cerr << "ERROR: Disrticte " << districte << " invalid";}

}

/**
 * \brief Muestra el resumen del nivel de estudios por año y distrito.
 *
 * Esta función muestra un resumen del nivel de estudios por año y distrito.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//08: RESUMEN DE NIVEL DE ESTUDIOS, POR AÑO Y DISTRITO
void promigNivellEstudis(Padro &p){
    mostraTitol("08. Resum nivell d'estudis");
    ResumNivellEstudis res = p.resumNivellEstudis();
    res.mostrarResumNivellEstudis();
}

/**
 * \brief Muestra un resumen de las nacionalidades por año.
 *
 * Esta función genera un resumen de las nacionalidades de la población por año,
 * utilizando la clase `ResumNacionalitats` para organizar y mostrar los datos correspondientes.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//09: RESUMEN DE NACIONALIDADES, POR AÑO
void resumenNacionalitats(Padro &p){
    mostraTitol("9. Resum de nacionalitats");
    ResumNacionalitats res = p.resumNacionalitats();
    res.mostrarResumNacionalitats();
}

/**
 * \brief Muestra los movimientos de una comunidad por código de nacionalidad.
 *
 * Esta función consulta y muestra los movimientos de la población perteneciente a una
 * comunidad identificada por un código de nacionalidad específico.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */


//10: MOVIMIENTOS DE UNA COMUNIDAD
void movimentsComunitat(Padro &p){
    mostraTitol("10. Moviments d'una comunitat");
    int codiNacionalitat; cin >> codiNacionalitat;
    cout << "Codi Nacionalitat:" << codiNacionalitat <<endl;
    map<int,string> moviments = p.movimentsComunitat(codiNacionalitat); //obtener movimientos
    //mostrar movimientos
    map<int,string>::const_iterator itMoviments = moviments.begin();
    while(itMoviments!=moviments.end()){
        cout << setw(10) << itMoviments->first << setw(7) << right << itMoviments->second << endl;
        ++itMoviments;
    }
}

/**
 * \brief Muestra un resumen de las edades de la población.
 *
 * Esta función genera un resumen de las edades de la población y las muestra en pantalla,
 * utilizando la clase `ResumEdats` para organizar los datos.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//11: RESUMEN DE EDADES
void resumenEdats(Padro& p){
    mostraTitol("11. Resum d'edats");
    ResumEdats resum = p.resumEdat();
    resum.mostrarResumEdats();
}

/**
 * \brief Muestra los movimientos de los mayores de edad.
 *
 * Esta función consulta y muestra los movimientos de la población de mayor edad,
 * proporcionando los datos por año.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//12: MOVIMIENTOS DE LOS MAYORES
void movimentsMesVells(Padro &p){
    mostraTitol("Moviments dels vells");

    map<int, string> moviments = p.movimentVells();
    for(const auto& any: moviments){
        cout << any.first << setw(5) << any.second << endl;
    }
}

/**
 * \brief Muestra el distrito con más jóvenes entre un rango de años.
 *
 * Esta función permite consultar el distrito con más jóvenes dentro de un rango de años
 * proporcionado por el usuario.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//13: MÁS JÓVENES
void mesJoves(Padro &p){
    mostraTitol("13. Més joves");

    int anyInicial, anyFinal;
    cin >> anyInicial;
    cin >> anyFinal;

    pair<string, long> districte = p.mesJoves(anyInicial, anyFinal);

    cout << "Any Inicial: " << anyInicial << " Any Final: " << anyFinal << endl;
    cout << districte.first << setw(5) << districte.second << endl;
}

/**
 * \brief Muestra los estudios correspondientes a un año, distrito, edad y nacionalidad específicos.
 *
 * Esta función consulta los estudios de la población filtrados por el año, distrito, edad y
 * nacionalidad, y muestra los resultados correspondientes.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//14: ESTUDIOS DE UN AÑO, DISRTITO, EDAD Y NACIONALIDAD
void estudisFiltre(Padro &p){
    mostraTitol("14. Estudis any, districte, edat i nació");

    int any, districte, edat, codiNacionalitat;
    cin >> any >> districte >> edat >> codiNacionalitat;

    list<string> estudis = p.estudisEdat(any, districte, edat, codiNacionalitat);

    cout << "Any: " << any << "Districte: " << districte << "Edat: " << edat << " Nacionalitat: " << codiNacionalitat << endl;
    if(!estudis.empty()){
        for(const string& estudi: estudis){
        cout << estudi << endl;
        }
    }
    else cout << "No se han encontrado estudios para estos criterios." << endl;
}

/**
 * \brief Muestra el menú de opciones del programa.
 *
 * Esta función muestra el menú principal con todas las opciones disponibles para el usuario.
 *
 */

//15: MENÚ
void menu(){
    cout << "MENU" << endl;
    lineaChar('-');
    cout << "00. FINALIZAR PROGRAMA" << endl;
    cout << "01. LEER DATOS" << endl;
    cout << "02. CONSULTAR SI EXISTE UN AÑO" << endl;
    cout << "03. CONSULTAR NUMERO DE HABITANTES POR AÑO" << endl;
    cout << "04. CONSULTAR NUMERO DE HABITANTES DE UN AÑO" << endl;
    cout << "05. CONSULTAR NUMERO DE HABITANTES DE UN AÑO Y UN DISTRITO" << endl;
    cout << "06. RESUMEN DE ESTUDIOS DE LA POBLACIÓN POR AÑO" << endl;
    cout << "07. NUMERO DE ESTUDIOS POR DISTRITO" << endl;
    cout << "08. RESUMEN DEL NIVEL DE ESTUDIOS" << endl;
    cout << "09. RESUMEN DE NACIONALIDADES" << endl;
    cout << "10. MOVIMIENTOS DE COMUNIDADES" << endl;
    cout << "11. RESUMEN DE EDADES" << endl;
    cout << "12. MOVIMIENTOS DE LOS MAYORES" << endl;
    cout << "13. DISTRITO CON MÁS JÓVENES" << endl;
    cout << "14. ESTUDIOS DE UN AÑO, DISTRITO, EDAD Y NACIONALIDAD" << endl;
    cout << "15. MENU" << endl;
    lineaChar('-');
}

/**
 * \brief Gestiona las opciones seleccionadas por el usuario.
 *
 * Esta función ejecuta la opción seleccionada por el usuario, llamando a la función correspondiente
 * según el número de opción ingresado.
 *
 * \param opcioS La opción seleccionada por el usuario, como una cadena de texto.
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */

//GESTIÓN DE OPCIÓN DEL USUARIO
void gestioOpcio(string opcioS, Padro &p){
    int opcio = stoi(opcioS);
    switch(opcio){
        case 1:
            cargarDatos(p);
            break;
        case 2:
            existeixAny(p);
            break;
        case 3:
            numHabitants(p);
            break;
        case 4:
            numHabitantsAny(p);
            break;
        case 5:
            numHabitantsAnyDistricte(p);
            break;
        case 6:
            resumEstudisPoblacio(p);
            break;
        case 7:
            numEstudisDistricte(p);
            break;
        case 8:
            promigNivellEstudis(p);
            break;
        case 9:
            resumenNacionalitats(p);
            break;
        case 10:
            movimentsComunitat(p);
            break;
        case 11:
            resumenEdats(p);
            break;
        case 12:
            movimentsMesVells(p);
            break;
        case 13:
            mesJoves(p);
            break;
        case 14:
            estudisFiltre(p);
            break;
        case 15:
            menu();
            break;
        default:
            cout << "Opción no válida. Introduce una opción de 1 a 15, o 0 para acabar." << endl;
            break;
    }
}


Here's the updated Doxygen-style documentation for options 9-15 of your program:

cpp
Copy code
/**
 * \brief Muestra un resumen de las nacionalidades por año.
 *
 * Esta función genera un resumen de las nacionalidades de la población por año,
 * utilizando la clase `ResumNacionalitats` para organizar y mostrar los datos correspondientes.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */
void resumenNacionalitats(Padro &p){
    mostraTitol("9. Resum de nacionalitats");
    ResumNacionalitats res = p.resumNacionalitats();
    res.mostrarResumNacionalitats();
}

/**
 * \brief Muestra los movimientos de una comunidad por código de nacionalidad.
 *
 * Esta función consulta y muestra los movimientos de la población perteneciente a una
 * comunidad identificada por un código de nacionalidad específico.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */
void movimentsComunitat(Padro &p){
    mostraTitol("10. Moviments d'una comunitat");
    int codiNacionalitat;
    cin >> codiNacionalitat;
    cout << "Codi Nacionalitat: " << codiNacionalitat << endl;

    map<int,string> moviments = p.movimentsComunitat(codiNacionalitat); //obtener movimientos
    // mostrar movimientos
    map<int,string>::const_iterator itMoviments = moviments.begin();
    while(itMoviments != moviments.end()){
        cout << setw(10) << itMoviments->first << setw(7) << right << itMoviments->second << endl;
        ++itMoviments;
    }
}

/**
 * \brief Muestra un resumen de las edades de la población.
 *
 * Esta función genera un resumen de las edades de la población y las muestra en pantalla,
 * utilizando la clase `ResumEdats` para organizar los datos.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */
void resumenEdats(Padro &p){
    mostraTitol("11. Resum d'edats");
    ResumEdats resum = p.resumEdat();
    resum.mostrarResumEdats();
}

/**
 * \brief Muestra los movimientos de los mayores de edad.
 *
 * Esta función consulta y muestra los movimientos de la población de mayor edad,
 * proporcionando los datos por año.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */
void movimentsMesVells(Padro &p){
    mostraTitol("Moviments dels vells");

    map<int, string> moviments = p.movimentVells();
    for(const auto& any: moviments){
        cout << any.first << setw(5) << any.second << endl;
    }
}

/**
 * \brief Muestra el distrito con más jóvenes entre un rango de años.
 *
 * Esta función permite consultar el distrito con más jóvenes dentro de un rango de años
 * proporcionado por el usuario.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */
void mesJoves(Padro &p){
    mostraTitol("13. Més joves");

    int anyInicial, anyFinal;
    cin >> anyInicial;
    cin >> anyFinal;

    pair<string, long> districte = p.mesJoves(anyInicial, anyFinal);

    cout << "Any Inicial: " << anyInicial << " Any Final: " << anyFinal << endl;
    cout << districte.first << setw(5) << districte.second << endl;
}

/**
 * \brief Muestra los estudios correspondientes a un año, distrito, edad y nacionalidad específicos.
 *
 * Esta función consulta los estudios de la población filtrados por el año, distrito, edad y
 * nacionalidad, y muestra los resultados correspondientes.
 *
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */
void estudisFiltre(Padro &p){
    mostraTitol("14. Estudis any, districte, edat i nació");

    int any, districte, edat, codiNacionalitat;
    cin >> any >> districte >> edat >> codiNacionalitat;

    list<string> estudis = p.estudisEdat(any, districte, edat, codiNacionalitat);

    cout << "Any: " << any << " Districte: " << districte << " Edat: " << edat << " Nacionalitat: " << codiNacionalitat << endl;
    if(!estudis.empty()){
        for(const string& estudi: estudis){
            cout << estudi << endl;
        }
    }
    else cout << "No se han encontrado estudios para estos criterios." << endl;
}

/**
 * \brief Muestra el menú de opciones del programa.
 *
 * Esta función muestra el menú principal con todas las opciones disponibles para el usuario.
 *
 */
void menu(){
    cout << "MENU" << endl;
    lineaChar('-');
    cout << "00. FINALIZAR PROGRAMA" << endl;
    cout << "01. LEER DATOS" << endl;
    cout << "02. CONSULTAR SI EXISTE UN AÑO" << endl;
    cout << "03. CONSULTAR NUMERO DE HABITANTES POR AÑO" << endl;
    cout << "04. CONSULTAR NUMERO DE HABITANTES DE UN AÑO" << endl;
    cout << "05. CONSULTAR NUMERO DE HABITANTES DE UN AÑO Y UN DISTRITO" << endl;
    cout << "06. RESUMEN DE ESTUDIOS DE LA POBLACIÓN POR AÑO" << endl;
    cout << "07. NUMERO DE ESTUDIOS POR DISTRITO" << endl;
    cout << "08. RESUMEN DEL NIVEL DE ESTUDIOS" << endl;
    cout << "09. RESUMEN DE NACIONALIDADES" << endl;
    cout << "10. MOVIMIENTOS DE COMUNIDADES" << endl;
    cout << "11. RESUMEN DE EDADES" << endl;
    cout << "12. MOVIMIENTOS DE LOS MAYORES" << endl;
    cout << "13. DISTRITO CON MÁS JÓVENES" << endl;
    cout << "14. ESTUDIOS DE UN AÑO, DISTRITO, EDAD Y NACIONALIDAD" << endl;
    cout << "15. MENU" << endl;
    lineaChar('-');
}

/**
 * \brief Gestiona las opciones seleccionadas por el usuario.
 *
 * Esta función ejecuta la opción seleccionada por el usuario, llamando a la función correspondiente
 * según el número de opción ingresado.
 *
 * \param opcioS La opción seleccionada por el usuario, como una cadena de texto.
 * \param p Un objeto de la clase Padro con los datos del padrón.
 */
void gestioOpcio(string opcioS, Padro &p){
    int opcio = stoi(opcioS);
    switch(opcio){
        case 1:
            cargarDatos(p);
            break;
        case 2:
            existeixAny(p);
            break;
        case 3:
            numHabitants(p);
            break;
        case 4:
            numHabitantsAny(p);
            break;
        case 5:
            numHabitantsAnyDistricte(p);
            break;
        case 6:
            resumEstudisPoblacio(p);
            break;
        case 7:
            numEstudisDistricte(p);
            break;
        case 8:
            promigNivellEstudis(p);
            break;
        case 9:
            resumenNacionalitats(p);
            break;
        case 10:
            movimentsComunitat(p);
            break;
        case 11:
            resumenEdats(p);
            break;
        case 12:
            movimentsMesVells(p);
            break;
        case 13:
            mesJoves(p);
            break;
        case 14:
            estudisFiltre(p);
            break;
        case 15:
            menu();
            break;
        default:
            cout << "Opción no válida. Introduce una opción de 1 a 15, o 0 para acabar." << endl;
            break;
    }
}

/**
 * \brief Función principal que ejecuta el programa.
 *
 * Esta función muestra el menú, procesa las opciones seleccionadas por el usuario
 * y ejecuta las funciones correspondientes según la elección del usuario.
 *
 * \return Código de salida del programa.
 */

int main()
{

    Padro p;
    menu();
    string opcio;
    cin >> opcio;
    while(opcio!="00" || opcio != "0"){
        gestioOpcio(opcio, p);
        cin >> opcio;
    }

    cout << "Finalizando el programa." << endl;

    return 0;
}
