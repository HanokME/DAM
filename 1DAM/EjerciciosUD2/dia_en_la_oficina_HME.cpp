#include <iostream>
#include <cmath>
#include "colors.h"
using namespace std;

/**
 * @file dia_en_la_oficina_HME.cpp.cpp
 * @brief Grabar una cantidad de juegos con una duracion en una cinta de doble pletina, sin cortar ninguno de los juegos.
 * @date 21/12/2023
 * @author Hanok
 * @version 0.0
 */
 
int main(){

        int tamaño_cinta = 0;
        int numero_juegos_grabar = 0;
        int tamaño_cada_juego = 0;
        int suma_tiempo_cada_juego = 0;
        int cara_a = 0;
        int cara_b= 0;
        bool cabe = true;
        
        cout << "Bienvenido a un programa que guarda juegos en una cinta de doble cara y muestra SI caben o NO." << endl;
        
        do{
        
                cout << "Introduce por favor el tamaño de las caras de la cinta (1-10⁸): ";
                cin >> tamaño_cinta;
                cara_a = tamaño_cinta; //Cada cinta tiene dos caras
                cara_b = tamaño_cinta;
                //cout << "Tienes un tamaño de cinta total de: " << RED << tamaño_cinta << RESET << endl;
                
        }while((tamaño_cinta <= 0) || (tamaño_cinta > pow(10, 8)));
        
        do{
        
                cout << "Introduce cuantos juegos quieres grabar en total (1-8): ";
                cin >> numero_juegos_grabar;
                //cout << "Quieres grabar: " << RED << numero_juegos_grabar << " juegos." << RESET << endl;
                
        }while((numero_juegos_grabar <= 0) || (numero_juegos_grabar > 8));
        
        
        //BUCLE PARA INTRODUCIR EL TAMAÑO DE CADA JUEGO Y HACER SU SUMA
        cabe = true;
        suma_tiempo_cada_juego = 0;
        cout << "Introduce el tamaño que quieres que ocupe cada juego (1-10⁸): " << endl;
        for(int i = 1; i <= numero_juegos_grabar; i++){
                
                do{
                
                        cout << "Juego " << i << ": ";
                        cin >> tamaño_cada_juego;
                        //cout << "juego " << i << ": " << RED << tamaño_cada_juego << RESET << endl;
                        
                }while((tamaño_cada_juego <= 0) || (tamaño_cada_juego > pow(10, 8)));
                
                cout << RED << "suma_tiempo_cada_juego antes de acumular: " << suma_tiempo_cada_juego << RESET << endl;
                
                if((suma_tiempo_cada_juego > tamaño_cinta) || (suma_tiempo_cada_juego > tamaño_cinta)){
                
                        cabe = false;
               
                }
                
                suma_tiempo_cada_juego = suma_tiempo_cada_juego + tamaño_cada_juego;
                
                cout << RED << "suma_tiempo_cada_juego despues de acumular: " << suma_tiempo_cada_juego << RESET << endl;
                
                
        }
        
        
        cout << "Suma de cada tiempo: " << suma_tiempo_cada_juego << endl;
        
        if(cabe == false){
        
                cout << RED << "NO" << RESET << endl;
        
        } else {
                
                cout << GREEN << "SI" << RESET << endl;
        
        }
        
        
        

}


