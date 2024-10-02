#ifndef TIENDA_H
#define TIENDA_H
#include <string>
using namespace std;

class Tienda{
    private:
        string nombre; //Nombre de la tienda.
        string barrio; //Barrio
        float latitud; 
        float longitud;
    public:
        Tienda(string nombre, string barrio, float latitud, float longitud); //Constructor.
        const string &getNombre() const; //Getter del nombre de la tienda
        friend float getDistance(const Tienda&tienda1, const Tienda&tienda2); //Función que calcula la distancia entre dos tiendas dadas.
};

#endif //TIENDA_H