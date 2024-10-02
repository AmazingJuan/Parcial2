#ifndef NODO_H
#define NODO_H

#include "tienda.h"  // Incluimos la definición de la clase Tienda

class Nodo {
    private:
        Tienda tienda;   // La tienda se almacena en esta variable.
        Nodo* next;  // Puntero al siguiente nodo
    public:
        // Constructor: Inicializa un nodo con una tienda
        Nodo(const Tienda& p);

        // Getters y setters
        const Tienda &getTienda() const;
        void setTienda(const Tienda& p);
        Nodo* getNext() const;
        void setNext(Nodo* n);
};

#endif