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

//Mostrar título de menú
void mostraTitol(const string &titol){
    int ancho = titol.size() + 4;
    cout << string(ancho, '*') << endl;
    cout << "* " << titol << " *" << endl;
    cout << string(ancho, '*') << endl;
}

void lineaChar(char c){
    int ancho = 15;
    cout << string(ancho, c) << endl;
}


//GESTIÓN DE INTERACCIÓN CON EL USUARIO

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

//06: RESUMEN DE ESTUDIOS DE LA POBLACIÓN POR AÑO
void resumEstudisPoblacio(Padro &p){
    mostraTitol("06. Resum per estudis");
    //guardar el resultado de la funcion de padro
    ResumEstudis res = p.resumEstudis();
    res.mostrarResumEstudis();
}

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

//08: RESUMEN DE NIVEL DE ESTUDIOS, POR AÑO Y DISTRITO
void promigNivellEstudis(Padro &p){
    mostraTitol("08. Resum nivell d'estudis");
    ResumNivellEstudis res = p.resumNivellEstudis();
    res.mostrarResumNivellEstudis();
}

//09: RESUMEN DE NACIONALIDADES, POR AÑO
void resumenNacionalitats(Padro &p){
    mostraTitol("9. Resum de nacionalitats");
    ResumNacionalitats res = p.resumNacionalitats();
    res.mostrarResumNacionalitats();
}

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

//11: RESUMEN DE EDADES
void resumenEdats(Padro& p){
    mostraTitol("11. Resum d'edats");
    ResumEdats resum = p.resumEdat();
    resum.mostrarResumEdats();
}

//12: MOVIMIENTOS DE LOS MAYORES
void movimentsMesVells(Padro &p){
    mostraTitol("Moviments dels vells");

    map<int, string> moviments = p.movimentVells();
    for(const auto& any: moviments){
        cout << any.first << setw(5) << any.second << endl;
    }
}

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

//GESTIÓN DE OPCIÓN DEL USUARIO
void gestioOpcio(int opcio, Padro &p){
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

int main()
{

    Padro p;
    menu();
    int opcio;
    cin >> opcio;
    while(opcio!=0){
        gestioOpcio(opcio, p);
        cin >> opcio;
    }

    cout << "Finalizando el programa." << endl;

    return 0;
}
