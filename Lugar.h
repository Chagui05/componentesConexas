#ifndef _LUGAR_
#define _LUGAR_ 1

#include <iostream>
#include <string>
using namespace std;
#include "INodo.h"

using namespace std;

class Lugar : public INodo {
    public:
        Lugar(string pNombre) {
            this->setId(rand()*99999999999);
            this->nombre = pNombre;
        }

    private:
};

#endif