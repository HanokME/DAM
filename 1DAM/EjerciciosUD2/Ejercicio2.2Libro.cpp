#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

/**
 * @file Ejercicio2.1Libro.cpp
 * @brief Calcula si un entero es número par o impar
 * @date 06/11/2023
 * @author Hanok
 * @version 1.0
 */

int main(){

        int valorEntero = 0;
        
        cout << "Bienvenido a un programa que calcula si un valor entero es par o impar..." << endl;
        cout << "Por favor introduce el numero entero a comparar, no introduzcas ni letras, ni símbolos, ni números reales: ";
        cin >> valorEntero;
        
        if (valorEntero % 2 == 0){
                cout << "El valor entero: " << valorEntero << " es par" << endl;
        }
        if (valorEntero % 2 != 0){
                cout << "El valor entero: " << valorEntero << " es impar" << endl;
        }


}
