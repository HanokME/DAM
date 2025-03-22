#include <iostream>
#include <cmath>
using namespace std;

int main(){

        double i = 0.0;
        double cantidadveces = 0.0;
        double factorial = 1.0;
        double e = 0.0;
        double j = 0.0;
        double aproximacion = 1.0;
        
        cout << "Bienvenido a la aproximacion de E." << endl;
        
        do{
        cout << "Introduce el numero de aproximaciones a calcular: ";
        cin >> cantidadveces;
        } while(cantidadveces <= 0);
        
        for(i = 1.0; i <= cantidadveces; i++){
  
                for(j = 1.0; j <= i; j++){
                
                        factorial *= j;
                
                }
                
                cout << "Aproximaciones de DEBUG: " << aproximacion << endl;
                
                aproximacion += 1.0 / factorial;
        
        }
        
        cout << "Resultado de la aproximacion de: " << cantidadveces << " veces = " << aproximacion << endl;

}
