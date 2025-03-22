#include <iostream>
#include <cmath>
using namespace std;

int main(){

        double a = 0.0, b = 0.0, c = 0.0, x1 = 0.0, x2 = 0.0;
        double raiz = 0.0;
        
        cout << "Bienvenido a un programa para calcular una ecuación de segundo grado..." << endl;
        cout << "Introduce el coeficiente a: ";
        cin >> a;
        cout << "Introduce el coeficiente b: ";
        cin >> b;
        cout << "Introduce el coeficiente c: ";
        cin >> c;
        
        raiz = (b * b) - (4 * a * c);
        
        x1 = (-b + sqrt(raiz)) / (2*a);
        x2 = (-b - sqrt(raiz)) / (2*a);
        
        cout << "Solucion de x1: " << x1 << endl;
        cout << "Solución e x2: " << x2 << endl;
        


}
