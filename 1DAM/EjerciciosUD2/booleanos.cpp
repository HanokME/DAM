#include <iostream>
#include <cmath>
using namespace std;

int main(){

        
        int valorEntero = 0;
        double valorReal = 0.0;
        bool apartado_1 = false;
        bool apartado_2 = false;
        bool apartado_3 = false;
        bool apartado_4 = false;
        bool apartado_5 = false;
        bool apartado_6 = false;
        bool apartado_7 = false;
        
        //APARTADO 1
        cout << "Ingrese un valor entero para el apartado 1: ";
        cin >> valorEntero;
        apartado_1 = (valorEntero >= 1) && (valorEntero <= 6);
        cout << "El valor de la expresión booleana del apartado 1 es: " << apartado_1 << endl;
        
        //APARTADO 2
        cout << "Ingrese un valor real para el apartado 2: ";
        cin >>valorReal;
        apartado_2 = (valorReal <= -5 || valorReal >= 5);
        cout << "El valor de la expresión booleana del apartado 2 es: " << apartado_2 << endl;
        
        //APARTADO 3
        cout << "Ingrese un valor real para el apartado 3: ";
        cin >>valorReal;        
        apartado_3 = !((valorReal >= -5) && (valorReal <= 3));
        cout << "El valor de la expresion booleana del apartado 3 es: " << apartado_3 << endl; 
        
        //APARTADO 4
        cout << "Ingrese un valor real para el apartado 4: ";
        cin >>valorReal;
        apartado_4 = (((valorReal >= 1 && valorReal <= 3)) || (valorReal >= 10 && valorReal < 20));
        cout << "El valor de la expresion booleana del apartado 4 es: " << apartado_4 << endl;
        
        //APARTADO 5        
        cout << "Ingrese un valor entero para el apartado 5: ";
        cin >>valorEntero;
        apartado_5 = ( (valorEntero >= 0 && valorEntero <= 10) && ((valorEntero % 2 == 0) || (valorEntero % 2 != 0)) );
        cout << "El valor de la expresion booleana del apartado 5 es: " << apartado_5 << endl;
        
        //APARTADO 6
        cout << "Ingrese un valor real para el apartado 6: ";
        cin >>valorReal;
        apartado_6 = ( ((valorReal >= 0) && (valorReal <= 10)) || ((valorReal >= 20) && (valorReal <= 30)) );
        cout << "El valor de la expresion booleana del apartado 6 es: " << apartado_6 << endl;
        
        //APARTADO 7
        cout << "Ingrese un valor real para el apartado 7: ";
        cin >>valorReal;
        apartado_7 = !( ((valorReal >= 0) && (valorReal < 10)) || ((valorReal > 20) && (valorReal <= 30)) );
        cout << "El valor de la expresion booleana del apartado 7 es: " << apartado_7 << endl;

}
