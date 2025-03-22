#include <iostream>
#include <cmath>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

using namespace std;

/**
 * @file Dia1_HME.cpp
 * @brief Criba de Erastotenes, imprime por pantalla los n primeros numeros primos que introduzca el usuario
 * @date 15/12/2023
 * @author Hanok
 * @version 1.0
 */

int main(){

        int n_numeros = 0;
        bool es_primo = true;
        int total_primos = 0;
        
               
        cout << "Bienvenido al programa que te muestra los n primeros numeros primos que quieras..." << endl;
        cout << "Recuerda que solo se podran introducir numeros enteros y por encima de 0..." << endl;
        
        //FILTRO PARA NÚMEROS INFERIORES O IGUAL A 0.
        do{
                cout << "Introduce el numero que quieras de primos: ";
                cin >> n_numeros;
        }while(n_numeros <= 0);
        
        
        
        
        //CUENTA LA CANTIDAD DE PRIMOS HASTA EL N_NUMEROS
        for(int i = 1; total_primos < n_numeros; i++){
                
                es_primo = true;
                
                //CALCULA SI ES PRIMO O NO
                for(int j = 2; ((j < i) && (es_primo == true)); j++){
                        
                        if((i % j == 0) == false){
                            
                                es_primo = true;               
                        }else{                
                                es_primo = false;
                        }   
                                         
                }
                
                if(es_primo == false){
                        cout << RED << i << RESET << " ";
                } else{
                        cout << GREEN << i << RESET << " ";
                        total_primos ++;         
                } 
           
        }

         cout << endl;
}







