#include <iostream>
#include "grafo.h"
#include "Lugar.h"
#include "GraphDiscover.h"
#include <vector>
#include <string>
using namespace std;

int main()
{
    Grafo grafo(true);

    Lugar argentina = Lugar("Argentina");
    Lugar brasil = Lugar("Brasil");
    Lugar chile = Lugar("Chile");
    Lugar uruguay = Lugar("Uruguay");
    Lugar paraguay = Lugar("Paraguay");
    Lugar bolivia = Lugar("Bolivia");
    Lugar colombia = Lugar("colombia");
    Lugar venezuela = Lugar("venezuela");
    Lugar ecuador = Lugar("ecuador");
    Lugar peru = Lugar("peru");
    Lugar panama = Lugar("panama");
    Lugar costaRica = Lugar("costaRica");
    Lugar nicaragua = Lugar("nicaragua");
    Lugar honduras = Lugar("honduras");
    Lugar elSalvador = Lugar("elSalvador");
    Lugar guatemala = Lugar("guatemala");
    Lugar mexico = Lugar("mexico");
    Lugar estadosUnidos = Lugar("estadosUnidos");

    Lugar allPlaces[] = {argentina, brasil, chile, uruguay,paraguay,bolivia,
                        colombia,venezuela,ecuador,peru,panama,costaRica,
                        nicaragua,honduras,elSalvador,guatemala,mexico,estadosUnidos};

    for (Lugar &i : allPlaces)
    {
        grafo.addNode(&i);
    }
    //peso es el tiempo en horas llegando en tren

    grafo.addArc(&venezuela,&colombia, 4);
    grafo.addArc(&argentina, &uruguay, 8);
    grafo.addArc(&argentina, &chile, 3);
    

    grafo.addArc(&uruguay,&brasil, 3);
    grafo.addArc(&uruguay,&paraguay,3);

    grafo.addArc(&paraguay,&bolivia, 7);
    grafo.addArc(&chile,&bolivia, 10);
    grafo.addArc(&bolivia,&peru, 14);

    grafo.addArc(&peru,&ecuador, 5);
    grafo.addArc(&ecuador,&colombia, 1);
    grafo.addArc(&peru,&colombia, 2);

    grafo.addArc(&colombia,&panama, 40);
    grafo.addArc(&panama,&costaRica, 10);
    grafo.addArc(&costaRica,&nicaragua,3 );
    grafo.addArc(&nicaragua,&honduras, 6);
    grafo.addArc(&honduras,&elSalvador, 5);
    grafo.addArc(&elSalvador,&guatemala, 7);
    grafo.addArc(&guatemala,&mexico, 8);
    grafo.addArc(&estadosUnidos,&mexico, 2);
    grafo.addArc(&mexico,&estadosUnidos, 2);


    GraphDiscover gd = GraphDiscover();

    NodoGrafo *nodo1 = grafo.getNodo(argentina.getId());
    NodoGrafo *nodo2 = grafo.getNodo(estadosUnidos.getId());

    Path * newPath = gd.getShorterPath(nodo1, nodo2, &grafo);


    for(int k = 0; k < newPath->path.size(); k++){
        cout <<newPath->path.at(k)->getInfo()->getNombre()  << endl;
    }
    // vector<INodo *> result = grafo.broadPath(&estadosUnidos);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     Lugar dato = *((Lugar *)(void *)result[i]);
    //     cout << dato.getId() << " " << dato.getNombre() << endl;
    // }
}