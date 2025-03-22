#include <iostream>
using namespace std;

int main(){

        int factor1 = 0;
        int factor2 = 0;
        int i = 0;
        int j = 0;
        int resultado = 0;
        
        cout << "Bienvenido a la calculadora topro..." << endl;
        
        do{
        cout << "Introduce el número al que quieras hacer la multiplicacion: ";
        cin >> factor1;
        } while(factor1 <= 0);
        
        do{
        cout << "Introduce el número de veces que quieres multiplicar el factor 1: ";
        cin >> factor2;
        } while(factor2 <= 0);
        
        for(i = 0; i <= factor2; i++){
                for(j = 0; j <= factor1; j++){
                        
                        resultado = i * j;
                                                                
                       
                }

                 cout << i << " x " << factor1 << " = " << resultado << endl;
        }
        


}
