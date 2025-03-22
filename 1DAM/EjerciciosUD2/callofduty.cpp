#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

/**
 * @file cllofduty.cpp
 * @brief Programa que coge el centro y el radio de 2 circunferencias y calcula la distancia entre los puntos
 * @date 14/11/2023
 * @author Hanok
 * @version 1.0
 */

int main(){

        //COORDENADAS X1,Y1(CIRCULO1) X2,Y2(CIRCULO2)
        double x1 = 0.0;
        double x2 = 0.0;
        double y1 = 0.0;
        double y2 = 0.0;
        
        //RADIOS DE AMBAS CIRCUNFERENCIAS
        double radio1 = 0.0;
        double radio2 = 0.0;
        
        //DISTANCIA ENTRE PUNTOS
        double distancia = 0.0;
        
        //BIENVENIDA Y ENTRADA DE DATOS
        cout << "Bienvenido a un programa que mediante la introduccion de coordenadas de 2 circunferencias, te dice la distancia entre cada uno." << endl;
        cout << "Introduce la coordenada x del centro de la primera circunferencia: ";
        cin >> x1;
        cout << "Introduce la coordenada y del centro de la primera circunferencia: ";
        cin >> y1;
        cout << "Introduce el radio de la primera circunferencia: ";
        cin >> radio1;
        
        cout << "Introduce la coordenada x del centro de la segunda circunferencia: ";
        cin >> x2;
        cout << "Introduce la coordenada y del centro de la segunda circunferencia: ";
        cin >> y2;
        cout << "Introduce el radio de la segunda circunferencia: ";
        cin >> radio2;
        
        //CALCULO DE LA DISTANCIA ENTRE PUNTOS
        distancia = sqrt(pow((x2 - x1),2.0) + pow((y2 - y1),2.0));
        
        //EMPEZAMOS A COMPARAR DISTANCIAS
        if(distancia == 0){
                cout << "Concéntrica (HEADSHOT)" << endl;
        } else if(distancia == radio1 - radio2){
                cout << "Tangente interior (LE HAS REVENTAO LA MITAD DE LA CARA!)" << endl;
        } else if((distancia < radio1 + radio2) && (distancia > radio1 - radio2)){
                cout << "Secante (LE HAS DADO EN LA OREJA)" << endl;
        } else if(distancia == radio1 + radio2){
                cout << "Tangente exterior (LE HA ROZAO LA OREJA)" << endl;
        } else if ( ((x1 == x2) && (y1 == y2)) && (radio1 != radio2) ){
                cout << "Inscrita" << endl;
        } else{
                cout << "Exterior (NI HA ESCUCHAO LA BALA)" << endl;
        }


}




