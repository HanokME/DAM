#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

int main(){

        int numero = 0;
        int suma = 0;
        
        cout << "Ingresa números enteros y se csumarán hasta que introduzcas cero, que automaticamente terminará el prorama." << endl;
        
        do{
        
        cout << "Introduce el número a sumar: ";
        cin >> numero;
        
        suma = suma + numero;
        
        }while (numero != 0);
        
        cout << "Resultado de la suma: " << suma << endl;


}
