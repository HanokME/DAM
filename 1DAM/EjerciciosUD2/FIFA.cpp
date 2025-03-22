#include <iostream>
#include <cmath>
#include "colors.h"

using namespace std;

/**
 * @file FIFA.cpp
 * @brief Programa en el que se introduce unas coordenadas validas de una porteria y el usuario "chuta" el balón  
 * @date 13/11/2023
 * @author Hanok
 * @version 1.0
 */

int main(){

        //DELIMITACION DE PORTERIA
        double xmax = 0.0;
        double xmin = 0.0;
        double ymax = 0.0;
        double ymin = 0.0;
        
        //CHUTAR EL BALON
        double xbalon = 0.0;
        double ybalon = 0.0;
        
        cout << "Bienvenido a una portería virtual..." << endl;
        cout << "Primero las reglas: " << endl;
        cout << "Vas a delimitar una portería que mida 7 metros de largo x 2 metros de alto, importante que sea en valor positivo." << endl;
        cout << "Fuera de ahí no serán válidas las medidas." << endl;
        cout << "A continuación chutarás hacia una trayectoria concreta y el programa decidirá si ha sido gol o no." << endl;
        
        cout << "Vamos a delimitar..." << endl;
        cout << "Introduce el punto bajo izquierdo de la portería: ";
        cin >> xmin;
        cout << "Introduce el punto bajo derecho de la portería: ";
        cin >> xmax;
        cout << "Introduce el punto alto izquierdo de la portería: ";
        cin >> ymin;
        cout << "Introduce el punto alto derecho de la portería: ";
        cin >> ymax;
        
        //CONDICION QUE COMPARA SI LA DIFERENCIA ENTRE MIN Y XMAX ES 7 Y YMAX YMIN ES 2
        if ( (xmax - xmin == 7.0) && (ymax - ymin == 2.0) ){
                
                //COORDENADAS DE TIRO
                cout<< "Introduce las coordenadas donde quieres que vaya el balón..." << endl;
                cout << "Coordenadas x: ";
                cin >> xbalon;
                cout << "Coordenadas y: ";
                cin >> ybalon;
                
                //CONDICION DENTRO DE LA PORTERIA
                if ( ((xbalon >= xmin) && (xbalon <= xmax)) && ((ybalon >= ymin) && (ybalon <= ymax)) ){
                        
                        //CONDICION PARA EL PALO
                        if((ybalon == ymin) || (ybalon == ymax)){
                                cout << ORANGE << "Le has dado al palo!!" << RESET << endl;
                        
                        //CONDICION PARA EL LARGUERO
                        } else if((xbalon == xmin) || (xbalon == xmax)){
                                cout << ORANGE << "Al larguerooo!!" << RESET << endl;
                        
                        //CONDICION PARA LA ESCUADRA
                        } else if(( (xbalon == xmax) || (xbalon == xmin) ) && ( (ybalon == ymin) || (ybalon == ymax) )){
                                cout << ORANGE << "A la escuadra!!" << RESET << endl;
                        
                        //LO QUE SOBRA ES GOL
                        }else{
                                cout << GREEN << "Gooool!!" << RESET << endl;
                        }
                //EL BALON ESTA FUERA
                } else{
                
                        if(y < ymin){
                                cout << "Golpe al suelo!!" << endl;
                        } else {
                                cout << "Ha sido fuera!!" << endl;
                        }
                
                }

        }  


}
