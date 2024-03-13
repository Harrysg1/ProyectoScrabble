#include "Palabra.h"
#include<cctype>
#include "DiccionarioInverso.h"
#include <stack>
#include"indice.h"
#include<iostream>
#include<fstream>

using namespace std;



void DiccionarioInverso::inicializarInverso( std::string rutaArchivo) {
    std::ifstream myfile(rutaArchivo);
    std::string linea;
    int contador=0;

    
    if(!myfile.is_open()){
        cout<<"El archivo no existe"<<endl;
        
    }else if (diccionarioInversoInicializado){
        cout<<"El archivo inverso ya fue ejecutado"<<endl;
        
    }
    
    
    if(myfile.is_open()&&!diccionarioInversoInicializado){
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
                // aqui se invierte 
                
                stack<char> pila;
                for (char c:linea){
                    pila.push(c);
                }
                string lineaAux="";
                string aux;
                while (!pila.empty()){
                    aux = pila.top();
                    lineaAux= lineaAux+aux;
                    pila.pop();
                
                    
                }
                linea = lineaAux;
                
                
                list<indice>::iterator it;
                for(it=indices.begin();it!=indices.end();it++){
                   
                    if(linea[0]==it->getLetra()){//toupper
                        
                        it->agregarPalabra(linea);
                        encontro ++;
                    }
                }
                if(encontro==0){
                    indice i(linea[0]);//toupper se maneja desde el constructor 
                    i.agregarPalabra(linea);
                    indices.push_back(i);
                }
               
                diccionarioInversoInicializado=true;
            }
        }
         cout<<"El diccionario inverso se ha inicializado correctamente."<<endl;
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


bool DiccionarioInverso::puntajePalabra(std::string palabra){
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