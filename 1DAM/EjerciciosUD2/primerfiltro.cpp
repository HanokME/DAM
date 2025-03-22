#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

int main(){

        int numero1 = 0;
        int numero2 = 0;
        
        do{
        
        cout << "Ingresa dos numeros positivos..." << endl;
        cout << "Numero1: ";
        cin >> numero1;
        cout << "Numero2: ";
        cin >> numero2;
        
        }while (numero1 <= 0 && numero2 <= 0);
        
        cout << "Canelita en rama, has sido obediente." << endl;


}
