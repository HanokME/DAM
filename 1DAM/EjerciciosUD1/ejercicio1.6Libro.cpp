#include <iostream>
using namespace std;

int main(){

        double precio = 0.0, pagado = 0.0, devolucion = 0.0;
        
        cout << "Escriba el precio del producto: ";
        cin >> precio;
        cout << "Escriba el dinero dado por el cliente: ";
        cin>> pagado;
        
        devolucion = pagado - precio;
        
        cout << "Hay que devolver: " << devolucion << "€" << endl;


}
