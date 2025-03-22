#include <iostream>
#include <cmath>
#include "colors.h"
using namespace std;

/**
 * @file kasparov.cpp
 * @brief Simulacion de un tablero de ajedrez y el movimiento de sus piezas
 * @date 15/11/2023
 * @author Hanok
 * @version 0.6
 */
 
 int main(){
 
        double x_inicial = 0.0;
        double y_inicial = 0.0;
        
        double x_final = 0.0;
        double y_final = 0.0;
        
        bool movimientoValido = false;
        
        char pieza = 'a';
        
        cout << "Bienvenido a una simulacion de un tabero de ajedrez." << endl;
        cout << "A continuación se le pedira que pieza quiere mover" << endl;
        
        //Introducir pieza a mover
        cout << "Por favor introduce la letra en minúscula o mayuscula de las piezas que le mostraré  continuación..." << endl;
        cout << "Para el movimiento de la torre pulse 't' o 'T': " << endl;
        cout << "Para el movimiento de la reina pulse 'r' o 'R': " << endl;
        cout << "Para el movimiento del caballo pulse 'c' o 'C': " << endl;
        cin >> pieza;
        
        //Introducir coordenadas iniciales y finales
        cout << "Todos los numeros tienen que estar comprendidos entre 1 y 8." << endl;
        
        cout << "Introduce la casilla de la fila inicial de la pieza: ";
        cin >> y_inicial;
        cout << "Introduce la casilla de la columna inicial de la pieza: ";
        cin >> x_inicial;
        
        cout << "Introduce la casilla de la fila final de la pieza: ";
        cin >> y_final;
        cout << "Introduce la casilla de la columna final de la pieza: ";
        cin >> x_final;
        
        //SWITCH
        switch(pieza){
        
                case 't':
                case 'T':
                
                if((x_inicial == x_final) && (y_inicial != y_final)){
                
                        cout << "El movimiento es: ¡VÁLIDO!" << endl;

                } else if ((x_inicial != x_final)&&(y_inicial == y_final)){
                        
                        cout << "El movimiento es: ¡VÁLIDO!" << endl;
                } else{
                
                        cout << "El movimiento es: ¡INVÁLIDO!" << endl;
                }
                break;
                
                case 'r':
                case 'R':
                
                if((x_inicial == x_final) && (y_inicial != y_final)){
                
                        cout << "El movimiento es: ¡VÁLIDO!" << endl;

                } else if ((x_inicial != x_final)&&(y_inicial == y_final)){
                        
                        cout << "El movimiento es: ¡VÁLIDO!" << endl;
                        
                } else if((x_inicial - y_inicial == x_final - y_final)){
                
                        cout << "El movimiento es: ¡VÁLIDO!" << endl;
                        
                } else if(x_inicial + y_inicial == x_final + y_inicial){
                
                        cout << "El movimiento es: ¡VÁLIDO!" << endl;
                
                } else{
                
                        cout << "El movimiento es: ¡INVÁLIDO!" << endl;
                
                }
                
                break;
                
                case 'c':
                case 'C':
                
                if(((x_final == x_inicial + 2)||(x_final ==x_inicial - 2))&&((y_final == y_inicial + 1)||(y_final == y_inicial - 1))){
                
                        cout << "El movimiento es: ¡VÁLIDO!" << endl;
                               
                } else if( ((x_final == x_inicial + 1) ||(x_final == x_inicial - 1)) && ((y_final == y_inicial + 2) || (y_final == y_inicial - 2)) ){
                
                        cout << "El movimiento es: ¡VÁLIDO!" << endl;
                        
                }else{
                
                        cout << "El movimiento es: ¡INVÁLIDO!" << endl;
                
                }
                
                break;
                
                default:
                
                        cout << "No has introducido una letra válida por favor reinicia y repite de nueo..." << endl;
        
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
 
 
 }
