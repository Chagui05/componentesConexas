#ifndef _LUGAR_
#define _LUGAR_ 1

#include <iostream>
#include "INodo.h"

using namespace std;

class Lugar : public INodo {
    public:
        Lugar(string pNombre) {
            this->setId(rand()*99999999999);
            nombre = pNombre;
        }

        string getNombre() {
            return this->nombre;
        }

        void setNombre(string pNombre) {
            this->nombre = pNombre;
        }

    private:
        string nombre;
};

#endif