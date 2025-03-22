#include <iostream>
using namespace std;

int main(){

        int num1 = 0;
        int num2 = 0;
        int res = 0;
        
        
        cout << "Bienvenido al calculador del MCD de dos números." << endl;
        
        
        
        do{
                cout << "Por favor introduzca el primer numero entero: ";
                cin >> num1;
                cout << "Por favor introduzca el segundo numero entero: ";
                cin >> num2;
        }while((num1 <= 0) && (num2 <= 0));
        
        while(num2 != 0){
        
                res = num2;
                num2 = num1 % num2; //Asignas el valor de la division a num2
                num1 = res; //asigna a num1 el valor anterior de num2 para la siguiente iteracion
        
        }
        
        cout << "El MCD es: " << num1 << endl;



}
