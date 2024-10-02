#ifndef GRAFO_H
#define GRAFO_H
#include <string>
#include <vector>
#include "tienda.h"
#include "nodo.h"

class Grafo{
    private:
        vector<Nodo*> nodos_tiendas; //Vector para almacenar los nodos que contienen las tiendas.
        float** matriz_adjacencia; //Matriz donde se almacenarán los pesos.
        //Indices correspondientes a la tienda sur y la tienda norte..
        const int index_sur = 16;
        const int index_norte = 0;
    public:
        Grafo(const vector<vector<string>> &datos); //Constructor.
        ~Grafo(); //Destructor
        int encontrarMinimo(vector<int> &lista, int indice_actual); //Funcion para encontrar la tienda de minima distancia a una tienda dada.
        void optimizarLogistica(); //Función que hace una aproximación del problema del agente viajero con dos origenes, e imprime los resultados.      
};
#endif //GRAFO_H
