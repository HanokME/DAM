#include <iostream>
#include "colors.h"
using namespace std;

int main(){

        int numero = 0;
        
        cout << "Bienvenido a un programa de interceptación de números para un satélite..." << endl;
        cout << "Introduce números y para parar introduce -1: " << endl;
        cin >> numero;
        
        while(numero != -1){
        
                cout << "Recibido el número: " << GREEN << numero << RESET << endl;
                cout << "Introduce el siguiente: " << endl;
                cin >> numero;
        
        }
        
        cout << RED << "Fin de la transmisión..." << RESET << endl;




}
