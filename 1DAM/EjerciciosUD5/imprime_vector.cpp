#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Módulo que se encarga de sacar por pantalla todos los valores que alberga el vector
 * @param Vector[] donde están guardados los valores.
 * @param util_vector posición libre del vector y componentes activos del vector.
 * @pre vector[i] >= 0 | util_vector <= DIM_V.
 * @version 1.1
 * @author Hanok
*/
void imprimir_valores_del_vector(const int vector[], int util_vector);

/**
 * Módulo que se encarga de procesar si un valor de vector[i] es par o no
 * @param Vector[] donde están guardados los valores.
 * @param util_vector posición libre del vector y componentes activos del vector.
 * @pre vector[i] >= 0 | util_vector <= DIM_V.
 * @return vector[i] true o false.
 * @version 1.1
 * @author Hanok
*/
bool es_par(const int numero);

/**
 * @brief Módulo que se encarga de leer vector[i] y guardar en el vector_par[] los números pares
 * @param vector[] donde están guardados los valores.
 * @param util_vector posición libre del vector y componentes activos del vector.
 * @param vector_par[] vector donde se van a guardar los números pares.
 * @param util_vector_par posición libre del vector y componentes activos del vector.
 * @pre vector[i] >= 0 | util_vector <= DIM_VECTOR.
 * @post vector_par[] contiene los números pares que había en vector[]
 * @version 1.1
 * @author Hanok
*/
void guardar_pares_vector(const int vector[], int util_vector, int vector_par[], int &util_vector_par);

/**
 * @brief Módulo que se encarga de multiplicar por dos todos los valores que alberga el vector
 * @param Vector[] donde están guardados los valores.
 * @param DIM_VECTOR Dimensión máxima del vector
 * @param util_vector posición libre del vector y componentes activos del vector.
 * @pre vector[i] >= 0 | util_vector <= DIM_VECTOR.
 * @post vector[i] * 2.
 * @version 1.1
 * @author Hanok
*/
void calcular_valor_doble(int vector[], int util_vector);

/**
 * @brief Módulo que se encarga de pedir por pantalla al usuario que introduzca los valores y guardarlo en el vector.
 * @param Vector[] donde se guardaran los valores.
 * @param DIM_VECTOR dimensión máxima del vector
 * @param util_vector posición libre del vector y componentes activos del vector
 * @post vector[i] >= 0 | util_vector <= DIM_VECTOR
 * @version 1.1
 * @author Hanok
*/
void introducir_valores_en_vector(int vector[], const int DIM_VECTOR, int &util_vector);



int main(){

    const int DIM_VECTOR = 100;
    int vector[DIM_VECTOR] = {0}; 
    int util_vector = 0;

    const int DIM_VECTOR_PARES = 100;
    int vector_par[DIM_VECTOR_PARES] = {0};
    int util_vector_par = 0;

    cout << "Hola, bienvenido a un programa en el que introduces valores y saca por pantalla los valores que son pares,"; 
    cout << "además los valores introducidos luego se multiplicarán por dos y también saldrán por pantalla los resultados." << endl;

    introducir_valores_en_vector(vector, DIM_VECTOR, util_vector);

    guardar_pares_vector(vector, util_vector, vector_par, util_vector_par);
    cout << "Los valores pares del vector son: " << endl;
    imprimir_valores_del_vector(vector_par, util_vector_par);

    calcular_valor_doble(vector, util_vector);
    imprimir_valores_del_vector(vector, util_vector);
}

void introducir_valores_en_vector(int vector[], const int DIM_VECTOR, int &util_vector){

    do{

        cout << "Cuantos valores enteros vas a introducir: ";
        cin >> util_vector;
        if(util_vector <= 0){
            cout << "Debes introducir un numero mayor a 0" << endl;
        }
    } while (util_vector <= 0 || util_vector > DIM_VECTOR);

    for(int i = 0; i < util_vector; i++){
        cout << "Ingrese el valor " << i+1 << ": ";
        cin >> vector[i];
    }

}

void guardar_pares_vector(const int vector[], int util_vector, int vector_par[], int &util_vector_par){
    util_vector_par = 0;

    for(int i = 0; i < util_vector; i++){
        if(es_par(vector[i])){
            vector_par[util_vector_par] = vector[i];
            util_vector_par++;
        }
    }


}

bool es_par(const int numero){

    bool es_par = false;

    if(numero % 2 == 0){
        es_par = true;
    }

    return es_par;
}

void calcular_valor_doble(int vector[], int util_vector){

    for(int i = 0; i < util_vector; i++){
        vector[i] *= 2;
    }

}

void imprimir_valores_del_vector(const int vector[], int util_vector){

    for(int i = 0; i < util_vector; i++){
        cout << vector[i] << " | ";
    }
    cout << endl;

    cout << "Util del vector: " << util_vector << endl;
}
