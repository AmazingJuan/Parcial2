#ifndef TIENDA_H
#define TIENDA_H
#include <string>
using namespace std;

class Tienda{
    private:
        string nombre;
        string barrio;
        float latitud;
        float longitud;
    public:
        Tienda(string nombre, string barrio, float latitud, float longitud);
        const string &getNombre() const;
        friend float getDistance(const Tienda&tienda1, const Tienda&tienda2);
};

#endif //TIENDA_H