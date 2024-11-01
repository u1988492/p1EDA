#ifndef ESTUDI_H
#define ESTUDI_H

#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

class Estudi
{
    public:
        Estudi(int id, string nom);
        int obtenirId() const;
        string obtenirNom() const;
        bool operator==(const Estudi &estudi) const;

    private:
        int codiNivellEstudis;
        string nivellEstudis;

};

#endif // ESTUDI_H
