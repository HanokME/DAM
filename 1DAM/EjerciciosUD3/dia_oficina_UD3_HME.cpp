#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * @brief Modulo que contiene el main del ejercicio parking 
 * @post Se ha pedido, calculado y mostrado todo lo referente al parking
 * @version 
 * @author Hanok
 */
void parking();

/**
 * @brief Modulo que muestra por pantalla la bienvenida al programa
 * @post Se ha mostrado la bienvenida al programa
 * @version 
 * @author Hanok
 */
void bienvenidaParking();

/**
 * @brief Modulo que le permite introducir al usuario el número de horas que han estacionado cada coche
 * @param double &hora1 (S) parametro de introducción de la hora de un determinado coche
 * @param double &hora2 (S) parametro de introducción de la hora de un determinado coche
 * @param double &hora3 (S) parametro de introducción de la hora de un determinado coche
 * @post Se ha pedido las horas de estacionamiento de cada coche.
 * @version 
 * @author Hanok
 */
void introducir_horas(double &hora1, double &hora2, double &hora3);

/**
 * @brief Modulo que calcula el total de horas
 * @param double hora1 (E) parametro que contiene la hora1
 * @param double hora2 (E) parametro que contiene la hora2
 * @param double hora3 (E) parametro que contiene la hora3
 * @return double total de horas calulado
 * @pre hora1, hora2, hora3 > 0
 * @post Se ha calculado el total de horas
 * @version 
 * @author Hanok
 */
double calcular_total_horas(double hora1, double hora2, double hora3);

/**
 * @brief Modulo que calcula el cargo dependiendo de las horas de estacionamiento de cada coche
 * @param double &hora1 (S) parametro que contiene la hora1 del coche 1
 * @param double &hora2 (S) parametro que contiene la hora2 del coche 2
 * @param double &hora3 (S) parametro que contiene la hora3 del coche 3
 * @param double &cargo1 (S) parametro para guardar el calculo del cargo individual
 * @param double &cargo2 (S) parametro para guardar el calculo del cargo individual
 * @param double &cargo3 (S) parametro para guardar el calculo del cargo individual
 * @param duble &total_cargos (S) parametro que guarda el total de los cargos de los vehiculos
 * @pre hora1, hora2, hora3 > 0
 * @post Se ha calculado el cargo parada cada coche y el total cargado.
 * @version 
 * @author Hanok
 */
void calcular_cargos(double &hora1, double &hora2, double &hora3, double &cargo1, double &cargo2, double &cargo3, double &total_cargos);

/**
 * @brief Modulo que muestra por pantalla una tabla que contiene todos los datos necesarios para el parking
 * @param double hora1 (E) parametro que contiene la hora1 del coche 1
 * @param double hora2 (E) parametro que contiene la hora2 del coche 2
 * @param double hora3 (E) parametro que contiene la hora3 del coche 3
 * @param double cargo1 (E) parametro que contiene el cargo del coche1
 * @param double cargo2 (E) parametro que contiene el cargo del coche2
 * @param double cargo3 (E) parametro que contiene el cargo del coche3
 * @param double total_cargos (E) parametro que contiene el total de los cargos de los vehiculos
 * @param double total_horas (E) parametro que contiene el total de lashoras calculadas
 * @pre hora1, hora2, hora3 > 0 / cargo1, cargo2, cargo3, total_cargos calculado 
 * @post Se ha mostrado por pantalla la tabla con los datos necesarios para el parking
 * @version 
 * @author Hanok2.5

 */
void mostrar_resultados_parking(double hora1, double hora2, double hora3, double cargo1, double cargo2, double cargo3, double total_cargos, double total_horas);

int main(){

        parking();

}

void parking(){

        bienvenidaParking();
        
        double hora1 = 0.0, hora2 = 0.0, hora3 = 0.0;
        double total_cargos = 0.0, horas_totales = 0.0;
        double cargo1 = 0.0, cargo2 = 0.0, cargo3 = 0.0;
        
        introducir_horas(hora1, hora2, hora3);
        
        horas_totales = calcular_total_horas(hora1, hora2, hora3);
        
        calcular_cargos(hora1, hora2, hora3, cargo1, cargo2, cargo3, total_cargos);

        mostrar_resultados_parking(hora1, hora2, hora3, cargo1, cargo2, cargo3, total_cargos, horas_totales);

}

void bienvenidaParking(){

        cout << "Bienvenido al parking virtual Cristo Rey." << endl;

}

void introducir_horas(double &hora1, double &hora2, double &hora3){


        do{
                cout << "Introduce las horas que ha estado estacionado el coche 1: ";
                cin >> hora1;
        }while(hora1 <= 0);
        
        do{
                cout << "Introduce las horas que ha estado estacionado el coche 2: ";
                cin >> hora2;
        }while(hora2 <= 0);
        
        do{
                cout << "Introduce las horas que ha estado estacionado el coche 3: ";
                cin >> hora3;
        }while(hora3 <= 0);


}

double calcular_total_horas(double hora1, double hora2, double hora3){

        double total_horas = 0.0;
        
        total_horas = hora1 + hora2 + hora3;
        
        return total_horas;

}

void calcular_cargos(double &hora1, double &hora2, double &hora3, double &cargo1, double &cargo2, double &cargo3, double &total_cargos){

        if(hora1 <= 3.0){
        
                cargo1 = 2.0;
        
        }else if(hora1 > 3.0 && hora1 < 24.0){
                cargo1 = 2.0;
                
                for(double i = 3.0; i <= hora1; i = i + 2.0){
                        
                        cargo1 = cargo1 += 0.5;
                        
                }
        }else if(hora1 = 24.0){
                
                cargo1 = 10.0;
                
        }
        
        if(hora2 <= 3.0){
        
                cargo2 = 2.0;
        
        }else if(hora2 > 3.0 && hora2 < 24.0){
                
                cargo2 = 2.0;
                
                for(double i = 3.0; i <= hora2; i = i + 2.0){                        
                        
                        cargo2 += 0.5;
                        
                } 
                
        }else if(hora2 = 24.0){
                
                cargo2 = 10.0;
                
        }
        
        if(hora3 <= 3.0){
        
                cargo3 = 2.0;
        
        }else if(hora3 > 3.0 && hora3 < 24.0){
                
                cargo3 = 2.0;
                
                for(double i = 3.0; i <= hora3; i = i + 2.0){
                        
                        cargo3 += 0.5;
                        
                }
                
        }else if(hora3 = 24.0){
                
                cargo3 = 10.0;
                
        }
        
        
        total_cargos = cargo1 + cargo2 + cargo3;

}

void mostrar_resultados_parking(double hora1, double hora2, double hora3, double cargo1, double cargo2, double cargo3, double total_cargos, double total_horas){

        cout << "Automóvil" << "\tHoras" << "\tCargo" << endl;
        cout << "1\t" << "\t" << hora1 << "\t" << cargo1 << endl;
        cout << "2\t" << "\t" << hora2 << "\t" << cargo2 << endl;
        cout << "3\t" << "\t" << hora3 << "\t" << cargo3 << endl;
        cout << "TOTAL\t" << "\t" << total_horas << "\t" << total_cargos << endl;

}





