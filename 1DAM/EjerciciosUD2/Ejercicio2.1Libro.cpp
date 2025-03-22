#include <iostream>
#include <cmath>
#include "colors.h"
using namespace std;

/**
 * @file Ejercicio2.1Libro.cpp
 * @brief Calcula el mayor de dos valores reales 
 * @date 05/11/2023
 * @author Hanok
 * @version 1,0
 */

int main(){

        double valor1 = 0.0;
        double valor2 = 0.0;
        
        cout << "Bienvenido a un programa que te indica de dos valores reales introducidos el mayor..." << endl;
        cout << "Por favor introduce dos valores reales seguido de un espacio entre cada uno: ";
        cin >> valor1 >> valor2;
        
        if (valor1 > valor2){
                
                cout << "El valor: " << valor1 << " es mayor que el valor: " << valor2 << endl;
        }
        if (valor2 > valor1){
                
                cout << "El valor: " << valor2 << " es mayor que el valor: " << valor1 << endl;
        }




}
