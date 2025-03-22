#include <iostream>
#include "colors.h"

using namespace std;

int main(){

        int numero = 0;
        
        do{
                cout << "Bienvenido a un programa de transmision a un satélite, la condición de parada será -1." << endl;
                cout << "Introduce un número entero: ";
                cin >> numero;
                
                cout << "Numero introducido: " << GREEN << numero << RESET << endl;
        
        }while (numero != -1);
                cout << RED << "Fin de la transmisión..." << RESET << endl;


}
