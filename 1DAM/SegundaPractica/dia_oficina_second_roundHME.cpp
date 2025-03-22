#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BLUE    "\x1b[34m"


#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Modulo que muestra por pantalla la bienvenida al programa
 * @post Queda mostrada la bienvenida al programa
 * @version 1.0
 * @author Hanok
*/
void BienvenidaPrograma();

/**
 * @brief Modulo que contiene el menu para elegir que funcionalidad elegir en el programa
 *
*/
void MenuPrograma();

/**
 * @brief Modulo que se encarga de pedir las opciones que contiene el menu del programa
 * @param opcion(E/S) Opcion que va a elegir el usuario
 * @return Devuelve la opcion cambiada en funcion de lo que elija el usuario.
 * @version 1.0
 * @author Hanok
*/
void PedirOpcion(char &opcion);


/**
 * @brief Modulo que se encarga de hacer la media de los numeros reales albergados en el vector
 * @param vector(E) Vector que contiene los valores a calcular
 * @param util_v(E) Util del vector que representa tanto el nº de componentes utilizados y la siguiente posicion libre
 * @param DIM_V(E) Dimensionalidad del vector
 * @pre util_v < DIM_v && util_v > 0
 * @return Devuelve un resultado de calcular la media de los valores que contiene el vector
 * @version 1.0
 * @author Hanok
*/
float calcularMedia(const int vector[], const int util_v, const int DIM_V);

/**
 * @brief Modulo que saca por pantalla una tabla con una serie de de datos
 * @param vector(E) Vector que contiene los valores a mostrar (Se pasan todas los vectores por separado)
 * @param util_v(E) Util del vector que representa tanto el nº de componentes utilizados y la siguiente posicion libre (se pasan todas las utiles por separado )
 * @param DIM_V(E) Dimensionalidad del vector 
 * @param media(E) Media de cada una de las notas (se pasan todas las medias por separado)
 * @post Queda mostrada la tabla con los valores
 * @version 1.0
 * @author Hanok
*/
void ImprimirTabla(const int vector_prog[], const int util_v_prog, const int vector_bd[], const int util_v_bd, const int vector_ed[], const int util_v_ed, const int vector_lm[], const int util_v_lm, const int vector_si[], const int util_v_si, const int vector_fol[], const int util_v_fol, const int DIM_V, const float media_prog, const float media_bd, const float media_ed, const float media_lm, const float media_si, const float media_fol, int v_estudiantes[], int util_v_estudiantes);


/**
 * @brief Módulo que se encarga de cambiar un valor determinado en un vector
 * @param vector(E/S) vector que contiene los valores
 * @param util_v(E) Util del vector que representa tanto el nº de componentes utilizados y la siguiente posicion libre
 * @param DIM_V(E) Dimension del vector
 * @post Valor del vector camiado
 * @version 1.0
 * @author Hanok
*/
void cambiarValor(float vector[], const int util_v, const int DIM_V, int id_estudiante);


/**
 * @brief Módulo que se pedir por pantalla la asignatura o vector que quieres elegir
 * @param asignatura(E/S) asignatura elegida
 * @post vector elegido
 * @version 1.0
 * @author Hanok
*/
void pedirAsignatura(int &asignatura);

/**
 * @brief Módulo que se encarga de pedir la posicion de un vector
 * @param id_estudiante(E/S) numero de estudiante a elegir 
 * @post posicion del vector elegida
 * @version 1.0
 * @author Hanok
*/
void pedirPosicionVector(int &id_estudiante, const int util_v);


/**
 * @brief Módulo que se encarga de agregar al vector un nuevo elemento
 * @param vector(E/S) vector que contiene los valores
 * @param util_v(E/S) Util del vector que representa tanto el nº de componentes utilizados y la siguiente posicion libre
 * @param DIM_V(E) Dimension del vector
 * @post Valor añadido en el vector
 * @version 1.0
 * @author Hanok
*/
void agregarElementoVector(float vector[], int &util_v, const int DIM_V);

/**
 * @brief Módulo que copia los elementos de un vector en otro
 * @param vector1(E) vector que contiene los valores a copiar
 * @param estudiante(E) posicion del vector que queremos copiar
 * @param DIM_V1(E) Dimension del vector1
 * @param vector2(E/S) vector en el que queremos copiar los valores
 * @param util_v2(E/S) Util del vector que representa tanto el nº de componentes utilizados y la siguiente posicion libre
 * @param DIM_V2(E) Dimension del vector2
 * @post Se ha copiado el valor del vector1 en el vector2
 * @version 1.0
 * @author Hanok
*/
void copiarElementosDeUnVectorAotroVector(const float vector1[], int estudiante, const int DIM_V1, float vector2[], int &util_v2, const int DIM_V2);


/**
 * @brief Modulo que imprime por pantala la media de un alumno
 * @param media(E) media del alumno
 * @post Se ha mostrado la media total del alumno
 * @version 1.0
 * @author Hanok
*/
void ImprimirMedia(float media);


/**
void eliminarAlumno(const int vector_prog[], const int util_v_prog, const int vector_bd[], const int util_v_bd, const int vector_ed[], const int util_v_ed, const int vector_lm[], const int util_v_lm, const int vector_si[], const int util_v_si, const int vector_fol[], const int util_v_fol, const int DIM_V, int v_estudiantes[], int util_v_estudiantes);
*/




int main(){

        MenuPrograma();


}

/**
void eliminarAlumno(const int vector_prog[], const int util_v_prog, const int vector_bd[], const int util_v_bd, const int vector_ed[], const int util_v_ed, const int vector_lm[], const int util_v_lm, const int vector_si[], const int util_v_si, const int vector_fol[], const int util_v_fol, const int DIM_V, int v_estudiantes[], int util_v_estudiantes, int id_estudiante){

        util_v_estudiantes = id_estudiante;

        for(int i = util_v_estudiantes; i <= util_v_estudiantes; i++ ){
        
                vector_prog[i] = vector_prog[i + 1];
                vector_bd[i] = vector_bd[i + 1];
                vector_ed[i] = vector_ed[i + 1];
                vector_lm[i] = vector_lm[i + 1];
                vector_si[i] = vector_si[i + 1];
                vector_fol[i] = vector_fol[i + 1];
                
                util_v_prog --;
                util_v_bd --;
                util_v_ed --;
                util_v_lm --;
                util_v_si --;
                util_v_fol --;
                
        }
               


}
*/

void ImprimirMedia(float media){

        cout << "La media es: " << media << endl;

}

void copiarElementosDeUnVectorAotroVector(const float vector1[], int estudiante, const int DIM_V1, float vector2[], int &util_v2, const int DIM_V2){

                
                vector2[util_v2] = vector1[estudiante];
                util_v2 ++;
        
        
}

void agregarElementoVector(float vector[], int &util_v, const int DIM_V){
        
        
        cin >> vector[util_v];
        util_v++;
        
}

void cambiarValor(float vector[], const int util_v, const int DIM_V, int id_estudiante){

        cout << "Introduce la nueva nota: ";
        cin >> vector[id_estudiante];
        
}

void BienvenidaPrograma(){

        cout << "BIENVENID@ A STUDENT DEATH by Tortuguita Soft(Version 1.0 by Hanok Martin Exposito" << endl;
        cout << "FUNCIONALIDADES DEL ADMINISTRADOR" << endl;


}

void CargarDatos(){

        cout << "CARGANDO DATOS, ESPERE UN MOMENTO...." << endl;

}

void pedirPosicionVector(int &id_estudiante, const int util_v){
                
        
        do{
                cout << "A que alumno quiere modificarle las notas, empezando desde el 0: ";
                cin >> id_estudiante;
                
        }while((id_estudiante < 0) || (id_estudiante >= util_v));                

}

void pedirAsignatura(int &asignatura){

        do{
                cout<< "En que asignatura quiere modificarle la nota: " << endl;
                cout << "" << endl;
                cout << "PROG = 1" << endl;
                cout << "" << endl;
                cout << "BD = 2" << endl;
                cout << "" << endl;
                cout << "ED = 3" << endl;
                cout << "" << endl;
                cout << "LM = 4" << endl;
                cout << "" << endl;
                cout << "SI = 5" << endl;
                cout << "" << endl;
                cout << "FOL = 6" << endl;
                cout << "" << endl;
                cout << "Introduce aqui el numero: ";
                cin >> asignatura;
                cout << "" << endl;
                
        }while((asignatura <= 0) || (asignatura > 6));

}

float calcularMedia(const float vector[], const int util_v, const int DIM_V){
        
        float media = 0.0;
        
        for(int i = 0; i < util_v; i++){
        
                media += vector[i];
        
        }
        media /= util_v;
        
        return media;


}


void ImprimirTabla(const float vector_prog[], const int util_v_prog, const float vector_bd[], const int util_v_bd, const float vector_ed[], const int util_v_ed, const float vector_lm[], const int util_v_lm, const float vector_si[], const int util_v_si, const float vector_fol[], const int util_v_fol, const int DIM_V, const float media_prog, const float media_bd, const float media_ed, const float media_lm, const float media_si, const float media_fol, int v_estudiantes[], int util_v_estudiantes){

        cout << "________________CALIFICACIONES_____________" << endl;
        cout << "ID";
        cout << "\tPROG";
        cout << "\tBD";        
        cout << "\tED";
        cout << "\tLM";
        cout << "\tSI";
        cout << "\tFOL" << endl;
        
        
        for(int i = 0; i < util_v_prog; i++){
                
                cout << i << "\t" << vector_prog[util_v_estudiantes] << "\t" << vector_bd[util_v_estudiantes] << "\t" << vector_ed[util_v_estudiantes] << "\t" << vector_lm[util_v_estudiantes] << "\t" << vector_si[util_v_estudiantes] << "\t" << vector_fol[util_v_estudiantes] << endl;
                
                util_v_estudiantes ++;
                
        }
        
        cout << "MEDIA   " << media_prog << "\t" << media_bd << "\t" << media_ed << "\t" << media_lm << "\t" << media_si << "\t" << media_fol << endl;
        cout << "" << endl;
        cout << "TOTAL ESTUDIANTES EN SISTEMA = " << util_v_prog << endl;
        cout << "" << endl;
        cout << "TOTAL ESTUDIANTES MÁXIMOS DISPONIBLES = " << DIM_V <<endl;
        cout << "" << endl;
        

}

void PedirOpcion(char &opcion){
        
        cout << BLUE << "Pulse la tecla que desee para realizar una de las siguientes acciones: " << endl;
        cout << "" << endl;
        cout << "Para cargar los datos del sistema pulse '1'. " << endl;
        cout << "" << endl;
        cout << "Para calcular la media de los valores introducidos pulse '2'. " << endl;
        cout << "" << endl;
        cout << "Para modificar una nota de un alumno determinado pulse '3'. " << endl;
        cout << "" << endl;
        cout << "Para añadir un nuevo alumno con sus calificaciones pulse '4'. " << endl;
        cout << "" << endl;
        cout << "Para calcular la media de un estudiante concreto pulse '5'. " << endl;
        cout << "" << endl;
        cout << "Si no desea hacer nada mas, pulse '0'. " << RESET << endl;
        cout << "" << endl;
        cout << "Introduce aquí el numero: ";
        cin >> opcion;
        cout << "" << endl;

}

void MenuPrograma(){

        //CONSTANTE
                
        const int DIM_NOTAS = 22;
        const int DIM_ASIGNATURAS = 6;
        
        //VECTORES
        
        float v_notas_PROG[DIM_NOTAS] = {5.0, 0.0, 5.0};
        float v_notas_BD[DIM_NOTAS] = {6.15, 0.0, 6.15};
        float v_notas_ED[DIM_NOTAS] = {4.0, 0.0, 4.0};
        float v_notas_LM[DIM_NOTAS] = {3.75,0.0, 3.75};
        float v_notas_SI[DIM_NOTAS] = {7.85, 0.0, 7.85};
        float v_notas_FOL[DIM_NOTAS] = {10.0, 0.0, 10.0};
        float v_medias[DIM_ASIGNATURAS] = {0};
        int v_estudiantes[DIM_NOTAS] = {0, 1, 2};
        
        //ÚTILES
        
        int util_v_PROG = 3;
        int util_v_BD = 3;
        int util_v_ED = 3;
        int util_v_LM = 3;
        int util_v_SI = 3;
        int util_v_FOL = 3;
        int util_v_medias = 0;
        int util_v_estudiantes = 0;
        
        //MEDIAS
        float media_prog = 0.0;
        float media_bd = 0.0;
        float media_ed = 0.0;
        float media_lm = 0.0;
        float media_si = 0.0;
        float media_fol = 0.0;
        float total_media_alumno = 0.0;
        
        //OTROS
        
        char opcion;
        
        int id_estudiante = 0;
        int asignatura = 0;
        
        
        BienvenidaPrograma();
        
        do{
                PedirOpcion(opcion);
        
                switch(opcion){
                
                        case '1':
                        
                               CargarDatos();
                        
                        break;
                        
                        case '2':
                                
                                media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS);
                                ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                        
                        break;
                        
                        case '3':
                        
                                pedirPosicionVector(id_estudiante, util_v_PROG);
                                pedirAsignatura(asignatura);
                                
                                if(asignatura == 1){
                                        
                                        cambiarValor(v_notas_PROG, util_v_PROG, DIM_NOTAS, id_estudiante);
                                        media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                        media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                        media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                        media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                        media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                        media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS);                                                                             
                                        ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                                
                                } else if(asignatura == 2){
                                
                                        cambiarValor(v_notas_BD, util_v_BD, DIM_NOTAS, id_estudiante);
                                        media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                        media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                        media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                        media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                        media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                        media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS);  
                                        ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                                
                                } else if(asignatura == 3){
                                
                                        cambiarValor(v_notas_ED, util_v_ED, DIM_NOTAS, id_estudiante);
                                        media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                        media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                        media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                        media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                        media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                        media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS);  
                                        ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                                
                                } else if(asignatura == 4){
                                
                                        cambiarValor(v_notas_LM, util_v_LM, DIM_NOTAS, id_estudiante);
                                        media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                        media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                        media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                        media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                        media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                        media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS);  
                                        ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                                
                                } else if(asignatura == 5){
                                
                                        cambiarValor(v_notas_SI, util_v_SI, DIM_NOTAS, id_estudiante);
                                        media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                        media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                        media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                        media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                        media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                        media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS);  
                                        ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                                
                                } else if(asignatura == 6){
                                
                                        cambiarValor(v_notas_FOL, util_v_FOL, DIM_NOTAS, id_estudiante);
                                        media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                        media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                        media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                        media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                        media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                        media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS);  
                                        ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                                
                                }
                               
                        
                        break;
                        
                        case '4':
                        
                                cout << "Introduce la nota de PROG: ";
                                agregarElementoVector(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                cout << "Introduce la nota de BD: ";
                                agregarElementoVector(v_notas_BD, util_v_BD, DIM_NOTAS);
                                media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                cout << "Introduce la nota de ED: ";
                                agregarElementoVector(v_notas_ED, util_v_ED, DIM_NOTAS);
                                media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                cout << "Introduce la nota de LM: ";
                                agregarElementoVector(v_notas_LM, util_v_LM, DIM_NOTAS);
                                media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                cout << "Introduce la nota de SI: ";
                                agregarElementoVector(v_notas_SI, util_v_SI, DIM_NOTAS);
                                media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                cout << "Introduce la nota de FOL: ";
                                agregarElementoVector(v_notas_FOL, util_v_FOL, DIM_NOTAS);
                                media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS); 
                                
                            
                                
                                ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                                
                        
                        
                        break;
                        
                        case '5':
                                media_prog = calcularMedia(v_notas_PROG, util_v_PROG, DIM_NOTAS);
                                media_bd = calcularMedia(v_notas_BD, util_v_BD, DIM_NOTAS);
                                media_ed = calcularMedia(v_notas_ED, util_v_ED, DIM_NOTAS);
                                media_lm = calcularMedia(v_notas_LM, util_v_LM, DIM_NOTAS);
                                media_si = calcularMedia(v_notas_SI, util_v_SI, DIM_NOTAS);
                                media_fol = calcularMedia(v_notas_FOL, util_v_FOL, DIM_NOTAS);                        
                                ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                                
                                pedirPosicionVector(id_estudiante, util_v_PROG);
                                
                                copiarElementosDeUnVectorAotroVector(v_notas_PROG, id_estudiante, DIM_NOTAS, v_medias, util_v_medias, DIM_ASIGNATURAS);
                                copiarElementosDeUnVectorAotroVector(v_notas_BD, id_estudiante, DIM_NOTAS, v_medias, util_v_medias, DIM_ASIGNATURAS);
                                copiarElementosDeUnVectorAotroVector(v_notas_ED, id_estudiante, DIM_NOTAS, v_medias, util_v_medias, DIM_ASIGNATURAS);
                                copiarElementosDeUnVectorAotroVector(v_notas_LM, id_estudiante, DIM_NOTAS, v_medias, util_v_medias, DIM_ASIGNATURAS);
                                copiarElementosDeUnVectorAotroVector(v_notas_SI, id_estudiante, DIM_NOTAS, v_medias, util_v_medias, DIM_ASIGNATURAS);
                                copiarElementosDeUnVectorAotroVector(v_notas_FOL, id_estudiante, DIM_NOTAS, v_medias, util_v_medias, DIM_ASIGNATURAS);
                                
                                
                                total_media_alumno = calcularMedia(v_medias, util_v_medias, DIM_ASIGNATURAS);
                                
                                ImprimirMedia(total_media_alumno);
                        
                                
                        
                        
                        break;
                        
                        /**
                        case '6':
                        
                                pedirPosicionVector(id_estudiante, util_v_estudiantes);
                                
                                eliminarAlumno(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, v_estudiantes, util_v_estudiantes, id_estudiante);
                                
                                ImprimirTabla(v_notas_PROG, util_v_PROG, v_notas_BD, util_v_BD, v_notas_ED, util_v_ED, v_notas_LM, util_v_LM, v_notas_SI, util_v_SI, v_notas_FOL, util_v_FOL,   DIM_NOTAS, media_prog, media_bd, media_ed, media_lm, media_si, media_fol, v_estudiantes, util_v_estudiantes);
                        
                        
                        break;
                        */
                        
                        
                        
                        default:
                                cout << "Número invalido..." << endl;
                                
                                                          
                                                                               
                
                }
                
        }while(opcion != '0');


}

