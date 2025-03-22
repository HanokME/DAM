#include <iostream>
#include <cmath>

//COLORES
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"


using namespace std;

int main(){

	//DECLARACIÓN DE VARIABLES
	double numero1 = 0.0, numero2 = 0.0;
	double resultadoSuma = 0.0;
	double resultadoResta = 0.0;
	double resultadoMultiplicacion = 0.0;
	double resultadoDivision = 0.0;
	
	//BIENVENIDA AL PROGRAMA
	cout << "Bienvenido a una calculadora de principiante..." << endl;
	cout << "A continuación le voy a pedir que introduzca los números pertinentes a calcular..." << endl;
	cout << "" << endl;
	
	//INTERACCIÓN CON USUARIO
	cout << "Introduzca el primer número: ";
	cin >> numero1;
	cout << "Introduzca el segundo número: ";
	cin >> numero2;
	cout << "" << endl;
	
	//CÁLCULOS
	resultadoSuma = numero1 + numero2;
	resultadoResta = numero1 - numero2;
	resultadoMultiplicacion = numero1 * numero2;
	resultadoDivision = numero1 / numero2;
	
	//RESULTADOS
	cout << "Los diferentes resultados son: " << endl;
	cout << numero1 << " + " << numero2 << " = " << GREEN << resultadoSuma << RESET << endl;
	cout << numero1 << " - " << numero2 << " = " << GREEN << resultadoResta << RESET << endl;
	cout << numero1 << " x " << numero2 << " = " << GREEN << resultadoMultiplicacion << RESET << endl;
	cout << numero1 << " / " << numero2 << " = " << GREEN << resultadoDivision << RESET << endl;

}
