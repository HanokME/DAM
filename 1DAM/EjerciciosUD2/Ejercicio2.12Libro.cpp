#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

/**
 * @file Ejercicio2.6Libro.cpp
 * @brief Programa utiliza un menu interactivo para que el usuario calcule la cuenta que quiera
 * @date 09/11/2023
 * @author Hanok
 * @version 1.0
 */
 
 int main(){
 
        double numero1 = 0.0;
        double numero2 = 0.0;
        
        char letra= 'W';
        
        double suma = 0.0;
        double resta = 0.0;
        double multiplicacion = 0.0;
        double division = 0.0;
        
        cout << "Bienvenido a una minicalculadora interactiva en la que podrás hacer el calculo que quieras..." << endl;
        cout << "Por favor introduce los dos numeros que quieras calcular" << endl;
        cout << "Numero 1: ";
        cin >> numero1;
        cout << "numero 2: ";
        cin >> numero2;
        
        cout << "OK, ahora que tenemos los dos numeros por favor pulsa S/s para hacer la suma, R/r para la resta, D/dpara la división y M/m para la multiplicacion: ";
        cin >> letra;
        
        switch (letra){
                
                //SUMA
                case 'S':
                case 's':
                
                suma = numero1 + numero2;
                
                cout << "La suma de " << numero1 << " y " << numero2 << " = " << suma << endl;
                
                break;
                
                //RESTA
                case 'r':
                case 'R':
                
                resta = numero1 - numero2;
                
                cout << "La resta de " << numero1 << " y " << numero2 << " = " << resta << endl;
                
                break;
                
                //MULTIPLICACION
                case 'M':
                case 'm':
                
                multiplicacion = numero1 * numero2;
                
                cout << "La multiplicacion de " << numero1 << " y " << numero2 << " = " << multiplicacion << endl;
                
                break;
                
                //DIVISION
                case 'd':
                case 'D':
                
                division = numero1 / numero2;
                
                cout << "La division de " << numero1 << " y " << numero2 << " = " << division << endl;
                
                break;
        
                default:
                
                    cout << "Has introducido una letra no vlida por favor vuelve a introducir una letra válida..." << endl;
        }
        
 
 
 
 }
