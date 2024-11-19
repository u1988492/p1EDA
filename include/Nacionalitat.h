/**
 * \file Nacionalitat.h
 * \brief Define la clase Nacionalitat para gestionar la información sobre nacionalidades.
 *
 * La clase `Nacionalitat` representa una nacionalidad asociada a una persona,
 * identificada por un código y un nombre.
 */

#ifndef NACIONALITAT_H
#define NACIONALITAT_H

#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

/**
 * \class Nacionalitat
 * \brief Clase que representa una nacionalidad.
 *
 * La clase `Nacionalitat` se utiliza para almacenar y gestionar la información de una nacionalidad,
 * incluyendo un identificador y el nombre de la nacionalidad.
 */

class Nacionalitat
{
    public:
        /**
     * \brief Constructor de la clase Nacionalitat.
     *
     * Inicializa un objeto `Nacionalitat` con un identificador y un nombre.
     *
     * \param id Código de la nacionalidad.
     * \param nom Nombre de la nacionalidad.
     */
        Nacionalitat(int id, string nom);

        /**
     * \brief Obtiene el código de la nacionalidad.
     *
     * \return El código de la nacionalidad como un valor entero (`int`).
     */
        int obtenirId() const;

        /**
     * \brief Obtiene el nombre de la nacionalidad.
     *
     * \return El nombre de la nacionalidad como una cadena (`string`).
     */
        string obtenirNom() const;

        /**
     * \brief Operador de igualdad para comparar dos objetos `Nacionalitat`.
     *
     * Compara dos objetos `Nacionalitat` para determinar si tienen el mismo código y nombre de nacionalidad.
     *
     * \param nacio Objeto `Nacionalitat` con el que se comparará.
     * \return `true` si ambos objetos tienen el mismo código y nombre; de lo contrario, `false`.
     */
        bool operator==(const Nacionalitat &nacio) const;

    private:
        int codiNacionalitat; /**< Código de la nacionalidad */
        string nacionalitat; /**< Nombre descriptivo de la nacionalidad */

};

#endif // NACIONALITAT_H
