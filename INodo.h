#ifndef _INODO_
#define _INODO_ 1
#include <iostream>
#include <string>
using namespace std;

class INodo
{
protected:
    int id;
    string nombre;

public:
    int getId()
    {
        return id;
    }

    void setId(int pId)
    {
        this->id = pId;
    }

    string getNombre()
    {
        return this->nombre;
    }

    void setNombre(string pNombre)
    {
        this->nombre = pNombre;
    }
};

#endif