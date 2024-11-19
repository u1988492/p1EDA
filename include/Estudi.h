/**
 * \file Estudi.h
 * \brief Define la clase Estudi para gestionar información sobre los niveles de estudios.
 *
 * La clase `Estudi` representa un nivel de estudios asociado a una persona,
 * identificada por un código y un nombre descriptivo.
 */

#ifndef ESTUDI_H
#define ESTUDI_H

#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

/**
 * \class Estudi
 * \brief Clase que representa un nivel de estudios.
 *
 * La clase `Estudi` se utiliza para almacenar y gestionar la información de un nivel de estudios,
 * incluyendo un identificador y el nombre del nivel.
 */

class Estudi
{
    public:

        /**
     * \brief Constructor de la clase Estudi.
     *
     * Inicializa un objeto `Estudi` con un identificador y un nombre.
     *
     * \param id Código del nivel de estudios.
     * \param nom Nombre del nivel de estudios.
     */
        Estudi(int id, string nom);

        /**
     * \brief Obtiene el código del nivel de estudios.
     *
     * \return El código del nivel de estudios como un valor entero (`int`).
     */
        int obtenirId() const;

        /**
     * \brief Obtiene el nombre del nivel de estudios.
     *
     * \return El nombre del nivel de estudios como una cadena (`string`).
     */
        string obtenirNom() const;

        /**
     * \brief Operador de igualdad para comparar dos objetos `Estudi`.
     *
     * Compara dos objetos `Estudi` para determinar si tienen el mismo código y nombre de nivel de estudios.
     *
     * \param estudi Objeto `Estudi` con el que se comparará.
     * \return `true` si ambos objetos tienen el mismo código y nombre; de lo contrario, `false`.
     */
        bool operator==(const Estudi &estudi) const;

    private:
        int codiNivellEstudis; /**< Código del nivel de estudios */
        string nivellEstudis; /**< Nombre descriptivo del nivel de estudios */

};

#endif // ESTUDI_H
