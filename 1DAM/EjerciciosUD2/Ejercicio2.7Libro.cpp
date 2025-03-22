#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

/**
 * @file Ejercicio2.6Libro.cpp
 * @brief Calcula el máximode tres numeros
 * @date 08/11/2023
 * @author Hanok
 * @version 1.0
 */
 
 int main(){
 
        double numero1 = 0.0;
        double numero2 = 0.0;
        double numero3 = 0.0;
        
        cout << "Bienvenido a un programa que calcula el máximo de 3 números reales..." << endl;
        cout << "Introduce el valor del primer número: ";
        cin >> numero1;
        cout << "Introduce el valor del segundo número: ";
        cin >> numero2;
        cout << "Introduce el valor del tercer número: ";
        cin >> numero3;
        
        if((numero1 > numero2) && (numero1 > numero3)){
        
                cout << "El valor máximo es: " << numero1 << endl;
        
        } else if((numero2 > numero1) && (numero2 > numero3)){
                
                cout << "El valor máximo es: " << numero2 << endl;
                
        } else if((numero3 > numero1) && (numero3 > numero2)){
        
                cout << "El valor máximo es: " << numero3 << endl;
        
        } else if( (numero1 == numero2) && (numero1 == numero3) && (numero2 == numero3) ){
                
                cout << "No hay un valor maximo todos los valores son iguales." << endl;
                
        }
        
 
 }
