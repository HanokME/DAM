#include <iostream>
#include <cmath>
using namespace std;

int main(){

        int segundos_usuario = 0.0;
        int dias = 0.0, horas = 0.0, minutos = 0.0, segundos = 0.0;
        
        cout << "bienvenido a un programa en el que se calcula los dias, horas, minutos y segundos, partiendo de un número introducido(segundos)..." << endl;
        
        cout << "Introducelos segundosque quiera calcular, importante, sin negativos, caracteres y decimales: ";
        cin >> segundos_usuario;
        
        /*dias = segundos_usuario / 86400;
        horas = segundos_usuario / 3600;
        minutos = segundos_usuario / 60;
        segundos = segundos_usuario % 60;*/
        dias = segundos_usuario / 86400;
        horas = segundos_usuario / 3600;
        segundos_usuario = segundos_usuario % 3600;
        minutos = segundos_usuario / 60;
        segundos = segundos_usuario % 60;
        cout << "Días totales calculados: " << dias << endl;
        cout << "Horas totales calculadas: " << horas << endl;
        cout << "Minutos totales calculados: " << minutos << endl;
        cout << "Segundos totales calculados: " << segundos << endl;

}
