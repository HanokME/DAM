#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	//Inicializamos variables para crear el menú de opciones
	int num_prob = 0;
	
	//Inicializamos las variables para el problema PONG
	int num_jugadas = 0;
	int i;
	bool primo = false;
	
	
	//Bienvenida al programa
	
	cout << "\tBienvenido a un programa para jugar a diferentes videojuegos" << endl;
	cout << "\tPor ahora solo hemos incluido uno de los videojuegos, los otros estarán disponibles proximamente" << endl;
	
	//Comenzamos a crear el menú mediante switch
	do{
	cout << "\tPor favor para comenzar con el videojuego PONG pulse 1: "; cin >> num_prob;
	} while ((num_prob != 1) && (num_prob != 2) && (num_prob != 3));
	
	switch (num_prob) {
		
		case 1:
			cout << "\tBienvenido al videojuego PONG" << endl;
			cout << "\tEste juego consiste en decir un número de veces que quieres que se lance la bolita..." << endl;
			cout << "\tDependiendo del número de veces la bolita dará el sonido PIC (ha dado de raqueta a raqueta), POC (ha dado en la pared superior o inferior) o PONG (habrá marcado punto)" << endl;
			cout << "\tHay dos lados y cada uno tiene su propio marcador, el juego parará cuando pulse 0" << endl;
			
			cout << "\tPulse el número de jugadas que quiera hacer: " << endl;
			cin >> num_jugadas;
			
			
			for (i=2; (i < num_jugadas) && (primo == false); i++){
				cout << i << " ";
				if (num_jugadas % i == 0){ primo = true;
				}
			}
			
			if (primo == false){
				cout << "pong" << endl;
			} else {
				cout << "pong" << endl;
			  }
			
			/*cout << "\tPulse el número de jugadas que desea hacer: "; cin >> num_jugadas;
			cout << "\tIntroduce la jugada que quieras hacer: ";
				
				
			for (contador_jugada = 0; contador_jugada <= num_jugadas; contador_jugada ++){
				cin >> contador_jugada;
			} */
			
		break;
		
		case 2:
		
			cout << "\tEste juego se encuentra en fase de desarrollo, por favor tenga paciencia..." << endl;
			
		break;
		
		case 3:
		
			cout << "\tEste juego se encuentra en fase de desarrollo, por favor tenga paciencia..." << endl;
			
		break;
	}
}
