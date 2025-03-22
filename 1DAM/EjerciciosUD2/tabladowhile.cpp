#include <iostream>
#include <cmath>

using namespace std;

int main(){

        int i = 1;
        int numero_multiplicar = 0;
        int numero_repeticiones = 0;
        int resultado = 0;
        
        cout << "Introduce el úmero que quieras multiplicar: ";
        cin >> numero_multiplicar;
        cout << "Introduce cuantas veces quieres multiplicarlo: ";
        cin >> numero_repeticiones;
        
        do{
                resultado = numero_multiplicar * i;
                cout << numero_multiplicar << " x " << i << " = " << resultado << endl;
                i = i + 1;
        } while (i <= numero_repeticiones);


}
