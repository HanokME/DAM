#include <iostream>
#include "colors.h"
using namespace std;

int main(){


        long int numero = 0;
        long int divisor = 2;
        bool esprimo = true;
        cout << "Bienvenido al programa de los primos..." << endl;
        
        do{
        
                cout << "Introduce el número a calcular, que no sea menor o igual que 1: ";
                cin >> numero;
        
        }while (numero <= 1);
        
        //AQUI ECORRE EL BUCLE MIENTRAS QUE EL RESTO DE NUMERO % DIVISOR SEA DISTINTO, SI ES IGUAL, PARA EL BUCLE
        while((numero % divisor != 0) && (divisor < numero)){
        
                
           divisor++;
        
        }
        
        if(divisor == numero){
        
                cout << "El número " << numero << " es primo." << endl;
        
        }else{
        
                cout << "El número " << numero<< " no es primo." << endl;
        
        }
        
}
