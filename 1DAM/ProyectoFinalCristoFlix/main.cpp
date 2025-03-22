#include <iostream>
#include "colors.h"
#include "sistema.h"

using namespace std;

int main(){
	//Ejemplo clase Fecha
    // Fecha fecha1;
    // fecha1.setFecha(15, 5, 2024);
    // cout << "Fecha 1: " << fecha1 << endl;

    // Fecha fecha2;
    // fecha2.setFecha(1, 1, 2000);
    // cout << "Fecha 2: " << fecha2 << endl;

    // //Asignación de fecha2 a fecha1 usando el operador de asignación
    // fecha1 = fecha2;
    // cout << "Fecha 1 (después de asignación): " << fecha1 << endl;

    // //Uso del constructor de copia
    // Fecha fecha3 = fecha1;
    // cout << "Fecha 3 (copiada de Fecha 1): " << fecha3 << endl;
    // 
    // 
    // 
    // 

    // Ejemplo clase contenido
    // Fecha fecha;
    // fecha.setFecha(15, 5, 2024);

    // // Crear un objeto Contenido y establecer sus valores
    // Contenido contenido1;
    // contenido1.setContenido(1, "Película de Ejemplo", fecha, 120, "Drama", 8.5, 20000);

    // // Imprimir el contenido usando el operador <<
    // cout << "Contenido 1: " << endl << contenido1 << endl;

    // // Crear otro objeto Contenido y usar el operador de asignación
    // Contenido contenido2;
    // contenido2.setContenido(2, "Otra Película", fecha, 95, "Comedia", 7.8, 15000);
    // cout << "Contenido 2: " << endl << contenido2 << endl;

    // // Asignar contenido2 a contenido1
    // contenido1 = contenido2;
    // cout << "Contenido 1 (después de asignación): " << endl << contenido1 << endl;

    // // Usar el constructor de copia
    // Contenido contenido3 = contenido1;
    // cout << "Contenido 3 (copiado de Contenido 1): " << endl << contenido3 << endl;
    // 
    // 
    // 
    // // Ejemplo clase fecha, contenido y usuario
    // Usuario usuario1;
    // usuario1.setDatosUsuarios(1, "usuario1", "password", "Juan", "Perez", "Gomez", Fecha(15, 5, 1998), true, "admin");

    // // Imprimir información del usuario
    // cout << "Información del usuario:" << endl;
    // cout << usuario1 << endl;
    // 
    // 
    // 
    // Crear algunos objetos de prueba para Usuario, Contenido y Valoracion
    // Usuario usuario1;
    // usuario1.setDatosUsuarios(15, "Napoleon", "221199", "Hanok", "Martin", "Exposito", Fecha(22, 11, 1999), true, "admin");

    // Contenido contenido1;
    // contenido1.setContenido(1, "The Matrix", Fecha(1, 1, 2020), 120, "Ciencia Ficcion", 4.5, 1000);

    // Valoracion valoracion1(1, &contenido1, &usuario1, 4.5, Fecha(1, 1, 2021));

    // cout << usuario1 << endl;
    // cout << contenido1 << endl;
    // cout << valoracion1 << endl;
    // 
    
    Sistema sistema;
    Usuario usuario;

    sistema.menuInicio(sistema, usuario);

}