#include <iostream>
#include "colors.h"
using namespace std;

int main(){

        int i = 1;
        int numeroMultiplicar = 0;
        int multiplicaciones = 0;
        
        cout << "Introduce el numero que quieras multiplicar: ";
        cin >> numeroMultiplicar;
        cout << "Introduce el numero de veces que quieras multiplicar: " << endl;
        cin >> multiplicaciones;
        
        while(i <= multiplicaciones){
        
                cout << numeroMultiplicar << " x " << i << " = " << numeroMultiplicar * i << endl;
                
                i = i + 1;
        
        }


}
