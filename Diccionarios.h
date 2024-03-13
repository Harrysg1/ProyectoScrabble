#ifndef DICCIONARIOS_H
#define DICCIONARIOS_H

#include <list>
#include <vector>
#include <string>
#include"indice.h"

class Diccionarios
{
private:
  bool diccionarioInicializado = false;
    std::list < indice > indices;

public:
  void inicializarDiccionario (std::string rutaArchivo);	// punto 1 Eduardo
  bool puntajePalabra (std::string palabra);	//punto 3 Harry 
  void ayuda (std::string x);	// Caicedo
};

#endif // DICCIONARIOS_H
