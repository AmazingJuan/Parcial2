#include "nodo.h"

// Constructor: Inicializa un Nodo con un país y establece el siguiente como nullptr
Nodo::Nodo(const Tienda& p) : tienda(p), next(nullptr) {}

// Getter: Devuelve el país almacenado en el Nodo
const Tienda &Nodo::getTienda() const { return tienda; }

// Setter: Establece el país del Nodo
void Nodo::setTienda(const Tienda& t) { tienda = t; }

// Getter: Devuelve el puntero al siguiente Nodo
Nodo* Nodo::getNext() const { return next; }

// Setter: Establece el puntero al siguiente Nodo
void Nodo::setNext(Nodo* n) { next = n; }