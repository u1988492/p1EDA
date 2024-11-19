/**
 * \file Persona.h
 * \brief Define la clase Persona para gestionar información individual sobre habitantes.
 *
 * La clase `Persona` representa a un habitante, almacenando datos como el año de nacimiento,
 * nivel de estudios y nacionalidad.
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Estudi.h"
#include "Nacionalitat.h"

using namespace std;


/**
 * \class Persona
 * \brief Clase que representa a una persona con atributos como año de nacimiento, estudios y nacionalidad.
 *
 * La clase `Persona` se utiliza para almacenar y gestionar la información relevante de un habitante,
 * incluyendo su nivel de estudios y nacionalidad.
 */
class Persona
{
    public:
        /**
     * \brief Constructor de la clase Persona.
     *
     * Inicializa un objeto `Persona` con los datos proporcionados.
     *
     * \param codiNivellEstudis Código del nivel de estudios de la persona.
     * \param nivellEstudis Nombre del nivel de estudios de la persona.
     * \param anyNaixement Año de nacimiento de la persona.
     * \param codiPaisNaixement Código del país de nacimiento de la persona.
     * \param paisNaixement Nombre del país de nacimiento de la persona.
     */
        Persona(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiPaisNaixement, const string &paisNaixement);

        /**
     * \brief Muestra los datos de la persona por consola.
     *
     * Imprime los detalles de la persona, como su año de nacimiento, estudios y nacionalidad.
     */
        void mostraPersona() const;

        /**
     * \brief Obtiene el año de nacimiento de la persona.
     *
     * \return El año de nacimiento como un valor entero (`int`).
     */
        int obtenirAnyNaixement() const;

        /**
     * \brief Obtiene el nivel de estudios de la persona.
     *
     * \return El nivel de estudios como una cadena (`string`).
     */
        string obtenirNivellEstudis() const;

        /**
     * \brief Obtiene el código del nivel de estudios de la persona.
     *
     * \return El código del nivel de estudios como un valor entero (`int`).
     */
        int obtenirCodiNivellEstudis() const;

        /**
     * \brief Obtiene la nacionalidad de la persona.
     *
     * \return La nacionalidad como una cadena (`string`).
     */
        string obtenirNacionalitat() const;

        /**
     * \brief Obtiene el código del país de nacimiento de la persona.
     *
     * \return El código del país de nacimiento como un valor entero (`int`).
     */
        int obtenirCodiPaisNaixement() const;

    private:
        int a_anyNaixement; /**< Año de nacimiento de la persona */
        Estudi a_estudis; /**< Objeto que representa el nivel de estudios de la persona */
        Nacionalitat a_nacionalitat; /**< Objeto que representa la nacionalidad de la persona */

};

#endif // PERSONA_H
