#include <iostream>
using namespace std;

const int MAX_CARACTERES_NOM_ALUMNO = 50;
const int MAX_CARACTERES_APE_ALUMNO = 50;
const int MAX_CARACTERES_COD_ASIG = 7;
const int MAX_CARACTERES_NOMBRE_ASIG = 40;
const int MAX_CARACTERES_ID_ALUMNO = 22;
const int MAX_ALUMNOS = 22;
const int MAX_ASIGNATURAS = 6;
const int MAX_MATRICULAS = 132;


///////////////FECHA////////////////
struct Fecha{
    int dia;
    int mes;
    int ano;
};

/**
 * @brief Establece el dia en la variable de tipo fecha
 * @param f hace referencia a la variable de tipo fecha a la que se le quiere introducir el dia
 * @param dia variable que contiene el dia que se quiere establecer
 * @pre dia debe ser (>=1 && <=31)
 * @post el dia de t, será actualizado con el valor proporcionado
*/
void setDiaFecha(Fecha &f, int dia);

/**
 * @brief Establece el mes en la variable de tipo fecha.
 * @param f hace referencia a la variable de tipo fecha a la que se le quiere introducir el mes.
 * @param mes variable que contiene el mes que se quiere establecer.
 * @pre mes debe ser (>=1 && <=12).
 * @post el mes de f será actualizado con el valor proporcionado.
*/
void setMesFecha(Fecha &f, int mes);

/**
 * @brief Establece el anyo en la variable de tipo fecha.
 * @param f hace referencia a la variable de tipo fecha a la que se le quiere introducir el anyo.
 * @param anyo variable que contiene el anyo que se quiere establecer.
 * @pre anyo debe ser un valor positivo.
 * @post el anyo de f será actualizado con el valor proporcionado.
*/
void setAnoFecha(Fecha &f, int ano);

/**
 * @brief Establece la fecha completa en la variable de tipo fecha.
 * @param f hace referencia a la variable de tipo fecha a la que se le quiere introducir la fecha completa.
 * @param dia variable que contiene el día que se quiere establecer.
 * @param mes variable que contiene el mes que se quiere establecer.
 * @param anyo variable que contiene el anyo que se quiere establecer.
 * @pre dia debe ser (>=1 && <=31), mes debe ser (>=1 && <=12) y anyo debe ser un valor positivo.
 * @post la fecha completa de f será actualizada con los valores proporcionados.
*/
void setFecha(Fecha &f, int dia, int mes, int ano);

/**
 * @brief Obtiene el día almacenado en la variable de tipo fecha.
 * @param f hace referencia a la variable de tipo fecha de la que se obtendrá el día.
 * @return el día almacenado en la variable de tipo fecha.
 * @post se ha obtenido el día almacenado correctamente en la variable de tipo fecha.
*/
int getDiaFecha(const Fecha &f);

/**
 * @brief Obtiene el mes almacenado en la variable de tipo fecha.
 * @param f hace referencia a la variable de tipo fecha de la que se obtendrá el mes.
 * @return el mes almacenado en la variable de tipo fecha.
 * @post se ha obtenido el mes almacenado correctamente en la variable de tipo fecha.
*/
int getMesFecha(const Fecha &f);

/**
 * @brief Obtiene el anyo almacenado en la variable de tipo fecha.
 * @param f hace referencia a la variable de tipo fecha de la que se obtendrá el anyo.
 * @return el anyo almacenado en la variable de tipo fecha.
 * @post se ha obtenido el anyo almacenado correctamente en la variable de tipo fecha.
*/
int getAnoFecha(const Fecha &f);

/**
 * @brief Imprime la fecha en formato día/mes/anyo.
 * @param f hace referencia a la fecha que se desea imprimir.
 * @post se ha impreso la fecha correctamente en la consola en formato día/mes/anyo.
*/
void printFecha(const Fecha &f);


//////////////ALUMNO///////////////////////
struct Alumno{
    int id;
    char nombre[MAX_CARACTERES_NOM_ALUMNO];
    char apellido1[MAX_CARACTERES_APE_ALUMNO];
    char apellido2[MAX_CARACTERES_APE_ALUMNO];
    Fecha fechaNacimiento;
};

/**
 * @brief Establece el ID del alumno.
 * @param a hace referencia al alumno al que se le quiere establecer el ID.
 * @param id el ID que se quiere establecer para el alumno.
 * @post el ID del alumno será actualizado con el valor proporcionado.
*/
void setIdAlumno(Alumno &a, int id);

/**
 * @brief Establece el nombre del alumno.
 * @param a hace referencia al alumno al que se le quiere establecer el nombre.
 * @param nombre el nombre que se quiere establecer para el alumno.
 * @post el nombre del alumno será actualizado con el valor proporcionado.
*/
void setNombreAlumno(Alumno &a,const char nombre[]);

/**
 * @brief Establece el primer apellido del alumno.
 * @param a hace referencia al alumno al que se le quiere establecer el primer apellido.
 * @param apellido1 el primer apellido que se quiere establecer para el alumno.
 * @post el primer apellido del alumno será actualizado con el valor proporcionado.
*/
void setApellido1Alumno(Alumno &a,const char apellido1[]);

/**
 * @brief Establece el segundo apellido del alumno.
 * @param a hace referencia al alumno al que se le quiere establecer el segundo apellido.
 * @param apellido2 el segundo apellido que se quiere establecer para el alumno.
 * @post el segundo apellido del alumno será actualizado con el valor proporcionado.
*/
void setApellido2Alumno(Alumno &a,const char apellido2[]);

/**
 * @brief Módulo que permite actualizar el valor del miembro "fecha_nacimiento" del dato compuesto introducido de tipo "Alumno".
 * @param a Es el tipo de dato compuesto de tipo "Alumno" que queremos modificar.
 * @param f Es el valor del miembro "fecha_nacimiento", dato compuesto de tipo Fecha, que queremos actualizar en nuestro dato compuesto introducido de tipo "Alumno".
 * @post Se actualizará el valor del miembro "fecha_nacimiento", correspondiente al dato estructurado de tipo "Alumno" introducido, con los valores que hubiera almacenados en "f".
 * @author Hanok
 * @version 2.5
 */
void setFechaNacimientoAlumno(Alumno &a, const Fecha &f);

/**
 * @brief Módulo que permite actualizar los valores de todos los miembros del dato compuesto de tipo Alumno introducido "a".
 * @param a Es el tipo de dato compuesto de tipo "Alumno" que queremos modificar.
 * @param id Es el valor del miembro "id" que queremos modificar en nuestro dato compuesto de tipo Alumno.
 * @param nombre[] Son los valores almacenados en el vector de char introducido, que queremos modificar en nuestro miembro nombre perteneciente al dato compuesto de tipo Alumno.
 * @param apellido1[] valor almacenado en el vector de char introducido, que queremos modificar en nuestro miembro apellido1, perteneciente al tipo alumno.
 * @param apellido2[] valor almacenado en el vector de char introducido, que queremos modificar en nuestro miembro apellido2, perteneciente al tipo alumno.
 * @param fechaNacimiento Es el valor del miembro fecha_nacimiento, dato compuesto de tipo Fecha, que queremos actualizar en nuestro dato compuesto introducido de tipo Alumno.
 * @post Se actualizarán los valores de todos los miembros, correspondiente al tipo Alumno introducido, con los valores que hubiera almacenados en en el resto de variables  introducidas.
 * @author Hanok
 * @version 2.5
 */
void setAlumno(Alumno &a, int id, char nombre[], char apellido1[], char apellido2[], const Fecha &fechaNacimiento);

/**
 * @brief Obtiene el ID del alumno.
 * @param a hace referencia al alumno del que se desea obtener el ID.
 * @return el ID del alumno.
 * @post se ha obtenido el ID del alumno correctamente.
*/
int getIdAlumno(const Alumno &a);

/**
 * @brief Obtiene el nombre del alumno.
 * @param a hace referencia al alumno del que se desea obtener el nombre.
 * @return el nombre del alumno.
 * @post se ha obtenido el nombre del alumno correctamente.
*/
void getNombreAlumno(const Alumno &a, char nombre[]);

/**
 * @brief Obtiene el primer apellido del alumno.
 * @param a hace referencia al alumno del que se desea obtener el primer apellido.
 * @return el primer apellido del alumno.
 * @post se ha obtenido el primer apellido del alumno correctamente.
*/
void getApellido1Alumno(const Alumno &a, char apellido1[]);

/**
 * @brief Obtiene el segundo apellido del alumno.
 * @param a hace referencia al alumno del que se desea obtener el segundo apellido.
 * @return el segundo apellido del alumno.
 * @post se ha obtenido el segundo apellido del alumno correctamente.
*/
void getApellido2Alumno(const Alumno &a, char apellido2[]);

/**
 * @brief Módulo que devuelve el valor del miembro fechaNacimiento (dato compuesto de tipo Fecha) del dato introducido de tipo Alumno.
 * @param a Es el tipo de dato compuesto de tipo Alumno introducido.
 * @param FechaNacimiento Es el tipo de dato compuesto de Tipo Fecha introducido.
 * @return Fecha Es el valor que se devuelve, correspondiente al miembro fechaNacimiento del ipo Alumno ingresado.
 * @post Devolverá el valor del miembro fechaNacimiento, correspondiente al tipo Alumno introducido.
 * @author Hanok
 * @version 2.5
 */
void getFechaNacimientoAlumno(const Alumno &a, Fecha &fechaNacimiento);

/**
 * @brief Imprime los detalles del alumno.
 * @param a hace referencia al alumno del que se desea imprimir los detalles.
 * @post se han impreso los detalles del alumno correctamente en la consola.
*/
void printAlumno(const Alumno &a);

/**
 * @brief Módulo que permite al usuario introducir los valores de todos los miembros del dato compuesto introducido de tipo "Alumno".
 * @param a Es el tipo de dato compuesto de tipo "Alumno" introducido.
 * @post Actualizará los valores de todos los miembros correspondientes al dato estructurado "a" de tipo "Alumno" introducido.
 * @author Hanok
 * @version 2.5
 */
void introducirDatosAlumno(Alumno &a, Alumno v_lista_estudiante[], int util_v_lista_estudiante);

/**
 * @brief Inserta un alumno en un vector de alumnos.
 * @param v_lista_estudiante vector de alumnos donde se insertará el nuevo alumno
 * @param util_v_lista_estudiante variable que contiene el número de alumnos que hay en el vector
 * @pre util_v_lista_estudiante < MAX_ALUMNOS
 * @post se habrá insertado el alumno en el vector de alumnos
 * @version 2.5
 * @author Hanok
 */
void insertarAlumnoEnVectorAlumno(Alumno v_lista_estudiante[], int &util_v_lista_estudiante, const Alumno &alumno);

/**
 * @brief Módulo que permite asignar los caracteres de un origen a un destino
 * @param a (E) parametro de entrada que contiene los valores a copiar
 * @param b (S) parametro de salida en el que se van a copiar los caracteres
 * @post se habran copiado todos los caracteres de origen en destino
 * @version 2.5
 * @author Hanok
 */
void asignarAlumno(Alumno &a, const Alumno &b);

void printIdAlumno( );


/////////////////////ASIGNATURA//////////////////
struct Asignatura{
    char cod_asig[MAX_CARACTERES_COD_ASIG];
    char nombreAsig[MAX_CARACTERES_NOMBRE_ASIG];
};

/**
 * @brief Establece el cod_asig en la variable a de tipo asignatura.
 * @param a hace referencia a la asignatura al que se le quiere establecer el cod_asig.
 * @param cod_asig parametro que se quiere utilizar para establecer el cod_asig en la variable a.
 * @post cod_asig será establecido correctamente en la variable a de tipo asignatura.
 * @version 2.5
 * @author Hanok
 */
void setCodAsig(Asignatura &a, const char cod_asig[]);

/**
 * @brief Establece el nombre de la asignatura en la variable a de tipo asignatura.
 * @param a hace referencia a la asignatura al que se le quiere establecer el nombre de la asignatura.
 * @param nombreAsig parametro que se quiere utilizar para establecer el nombre de la asignatura en la variable a.
 * @post nombreAsig será establecido correctamente en la variable a de tipo asignatura.
 * @version 2.5
 * @author Hanok
 */
void setNombreAsig(Asignatura &a, const char nombreAsig[]);

/**
 * @brief Obtiene el cod_asig almacenado en la variable de tipo asignatura.
 * @param a hace referencia a la asignatura de la que se desea obtener el cod_asig.
 * @param cod_asig variable donde se almacenará el cod_asig obtenido.
 * @post se ha obtenido el cod_asig almacenado correctamente en la variable de tipo asignatura.
 * @version 2.5
 * @author Hanok
 */
void getCodAsig(const Asignatura &a, char cod_asig[]);

/**
 * @brief Obtiene el nombre de la asignatura almacenado en la variable de tipo asignatura.
 * @param a hace referencia a la asignatura de la que se desea obtener el nombre de la asignatura.
 * @param nombreAsig variable donde se almacenará el nombre de la asignatura obtenido.
 * @post se ha obtenido el nombre de la asignatura almacenado correctamente en la variable de tipo asignatura.
 * @version 2.5
 * @author Hanok
 */
void getNombreAsig(const Asignatura &a, char nombreAsig[]);

/**
 * @brief Establece el cod_asig y el nombre de la asignatura en la variable a de tipo asignatura.
 * @param a hace referencia a la asignatura al que se le quiere establecer el cod_asig y el nombre de la asignatura.
 * @param cod_asig parametro que se quiere utilizar para establecer el cod_asig en la variable a.
 * @param nombreAsig parametro que se quiere utilizar para establecer el nombre de la asignatura en la variable a.
 * @post cod_asig y nombreAsig serán establecidos correctamente en la variable a de tipo asignatura.
 * @version 2.5
 * @author Hanok
 */
void setAsignatura(Asignatura &a, char cod_asig[], char nombreAsig[]);

/**
 * @brief Módulo que permite al usuario introducir los valores de todos los miembros del dato compuesto introducido de tipo "Asignatura". 
 * @param a Es el tipo de dato compuesto de tipo "Asignatura" introducido.
 * @post Actualizará los valores de todos los miembros correspondientes al dato estructurado "a" de tipo "Asignatura" introducido.
 * @version 2.5
 * @author Hanok
 */
void introducirDatosAsignatura(Asignatura &a);

/**
 * @brief Imprime los detalles de la asignatura.
 * @param a hace referencia a la asignatura del que se desea imprimir los detalles.
 * @post se han impreso los detalles de la asignatura correctamente en la consola.
 * @version 2.5
 * @author Hanok
 */
void printAsignatura(const Asignatura &a);

/**
 * @brief Inserta una asignatura en un vector de asignaturas.
 * @param v_lista_asignatura vector de asignaturas donde se insertará la nueva asignatura
 * @param util_v_lista_asignatura variable que contiene el número de asignaturas que hay en el vector 
 * @pre util_v_lista_asignatura < MAX_ASIGNATURAS
 * @post se habrá insertado la asignatura en el vector de asignaturas
 * @version 2.5
 * @author Hanok
 */
void insertarAsignaturaEnVectorAsignatura(Asignatura v_lista_asignatura[], int &util_v_lista_asignatura, const Asignatura &asignatura);

/**
 * @brief Módulo que permite asignar los caracteres de un origen a un destino
 * @param a (E) parametro de entrada que contiene los valores a copiar
 * @param b (S) parametro de salida en el que se van a copiar los caracteres
 * @post se habran copiado todos los caracteres de origen en destino
 * @version 2.5
 * @author Hanok
 */
void asignarAsignatura(Asignatura &a, const Asignatura &b);

void printAsignaturas(const Asignatura v_lista_asignatura[], int util_v_lista_asignatura);


///////////////////MATRICULA////////////////
struct Matricula{
    Alumno alumno;
    Asignatura asignatura;
    float nota;
};

/**
 * @brief Establece el alumno en la variable de tipo matricula.
 * @param m hace referencia a la matricula al que se le quiere establecer el alumno.
 * @param a el alumno que se quiere establecer para la matricula.
 * @post el alumno de m será actualizado con el valor proporcionado.
 * @version 2.5
 * @author Hanok
 */
void setAlumnoMatricula(Matricula &m, const Alumno &a);

/**
 * @brief Establece la asignatura en la variable de tipo matricula.
 * @param m hace referencia a la matricula al que se le quiere establecer la asignatura.
 * @param a la asignatura que se quiere establecer para la matricula.
 * @post la asignatura de m será actualizada con el valor proporcionado.
 * @version 2.5
 * @author Hanok
 */
void setAsignaturaMatricula(Matricula &m, const Asignatura &a);

/**
 * @brief Establece la nota en la variable de tipo matricula.
 * @param m hace referencia a la matricula al que se le quiere establecer la nota.
 * @param nota la nota que se quiere establecer para la matricula.
 * @post la nota de m será actualizada con el valor proporcionado.
 * @version 2.5
 * @author Hanok
 */
void setNotaMatricula(Matricula &m, float nota);

/**
 * @brief Obtiene el alumno almacenado en la variable de tipo matricula.
 * @param m hace referencia a la matricula de la que se desea obtener el alumno.
 * @param a variable donde se almacenará el alumno obtenido.
 * @post se ha obtenido el alumno almacenado correctamente en la variable de tipo matricula.
 * @version 2.5
 * @author Hanok
 */
void getAlumnoMatricula(const Matricula &m, Alumno &a);

/**
 * @brief Obtiene la asignatura almacenada en la variable de tipo matricula.
 * @param m hace referencia a la matricula de la que se desea obtener la asignatura.
 * @param a variable donde se almacenará la asignatura obtenida.
 * @post se ha obtenido la asignatura almacenada correctamente en la variable de tipo matricula.
 * @version 2.5
 * @author Hanok
 */
void getAsignaturaMatricula(const Matricula &m, Asignatura &a);

/**
 * @brief Obtiene la nota almacenada en la variable de tipo matricula.
 * @param m hace referencia a la matricula de la que se desea obtener la nota.
 * @return la nota almacenada en la variable de tipo matricula.
 * @post se ha obtenido la nota almacenada correctamente en la variable de tipo matricula.
 * @version 2.5
 * @author Hanok
 */
float getNotaMatricula(const Matricula &m);

/**
 * @brief Módulo que permite al usuario introducir los valores de todos los miembros del dato compuesto introducido de tipo "Matricula".
 * @param m Es el tipo de dato compuesto de tipo "Matricula" introducido.
 * @post Actualizará los valores de todos los miembros correspondientes al dato estructurado "m" de tipo "Matricula" introducido.
 * @version 2.5
 * @author Hanok
 */
void introducirDatosMatricula(Matricula &m, Alumno v_lista_estudiante[], int util_v_lista_estudiante);

/**
 * @brief Establece la matricula completa en la variable de tipo matricula.
 * @param m hace referencia a la matricula a la que se le quiere establecer la matricula completa.
 * @param nota variable que contiene la nota que se quiere establecer.
 * @param alumno variable que contiene el alumno que se quiere establecer.
 * @param asignatura variable que contiene la asignatura que se quiere establecer.
 * @pre nota debe ser un valor positivo, alumno y asignatura deben contener valores válidos.
 * @post la matricula completa de m será actualizada con los valores proporcionados.
 * @version 2.5
 * @author Hanok
 */
void setMatricula(Matricula &m, float nota, const Alumno &alumno, const Asignatura &asignatura );

/**
 * @brief Imprime los detalles de la matricula.
 * @param m hace referencia a la matricula del que se desea imprimir los detalles.
 * @post se han impreso los detalles de la matricula correctamente en la consola.
 * @version 2.5
 * @author Hanok
 */
void printMatricula(const Matricula &m);

/**
 * @brief Inserta una matricula en un vector de matriculas.
 * @param v_lista_matricula vector de matriculas donde se insertará la nueva matricula
 * @param util_v_lista_matricula variable que contiene el número de matriculas que hay en el vector 
 * @pre util_v_lista_matricula < MAX_MATRICULAS
 * @post se habrá insertado la matricula en el vector de matriculas
 * @version 2.5
 * @author Hanok
 */
void insertarMatriculaEnVectorMatricula(Matricula v_lista_matricula[], int &util_v_lista_matricula, const Matricula &matricula);

/**
 * @brief Módulo que permite asignar los caracteres de un origen a un destino
 * @param a (E) parametro de entrada que contiene los valores a copiar
 * @param b (S) parametro de salida en el que se van a copiar los caracteres
 * @post se habran copiado todos los caracteres de origen en destino
 * @version 2.5
 * @author Hanok
 */
void asignarMatricula(Matricula &a, const Matricula &b);

void printNotas();


//////////////////OTROS///////////////////

/**
 * @brief Módulo que permite asignar los caracteres de un origen a un destino
 * @param origen[] (E) parametro de entrada que contiene los valores a copiar
 * @param destino[] (S) parametro de salida en el que se van a copiar los caracteres
 * @param MAX_CARACTERES (E) parametro para controlar el maximo de caracteres a copiar
 * @post se habran copiado todos los caracteres de origen en destino
 * @version 2.5
 * @author Hanok
*/
void copiarCadenaCaracteres(const char origen[], char destino[], int MAX_CARACTERES);

/**
 * @brief Módulo que muestra por pantalla caracter a caracter un vector de char
 * @param cadena[] (E) parametro que contiene todos los caracteres a imprimir
 * @param MAX_CARACTERES (E) parametro para controlar el maximo de caracteres a mostrar
 * @post se habran mostrado todos los caracteres por pantalla
 * @version 2.5
 * @author Hanok
*/
void imprimirCadenaCaracteres(const char cadena[], int MAX_CARACTERES);

/**
 * @brief Módulo que crea los datos básicos necesarios del sistema, haciendo llamadas a otros módulos
 * @param v_lista_estudiante (E/S) vector de alumnos donde se insertarán los alumnos
 * @param util_v_lista_estudiante (E/S) variable que contiene el número de alumnos que hay en el vector
 * @param v_lista_asignatura (E/S) vector de asignaturas donde se insertarán las asignaturas
 * @param util_v_lista_asignatura (E/S) variable que contiene el número de asignaturas que hay en el vector
 * @param v_lista_matricula (E/S) vector de matriculas donde se insertarán las matriculas
 * @param util_v_lista_matriculas (E/S) variable que contiene el número de matriculas que hay en el vector
 * @post se habrán creado los datos básicos necesarios del sistema
 * @version 2.5
 * @author Hanok
 */
void crearDatosBasicosSistema(Alumno v_lista_estudiante[], int util_v_lista_estudiante, Asignatura v_lista_asignatura[], int util_v_lista_asignatura, Matricula v_lista_matricula[], int util_v_lista_matriculas);

/**
 * @brief Mñodulo que se encarga de imprimir por pantalla una tabla con los alumnos, asignaturas y matriculas
 * @param v_lista_estudiante (E) vector de alumnos donde se encuentran los alumnos
 * @param util_v_lista_estudiante (E) variable que contiene el número de alumnos que hay en el vector
 * @param v_lista_asignatura (E) vector de asignaturas donde se encuentran las asignaturas
 * @param util_v_lista_asignatura (E) variable que contiene el número de asignaturas que hay en el vector
 * @param v_lista_matricula (E) vector de matriculas donde se encuentran las matriculas
 * @param util_v_lista_matricula (E) variable que contiene el número de matriculas que hay en el vector
 * @post se habrá impreso por pantalla una tabla con los alumnos, asignaturas y matriculas
 * @version 2.5
 * @author Hanok
 */
void imprimirTabla(const Alumno v_lista_estudiante[], int &util_v_lista_estudiante,  Asignatura v_lista_asignatura[], int &util_v_lista_asignatura,  Matricula v_lista_matricula[], int &util_v_lista_matricula);

/**
 * @brief Módulo que inicializa los datos de testing
 * @param v_lista_estudiante (E/S) vector de alumnos donde se insertarán los alumnos
 * @param util_v_lista_estudiante (E/S) variable que contiene el número de alumnos que hay en el vector
 * @param v_lista_asignatura (E/S) vector de asignaturas donde se insertarán las asignaturas
 * @param util_v_lista_asignatura (E/S) variable que contiene el número de asignaturas que hay en el vector
 * @param v_lista_matricula (E/S) vector de matriculas donde se insertarán las matriculas
 * @param util_v_lista_matricula (E/S) variable que contiene el número de matriculas que hay en el vector
 * @post se habrán inicializado los datos de testing
 * @version 2.5
 * @author Hanok
 */
void inicializarDatosTesting(Alumno v_lista_estudiante[], int &util_v_lista_estudiante, Asignatura v_lista_asignatura[], int &util_v_lista_asignatura, Matricula v_lista_matricula[], int &util_v_lista_matricula);

/**
 * @brief Comprueba si dos cadenas de caracteres son iguales. 
 * @param cadena1 La primera cadena a comparar.
 * @param cadena2 La segunda cadena a comparar.
 * @return true si las cadenas son iguales, false en caso contrario.
 */
bool comprobarSiCadenasSonIguales(const char cadena1[], const char cadena2[], const int DIMENSION);

/**
 * @brief Busca las notas de un alumno en la lista de matrículas.
 * @param v_lista_matricula vector de matriculas donde se van a buscar las notas de un alumno
 * @param util_v_lista_matricula El tamaño actual de la lista de matrículas.
 * @param notas vector para almacenar las notas del alumno.
 * @param util_v_notas La cantidad de notas que contiene el v_notas
 * @param idAlumno El ID del alumno del que se buscan las notas.
 * @post se habrán buscado las notas del alumno en la lista de matrículas
 * @version 2.5
 * @author Hanok
 */
void buscarNotasAlumno(const Matricula v_lista_matricula[], int util_v_lista_matricula, float notas[], int &util_v_notas, int idAlumno);

/**
 * @brief Muestra el menú de opciones.
 */
void mostrarMenu();

/**
 * @brief Ejecuta el menú con las diferentes opciones
 * @param opcion La opción seleccionada.
 * @param v_lista_estudiante (E/S) vector de alumnos donde se insertarán los alumnos
 * @param util_v_lista_estudiante (E/S) variable que contiene el número de alumnos que hay en el vector
 * @param v_lista_asignatura (E/S) vector de asignaturas donde se insertarán las asignaturas
 * @param util_v_lista_asignatura (E/S) variable que contiene el número de asignaturas que hay en el vector
 * @param v_lista_matricula (E/S) vector de matriculas donde se insertarán las matriculas
 * @param util_v_lista_matricula (E/S) variable que contiene el número de matriculas que hay en el vector
 * @post se habrá ejecutado la opción seleccionada
 * @version 2.5
 * @author Hanok
 */
void ejecutarMenu(int opcion, Alumno v_lista_estudiante[], int &util_v_lista_estudiante,  Asignatura v_lista_asignatura[], int &util_v_lista_asignatura,  Matricula v_lista_matricula[], int &util_v_lista_matricula);

/**
 * @brief Calcula la media de un conjunto de notas.
 * @param notas El vector que contiene las notas
 * @param util_v_notas La cantidad de notas que contiene el vector
 * @return La media de las notas.
 * @version 2.5
 * @author Hanok
 */
float calcularMedia(const float notas[], int util_v_notas);

/**
 * @brief Busca las matrículas correspondientes a una asignatura.
 * @param codigoAsignatura El código de la asignatura a buscar.
 * @param v_lista_matricula vector donde se encuentran las matriculas
 * @param util_v_lista_matricula El tamaño actual de la lista de matrículas.
 * @param matriculasAsignatura vector que almacena las matriculas encontradas
 * @param util_v_matriculasAsignatura La cantidad de matrículas encontradas.
 * @post se habrán buscado las matrículas correspondientes a una asignatura
 * @version 2.5
 * @author Hanok
 */
void buscarMatriculasPorAsignatura(const char codigoAsignatura[], const Matricula v_lista_matricula[], int util_v_lista_matricula, Matricula matriculasAsignatura[], int& util_v_matriculasAsignatura);

/**
 * @brief Busca las notas de una asignatura en la lista de matrículas.
 * @param v_lista_matricula vector donde se encuentran las matriculas
 * @param util_v_lista_matricula El tamaño actual de la lista de matrículas.
 * @param notas vector que contiene las notas a buscar
 * @param util_v_notas La cantidad de notas que contiene el vector
 * @param asignatura La asignatura de la que se buscan las notas.
 * @version 2.5
 * @author Hanok
 */
void buscarNotasAsignatura(Matricula v_lista_matricula[], int util_v_lista_matricula, float v_notas[], int& util_v_notas);

float buscarNotaAlumnoEnAsignatura(int idAlumno, const char cod_asig[], const Matricula v_lista_matricula[], int util_v_lista_matricula);

/**
 * @brief Permite cambiar la nota de una matrícula concreta de un alumno y asignatura concreto.
 * @param v_lista_matricula vector que contiene las matriculas
 * @param util_v_lista_matricula El tamaño actual de la lista de matrículas.
 * @post se habrá cambiado la nota de una matrícula concreta
 * @version 2.5
 * @author Hanok
 */
void cambiarNota(Matricula v_lista_matricula[], int util_v_lista_matricula);

/**
 * @brief Inserta un nuevo estudiante junto con sus notas en la lista de estudiantes y matrículas.
 * @param v_lista_estudiante vector que contiene la lista de estudiantes
 * @param util_v_lista_estudiante El tamaño actual de la lista de estudiantes.
 * @param v_lista_asignatura vector que contiene la lista de asignaturas
 * @param util_v_lista_asignatura El tamaño actual de la lista de asignaturas.
 * @param v_lista_matricula vector que contiene la lista de matriculas
 * @param util_v_lista_matricula El tamaño actual de la lista de matrículas.
 * @post se habrá insertado un nuevo estudiante en la lista de estudiantes y matrículas, ademas de sus notas
 * @version 2.5
 * @author Hanok
 */
void insertarNuevoEstudiante(Alumno v_lista_estudiante[], int &util_v_lista_estudiante, Asignatura v_lista_asignatura[], int &util_v_lista_asignatura, Matricula v_lista_matricula[], int &util_v_lista_matricula);

/**
 * @brief Elimina un usuario junto con sus notas de la lista de estudiantes y matrículas.
 * @param listaEstudinated Lista de estudiantes donde se eliminará el usuario.
 * @param util_v_lista_estudiante Número de estudiantes en la lista.
 * @param v_lista_matricula Lista de matrículas donde se eliminarán las notas del usuario.
 * @param util_v_lista_matricula Número de matrículas en la lista.
 * @post se habrá eliminado un usuario de la lista de estudiantes y matrículas
 * @version 2.5
 * @author Hanok
 */

void eliminarUsuario(Alumno listaEstudinated[], int &util_v_lista_estudiante, Matricula v_lista_matricula[], int &util_v_lista_matricula);

/**
 * @brief Elimina las calificaciones de un alumno específico en la lista de matrículas.
 * @param v_lista_matricula Lista de matrículas.
 * @param util_v_lista_matricula Número de matrículas en la lista.
 * @param id_alumno Identificador del alumno cuyas calificaciones se desean eliminar.
 * @post se habrán eliminado las calificaciones de un alumno específico en la lista de matrículas
 * @version 2.5
 * @author Hanok
 */
void eliminarCalificaciones(int id_alumno, Matricula v_lista_matricula[], int &util_v_lista_matricula);

/**
 * @brief Calcula la media de notas de una asignatura específica.
 * @param v_lista_estudiante Lista de alumnos donde se encuentran las notas.
 * @param util_v_lista_estudiante Número de alumnos en la lista.
 * @param v_lista_matricula Lista de matriculas donde se encuentran las notas de las asignaturas.
 * @param util_v_lista_matricula Número de matriculas en la lista.
 * @param cod_asig Código de la asignatura a la que pertenecen las notas.
 * @pre util_v_lista_estudiante > 0, util_v_lista_matricula > 0
 * @post se habrá calculado la media de notas de una asignatura específica
 * @return Devuelve la media de notas de la asignatura específica.
 * @version 2.5
 * @author Hanok
 */
float calcularMediaAsignatura(const Alumno v_lista_estudiante[], int util_v_lista_estudiante, Matricula v_lista_matricula[], int util_v_lista_matricula, const char cod_asig[]);

/**
 * @brief Calcula la media de notas de un estudiante específico.
 * @param v_lista_matricula Lista de matrículas donde se encuentran las notas de las asignaturas.
 * @param util_v_lista_matricula Número de matrículas en la lista.
 * @param alumno Estudiante cuyas notas se desean calcular.
 * @pre util_v_lista_matricula > 0
 * @post se habrá calculado la media de notas de un estudiante específico
 * @return Devuelve la media de notas de un estudiante específico.
 * @version 2.5
 * @author Hanok
 */
float calcularMediaEstudiante(Matricula v_lista_matricula[], int util_v_lista_matricula, const Alumno &alumno);


/**
 * @brief Ordena la lista de estudiantes por su nota media, excluyendo a aquellos cuya nota media sea inferior a la nota mínima especificada.
 * 
 * @param v_lista_estudiante vector de estudiantes.
 * @param util_v_lista_estudiante Util del vector de estudiantes.
 * @param v_lista_matricula vector de matrículas.
 * @param util_v_lista_matricula Util del vector de matrículas.
 * @param v_lista_asignatura vector de asignaturas.
 * @param util_v_lista_asignatura Utildel vector de asignaturas.
 * @param notaMediaMinima Nota media mínima requerida para incluir al alumno en el ordenamiento.
 * @pre util_v_lista_estudiante > 0, util_v_lista_matricula > 0
 * @post se habrá ordenado la lista de estudiantes por su nota media, excluyendo a aquellos cuya nota media sea inferior a la nota mínima especificada.
 * @version 2.5
 * @author Hanok
 */
void ordenarPorNotaMedia(Alumno v_lista_estudiante[], int util_v_lista_estudiante, Matricula v_lista_matricula[], int util_v_lista_matricula, Asignatura v_lista_asignatura[], int util_v_lista_asignatura, float notaMediaMinima);

/**
 * @brief Ordena la lista de estudiantes por la nota obtenida en una asignatura específica.
 * 
 * @param v_lista_estudiante vector de estudiantes.
 * @param util_v_lista_estudiante util del vector de estudiantes.
 * @param v_lista_matricula vector de matrículas.
 * @param util_v_lista_matricula util del vector de matrículas.
 * @param cod_asig Código de la asignatura por la cual ordenar.
 * @param v_alumno_aux vector auxiliar de estudiantes ordenados.
 * @param util_v_alumno_aux util del vector auxiliar de estudiantes ordenados.
 * @pre util_v_lista_estudiante > 0, util_v_lista_matricula > 0
 * @post se habrá ordenado la lista de estudiantes por la nota obtenida en una asignatura específica.
 * @version 2.5
 * @author Hanok
 */
void ordenarPorAsignatura(Alumno v_lista_estudiante[],  int util_v_lista_estudiante, Matricula v_lista_matricula[], int util_v_lista_matricula, char cod_asig[], Alumno v_alumno_aux[], int &util_v_alumno_aux );

/**
 * @brief Solicita al usuario un código de asignatura.
 * @param CodAsig Código de asignatura introducido por el usuario.
 * @post CodAsig contendrá el código de asignatura introducido por el usuario.
 * @version 2.5
 * @author Hanok
 */
void pedirCodAsig(char CodAsig[]);

/**
 * @brief Comprueba si el código de asignatura es igual al proporcionado.
 * @param v_lista_asignatura Lista de asignaturas.
 * @param util_v_lista_asignatura Número de asignaturas en la lista.
 * @param cod_asig Código de asignatura a comparar.
 * @return Devuelve true si el código de asignatura es igual, false en caso contrario.
 * @version 2.5
 * @author Hanok
 */
bool comprobarCodAsig(const Asignatura v_lista_asignatura[], const int util_v_lista_asignatura, const char cod_asig[]);

/**
 * @brief Pedir una nota media.
 * @return Devuelve una nota media.
 * @version 2.5
 * @author Hanok
 
 */
float pedirNotaMedia();

int main(){
    
    Alumno v_lista_estudiante[MAX_ALUMNOS];
    int util_v_lista_estudiante = 0;
    Asignatura v_lista_asignatura[MAX_ASIGNATURAS];
    int util_v_lista_asignatura = 0;
    Matricula v_lista_matricula[MAX_MATRICULAS];
    int util_v_lista_matricula = 0;

    int opcion;
    bool salir = false;

    inicializarDatosTesting(v_lista_estudiante, util_v_lista_estudiante, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);

    while(!salir){
        mostrarMenu();
        cin >> opcion;
        ejecutarMenu(opcion, v_lista_estudiante, util_v_lista_estudiante, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);
        if(opcion == 0){
            salir = true;
        }
    }

    
    //crearDatosBasicosSistema(v_lista_estudiante, util_v_lista_estudiante, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);
    
    
}

float buscarNotaAlumnoEnAsignatura(int idAlumno, const char cod_asig[], const Matricula v_lista_matricula[], int util_v_lista_matricula){
    float nota = 0.0;
    Alumno alumno;
    Asignatura asignatura;

    //Recorremos la lista de matriculas
    for(int i = 0; i < util_v_lista_matricula; i++){
        getAlumnoMatricula(v_lista_matricula[i], alumno);
        getAsignaturaMatricula(v_lista_matricula[i], asignatura);

        //Comprobamos si el alumno y la asignatura coinciden
        if(getIdAlumno(alumno) == idAlumno && comprobarSiCadenasSonIguales(cod_asig, asignatura.cod_asig, MAX_CARACTERES_COD_ASIG)){
            nota = getNotaMatricula(v_lista_matricula[i]);
        }
    }
    return nota;
}



bool comprobarCodAsig(const Asignatura v_lista_asignatura[], const int util_v_lista_asignatura, const char cod_asig[]){
    char codAsig[MAX_CARACTERES_COD_ASIG];
    bool resultado = false;
    for(int i = 0; (i < util_v_lista_asignatura); i++){
        getCodAsig(v_lista_asignatura[i], codAsig);
        cout << "Comparando código de asignatura: " << codAsig << endl;
        if(comprobarSiCadenasSonIguales(codAsig, cod_asig, MAX_CARACTERES_COD_ASIG)){
            resultado = true;
            
        }
    }
    return resultado;
}

void ordenarPorAsignatura(Alumno v_lista_estudiante[],  int util_v_lista_estudiante, Matricula v_lista_matricula[], int util_v_lista_matricula, char cod_asig[], Alumno v_alumno_aux[], int &util_v_alumno_aux){
    float v_notas[MAX_ALUMNOS];
    int util_v_notas = 0;
    int v_id_alumnos[MAX_ALUMNOS];
    int util_v_id_alumnos = 0;
    int pos_min = 0;
    int aux1 = 0;
    int aux2 = 0;
    int id_alumno = 0;

    for(int i = 0; i < util_v_lista_estudiante; i++){
        //Obtengo el id del alumno y lo guardo en orden en el vector auxiliar de id
        v_id_alumnos[util_v_id_alumnos] = getIdAlumno(v_lista_estudiante[i]);


        //Obtengo la nota del alumno y lo guardo en orden en el vector auxiliar de notas
        v_notas[util_v_notas] = buscarNotaAlumnoEnAsignatura(v_id_alumnos[util_v_id_alumnos], cod_asig, v_lista_matricula, util_v_lista_matricula);
        util_v_id_alumnos++;
        util_v_notas++;

    }

    //ordenar vector de notas y alumnos
    for(int i = 0; i < (util_v_notas -1); i++){

        pos_min = i;
        for(int j = i + 1; j < util_v_notas; j++){
            if(v_notas[j] < v_notas[pos_min]){
                pos_min = j;
            }
        }
        aux1 = v_notas[i];
        v_notas[i] = v_notas[pos_min];
        v_notas[pos_min] = aux1;

        aux2 = v_id_alumnos[i];
        v_id_alumnos[i] = v_id_alumnos[pos_min];
        v_id_alumnos[pos_min] = aux2;

    }

    util_v_alumno_aux = 0;
    for(int i = 0; i < util_v_id_alumnos; i++){
        for(int j = 0; j < util_v_lista_estudiante; j++){
            id_alumno = getIdAlumno(v_lista_estudiante[j]);
            if(v_id_alumnos[i] == id_alumno){
                insertarAlumnoEnVectorAlumno(v_alumno_aux, util_v_alumno_aux, v_lista_estudiante[j]);
            }
        }
    }



}

float pedirNotaMedia(){
    float nota;
    do{
        cout << "Ingrese una nota: ";
        cin >> nota;
    }while(nota < 0 || nota > 10);
    return nota;
}

float calcularMediaEstudiante(Matricula v_lista_matricula[], int util_v_lista_matricula, const Alumno &alumno){
    float suma = 0.0;
    int cantidad_asignaturas = 0;
    Alumno alumno_matricula;
    float media = 0.0;

    for(int i = 0; i < util_v_lista_matricula; i++){

        getAlumnoMatricula(v_lista_matricula[i], alumno_matricula);
        if(getIdAlumno(alumno) == getIdAlumno(alumno_matricula)){
            suma += getNotaMatricula(v_lista_matricula[i]);
            cantidad_asignaturas++;
        }
    }

    media = suma / cantidad_asignaturas;

    if(cantidad_asignaturas > 0){
        return media;
        
    } else{
        media = 0;
        return media;
    }
}

void ordenarPorNotaMedia(Alumno v_lista_estudiante[], int util_v_lista_estudiante, Matricula v_lista_matricula[], int util_v_lista_matricula, Asignatura v_lista_asignatura[], int util_v_lista_asignatura, float notaMediaMinima){
    Alumno estudianteFiltrado[MAX_ALUMNOS];
    int util_v_estudianteFiltrado = 0;
    float media = 0.0;

    for(int i = 0; i < util_v_lista_estudiante; i++){
        media = calcularMediaEstudiante(v_lista_matricula, util_v_lista_matricula, v_lista_estudiante[i]);
        if(media >= notaMediaMinima){
            estudianteFiltrado[util_v_estudianteFiltrado] = v_lista_estudiante[i];
            util_v_estudianteFiltrado++;
        }
    }
    imprimirTabla(estudianteFiltrado, util_v_estudianteFiltrado, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);
}

void eliminarUsuario(Alumno v_lista_estudiante[], int &util_v_lista_estudiante, Matricula v_lista_matricula[], int &util_v_lista_matricula){
    int id_alumno;
    cout << "Introduce el ID del alumno que quieres eliminar: ";
    cin >> id_alumno;
    
    for(int i = 0; i < util_v_lista_estudiante; i++){
        if(getIdAlumno(v_lista_estudiante[i]) == id_alumno){
            for(int j = i; j < util_v_lista_estudiante - 1; j++){
                asignarAlumno(v_lista_estudiante[j], v_lista_estudiante[j + 1]);
            }
            util_v_lista_estudiante--;
        }
    }
    
    eliminarCalificaciones(id_alumno, v_lista_matricula, util_v_lista_matricula);
    
    cout << "Usuario eliminado correctamente." << endl;

}

void eliminarCalificaciones(int id_alumno, Matricula v_lista_matricula[], int &util_v_lista_matricula) {
    for (int i = 0; i < util_v_lista_matricula; i++) {
        Alumno alumno;
        getAlumnoMatricula(v_lista_matricula[i], alumno);
        if (getIdAlumno(alumno) == id_alumno) {
            // Sobrescribe la calificación a eliminar con la última calificación
            v_lista_matricula[i] = v_lista_matricula[util_v_lista_matricula - 1];
            // Reduce el tamaño del vector
            util_v_lista_matricula--;
            // Decrementa i para volver a comprobar la calificación movida
            i--;
        }
    }
}
void insertarNuevoEstudiante(Alumno v_lista_estudiante[], int &util_v_lista_estudiante, Asignatura v_lista_asignatura[], int &util_v_lista_asignatura, Matricula v_lista_matricula[], int &util_v_lista_matricula){
    Alumno nuevoAlumno;
    Matricula nuevaMatricula;
    char nom_asig[MAX_CARACTERES_NOMBRE_ASIG];
    float nota;

    introducirDatosAlumno(nuevoAlumno, v_lista_estudiante, util_v_lista_estudiante);
    
    // Insertar el nuevo alumno en el vector de alumnos
    insertarAlumnoEnVectorAlumno(v_lista_estudiante, util_v_lista_estudiante, nuevoAlumno);
    
    // Iterar sobre todas las asignaturas y crear una matrícula para cada una
    for (int i = 0; i < util_v_lista_asignatura; i++) {

        setAlumnoMatricula(nuevaMatricula, nuevoAlumno);
        setAsignaturaMatricula(nuevaMatricula, v_lista_asignatura[i]);
        

        getNombreAsig(v_lista_asignatura[i], nom_asig);
        cout << "Introduce la nota para la asignatura " << nom_asig << ": ";
        cin >> nota;
        
        while (nota < 0 || nota > 10) {
            cout << "Nota inválida. Introduce una nota entre 0 y 10: ";
            cin >> nota;
        }
        
        setNotaMatricula(nuevaMatricula, nota);
        
        // Insertar la nueva matrícula en el vector de matrículas
        insertarMatriculaEnVectorMatricula(v_lista_matricula, util_v_lista_matricula, nuevaMatricula);

    }
    
    cout << "Estudiante insertado correctamente." << endl;
    
}

void cambiarNota( Matricula v_lista_matricula[], int util_v_lista_matricula){
    char cod_asig[MAX_CARACTERES_COD_ASIG];
    float nuevaNota;
    int id_alum;
    Asignatura asignatura;
    char cod_asig_matricula[MAX_CARACTERES_COD_ASIG];

    cout << "Introduce el código del alumno: ";
    cin >> id_alum;
    cout << "Introduce el código de la asignatura: ";
    cin >> cod_asig;
    cout << "Introduce la nueva nota: ";
    cin >> nuevaNota;

    for(int i = 0; i < util_v_lista_matricula; i++){
        Alumno alumno;
        getAlumnoMatricula(v_lista_matricula[i], alumno); // Obtener el alumno asociado a la matrícula
        if(getIdAlumno(alumno) == id_alum){
            getAsignaturaMatricula(v_lista_matricula[i], asignatura);
            getCodAsig(asignatura, cod_asig_matricula);
            if(comprobarSiCadenasSonIguales(cod_asig, cod_asig_matricula, MAX_CARACTERES_COD_ASIG)){
                setNotaMatricula(v_lista_matricula[i], nuevaNota);
            }
        }
    }
}


void mostrarMenu(){
    cout << "---------MENÚ--------" << endl;
    cout << "1. Cargar datos básicos..." << endl;
    cout << "2. Imprimir tabla..." << endl;
    cout << "3. Cambiar nota..." << endl;
    cout << "4. Insertar un nuevo estudiante..." << endl;
    cout << "5. Eliminar usuario..." << endl;
    cout << "6. Ordenar por nota media..." << endl;
    cout << "7. Ordenar por asignatura..." << endl;
    cout << "0. Salir..." << endl;
    cout << "Ingrese una opción: ";
}

void ejecutarMenu(int opcion,  Alumno v_lista_estudiante[], int &util_v_lista_estudiante,  Asignatura v_lista_asignatura[], int &util_v_lista_asignatura,  Matricula v_lista_matricula[], int &util_v_lista_matricula){
    float media = 0.0;
    char cod_asig[MAX_CARACTERES_COD_ASIG];
    Alumno v_alumno_aux[MAX_ALUMNOS];
    int util_v_alumno_aux = 0;
 
    switch(opcion){
        case 1:
            cout << "Datos cargados satisfactoriamente..." << endl;
            break;
        case 2:
            imprimirTabla(v_lista_estudiante, util_v_lista_estudiante, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);
            break;
            
        case 3:
            cambiarNota(v_lista_matricula, util_v_lista_matricula);
            imprimirTabla(v_lista_estudiante, util_v_lista_estudiante, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);
            break;
            
        case 4:
            insertarNuevoEstudiante(v_lista_estudiante, util_v_lista_estudiante, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);
            imprimirTabla(v_lista_estudiante, util_v_lista_estudiante, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);
            
            break;
            
        case 5:
            eliminarUsuario(v_lista_estudiante, util_v_lista_estudiante, v_lista_matricula, util_v_lista_matricula);
            imprimirTabla(v_lista_estudiante, util_v_lista_estudiante, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);

            break;
            
        case 6:

            media = pedirNotaMedia();
            ordenarPorNotaMedia(v_lista_estudiante, util_v_lista_estudiante, v_lista_matricula, util_v_lista_matricula, v_lista_asignatura, util_v_lista_asignatura, media);

            break;
            
        case 7:
            cin.ignore();  
            cout << "Ingrese el código de la asignatura: ";
            cin.getline(cod_asig, MAX_CARACTERES_COD_ASIG);

            cout << "Código de asignatura ingresado: " << cod_asig << endl;

            if(comprobarCodAsig(v_lista_asignatura, util_v_lista_asignatura, cod_asig)){
                ordenarPorAsignatura(v_lista_estudiante, util_v_lista_estudiante, v_lista_matricula, util_v_lista_matricula, cod_asig, v_alumno_aux, util_v_alumno_aux);
                imprimirTabla(v_alumno_aux, util_v_alumno_aux, v_lista_asignatura, util_v_lista_asignatura, v_lista_matricula, util_v_lista_matricula);
            } else{
                cout << "El código de la asignatura no es válido." << endl;
              }
            
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
    }
}

void printIdAlumno(int idAlumno){
    cout << idAlumno << "\t\t";
}

void printAsignaturas(const Asignatura v_lista_asignatura[], int util_v_lista_asignatura){
    char cod_asig[MAX_CARACTERES_COD_ASIG];
    for(int i = 0; i < util_v_lista_asignatura; i++){
        getCodAsig(v_lista_asignatura[i], cod_asig);
        imprimirCadenaCaracteres(cod_asig, MAX_CARACTERES_COD_ASIG);
        cout << "\t";
    }

}
void printNotas(const Matricula v_lista_matricula[], int util_v_lista_matricula, int idAlumno){
    float v_notas[MAX_ASIGNATURAS] = {0};
    int util_v_notas = 0;
    buscarNotasAlumno(v_lista_matricula, util_v_lista_matricula, v_notas, util_v_notas, idAlumno);
    for(int i = 0; i < util_v_notas; i++){
        cout << v_notas[i] << "\t";
    }
}

void buscarNotasAlumno(const Matricula v_lista_matricula[], int util_v_lista_matricula, float notas[], int &util_v_notas, int idAlumno){
    util_v_notas = 0;

    for(int i = 0; i < util_v_lista_matricula; i++){
        Matricula matricula;
        matricula = v_lista_matricula[i];
        Alumno alumno;
        Asignatura asignatura;

        getAlumnoMatricula(matricula, alumno);
        getAsignaturaMatricula(matricula, asignatura);

        if(getIdAlumno(alumno) == idAlumno){

            float nota = getNotaMatricula(matricula);
                notas[util_v_notas] = nota;
                util_v_notas++;
            }
        
    }

}


void inicializarDatosTesting(Alumno v_lista_estudiante[], int &util_v_lista_estudiante, Asignatura v_lista_asignatura[], int &util_v_lista_asignatura, Matricula v_lista_matricula[], int &util_v_lista_matricula){
    
    Alumno alumno0;
    Alumno alumno1;
    Alumno alumno2;
    char v_nombre_0[MAX_CARACTERES_NOM_ALUMNO] = "Juan";
    char v_nombre_1[MAX_CARACTERES_NOM_ALUMNO] = "Pedro";
    char v_nombre_2[MAX_CARACTERES_NOM_ALUMNO] = "Maria";   
    char v_apellido1_0[MAX_CARACTERES_APE_ALUMNO] = "Garcia";
    char v_apellido1_1[MAX_CARACTERES_APE_ALUMNO] = "Lopez";
    char v_apellido1_2[MAX_CARACTERES_APE_ALUMNO] = "Martinez";
    char v_apellido2_0[MAX_CARACTERES_APE_ALUMNO] = "Perez";
    char v_apellido2_1[MAX_CARACTERES_APE_ALUMNO] = "Gomez";
    char v_apellido2_2[MAX_CARACTERES_APE_ALUMNO] = "Sanchez";
    Fecha fechaNacimiento_0, fechaNacimiento_1, fechaNacimiento_2;
    setFecha(fechaNacimiento_0, 1, 1, 1990);
    setFecha(fechaNacimiento_1, 2, 2, 1991);
    setFecha(fechaNacimiento_2, 3, 3, 1992);

    util_v_lista_estudiante = 0;
    setIdAlumno(alumno0, 0);
    setNombreAlumno(alumno0, v_nombre_0);
    setApellido1Alumno(alumno0, v_apellido1_0);
    setApellido2Alumno(alumno0, v_apellido2_0);
    setFechaNacimientoAlumno(alumno0, fechaNacimiento_0);
    insertarAlumnoEnVectorAlumno(v_lista_estudiante, util_v_lista_estudiante, alumno0);

    setIdAlumno(alumno1, 1);
    setNombreAlumno(alumno1, v_nombre_1);
    setApellido1Alumno(alumno1, v_apellido1_1);
    setApellido2Alumno(alumno1, v_apellido2_1);
    setFechaNacimientoAlumno(alumno1, fechaNacimiento_1);
    insertarAlumnoEnVectorAlumno(v_lista_estudiante, util_v_lista_estudiante, alumno1);

    setIdAlumno(alumno2, 2);
    setNombreAlumno(alumno2, v_nombre_2);
    setApellido1Alumno(alumno2, v_apellido1_2);
    setApellido2Alumno(alumno2, v_apellido2_2);
    setFechaNacimientoAlumno(alumno2, fechaNacimiento_2);
    insertarAlumnoEnVectorAlumno(v_lista_estudiante, util_v_lista_estudiante, alumno2);

    Asignatura asignatura0;
    Asignatura asignatura1;
    Asignatura asignatura2;
    Asignatura asignatura3;
    Asignatura asignatura4;
    Asignatura asignatura5;


    char v_cod_asig_0[MAX_CARACTERES_COD_ASIG] = "PROG";
    char v_cod_asig_1[MAX_CARACTERES_COD_ASIG] = "BD";
    char v_cod_asig_2[MAX_CARACTERES_COD_ASIG] = "ED";
    char v_cod_asig_3[MAX_CARACTERES_COD_ASIG] = "LM";
    char v_cod_asig_4[MAX_CARACTERES_COD_ASIG] = "SI";
    char v_cod_asig_5[MAX_CARACTERES_COD_ASIG] = "FOL";

    char v_nombreAsig_0[MAX_CARACTERES_NOMBRE_ASIG] = "Programacion";
    char v_nombreAsig_1[MAX_CARACTERES_NOMBRE_ASIG] = "Base de Datos";
    char v_nombreAsig_2[MAX_CARACTERES_NOMBRE_ASIG] = "Entornos de Desarrollo";
    char v_nombreAsig_3[MAX_CARACTERES_NOMBRE_ASIG] = "Lenguaje de Marcas";
    char v_nombreAsig_4[MAX_CARACTERES_NOMBRE_ASIG] = "Sistemas Informaticos";
    char v_nombreAsig_5[MAX_CARACTERES_NOMBRE_ASIG] = "Formacion y Orientacion Laboral";

    util_v_lista_asignatura = 0;
    setAsignatura(asignatura0, v_cod_asig_0, v_nombreAsig_0);
    insertarAsignaturaEnVectorAsignatura(v_lista_asignatura, util_v_lista_asignatura, asignatura0);
    
    setAsignatura(asignatura1, v_cod_asig_1, v_nombreAsig_1);
    insertarAsignaturaEnVectorAsignatura(v_lista_asignatura, util_v_lista_asignatura, asignatura1);
    
    setAsignatura(asignatura2, v_cod_asig_2, v_nombreAsig_2);
    insertarAsignaturaEnVectorAsignatura(v_lista_asignatura, util_v_lista_asignatura, asignatura2);
    
    setAsignatura(asignatura3, v_cod_asig_3, v_nombreAsig_3);
    insertarAsignaturaEnVectorAsignatura(v_lista_asignatura, util_v_lista_asignatura, asignatura3);
    
    setAsignatura(asignatura4, v_cod_asig_4, v_nombreAsig_4);
    insertarAsignaturaEnVectorAsignatura(v_lista_asignatura, util_v_lista_asignatura, asignatura4);
    
    setAsignatura(asignatura5, v_cod_asig_5, v_nombreAsig_5);
    insertarAsignaturaEnVectorAsignatura(v_lista_asignatura, util_v_lista_asignatura, asignatura5);

    util_v_lista_matricula = 0;
    float v_notas[MAX_MATRICULAS] = {5.0, 6.15, 4.0, 3.75, 7.85, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 6.15, 4.0, 3.75, 7.85, 10.0};


    ////////EJEMPLO DE MATRICULA
    /*
    IDALUMNO    PROG    BD    ED    LM    SI    FOL    MEDIA ALUMNO
    0           5.0     6.15  4.0   3.75  7.85  10.0   6.125
    1           0.0     0.0   0.0   0.0   0.0   0.0    0
    2           5.0     6.15  4.0   3.75  7.85  10.0   6.125

    Media 
    Asignatura   3.33    4.1   2.67  2.5   5.27  6.67

    Alumnos
    Matriculados 3

    */

    for(int i = 0; i < util_v_lista_estudiante; i++){
        for(int j = 0; j < util_v_lista_asignatura; j++ ){
            setMatricula(v_lista_matricula[util_v_lista_matricula], v_notas[i * util_v_lista_asignatura + j], v_lista_estudiante[i], v_lista_asignatura[j]);
            insertarMatriculaEnVectorMatricula(v_lista_matricula, util_v_lista_matricula, v_lista_matricula[util_v_lista_matricula]);
        }
    }



}

float calcularMedia(const float notas[], int util_v_notas){
    float suma = 0;
    float media = 0;
    for(int i = 0; i < util_v_notas; i++){
        suma += notas[i];
    }

    media = suma / util_v_notas;
    return media;
}



void crearDatosBasicosSistema(Alumno v_lista_estudiante[], int util_v_lista_estudiante, Asignatura v_lista_asignatura[], int util_v_lista_asignatura, Matricula v_lista_matricula[], int util_v_lista_matricula){
    
    Alumno alumno;
    introducirDatosAlumno(alumno, v_lista_estudiante, util_v_lista_estudiante);

    insertarAlumnoEnVectorAlumno(v_lista_estudiante, util_v_lista_estudiante, alumno);



    for(int i = 0; i < MAX_ASIGNATURAS; i++){
        introducirDatosAsignatura(v_lista_asignatura[i]);
        insertarAsignaturaEnVectorAsignatura(v_lista_asignatura, util_v_lista_asignatura, v_lista_asignatura[i]);
    }

    Matricula matricula;

    for(int i = 0; i <= 18; i++){
       
        introducirDatosMatricula(matricula, v_lista_estudiante, util_v_lista_estudiante);
        insertarMatriculaEnVectorMatricula(v_lista_matricula, util_v_lista_matricula, v_lista_matricula[i]);

    }
    insertarMatriculaEnVectorMatricula(v_lista_matricula, util_v_lista_matricula, matricula);

}

void insertarAlumnoEnVectorAlumno(Alumno v_lista_estudiante[], int &util_v_lista_estudiante, const Alumno &alumno){


    asignarAlumno(v_lista_estudiante[util_v_lista_estudiante], alumno);
    util_v_lista_estudiante++;
    
}

void insertarAsignaturaEnVectorAsignatura(Asignatura v_lista_asignatura[], int &util_v_lista_asignatura, const Asignatura &asignatura){

    asignarAsignatura(v_lista_asignatura[util_v_lista_asignatura], asignatura);
    util_v_lista_asignatura++;
}

void insertarMatriculaEnVectorMatricula(Matricula v_lista_matricula[], int &util_v_lista_matricula, const Matricula &matricula){

    asignarMatricula(v_lista_matricula[util_v_lista_matricula], matricula);
    util_v_lista_matricula++;
}

void imprimirTabla(const Alumno v_lista_estudiante[], int &util_v_lista_estudiante,  Asignatura v_lista_asignatura[], int &util_v_lista_asignatura, Matricula v_lista_matricula[], int &util_v_lista_matricula){
    
    float v_notas_alumno[MAX_ASIGNATURAS];
    int util_v_notas = 0;
    float media_alumno = 0.0;

    float media_asignatura = 0.0;
    char cod_asig[MAX_CARACTERES_COD_ASIG];


    cout << "----------------------------CALIFICACIONES----------------------------" << endl;

    cout << "IDALUMNO\t";


    printAsignaturas(v_lista_asignatura, util_v_lista_asignatura);
    cout << "MEDIA ALUMNO";
    cout << endl;

    for(int i = 0; i < util_v_lista_estudiante; i++){
        printIdAlumno(getIdAlumno(v_lista_estudiante[i]));
        printNotas(v_lista_matricula, util_v_lista_matricula, getIdAlumno(v_lista_estudiante[i]));
        buscarNotasAlumno(v_lista_matricula, util_v_lista_matricula, v_notas_alumno, util_v_notas, getIdAlumno(v_lista_estudiante[i]));
        media_alumno = calcularMedia(v_notas_alumno, util_v_notas);
        cout << media_alumno << endl;
        cout << endl;
        
    }

    cout << "------------------------------------------------------------------------" << endl;


    cout << "MEDIA\nASIGNATURA\t";

    for (int i = 0; i < util_v_lista_asignatura; i++) {
        getCodAsig(v_lista_asignatura[i], cod_asig);
        
        media_asignatura = calcularMediaAsignatura(v_lista_estudiante, util_v_lista_estudiante, v_lista_matricula, util_v_lista_matricula, cod_asig);
        cout << media_asignatura << "\t";
    }

    cout << endl;

    cout << "Alumnos Matriculados: " << util_v_lista_estudiante << endl;
        

}

float calcularMediaAsignatura(const Alumno v_lista_estudiante[], int util_v_lista_estudiante, Matricula v_lista_matricula[], int util_v_lista_matricula, const char cod_asig[]) {
    int id_aux = 0;
    float acumulador = 0;
    float media = 0.0;
    
    for(int i = 0; i < util_v_lista_estudiante; i++){
        id_aux = getIdAlumno(v_lista_estudiante[i]);
        acumulador = acumulador + buscarNotaAlumnoEnAsignatura(id_aux, cod_asig, v_lista_matricula, util_v_lista_matricula);

    }
    media = acumulador / util_v_lista_estudiante;
    return media;

}

void buscarNotasAsignatura(Matricula v_lista_matricula[], int util_v_lista_matricula, float v_notas[], int& util_v_notas) {
    // Inicializar el contador de notas
    util_v_notas = 0;
    char cod_asig_matricula[MAX_CARACTERES_COD_ASIG];
    char cod_asig[MAX_CARACTERES_COD_ASIG];
    float nota;

    for (int i = 0; i < util_v_lista_matricula; ++i) {

        Asignatura asignaturaMatricula;
        getAsignaturaMatricula(v_lista_matricula[i], asignaturaMatricula);

        // Comparar si la asignatura de la matrícula actual es igual a la asignatura proporcionada
        if (comprobarSiCadenasSonIguales(cod_asig_matricula, cod_asig, MAX_CARACTERES_COD_ASIG)) {
            // Obtener la nota de la matrícula actual
            nota = getNotaMatricula(v_lista_matricula[i]);
            v_notas[util_v_notas] = nota;

            ++util_v_notas;
        }
    }
}

void buscarMatriculasPorAsignatura(const char codigoAsignatura[], const Matricula v_lista_matricula[], int util_v_lista_matricula, Matricula matriculasAsignatura[], int& util_v_matriculasAsignatura) {
    util_v_matriculasAsignatura = 0;
    for (int i = 0; i < util_v_lista_matricula; ++i) {
        Asignatura asignaturaMatricula;
        getAsignaturaMatricula(v_lista_matricula[i], asignaturaMatricula);
        char codAsig[MAX_CARACTERES_COD_ASIG];
        getCodAsig(asignaturaMatricula, codAsig);
        if (comprobarSiCadenasSonIguales(codAsig, codigoAsignatura, MAX_CARACTERES_COD_ASIG)) {
            matriculasAsignatura[util_v_matriculasAsignatura++] = v_lista_matricula[i];
        }
    }
}
bool comprobarSiCadenasSonIguales(const char cadena1[], const char cadena2[], const int DIMENSION) {
    bool resultado = true;
    for(int i = 0; (i < DIMENSION) && (cadena1[i] != '\0') && (cadena2[i] != '\0'); i++) {
        if (cadena1[i] != cadena2[i]) {
            resultado = false;
        }
    }
    return resultado;
}

void asignarAlumno(Alumno &a, const Alumno &b){
    int id = 0;
    char nombre[MAX_CARACTERES_NOM_ALUMNO];
    char apellido1[MAX_CARACTERES_APE_ALUMNO];
    char apellido2[MAX_CARACTERES_APE_ALUMNO];
    Fecha fechaNacimiento;

    id = getIdAlumno(b);
    getNombreAlumno(b, nombre);
    getApellido1Alumno(b, apellido1);
    getApellido2Alumno(b, apellido2);
    getFechaNacimientoAlumno(b, fechaNacimiento);

    setAlumno(a, id, nombre, apellido1, apellido2, fechaNacimiento);
}

void asignarAsignatura(Asignatura &a, const Asignatura &b){
    char cod_asig[MAX_CARACTERES_COD_ASIG];
    char nombreAsig[MAX_CARACTERES_NOMBRE_ASIG];

    getCodAsig(b, cod_asig);
    getNombreAsig(b, nombreAsig);

    setAsignatura(a, cod_asig, nombreAsig);
}

void asignarMatricula(Matricula &a, const Matricula &b){
    float nota = 0.0;
    Alumno alumno;
    Asignatura asignatura;
    
    nota = getNotaMatricula(b);
    getAlumnoMatricula(b, alumno);
    getAsignaturaMatricula(b, asignatura);

    setMatricula(a, nota, alumno, asignatura);

}

void copiarCadenaCaracteres(const char origen[], char destino[], int MAX_CARACTERES){
    int i = 0;
    for(i = 0; (origen[i]!= '\0') && (i < MAX_CARACTERES); i++){
        destino[i] = origen[i];
    }
    destino[i] = '\0';
}

////////////FECHA
void setDiaFecha(Fecha &f, int dia){
    f.dia = dia;

}

void setMesFecha(Fecha &f, int mes){
    f.mes = mes;

}

void setAnoFecha(Fecha &f, int ano){
    f.ano = ano;

}

void setFecha(Fecha &f, int dia, int mes, int ano){
    setDiaFecha(f, dia);
    setMesFecha(f, mes);
    setAnoFecha(f, ano);
}

int getDiaFecha(const Fecha &f){
    return f.dia;

}

int getMesFecha(const Fecha &f){
    return f.mes;

}

int getAnoFecha(const Fecha &f){
    return f.ano;

}

void printFecha(const Fecha &f){
    cout << getDiaFecha(f) << "/" << getMesFecha(f) << "/" << getAnoFecha(f) << endl;
}

//////// ALUMNO
void setIdAlumno(Alumno &a, int id){
    a.id = id;

}

void setNombreAlumno(Alumno &a,const char nombre[]){
    copiarCadenaCaracteres(nombre, a.nombre, MAX_CARACTERES_NOM_ALUMNO);

}

void setApellido1Alumno(Alumno &a,const char apellido1[]){
    copiarCadenaCaracteres(apellido1, a.apellido1, MAX_CARACTERES_APE_ALUMNO);

}

void setApellido2Alumno(Alumno &a,const char apellido2[]){
    copiarCadenaCaracteres(apellido2, a.apellido2, MAX_CARACTERES_APE_ALUMNO);

}

void setFechaNacimientoAlumno(Alumno &a, const Fecha &f){
    setFecha(a.fechaNacimiento, getDiaFecha(f), getMesFecha(f), getAnoFecha(f));
}

void setAlumno(Alumno &a, int id, char nombre[], char apellido1[], char apellido2[], const Fecha &fechaNacimiento){
    setIdAlumno(a, id);
    setNombreAlumno(a, nombre);
    setApellido1Alumno(a, apellido1);
    setApellido2Alumno(a, apellido2);
    setFechaNacimientoAlumno(a, fechaNacimiento);
}

int getIdAlumno(const Alumno &a){
    return a.id;
}

void getNombreAlumno(const Alumno &a, char nombre[]){
    copiarCadenaCaracteres(a.nombre, nombre, MAX_CARACTERES_NOM_ALUMNO);
}

void getApellido1Alumno(const Alumno &a, char apellido1[]){
    copiarCadenaCaracteres(a.apellido1, apellido1, MAX_CARACTERES_APE_ALUMNO);

}

void getApellido2Alumno(const Alumno &a, char apellido2[]){
    copiarCadenaCaracteres(a.apellido2, apellido2, MAX_CARACTERES_APE_ALUMNO);

}


void getFechaNacimientoAlumno(const Alumno &a, Fecha &fechaNacimiento){
    setDiaFecha(fechaNacimiento, getDiaFecha(a.fechaNacimiento)); 
    setMesFecha(fechaNacimiento, getMesFecha(a.fechaNacimiento)); 
    setAnoFecha(fechaNacimiento, getAnoFecha(a.fechaNacimiento));
}

//////////ASIGNATURA
void setCodAsig(Asignatura &a, const char cod_asig[]){
    copiarCadenaCaracteres(cod_asig, a.cod_asig, MAX_CARACTERES_COD_ASIG);
}

void setNombreAsig(Asignatura &a, const char nombreAsig[]){
    copiarCadenaCaracteres(nombreAsig, a.nombreAsig, MAX_CARACTERES_NOMBRE_ASIG);
}

void getCodAsig(const Asignatura &a, char cod_asig[]){
    copiarCadenaCaracteres(a.cod_asig, cod_asig, MAX_CARACTERES_COD_ASIG);
}

void getNombreAsig(const Asignatura &a, char nombreAsig[]){
    copiarCadenaCaracteres(a.nombreAsig, nombreAsig, MAX_CARACTERES_NOMBRE_ASIG);
}

void setAsignatura(Asignatura &a, char cod_asig[], char nombreAsig[]){
    setCodAsig(a, cod_asig);
    setNombreAsig(a, nombreAsig);
}
void introducirDatosAsignatura(Asignatura &a){
    char cod_asig[MAX_CARACTERES_COD_ASIG];
    char nombreAsig[MAX_CARACTERES_NOMBRE_ASIG];

    cin.ignore();
    cout << "Introduce el codigo de la asignatura: ";
    cin.getline(cod_asig, MAX_CARACTERES_COD_ASIG);

    cout << "Introduce el nombre de la asignatura: ";
    cin.getline(nombreAsig, MAX_CARACTERES_NOMBRE_ASIG);

    setAsignatura(a, cod_asig, nombreAsig);
}
void printAsignatura(const Asignatura &a){
    cout << " codigo de asignatura: ";
    imprimirCadenaCaracteres(a.cod_asig, MAX_CARACTERES_COD_ASIG);
    cout << endl;
    cout << "Nombre de la asignatura: ";
    imprimirCadenaCaracteres(a.nombreAsig, MAX_CARACTERES_NOM_ALUMNO);
    cout << endl;

}

//////////MATRICULA
void setAlumnoMatricula(Matricula &m, const Alumno &a){


    asignarAlumno(m.alumno, a); 

}

void setAsignaturaMatricula(Matricula &m, const Asignatura &a){
    asignarAsignatura(m.asignatura, a);
}

void setNotaMatricula(Matricula &m, float nota){
    m.nota = nota;
}

void getAlumnoMatricula(const Matricula &m, Alumno &a){

    asignarAlumno(a, m.alumno);

}

void getAsignaturaMatricula(const Matricula &m, Asignatura &a){
   asignarAsignatura(a, m.asignatura);
}

float getNotaMatricula(const Matricula &m){
    return m.nota;
}


void introducirDatosMatricula(Matricula &m, Alumno v_lista_estudiante[], int util_v_lista_estudiante){
    float nota;
    Asignatura asignatura_matricula;
    Alumno alumno_matricula;

    do{
        cout << "Introduce la nota del alumno: ";
        cin >> nota;
        if(nota < 0){
            cout << "La nota no puede ser negativa..." << endl;
        } else if(nota > 10){
            cout << "La nota no puede ser superior a 10..." << endl;
        }
    } while((nota < 0) || (nota > 10));


    introducirDatosAlumno(alumno_matricula, v_lista_estudiante, util_v_lista_estudiante);
    introducirDatosAsignatura(asignatura_matricula);

    setMatricula(m, nota, alumno_matricula, asignatura_matricula);



}

void setMatricula(Matricula &m, float nota, const Alumno &alumno, const Asignatura &asignatura ){

    setNotaMatricula(m, nota);
    setAlumnoMatricula(m, alumno);
    setAsignaturaMatricula(m, asignatura);
}

void printMatricula(const Matricula &m){
    cout << "Nota: " << getNotaMatricula(m) << endl;
    cout << "Alumno: " << endl;
    printAlumno(m.alumno);
    cout << "Asignatura: " << endl;
    printAsignatura(m.asignatura);

}

void imprimirCadenaCaracteres(const char cadena[], int MAX_CARACTERES){
    for(int i = 0; (cadena[i]!= '\0') && (i < MAX_CARACTERES); i++){
        cout << cadena[i];
    }

}

void printAlumno(const Alumno &a){
    cout << "ID: " << getIdAlumno(a) << endl;
    cout << "Nombre: ";
    imprimirCadenaCaracteres(a.nombre, MAX_CARACTERES_NOM_ALUMNO);
    cout << "\nApellido1: ";
    imprimirCadenaCaracteres(a.apellido1, MAX_CARACTERES_APE_ALUMNO);
    cout << "\nApellido2: ";
    imprimirCadenaCaracteres(a.apellido2, MAX_CARACTERES_APE_ALUMNO);
    cout << endl;
    cout << "Fecha de Nacimiento: ";
    printFecha(a.fechaNacimiento);
}

void introducirDatosAlumno(Alumno &a, Alumno v_lista_estudiante[], int util_v_lista_estudiante){
    int id;
    bool id_valido = false;
    char v_nombre_alumno[MAX_CARACTERES_NOM_ALUMNO];
    char v_apellido1_alumno[MAX_CARACTERES_APE_ALUMNO];
    char v_apellido2_alumno[MAX_CARACTERES_APE_ALUMNO];
    int dia;
    int mes;
    int ano;
    Fecha FechaNacimientoAlumno;
    
    do{
        cout << "Introduce el ID del alumno: ";
        cin >> id;
        id_valido = true;
        for(int i = 0; i < util_v_lista_estudiante; i++){
            if(id == getIdAlumno(v_lista_estudiante[i])){
                cout << "El ID ya existe, introduzca otro ID" << endl;
                id_valido = false;
            }
        }
    } while(!id_valido);

    cin.ignore();
    cout << "Introduce el nombre del alumno: ";
    cin.getline(v_nombre_alumno, MAX_CARACTERES_NOM_ALUMNO);



    cout << "Introduce el apellido1 del alumno: ";
    cin.getline(v_apellido1_alumno, MAX_CARACTERES_APE_ALUMNO);


    cout << "Introduce el apellido2 del alumno: ";
    cin.getline(v_apellido2_alumno, MAX_CARACTERES_APE_ALUMNO);



    cout << "Introduce la fecha de nacimiento: " << endl;
    do{
        cout << "Introduce el dia: ";
        cin >> dia;
        if(dia <= 0){
            cout << "El dia debe ser mayor a 0" << endl;
        }else if(dia > 31){
            cout << "El dia no puede ser mayor a 31" << endl;
        }

    } while((dia <= 0) || (dia > 31));
    
    cout << "Introduce el mes: ";
    do{
        cin >> mes;
        if(mes <= 0){
            cout << "El mes debe ser mayor a 0" << endl;
        }else if(mes > 12){
            cout << "El mes no puede ser mayor a 12" << endl;
        }
    }while((mes <= 0) || (mes > 12));

    cout << "Introduce el año: ";
    do{
        cin >> ano;
        if(ano <= 0){
            cout << "El año debe ser mayor a 0" << endl;
        }else if(ano > 10000){
            cout << "El año no puede ser mayor a 10000" << endl;
        }
    }while((ano <= 0) || (ano > 10000));

    setFecha(FechaNacimientoAlumno, dia, mes, ano);
    setAlumno(a, id, v_nombre_alumno, v_apellido1_alumno, v_apellido2_alumno, FechaNacimientoAlumno);
        
        
}
