#include <iostream>
#include <iomanip>
using namespace std;
#include "polinomio.h"

#define DEFAULT "\033[1;0m"
#define ERROR "\033[1;31m"
#define OK "\033[1;32m"
#define DEBUG "\033[1;34m"

const bool CASOSUMA = true;
const bool TESTUNITARIO = false;

int main(){
////////TESTING SUMA
    if(CASOSUMA){
        Polinomio p1;
        Polinomio p2;
        Polinomio pres;
        

        /*Caso de suma 1: 
        //p1(x) = 7x^2 + 3x
        //p2(x) = 4x^4 + 3x^2 + 3
        //pres(x) = 4x^4 + 10x^2 + 3x + 3
        */
        p1.setCoeficienteV3(2, 7);
        p1.setCoeficienteV3(1, 3);
        p1.setCoeficienteV3(0, 3);
        cout << "CASO 1: " << endl;
        cout << "Polinomio 1: " << endl;
        cout << p1;

        p2.setCoeficienteV3(4, 4);
        p2.setCoeficienteV3(2, 3);
        p2.setCoeficienteV3(0, 3);
        cout << "Polinomio 2: " << endl;
        cout << p2;

        pres = p1 + p2;
        cout << "Resultado: " << endl;
        cout << pres;

        p1.resetPolinomio(p1);
        p2.resetPolinomio(p2);
        

        /*Caso de suma 2: 
        p1(x) = 4x^4 + 3x^2 + 3
        p2(x) = 7x^2 + 3x
        pres(x) = 4x^4 + 10x^2 + 3x + 3
        */
        p1.setCoeficienteV3(4, 4);
        p1.setCoeficienteV3(2, 3);
        p1.setCoeficienteV3(0, 3);
        cout << "CASO 2: " << endl;
        cout << "Polinomio 1: " << endl;
        cout << p1;

        p2.setCoeficienteV3(2, 7);
        p2.setCoeficienteV3(1, 3);
        cout << "Polinomio 2: " << endl;
        cout << p2;

        pres = p1 + p2;
        cout << "Resultado: " << endl;
        cout << pres;

        p1.resetPolinomio(p1);
        p2.resetPolinomio(p2);
        

        /*Caso de suma 3: 
        p1(x) = 4x^4 + 3x^2 + 3
        p2(x) = 7x^4 + 3x - 3
        pres(x) = 11x^4 + 3x^2 + 3x
        */

        p1.setCoeficienteV3(4, 4);
        p1.setCoeficienteV3(2, 3);
        p1.setCoeficienteV3(0, 3);
        cout << "CASO 3: " << endl;
        cout << "Polinomio 1: " << endl;
        cout << p1;

        p2.setCoeficienteV3(4, 7);
        p2.setCoeficienteV3(1, 3);
        p2.setCoeficienteV3(0, -3);
        cout << "Polinomio 2: " << endl;
        cout << p2;

        pres = p1 + p2;
        cout << "Resultado: " << endl;
        cout << pres;

        p1.resetPolinomio(p1);
        p2.resetPolinomio(p2);
        

        /*Caso de suma 4: 
        p1(x) = 4x^4 + 3x^2 + 3
        p2(x) = -4x^4 + 3x - 3
        pres(x) = 3x^2 + 3x
        */

        p1.setCoeficienteV3(4, 4);
        p1.setCoeficienteV3(2, 3);
        p1.setCoeficienteV3(0, 3); 
        cout << "CASO 4: " << endl;
        cout << "Polinomio 1: " << endl;
        cout << p1;

        p2.setCoeficienteV3(4, -4); 
        p2.setCoeficienteV3(1, 3); 
        p2.setCoeficienteV3(0, -3); 
        cout << "Polinomio 2: " << endl;
        cout << p2;

        pres = p1 + p2;
        cout << "Resultado: " << endl;
        cout << pres;

        p1.resetPolinomio(p1);
        p2.resetPolinomio(p2);


        /*Caso de suma 5: 
        p1(x) = 4x^4 + 3x^2 + 3
        p2(x) = -4x^4 + 3x^2 - 3
        pres(x) = 0(nulo) warning al imprimir
        */

        p1.setCoeficienteV3(4, 4); 
        p1.setCoeficienteV3(2, 3); 
        p1.setCoeficienteV3(0, 3); 
        cout << "CASO 5: " << endl;
        cout << "Polinomio 1: " << endl;
        cout << p1;

        p2.setCoeficienteV3(4, -4); 
        p2.setCoeficienteV3(2, -3); 
        p2.setCoeficienteV3(0, -3); 
        cout << "Polinomio 2: " << endl;
        cout << p2;

        pres = p1 + p2;
        cout << "Resultado: " << endl;
        cout << pres;


    }


////////////TESTING UNITARIO
    // Definición de polinomios para probar los casos
    
    if(TESTUNITARIO){
   
        Polinomio caso1;
        Polinomio caso2;
        Polinomio caso3;
        Polinomio caso4;
        Polinomio caso5;
        Polinomio subcaso51;
        Polinomio caso1_resize;
        Polinomio caso2_resize; 

        // Caso 1: Insertar un monomio de grado menor o igual que el grado actual
        caso1.setCoeficienteV3(2, 7);   // Coeficiente en x^2: 7
        caso1.setCoeficienteV3(5, 5);   // Coeficiente en x^5: 5
        caso1.setCoeficienteV3(0, 8);   // Coeficiente en x^0: 8
        cout << "caso1: " << endl;
        cout << caso1;
        // Debería imprimir: P(x): 7x^2 + 5x^5 + 8
        cout << "caso1: " << endl;
        cout << caso1;
        // Debería imprimir: P(x): 4x^5 + 5x^2 + 7

        // Caso 2: Insertar un monomio de grado negativo
        caso2.setCoeficienteV3(0, 8);   // Coeficiente en x^0: 8
        caso2.setCoeficienteV3(5, -3);  // Coeficiente en x^5: -3
        caso2.setCoeficienteV3(2, 9);   // Coeficiente en x^2: 9
        caso2.setCoeficienteV3(-12, 2); // Intento de inserción con grado negativo
        cout << "caso2: " << endl;
        cout << caso2;
        // Debería imprimir: P(x): -3x^5 + 9x^2 + 8
        // Debería mostrar un mensaje de advertencia por el intento de inserción con grado negativo

        // Caso 3: Insertar un monomio de grado mayor al grado actual, pero menor que max_grado
        caso3.setCoeficienteV3(0, 8);   // Coeficiente en x^0: 8
        caso3.setCoeficienteV3(5, -3);  // Coeficiente en x^5: -3
        caso3.setCoeficienteV3(2, 9);   // Coeficiente en x^2: 9
        caso3.setCoeficienteV3(-12, 2); // Coeficiente en x^-12: 2
        caso3.setCoeficienteV3(9, 5);   // Coeficiente en x^9: 5
        cout << "caso3: " << endl;
        cout << caso3;
        // Debería imprimir: P(x): 5x^9-3x^5 + 9x^2 + 8

        // Caso 4: Insertar un monomio de grado mayor al grado actual, y que sea mayor que max_grado
        caso4.setCoeficienteV3(0, 8);   // Coeficiente en x^0: 8
        caso4.setCoeficienteV3(5, -3);  // Coeficiente en x^5: -3
        caso4.setCoeficienteV3(2, 9);   // Coeficiente en x^2: 9
        caso4.setCoeficienteV3(-12, 2); // Coeficiente en x^-12: 2
        caso4.setCoeficienteV3(9, 5);   // Coeficiente en x^9: 5
        caso4.setCoeficienteV3(12, 4);  // Coeficiente en x^12: 4
        cout << "caso4: " << endl;
        cout << caso4;
        // Debería imprimir: P(x): 4x^12 + 5x^9-3x^5 + 9x^2 + 8

        // Caso 5: Insertar un monomio de grado igual que el grado actual, y cuyo coeficiente sea cero
        caso5.setCoeficienteV3(0, 8);   // Coeficiente en x^0: 8
        caso5.setCoeficienteV3(5, -3);  // Coeficiente en x^5: -3
        caso5.setCoeficienteV3(2, 9);   // Coeficiente en x^2: 9
        caso5.setCoeficienteV3(-12, 2); // Coeficiente en x^-12: 2
        caso5.setCoeficienteV3(9, 5);   // Coeficiente en x^9: 5
        caso5.setCoeficienteV3(12, 4);  // Coeficiente en x^12: 4
        caso5.setCoeficienteV3(12, 0);  // Coeficiente en x^12: 0
        cout << "caso5: " << endl;
        cout << caso5;
        // Debería imprimir: P(x): 5x^9-3x^5 + 9x^2 + 8

        // Subcaso 5.1: Todos los coeficientes anteriores son cero
        subcaso51.setCoeficienteV3(0, 0);  
        subcaso51.setCoeficienteV3(5, 0);  
        subcaso51.setCoeficienteV3(2, 0);  
        subcaso51.setCoeficienteV3(9, 0);  
        subcaso51.setCoeficienteV3(12, 0); 
        cout << "Subcaso 5.1: " << endl;
        subcaso51.print();
        // No debería imprimir ningún polinomio ya que todos los coeficientes son cero

        ///////TESTING RESIZE
        
        // Caso 1: Redimensionar el polinomio para reducir el tamaño
        caso1_resize.setCoeficienteV3(0, 8);   // Coeficiente en x^0: 8
        caso1_resize.setCoeficienteV3(5, -3);  // Coeficiente en x^5: -3
        caso1_resize.setCoeficienteV3(2, 9);   // Coeficiente en x^2: 9
        caso1_resize.setCoeficienteV3(-12, 2); // Coeficiente en x^-12: 2
        caso1_resize.setCoeficienteV3(9, 5);   // Coeficiente en x^9: 5
        caso1_resize.setCoeficienteV3(12, 4);  // Coeficiente en x^12: 4
        caso1_resize.resize(5); // Redimensionar el polinomio para incluir el grado 5
        cout << "caso1_resize: " << endl;
        cout << caso1_resize;
        // Debería imprimir: P(x): -3x^5 + 9x^2 + 8

        // Caso 2: Redimensionar el polinomio para aumentar el tamaño
        caso2_resize.setCoeficienteV3(0, 8);   // Coeficiente en x^0: 8
        caso2_resize.setCoeficienteV3(5, -3);  // Coeficiente en x^5: -3
        caso2_resize.setCoeficienteV3(2, 9);   // Coeficiente en x^2: 9
        caso2_resize.setCoeficienteV3(-12, 2); // Coeficiente en x^-12: 2
        caso2_resize.setCoeficienteV3(9, 5);   // Coeficiente en x^9: 5
        caso2_resize.setCoeficienteV3(12, 4);  // Coeficiente en x^12: 4
        caso2_resize.resize(15); // Redimensionar el polinomio vacío para incluir el grado 15
        cout << "caso2_resize: " << endl;
        cout << caso2_resize;
        // Debería imprimir: P(x): 4x^12 + 5x^9-3x^5 + 9x^2 + 8
        // Debería mostrar un mensaje de advertencia por el intento de redimensionar el polinomio para un grado menor al actual
    }
}