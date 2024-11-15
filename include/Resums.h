
#ifndef RESUMS_H
#define RESUMS_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

extern vector<string> nomsDistrictes;


//ESTRUCTURAS DE DATOS DE RESUMEN

//tipos de estudios de la población para cada año
struct ResumEstudis{
    map<int, set<string>> res;

    void afegirResumEstudis(int any, const set<string>& estudis){
        res[any].insert(estudis.begin(), estudis.end()); //inserir en el año correspondinte del map, el set de estudios
    }

    void mostrarResumEstudis() const{
        map<int, set<string>>::const_iterator itResum = res.begin();
        while(itResum!=res.end()){
        //mostrar
        cout << itResum->first << " Estudis: ";
        //iterador para recorrer el set de estudios
        set<string>::const_iterator itEstudi = itResum->second.begin();
        while(itEstudi!=itResum->second.end()){
            cout << *itEstudi;
            ++itEstudi;
            if(itEstudi!= itResum->second.end()){
                cout << " -- ";
            }
        }
        cout << endl;
        ++itResum;
        }
    }
};

struct ResumEdats{
};

struct ResumNacionalitats{
};

//nivel promedio de estudios de cada distrito por año
struct ResumNivellEstudis{
    map<int, vector<double>> promig;

    void afegirPromig(int any, const vector<double>& promigDistrictes){
        promig[any] = promigDistrictes;
    }

    int mesEstudios(const vector<double>& vec){
        double maxNivell = vec[1];
        int vecMax = 1;
        for(unsigned i=2; i<vec.size(); i++){
            if(vec[i]>maxNivell){
                maxNivell = vec[i];
                vecMax = i;
            }
        }
        return vecMax;
    }

    int menysEstudios(const vector<double>& vec){
        double minNivell = vec[1];
        int vecMin = 1;
        for(unsigned i=2; i<vec.size(); i++){
            if(vec[i]<minNivell){
                minNivell = vec[i];
                vecMin = i;
            }
        }
        return vecMin;
    }

    void mostrarResumNivellEstudis(){
        map<int, vector<double>>::const_iterator itRes = promig.begin();
        while(itRes!=promig.end()){
            int mesEst = mesEstudios(itRes->second);
            int menysEst = menysEstudios(itRes->second);
            cout << itRes->first << ":" << endl;
            for(unsigned i=1; i<itRes->second.size(); i++){
                if(i==mesEst) cout << "- ";
                else if(i==menysEst) cout << "+ ";
                cout << " " << nomsDistrictes[i];
                cout << " Promig Estudis:" << itRes->second[i] << endl;
            }
            cout << "seguent any" << endl;
            ++itRes;
        }
    }
};

#endif // RESUMS_H
