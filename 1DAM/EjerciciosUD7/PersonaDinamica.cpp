#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Persona{
    string nombre;
    int edad;
};
void setNombre(Persona *p, string nombre);
void setEdad (Persona *p, int edad);
string getNombre(Persona *p);
int getEdad (Persona *p);
void printPersona(Persona *p);
void printVectorPersonas(Persona *v, int util_v);
Persona* crearPersona();
Persona* borrarPersona(Persona *p);

Persona* resize(Persona *v, int &util_actual, int &dim_actual,  int dim_nueva);
void insertarPersonaenVector(Persona* v, int &util_actual, int &dim_actual, Persona * p);


Persona* asignarPersona(Persona* v_entrada, int util_persona_entrada, int dim_v_entrada, int &util_persona_salida, int dim_v_salida);

void setNombre(Persona *p, string nombre){
    //(*p).nombre = nombre  //tb vale
    p->nombre = nombre;    //cuando tenemos punteros nos gusta más usar el operador flecha
}

void setEdad (Persona *p, int edad){
    p->edad = edad;
}

string getNombre(Persona *p){
    return p->nombre;
}

int getEdad (Persona *p){
    return p->edad;
}

void printPersona(Persona *p){
    cout << "Persona: " << getNombre(p) << " tiene " << getEdad(p) << " años." << endl;
}

void printVectorPersonas(Persona *v, int util_v){
    for(int i=0; i < util_v; i++)
        printPersona(&v[i]);
}

Persona* crearPersona(){
    Persona *p = new Persona;
    if (p == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    return p;
}

Persona* borrarPersona(Persona *p){
    //formateo a cero/nulo todos los datos que tiene una persona
    p->nombre = "";
    p->edad = -1;
    //borro el fragmento de memoria
    delete p;
    //elimino la dirección que referenciaba al fragmento de memoria
    p = 0;
    return p;
}

/**
 * @brief Cambia la dimensión del vector a una nueva dim_nueva
 *  1) Creo un vector nuevo con la nueva dimension
 *  2) Copio el contenido del vector que me pasan, en el nuevo vector (OJO SI ES MÁS GRANDE O MÁS CHICO)
 *  3) Libero la memoria del vector que me pasan
 *  4) Devuelvo el puntero del nuevo vector
 */
Persona* resize(Persona *v, int &util_actual, int &dim_actual,  int dim_nueva){
    Persona *v_nuevo = new Persona[dim_nueva];//creamos nuevo vector
    int util_v_nuevo = 0;

    //copiamos los elementos del vector anterior en el nuevo
    v_nuevo = asignarPersona(v, util_actual, dim_actual, util_v_nuevo, dim_nueva);
    util_actual = util_v_nuevo;
    
    //libero la memoria del vector anterior
    delete[] v;

    //Asignar el nuevo vector a la variable
    v = v_nuevo;
    
    //actualizo la dimensión del vector
    dim_actual = dim_nueva;
    
    return v;

}

/**
 * @brief Módulo que inserta la Persona p, en el Vector Dinámico de Personas v.
 *  En los escenarios necesarios realiza una llamada al módulo resize para que la nueva persona p pueda introducirse sin problemas y sea transparente para el programado que utilice este módulo
 *
 */
void insertarPersonaenVector(Persona* v, int &util_actual, int &dim_actual, Persona * p){
    if(util_actual >= dim_actual){ //Si la cantidad de elementos supera la capacidad actual, aumentamos de uno en uno la dimension
        dim_actual++;
        v = resize(v, util_actual, dim_actual, dim_actual);
    }
    v[util_actual++] = *p;
}

Persona* asignarPersona(Persona* v_entrada, int util_persona_entrada, int dim_v_entrada, int &util_persona_salida, int dim_v_salida){
    Persona *v_salida = new Persona[dim_v_salida];
    util_persona_salida = 0;
    if( util_persona_entrada > dim_v_salida ){
        cout << "Se perderá información en el copiado..." << endl;
        for(int i = 0; i < dim_v_salida; i++){
            v_salida[util_persona_salida] = v_entrada[i];
            util_persona_salida++;
        }
    } else{
        for(int i = 0; i < util_persona_entrada; i++){
            cout << "La copia se hará correctamente..." << endl;
            v_salida[util_persona_salida] = v_entrada[i];
            util_persona_salida++;
        }
    }
    return v_salida;
}

int main(){
    
    Persona pepe_estatico; //memoria estática
    
    //1º) Declaro los punteros
    Persona *pepe = 0, *carlos = 0, *jose = 0; //memoria dinámica
    
    //2º) Pedir memoria al SO
    pepe = crearPersona();
    carlos = crearPersona();
    jose = crearPersona();

    //3º) METEMOS DATOS
    //Uso estático de los módulos que emplean punteros
    setNombre(&pepe_estatico, "Pepe_Estático");
    setEdad(&pepe_estatico, 31);
    //Uso dinámico de los módulos que emplean punteros
    setNombre(pepe,"Pepe");
    setEdad(pepe, 20);
    setNombre(jose,"Jose");
    setEdad(jose, 5);
    setNombre(carlos,"Carlos");
    setEdad(carlos, 47);
    
    
    //AHORA VAMOS A USAR UN VECTOR DINÁMICO
    const int DIM_V = 20;
    Persona v_estatico[DIM_V]; //memoria estática: ME HA CREADO 20 PERSONAS ESTÁTICAS!!!!!
    int util_v_estatico = 0;
    
    //1ª ALTERNATIVA: UN VECTOR DINÁMICO DE PERSONAS
    int tamanio = 3;
    int util_v_dinamico = 0;
    Persona *v_dinamico = new Persona[tamanio]; //memoria dinámica: ME HE CREADO "tamanio" PERSONAS DINÁMICAS
    if (v_dinamico == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    
    v_estatico[0] = *carlos;
    v_estatico[1] = pepe_estatico;
    util_v_estatico = 2;
    printVectorPersonas(v_estatico, util_v_estatico);
    
    v_dinamico[0] = pepe_estatico; //TIPOS COMPATIBLES!!!
    //v[0] = pepe; //TIPOS INCOMPATIBLES!!!
    v_dinamico[0] = *pepe; //UNA COPIA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    v_dinamico[1] = *jose;
    v_dinamico[2] = pepe_estatico;
    util_v_dinamico = 3;
    //v contiene la dirección de la primera Persona
    printVectorPersonas(v_dinamico, util_v_dinamico);
    
    
    //Uso y testing del resize
    int nuevo_tam = tamanio+2; // CRECER
    v_dinamico = resize(v_dinamico,util_v_dinamico,tamanio,nuevo_tam);
    printVectorPersonas(v_dinamico,util_v_dinamico);
    
    nuevo_tam = tamanio-4; //DECRECER
    v_dinamico = resize(v_dinamico,util_v_dinamico,tamanio, nuevo_tam);
    printVectorPersonas(v_dinamico,nuevo_tam);
 
    
    //LIBERAR LA MEMORIA
    delete [] v_dinamico;  //BORRO LAS COPIAS DE LAS PERSONAS GUARDADAS EN EL VECTOR DINÁMICO DE PERSONAS!!!!
    //Borro las personas que tenía creadas antes
    borrarPersona(pepe);
    borrarPersona(carlos);
    borrarPersona(jose);
    
    //Borrar las direcciones donde estaba la memoria reservada
    v_dinamico = pepe = carlos = jose = 0;
    
}