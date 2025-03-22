#include <iostream>
using namespace std;

int main(){

        int numero = 0;
        int resultado = 0;
        bool cuadradoperfe = false;
        
        cout << "Bienvenido a la hallacion de cuadrado perfecto de n..." << endl;
        
        do{
                cout << "Introduce el numero a hallar para averiguar si es un cuadrado perfecto: ";
                cin >> numero;
        }while(numero <= 0);
        
        for(int i = 0; resultado <= numero; i++){
                
                resultado = i * i;
                
                if (resultado == numero){
                
                        cuadradoperfe = true;
                }
        
        }
        
        if(cuadradoperfe == true){
                
                cout << "El número: " << numero << " es un cuadrado perfecto." << endl;
        } else{
        
                cout << "El número: " << numero << " no es un cuadrado perfecto." << endl;
        
        }


}
