#include "archivos.h"
#include "grafo.h"
#include <iostream>
int main(){
    Archivo archivo("tiendas.txt");
    archivo.leerArchivo();
    Grafo tiendas(archivo.getDatos());
    tiendas.dijkstra(0);
    tiendas.dijkstra(9);
    for(int cont = 0; cont < tiendas.caminos_norte.size(); cont++){
        cout << "Caminos desde china hasta " << tiendas.caminos_norte[cont][tiendas.caminos_norte[cont].size() - 1].getNombre();
        for(int j = 0; j < tiendas.caminos_norte[cont].size(); j++){
            cout << tiendas.caminos_norte[cont][j].getNombre();
            if(j > 0) cout << "->";
        }
    }


}