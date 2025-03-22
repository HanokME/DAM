#include <iostream>
#include <cmath>
using namespace std;

int main(){

	//Inicializamos variables 
	int num_casos = 0;
	int num_poblacion = 0;
	int saltos = 0;
	int pos_peter = 0;
	int pos_stark = 0;
	int muerte = 0;
	
	//Bienvenida al programa
	cout << "\tBienvenido a un programa que predice si muere stark o peter cuando thanos chasquea los dedos" << endl;
	//Bucle que repite mientras que las conndiciones no se cumplan
	
	//Interactuamos con el usuario para pedirle los valores de las variables
	cout << "\tIntroduce el número de casos que desea hacer: "; 
	cin >> num_casos;
	
	//Hacemos un bucle for para repetir todo num_casos veces
	for (int i = 1; i <= num_casos; i++){
		do{
		cout << "\tIntroduce el número de habitantes que hay: "; 
		cin >> num_poblacion;
		} while (!((num_poblacion >= 2) && (num_poblacion <= 1000)));
		
		do{
			cout << "\tIntroduce la posición de peter y de stark consecutivamente: "; 
			cin >> pos_peter; 	
			cin >> pos_stark;
		} while (pos_peter == pos_stark);
	
		do{
			cout << "\tIntroduce los saltos que va a dar thanos para elegir matar a alguien: "; cin >> saltos;
		} while (!((saltos >= 0) && (saltos <= 20)));
	 
		muerte = saltos + 1;
		
		//Introducimos un par de condiciones para filtar hipoteticos casos
		if (muerte == pos_peter){
			cout << "\tNo quiero irme, Stark" << endl;
		} else if (muerte == pos_stark){
		  	cout << "\tNo quiero irme, Peter" << endl;	
		}
	} 	
	
	
	
	
	
	
	
}

