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
    bool finished = 0; //Booleano que indica si ya se ha terminado de procesar la cadena o no
    vector<string> datos; //Vector donde se almacenarán los datos de la cadena.
    unsigned short cont = 0; //Contador auxiliar.
    string stringAux = ""; //String auxiliar.
    while(!finished){
        //Loop que va a procesar la cadena, metiendo datos al vector de datos si es que se encuentra
        //una coma, o bien se termina la cadena.
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
    return datos; //Se devuelven los datos extraidos.
}

const vector<vector<string>> &Archivo::getDatos() const
{
    return datos;
}
