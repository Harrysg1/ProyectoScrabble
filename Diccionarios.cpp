#include "Diccionarios.h"
#include"indice.h"
#include<iostream>
#include<fstream>

#include <cctype> 
using namespace std;
void Diccionarios::inicializarDiccionario(std::string rutaArchivo) {
    std::ifstream myfile(rutaArchivo);
    std::string linea;
    int contador=0;

    
    if(!myfile.is_open()){
        cout<<"El archivo no existe"<<endl;
        
    }else if (diccionarioInicializado){
        cout<<"El archivo ya fue ejecutado"<<endl;
        
    } 
    
  
    
    
    if(myfile.is_open() && !diccionarioInicializado){
        contador=0;
        
          while(getline(myfile,linea)){
        
            for (char c: linea) { 
            // 65-90,97-122
                if ((c >=65 && c <= 90 )||( c>=97 && c<= 122 )) {
                }else{
                    contador++;
                }
              
            }
            int encontro =0;
             
            if(contador==0){
                
                list<indice>::iterator it;
                for(it=indices.begin();it!=indices.end();it++){
                   linea[0] = toupper(linea[0]);
                    if(linea[0]==it->getLetra()){//toupper
                        
                        it->agregarPalabra(linea);
                        encontro ++;
                    }
                }
                if(encontro==0){
                    linea[0] = toupper(linea[0]);
                    indice i(linea[0]);//toupper se maneja desde el constructor 
                    i.agregarPalabra(linea);
                    indices.push_back(i);
                }
                
                diccionarioInicializado=true;
            }
        }
        cout<<"El diccionario se ha inicializado correctamente."<<endl;
        
        // impresion:
    /*
        list<indice>::iterator it;
        for(it=indices.begin();it!=indices.end();it++){
            cout<<"\n indice: "<<it->getLetra()<<endl;
            vector<Palabra>aux = it->getPalabras();
            for(Palabra p: aux){
                cout<<p.getPalabra()<<endl;
            }
        }
      */  
    }
    
    
}
bool Diccionarios::puntajePalabra(std::string palabra){
    
    for (char c: palabra) { 
        // 65-90,97-122
        if ((c >=65 && c <= 90 )||( c>=97 && c<= 122 )) {
        }else{
            cout<<"La palabra contiene símbolos inválidos."<<endl;
            return true;
        
        }
              
    }
    
    palabra[0]=toupper(palabra[0]);
    list<indice>::iterator it;
    for(it=indices.begin();it!=indices.end();it++){
        vector<Palabra>aux = it->getPalabras();
        for(Palabra p:aux){
            if(p.getPalabra()==palabra){
                cout<<"la palabra contien un valor de ";
                cout<<p.calcularPuntaje()<<endl;
                return true;
            }
        }
    }
    return false;
}




void Diccionarios::ayuda(string x) {
    if(x=="inicializar"){
        cout<<"Inicaliza el sistema a partir del archivo que desee"<<endl;
        cout<<"Debe recibir un parametro: el nombre del archivo"<<endl;
        cout<<"Ejemplo: inicializar diccionario.txt"<<endl;
    }else if(x== "iniciar_inverso"){
        cout<<"A diferencia del comando inicializar, este comando almacena las palabras en sentido inverso"<<endl;
        cout<<"Debe recibir un parametro: el nombre del archivo"<<endl;
        cout<<"iniciar_inverso diccionario.txt"<<endl;
    }else if(x== "puntaje"){
        cout<<"Permite conocer la puntuacion que puede obtenerse con una palabra dada"<<endl;
        cout<<"Debe recibir un parametro:la palabra que desea conocer su puntaje"<<endl;
        cout<<"puntaje palabra"<<endl;
    }else if(x== "salir"){
        cout<<"Finaliza el programa "<<endl;
        cout<<"No recibe parametro"<<endl;
        
    }
    
}



