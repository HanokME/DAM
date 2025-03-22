#include <iostream>
#include <cmath>
#include "colors.h"
using namespace std;

/**
 * @file Ejercicio2.4Libro.cpp
 * @brief Calcula el área y la longitud de un ículo a partir del radio
 * @date 07/11/2023
 * @author Hanok
 * @version 0.25
 */
 
 int main(){
 
        double radio = 0.0;
        const double PI = 3.14;
        double area = 0.0;
        double perimetro = 0.0;
        
        cout << "Bienvenido a un programa que calcula el área y perímetro de una circunferencia, a partir de un radio introducido..." << endl;
        cout << "Por favor introduce un número real corresponciente al radio, no introduzca ninguna simbología ni letra: ";
        cin >> radio;
        
        if (radio > 0){
                area = PI * pow(radio, 2);
                perimetro = 2.0 * PI * radio;
                        
                cout << "El radio introducido es: " << radio << " por lo tanto el área es: " << area << " y el perimetro: " << perimetro << endl; 
        }
        if (radio <= 0){
                
                cout << "El numero introducido es: " << radio << " por favor reinicia e introduzca un numero válido." << endl;
        
        }
 
 
 }
