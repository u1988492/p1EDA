#include <vector>
#include <map>
#include <list>
#include <string>
#include "Padro.h"

using namespace std;

int main()
{
    Padro p;
    cout << "Introduce el nombre del archivo que quieres cargar: " << endl;
    string fitxer;
    cin >> fitxer;
    int lectura = p.llegirDades(fitxer);
    if(lectura==-1){
        cerr << "No se ha leido el archivo correctamente." << endl;
        return -1;
    }


    cout << "Introduce el año y numero de distrito para consultar sus datos: " << endl;
    int any, districte;
    cin >> any;
    cin >> districte;
    p.mostraPadro(any, districte);

    return 0;
}
