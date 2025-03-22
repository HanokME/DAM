#include <iostream>
using namespace std;

int main(){

        double teoria = 0.7, practica = 0.2, problema = 0.1;
        double notaT = 0.0, notaPT = 0.0, notaPB = 0.0;
        
        double calificacionT = 0.0, calificacionPT = 0.0, calificacionPB = 0.0, calificacionFinal = 0.0;
        
        cout << "Bienvenido a un programa que calcula la calificación que tienes dependiendo de las notas introducidad..." << endl;
        
        cout << "Introduce la nota de la teoría, práctica y problemas consecutivamente separados por un espacio: ";
        cin >> notaT >> notaPT >> notaPB;
        
        calificacionT = notaT * teoria;
        calificacionPT = notaPT * practica;
        calificacionPB = notaPB * problema;
        calificacionFinal = calificacionT + calificacionPT + calificacionPB;
        
        cout << "Resultado de la calificacion de la teoría: " << calificacionT << endl;
        cout << "Resultado de la calificacion de la práctica: " << calificacionPT << endl;
        cout << "Resultado de la calificacion de los problemas: " << calificacionPB << endl;
        cout << "Resultado de la calificacion final " << calificacionFinal << endl;


}
