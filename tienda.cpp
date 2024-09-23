#include "tienda.h"
#include <cmath>
Tienda::Tienda(string nombre, string barrio, float latitud, float longitud): nombre(nombre), barrio(barrio), latitud(latitud), longitud(longitud){}

const string &Tienda::getNombre() const
{
    return nombre;
}

float getDistance(const Tienda &tienda1, const Tienda &tienda2)
{
    double lat1_rad = tienda1.latitud * M_PI / 180.0;
    double lat2_rad = tienda2.latitud * M_PI / 180.0;
    double delta_lat = (lat2_rad - lat1_rad) * M_PI/180.;
    double delta_lon = (tienda1.longitud - tienda2.longitud) * M_PI / 180.0;

    double a = sin(delta_lat / 2) * sin(delta_lat / 2) +
               cos(lat1_rad) * cos(lat2_rad) *
               sin(delta_lon / 2) * sin(delta_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance_km = 6371.0 * c;

    return distance_km * 1000;
}
