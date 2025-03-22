#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Módulo que saca por pantalla los resultados de los calculos
 * @param media (E) Media calculada de unos valores.
 * @param varianza (E) Varianza calculada de unos valores.
 * @param desvicion (E) Desviacion calculada de la media.
 * @post los resultados han sido mostrados.
*/
void imprimir_resultados(double media, double varianza, double desviacion);

/**
 * @brief Módulo que calcula la desviación estándar de un conjunto de valores.
 * @param varianza (E) Varianza calculada de los valores.
 * @pre varianza calculada
 * @return Desviación de la media calculada
 * @version 3.0
 * @author Hanok
 */
double calcularDesviacion(double varianza);

/**
 * @brief Módulo que calcula la varianza de los valores de un vector
 * @param v_notas[] (E) vector que guarda los valores introducidos por el usuario
 * @param V_NOTAS_MAX (E) Número de componentes máximo del vector
 * @param util_v_notas (E) posición libre del vector y cantidad de componentes activos.
 * @param media Media (E) calculada de los valores del vector
 * @pre v_notas[i] >= 0 | util_v_notas <= V_NOTAS_MAX | media ya calculada
 * @return Varianza de los valores calculada.
 * @version 3.0
 * @author Hanok
*/
double calcularVarianza(double v_notas[], const int V_NOTAS_MAX, int util_v_notas, double media);

/**
 * @brief Módulo que calcula la media de los valores que hay en el vector
 * @param v_notas (E) vector que guarda los valores introducidos por el usuario
 * @param V_NOTAS_MAX (E) Número de componentes máximo del vector
 * @param util_v_notas (E) posición libre del vector y cantidad de componentes activos.
 * @pre v_notas[i] >= 0 | util_v_notas <= V_NOTAS_MAX
 * @return Media de los valores introducidos por el usuario
 * @version 3.0
*/
double calcularMedia(const double v_notas[], const int V_NOTAS_MAX, int util_v_notas);

/*
 * @brief Módulo que se encarga de pedir por pantalla al usuario que introduzca la util y los valores y guardarlo en el vector.
 * @param v_notas[] (S) donde se guardaran los valores.
 * @param V_NOTAS_MAX (E) dimensión máxima del vector
 * @param util_v_notas (S) posición libre del vector y componentes activos del vector
 * @post v_notas[i] >= 0 | util_v_notas <= V_NOTAS_MAX
 * @version 3.0
 * @author Hanok
*/
void introducir_valores_y_util_de_vector(double v_notas[], const int V_NOTAS_MAX, int &util_v_notas, int &maximo_notas);


int main(){
    //DECLARACIÓN DE VARIABLES Y CONSTANTES
    const int V_NOTAS_MAX = 50;
    double v_notas [V_NOTAS_MAX]; //Vector de notas
    int util_v_notas = 0;
    double desviacion = 0.0;
    double varianza = 0.0;
    double media = 0.0;
    int maximo_notas = 0;
    
    cout << "\tBienvenido al programa que va a calcular la media, desviación y varianza de una serie de notas de alumnos." << endl;
    cout << "\tEstas notas deberán ser números enteros o reales entre 0 y 10." << endl;

    introducir_valores_y_util_de_vector(v_notas, V_NOTAS_MAX, util_v_notas, maximo_notas);
    media = calcularMedia(v_notas, V_NOTAS_MAX, util_v_notas);
    varianza = calcularVarianza(v_notas, V_NOTAS_MAX, util_v_notas, media);
    desviacion = calcularDesviacion(varianza);
    imprimir_resultados(media, varianza, desviacion);

}

void introducir_valores_y_util_de_vector(double v_notas[], const int V_NOTAS_MAX, int &util_v_notas, int &maximo_notas){

    do
    {

        cout << "\tIntroduce el número total de notas que quieres calcular, el máximo es " << V_NOTAS_MAX << " notas: ";
        cin >> maximo_notas;

    } while ( maximo_notas < 0 || maximo_notas > V_NOTAS_MAX );

    //Bucle para introducir las notas de alumno
    for (int i = 0; i < maximo_notas; i++){    

        do{
            cout << "\tIngrese la nota del alumno " << i + 1 << ": ";
            cin >> v_notas[i];
        } while ( v_notas[i] < 0 || v_notas[i] > 10);

        util_v_notas++;
           
    }

}

double calcularMedia(const double v_notas[], const int V_NOTAS_MAX, int util_v_notas){

    double media = 0.0;

    for (int i = 0; i < util_v_notas; i++){
        media += v_notas[i];

    }
    
    media /= util_v_notas;

    return media;
}

double calcularVarianza(double v_notas[], const int V_NOTAS_MAX, int util_v_notas, double media){

    double varianza = 0.0;

    //Bucle que recorra el vector de notas y calcula la diferencia entre cada una de las notas al cuadrado para calcular la varianza
    for (int i = 0; i < util_v_notas; i++){
        varianza += pow(v_notas[i] - media, 2); 
    }

    varianza /= util_v_notas; //Calcula la varianza de las notas

    return varianza;
}

double calcularDesviacion(double varianza){

    double desviacion = 0.0;

    desviacion = sqrt(varianza);
    
    return desviacion;
    
}

void imprimir_resultados(double media, double varianza, double desviacion){

    cout << "\tLa media de las notas es: " << media << endl;
    cout << "\tLa varianza de las notas es: " << varianza << endl;
    cout << "\tLa desviacion de las notas es: " << desviacion << endl;
}