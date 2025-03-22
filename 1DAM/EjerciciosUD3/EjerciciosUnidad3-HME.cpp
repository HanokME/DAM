#include <iostream>
#include <cmath>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define RESET   "\x1b[0m"
using namespace std;

///////////PROTOTIPOS//////////////
/**
 * @brief Módulo que muestra un mensaje de bienvenida al programa.
 * @
 * @version 1.3
 * @author Hanok
 */
void BienvenidaGeneral();

/**
 * @brief Módulo que maneja la llamada a los diferentes ejercicios del programa.
 * @version 1.3
 * @author Hanok
 */
void llamada_ejercicio();

/**
 * @brief Módulo que muestra el menú de bienvenida al programa.
 * @version 1.3
 * @author Hanok
 */
void mostrar_menu();

/**
 * @brief Módulo que solicita la entrada del usuario para elegir un ejercicio.
 * @return char - La opción elegida por el usuario.
 * @version 1.3
 * @author Hanok
 */
char pedir_opcion();

/**
 * @brief Módulo que lee por pantalla tres números.
 * @param double &n1 - Primer número a introducir.
 * @param double &n2 - Segundo número a introducir.
 * @param double &n3 - Tercer número a introducir.
 * @post se han leido 3 números reales o enteros
 * @version 1.3
 * @author Hanok
 */
void leer_tres_numeros(double &n1, double &n2, double &n3);

/**
 * @brief Módulo principal para calcular la media de tres números.
 * @version 1.3
 * @author Hanok
 */
void media();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaMedia();

/**
 * @brief Módulo que calcula la media de tres números.
 * @param double n1 - Primer número.
 * @param double n2 - Segundo número.
 * @param double n3 - Tercer número.
 * @return double - Resultado de la media de tres números reales o enteros.
 * @pre n1, n2, n3 reales y/o enteros
 * @version 1.3
 * @author Hanok
 */
double calcular_media(double n1, double n2, double n3);

/**
 * @brief Módulo que muestra el resultado de la media de tres números.
 * @param double media - Resultado de la media.
 * @post Resultado de la media mostrado por pantalla
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_media(double media);

/**
 * @brief Módulo que contiene todas las llamadas del ejercicio de los primos
 * @version 1.3
 * @author Hanok
 */
void primos();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaPrimos();

/**
 * @brief Solicita al usuario que introduzca un intervalo válido.
 * @param Ei (S) Variable de salida para el extremo inferior del intervalo.
 * @param Es (S) Variable de salida para el extremo superior del intervalo.
 * @post Ei, Es > 0
 * @version 1.3
 * @author Hanok
 */
void entrada_intervalo(int &Ei, int &Es);

/**
 * @brief Cuenta la cantidad de números primos en un intervalo dado.
 * @param Ei Extremo inferior del intervalo.
 * @param Es Extremo superior del intervalo.
 * @return Devuelve la cantidad de números primos en el intervalo.
 * @pre Ei, Es > 0
 * @post n primos en un intervalo > 0
 * @version 1.3
 * @author Hanok
 */
int contador_primos(int Ei, int Es);

/**
 * @brief Módulo que verifica si un número es primo o no.
 * @param int n - Número a verificar.
 * @return bool true si el número es primo, false en caso contrario.
 * @pre n > 0.
 * @version 1.3
 * @author Hanok
 */
bool esPrimo(int n);

/**
 * @brief Módulo que muestra los números primos de un intervalo dado.
 * @param int cantidad_primos - Resultado de la verificación.
 * @pre cantidad_primos > 0
 * @post El resultado de los primos ha sido mostrado
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_primo(int cantidad_primos);

/**
 * @brief Módulo principal que encapsula el ejercicio del factorial.
 * @version 1.3
 * @author Hanok
 */
void factorial();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaFactorial();

/**
 * @brief Módulo que solicita al usuario introducir un número estrictamente entero y positivo.
 * @return int El número entero ingresado por el usuario.
 * @post numero entero positivo
 * @version 1.3
 * @author Hanok
 */
int introducir_numero_entero_positivo();

/**
 * @brief Módulo que calcula el factorial de un número.
 * @param int n1 Número para calcular el factorial.
 * @return int Resultado del factorial.
 * @pre n1 > 0
 * @post resultado del factorial > 0
 * @version 1.3
 * @author Hanok
 */
int calcular_factorial(int n1);

/**
 * @brief Módulo que muestra el resultado del cálculo del factorial.
 * @param int (E) n1 Número para el cual se calculó el factorial.
 * @param int (E) resultado Resultado del factorial.
 * @post Se ha mostrado por pantalla el resultado del factorial de n.
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_factorial(int n1, int resultado);

/**
 * @brief Módulo que contiene el menú de la calculadora y proporciona opciones para realizar diferentes operaciones matemáticas.
 * @post Depende de la opción seleccionada, hace una operación u otra.
 */
void menu_calculadora();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaCalculadora();

/**
 * @brief Solicita al usuario introducir dos números.
 * @param num1 (S) Variable para almacenar el primer número ingresado.
 * @param num2 (S) Variable para almacenar el segundo número ingresado.
 * @post Se retornan dos números enteros o reales.
 * @version 1.3
 * @author Hanok
 */
void introducir_dos_numeros(double &num1, double &num2);

/**
 * @brief Realiza la operación de división entre dos números.
 * @param num1 (E) El numerador.
 * @param num2 (E) El denominador (debe ser diferente de cero).
 * @return Retorna el resultado de la división.
 * @version 1.3
 * @author Hanok
 */
double calcular_division(double num1, double num2);

/**
 * @brief Realiza la operación de multiplicación entre dos números.
 * @param num1 (E) El primer factor.
 * @param num2 (E) El segundo factor.
 * @return Retorna el resultado de la multiplicación.
 * @version 1.3
 * @author Hanok
 */
double calcular_multiplicacion(double num1, double num2);

/**
 * @brief Realiza la operación de resta entre dos números.
 * @param num1 (E) El número del que se resta.
 * @param num2 (E) El número que se resta.
 * @return Retorna el resultado de la resta.
 * @version 1.3
 * @author Hanok
 */
double calcular_resta(double num1, double num2);

/**
 * @brief Realiza la operación de suma con una cantidad específica de números.
 * @param total_numeros (E) La cantidad total de números a sumar (debe ser mayor que cero).
 * @return Retorna el resultado de la suma.
 * @pre total_numeros debe ser mayor que cero.
 * @post resultado de la suma > 0
 * @version 1.3
 * @author Hanok
 */
double calcular_suma(double total_numeros);

/**
 * @brief Muestra el resultado de una operación en la calculadora.
 * @param resultado (E) El resultado de la operación.
 * @post El resultado de la calculadora ha sido mostrado
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_calculadora(double resultado);

/**
 * @brief Solicita al usuario introducir la cantidad total de números a sumar.
 * @return La cantidad total de números a sumar.
 * @post Retorna la cantidad total de números ingresada por el usuario > 0.
 * @version 1.3
 * @author Hanok
 */
double introducir_total_numeros();

/**
 * @brief Módulo que contiene el comparador de máximo y mínimos de una lista de números.
 * @version 1.3
 * @author Hanok
 */
void min_max();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaMinMax();

/**
 * @brief Lee una lista de números ingresada por el usuario y actualiza los valores máximo y mínimo.
 * @param total_numeros (E) Cantidad total de números a ingresar.
 * @param lista_numeros (S) Variable que almacena cada número ingresado.
 * @param minimo Valor (S) mínimo actual.
 * @param maximo Valor (S) máximo actual.
 * @pre total_numeros > 0
 * @version 1.3
 * @author Hanok
 */
void leer_lista_numeros(int total_numeros, int &lista_numeros, int &minimo, int &maximo);

/**
 * @brief Calcula el valor máximo y mínimo de una lista de números.
 * @param total_numeros (E) Cantidad total de números en la lista.
 * @param lista_numeros (E) Número actual de la lista.
 * @param maximo (S) Valor máximo actual.
 * @param minimo (S) Valor mínimo actual.
 * @post minimo y maximo actualizados.
 * @version 0.1
 * @author Hanok
 */
void calcular_maxmin_de_lista(int total_numeros, int lista_numeros, int &minimo, int &maximo);

/**
 * @brief Muestra el valor máximo y mínimo de la lista.
 * @param minimo (E) Valor mínimo de la lista.
 * @param maximo (E) Valor máximo de la lista.
 * @post Resultados mostrados
 * @version 1.3
 * @author Hanok
 */
void mostrar_maxmin_de_lista(int &minimo, int &maximo);

/**
 * @brief Módulo que lee por pantalla dos números enteros estrictos
 * @param int a (S) primer número que lee por pantalla
 * @param int b (s) segundo número que lee por pantalla
 * @return dos números enteros (a, b).
 * @post numeros a, b enteros
 * @version 1.3
 * @author Hanok
 */
void introducir_dos_numeros_enteros(int &a, int &b);

/**
 * @brief Módulo que contiene las llamadas a otros módulos que hallan el máximo común divisor
 * @post da como salida el resultado de calcular el mcd de dos número
 * @version 1.3
 * @author Hanok
 */
void mcd();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaMCD();

/**
 * @brief Módulo que calcula el mcd de dos números (a, b)
 * @param  int a (E) primer número a calcular introducido por el usuario
 * @param  int b (E) segundo número a calcular introducido por el usuario
 * @pre los números (a, b) deben ser positivos
 * @return int residuo (S) Número (a, b) que queda despues del cálculo de hallar cual es el mcd
 * @post el resultado del calculo del mcd será positivo
 * @version 1.3
 * @author Hanok
 */
int calcular_mcd(int a, int b);

/**
 * @brief Módulo que muestra el resultado de calcular el mcd de dos números
 * @param int resultado (E) número que queda de hallar cual es el mcd de dos números
 * @pre resultado debe ser un número positivo
 * @post el resultado es mostrado al usuario
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_mcd(int resultado);

/**
 * @brief Módulo que contiene las llamadas a otros módulos que hallan el mínimo común multiplo
 * @post da como salida el resultado de calcular el mcm de dos número
 * @version 1.3
 * @author Hanok
 */
void mcm();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaMCM();

/**
 * @brief Módulo que calcular el mcm de dos número a partir del módulo mcd
 * @param int a (E) primer número que se utiliza para calcular el mcm
 * @param int b (E) segundo número que se utiliza para calcular el mcm
 * @return int resultado (S) resultado del calculo del mcm de dos números (a, b)
 * @pre números (a, b) deberán ser positivos
 * @post el resultado de calcular el mcm positivo
 * @version 1.3
 * @author Hanok
 */
int calcular_mcm(int a, int b);

/**
 * @brief Módulo que muestra el resultado de calcular el mcm de dos números
 * @param int resultado (E) número que queda de hallar cual es el mcm de dos números
 * @pre int resultado debe ser un número positivo
 * @post el resultado es mostrado al usuario
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_mcm(int resultado);

/**
 * @brief Módulo que alberga las llamadas para calcular y mostrar los resultados de una ecuación de segundo grado
 * @version 1.3
 * @author Hanok
 */
void ecuacion_cuadratica();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaEcuacion();

/**
 * @brief Módulo que calcula la ecuación de segundo grado
 * @param double a (E) Número a calcular
 * @param double b (E) Número a calcular
 * @param double c (E) Número a calcular
 * @param double x1 (E/S) Resultado del 1º calculo 
 * @param double x2 (E/S) Resultado del 2º calculo 
 * @return resultado de x1 y x2 calculado
 * @post double x1 y x2 ya calculado
 * @version 1.3
 * @author Hanok
 */
void calcular_ecuacion(double a, double b, double c, double &x1, double &x2);

/**
 * @brief Módulo que muestra por pantalla los dos resultados de la ecuación
 * @param double x1 (E) Resultado del 1º calculo
 * @param double x2 (E) Resultado del 2º calculo
 * @post Queda mostrado el resultado
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_ecuacion(double x1, double x2);

/**
 * @brief Módulo que alberga todas las llamadas para calcular y mostrar los resultados de la conversión de segundos
 * @post queda mostrado el resultado de la conversión de segundos
 * @versión 1.3
 * @author Hanok
 */
void OnTime();

/**
 * @brief muestra la bienvenida al programa por pantalla
 * @post ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaOnTime();

/**
 * @brief Módulo que convierte un número determinado de segundos en dias, horas, minutos y segundos
 * @param int segundos (E) segundos introducidos por el usuario que hay que convertir 
 * @param int dias (S) parametro que va a albergar el numero de días ya convertidas
 * @param int horas (S) parametro que va a albergar el numero de horas ya convertidas 
 * @param int minutos (S) parametro que va a albergar el numero de horas ya convertidos 
 * @param int segundos_restantes (S) parametro que va a albergar el resultante de los segundos despues de convertirlos
 * @return el resultados de convertir los segundos en dias, horas, minutos y segundos restantes
 * @pre int segundos >= 0
 * @post dias, horas, minutos y segundos_restantes >= 0
 * @version 1.3
 * @author Hanok 
 */
void convertidor_tiempo(int segundos, int &dias, int &horas, int &minutos, int &segundos_restantes);

/**
 * @brief Módulo que muestra por pantalla el resultado de convertir los segundos en dias, horas, minutos y segundos
 * @param int dias (E) parámetro que contiene el valor que queda despues de convertir los segundos en dias
 * @param int horas (E) parámetro que contiene el valor que queda despues de convertir los segundos en horas
 * @param int minutos (E) parámetro que contiene el valor que queda despues de convertir los segundos en minutos
 * @param int segundos_restantes (E) parámetro que contiene el valor que queda despues de convertir los segundos en dias, horas y minutos
 * @pre dias, horas, minutos y segundos_restantes >= 0
 * @post resultados mostrados al usuario
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_OnTime(int dias, int horas, int minutos, int segundos_restantes);

/**
 * @brief Módulo central del ejercicio nicomano
 * @post Ha sido calculado y mostrado el resultado del calculo de nicomano
 * @version 1.3
 * @author Hanok
 */
void nicomano();

/**
 * @brief Módulo que muestra por pantalla la bienvenida
 * @post Ha sido mostrada la bienvenida por pantalla
 * @version 1.3
 * @author Hanok
 */
void bienvenidaNicomano();

/**
 * @brief Módulo que se encarga de calcular el cubo del número introducido por el usuario
 * @param int n (E) Número que ha introducido el usuario para ser calculado
 * @return int cubo de n calculado
 * @pre n > 0
 * @version 1.3
 * @author Hanok
 */
int calcular_nicomano(int n);

/**
 * @brief Módulo que muestra por pantalla el resultado de calcular el cubo de n
 * @param int n (E) Resultado de haber calculado el cubo
 * @post Resultado ya mostrado por pantalla al usuario
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_nicomano(int n);

/**
 * @brief Módulo que se encarga de leer las coordenadas por pantalla
 * @param Xi (S) Coordenada X inicial
 * @param Xf (S) Coordenada X final
 * @param Yi (S) Coordenada Y inicial
 * @param Yf (S) Coordenada Y final
 * @post Coordenadas X-Y > 0
 * @version 1.3
 * @author Hanok
 */
void introducir_coordenadas(double &Xi, double &Xf, double &Yi, double &Yf);

/**
 * @brief Módulo que contiene las llamadas generales del ejercicio Kasparov
 * @post Kasparov ya mostrado
 * @version 1.3
 * @author Hanok
 */
void kasparov();

/**
 * @brief Módulo que muestra por pantalla la bienvenida al ejercicio kasparov
 * @version 1.3
 * @author Hanok
 */
void bienvenidaKasparov();

/**
 * @brief Módulo que contiene un menú para verificar si las coordenadas de cada pieza son válidas
 * @param pieza (E) Pieza que has elegido previamente para acceder a los filtros pertinentes
 * @param Xi (E) Coordenada X Inicial introducida por el usuario
 * @param Xf (E) Coordenada X Final introducida por el usuario
 * @param Yi (E) Coordenada Y Inicial introducida por el usuario
 * @param Yf (E) Coordenada Y Final introducida por el usuario
 * @pre coordenadas > 0
 * @post coordenadas de cada pieza validadas o no
 * @version 1.3
 * @author Hanok
 */
void menu_validador_movimientos_kasparov(char pieza, double Xi, double Xf, double Yi, double Yf, bool &movimiento_valido);

/**
 * @brief Módulo que muestra por pantalla un mensaje para recoger el tipo de pieza que quieres utilizar
 * @return Pieza elegida
 * @version 1.3
 * @author Hanok
 */
char obtener_pieza();

/**
 * @brief Módulo que muestra por pantalla el resultado
 * @param movimiento_valido (E) booleano para mostrar por pantalla los diferentes resultados
 * @post Resultados ya mostrados
 * @version 1.3
 * @author Hanok
 */
void mostrar_resultados_kasparov(bool movimiento_valido);

///////////MAIN///////////
int main(){

	llamada_ejercicio();

}

//////////MÓDULOS/////////

int introducir_numero_entero_positivo(){

	int n = 0.0;

	do{
		
		cout << "\tIntroduce el número entero positivo a calcular: ";
		cin >> n;

	}while(n <= 0);

	return n;
}

void leer_tres_numeros(double &n1, double &n2, double &n3){

	cout << "\tIntroduce el primer número: ";
	cin >> n1;
	cout << "\tIntroduce el segundo número: ";
	cin >> n2;
	cout << "\tIntroduce el tercer número: ";
	cin >> n3;
}

void introducir_coordenadas(double &Xi, double &Xf, double &Yi, double &Yf){

	cout << "\tLas coordenadas estarán comprendidas siempre entre 1 y 8." << endl;

	do{
		cout << "\tIntroduce la coordenada inicial de X estando siempre en positivo: ";
		cin >> Xi;

		cout << "\tIntroduce la coordenada inicial de Y estando siempre en positivo: ";
		cin >> Yi;
	}while( !(((Xi >= 1) && (Xi <= 8)) && ((Yi >= 1) && (Yi <= 8))) );

	do{
		cout << "\tIntroduce la coordenada final de X estando siempre en positivo: ";
		cin >> Xf;

		cout << "\tIntroduce la coordenada final de Y estando siempre en positivo: ";
		cin >> Yf;
	}while( !(((Xf >= 1) && (Xf <= 8)) && ((Yf >= 1) && (Yf <= 8))) );
	
}

void kasparov(){

	bienvenidaKasparov();

	double X_inicial = 0.0, X_final = 0.0, Y_inicial = 0.0, Y_final = 0.0;
	char pieza = ' ';
	bool movimiento_valido = false;

	char continuar = 's';

	do{

		pieza = obtener_pieza();

		introducir_coordenadas(X_inicial, X_final, Y_inicial, Y_final);

		menu_validador_movimientos_kasparov(pieza, X_inicial, X_final, Y_inicial, Y_final, movimiento_valido);

		mostrar_resultados_kasparov(movimiento_valido);

		cout << "\tDesea validar otra pieza? S/N: ";
		cin >> continuar;

	}while(continuar == 's' || continuar == 'S');

}

void bienvenidaKasparov(){

	cout << "\tBienvenido a un validador de movimientos de ajedrez." << endl;

}

char obtener_pieza(){

	char pieza = ' ';

	cout << "\t(T) para escoger la torre." << endl;
	cout << "\t(R) para escoger la reina." << endl;
	cout << "\t(C) para escoger al caballo." << endl;
	cout << "\tEscoge pieza: ";
	cin >> pieza;

	return pieza;
}

void menu_validador_movimientos_kasparov(char pieza, double Xi, double Xf, double Yi, double Yf, bool &movimiento_valido){

	switch(pieza){

		case 't':
		case 'T':

			if ((Xi == Xf && Yi != Yf) || (Xi != Xf && Yi == Yf)){

				movimiento_valido = true;

			} else{

				movimiento_valido = false;

			}

		break;

		case 'r':
		case 'R':

			if ((Xi == Xf && Yi != Yf) || (Xi != Xf && Yi == Yf) || (Xi - Yi == Xf - Yf) || (Xi + Yi == Xf + Yf)){

				movimiento_valido = true;

			} else{

				movimiento_valido = false;

			}

		break;

		case 'c':
		case 'C':

			if ( ((Xf == Xi + 2 || Xf == Xi - 2) && (Yf == Yi + 1 || Yf == Yi - 1)) || ((Xf == Xi + 1 || Xf == Xi - 1) && (Yf == Yi + 2 || Yf == Yi - 2)) ){

				movimiento_valido = true;

			} else{

				movimiento_valido = false;

			}

		break;
		
		default:

			cout << RED << "\tNo has escogido la pieza correcta." << RESET << endl;

	}


}

void mostrar_resultados_kasparov(bool movimiento_valido){

	if (movimiento_valido == true){

		cout << "\tEl movimiento es: " << GREEN << "VÁLIDO!!" << RESET << endl;

	} else{

		cout << "\tEl movimiento es: " << RED << "INVÁLIDO!!" << RESET << endl;

	}

}

void nicomano(){

	bienvenidaNicomano();

	int n = 0;
	int cubo = 0;

	n = introducir_numero_entero_positivo();

	cubo = calcular_nicomano(n);

	mostrar_resultados_nicomano(cubo);

}


void bienvenidaNicomano(){

	cout << "\tBienvenido al programa que te calcula el cubo de un número concreto." << endl;
}

int calcular_nicomano(int n){

	int cubo = 0;

	for(int i = 0; i <= n; i++){
        
        cubo = pow(i, 3);

    }

    return cubo;

}

void mostrar_resultados_nicomano(int n){

	cout << "\tEl resultado de nicomano es: " << GREEN << n << RESET << endl;

}

void OnTime(){

	bienvenidaOnTime();

	int segundos = 0, dias = 0, horas = 0, minutos = 0, segundos_restantes = 0;

	segundos = introducir_numero_entero_positivo();
	convertidor_tiempo(segundos, dias, horas, minutos, segundos_restantes);
	mostrar_resultados_OnTime(horas, dias, minutos, segundos_restantes);
}

void bienvenidaOnTime(){
	cout << "\tBienvenido al convertidor de tiempo por excelencia..." << endl;
}

void convertidor_tiempo(int segundos, int &dias, int &horas, int &minutos, int &segundos_restantes){

	const int SEGUNDOS_DIA = 86400;
	const int SEGUNDOS_HORA = 3600;
	const int SEGUNDOS_MINUTO = 60;

	dias = segundos / SEGUNDOS_DIA;
    segundos_restantes = segundos % SEGUNDOS_DIA;

    horas = segundos_restantes / SEGUNDOS_HORA;
    segundos_restantes %= SEGUNDOS_HORA;

    minutos = segundos_restantes / SEGUNDOS_MINUTO;
    segundos_restantes %= SEGUNDOS_MINUTO;

    segundos_restantes %= SEGUNDOS_MINUTO;
}

void mostrar_resultados_OnTime(int dias, int horas, int minutos, int segundos_restantes){

	cout << "\tDías: " << GREEN << dias << RESET << endl;
	cout << "\tHoras: " << GREEN << horas << RESET << endl;
	cout << "\tMinutos: " << GREEN << minutos << RESET << endl;
	cout << "\tSegundos restantes: " << GREEN << segundos_restantes << RESET << endl;
}

void ecuacion_cuadratica(){

	bienvenidaEcuacion();

	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;

	leer_tres_numeros(a, b, c);
	calcular_ecuacion(a, b, c, x1, x2);
	mostrar_resultados_ecuacion(x1, x2);

}

void bienvenidaEcuacion(){
	cout << "\tBienvenido al programa por excelencia para calcular una ecuación cuadrática..." << endl;
}

void calcular_ecuacion(double a, double b, double c, double &x1, double &x2){

	double discriminante = 0.0;

	discriminante = ((b * b) - (4.0 * a) * c);

	x1 = ( (-b + sqrt(discriminante)) / (2 * a) );
	x2 = ( (-b - sqrt(discriminante)) / (2 * a) );

}

void mostrar_resultados_ecuacion(double x1, double x2){

	if (x1 == x2){
	
		cout << "\tSolo tiene una solución: " << GREEN << x1 << RESET << endl;	
		
	} else {
	
		cout << "\tResultado de x1: " << GREEN << x1 << RESET << endl;
		cout << "\tResultado de x2: " << GREEN << x2 << RESET << endl;

	}

}

void mcm(){

	bienvenidaMCM();

	int a = 0;
	int b = 0;
	int resultado = 0;

	introducir_dos_numeros_enteros(a, b);
	resultado = calcular_mcm(a, b);
	mostrar_resultados_mcm(resultado);
}

void bienvenidaMCM(){
	cout << "\tBienvenido al programa por excelencia para calcular el mínimo común multiplo..." << endl;
}

int calcular_mcm(int a, int b){

	int resultado = 0;
	int resultado_mcd = 0;

	resultado_mcd = calcular_mcd(a, b);

	resultado = (a * b) / resultado_mcd;

	return resultado;
}

void mostrar_resultados_mcm(int resultado){

	cout << "\tEste es el resultado del mcm: " << GREEN << resultado << RESET << endl;
}

void mcd(){

	bienvenidaMCD();

	int a = 0.0;
	int b = 0.0;
	int resultado = 0.0;

	introducir_dos_numeros_enteros(a, b);
	resultado = calcular_mcd(a, b);
	mostrar_resultados_mcd(resultado);
}

void bienvenidaMCD(){
	cout << "\tBienvenido al programa por excelencia para calcular el máximo común divisor..." << endl;
}

int calcular_mcd(int a, int b){

	int residuo = 0.0;

	residuo = a%b;

	while(residuo != 0){

		a = b;
		b = residuo;
		residuo = a%b;
	}

	return b;
}

void mostrar_resultados_mcd(int resultado){

	cout << "\tEl resultado del mcd es: " << GREEN << resultado << RESET << endl;
}

void introducir_dos_numeros_enteros(int &a, int &b){

	cout << "\tIntroduzca el primer número: ";
	cin >> a;
	cout << "\tIntroduzca el segundo número: ";
	cin >> b;
}

void min_max(){

	bienvenidaMinMax();

	int total_numeros = 0;
	int maximo = 0;
	int minimo = 100;
	int lista_numeros = 0;
	
	total_numeros = introducir_total_numeros();
	leer_lista_numeros (total_numeros, lista_numeros, minimo, maximo);
	mostrar_maxmin_de_lista (maximo, minimo);

}

void bienvenidaMinMax(){
	cout << "\tBienvenido al programa por excelencia para calcular el mínimo y el máximo de una lista de números..." << endl;
}

double introducir_total_numeros(){

	double total = 0.0;

	do{

		cout << "\tIntroduce el total de números que vas a introducir: ";
		cin >> total;

	}while(total <= 0.0);

	return total;
}

void leer_lista_numeros (int total_numeros, int &lista_numeros, int &minimo, int &maximo){
	
	cout << "\tIntroduce la lista de números a comprobar: ";
	
	for (int i = 0; i < total_numeros; i++){
	
		cin >> lista_numeros;
		
		calcular_maxmin_de_lista(total_numeros, lista_numeros, maximo, minimo);
	}
	
}

void calcular_maxmin_de_lista (int total_numeros, int lista_numeros, int &minimo, int &maximo){
		
	for(int i = 0; i < total_numeros; i++){
	
		if(minimo >= lista_numeros){
			minimo = lista_numeros;
		} if(maximo <= lista_numeros){
			maximo = lista_numeros;
		}
	
	}	
}

void mostrar_maxmin_de_lista (int &minimo, int &maximo){
	
	cout << "\tEl mínimo es: " << GREEN << minimo << RESET << endl;
	cout << "\tEl máximo es: " << GREEN << maximo << RESET << endl;
}

void menu_calculadora(){

	bienvenidaCalculadora();

	char opcion = ' ';

	double num1 = 0.0;
	double num2 = 0.0;
	double resultado = 0.0;
	double total_numeros = 0.0;

	cout << BG_LBLUE << "\tBienvenido, por favor elija que cálculo quiere hacer, dentro de las siguientes posibilidades." << RESET << endl;
	cout << BG_LBLUE << "\tRealizar una suma (S)." << RESET << endl;
	cout << BG_LBLUE << "\tRealizar una resta (R)." << RESET << endl;
	cout << BG_LBLUE << "\tRealizar una multiplicación (M)." << RESET << endl;
	cout << BG_LBLUE << "\tRealizar una división (D)." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce aquí el caracter: " << RESET;
	cin >> opcion;

	switch(opcion){

		case 's':
		case 'S':

			total_numeros = introducir_total_numeros();
			resultado = calcular_suma(total_numeros);
			mostrar_resultados_calculadora(resultado);

		break;

		case 'r':
		case 'R':

			introducir_dos_numeros(num1, num2);
			resultado = calcular_resta(num1, num2);
			mostrar_resultados_calculadora(resultado);

		break;

		case 'm':
		case 'M':

			introducir_dos_numeros(num1, num2);
			resultado = calcular_multiplicacion(num1, num2);
			mostrar_resultados_calculadora(resultado);

		break;

		case 'd':
		case 'D':

			introducir_dos_numeros(num1, num2);
			resultado = calcular_division(num1, num2);
			mostrar_resultados_calculadora(resultado);

		break;

		default:
		cout << "\tOpción no válida."<< endl;
	}

}

void bienvenidaCalculadora(){
	cout << "\tBienvenido al programa que contiene dentro una calculadora equipada hasta arriba de juguetes..." << endl;
}

double calcular_suma(double total_numeros){

	double resultado_suma = 0.0;

	//bucle que itera hasta que llegue a total_numeros y tiene una sumatoria para hallar el resultado
	for(int i = 0; i < total_numeros; i++){
		double numero = 0.0;

		cout << "\tIntroduce el número " << i + 1 << ": ";
		cin >> numero;

		resultado_suma += numero;
	}

	return resultado_suma;
}

void introducir_dos_numeros(double &num1, double &num2){

	cout << "\tIntroduzca el primer número: ";
	cin >> num1;
	cout << "\tIntroduzca el segundo número: ";
	cin >> num2;

}

double calcular_resta(double num1, double num2){

	double resultado_resta = 0.0;

	resultado_resta = num1 - num2;

	return resultado_resta;
}

double calcular_multiplicacion(double num1, double num2){

	double resultado_multiplicacion = 0.0;

	resultado_multiplicacion = num1 * num2;

	return resultado_multiplicacion;
}

double calcular_division(double num1, double num2){

	double resultado_division = 0.0;

	resultado_division = num1 / num2;

	return resultado_division;
}

void mostrar_resultados_calculadora(double resultado){

	cout << "\tEl resultado es: " << GREEN << resultado << RESET << endl;
}

void media(){

	bienvenidaMedia();

	//Variables de alm,acenamiento de números
	double numero1 = 0.0;
	double numero2 = 0.0;
	double numero3 = 0.0;

	//Variable donde se guarda el total de la media
	double media = 0.0;

	//llamada a la funcion que lee los números a calcular
	leer_tres_numeros(numero1, numero2, numero3);

	//llamada a la funcion que calcula la media, además lo guardamos en la variable media
	media = calcular_media(numero1, numero2, numero3);

	//llamada a la funcion que muestra el resultado de la media
	mostrar_resultados_media(media);
}

void bienvenidaMedia(){
	cout << "\tBienvenido al programa por excelencia para calcular la media de 3 números..." << endl;
}

double calcular_media(double n1, double n2, double n3){

	double media = 0.0;

	media = (n1 + n2 + n3) / 3.0;

	return media;

}

void mostrar_resultados_media(double media){

	cout << "\tEl resultado de la media es: " << GREEN << media << RESET << endl;

}

void primos(){

	bienvenidaPrimos();

	int cantidad_primos = 0;
	int Ei = 0;
	int Es = 0;


	entrada_intervalo(Ei, Es);

	cantidad_primos = contador_primos(Ei, Es);

	mostrar_resultados_primo(cantidad_primos);

}

void bienvenidaPrimos(){
	cout << "\tBienvenido al programa por excelencia para calcular los primos que hay en un intervalo..." << endl;
}

void entrada_intervalo(int &Ei, int &Es) {
    do {
        cout << "\tIntroduce el extremo inferior: ";
        cin >> Ei;
        cout << "\tIntroduce el extremo superior: ";
        cin >> Es;

        if (Ei <= 0 || Es <= 0 || Ei > Es) {
            cout << "\tIntervalo no válido. Asegúrate de que el intervalo sea válido." << endl;
        }
    } while ((Ei < 0 || Ei >= Es) && (Es <= 0));
}

int contador_primos(int Ei, int Es){
    
    int i = 0; 
    int contador_primos = 0;
    
    //Bucle que recorre el intervalo
    for(i = Ei; i <= Es; i++){
        
        //Si el valor actual de la 'i' es primo contador suma
        if(esPrimo(i) == true){
            contador_primos++;
            cout << "\tNúmero: " << GREEN << i << RESET << endl;
        }
    }
    return contador_primos;
}

bool esPrimo (int n){
	
    bool es_primo = true;
    	
    	//Comprueba si el valor actual de la "i" es primo o no
    	for(int i = 2; ((i < n) && (es_primo == true)); i++){

        	if(n % i == 0){

            	es_primo = false;  
        	
        	}
    	}
	
	return es_primo;
}

void mostrar_resultados_primo(int cantidad_primos){

	cout << "\tLa cantidad de primos en el intervalo es de: " << GREEN << cantidad_primos << RESET << endl;

}

void factorial(){

	bienvenidaFactorial();

	int numero1 = 0;
	int resultado = 0;

	numero1 = introducir_numero_entero_positivo();

	resultado = calcular_factorial(numero1);

	mostrar_resultados_factorial(numero1, resultado);


}

void bienvenidaFactorial(){
	cout << "\tBienvenido al programa por excelencia para calcular el factorial de n..." << endl;
}

int calcular_factorial(int n1){

	int resultado = 1;

	for(int i = 2; i <= n1; i++){

		resultado = resultado * i;
	}

	return resultado;

}

void mostrar_resultados_factorial(int n1, int resultado){

	cout << "\tEl factorial de " << n1 << " es: " << GREEN << resultado << RESET << endl;
}

void llamada_ejercicio(){

	BienvenidaGeneral();

	char continuar = 's';

	do{

		char ejercicio = ' ';

		mostrar_menu();

		ejercicio = pedir_opcion();

		switch (ejercicio){

			case 'p':
			case 'P':

				primos();

			break;

			case 'm':
			case 'M':

				media();

			break;

			case 'f':
			case 'F':

				factorial();

			break;

			case 'c':
			case 'C':

				menu_calculadora();

			break;

			case 'x':
			case 'X':

				min_max();

			break;

			case 'd':
			case 'D':

				mcd();

			break;

			case 'l':
			case 'L':

				mcm();

			break;

			case 'e':
			case 'E':

				ecuacion_cuadratica();

			break;

			case 's':
			case 'S':

				OnTime();

			break;

			case 'n':
			case 'N':

				nicomano();

			break;

			case 'k':
			case 'K':

				kasparov();

			break;


			default:

				cout << RED << "\tOpción no válida." << RESET << endl;
		}

		cout << "\tDesea hacer otro ejercicio? S/N: ";
		cin >> continuar;

	}while(continuar == 's' || continuar == 'S');

}

void BienvenidaGeneral(){
	cout << "\tBienvenido a un programa que alberga todos los ejercicios de la UD3..." << endl;
}

void mostrar_menu (){
	
	cout << BG_LBLUE << "\tIntroduce [P] para acceder al ejercicio de cálculo de números primos en intervalos." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [F] para acceder al ejercicio de cálculo de factorial de un número." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [M] para acceder al ejercicio de cálculo de la media de x números." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [C] para acceder a un menú que contiene diferentes apartados de una calculadora." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [X] para acceder al ejercicio que halla el máximo y el mínimo de una lista de números." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [D] para acceder al ejercicio que halla el máximo común divisor de dos números." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [L] para acceder al ejercicio que halla el mínimo común multiplo de dos números." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [E] para acceder al ejercicio que halla el resultado de una ecuación de segundo grado." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [S] para acceder al ejercicio que convierte los segundos en días, horas y minutos." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [N] para acceder al ejercicio que calcula el cubo de un número entero (Nicomano)." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce [K] para acceder al ejercicio validador de movimientos de piezas de ajedrez." << RESET << endl;
	cout << BG_LBLUE << "\tIntroduce aquí el caracter: "<< RESET;
}

char pedir_opcion (){

	char ejercicio = ' ';
	
	cin >> ejercicio;
	
	return ejercicio;
} 
