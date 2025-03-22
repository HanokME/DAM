#include <iostream>
#include <cmath>
using namespace std;

//cpp para ejercicios de matrices
const int FILA = 5, COLUM = 5;

void PedirFilaColumna(int &utilFila, int &utilColumna);

void rellenarMatriz(double matriz[][5], int utilFila, int utilColumna);

void imprimirMatriz(double matriz[][5], int utilFila, int utilColumna);

int pedirNumeroBuscar();


void buscarNumero(double matriz[][5], int utilFila, int utilColumna, double numeroBuscar, int &filaEncontrada, int &columnaEncontrada);


int main(){

    double matriz [FILA][COLUM];
    int utilFila = 0, utilColumna = 0;
    double numeroBuscar = 0;
    int filaEncontrada = -1, columnaEncontrada = -1;

    PedirFilaColumna(utilFila, utilColumna);
    rellenarMatriz(matriz, utilFila, utilColumna);
    imprimirMatriz(matriz, utilFila, utilColumna);

    numeroBuscar = pedirNumeroBuscar();

    buscarNumero(matriz, utilFila, utilColumna, numeroBuscar, filaEncontrada, columnaEncontrada);

    if(filaEncontrada != -1 && columnaEncontrada != -1){
        cout << "El numero se encuentra en la fila: " << filaEncontrada << " y la columna: " << columnaEncontrada << endl;

    } else{
        cout << "El numero no se encuentra en la matriz" << endl;
    }





}

void PedirFilaColumna(int &utilFila, int &utilColumna){
    
    do{
    cout << "Introduce el número de filas: ";
    cin >> utilFila;
    }while(utilFila < 1 || utilFila > FILA);
    
    do{
    cout << "Introduce el número de columnas: ";
    cin >> utilColumna;
    }while(utilColumna < 1 || utilColumna > COLUM);
}

void rellenarMatriz(double matriz[][5], int utilFila, int utilColumna){
    cout << "Rellena los elementos de la matriz:\n";

    for(int i = 0; i < utilFila; i++){
        for(int j = 0; j < utilColumna; j++){
            cout << "Introduce el elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

}

void imprimirMatriz(double matriz[][5], int utilFila, int utilColumna){

    cout << "matriz:\n";
    for(int i = 0; i < utilFila; i++){
        for(int j = 0; j < utilColumna; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int pedirNumeroBuscar(){

    double numero = 0;
    cout << "Introduce el número que desea buscar: ";
    cin >> numero;
    return numero;
}

void buscarNumero(double matriz[][5], int utilFila, int utilColumna, double numeroBuscar, int &filaEncontrada, int &columnaEncontrada){

    for(int i = 0; i < utilFila; i++){
        for(int j = 0; j < utilColumna; j++){
            if(matriz[i][j] == numeroBuscar){
                filaEncontrada = i;
                columnaEncontrada = j;
            }
        }
    }
}