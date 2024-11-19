/**
 * \file Resums.h
 * \brief Define las estructuras de datos para almacenar resúmenes sobre estudios, niveles de estudios, nacionalidades y edades.
 *
 * Este archivo contiene diversas estructuras que permiten resumir y gestionar información
 * acerca de los estudios, nacionalidades y edades de la población a lo largo de diferentes años.
 */

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


/**
 * \brief Vector global que contiene los nombres de los distritos.
 */
extern vector<string> nomsDistrictes;


// *****************************************************************
// ESTRUCTURAS DE DATOS DE RESUMEN
// *****************************************************************

/**
 * \struct ResumEstudis
 * \brief Resumen de tipos de estudios de la población para cada año.
 *
 * Esta estructura almacena, por cada año, un conjunto de niveles de estudios presentes en la población.
 */
struct ResumEstudis{
    map<int, set<string>> res; /**< Mapa que asocia cada año con un conjunto de estudios. */

    /**
     * \brief Añadir un conjunto de estudios al resumen de un año.
     * \param any Año al que se asocian los estudios.
     * \param estudis Conjunto de estudios a añadir.
     */
    void afegirResumEstudis(int any, const set<string>& estudis){
        res[any].insert(estudis.begin(), estudis.end()); //inserir en el año correspondinte del map, el set de estudios
    }

    /**
     * \brief Mostrar el resumen de estudios por cada año.
     */
    void mostrarResumEstudis() const{
        map<int, set<string>>::const_iterator itResum = res.begin();
        while(itResum!=res.end()){
        //mostrar
        cout << itResum->first << setw(2) << "Estudis: ";
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

// *****************************************************************

/**
 * \struct ResumNivellEstudis
 * \brief Resumen del nivel promedio de estudios de cada distrito por año.
 *
 * Esta estructura almacena un mapa que asocia cada año con un vector de promedios de estudios para cada distrito.
 */
//nivel promedio de estudios de cada distrito por año
struct ResumNivellEstudis{
    map<int, vector<double>> promig; /**< Mapa que asocia cada año con el promedio de estudios por distrito. */

    /**
     * \brief Añadir promedios de estudios para un año dado.
     * \param any Año al que se asocian los promedios.
     * \param promigDistrictes Vector con los promedios de estudios para cada distrito.
     */
    void afegirPromig(int any, const vector<double>& promigDistrictes){
        promig[any] = promigDistrictes;
    }

    /**
     * \brief Determina el distrito con mayor nivel de estudios en un año.
     * \param vec Vector con los niveles de estudios por distrito.
     * \return El índice del distrito con mayor nivel de estudios.
     */
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

    /**
     * \brief Determina el distrito con menor nivel de estudios en un año.
     * \param vec Vector con los niveles de estudios por distrito.
     * \return El índice del distrito con menor nivel de estudios.
     */
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

    /**
     * \brief Mostrar el resumen de niveles de estudios por distrito y año.
     */
    void mostrarResumNivellEstudis(){
        map<int, vector<double>>::const_iterator itRes = promig.begin();
        while(itRes!=promig.end()){
            size_t mesEst = mesEstudios(itRes->second);
            size_t menysEst = menysEstudios(itRes->second);
            cout << itRes->first << ":" << endl;
            for(size_t i=1; i<itRes->second.size(); i++){
                if(i==mesEst) cout << "+ ";
                else if(i==menysEst) cout << "- ";
                cout << "" << setw(7) << nomsDistrictes[i]
                << setw(7) << " Promig Estudis:" << right << setprecision(2) << itRes->second[i] << endl;
            }
            ++itRes;
        }
    }
};


// *****************************************************************

/**
 * \struct ResumNacionalitats
 * \brief Resumen de nacionalidades y número de habitantes por cada año.
 *
 * Esta estructura almacena un mapa que asocia cada año con un mapa de nacionalidades y sus respectivos conteos de habitantes.
 */
//tipos de nacionalidad y numero de habitantes de esa nacionalidad por cada año, ordenadas por número de habitantes descendiente
struct ResumNacionalitats{
    map<int, map<pair<string, int>, long>> nacionalitats; /**< Mapa que asocia cada año con el conteo de nacionalidades. */

    /**
     * \brief Añadir resumen de nacionalidades para un año.
     * \param any Año al que se asocia el resumen.
     * \param mapResum Mapa de nacionalidades y sus conteos.
     */
    void afegirNacionalitats(int any, const map<pair<string, int>, long>& mapResum){
        nacionalitats[any] = mapResum;
    }

    /**
     * \brief Ordenar nacionalidades por número de habitantes en un año.
     * \param any Año del que se quiere ordenar la información.
     * \return Vector de pares con las nacionalidades ordenadas descendientemente por habitantes.
     */
     //ordenar nacionalidades por numero de habitantes usando un vector y sort de la libreria algorithm
    vector<pair<pair<string, int>, long>> ordenaResumNacionalitats(int any) const{
        vector<pair<pair<string, int>, long>> vecResum;

        const auto& mapResum = nacionalitats.at(any);

        vecResum.reserve(mapResum.size());
        map<pair<string, int>, long>::const_iterator it = mapResum.begin();
        while(it!=mapResum.end()){
            vecResum.emplace_back(*it);
            ++it;
        }

        sort(vecResum.begin(), vecResum.end(),
             [](const pair<pair<string, int>, long>& a, const pair<pair<string, int>, long>&b){
                if(a.second!=b.second) return a.second > b.second; //ordenar por num habitantes
                return a.first.first < b.first.first; //en el caso de nacionalidades con mismo num habitantes, ordenar alfabeticamente
             });

        return vecResum;
    }

    /**
     * \brief Mostrar el resumen de nacionalidades ordenado por número de habitantes.
     */
    void mostrarResumNacionalitats() const{
        for(const auto& any: nacionalitats){
            cout << any.first << endl; //mostrar año
            //obtener vector de resumen año ordenado
            auto nacOrdenadas = ordenaResumNacionalitats(any.first);
            //mostrar nombres y codigo de nacionalidad ordenados por habitantes descendiente
            for(const auto&nacion: nacOrdenadas){
                const auto& nacio = nacion.first;
                cout << setw(10) << left << nacio.first << "(" << nacio.second << ")" <<
                setw(20) << ":" << setw(8) << nacion.second << endl;
            }
            cout << endl;
        }
    }
};

/**
 * \struct ResumEdats
 * \brief Resumen de edades promedio por distrito y año.
 *
 * Esta estructura permite almacenar y mostrar el promedio de edades de los habitantes en diferentes distritos para cada año.
 */
struct ResumEdats{

    map<int, vector<double>> promigEdats; /**< Mapa que asocia cada año con el promedio de edades por distrito. */

    /**
     * \brief Añadir promedios de edades para un año dado.
     * \param any Año al que se asocian los promedios.
     * \param promigEdatsDistrictes Vector con los promedios de edades por distrito.
     */
    void afegirEdats(int any, const vector<double>& promigEdatsDistrictes){
        vector<double> edatsOrdenats = promigEdatsDistrictes;
        sort(edatsOrdenats.begin(), edatsOrdenats.end()); //ordenar por edad ascendiente
        promigEdats[any] = edatsOrdenats;
    }

     /**
     * \brief Mostrar el resumen de edades promedio por distrito y año.
     */
    void mostrarResumEdats(){
        map<int, vector<double>>::const_iterator itRes = promigEdats.begin();
        while(itRes!=promigEdats.end()){
            cout << itRes->first << ":" << endl;
            for(size_t i=0; i<itRes->second.size(); i++){
                cout << left << setw(8) << nomsDistrictes[i+1]
                << setw(8) << "Promig Edat: "  << right  << fixed << setprecision(2) << itRes->second[i] << endl;
            }
            ++itRes;
        }
    }
};





#endif // RESUMS_H
