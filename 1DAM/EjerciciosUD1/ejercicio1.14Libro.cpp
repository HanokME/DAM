#include <iostream>
#include <cmath>
using namespace std;

int main(){
        
        double x1 = 0.0, x2 = 0.0, x3 = 0.0;
        double media = 0.0, diferencia_valores = 0.0, desviacion_tipica = 0.0;
        
        cout << "Bienvenido a un programa que calcula la media y la desviacion típica de 3 valores..." << endl;
        cout << "A continuacion, por favor, introduzca 3 valores reales, pero nunca caracteres, gracias..." << endl;
        
        cout << "Introduce el valor de x1: ";
        cin >> x1;
        cout << "Introduce el valor de x2: ";
        cin >> x2;
        cout << "Introduce el valor de x3: ";
        cin >> x3;
        
        media = (x1 + x2 + x3) / 3.0;
        
        //Calcula la variabilidad de los valores respecto a la media
        diferencia_valores = pow(x1 - media, 2) + pow(x2 - media, 2) + pow(x3 - media, 2);
        
        desviacion_tipica = sqrt(diferencia_valores / 3);
        
        cout << "Resultado media: " << media << endl;
        cout << "Resultado desviación típica: " << desviacion_tipica << endl;
        

}
