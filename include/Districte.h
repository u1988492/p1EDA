/**
 * \file Districte.h
 * \brief Define la clase Districte para gestionar informaci�n sobre los habitantes en secciones de un distrito.
 *
 * La clase `Districte` gestiona la informaci�n de los habitantes organizados por secciones,
 * permitiendo realizar consultas relacionadas con estudios, edades, nacionalidades y otros datos demogr�ficos.
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
 * La clase `Districte` organiza y permite el acceso a informaci�n demogr�fica de los habitantes,
 * incluyendo estudios, edades, y nacionalidades, organizados por secciones dentro del distrito.
 */

class Districte
{
    public:

        /**
     * \brief Constructor por defecto de la clase Districte.
     *
     * Inicializa un objeto `Districte` vac�o sin habitantes.
     */
        Districte() {};

         /**
     * \brief A�ade un habitante a una secci�n del distrito.
     *
     * Este m�todo a�ade una nueva persona a la secci�n indicada dentro del distrito,
     * utilizando la informaci�n proporcionada sobre su nivel de estudios, a�o de nacimiento, y nacionalidad.
     *
     * \param codiNivellEstudis C�digo del nivel de estudios de la persona.
     * \param nivellEstudis Nombre del nivel de estudios de la persona.
     * \param anyNaixement A�o de nacimiento de la persona.
     * \param codiNacionalitat C�digo de la nacionalidad de la persona.
     * \param nomNacionalitat Nombre de la nacionalidad de la persona.
     * \param seccio Secci�n dentro del distrito en la que reside la persona.
     */
        void afegirDistricte(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio);

        /**
     * \brief Verifica si una secci�n existe en el distrito.
     *
     * \param seccio N�mero de la secci�n a verificar.
     * \return `true` si la secci�n existe, `false` en caso contrario.
     */
        bool existeixSeccio(int seccio);

        /**
     * \brief Obtiene el n�mero total de habitantes en el distrito.
     *
     * \return El n�mero total de habitantes como un valor de tipo `long`.
     */
        long obtenirNumHabitants() const;

        /**
     * \brief Obtiene el n�mero de habitantes por secci�n.
     *
     * Devuelve un mapa que asocia cada secci�n con el n�mero de habitantes correspondientes.
     *
     * \return Un mapa donde la clave es el n�mero de la secci�n y el valor es el n�mero de habitantes.
     */
        map<int, long> obtenirNumHabitantsSeccio() const;

        /**
     * \brief Calcula la edad media de los habitantes en el distrito para un a�o espec�fico.
     *
     * \param any A�o para calcular la edad media.
     * \return La edad media como un valor de tipo `double`.
     */
        double obtenirEdatMitjana(int any) const;

        /**
     * \brief Obtiene un conjunto de estudios presentes en la poblaci�n del distrito.
     *
     * Devuelve un conjunto de cadenas que representan los diferentes niveles de estudios de los habitantes.
     *
     * \return Un conjunto (`set`) de `string` con los niveles de estudios.
     */
        set<string> resumEstudis() const; //devuelve un set con los estudios de la poblaci�n

        /**
     * \brief Calcula el nivel medio de estudios en el distrito.
     *
     * \return El promedio del nivel de estudios como un valor de tipo `double`.
     */
        double resumNivellEstudis() const;

        /**
     * \brief Obtiene un resumen de las nacionalidades en el distrito.
     *
     * Devuelve un mapa que asocia un par de nombre de nacionalidad y c�digo de nacionalidad con el n�mero de habitantes.
     *
     * \return Un mapa con las nacionalidades presentes y sus respectivos conteos.
     */
        map<pair<string, int>, long> resumNacionalitats() const;

         /**
     * \brief Obtiene el n�mero de habitantes de una nacionalidad espec�fica en el distrito.
     *
     * \param codiNacionalitat C�digo de la nacionalidad a consultar.
     * \return El n�mero de habitantes de esa nacionalidad como un valor de tipo `long`.
     */
        long obtenirNumHabitantsNacionalitat(int codiNacionalitat) const;

        /**
     * \brief Calcula el n�mero de j�venes (habitantes menores de una edad determinada) en un a�o dado.
     *
     * \param any A�o para el cual se desea contar los j�venes.
     * \return El n�mero de j�venes como un valor de tipo `long`.
     */
        long obtenirNumJoves(int any) const;

        /**
     * \brief Obtiene un conjunto de estudios seg�n la edad, a�o y nacionalidad especificados.
     *
     * \param any A�o de referencia.
     * \param edat Edad de los habitantes.
     * \param codiNacionalitat C�digo de la nacionalidad.
     * \return Un conjunto (`set`) de `string` con los niveles de estudios que cumplen las condiciones especificadas.
     */
        set<string> estudisEdat(int any, int edat, int codiNacionalitat) const;

    private:

        /**
     * \brief Almacena los habitantes organizados por secciones dentro del distrito.
     *
     * Un mapa que asocia el n�mero de la secci�n (`int`) con una lista de objetos `Persona` que
     * representan a los habitantes de esa secci�n.
     */
        map<int, list<Persona>> habitantsSeccio;
};

#endif // DISTRICTE_H
