#include <iostream>

using namespace std;

int main(){
	
	int dato;
	
	cout << "Introduce un valor entero distinto de cero" << endl;
	cin >> dato;
	if (dato!=0) 
		cout << "Ha escrito " << dato
		     << " que es distinto de cero" << endl;
		cout << "Es un alumno muy obediente" << endl;
	
	if (dato==0)
		cout << "Ups! que desobediente..." << endl;
}
