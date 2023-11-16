#include <iostream>
#include "grafo.h"
#include "Lugar.h"
#include "GraphDiscover.h"
#include "QuestionSolver.h"
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

    grafo.addArc(&argentina,&uruguay, 2);   //primer cierre de argetina-uruguay-brasil-bolivia-paraguay-argentina
    grafo.addArc(&uruguay,&argentina, 2);
    grafo.addArc(&argentina,&chile, 4);
    grafo.addArc(&chile,&argentina, 4);
    grafo.addArc(&argentina,&bolivia, 5);
    grafo.addArc(&bolivia,&brasil, 3);
    grafo.addArc(&uruguay,&brasil, 1);
    grafo.addArc(&brasil,&bolivia, 2);
    grafo.addArc(&bolivia,&paraguay, 2);
    grafo.addArc(&paraguay,&argentina, 2);
    grafo.addArc(&bolivia,&peru, 4);
    grafo.addArc(&chile,&peru, 3);
    grafo.addArc(&peru,&ecuador, 2);      //segundo cierre de peru-ecuador-colombia-venezuela-brasil-peru
    grafo.addArc(&peru,&brasil, 2);
    grafo.addArc(&brasil,&colombia, 2);
    grafo.addArc(&brasil,&peru, 2);
    grafo.addArc(&ecuador,&colombia, 2);
    grafo.addArc(&colombia,&panama, 20);
    grafo.addArc(&colombia,&venezuela, 2);
    grafo.addArc(&venezuela,&brasil, 2);
    grafo.addArc(&panama,&costaRica, 2);
    grafo.addArc(&costaRica,&nicaragua, 2);
    grafo.addArc(&nicaragua,&honduras, 2);
    grafo.addArc(&honduras,&elSalvador, 2);
    grafo.addArc(&elSalvador,&guatemala, 2);
    grafo.addArc(&guatemala,&mexico, 2);
    grafo.addArc(&mexico,&estadosUnidos, 2);
    





    GraphDiscover gd = GraphDiscover();

    NodoGrafo *nodo1 = grafo.getNodo(argentina.getId());
    NodoGrafo *nodo2 = grafo.getNodo(peru.getId());

    QuestionSolver qs = QuestionSolver();

//DJISTRA:
    // qs.printLeastTimeFromOneCOuntryToOther(nodo1, nodo2, &grafo);

//WARSHALL:
    vector<Path *> *wasrshalPaths = gd.getPathsByWarshall(nodo1, nodo2, &grafo);

    // for(int j = 0 ; j < wasrshalPaths->size(); j++){
        
    //     for(int k = 0; k < wasrshalPaths->at(j)->path.size(); k++){
    //         cout <<wasrshalPaths->at(j)->path.at(k)->getInfo()->getNombre()  << endl;
    //     }
    //     cout << "----------------" << endl;
    // }
    // vector<INodo *> result = grafo.broadPath(&estadosUnidos);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     Lugar dato = *((Lugar *)(void *)result[i]);
    //     cout << dato.getId() << " " << dato.getNombre() << endl;
    // }
}