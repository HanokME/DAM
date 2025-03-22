#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

/**
 * @file SanFermines.cpp
 * @brief Simulacion de unos San Fermines en las que tenemos grupos de toros, velocidades y velocidad a la que el corredor tiene que ir
 * @date 13/12/2023
 * @author Hanok
 * @version 1.0
 */
 
 int main(){
 
        //VARIABLES    
        int g_toros= 0; //Grupos de toros    
        int n_toros = 0; //Numero de toros
        int v_toros = 0; //Velocidad de cada toro
        int v_maxima = 0; //Comparacion velocidad toros
        int v_minima = 0; //Comparacion velocidad toros
        int v_corredor = 0; //Velocidad a la que tiene que ir el corredor
        
        //BIENVENIDA
        cout << "Bienvenido a un programa que simula una fiesta de San Fermines." << endl;
        cout << "Un programa en el que va a introducir la cantidad de grupos de toros querida y la velocidad de cada uno." << endl;
        cout << "Y por pantalla se imprimirá la velocidad a la que tiene que ir el corredor pa que n lo maten." << endl;
        cout << "Toda introducción de datos tendrá que ser de números positivos y enteros, en ningún caso deberá ser otro." << endl;
        
        //ENTRADA DE DATOS
        
        do{
                cout << "Introduce la cantidad de grupos de toros que quieras comparar: ";
                cin >> g_toros;
        }while(g_toros <= 0);
        
        //BUCLE PARA REPETIR G_CASOS
        for(int g = 0; g < g_toros; g++){
                //INTRODUCCION DE NUMERO DE TOROS
                do{
                
                        cout << BLUE << "G" << g + 1 << RESET << " Introduce la cantidad de toros que quieras comparar: ";
                        cin >> n_toros;
                
                }while(n_toros <= 0);
                
                //INTRODUCCION DE LA PRIMERA VELOCIDAD DE TOROS
                do{
                cout << "Introduce la velocidad del toro 1: ";
                cin >> v_toros;
                }while(v_toros <= 0);
                
                //INICIALIAMOS A V_TOROS PARA QUE OS DOS EMPIECEN DESDE EL PRIMER NUMERO
                v_minima = v_toros;
                v_maxima = v_toros;
                
                for(int i = 1; i < n_toros; i++){
                        
                        do{
                        cout << "Introduce la velocidad del toro " << i + 1 << ": ";
                        cin >> v_toros;
                        }while(v_toros <= 0);
                        
                        //COMPARAR EL MINIMO
                        if(v_toros < v_minima){
                                v_minima = v_toros;
                        }
                        //COMPARAR EL MAXIMO
                        if(v_toros > v_maxima){
                                v_maxima = v_toros;
                        }
                                               
                }
                
             cout << BLUE << "Grupo " << g + 1 << RESET << " || Velocidad mínima a la que tiene que ir el corredor: " << GREEN << v_maxima << RESET << endl;
        }
        
        
 

 }
