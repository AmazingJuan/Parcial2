#include "grafo.h"
#include <vector>
#include "tienda.h"
#include <iostream>
#include <algorithm>
using namespace std;

#define infinito 100000

Grafo::Grafo(const vector<vector<string>> &datos)
{
    for(unsigned short contador; contador < datos.size(); contador++){
        tabla_tiendas.push_back(Tienda(datos[contador][0], datos[contador][1], stof(datos[contador][2]), stof(datos[contador][3])));
    }

    matriz_adjacencia = new float*[tabla_tiendas.size()];
    for(unsigned short contador; contador < tabla_tiendas.size(); contador++){
        matriz_adjacencia[contador] = new float[tabla_tiendas.size()];
    }

    for(unsigned short contador; contador < tabla_tiendas.size(); contador++){
        matriz_adjacencia[contador][contador] = 0;
        for(unsigned short contador2 = contador; contador2  < tabla_tiendas.size(); contador2++){
            if(contador != contador2){
                Tienda aux = tabla_tiendas[contador];
                Tienda aux2 = tabla_tiendas[contador2];
                float distancia = getDistance(aux, aux2);
                if(distancia <= 1500){
                    matriz_adjacencia[contador][contador2] = distancia;
                    matriz_adjacencia[contador2][contador] = matriz_adjacencia[contador][contador2];
                }
                else{
                    matriz_adjacencia[contador][contador2] = infinito;
                    matriz_adjacencia[contador2][contador] = infinito;
                }
            }
        }
    }
}

void Grafo::dijkstra(int index)
{
    int n = tabla_tiendas.size();
    vector<float> distances(n, infinito);
    vector<int> previous(n, -1);
    vector<bool> visited(n, false);
    
    distances[index] = 0;

    for (int i = 0; i < n - 1; i++) {
        // Encontrar el nodo no visitado con la distancia más corta
        float minDistance = infinito;
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                u = j;
            }
        }

        // Marcar el nodo como visitado
        visited[u] = true;

        // Actualizar las distancias de los nodos adyacentes
        for (int v = 0; v < n; v++) {
            if (matriz_adjacencia[u][v] >= 0 && !visited[v]) { // hay un camino desde u a v
                float newDist = distances[u] + matriz_adjacencia[u][v];
                if (newDist < distances[v]) {
                    distances[v] = newDist;
                    previous[v] = u; // Rastrear el camino
                }
            }
        }
    }

    // Imprimir distancias y caminos
    for (int i = 0; i < n; i++) {
        cout << "Distancia desde el nodo " << index << " al nodo " << i << ": ";
        if (distances[i] == infinito) {
            cout << "INFINITO" << endl;
        } else {
            cout << distances[i] << endl;
            cout << "Camino: ";
            vector<int> path;
            for (int at = i; at != -1; at = previous[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end()); // Invertir el camino
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
}
