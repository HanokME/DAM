#include <iostream>
using namespace std;

int main(){

        int cantidadnumeros;
        int numero;
        
        int maximo;
        int minimo;
        
        do{
                cout << "Introduce la cantidad de numeros que vas a introducir: ";
                cin >> cantidadnumeros;
        }while(cantidadnumeros <= 0);

        //Aqui inicializo las dos variables para que desde el principionumero sea el minimo  el maximo a la vez
        cout << "Introduce el valor 1: ";
        cin >> numero;
        
        minimo = numero;
        maximo = numero;
        
        for(int i = 1; i < cantidadnumeros; i++){
        
                cout << "Ingresa el valor " << i + 1 << ": ";
                cin >> numero;
                
                if(numero < minimo){
                        minimo = numero;
                }
                
                if(numero > maximo){
                        maximo = numero;
                }
        }
        
        cout << "El valor minimo es: " << minimo << endl;
        cout << "El valor maximo es: " << maximo << endl;

}
