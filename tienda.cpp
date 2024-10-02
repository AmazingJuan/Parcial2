#include "tienda.h"
#include <cmath>
const double PI = 3.14159265358979323846;
const double RADIO_TIERRA = 6371.0; // Radio de la Tierra en kilómetros

Tienda::Tienda(string nombre, string barrio, float latitud, float longitud): nombre(nombre), barrio(barrio), latitud(latitud), longitud(longitud){}

const string &Tienda::getNombre() const
{
    return nombre;
}

float getDistance(const Tienda &tienda1, const Tienda &tienda2)
{
    double lat1 = tienda1.latitud * PI / 180.0;
    double lon1 = tienda1.longitud * PI / 180.0;
    double lat2 = tienda2.latitud * PI / 180.0;
    double lon2 = tienda2.longitud * PI / 180.0;

    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;

    double a = std::sin(dlat/2) * std::sin(dlat/2) + std::cos(lat1) * std::cos(lat2) * std::sin(dlon/2) * std::sin(dlon/2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));

    return RADIO_TIERRA * c;
}
