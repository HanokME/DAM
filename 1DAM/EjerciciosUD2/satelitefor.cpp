#include <iostream>
using namespace std;

int main(){

        int numero = 0;
        
        cout << "Introduce un número mayor o igual que cero, en caso contrario, la transmision parará: ";
        
        for(numero = 0; numero >= 0;){
                
                cin >> numero;
                cout << "Transmitiendo.." << endl;
                
        }
        cout << "Fin de la transmision." << endl;


}
