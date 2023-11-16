#ifndef _GRAPHDISCOVER_
#define _GRAPHDISCOVER_ 1

#include <iostream>
#include <vector>
#include <map>
#include "NodoGrafo.h"
#include "grafo.h"

using namespace std;

struct Path
{
    NodoGrafo *origen = nullptr;
    NodoGrafo *destino = nullptr;
    int peso;

    vector<NodoGrafo *> path;
};

struct DistancePath
{
    NodoGrafo *keyNode = nullptr;
    NodoGrafo *LastNodo = nullptr;
    bool procesado = false;
    int peso = 999999999;
};

class GraphDiscover
{
public:
    vector<Path *> *getPathsByWarshall(NodoGrafo *pOrigen, NodoGrafo *pDestino, Grafo *pGrafo) {
        int numNodes = pGrafo->getSize();
        vector<vector<bool>> adjacencyMatrix(numNodes, vector<bool>(numNodes, false));

        for (auto node : *(pGrafo->getListaNodos())) {
            for (auto arc : *(node->getArcs())) {
                int originId = ((NodoGrafo *)arc->getOrigen())->getInfo()->getId();
                int destId = ((NodoGrafo *)arc->getDestino())->getInfo()->getId();
                adjacencyMatrix[originId][destId] = true;
            }
        }

        for (int k = 0; k < numNodes; k++) {
            for (int i = 0; i < numNodes; i++) {
                for (int j = 0; j < numNodes; j++) {
                    adjacencyMatrix[i][j] = adjacencyMatrix[i][j] || (adjacencyMatrix[i][k] && adjacencyMatrix[k][j]);
                }
            }
        }
        
        vector<Path *> *resultPaths = new vector<Path *>();

        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (adjacencyMatrix[i][j]) {
                    Path *path = new Path();
                    path->origen = pGrafo->getNodo(i);
                    path->destino = pGrafo->getNodo(j);
                    path->peso = 0;  // You might need to adjust this based on your requirements

                    // Construct the path
                    int currentNode = i;
                    while (currentNode != j) {
                        path->path.push_back(pGrafo->getNodo(currentNode));
                        for (int nextNode = 0; nextNode < numNodes; nextNode++) {
                            if (adjacencyMatrix[currentNode][nextNode] && adjacencyMatrix[nextNode][j]) {
                                currentNode = nextNode;
                                break;
                            }
                        }
                    }
                    path->path.push_back(pGrafo->getNodo(j));

                    resultPaths->push_back(path);
                }
            }
        }
            return resultPaths;

        
       
    }

    Path *getShorterPath(NodoGrafo *pOrigen, NodoGrafo *pDestino, Grafo *pGrafo)
    {
        vector<DistancePath *> pendingNodesV;
        vector<DistancePath *> processedNodesF;
        DistancePath *currentMin;

        // Initialization
        for (auto &node : *(pGrafo->getListaNodos()))
        {
            DistancePath *distanceNode = new DistancePath();
            distanceNode->keyNode = node;
            pendingNodesV.push_back(distanceNode);
        }

        // Set the distance of the origin to 0
        getDistancePathNode(pOrigen, &pendingNodesV)->peso = 0;

        while (!pendingNodesV.empty())
        {
            // Get the node with the minimum distance from pendingNodesV
            currentMin = extractMin(&pendingNodesV);

            // Mark the node as processed
            processedNodesF.push_back(currentMin);

            // Relaxation step
            relaxNeighbors(currentMin, &pendingNodesV);
        }

        // Build the result path
        Path *resultPath = new Path();
        resultPath->origen = pOrigen;
        resultPath->destino = pDestino;
        resultPath->peso = getDistancePathNode(pDestino, &processedNodesF)->peso;

        // Reconstruct the path
        reconstructPath(pDestino, resultPath, &processedNodesF);

        return resultPath;
    }

private:
    

    DistancePath *getDistancePathNode(NodoGrafo *node, vector<DistancePath *> *nodes)
    {
        for (auto &distanceNode : *nodes)
        {
            if (distanceNode->keyNode == node)
            {
                return distanceNode;
            }
        }
        return nullptr;
    }

    // Helper method to extract the node with the minimum distance from the pending nodes
    DistancePath *extractMin(vector<DistancePath *> *nodes)
    {
        DistancePath *minNode = nodes->front();
        for (auto &node : *nodes)
        {
            if (node->peso < minNode->peso)
            {
                minNode = node;
            }
        }
        nodes->erase(std::remove(nodes->begin(), nodes->end(), minNode), nodes->end());
        return minNode;
    }

    // Helper method to relax the neighbors of a node
    void relaxNeighbors(DistancePath *node, vector<DistancePath *> *nodes)
    {
        vector<Arco *> *adjacentArcs = node->keyNode->getArcs();
        for (auto &arc : *adjacentArcs)
        {
            NodoGrafo *neighbor = (NodoGrafo *)arc->getDestino();
            DistancePath *neighborNode = getDistancePathNode(neighbor, nodes);

            if (neighborNode != nullptr)
            {
                int newDistance = node->peso + arc->getPeso();
                if (newDistance < neighborNode->peso)
                {
                    neighborNode->peso = newDistance;
                    neighborNode->LastNodo = node->keyNode;
                }
            }
        }
    }

    // Helper method to reconstruct the shortest path
    void reconstructPath(NodoGrafo *destino, Path *resultPath, vector<DistancePath *> *processedNodes)
    {
        DistancePath *destNode = getDistancePathNode(destino, processedNodes);
        while (destNode->LastNodo != nullptr)
        {
            resultPath->path.insert(resultPath->path.begin(), destNode->keyNode);
            destNode = getDistancePathNode(destNode->LastNodo, processedNodes);
        }
        resultPath->path.insert(resultPath->path.begin(), destNode->keyNode);
    }
};

#endif