/**
 * \file Any.h
 * \brief Define la clase Any para gestionar la información de habitantes en cada distrito.
 *
 * La clase `Any` organiza los datos de los habitantes dentro de un año específico,
 * gestionando información sobre los distritos, niveles de estudios, nacionalidades, edades,
 * y más. Permite acceder a estadísticas relacionadas con los habitantes de cada distrito.
 */

#ifndef ANY_H
#define ANY_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <iomanip>
#include <iostream>
#include "Districte.h"


using namespace std;

/**
 * \class Any
 * \brief Clase que gestiona los datos de los habitantes de un año específico.
 *
 * La clase `Any` contiene y organiza los datos de los habitantes en un año determinado,
 * permitiendo consultar estadísticas sobre la población en cada distrito, como edad,
 * nivel de estudios, nacionalidad, y más.
 */

class Any {
    public:
    /**
     * \brief Constructor de la clase Any.
     *
     * Este constructor inicializa un objeto `Any` con un vector de 7 posiciones
     * para almacenar la información de los distritos.
     */
        Any();
        //Pre: --
        //Post: se ha construido el objeto Any con un vector de 7 posiciones

   /**
     * \brief Añade una persona a los datos del distrito en un año específico.
     *
     * Este método agrega una nueva persona a la lista de habitantes, en el distrito y sección
     * especificados, con la información relacionada como el nivel de estudios, la edad y la nacionalidad.
     *
     * \param districte El distrito al que se agregará la persona.
     * \param codiNivellEstudis El código del nivel de estudios de la persona.
     * \param nivellEstudis El nombre del nivel de estudios de la persona.
     * \param anyNaixement El año de nacimiento de la persona.
     * \param codiNacionalitat El código de la nacionalidad de la persona.
     * \param nomNacionalitat El nombre de la nacionalidad de la persona.
     * \param seccio La sección dentro del distrito en la que se encuentra la persona.
     */

        void afegirAny(int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat, int seccio);
        //Pre: parámetros válidos (según la función validarDades en Padro)
        //Post: se ha añadido al objeto Any, en el distrito y sección correspondientes, una nueva persona a la lista de habitantes

        /**
     * \brief Obtiene el número de habitantes por distrito.
     *
     * Este método devuelve un vector que contiene el número de habitantes de cada uno de los 7 distritos
     * del año actual.
     *
     * \return Un vector de tipo `long` con el número de habitantes por distrito.
     */

        vector<long> obtenirNumHabitantsPerDistricte() const;
        //Pre: --
        //Post: se devuelve un vector de longs con el número de habitantes que tiene cada distrito


        /**
     * \brief Obtiene el número de habitantes por sección dentro de un distrito.
     *
     * Este método devuelve un mapa que asocia cada sección de un distrito con el número de habitantes.
     *
     * \param districte El código del distrito cuyo número de habitantes por sección se desea obtener.
     * \return Un mapa donde la clave es la sección y el valor es el número de habitantes.
     */

        map<int, long> obtenirNumHabitantsPerSeccio(int districte) const;
        //Pre: districte > 0 y districte <=6
        //Post: devuelve un map con la sección y el número de habitantes de esa sección, de un distrito introducido

        /**
     * \brief Obtiene los promedios de edad de los distritos en un año específico.
     *
     * Este método devuelve un vector con los promedios de edad de los habitantes en cada uno de los distritos,
     * para el año actual.
     *
     * \param any El año para el cual se desea obtener los promedios de edad.
     * \return Un vector de tipo `double` con los promedios de edad de los distritos en el año especificado.
     */

        vector<double> resumEdat(int any) const;
        //Pre: --
        //Post: devuelve un vector con los promedios de edad de los distritos de ese año

        /**
     * \brief Obtiene los estudios únicos de los habitantes de un año.
     *
     * Este método devuelve un conjunto con los niveles de estudios únicos de los habitantes en el año actual.
     *
     * \return Un conjunto de `string` con los niveles de estudios únicos de la población del año.
     */

        set<string> resumEstudis() const;
        //Pre: --
        //Post: devuelve un vector de strings con los estudios únicos de los habitantes en ese año del padrón

     /**
     * \brief Obtiene los estudios únicos de los habitantes de un distrito específico.
     *
     * Este método devuelve un conjunto con los niveles de estudios únicos de los habitantes de un distrito.
     *
     * \param districte El código del distrito cuyo nivel de estudios se desea consultar.
     * \return Un conjunto de `string` con los niveles de estudios únicos del distrito.
     */

        set<string> resumEstudisDistricte(int districte) const;
        //Pre: districte > 0 && districte <=6
        //Post: devuelve un set con los niveles de estudios únicos del distrito introducido

        /**
     * \brief Obtiene los promedios de nivel de estudios por distrito en un año específico.
     *
     * Este método devuelve un vector con los promedios de nivel de estudios por distrito.
     *
     * \return Un vector de tipo `double` con los promedios de nivel de estudios por distrito.
     */

        vector<double> resumNivellEstudis() const;
        //Pre: --
        //Post: devuelve un vector con los promedios de nivel de estudios de cada distrito de un año

         /**
     * \brief Obtiene un resumen de las nacionalidades por distrito en un año.
     *
     * Este método devuelve un mapa con las nacionalidades de los habitantes, donde cada clave es una tupla
     * de la nacionalidad y el distrito, y el valor es el número de habitantes de esa nacionalidad en ese distrito.
     *
     * \return Un mapa con las nacionalidades de los habitantes en un año determinado.
     */

        map<pair<string, int>, long> resumNacionalitats() const;
        //Pre: --
        //Post: devuelve un set con las nacionalidades de los distritos de un año

        /**
     * \brief Obtiene el distrito con la mayor concentración de una nacionalidad.
     *
     * Este método devuelve el distrito con la mayor concentración de habitantes de una nacionalidad específica.
     *
     * \param codiNacionalitat El código de la nacionalidad a consultar.
     * \return El código del distrito con la mayor concentración de habitantes de esa nacionalidad.
     */

        int maxNacionalitat(int codiNacionalitat) const;
        //Pre: codiNacionalitat es un código de nacionalidad del padrón
        //Post: devuelve un int con el número del distrito con mayor concentración de habitantes de esa nacionalidad

        /**
     * \brief Obtiene el distrito con la mayor media de edad en un año específico.
     *
     * Este método devuelve el índice del distrito con la mayor media de edad de la población en el año especificado.
     *
     * \param any El año para el cual se desea obtener el distrito con la mayor media de edad.
     * \return El índice del distrito con la mayor media de edad en el año.
     */

        int maxEdat(int any) const;
        //Pre: --
        //Post: devuelve el índice del distrito con mayor media de edad de ese año

        /**
     * \brief Obtiene los incrementos en el número de jóvenes entre años.
     *
     * Este método devuelve un vector con los incrementos en el número de jóvenes en cada distrito, comparando
     * dos años consecutivos.
     *
     * \param any El año para el cual se desea calcular el incremento de jóvenes.
     * \return Un vector de tipo `long` con el incremento en el número de jóvenes por distrito.
     */

        vector<long> incrementJoves(int any) const;

        /**
     * \brief Obtiene los estudios de habitantes en un año, distrito, edad y nacionalidad específicos.
     *
     * Este método devuelve una lista de los estudios de los habitantes que cumplen las condiciones especificadas
     * (año, distrito, edad y nacionalidad).
     *
     * \param any El año de los habitantes.
     * \param districte El código del distrito de los habitantes.
     * \param edat La edad de los habitantes.
     * \param CodiNacionalitat El código de la nacionalidad de los habitantes.
     * \return Una lista de los estudios de los habitantes que cumplen las condiciones.
     */

        list<string> estudisEdat(int any, int districte, int edat, int CodiNacionalitat) const;

    private:

        /**
     * \brief Almacena los distritos con la información de los habitantes.
     *
     * Este vector contiene 7 objetos de tipo `Districte`, cada uno representando un distrito
     * y sus habitantes.
     */
        vector<Districte> vecDistrictes;  //Almacena los distritos
};

#endif // ANY_H
