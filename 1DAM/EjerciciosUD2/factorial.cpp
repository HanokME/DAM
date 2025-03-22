#include <iostream>
#include "colors.h"

/**
 * @file factorial.cpp
 * @brief Calcula el factorial de un número
 * @date 30/11/2023
 * @author Hanok
 * @version 1.0
 */
using namespace std;

int main(){

        int numero = 0;
        int factorial = 0;
        int i = 0; //Este es el contador del bucle
        
        cout << "Bienvenido a una calculadora de factorial de N..." << endl;
       
       do{
       
        cout << "Introduce números positivos y que no sea 0, gracias: ";
        cin >> numero;
        
        }while(numero <= 0);
        
        //EMPEZAMOS CON EL BUCLE PARA RECORRER LOS NUMEROS HASTA EL FINAL, QUE ES EL QUE HA INTRODUCIDO EL USUARIO
        factorial = 1;
        for(i = 1; i <= numero; i++){
                
                //ESTO VA MULTIPLICANDO CADA NÚMERO POR EL QUE PASA I PARA HACER EL FACTORIAL
                factorial = factorial * i;
                
        }
                
        cout << "El factorial de " << numero << " es: " << GREEN << factorial << RESET << endl;
        
}
