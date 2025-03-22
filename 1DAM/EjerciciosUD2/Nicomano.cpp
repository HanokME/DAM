#include <iostream>
#include <cmath>
#include "colors.h"
using namespace std;
/**
 * @file Nicomano.cpp
 * @brief Calcular el cubo de un número calculando los previos
 * @date 17/12/2023
 * @author Hanok
 * @version 1.0
 */
int main(){

        int numero_que_quieres_calcular = 0;
        int cubo = 0;
        
                cout << "Bienvenido a un programa que te clcula el cubo de un numero calculando los previos..." << endl;
                
        do{
                
                cout << "Ingrese el número al que quiera calcular el cubo: ";
                cin >> numero_que_quieres_calcular;
                
        }while(numero_que_quieres_calcular <= 0);
        
        cubo = 0;
        for(int i = 0; i <= numero_que_quieres_calcular; i++){
        
                cubo = pow(i, 3);
                
                cout << "El cubo de " << i << " es: " << GREEN << cubo << RESET << endl;
        
        }




}
