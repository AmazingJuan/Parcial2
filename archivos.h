#ifndef ARCHIVOS_H
#define ARCHIVOS_H
using namespace std;
#include <string>
#include <vector>
#include <fstream>
class Archivo{
    private:
        string nombre;
        vector<vector<string>> datos;
    public:
        Archivo(const string&nombre);
        bool leerArchivo();
        vector<string> procesarCadena(const string&cadena) const;
        const vector<vector<string>> &getDatos() const;
};

#endif