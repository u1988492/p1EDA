/**
 * \file Padro.h
 * \brief Define la clase Padro para gestionar los datos del padrón.
 *
 * Esta clase maneja los datos de los habitantes, incluyendo estadísticas sobre
 * nacionalidades, edad, estudios, y movimientos de los habitantes por año y distrito.
 */

#ifndef PADRO_H
#define PADRO_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Any.h"
#include "Districte.h"
#include "eines.h"
#include "Resums.h"

using namespace std;

/**
 * \class Padro
 * \brief Clase que gestiona los datos del padrón, incluyendo habitantes, estudios y movimientos.
 *
 * La clase `Padro` proporciona una interfaz para cargar datos, consultar estadísticas sobre
 * la población, los estudios y movimientos de los habitantes, y calcular resúmenes de edades y
 * nacionalidades por año.
 */

class Padro {
public:
    /**
     * \brief Constructor de la clase Padro.
     *
     * Inicializa un objeto `Padro` vacío, preparado para leer datos de archivos.
     */
    Padro();
    //Constructor vacío

    /**
     * \brief Lee los datos desde un archivo y los carga en las estructuras internas.
     *
     * Este método carga los datos de población desde un archivo, organizándolos por año.
     *
     * \param path Ruta al archivo con los datos a cargar.
     * \return El número total de datos leídos del archivo.
     */

    int llegirDades(const string &path);
    //Pre: path es el archivo que quiere cargar el usuario a las estructuras de datos
    //Post: devuelve el número total de datos leídos

    /**
     * \brief Verifica si existe un año en los datos cargados.
     *
     * Este método verifica si el año solicitado existe en los datos del padrón.
     *
     * \param any Año a buscar.
     * \return `true` si el año existe, `false` en caso contrario.
     */

    bool existeixAny(int any) const;
    //Pre: any es el año que quiere buscar el usuario
    //Post: devuelve true si existe en padroAnys, false si no

     /**
     * \brief Obtiene el número total de habitantes por año.
     *
     * Este método devuelve un mapa con el número total de habitantes para cada año
     * registrado en el padrón.
     *
     * \return Un mapa donde la clave es el año y el valor es el número total de habitantes.
     */

    map<int, long> obtenirNumHabitantsPerAny() const;
    //Pre: --
    //Post: devuelve un map con el total de habitantes de cada año

     /**
     * \brief Obtiene el número de habitantes por distrito en un año específico.
     *
     * Este método devuelve un vector con el número de habitantes para cada distrito en
     * el año especificado.
     *
     * \param any Año de los datos a consultar.
     * \return Un vector donde el índice representa el distrito y el valor es el número de habitantes.
     */

    vector<long> obtenirNumHabitantsPerDistricte(int any) const;
    //Pre: any es un año válido dentro de padroAnys
    //Post: devuelve un vector con los habitantes de cada distrito

    /**
     * \brief Obtiene el número de habitantes por sección de un distrito en un año específico.
     *
     * Este método devuelve un mapa con el número de habitantes por cada sección dentro de un distrito,
     * para un año específico.
     *
     * \param any Año de los datos a consultar.
     * \param districte Distrito de los datos a consultar.
     * \return Un mapa donde la clave es el número de sección y el valor es el número de habitantes.
     */

    map<int, long> obtenirNumHabitantsPerSeccio(int any, int districte) const;
    //Pre: any y districte son el año y distrito son un año y distrito válidos de padroAnys
    //Post: devuelve un map con los habitantes por cada sección del distrito en el año introducido

     /**
     * \brief Obtiene un resumen de los estudios de la población en cada año.
     *
     * Este método genera un resumen de los estudios de los habitantes, agrupado por año.
     *
     * \return Un objeto `ResumEstudis` con los estudios de los habitantes por año.
     */

    ResumEstudis resumEstudis() const;
    //Pre:
    //Post: Devuelve un ResumEstudis que contiene los estudios de los habitantes de cada año en padroAnys

    /**
     * \brief Obtiene el número de estudios por distrito en un año.
     *
     * Este método devuelve un mapa con el número total de estudios en cada distrito para un año específico.
     *
     * \param districte Código del distrito.
     * \return Un mapa donde la clave es el año y el valor es el número de estudios del distrito en ese año.
     */

    map<int,int> nombreEstudisDistricte(int districte) const;
    //Pre: districte > 0 y districte <= 6
    //Post: devuelve un map con el año y el número de estudios del distrito en ese año

     /**
     * \brief Obtiene un resumen del nivel de estudios por distrito y año.
     *
     * Este método devuelve un resumen que incluye el promedio del nivel de estudios por distrito,
     * para cada año del padrón.
     *
     * \return Un objeto `ResumNivellEstudis` con los promedios de nivel de estudios por distrito y año.
     */

    ResumNivellEstudis resumNivellEstudis() const;
    //Pre: --
    //Post: devuelve un map con un pair de distrito y promedio del distrito por cada año

    /**
     * \brief Obtiene un resumen de las nacionalidades en el padrón.
     *
     * Este método devuelve un mapa que contiene los nombres de las nacionalidades y el número
     * de habitantes de cada nacionalidad, ordenados de mayor a menor.
     *
     * \return Un objeto `ResumNacionalitats` con los resúmenes de nacionalidades y número de habitantes.
     */

    ResumNacionalitats resumNacionalitats() const;
    //Pre: --
    //Post: devuelve un map con un set de pairs de nombre de la nacionalidad y número de habitantes de esa nacionalidad, ordenados descendientemente

    /**
     * \brief Obtiene los movimientos de una comunidad según su código de nacionalidad.
     *
     * Este método devuelve un mapa con el año y el nombre del distrito con el mayor número de habitantes
     * de una comunidad (nacionalidad) en ese año.
     *
     * \param codiNacionalitat Código de la nacionalidad a consultar.
     * \return Un mapa con el año y el nombre del distrito con más habitantes de la nacionalidad.
     */

    map<int,string> movimentsComunitat(int codiNacionalitat) const;
    //Pre: codiNacionalitat es un código de nacionalides del padrón
    //Post: devuelve un map con el año y el nombre del distrito con más habitantes de esa nacionalidad en ese año

    /**
     * \brief Obtiene un resumen de las edades promedio por distrito, por año.
     *
     * Este método devuelve un mapa con el promedio de edad para cada distrito en cada año.
     *
     * \return Un objeto `ResumEdats` con los promedios de edad por distrito y año.
     */

    ResumEdats resumEdat() const;
    //Pre: --
    //Post: devuelve un map con el promedio de edad de cada distrito, para cada año del padrón

    /**
     * \brief Obtiene los movimientos de los mayores, es decir, los distritos con mayor promedio de edad.
     *
     * Este método devuelve un mapa con el nombre del distrito con mayor promedio de edad para cada año.
     *
     * \return Un mapa con el nombre del distrito de mayor edad promedio para cada año.
     */

    map<int, string> movimentVells() const;
    //Pre: --
    //Post: devuelve un map con el nombre del distrito de mayor edad promedia de cada año

    /**
     * \brief Obtiene el distrito con el mayor incremento de jóvenes entre dos años.
     *
     * Este método devuelve un par que incluye el nombre del distrito con el mayor incremento de jóvenes
     * entre los dos años especificados, junto con el valor de ese incremento.
     *
     * \param anyInicial Año inicial.
     * \param anyFinal Año final.
     * \return Un par con el nombre del distrito y el incremento de jóvenes.
     */


    pair<string,long> mesJoves(int anyInicial, int anyFinal) const;
    //Pre: anyInicial y anyFinal > 0
    //Post: devuelve un pair con el nombre del distrito con mayor incremento de jóvenes entre los dos años, y el incremento


    /**
     * \brief Obtiene los estudios de los habitantes en un año, distrito, edad y nacionalidad específicos.
     *
     * Este método devuelve una lista con los nombres de los estudios de los habitantes que cumplen las
     * condiciones especificadas (año, distrito, edad, nacionalidad).
     *
     * \param any Año de los datos a consultar.
     * \param districte Código del distrito.
     * \param edat Edad de los habitantes.
     * \param codiNacionalitat Código de la nacionalidad.
     * \return Una lista con los nombres de los estudios de los habitantes que cumplen las condiciones.
     */

    list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;
    //Pre: any > 0, 0<districte<=6, edat>0, codiNacionalitat>0
    //Post: devuelve una list con los nombres de los estudios de los habitantes que cumplen las condiciones

private:
     /** Mapa que contiene los datos del padrón por año. */
    map<int, Any> padroAnys;

};

#endif //PADRO_H
