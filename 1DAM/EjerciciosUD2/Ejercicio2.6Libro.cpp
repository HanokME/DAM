#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

/**
 * @file Ejercicio2.6Libro.cpp
 * @brief Calcula una ecuacion de segundo grado
 * @date 07/11/2023
 * @author Hanok
 * @version 1.0
 */
 
int main(){

        double a = 0.0;
        double b = 0.0;
        double c = 0.0;
        double x1 = 0.0;
        double x2 = 0.0;
        double discriminante = 0.0;
        
        cout << "Bienvenido a un programa que calcula una ecuacion de segundo grado..." << endl;
        cout << "Por favor introduce solo números..." << endl;
        cout << "Introduce el valor del coeficiente a: ";
        cin >> a;
        cout << "Por favor introduce el valor del coeficiente b: ";
        cin >> b;
        cout << "Por favor introduce el valor del coeficiente c: ";
        cin >> c;
        
        discriminante = ((b * b) - (4.0 * a * c));
        
        if(discriminante > 0){
                
                x1 = (-b + sqrt(discriminante)) / (2.0 * a);
                x2 = (-b - sqrt(discriminante)) / (2.0 * a);
                
                cout << "La raíz de x1 es: " << x1 << " y la raíz de x2 es: " << x2<< endl;
        
        } else if (discriminante == 0){
                
                x1 = -b / (2.0 * a);
                
                cout << "La raiz doble es: " << x1 << endl; 
        } else{
                
                cout << "La ecuación no tiene solución..." << endl;
        }



}
