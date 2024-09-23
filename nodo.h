#ifndef NODO_H
#define NODO_H

#include "tienda.h"  // Incluimos la definición de la clase Pais

class Nodo {
private:
    Tienda tienda;   // El país almacenado en este nodo
    Nodo* next;  // Puntero al siguiente nodo en la lista enlazada

public:
    // Constructor: Inicializa un nodo con un país
    Nodo(const Tienda& t);

    // Getters y setters
    const Tienda &getTienda() const;
    void setTienda(const Tienda& p);
    Nodo* getNext() const;
    void setNext(Nodo* n);
};

#endif