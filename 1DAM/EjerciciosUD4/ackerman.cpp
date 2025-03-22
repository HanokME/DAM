#include <iostream>
using namespace std;

/**
 * @brief Módulo que hace el cáclulo de la función Ackerman
 * @pre int m >= 0
 * @pre int n >= 0
 * return int resultado Resultado del cálculo de n y m ackerman
 * @version 0.1
 * @author Hanok
 * @date 01/02/2023
 */
int ackerman(int m, int n);

int ackerman(int m, int n){

	int resultado = 0;

	if(m == 0){
		resultado = n + 1;
	}
	else if((m > 0) && (n == 0)){
		resultado = ackerman(m - 1, 1);
	}
	else{
		resultado = ackerman(m - 1, ackerman(m, n - 1));
	}

	return resultado;

}

int main(){

	int n = 0;
	int m = 0;
	int resultado = 0;

	cout << "Bienvenido al cálculo de la función de Ackerman..." << endl;
	cout << "Por favor ingrese el número n: ";
	cin >> n;
	cout << "Por favor ingrese el número m: ";
	cin >> m;

	resultado = ackerman(m, n);

	cout << "El resultado de la función de Ackerman es: " << resultado << endl;

}