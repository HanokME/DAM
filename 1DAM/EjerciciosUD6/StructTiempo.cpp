#include <iostream>
using namespace std;

struct Tiempo{
    int horas;
    int minutos;
    int segundos;
};

/**
 * @brief Establece la hora en la variable de tipo tiempo.
 * @param t hace referencia a la variable de tipo tiempo a la que se le quiere introducir la hora
 * @param horas variable que contiene la hora que se quiere establecer
 * @pre horas debe ser >= 0 && <= 12.
 * @post las horas de t, seran actualizadas según el valor proporcionado
 * @version 1.0
 * @author Hanok
*/
void setHorasTiempo(Tiempo &t, int horas);

/**
 * @brief Establece los minutos en la variable de tipo tiempo.
 * @param t hace referencia a la variable de tipo tiempo a la que se le quieren introducir los minutos
 * @param minutos variable que contiene los minutos que se quieren establecer
 * @pre minutos debe ser >= 0 && <= 59.
 * @post los minutos de t, seran actualizados según el valor proporcionado
 * @version 1.0
 * @author Hanok
*/
void setMinutosTiempo(Tiempo &t, int minutos);

/**
 * @brief Establece los segundos en la variable de tipo tiempo.
 * @param t hace referencia a la variable de tipo tiempo a la que se le quieren introducir los segundos
 * @param segundos variable que contiene los segundos que se quieren establecer
 * @pre segundos debe ser >= 0 && <= 59.
 * @post los segundos de t, seran actualizados según el valor proporcionado
 * @version 1.0
 * @author Hanok
*/
void setSegundosTiempo(Tiempo &t, int segundos);


/**
 * @brief Obtiene la hora almacenada en la variable de tipo tiempo
 * @param t hace referencia a la variable de tipo tiempo de la que se obtendrá la hora
 * @return la hora almacenada en la variable de tipo tiempo
 * @post se ha obtenido la hora almacenada correctamente en la variable de tipo tiempo
 * @version 1.0
 * @author Hanok
*/
int getHorasTiempo(const Tiempo &t);

/**
 * @brief Obtiene los minutos almacenados en la variable de tipo tiempo
 * @param t hace referencia a la variable de tipo tiempo de la que se obtendran los minutos
 * @return los minutos almacenados en la variable de tipo tiempo
 * @post se han obtenido los minutos almacenados correctamente en la variable de tipo tiempo
 * @version 1.0
 * @author Hanok
*/
int getMinutosTiempo(const Tiempo &t);

/**
 * @brief Obtiene los segundos almacenados en la variable de tipo tiempo
 * @param t hace referencia a la variable de tipo tiempo de la que se obtendrán los segundos
 * @return los segundos almacenados en la variable de tipo tiempo
 * @post se han obtenido los segundos almacenados correctamente en la variable de tipo tiempo
 * @version 1.0
 * @author Hanok
*/
int getSegundosTiempo(const Tiempo &t);


/**
 * @brief Establece todos los miembros de tiempo en la estructura Tiempo.
 * @param t hace referencia a la variable de tipo tiempo de la que se obtendran todos los miembros de tiempo
 * @param horas variable que contiene la hora que se quiere establecer
 * @param minutos variable que contiene los minutos que se quieren establecer
 * @param segundos variable que contiene los segundos que se quieren establecer
 * @pre horas debe ser un valor válido (>= 0 y <= 12).
 * @pre minutos debe ser un valor válido (>= 0 y <= 59).
 * @pre segundos debe ser un valor válido (>= 0 y <= 59).
 * @pre am debe ser un valor booleano válido.
 * @post Los componentes de tiempo de la estructura Tiempo serán actualizadas según los valores proporcionados.
 * @version 1.0
 * @author Hanok
*/
void setTiempo(Tiempo &t, int horas, int minutos, int segundos);

/**
 * @brief Imprime todos los valores almacenados en la estructura tiempo de cada uno de sus miembros en formato (HH:MM:SS AM/PM)
 * @param t hace referencia a la variable de tipo tiempo de la que se van a obtener todos los valores a imprimir
 * @post todos los valores almacenados en la estructura tiempo serán sacados por pantalla es un formato determinado
 * @version 1.0
 * @author Hanok
*/
void printTiempo(const Tiempo &t);

/**
 * @brief Solicita al usuario que introduzca los valores queridos en cada uno de los miembros de la estructura tiempo
 * @param t hace referencia a la variable de tipo t en la que se van a almacenar los valores de cada miembro
 * @post todos los valores introducidos se almacenarán en la estructura tiempo y en un correcto formato (horas(0-12), minutos(0-59), segundos(0-59) y AM/PM)
 * @version 1.0
 * @author Hanok
*/
void pedirTiempo(Tiempo &t);

/**
 * @brief Calcula la diferencia de tiempo entre dos variables tiempo diferentes
 * @param t hace referencia a la variable de tipo tiempo1 en la que se van a almacenar los valores de cada miembro.
 * @param t2 hace referencia a la variable de tipo tiempo2 en la que se van a almacenar los valores de cada miembro.
 * @return La diferencia de tiempo entre t y t2.
 * @pre .
 * @post se ha calculado correctamente la diferencia de tiempo entre t1 y t2.
 * @version 1.0
 * @author Hanok
 */
Tiempo diferenciaTiempo(const Tiempo &t, const Tiempo &t2);



int main (){
    Tiempo tiempo1, tiempo2, diferencia;

    cout << "Ingrese el primer tiempo: " << endl;
    pedirTiempo(tiempo1);
    cout << "Ingrese el segundo tiempo: " << endl;
    pedirTiempo(tiempo2);
    diferencia = diferenciaTiempo(tiempo1, tiempo2);
    cout << "La diferencia de tiempo es: " << endl;
    printTiempo(diferencia);

}


void setHorasTiempo(Tiempo &t, int horas){
    t.horas = horas;
}

void setMinutosTiempo(Tiempo &t, int minutos){
    t.minutos = minutos;
}

void setSegundosTiempo(Tiempo &t, int segundos){
    t.segundos = segundos;
}


int getHorasTiempo(const Tiempo &t){
    return t.horas;
}

int getMinutosTiempo(const Tiempo &t){
    return t.minutos;
}

int getSegundosTiempo(const Tiempo &t){
    return t.segundos;
}



void setTiempo(Tiempo &t, int horas, int minutos, int segundos){
    t.horas = horas;
    t.minutos = minutos;
    t.segundos = segundos;

}



void pedirTiempo(Tiempo &t){
    int horas, minutos, segundos;

    
    do{
        cout << "Ingrese la hora: ";
        cin >> horas;
    }while(horas < 0 || horas > 23);
    setHorasTiempo(t, horas);
    
    do{
        cout << "Ingrese el minuto: ";
        cin >> minutos;
    }while(minutos < 0 || minutos > 59);
    setMinutosTiempo(t, minutos);
    
    do{
        cout << "Ingrese el segundo: ";
        cin >> segundos;
    }while(segundos < 0 || segundos > 59);
    setSegundosTiempo(t, segundos);


    
}

void printTiempo(const Tiempo &t){
    cout << getHorasTiempo(t) << ":" << getMinutosTiempo(t) << ":" << getSegundosTiempo(t) << endl;

}

Tiempo diferenciaTiempo(const Tiempo &t1, const Tiempo &t2) {
    Tiempo diferencia;
    int totalSegundosT1 = 0;
    int totalSegundosT2 = 0;
    int diferenciaSegundos = 0;

    totalSegundosT1 = getHorasTiempo(t1) * 3600 + getMinutosTiempo(t1) * 60 + getSegundosTiempo(t1);

    totalSegundosT2 = getHorasTiempo(t2) * 3600 + getMinutosTiempo(t2) * 60 + getSegundosTiempo(t2);

    diferenciaSegundos = totalSegundosT2 - totalSegundosT1;

    // Manejo de la diferencia de segundos negativos (ocurre cuando t2 es anterior a t1)
    if (diferenciaSegundos < 0) {
        diferenciaSegundos += 24 * 3600; // Agrega un día en segundos (24 horas * 3600 segundos)
    }

    setHorasTiempo(diferencia, diferenciaSegundos / 3600);
    diferenciaSegundos %= 3600;
    setMinutosTiempo(diferencia, diferenciaSegundos / 60);
    diferenciaSegundos %= 60;
    setSegundosTiempo(diferencia, diferenciaSegundos);


    return diferencia;
}

