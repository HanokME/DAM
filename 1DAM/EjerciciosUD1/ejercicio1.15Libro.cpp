#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * @file ejercicio1.15Libro.cpp
 * @brief Programa para calcular 2 aproximaciones de pi mediante la fórmula de Borwein
 * @version 1.0 
 * @date 24/10/2023
 * @author Hanok
 */

int main(){
        
        double x0 = 0.0, x1 = 0.0, x2 = 0.0;
        double y0 = 0.0, y1 = 0.0, y2 = 0.0;
        double pi0 = 0.0, pi1 = 0.0, pi2 = 0.0;
        
        
        //Presentacion
        cout << "Bienvenido al programa de Borwein que hace aproximaciones de pi..." << endl;
        cout << "A continuacion saldrán los resultados..." << endl;
        
        //Calculos de x0, y1 y pi0
        x0 = sqrt(2.0);
        y1 = pow(2, 0.25);
        pi0 = 2 + sqrt(2);
        
        //Cálculo de pi1, pi2, x1, x2 e y2
        x1 = (1.0 / 2.0) * (sqrt(x0) + (1.0 / sqrt(x0)));
        pi1 = pi0 * ( (x1 + 1.0) / (y1 + 1.0) );
        x2 = (1.0 / 2.0) * (sqrt(x1) + (1.0 / sqrt(x1)));
        y2 = ( (y1 * sqrt(x1) + 1 / sqrt(x1)) / (y1 + 1.0) );
        pi2 = pi1 * ( (x2 + 1.0) / (y2 + 1.0) );
        
        //Resultados
        cout << "Resultado de pi0: " << setprecision(20) << pi0 << endl;
        cout << "Resultado de pi1: " << pi1 << endl;
        cout << "Resultado de pi2: " << pi2 << endl;
        
}
