#include <iostream>
#include "colors.h"
using namespace std;

int main(){

        int intervalo_a = 0;
        int intervalo_b = 0;
        int numero = 0;
        int total_divisores = 0;
        
        cout << "Bienvenido al calculador de divisores de un número en un intervalo específico..." << endl;
        cout << "No se aceptan números negativos, cero ni caracteres y símbolos..." << endl;
        
        do{
        
                cout << "Introduce el intervalo mínimo: ";
                cin >> intervalo_a;
                cout << "Introduce el intervalo máximo: ";
                cin >> intervalo_b;
                
                cout << "Introduce el número al que le quieres hallar los divisores: ";
                cin >> numero;
        
        }while ( (numero <= 0) || (intervalo_a < 0) || (intervalo_b <= 0 ) );
        
        while(intervalo_a <= numero){
        
                if(numero % intervalo_a == 0){
                        
                        cout << "Divisor: " << intervalo_a << endl;
                        total_divisores++;
                
                }
                
           intervalo_a = intervalo_a + 1;
        
        }
        
        cout << "Total de divisores: " << total_divisores << endl;
        



}
