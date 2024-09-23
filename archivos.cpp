#include "archivos.h"
#include <iostream>
Archivo::Archivo(const string& nombre)
{
    this->nombre = nombre;
}

bool Archivo::leerArchivo()
{
    ifstream archivo(nombre); //Se crea una instancia de ifstream dandole un nombre de archivo para abrir.
    if(archivo.is_open()){ //Si el archivo se abrio correctamente se ejecuta el siguiente bloque
        string textoAux; //Almacenará el texto de cada linea

        while(getline(archivo,textoAux)) datos.push_back(procesarCadena(textoAux)); //Se introduce al vector de items cada linea de texto.
        archivo.close(); //Se cierra el archivo finalmente.
        return true; //Dado que las operaciones se completaron satisfactoriamente se retorna true.
    }
    else{
        return false; //Como el archivo no se abrio se devuelve falso.
    }
}

vector<string> Archivo::procesarCadena(const string &cadena) const
{
    bool finished = 0;
    vector<string> datos;
    unsigned short cont = 0;
    string stringAux = "";
    while(!finished){
        if(cadena.at(cont) == ',' || cont == cadena.length() - 1){
            if(cont == cadena.length() - 1) {
                finished = true;
                stringAux += cadena.at(cont);
            }
            datos.push_back(stringAux);
            stringAux = "";
        }
        else stringAux += cadena.at(cont);
        
        cont += 1;
    }
    return datos;
}

const vector<vector<string>> &Archivo::getDatos() const
{
    return datos;
}
