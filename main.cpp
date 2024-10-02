#include "archivos.h"
#include "grafo.h"
#include <iostream>
int main(){
    Archivo archivo("tiendas.txt"); //Se crea una instancia de la clase archivo con el archivo "tiendas.txt".
    if(archivo.leerArchivo()){
        Grafo tiendas(archivo.getDatos()); //Crea un grafo, con los datos recopilados en la lectura del archivo.
        tiendas.optimizarLogistica(); //Se ejecuta el metodo optimizar logistica, el cual imprime los resultados obtenidos.
    }
    else{
        cout << "No se puede hacer la optimización de la logistica, no se pudieron cargar las tiendas....... " << endl;
    }


}