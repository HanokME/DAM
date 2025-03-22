#include <iostream>
using namespace std;

int main(){

        int cuenta = 0;
        int numero_repeticiones = 0;
        int numero_multiplicar = 0;
        
        cout << "Introduce el número que quieres multipicar: ";
        cin >> numero_multiplicar;
        cout << "Introduce el número de repeticiones que quieres hacer de la tabla del 7: ";
        cin >> numero_repeticiones;
        
        for(cuenta = 1; cuenta <= numero_repeticiones; cuenta++){
                
                cout << numero_multiplicar << " x " << cuenta << " = " << numero_multiplicar * cuenta << endl;
        
        }


}
