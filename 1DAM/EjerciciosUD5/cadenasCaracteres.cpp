#include <iostream>
#include <cmath>
using namespace std;

/**
 * CADENAS DE CARACTERES
 * HANOK
 * 1.3
 * 22/01/2024
*/

/**
 * @brief Módulo que comprueba la longitud de una cadena de caracteres
 * @param cadena vector que contiene la cadena de caracteres a comprobar
 * @param Dimension dimension del vector
 * @return longitud de la cadena de caracteres
 * @version 1.0
 * @author Hanok
*/
int comprobarLongitudCadena(const char cadena[], const int Dimension);

/**
 * @brief Módulo que concatena 3 cadenas de caracteres.
 * @param cadena1 vector que contiene la primera cadena de caracteres a concatenar
 * @param cadena2 vector que contiene la segunda cadena de caracteres a concatenar
 * @param cadena3 vector que contiene la tercera cadena de caracteres a concatenar
 * @param cadena 4 vector que almacena la cadena de caracteres concatenada
 * @param Dimension Dimension del vector
 * @post cadena4 contiene la cadena de caracteres concatenada
 * @version 1.0
 * @author Hanok
*/
void concatenarCadenas(const char cadena1[], const char cadena2[], const char cadena3[], char cadena4[], const int Dimension);

/**
 * @brief Módulo que comprueba si hay espacios en blanco en una cadena y copia el contenido en otro vector, sin espacios
 * @param cadena vector que contiene la cadena de caracteres a comprobar
 * @param cadenaresultado vector al que se va a copiar la cadena
 * @param Dimension dimension del vector
 * @post contiene la cadena de caracteres sin espacios
 * @version 1.0
 * @author Hanok
*/
void quitarEspaciosEnBlanco(const char cadena[], char cadenaresultado[], const int Dimension);

/**
 * @brief Módulo que calcul el espacio libre del vector
 * @param cadena vector que queremos calcular
 * @param dimension dimension del vector
 * @post espacio que queda libre del vector
 * @version 1.0
 * @author Hanok
*/
int calcularEspacioLibre(const char cadena[], const int Dimension);

/**
 * @brief Módulo que invierte la cadena sobre si misma en el mismo vector
 * @param cadena vector que contiene la cadena
 * @param dimension dimension del vector
 * @post cadena ya invertida
 * @version 1.0
 * @author Hanok
*/
void invertirCadena(char cadena[], const int Dimension);

/**
 * @brief Módulo que verifica si la cadena es palindroma o no
 * @param cadena vector que contiene la cadena a analizar
 * @param dimension dimension del vector
 * @return true si la cadena es palindroma o false si no lo es
 * @version 1.0
 * @author Hanok
*/
bool esPalindromo(const char cadena[], const int Dimension);

int main(){

    const int DIM_CHAR = 100;
    char nombre[DIM_CHAR];
    char apellido1[DIM_CHAR];
    char apellido2[DIM_CHAR];
    char resultado[DIM_CHAR];
    int espacioLibre = 0;

    cout << "Introduce tu nombre: ";
    cin >> nombre;
    cout << "Introduce tu primer apellido: ";
    cin >> apellido1;
    cout << "Introduce tu segundo apellido: ";
    cin >> apellido2;
    

    cout << "Longitud de la cadena nombre: " << comprobarLongitudCadena(nombre, DIM_CHAR) << endl;
    cout << "Longitud de la cadena apellido1: " << comprobarLongitudCadena(apellido1, DIM_CHAR) << endl;
    cout << "Longitud de la cadena apellido2: " << comprobarLongitudCadena(apellido2, DIM_CHAR) << endl;
    

    cout  << "Entrando en concatenarCadenas" << endl;
    concatenarCadenas(nombre, apellido1, apellido2, resultado, DIM_CHAR);
    cout << resultado << endl;

    cout << "Entrando en quitarEspaciosEnBlanco" << endl;
    quitarEspaciosEnBlanco(resultado, resultado, DIM_CHAR);
    cout << resultado << endl;

    cout << "Entrando en calcularEspacioLibre" << endl;
    espacioLibre = calcularEspacioLibre(resultado, DIM_CHAR);
    cout << "Espacio libre: " << espacioLibre << endl;

    cout << "Entrando en invertirCadena" << endl;
    invertirCadena(resultado, DIM_CHAR);
    cout << resultado << endl;

    cout << "Entrando en esPalindromo" << endl;
    if(esPalindromo(resultado, DIM_CHAR) == true){
        cout << "La cadena es palindroma" << endl;
    } else{
        cout << "La cadena no es palindroma" << endl;
    }

}

int comprobarLongitudCadena(const char cadena[], const int Dimension){

    int i = 0;
    while(cadena[i]!= '\0' && i < Dimension) {
        i++;
    }
    return i;
}

void concatenarCadenas(const char cadena1[], const char cadena2[], const char cadena3[], char cadena4[], const int Dimension){

    int posicion = 0;

    for(int i = 0; cadena1[i]!= '\0' && i < Dimension; i++){
        cadena4[posicion] = cadena1[i];
        posicion++;
    }
    cadena4[posicion] = ' ';
    posicion++;

    for(int i = 0; cadena2[i]!= '\0' && i < Dimension; i++){
        cadena4[posicion] = cadena2[i];
        posicion++;
    }
    cadena4[posicion] = ' ';
    posicion++;
    for(int i = 0; cadena3[i]!= '\0' && i < Dimension; i++){
        cadena4[posicion] = cadena3[i];
        posicion++;
    }
    cadena4[posicion] = '\0';
}

void quitarEspaciosEnBlanco(const char cadena[], char cadenaresultado[], const int Dimension){
    int posicion = 0;
    for(int i = 0; cadena[i]!= '\0' && i < Dimension; i++){
        if(cadena[i]!= ' '){
            cadenaresultado[posicion] = cadena[i];
            posicion++;
        }
    }
    cadenaresultado[posicion] = '\0';

}

int calcularEspacioLibre(const char cadena[], const int Dimension){
    int longitud = 0;
    int resultado = 0;

    longitud = comprobarLongitudCadena(cadena, Dimension);

    resultado = Dimension - longitud -1;

    return resultado;
}

void invertirCadena( char cadena[], const int Dimension){

    int longitud = 0;

    while(cadena[longitud] != '\0' && longitud < Dimension){
        longitud++;
    }

    for(int i = 0, j = longitud - 1; i < j; i++, j-- ){
        char intercambiador = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = intercambiador;
    }
}

bool esPalindromo(const char cadena[], const int Dimension){
    int longitud = 0;
    int resultado = 0;
    bool espalindromo = false;
    longitud = comprobarLongitudCadena(cadena, Dimension);
    resultado = longitud / 2;
    for(int i = 0; i < resultado; i++){
        if(cadena[i]!= cadena[longitud - i - 1]){
            espalindromo = false;
        } else{
            espalindromo = true;
        }
    }
    return espalindromo;
}