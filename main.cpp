#include <vector>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include "Padro.h"

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
    cout << "Introduce el nombre del archivo que quieres cargar: " << endl;
        string fitxer;
        cin >> fitxer;
        int lectura = p.llegirDades(fitxer);
        if(lectura==-1){
            cerr << "No se ha leido el archivo correctamente." << endl;
            return;
        }
        else cout << "Se han leído " << lectura << " datos." << endl;
}

//02: EXISTE AÑO
void existeixAny(Padro &p){
    mostraTitol("02. Existeix any");
    int any;
    cout << "Any: "; cin >> any;
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
    int totalPadro = 0;

    for(const auto &any: habitants){
        int anyActual = any.first;
        long total = any.second;
        cout << anyActual << " habitants: " << total << endl;
        totalPadro += total;
    }
    long promig = (habitants.size()>0) ? totalPadro/habitants.size(): 0; //comprobar si habitants>0 antes de operar para evitar errores
    cout << "PROMIG: " << setprecision(2) << promig << endl;
}

//04: NÚMERO DE HABITANTES DE UN AÑO
void numHabitantsAny(Padro &p){
    return;
}

//05: NÚMERO DE HABITANTES DE UN AÑO Y DISTRITO
void numHabitantsAnyDistricte(Padro &p){
    return;
}

//06: RESUMEN POR ESTUDIOS

//07: NÚMERO DE ESTUDIOS POR DISTRITO

//08: RESUMEN DE NIVEL DE ESTUDIOS, POR AÑO Y DISTRITO

//09: RESUMEN DE NACIONALIDADES, POR AÑO

//10: MOVIMIENTOS DE UNA COMUNIDAD

//11: RESUMEN DE EDADES

//12: MOVIMIENTOS DE LOS MAYORES

//12: MÁS JÓVENES

//14: ESTUDIOS DE UN AÑO, DISRTITO, EDAD Y NACIONALIDAD

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
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
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
    cout << "Introduce una opción del 1 al 15, o 0 para acabar." << endl;
    int opcio;
    cin >> opcio;
    while(opcio!=0){
        gestioOpcio(opcio, p);
        cout << "Introduce una opción del 1 al 15, o 0 para acabar." << endl;
        cin >> opcio;
    }

    cout << "Finalizando el programa." << endl;

    return 0;
}
