/**
 * \file Districte.h
 * \brief Define la clase Districte para gestionar información sobre los habitantes en secciones de un distrito.
 *
 * La clase `Districte` gestiona la información de los habitantes organizados por secciones,
 * permitiendo realizar consultas relacionadas con estudios, edades, nacionalidades y otros datos demográficos.
 */

#ifndef DISTRICTE_H
#define DISTRICTE_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <set>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Persona.h"
#include "Resums.h"

using namespace std;

/**
 * \class Districte
 * \brief Clase que gestiona los datos de los habitantes en las secciones de un distrito.
 *
 * La clase `Districte` organiza y permite el acceso a información demográfica de los habitantes,
 * incluyendo estudios, edades, y nacionalidades, organizados por secciones dentro del distrito.
 */

class Districte
{
    public:

        /**
     * \brief Constructor por defecto de la clase Districte.
     *
     * Inicializa un objeto `Districte` vacío sin habitantes.
     */
        Districte() {};

         /**
     * \brief Añade un habitante a una sección del distrito.
     *
     * Este método añade una nueva persona a la sección indicada dentro del distrito,
     * utilizando la información proporcionada sobre su nivel de estudios, año de nacimiento, y nacionalidad.
     *
     * \param codiNivellEstudis Código del nivel de estudios de la persona.
     * \param nivellEstudis Nombre del nivel de estudios de la persona.
     * \param anyNaixement Año de nacimiento de la persona.
     * \param codiNacionalitat Código de la nacionalidad de la persona.
     * \param nomNacionalitat Nombre de la nacionalidad de la persona.
     * \param seccio Sección dentro del distrito en la que reside la persona.
     */
        void afegirDistricte(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio);

        /**
     * \brief Verifica si una sección existe en el distrito.
     *
     * \param seccio Número de la sección a verificar.
     * \return `true` si la sección existe, `false` en caso contrario.
     */
        bool existeixSeccio(int seccio);

        /**
     * \brief Obtiene el número total de habitantes en el distrito.
     *
     * \return El número total de habitantes como un valor de tipo `long`.
     */
        long obtenirNumHabitants() const;

        /**
     * \brief Obtiene el número de habitantes por sección.
     *
     * Devuelve un mapa que asocia cada sección con el número de habitantes correspondientes.
     *
     * \return Un mapa donde la clave es el número de la sección y el valor es el número de habitantes.
     */
        map<int, long> obtenirNumHabitantsSeccio() const;

        /**
     * \brief Calcula la edad media de los habitantes en el distrito para un año específico.
     *
     * \param any Año para calcular la edad media.
     * \return La edad media como un valor de tipo `double`.
     */
        double obtenirEdatMitjana(int any) const;

        /**
     * \brief Obtiene un conjunto de estudios presentes en la población del distrito.
     *
     * Devuelve un conjunto de cadenas que representan los diferentes niveles de estudios de los habitantes.
     *
     * \return Un conjunto (`set`) de `string` con los niveles de estudios.
     */
        set<string> resumEstudis() const; //devuelve un set con los estudios de la población

        /**
     * \brief Calcula el nivel medio de estudios en el distrito.
     *
     * \return El promedio del nivel de estudios como un valor de tipo `double`.
     */
        double resumNivellEstudis() const;

        /**
     * \brief Obtiene un resumen de las nacionalidades en el distrito.
     *
     * Devuelve un mapa que asocia un par de nombre de nacionalidad y código de nacionalidad con el número de habitantes.
     *
     * \return Un mapa con las nacionalidades presentes y sus respectivos conteos.
     */
        map<pair<string, int>, long> resumNacionalitats() const;

         /**
     * \brief Obtiene el número de habitantes de una nacionalidad específica en el distrito.
     *
     * \param codiNacionalitat Código de la nacionalidad a consultar.
     * \return El número de habitantes de esa nacionalidad como un valor de tipo `long`.
     */
        long obtenirNumHabitantsNacionalitat(int codiNacionalitat) const;

        /**
     * \brief Calcula el número de jóvenes (habitantes menores de una edad determinada) en un año dado.
     *
     * \param any Año para el cual se desea contar los jóvenes.
     * \return El número de jóvenes como un valor de tipo `long`.
     */
        long obtenirNumJoves(int any) const;

        /**
     * \brief Obtiene un conjunto de estudios según la edad, año y nacionalidad especificados.
     *
     * \param any Año de referencia.
     * \param edat Edad de los habitantes.
     * \param codiNacionalitat Código de la nacionalidad.
     * \return Un conjunto (`set`) de `string` con los niveles de estudios que cumplen las condiciones especificadas.
     */
        set<string> estudisEdat(int any, int edat, int codiNacionalitat) const;

    private:

        /**
     * \brief Almacena los habitantes organizados por secciones dentro del distrito.
     *
     * Un mapa que asocia el número de la sección (`int`) con una lista de objetos `Persona` que
     * representan a los habitantes de esa sección.
     */
        map<int, list<Persona>> habitantsSeccio;
};

#endif // DISTRICTE_H
