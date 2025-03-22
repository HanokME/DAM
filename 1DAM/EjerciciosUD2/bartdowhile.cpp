#include <iostream>
#include <cmath>

using namespace std;

int main(){

        int i = 1;
        int repeticiones = 0;
        
        cout << "Introduce el numero de veces que quieres copiar la frase: ";
        cin >> repeticiones;
        
        do{
                cout << "No debo mirar el ordenador en clase..." << endl;
                i = i + 1;
        } while (i <= repeticiones);


}
