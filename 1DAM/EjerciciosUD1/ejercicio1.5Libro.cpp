#include <iostream>
#include <cmath>
using namespace std;

int main(){

        double valor = 0.0, base = 0.0, resultado = 0.0;
        
        cout << "Indique el valor de base: ";
        cin >> base;
        cout << "Indique el valor: ";
        cin >> valor;
        
        resultado = log(valor)/log(base);
        
        cout << "El log en base " << base << " de valor: " << valor << " es: " << resultado << endl;


}
