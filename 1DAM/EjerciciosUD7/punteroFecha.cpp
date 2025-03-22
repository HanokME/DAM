#include <iostream>
#include <stdlib.h>
using namespace std;

const bool DEBUG = true;
/*
if(DEBUG == true){
		cout << RED << "DEBUG: " << "Entrando en crearFecha..." << RESET << endl;
	}
*/

///////COLORES///////////
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


/////////STRUCT FECHA
///

struct Fecha{
    int dia;
    int mes;
    int ano;
};

//////CREACIÓN Y BORRADO

/**
 * @brief Módulo que se encarga de crear un puntero en memodria dinámica a Fecha
 * @return Devuelve un puntero con una dirección de memori en su cajita
 * @version 1.0
 * @author Hanok
 */
Fecha* crearFecha();

/**
 * @brief Módulo que se encarga de limpiar de la memoria dinámica el puntero a Fecha
 * @param f Puntero a Fecha
 * @return Fecha* f = 0
 * @version 1.0
 * @author Hanok
 */
Fecha* borrarFecha(Fecha *f);

///
///SET
///

/**
 * @brief Establece el dia en la variable de tipo fecha a través de un puntero
 * @param *f (S) Puntero a la variable de tipo Fecha en la que se quiere establecer el día.
 * @param dia (E) variable que contiene el dia que se quiere establecer
 * @pre dia debe ser (>=1 && <=31)
 * @post el dia de t, será actualizado con el valor proporcionado
 * @version 1.0
 * @author Hanok
*/
void setDiaFecha(Fecha *f, int dia);

/**
 * @brief Establece el mes de la variable de tipo Fecha a través de un puntero
 * @param *f (S) Puntero a la variable de tipo Fecha en la que se quiere establecer el día.
 * @param mes variable que contiene el mes que se quiere establecer.
 * @pre mes debe ser (>=1 && <=12).
 * @post el mes de f será actualizado con el valor proporcionado.
 * @version 1.0
 * @author Hanok
*/
void setMesFecha(Fecha *f, int mes);

/**
 * @brief Establece el año de la variable de tipo Fecha a través de un puntero
 * @param *f (S) Puntero a la variable de tipo Fecha en la que se quiere establecer el día.
 * @param anyo variable que contiene el anyo que se quiere establecer.
 * @pre ano debe ser un valor positivo comprendido año >= 1940 || año <= 2024.
 * @post el anyo de f será actualizado con el valor proporcionado.
 * @version 1.0
 * @author Hanok
*/
void setAnoFecha(Fecha *f, int ano);

/**
 * @brief Establece la fecha completa en la variable de tipo fecha a través de un puntero.
 * @param *f (S) Puntero a la variable de tipo Fecha en la que se quiere establecer la fecha completa.
 * @param dia (E) variable que contiene el día que se quiere establecer.
 * @param mes (E) variable que contiene el mes que se quiere establecer.
 * @param anyo (E) variable que contiene el anyo que se quiere establecer.
 * @pre dia debe ser (>=1 && <=31), mes debe ser (>=1 && <=12) y anyo debe ser un valor positivo.
 * @post la fecha completa de f será actualizada con los valores proporcionados.
 * @version 1.0
 * @author Hanok
*/
void setFecha(Fecha *f, int dia, int mes, int ano);

///
///GET
///

/**
 * @brief Obtiene el día desde una variable de tipo Fecha a través de un puntero.
 * @param *f (E) Puntero constante a la variable de tipo Fecha de la que se quiere obtener el día.
 * @return el día almacenado en la variable de tipo fecha.
 * @post se ha obtenido el día almacenado correctamente en la variable de tipo fecha.
 * @version 1.0
 * @author Hanok
*/
int getDiaFecha(const Fecha *f);

/**
 * @brief Obtiene el mes desde una variable de tipo Fecha a través de un puntero.
 * @param *f (E) Puntero constante a la variable de tipo Fecha de la que se quiere obtener el mes.
 * @return el mes almacenado en la variable de tipo fecha.
 * @post se ha obtenido el mes almacenado correctamente en la variable de tipo fecha.
 * @version 1.0
 * @author Hanok
*/
int getMesFecha(const Fecha *f);

/**
 * @brief Obtiene el año desde una variable de tipo Fecha a través de un puntero.
 * @param *f (E) Puntero constante a la variable de tipo Fecha de la que se quiere obtener el año.
 * @return el anyo almacenado en la variable de tipo fecha.
 * @post se ha obtenido el anyo almacenado correctamente en la variable de tipo fecha.
 * @version 1.0
 * @author Hanok
*/
int getAnoFecha(const Fecha *f);


///
///OTROS
///

///
///BACK
///

/**
 * @brief Módulo que asigna una Fecha de origen en una de destino, a través de un puntero
 * @param origen (E) la variable puntero de tipo Fecha de la que se quiere obtener la fecha
 * @param destino (D) la variable de tipo Fecha a la que se va a asignar la fecha
 * @pre Cumple con las condiciones de pedirFecha
 * @post Se ha asignado la fecha de un origen a un destino correctamente
 * @version 1.0
 * @author Hanok
*/
void asignarFecha(const Fecha *origen, Fecha *destino);

///
///FRONT
///

/**
 * @brief Imprime la fecha en formato día/mes/anyo a través de un puntero *f a Fecha.
 * @param *f (E) Puntero constante a la variable de tipo Fecha de la que se quiere obtener la fecha.
 * @post se ha impreso la fecha correctamente en la consola en formato día/mes/anyo.
 * @version 1.0
 * @author Hanok
*/
void printFecha(const Fecha *f);

/**
 * @brief Módulo que se encarga de pedir por pantalla la fecha que quiera el usuario, accediendo a esta a través de un puntero
 * @param f (E) Puntero a la variable de tipo Fecha de la que se quiere obtener la fecha.
 * @post se han recogido los datoscorrespondientes de la fecha
 * @version 1.0
 * @author Hanok
*/
void pedirFecha(Fecha *f);

int main(){	

	Fecha *ptr_fecha1 = crearFecha();
	Fecha *ptr_fecha2 = crearFecha();

	pedirFecha(ptr_fecha1);
	printFecha(ptr_fecha1);

	pedirFecha(ptr_fecha2);
	printFecha(ptr_fecha2);

	asignarFecha(ptr_fecha1, ptr_fecha2);

	printFecha(ptr_fecha2);
	printFecha(ptr_fecha1);

	ptr_fecha1 = borrarFecha(ptr_fecha1);
	ptr_fecha2 = borrarFecha(ptr_fecha2);


}

//CREACIÓN Y BORRADO

Fecha* crearFecha(){

	if(DEBUG == true){
		cout << RED << "DEBUG: " << "Entrando en crearFecha..." << RESET << endl;
	}
    Fecha *f = new Fecha;
	if(f == 0){
		cout << "Error al crear fecha..." << endl;
		exit(-1);
	}

	if(DEBUG == true){
    	cout << RED << "DEBUG: " << "Fecha creada adecuadamente en la dirección: " << f << RESET << endl;
		cout << RED << "DEBUG: " << "Saliendo de crearFecha..." << RESET << endl;
    }
    return f;
}

Fecha* borrarFecha(Fecha *f){

	if(DEBUG == true){
		cout << RED << "DEBUG: " << "Entrando en borrarFecha..." << RESET << endl;
	}
	delete f;
	if(DEBUG == true){
        cout << RED << "DEBUG: " << "Fecha borrada adecuadamente en la dirección: " << f << RESET << endl;
		cout << RED << "DEBUG: " << "Saliendo de borrarFecha..." << RESET << endl;
    }

	f = 0;
    return f;


}

/////////////STRUCT FECHA
///
///SET
///

void setDiaFecha(Fecha *f, int dia){
    f->dia = dia;

}

void setMesFecha(Fecha *f, int mes){
    f->mes = mes;

}

void setAnoFecha(Fecha *f, int ano){
    f->ano = ano;

}

void setFecha(Fecha *f, int dia, int mes, int ano){
    setDiaFecha(f, dia);
    setMesFecha(f, mes);
    setAnoFecha(f, ano);
}

///
///GET
///

int getDiaFecha(const Fecha *f){
    return f->dia;

}

int getMesFecha(const Fecha *f){
    return f->mes;

}

int getAnoFecha(const Fecha *f){
    return f->ano;

}

///
///FRONT
///

void pedirFecha(Fecha* f){
	int dia = 0, mes = 0, ano = 0;

	do{
		cout << "Introduzca el dia: ";
		cin >> dia;
		if(dia == 0){
			cout << "El dia no puede ser 0" << endl;
        } else if(dia < 0){
			cout << "El dia no puede ser negativo" << endl;
		} else if(dia > 31){
			cout << "El dia no puede ser superior a 31" << endl;
		}
	}while(dia <= 0 || dia > 31);

	do{
		cout << "Introduzca el mes: ";
        cin >> mes;
        if(mes == 0){
            cout << "El mes no puede ser 0" << endl;
        } else if(mes < 0){
            cout << "El mes no puede ser negativo" << endl;
        } else if(mes > 12){
            cout << "El mes no puede ser superior a 12" << endl;
        }
    }while(mes <= 0 || mes > 12);

	do{
		cout << "Introduzca el año: ";
        cin >> ano;
        if(ano == 0){
            cout << "El año no puede ser 0" << endl;
        } else if(ano < 0){
            cout << "El año no puede ser negativo" << endl;
        } else if(ano > 2024){
            cout << "El año no puede ser superior a 2024" << endl;
        }
	}while(ano < 1940 || ano > 2024);

    setFecha(f, dia, mes, ano);

}

void printFecha(const Fecha *f){
    cout << getDiaFecha(f) << "/" << getMesFecha(f) << "/" << getAnoFecha(f) << endl;
}

void asignarFecha(const Fecha *origen, Fecha *destino){
	setFecha(destino, getDiaFecha(origen), getMesFecha(origen), getAnoFecha(origen));
}