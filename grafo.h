#ifndef GRAFO_H
#define GRAFO_H
#include <string>
#include <vector>
#include "tienda.h"

class Grafo{
    private:
        vector<Tienda> tabla_tiendas;
        int index_sur;
        int index_norte;
        float** matriz_adjacencia;
    public:
        vector<vector<Tienda>> caminos_norte;
        vector<vector<Tienda>> caminos_sur;
        Grafo(const vector<vector<string>> &datos);
        void dijkstra(int index);
        
};

#endif //GRAFO_H