#ifndef ARCHIVOS_H
#define ARCHIVOS_H
using namespace std;
#include <string>
#include <vector>
#include <fstream>
class Archivo{
    private:
        string nombre; //Nombre del archivo que se queire abrir
        vector<vector<string>> datos; //Datos extraidos de cada linea de texto del archivo.
    public:
        Archivo(const string&nombre); //Constructor.
        bool leerArchivo(); //Función que permite leer el archivo.
        vector<string> procesarCadena(const string&cadena) const; //Procesa cada linea de texto y obtiene los datos necesarios.
        const vector<vector<string>> &getDatos() const; //Getter para los datos extraidos.
};

#endif //ARCHIVOS_H