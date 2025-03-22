//
//  ejemplovectoresmodulos.cpp
//
//
//  Created by Jaime Matas Bustos on 11/1/17.
//
//

#include <iostream>
#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
using namespace std;

/**
 * @brief Módulo que agrega un nuevo número entero en el vector de enteros, al final de las componentes utilizadas.
 * EJEMPLO:
 ENTRADA v = { 4 2 7 ? ? ? ? ... ? } util = 3 DIM_VECTOR = 2000 entero = 3
 SALIDA  v = { 4 2 7 3 ? ? ? ... ? } util = 4 DIM_VECTOR = 2000 entero = 3
 
 * @pre El número entero que queremos insertar está filtrado.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por REFERENCIA porque SÍ se va a cambiar el número de componentes utilizadas en el vector.
 * @param DIM_VECTOR Es la constante que me indica la DIMENSIÓN del vector, esto es el número máximo de componentes que podré utilizar. Es fijo y no se puede alterar.
 * @param entero Es el nuevo número entero que quiero insertar en el vector.
 */
void agregarNuevoEnteroenVectorEnteros(int vector[], int &util_vector, const int DIM_VECTOR, int entero){
    // Comprueba que la util no sea mayor que la dimensión y añade el entero en la siguiente posicion libre (util_vector), despues actualiza la util
    if(util_vector < DIM_VECTOR){
        vector[util_vector] = entero;
        util_vector++;
    }
}


/**
 * @brief Módulo que imprimirá por pantalla un vector de enteros.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de sólo lectura del vector, lo paso como referencia constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por COPIA porque NO se va a cambiar el número de componentes utilizadas en el vector.
 * @post Se imprimirá por la pantalla de la consola el contenido del vector.
 */
void imprimeVectorEnteros(const int vector[], int util_vector){
    cout << "Vector Enteros = { ";
    for (int i=0; i < util_vector; i++){
        cout << vector[i] << " ";
    }
    cout << "}" << endl;
}

/**
 * @brief Módulo que dobla el valor de cada componente del vector de enteros.
 *    Ejemplo: ENTRADA: v = { 4 2 7 } SALIDA: v = { 8 4 14 }
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por COPIA porque NO se va a cambiar el número de componentes utilizadas en el vector.
 * @pre util_vector deberá ser >=0 y < DIM_VECTOR
 * @post El vector cambiará sus valores y serán el doble.
 * @author
 * @version
 */
void doblarValoresDelVectorEnteros(int vector[], int util_vector){
    cout << USER << "Doblando el valor del contenido de las componentes del vector, por favor tenga paciencia..." << RESTORE << endl;
    //cout << DEBUG << "debug: El valor de las utiles antes del bucle es: " << util_vector << RESTORE <<  endl;
    for (int i=0; i < util_vector; i++){
      //  cout << DEBUG << "debug: Entrada en el bucle para doblar valores del vector..." << RESTORE << endl;
        vector[i]  = 2 * vector[i];
    }
    cout << USER << "Se dobló correctamente el vector... Lo comprobará cuando vuelva a imprimirlo..." << RESTORE << endl;
}

/**
 * @brief Módulo que copia vector[i] de un vector de entrada en v[i] de un vector de salida
 * @param vector[] vector de entrada que contiene los enteros a copiar
 * @param DIM_VECTOR dimensión máxima del vector de entrada
 * @param util_vector primera posicion libre del vector y cantidad de componentes activos del vector de entrada
 * @param vector_final[] vector de salida en el que vas a copiar los valores
 * @param DIM_VECTOR_FINAL dimensión máxima del vector final
 * @param util_vector_final primera posicion libre del vector y cantidad de componentes activos del vector de salida
 * @pre utiles de los vectores deberán ser <= DIM_VECTORES
 * @post Los valores del vector de entrada ahora también están en el vector de salida
 * @author Hanok
*/
void copiar_vector_entrada_en_vector_salida(const int vector[], const int DIM_VECTOR, int util_vector, int vector_final[], const int DIM_VECTOR_FINAL, int &util_vector_final){

    for (int i=0; i < util_vector; i++){
        vector_final[i] = vector[i];
        util_vector_final++;
    }
    
}

int main(){
    const int DIM_VECTOR = 2000;
    int vector[DIM_VECTOR] = {4,2,7}; //se inicializan las tres primeras componentes y el resto a 0
    int util_vector = 3; //inicializo a 3 porque he llenado el vector en la inicialización

    const int DIM_VECTOR_FINAL = 2000;
    int vector_final[DIM_VECTOR_FINAL] = {0};
    int util_vector_final = 0;
    
    cout << USER << "****** EJEMPLO DE VECTORES Y MODULARIZACIÓN ********" << RESTORE << endl;
    imprimeVectorEnteros(vector, util_vector); //{4,2,7}
    doblarValoresDelVectorEnteros(vector, util_vector);

    cout << "Resultados de doblar valores: " << endl;
    imprimeVectorEnteros(vector, util_vector); //{8,4,14}
    agregarNuevoEnteroenVectorEnteros(vector,util_vector, DIM_VECTOR, -1);

    cout << "Resultados de agregar un entero a vector de enteros: " << endl;
    imprimeVectorEnteros(vector, util_vector);


    cout << "Los valores del vector final antes de copiar son: " << endl;
    for ( int i = 0; i < util_vector_final; i++ ){

        cout << vector_final[i] << " | ";

        
    }
    cout << endl;
    copiar_vector_entrada_en_vector_salida(vector, DIM_VECTOR, util_vector, vector_final, DIM_VECTOR_FINAL, util_vector_final);

    cout << "Resultados de copiar un vector de entrada en otro de salida: " << endl;
    imprimeVectorEnteros(vector_final, util_vector_final);
    
}