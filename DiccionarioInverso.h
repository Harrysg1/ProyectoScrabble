#ifndef DICCIONARIOINVERSO_H
#define DICCIONARIOINVERSO_H

#include <list>
#include <vector>
#include <string>
#include"indice.h"

class DiccionarioInverso {
private:

    bool diccionarioInversoInicializado = false;
    std::list<indice>indices;

public:
    void inicializarInverso(std::string rutaArchivo);
    bool puntajePalabra( std::string palabra);
    
};

#endif // DICCIONARIOSINVERSO_H

