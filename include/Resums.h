
#ifndef RESUMS_H
#define RESUMS_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

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

//nivel promedio de estudios de cada distrito por año
struct ResumNivellEstudis{
    map<int, vector<double>> promig;

    void afegirPromig(int any, const vector<double>& promigDistrictes){
        promig[any] = promigDistrictes;
    }

    int mesEstudios(const vector<double>& vec){
        double maxNivell = vec[1];
        int vecMax = 1;
        for(size_t i=2; i<vec.size(); i++){
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
        for(size_t i=2; i<vec.size(); i++){
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
            for(size_t i=1; i<itRes->second.size(); i++){
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

//tipos de nacionalidad y numero de habitantes de esa nacionalidad por cada año, ordenadas por número de habitantes descendiente
struct ResumNacionalitats{
    map<int, map<pair<string, int>, long>> nacionalitats;

    void afegirNacionalitats(int any, const map<pair<string, int>, long>& mapResum){
        nacionalitats[any] = mapResum;
    }

    //ordenar nacionalidades por numero de habitantes usando un vector y sort de la libreria algorithm
    vector<pair<pair<string, int>, long>> ordenaResumNacionalitats(int any) const{
        vector<pair<pair<string, int>, long>> vecResum; //vector resultado

        const auto& mapResum = nacionalitats.at(any); //referencia al mapa en nacionalitats del año en concreto

        vecResum.reserve(mapResum.size()); //guardar espacio en el vector
        for(const auto&it: mapResum){
            vecResum.emplace_back(it); //guardar el pair del mapa en el vector
        }

        sort(vecResum.begin(), vecResum.end(), //ordenar vector segun habitantes
             [](const pair<pair<string, int>, long>& a, const pair<pair<string, int>, long>&b){
                return a.second > b.second;
             });

        return vecResum;
    }

    void mostrarResumNacionalitats() const{
        for(const auto& elem: nacionalitats){
            int any = elem.first;
            cout << any << endl;//mostrar año
            //obtener vector de resumen año ordenado
                auto nacOrdenadas = ordenaResumNacionalitats(any.first);
            //mostrar nombres y codigo de nacionalidad ordenados por habitantes descendiente
            for(const auto&nacion: nacOrdenadas){
                const auto& nacio = nacion.first;
                cout << nacio.first << "(" << nacio.second << ")" << setw(20) << ":" << setw(20) << nacion.second << endl;
            }
            cout << endl;
        }
    }
};

struct ResumEdats{
};





#endif // RESUMS_H
