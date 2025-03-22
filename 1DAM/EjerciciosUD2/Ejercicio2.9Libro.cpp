#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

/**
 * @file Ejercicio2.6Libro.cpp
 * @brief Programa que te informa de tu nivel de aprobado o suspenso dependiendo de la nota de enrada
 * @date 09/11/2023
 * @author Hanok
 * @version 1.0
 */

int main(){

        double nota = 0.0;
        
        
        cout << "Bienvenido a un programa que te dice si estas aprobado o supenso dependiendo de la nota de entrada..." << endl;
        cout << "Por favor introduce la nota: ";
        cin >> nota;
        
        if((nota < 5.0) && (nota >= 0)){
        
                cout << "Lo siento pero estas supenso, estudia más." << endl;
        } else if ((nota >= 5.0) && (nota < 7.0)){
        
                cout << "Enhorabuena has aprobado con un bien." << endl;
        } else if ((nota >= 7.0) && (nota < 9.0)){
        
                cout << "Magnifico has sacado un notable." << endl;    
        } else if ((nota >= 9.0) && (nota <= 10.0)){
        
                cout << "INCREIBLE HAS SACADO UN SOBRESALIENTE Y ENCIMA SIN ESTUDIAR GOLFO." << endl;        
                
        } else {
        
                cout << "Máquina no mientas con la nota, pon una nota real..." << endl;
        
        }


}
