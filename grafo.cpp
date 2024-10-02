#include "grafo.h"
#include <vector>
#include "tienda.h"
#include <iostream>
#include <chrono>
using namespace std;

Grafo::Grafo(const vector<vector<string>> &datos)
{
    //Para este for se crean los nodos de cada tienda.
    for(unsigned short contador = 0; contador < datos.size(); contador++){
        nodos_tiendas.push_back(new Nodo(Tienda(datos[contador][0], datos[contador][1], stof(datos[contador][2]), stof(datos[contador][3]))));
    }
    //Se aloja memoria en el heap para arreglos de float*.
    matriz_adjacencia = new float*[nodos_tiendas.size()];
    //Se aloja para cada fila sus respectivas columnas.
    for(unsigned short contador = 0; contador < nodos_tiendas.size(); contador++){
        matriz_adjacencia[contador] = new float[nodos_tiendas.size()];
    }

    //Se llena la matriz con las distancias.
    for(unsigned short contador = 0; contador < nodos_tiendas.size(); contador++){
        matriz_adjacencia[contador][contador] = 0; //La distancia de una tienda a ella misma es 0
        for(unsigned short contador2 = contador; contador2  < nodos_tiendas.size(); contador2++){
            if(contador != contador2){ //Se verifica que no se asigne la distancia de la misma tienda.
                //Se asigna como peso de conexión entre los nodos, la distancia entre las coordenadas de las tiendas.
                Tienda aux = nodos_tiendas[contador]->getTienda();  
                Tienda aux2 = nodos_tiendas[contador2]->getTienda();
                float distancia = getDistance(aux, aux2); //Se obtiene la distancia entre las tiendas
                //Dado que la matriz es simetrica se ahorra esfuerzo computacional al asignar el mismo valor en [i][j]
                // y [j][i]
                matriz_adjacencia[contador][contador2] = distancia;
                matriz_adjacencia[contador2][contador] = matriz_adjacencia[contador][contador2];
            }
        }
    }
}

Grafo::~Grafo(){
    int cont = 0; //Contador que indica en que fila estamos de la matriz
    while(nodos_tiendas.size() != 0){
        delete[] matriz_adjacencia[cont]; //Se libera la memoria asignada a cada columna.
        delete nodos_tiendas[0]; //Se libera la memoria del nodo 0
        nodos_tiendas.erase(nodos_tiendas.begin()); //Se elimina el nodo 0 del vector, de tal manera que 
        //en la posicion 0 hay un nuevo dato.
        cont++; //Se actualiza el contador.
    }
    delete[] matriz_adjacencia; //Se libera la memoria de las filas.
}

void Grafo::optimizarLogistica(){
    vector<int> indexes_norte; //Se crea un vector donde se almacenarán los indices de las tiendas más cercanas al norte.
    vector<int> indexes_sur; //Se crea un vector donde se almacenarán los indices de las tiendas más cercanas al sur.
    int index_minimo; //Esta variable almacenará el indice en el vector de nodos de la tienda más cercana a la actual.
    //Se inicia la ruta de cada camión en la tienda correspondiente (Sur o norte)
    string camino_norte = nodos_tiendas[index_norte]->getTienda().getNombre();
    string camino_sur = nodos_tiendas[index_sur]->getTienda().getNombre();
    auto inicio = std::chrono::high_resolution_clock::now(); //Se registra el tiempo actual.
    //Este ciclo for separa las tiendas en 2 subconjuntnos, las más proximas al norte y al sur.
    for(int i = 0; i < nodos_tiendas.size();i++){
        if(i != index_norte && i != index_sur){
            if(matriz_adjacencia[index_norte][i] < matriz_adjacencia[index_sur][i]){
                indexes_norte.push_back(i);
            }
            else{
                indexes_sur.push_back(i);
            }
        }
    }


    float distancia1 = 0; //Distancia recorrida por el camión 1 (ida) 
    index_minimo = index_norte; //Se inicializa el index minimo en el indice del norte.
    while(indexes_norte.size() != 0){
        //Se encuentra el indice de la tienda más proxima a la tienda actual de la ruta.
        index_minimo = encontrarMinimo(indexes_norte, index_minimo);
        distancia1 += matriz_adjacencia[index_norte][index_minimo]; //Actualiza el acumulador de distancia.
        camino_norte += " -> " + nodos_tiendas[index_minimo]->getTienda().getNombre(); //Se actualiza la ruta agregando la nueva tienda.
    }
    //El proceso es el mismo para el camión sur.
    float distancia2 = 0;
    index_minimo = index_sur;
    while(indexes_sur.size() != 0){
        index_minimo = encontrarMinimo(indexes_sur, index_minimo);
        distancia2 += matriz_adjacencia[index_sur][index_minimo];
        camino_sur += " -> " + nodos_tiendas[index_minimo]->getTienda().getNombre();
    }
    //Se calcula el tiempo final y se hace la diferencia para obtener el tiempo total.
    auto final = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(final - inicio);
    //Se multiplican las distancias para 
    distancia1 *= 2;
    distancia2 *= 2;
    cout << "--------Optimizacion de logistica D1--------" << endl << endl;
    cout << "Ruta Norte: " << camino_norte << endl << "Distancia recorrida (ida y vuelta): " << distancia1 << endl << endl;
    cout << "Ruta Sur: " << camino_sur << endl << "Distancia recorrida (ida y vuelta): " << distancia2 << endl;
    cout << "Distancia total recorrida por ambos camiones: " << distancia1 + distancia2 << endl << endl;
    cout << "Tiempo utilizado para encontrar las rutas: " << duracion.count() << " milisegundos." << endl;
}

int Grafo::encontrarMinimo(vector<int> &lista, int indice_actual){
    int elemento_minimo = -1; //Elemento de la lista minimo
    int indice_minimo = 0; //Indice de la lista donde se encuentra el elemento minimo
    for(int cont = 0; cont < lista.size();cont++){
        //Se itera sobre toda la lista comparando las distancias entre las tiendas cuyos indices están incluidas en el vector lista.
        //La distancia se toma con respecto a la tienda 'indice_actual'. 
        if(elemento_minimo == -1) {
            elemento_minimo = lista[cont];
            indice_minimo = cont;
        }
        else if(matriz_adjacencia[indice_actual][lista[cont]] < matriz_adjacencia[indice_actual][lista[indice_minimo]]) {
            elemento_minimo = lista[cont];
            indice_minimo = cont;
        }
    }
    lista.erase(lista.begin() + indice_minimo); //Se borra de la lista el elemento minimo, para que no sea incluida en proximas comparaciones.

    return elemento_minimo; //Se retorna el elemento minimo.
}
