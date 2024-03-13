
#include <iostream>
#include <sstream>
#include "Diccionarios.h"
#include "Palabra.h"
#include "indice.h"
#include "DiccionarioInverso.h"

using namespace std; 
int main() {
    Diccionarios sistema1;// aqui se crea la instancia sistema
    DiccionarioInverso sistema2;
    string linea; // donde se guarda las lineas 
    string comando;
    string argumento;

    while (true) {
        cout << "$";
        getline(cin, linea);
        istringstream stream(linea);
        stream >> comando;

      // no se puede usar un swicht case con string entonces toca con if or else if 


        if (comando == "salir") {
            break;
        } else if (comando == "inicializar" || comando == "iniciar_inverso" || comando == "puntaje"|| comando == "ayuda") {
            stream >> argumento;
            if (comando == "ayuda") {
                sistema1.ayuda(argumento);
            }else if (comando == "inicializar"){
              sistema1.inicializarDiccionario(argumento);
            } else if (comando == "iniciar_inverso") {
                sistema2.inicializarInverso(argumento);
            } else if (comando == "puntaje") {
                if(!sistema1.puntajePalabra(argumento)){
                    if(!sistema2.puntajePalabra(argumento)){
                        cout<<"la palabra no existe en el diccionario"<<endl;
                    }
                }
            }
        } else {
            cout << "Comando no reconocido." <<endl;
        }
    }

    return 0;
}
