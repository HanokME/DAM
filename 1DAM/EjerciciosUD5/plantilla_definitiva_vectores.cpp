

#include <iostream>
#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
using namespace std;

/**
 * @brief Módulo que elimina los valores repetidos de un vector de entrada y copia los valores en un vector de salida.
 * @param vector_entrada[] Vector de entrada que contiene los elementos a procesar.
 * @param util_vector_entrada Tamaño útil del vector de entrada.
 * @param DIM_VECTOR_ENTRADA Dimension del vector de entrada.
 * @param vector_salida[] Vector de salida donde se copiarán los elementos sin repetir.
 * @param util_vector_salida Tamaño útil del vector de salida.
 * @param DIM_VECTOR_SALIDA Dimension del vector de salida.
 * @pre vector_entrada[i] > 0
 * @post vector_salida contendrá los elementos de vector_entrada sin repetir.
 * @version 1.0
 * @author Hanok
*/
void eliminarRepetidosContiguos(int vector_entrada[], int util_vector_entrada, const int DIM_VECTOR_ENTRADA, int vector_salida[], int &util_vector_salida, const int DIM_VECTOR_SALIDA);

/**
 * @brief Módulo que intercambia los valores de un vector de entrada y un vector de salida.
 * @param vector_entrada[] Vector de entrada que contiene los elementos a intercambiar
 * @param util_vector_entrada Tamaño útil del vector de entrada.
 * @param DIM_VECTOR_ENTRADA Dimension del vector de entrada.
 * @param vector_salida[] Vector de salida con los valores que se van a intercambiar.
 * @param util_vector_salida Tamaño útil del vector de salida.
 * @param DIM_VECTOR_SALIDA Dimension del vector de salida.
 * @pre DIM_VECTOR_ENTRADA == DIM_VECTOR_SALIDA && util_vector_entrada <= DIM_VECTOR_ENTRADA
 * @pre util_vector_salida <= DIM_VECTOR_SALIDA && util_vector_entrada >= 0 && util_vector_salida >= 0
 * @post vector_salida contendrá los valores de vector_entrada y vector_entrada contendrá los valores de vector_salida.
 * @version 1.0
 * author Hanok
*/
void intercambiarVectores(int vector_entrada[], int util_vector_entrada, const int DIM_VECTOR_ENTRADA, int vector_salida[], int util_vector_salida, const int DIM_VECTOR_SALIDA);

/**
 * @brief Módulo que se encarga de leer vector[i] y guardar en el vector_par[] los números primos
 * @param vector[] donde están guardados los valores.
 * @param util_vector posición libre del vector y componentes activos del vector.
 * @param vector_primos[] vector donde se van a guardar los números pares.
 * @param util_vector_primos posición libre del vector y componentes activos del vector.
 * @pre vector[i] >= 0 | util_vector <= DIM_VECTOR.
 * @post vector_par[] contiene los números primos que había en vector[i]
 * @version 1.0
 * @author Hanok
*/
void guardar_primos_vector(const int vector[], int util_vector, int vector_primos[], int &util_vector_primos);

/**
 * @brief Módulo que se encarga de procesar si un valor de vector[i] es primo o no.
 * @param n Número a procesar.
 * @pre vector[i] > 0
 * @post vector[i] es primo o no.
 * @version 1.0
 * @author Hanok
 * 
*/
bool esPrimo(int n);

/**
 * @brief Módulo que se encarga de procesar si un valor de vector[i] es par o no
 * @param numero Número a evaluar.
 * @pre vector[i] >= 0 
 * @post vector[i] true o false.
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
 * @brief Módulo que se encarga de comparan la util con la dimensión para saber en todo momento si la util es mas pequeña o no que la dimension del vector
 * @param util_v_notas (E) util del vector 
 * @param DIM_V_NOTAS (E) dimension del vector
 * @return true o false de la comparacion
 * @version 1.0
 * @author Hanok
*/
bool preguntarSiUtilesMenorqueDim(int util_v_notas, int DIM_V_NOTAS);

/**
 * @brief Módulo que agrega un nuevo número entero en el vector de enteros, al final de las componentes utilizadas.
 EJEMPLO:
 ENTRADA v = { 4 2 7 ? ? ? ? ... ? } util = 3 DIM_VECTOR = 2000 entero = 3
 SALIDA  v = { 4 2 7 3 ? ? ? ... ? } util = 4 DIM_VECTOR = 2000 entero = 3
 
 * @pre El número entero que queremos insertar está filtrado.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de escritura y lectura del vector, lo paso como referencia SIN constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por REFERENCIA porque SÍ se va a cambiar el número de componentes utilizadas en el vector.
 * @param DIM_VECTOR Es la constante que me indica la DIMENSIÓN del vector, esto es el número máximo de componentes que podré utilizar. Es fijo y no se puede alterar.
 * @param entero Es el nuevo número entero que quiero insertar en el vector.
 * @pre util_vector < DIM_VECTOR
 */
void agregarNuevoEnteroenVectorEnteros(int vector[], int &util_vector, const int DIM_VECTOR, int entero);


/**
 * @brief Módulo que imprimirá por pantalla un vector de enteros.
 * @param vector Es una referencia al vector de números enteros. Al ser un módulo de sólo lectura del vector, lo paso como referencia constante.
 * @param util_vector Es la variable que contiene las componentes utilizadas/ocupadas actualmente en el vector. Se pasa por COPIA porque NO se va a cambiar el número de componentes utilizadas en el vector.
 * @post Se imprimirá por la pantalla de la consola el contenido del vector.
 */
void imprimeVectorEnteros(const int vector[], int util_vector);

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
void doblarValoresDelVectorEnteros(int vector[], int util_vector);

/**
 * @brief Copia el contenido de un vector de entrada de tipo int en otro vector de salida de tipo int
 *  EJEMPLO: v_entrada = { 2, 3, 4 } --->  v_salida = { 2, 3, 4}
 * @param const int v_entrada[] (E) Vector de enteros que se pretende copiar
 * @param int util_v_entrada (E) Número de componentes utilizadas hasta el momento en el vector de entrada
 * @param const int DIM_V_ENTRADA (E) Dimensión máxima del vector de entrada
 * @param int v_salida[] (S) Vector de enteros en el que se copiará la información del vector de entrada
 * @param int util_v_salida (S) Nuevo número de componentes utilizadas a partir de ese momento en el vector de salida
 * @param const int DIM_V_SALIDA (E) Dimensión máxima del vector de entrada
 * @pre ¿Qué ocurre con las dimensiones y las utiles de los vectores?
 * @post Se copia el primer vector en el vector de salida y las útiles del vector de salida se verán modificadas.
 */
void copiarVector(const int v_entrada[], int util_v_entrada, const int DIM_V_ENTRADA, int v_salida[], int &util_v_salida, const int DIM_V_SALIDA );

/**
 * @brief Módulo que calcula la moda de un vector de enteros
 * @param vecor vector que contiene los números a analizar
 * @param util_vector util del vector 
 * @return devuelve la moda de un vector
 * @pre util > 0
*/
int calcularModa(const int vector[], int util_vector);

/**
 * @brief Módulo que recibe dos vectores ordenados y lo desordena en un 3 vector
 * @param vecor primer vector con el contendio ordenado
 * @param util_vector util del primer vector
 * @param vector2 segundo vector con el contenido ordenado
 * @param util_vector2 util del segundo vector
 * @param vector_resultado vector donde se van a desordenar los anteriores vectores
 * @param util_resultado util del vector de resultado
 * @param DIM_V_RESULTADO Dimension del vector de resultado
 * @pre vector y vector2 previamente ordenados
 * @post vector_resultado con el contenido desordenado
 * @version 1.0
 * @author Hanok
 * 
*/
void mezclarDosVectoresOrdenados(const int vector[], int util_vector, const int vector2[], int util_vector2, int vector_resultado[], int &util_resultado, const int DIM_V_RESULTADO);


int main(){
    
    const int DIM_VECTOR = 5;
    int vector[DIM_VECTOR] = {1, 3, 5, 7 , 9}; //se inicializan las tres primeras componentes y el resto a 0
    int util_vector = 5; //inicializo a 3 porque he llenado el vector en la inicialización
    const int DIM_VECTOR2 = 4;
    int vector2[DIM_VECTOR2] = {2, 4, 6, 8};
    int util_vector2 = 4;
    const int DIM_VECTOR_RESULTADO = DIM_VECTOR + DIM_VECTOR2;
    int vector_resultado [DIM_VECTOR_RESULTADO];
    int util_vector_resultado = 0;
    int moda = 0;
    
    /**
    cout << USER << "****** EJEMPLO DE VECTORES Y MODULARIZACIÓN ********" << RESTORE << endl;
    imprimeVectorEnteros(vector, util_vector); //{4,2,7}
    //doblarValoresDelVectorEnteros(vector, util_vector);
    //imprimeVectorEnteros(vector, util_vector); //{8,4,14}
    do{
        cout << "Introduce un número: ";
        cin >> numero;
        if (numero != -1){   
            if (util_vector < DIM_VECTOR){ //está aquí puesto para cumplir la PRE-condición del módulo agregarNuevo...
                agregarNuevoEnteroenVectorEnteros(vector,util_vector, DIM_VECTOR, numero);
                imprimeVectorEnteros(vector, util_vector);
            }
            else{
                cout << "ERROR: No hay espacio suficiente en el vector!" << endl;
            }
        }
    } while (numero != -1);

    cout << "****** Y AHORA COPIAMOS EL VECTOR DE ENTRDADA EN OTRO DE SALIDA ****** " << endl;
    copiarVector(vector, util_vector, DIM_VECTOR, vector_resultado, util_vector_resultado, DIM_VECTOR_RESULTADO );
    imprimeVectorEnteros (vector_resultado, util_vector_resultado);

    */

   /**
    cout << "Comienzco de guardar los números pares de un vector en otro: " << endl;   
    guardar_pares_vector(vector, util_vector, vector_resultado, util_vector_resultado);
    imprimeVectorEnteros(vector_resultado, util_vector_resultado); 

    cout << "Comienzo de guardar los números primos de un vector en otro: " << endl;   
    guardar_primos_vector(vector, util_vector, vector_resultado, util_vector_resultado);
    imprimeVectorEnteros(vector_resultado, util_vector_resultado);    

    cout << "Comienzo de guardar los números no repetidos de un vector en otro: " << endl;   
    eliminarRepetidosContiguos(vector, util_vector, DIM_VECTOR, vector_resultado, util_vector_resultado, DIM_VECTOR_RESULTADO);
    imprimeVectorEnteros(vector_resultado, util_vector_resultado);
    */

    
    /*Casos para testar*/
    /**
    //1) Utiles y dimensiones iguales
    const int DIM_V_ENTRADA_C1 = 4;
    int v_entrada_c1[DIM_V_ENTRADA_C1] = {4, 2, 7, 6};
    int util_v_entrada_c1 = 4;
    const int DIM_V_SALIDA_C1 = 4;
    int v_salida_c1[DIM_V_SALIDA_C1] = {1, 1, 1, 1};
    int util_v_salida_c1 = 4;

    cout << DEBUG << "Caso 1 antes de ejecutar: " << RESTORE << endl;
    cout << DEBUG << "DIM_V_ENTRADA_C1 | " << DIM_V_ENTRADA_C1 << " | util_v_entrada_c1 | " << util_v_entrada_c1 << RESTORE << endl;
    cout << DEBUG << "DIM_V_SALIDA_C1 | " << DIM_V_SALIDA_C1 << " | util_v_salida_c1 | " << util_v_salida_c1 << RESTORE << endl;
    copiarVector(v_entrada_c1, util_v_entrada_c1, DIM_V_ENTRADA_C1, v_salida_c1, util_v_salida_c1, DIM_V_SALIDA_C1);
    imprimeVectorEnteros(v_salida_c1, util_v_salida_c1);

    //2) util_v_entrada > util_v_salida && DIM_V_ENTRADA == DIM_V_SALIDA
    const int DIM_V_ENTRADA_C2 = 4;
    int v_entrada_c2[DIM_V_ENTRADA_C2] = {4, 2, 7, 6};
    int util_v_entrada_c2 = 4;
    const int DIM_V_SALIDA_C2 = 4;
    int v_salida_c2[DIM_V_SALIDA_C2] = {1, 1, 1};
    int util_v_salida_c2 = 3;

    cout << DEBUG << "Caso 2 antes de ejecutar: " << RESTORE << endl;
    cout << DEBUG << "DIM_V_ENTRADA_C2 | " << DIM_V_ENTRADA_C2 << " | util_v_entrada_c2 | " << util_v_entrada_c2 << RESTORE << endl;
    cout << DEBUG << "DIM_V_SALIDA_C2 | " << DIM_V_SALIDA_C2 << " | util_v_salida_c2 | " << util_v_salida_c2 << RESTORE << endl;
    copiarVector(v_entrada_c2, util_v_entrada_c2, DIM_V_ENTRADA_C2, v_salida_c1, util_v_salida_c2, DIM_V_SALIDA_C2);
    imprimeVectorEnteros(v_salida_c2, util_v_salida_c2);

    //3) util_v_entrada == util_v_salida && DIM_V_ENTRADA > DIM_V_SALIDA
    const int DIM_V_ENTRADA_C3 = 5;
    int v_entrada_c3[DIM_V_ENTRADA_C3] = {4, 2, 7, 6};
    int util_v_entrada_c3 = 4;
    const int DIM_V_SALIDA_C3 = 4;
    int v_salida_c3[DIM_V_SALIDA_C3] = {1, 1, 1};
    int util_v_salida_c3 = 3;

    cout << DEBUG << "Caso 3 antes de ejecutar: " << RESTORE << endl;
    cout << DEBUG << "DIM_V_ENTRADA_C3 | " << DIM_V_ENTRADA_C3 << " | util_v_entrada_c3 | " << util_v_entrada_c3 << RESTORE << endl;
    cout << DEBUG << "DIM_V_SALIDA_C3 | " << DIM_V_SALIDA_C3 << " | util_v_salida_c3 | " << util_v_salida_c3 << RESTORE << endl;
    copiarVector(v_entrada_c3, util_v_entrada_c3, DIM_V_ENTRADA_C3, v_salida_c1, util_v_salida_c3, DIM_V_SALIDA_C3);
    imprimeVectorEnteros(v_salida_c3, util_v_salida_c3);

    //4) util_v_entrada == util_v_salida && DIM_V_ENTRADA < DIM_V_SALIDA
    const int DIM_V_ENTRADA_C4 = 4;
    int v_entrada_c4[DIM_V_ENTRADA_C4] = {4, 2, 7, 6};
    int util_v_entrada_c4 = 4;
    const int DIM_V_SALIDA_C4 = 5;
    int v_salida_c4[DIM_V_SALIDA_C4] = {1, 1, 1};
    int util_v_salida_c4 = 3;

    cout << DEBUG << "Caso 4 antes de ejecutar: " << RESTORE << endl;
    cout << DEBUG << "DIM_V_ENTRADA_C4 | " << DIM_V_ENTRADA_C4 << " | util_v_entrada_c4 | " << util_v_entrada_c4 << RESTORE << endl;
    cout << DEBUG << "DIM_V_SALIDA_C4 | " << DIM_V_SALIDA_C4 << " | util_v_salida_c4 | " << util_v_salida_c4 << RESTORE << endl;
    copiarVector(v_entrada_c4, util_v_entrada_c4, DIM_V_ENTRADA_C4, v_salida_c1, util_v_salida_c4, DIM_V_SALIDA_C4);
    imprimeVectorEnteros(v_salida_c4, util_v_salida_c4);

    //5) util_v_entrada > util_v_salida && DIM_V_ENTRADA > DIM_V_SALIDA
    const int DIM_V_ENTRADA_C5 = 4;
    int v_entrada_c5[DIM_V_ENTRADA_C5] = {4, 2, 7, 6};
    int util_v_entrada_c5 = 4;
    const int DIM_V_SALIDA_C5 = 2;
    int v_salida_c5[DIM_V_SALIDA_C5] = {1, 1};
    int util_v_salida_c5 = 2;

    cout << DEBUG << "Caso 5 antes de ejecutar: " << RESTORE << endl;
    cout << DEBUG << "DIM_V_ENTRADA_C5 | " << DIM_V_ENTRADA_C5 << " | util_v_entrada_c5 | " << util_v_entrada_c5 << RESTORE << endl;
    cout << DEBUG << "DIM_V_SALIDA_C5 | " << DIM_V_SALIDA_C5 << " | util_v_salida_c5 | " << util_v_salida_c5 << RESTORE << endl;
    copiarVector(v_entrada_c5, util_v_entrada_c5, DIM_V_ENTRADA_C5, v_salida_c1, util_v_salida_c5, DIM_V_SALIDA_C5);
    imprimeVectorEnteros(v_salida_c5, util_v_salida_c5);

    //6) util_v_entrada < util_v_salida && DIM_V_ENTRADA < DIM_V_SALIDA
    const int DIM_V_ENTRADA_C6 = 2;
    int v_entrada_c6[DIM_V_ENTRADA_C6] = {4, 2};
    int util_v_entrada_c6 = 2;
    const int DIM_V_SALIDA_C6 = 4;
    int v_salida_c6[DIM_V_SALIDA_C6] = {1, 1, 1, 1};
    int util_v_salida_c6 = 4;

    cout << DEBUG << "Caso 6 antes de ejecutar: " << RESTORE << endl;
    cout << DEBUG << "DIM_V_ENTRADA_C6 | " << DIM_V_ENTRADA_C6 << " | util_v_entrada_c6 | " << util_v_entrada_c6 << RESTORE << endl;
    cout << DEBUG << "DIM_V_SALIDA_C6 | " << DIM_V_SALIDA_C6 << " | util_v_salida_c6 | " << util_v_salida_c6 << RESTORE << endl;
    copiarVector(v_entrada_c6, util_v_entrada_c6, DIM_V_ENTRADA_C6, v_salida_c1, util_v_salida_c6, DIM_V_SALIDA_C6);
    imprimeVectorEnteros(v_salida_c6, util_v_salida_c6);

    //7) util_v_entrada < util_v_salida && DIM_V_ENTRADA == DIM_V_SALIDA
    const int DIM_V_ENTRADA_C7 = 4;
    int v_entrada_c7[DIM_V_ENTRADA_C7] = {4, 2, 7};
    int util_v_entrada_c7 = 3;
    const int DIM_V_SALIDA_C7 = 4;
    int v_salida_c7[DIM_V_SALIDA_C7] = {1, 1, 1, 1};
    int util_v_salida_c7 = 4;

    cout << DEBUG << "Caso 7 antes de ejecutar: " << RESTORE << endl;
    cout << DEBUG << "DIM_V_ENTRADA_C7 | " << DIM_V_ENTRADA_C7 << " | util_v_entrada_c7 | " << util_v_entrada_c7 << RESTORE << endl;
    cout << DEBUG << "DIM_V_SALIDA_C7 | " << DIM_V_SALIDA_C7 << v_salida_c7 << " | util_v_salida_c7 | " << util_v_salida_c7 << RESTORE << endl;
    copiarVector(v_entrada_c7, util_v_entrada_c7, DIM_V_ENTRADA_C7, v_salida_c1, util_v_salida_c7, DIM_V_SALIDA_C7);
    imprimeVectorEnteros(v_salida_c7, util_v_salida_c7);
    */

    //INTERCAMBIAR VECTORES
    /**
    cout << "Vector de entrada para intercambiar vectores: " << endl;
    imprimeVectorEnteros(vector, util_vector);
    cout << "Vector de salida para intercambiar vectores: " << endl;
    imprimeVectorEnteros(vector_resultado, util_vector_resultado);

    cout << "Entramos en intercambiarVectores" << endl;
    intercambiarVectores(vector, util_vector, DIM_VECTOR, vector_resultado, util_vector_resultado, DIM_VECTOR_RESULTADO);
    cout << "Salimos de intercambiarVectores" << endl;
    cout << "Vector de entrada despues de intercambiar vectores: " << endl;
    imprimeVectorEnteros(vector, util_vector);
    cout << "Vector de salida despues de intercambiar vectores: " << endl;
    imprimeVectorEnteros(vector_resultado, util_vector_resultado);
    */

    //CALCULAR MODA
    cout << "Entramos en calcularModa" << endl;
    moda = calcularModa(vector, util_vector);
    cout << "La moda del vector es: " << moda << endl;
    cout << "Salimos de calcularModa" << endl;

    //ORDENAR DOS VECTORES ORDENADOS
    cout << "Entramos en ordenar dos vectores ordenados" << endl;
    mezclarDosVectoresOrdenados(vector, util_vector, vector2, util_vector2, vector_resultado, util_vector_resultado, DIM_VECTOR_RESULTADO);
    cout << "Vector resultado: " << endl;
    imprimeVectorEnteros(vector_resultado, util_vector_resultado);
    

}

void copiarVector(const int v_entrada[], int util_v_entrada, const int DIM_V_ENTRADA, int v_salida[], int &util_v_salida, const int DIM_V_SALIDA ){
        if(util_v_entrada < util_v_salida){

            cout << USER << "Se copian todos los valores del vector de entrada, pero los valores del vector de salida desaparecen." << RESTORE << endl;
            for(int i = 0; i < util_v_entrada; i++){
                v_salida[i] = v_entrada[i];
            }

            util_v_salida = util_v_entrada;

        } else if((DIM_V_ENTRADA > DIM_V_SALIDA) && (util_v_entrada > DIM_V_SALIDA) ){
            cout << USER << "No se pueden copiar todos los valores del vector de entrada en el vector de salida." << RESTORE << endl;
            for(int i = 0; i < DIM_V_SALIDA; i++){
                v_salida[i] = v_entrada[i];
            }
            util_v_salida = DIM_V_SALIDA;
    
        }else{
            cout << USER << "La copia se hará correctamente." << RESTORE << endl;

            for(int i = 0; i < util_v_entrada; i++){
                v_salida[i] = v_entrada[i];
            }
            util_v_salida = util_v_entrada;
        }
        
}

void doblarValoresDelVectorEnteros(int vector[], int util_vector){
    cout << USER << "Doblando el valor del contenido de las componentes del vector, por favor tenga paciencia..." << RESTORE << endl;
    cout << DEBUG << "debug: El valor de las utiles antes del bucle es: " << util_vector << RESTORE <<  endl;
    for (int i=0; i < util_vector; i++){
        cout << DEBUG << "debug: Entrada en el bucle para doblar valores del vector..." << RESTORE << endl;
        vector[i]  = 2 * vector[i];
    }
    cout << USER << "Se dobló correctamente el vector... Lo comprobará cuando vuelva a imprimirlo..." << RESTORE << endl;
}

void imprimeVectorEnteros(const int vector[], int util_vector){
    cout << "Vector Enteros = { ";
    for (int i=0; i < util_vector; i++){
        cout << vector[i] << " ";
    }
    cout << "}" << endl;
}

void agregarNuevoEnteroenVectorEnteros(int vector[], int &util_vector, const int DIM_VECTOR, int entero){
   //if (util_vector >= DIM_VECTOR){
   //     cout << "ERROR: No hay espacio suficiente en el vector!" << endl;
   //}else{
        vector[util_vector] = entero;
        util_vector++;
   //}
}

bool preguntarSiUtilesMenorqueDim(int util_v_notas, int DIM_V_NOTAS){
    bool respuesta = false;

    if (util_v_notas < DIM_V_NOTAS) {
        respuesta = true;
    } else {
        respuesta = false;
    }
    return respuesta;
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

bool esPrimo(int numero){
    bool es_primo = true;

    for(int i = 2; ( (i < numero) && (es_primo == true) ); i++){
        if(numero % i == 0){
            es_primo = false;
        }
    }

    return es_primo;
}

void guardar_primos_vector(const int vector[], int util_vector, int vector_primos[], int &util_vector_primos){

    util_vector_primos = 0;

    for(int i = 0; i < util_vector; i++){
        if(esPrimo(vector[i])){
            vector_primos[util_vector_primos] = vector[i];
            util_vector_primos++;
    
        }
    }
}
void eliminarRepetidosContiguos(const int vector_entrada[], int util_vector_entrada, const int DIM_VECTOR_ENTRADA, int vector_salida[], int &util_vector_salida, const int DIM_VECTOR_SALIDA){
      //Inicializamos la util a 0 para controlar la posicion del vector de salida.
    util_vector_salida = 0;

    for(int i = 0; i < util_vector_entrada; i++){

        //Verificamos si estamos en la ultima posicion del vector
        //Despues verificamos si el elemento actual es diferente al elemento siguiente a la posicion actual.
        //Si es diferente, se agrega el elemento actual al vector de salida.
        if (i == util_vector_entrada - 1 || vector_entrada[i] != vector_entrada[i + 1]) {
            vector_salida[util_vector_salida] = vector_entrada[i];
            util_vector_salida++;
        
            cout << "Elemento copiado en posición " << util_vector_salida - 1 << ": " << vector_entrada[i] << endl;
        } else {
            // Impresión para depurar
            cout << "Elemento omitido en posición " << i << ": " << vector_entrada[i] << endl;
        }
    }

    
}

void intercambiarVectores(int vector_entrada[], int util_vector_entrada, const int DIM_VECTOR_ENTRADA, int vector_salida[], int util_vector_salida, const int DIM_VECTOR_SALIDA){

    const int DIM_VECTOR_AUX = DIM_VECTOR_ENTRADA;
    int vector_aux[DIM_VECTOR_AUX];
    int util_vector_aux = 0;

    //COPIAMOS EL VECTOR DE ENTRADA EN EL VECTOR AUXILIAR
    copiarVector(vector_entrada, util_vector_entrada, DIM_VECTOR_ENTRADA, vector_aux, util_vector_aux, DIM_VECTOR_AUX);

    //COPIAMOS EL VECTOR SALIDA EN EL VECTOR DE ENTRADA
    copiarVector(vector_salida, util_vector_salida, DIM_VECTOR_SALIDA, vector_entrada, util_vector_entrada, DIM_VECTOR_ENTRADA);

    //COPIAMOS EL VECTOR AUXILIAR EN EL VECTOR SALIDA
    copiarVector(vector_aux, util_vector_aux, DIM_VECTOR_AUX, vector_salida, util_vector_salida, DIM_VECTOR_SALIDA);


}

int calcularModa(const int vector[], int util_vector){
    int moda = vector[0];//Inicializamos con el primer elemento del vector
    int frecuencia = 1;//Frecuencia de la moda actual

    //Recorremos el vector para encontrar la moda
    for(int i = 0; i < util_vector; i++){
        int frecuenciaActual = 1;//Frecuencia del elemento actual
        for(int j = i + 1; j < util_vector; j++){
            if(vector[i] == vector[j]){
                frecuenciaActual++;
            }
        }
        //Si la frecuencia del elemento actual es mayor que la frecuencia maxima encontrada, actualizamos la moda y la frecuencia 
        if(frecuenciaActual > frecuencia){
            moda = vector[i];
            frecuencia = frecuenciaActual;
        }

    }

    return moda;

}

void mezclarDosVectoresOrdenados(const int vector[], int util_vector, const int vector2[], int util_vector2, int vector_resultado[], int &util_resultado, const int DIM_V_RESULTADO){
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < util_vector && j < util_vector2){
        if(vector[i] <= vector2[j]){
            vector_resultado[k] = vector[i];
            i++;
            
        }else{
            vector_resultado[k] = vector2[j];
            j++;
        
        }
        k++;
    }
    
    while(i < util_vector && k < DIM_V_RESULTADO){
        vector_resultado[k] = vector[i];
        i++;
        k++;
    }
    while(j < util_vector2 && k < DIM_V_RESULTADO){
        vector_resultado[k] = vector2[j];
        j++;
        k++;
    }

    util_resultado = k;

}

