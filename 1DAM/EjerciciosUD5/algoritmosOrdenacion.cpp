#include <iostream>
using namespace std;

/**
 * ALGORITMOS DE ORDENACIÓN DE VECTORES
*/

/**
 * @brief Módulo que se encarga de buscar un valor concreto en un vector
 * @param vector(E) Vector que contiene unso valores predeterminados
 * @param utilv(E) Util del vector
 * @param DIMV(E) Dimension del vector
 * @param valor(E) Valor que se va a buscar
 * @pre utilv < DIMV && utilv > 0 
 * @return Resultado con la posición en la que se encuentra el valor, en el vector o -1 en el caso de que no exista dicho valor en el vector
 * @version 1.0
 * @author Hanok
*/
int busquedaSecuencial(const int vector[], const int utilv, const int DIMV, int valor);

/**
 * @brief Módulo que ordena un vector de enteros utilizando el algoritmo de selección
 * @param vector(E/S) Vector que contiene unos valores predeterminados desordenados
 * @param utilv(E/S) Util del vector
 * @post valores del vector ordenados
 * @version 1.0
 * @author Hanok
*/
void ordenacionSeleccion(int vector[], const int utilv);

/**
 * @brief Módulo que encuentra la posicion del valor mínimo de un vector
 * @param vector(E) Vector en el que se busca el mínimo
 * @param inicio(E/S) El que indica el inicio del vector
 * @param utilv(E) Cantidad de elementos utilizados en el vector
 * @return Posicion del elemento mínimo del vector
 * @version 1.0
 * @author Hanok
*/
int posicionMinimo(const int vector[], int inicio, const int utilv);

/**
 * @brief Módulo que intercambia dos valores
 * @param a(E/S) Primer valor
 * @param b(E/S) Segundo valor
 * @post Los valores a y b han sido intercambiados
 * @version 1.0
 * @author Hanok
*/
void intercambiar(int &a, int &b);

void ordenarInsercion(int v[], int util, const int DIMV);

void ordenarBurbuja(int v[], int util, const int DIMV);

int busquedaBinaria(const int vector[], int utilv, int valor);

int main(){

    /*
    int vector[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int DIMV = 10;
    int vector[DIMV] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int utilv = 10;
    int valor = 0;
    int posicion = 0;

    posicion = busquedaSecuencial(vector, utilv, DIMV, valor);
    
    if(posicion != -1){
        cout << "El valor se encuentra en la posición: " << posicion << endl;
    } else{
        cout << "El valor no se encuentra en el vector" << endl;
    }
    */

    const int DIMV = 10;
    int vector[DIMV] = {2, 4, 5, 1, 6, 3, 7, 9, 10, 8};
    int utilv = 10;
    int posicionEncontrar = 0;
    int valor = 5;

    cout << "Vector original: " << endl;
    for(int i = 0; i < utilv; i++){
        cout << vector[i] << " ";
    }
    cout << endl;


    //ordenarInsercion(vector, utilv, DIMV);
    //ordenacionSeleccion(vector, utilv);
    ordenarBurbuja(vector, utilv, DIMV);
    
    cout << "Vector ordenado: " << endl;
    for(int i = 0; i < utilv; i++){
        cout << vector[i] << " ";
    }
    cout << endl;

    posicionEncontrar = busquedaBinaria(vector, utilv, valor);

    if(posicionEncontrar != -1){
        cout << "El valor se encuentra en la posición: " << posicionEncontrar << endl;
    } else{
        cout << "El valor no se encuentra en el vector" << endl;
    }


}

int busquedaBinaria(const int vector[], int utilv, int valor){
    int izquierda = 0;
    int derecha = utilv - 1;
    int medio = (izquierda + derecha) / 2;

    while((izquierda <= derecha) && (vector[medio] != valor)){
        if(valor < vector[medio]){
            derecha = medio - 1;
        } else{
            izquierda = medio + 1;
        }
        medio = (izquierda + derecha) / 2;
        
    }
    if(izquierda > derecha){
        return -1;
    } else{
        return medio;
    }

}

void ordenarBurbuja(int v[], int util, const int DIMV){
    for(int izq = 0; izq < util; izq++){

        //DEBUG
        cout << "Iteracion " << izq + 1 << ": " << endl;

        for(int i = util - 1; i > izq; i--){
            if(v[i] < v[i - 1]){
                intercambiar(v[i], v[i - 1]);

                //DEBUG
                cout << "Intercambiando " << v[i-1] << " por " << v[i] << ": " << endl;
                for(int j = 0; j < util; j++){
                    cout << v[j] << " ";
                }
                cout << endl;
            }


        }
    }
}


void intercambiar(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}


void ordenacionSeleccion(int vector[], const int utilv){

    int posMinimo = 0; 
    //Iteramos desde la primera posicion hasta la penultima
    for(int i = 0; i < utilv -1; i ++ ){
        //Encontramos el índice del elemento mínimo en el vector a partir de la posición i
        posMinimo = posicionMinimo(vector, i, utilv);
        //Intercambiamos los valores
        intercambiar(vector[i], vector[posMinimo]);
    }
}

int posicionMinimo(const int vector[], int inicio, const int utilv){

    int posMinimo = inicio;
    
    for(int i = inicio + 1; i < utilv; i++){
        //Si encontramos un elemento menor que el elemento en el índice mínimo actual, actualizamos el índice mínimo
        if(vector[i] < vector[posMinimo]){
            posMinimo = i;
        }
    }
    return posMinimo;
}

int busquedaSecuencial(const int vector[], const int utilv, const int DIMV, int valor){

    int posicion = -1;

    for(int i = 0; i < utilv; i++){
        if(vector[i] == valor){
            posicion = i;
        }
    }
        
     return posicion;
}



void ordenarInsercion(int v[], int util, const int DIMV){

        int izq = 0;
        int i = 0;
        int valor = 0;
        
        
        for(izq = 1; izq < util; izq++){
                
                valor = v[izq];
        
                for(i = izq; i > 0 && valor < v[i - 1]; i--){
                
                        v[i] = v[i - 1];
                
                }
                
                v[i] = valor;   
        
        
        }

}








