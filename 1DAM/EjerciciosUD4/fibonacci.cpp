#include <time.h>
#include <iostream>
using namespace std;

/**
 * @brief Módulo que hace el análisis del cálculo de fibonacci y devuelve el resultado
 * @param int n Número entero al que le vamos a calcular el número fibonacci
 * @pre int n >= 0
 * @return long int resultado Resultado del cálculo de n fibonacci de forma recursiva
 * @version 0.5
 * @author Hanok
 * @date 30/01/2023
 */
long int fibonacci_recursivo(int n);

long int fibonacci_recursivo(int n){
	long int resultado = 0;


	if (n == 2){

		resultado = 1;

	} else if (n == 1){

		resultado = 1;

	} else if(n == 0){

		resultado = 1;

	} else{

		resultado = fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);

	}

	return resultado;
}

int main(){
		
	int n = 0;
	long int resultado_recur = 0;

	cout << "Bienvenido a la sucesión de Fibonacci" << endl;
	cout << "Indica el número que quieras calcular: ";
	cin >> n;

	resultado_recur = fibonacci_recursivo(n);

	cout << "Fibonacci recursivo de " << n << " es: " << resultado_recur << endl;
}