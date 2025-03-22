#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

using namespace std;

/**
 * @brief Programa que utiliza cerrojos y variables condición para resolver el problema del productor consumidor, con un buffer circular
 * @author @HanokMartin
 * @version 2.0
 * @date 08/01/2025
 */

int *buffer; //Buffer dinámico
int buffer_size;
int in = 0; //Inserción
int out = 0; //Extracción

pthread_mutex_t buffer_mutex; //Cerrojo
pthread_cond_t buffer_vacio; //Condicion de control cuando no esta lleno
pthread_cond_t buffer_lleno; //Condicion de control cuando no esta vacio

bool terminan_prod = false;
bool terminan_cons = false;

/**
 * @brief Imprime por terminal el estado actual del buffer
 * @post Muestra el contenido de cada posición(1 si está lleno) y (0 si está vacio)
 * @version 2.0
 * @author @HanokMartin
 * @date 08/01/2025
 */
void imprimir_buffer(){
    printf("Estado del buffer: [ ");
    for(int i = 0; i < buffer_size; i++){
        if (buffer[i] == 1) {
            printf("\033[32m%d\033[0m ", buffer[i]); // Verde para 1
        } else {
            printf("\033[31m%d\033[0m ", buffer[i]); // Rojo para 0
        }
    }
    printf("]\n");
}

/**
 * @brief Función que se ejecuta por las hebras productoras, produciendo un elemento en una posición libre del buffer
 * @param arg Puntero al identificador único de la hebra productora
 * @return NULL
 * @version 2.0
 * @author @HanokMartin
 * @date 08/01/2025
 */
void *productor(void *arg){
    int id = *(int *)arg;//identificador de la hebra
    bool continuar = true;
    while(continuar){
        
        pthread_mutex_lock(&buffer_mutex); //Bloquear mutex

        while(((in +1)% buffer_size) == out && !terminan_prod){
            pthread_cond_wait(&buffer_vacio, &buffer_mutex);
        }

        //Verificar si termina
        if(terminan_prod && ((in + 1)% buffer_size) == out){
            continuar = false;
        } else{
            buffer[in] = 1; 
            printf("\033[32mHebraProductora(%d) produce en la posición %d\033[0m\n", id, in);
            in = (in + 1) % buffer_size; //actualiza la posicion circular
            imprimir_buffer();

            pthread_cond_signal(&buffer_lleno);
        }

        pthread_mutex_unlock(&buffer_mutex);
        sleep(1);
    }
    return NULL;

}

/**
 * @brief Función que se ejecuta por las hebras consumidoras, extrayendo un elemento en una posición "llena" del buffer
 * @param arg Puntero al identificador de una hebra consumidora
 * @return NULL
 * @version 2.0
 * @author @HanokMartin
 * @date 08/01/2025
 */
void *consumidor(void *arg){
    int id = *(int *)arg; //identificador de la hebra
    bool continuar = true;
    while(continuar){
        
        pthread_mutex_lock(&buffer_mutex); //Bloquear mutex

        while(in == out && !terminan_cons){
            pthread_cond_wait(&buffer_lleno, &buffer_mutex);
        }

        //Verificar si termina
        if(terminan_cons && in == out){
            continuar = false;
        } else{
            buffer[out] = 0;
            printf("\033[31mHebraConsumidora(%d) consume en la posición %d\033[0m\n", id, out);
            out = (out + 1) % buffer_size; //actualiza la posicion circular
            imprimir_buffer();

            pthread_cond_signal(&buffer_vacio);
        }

        pthread_mutex_unlock(&buffer_mutex);
        sleep(2);
    }
    return NULL;
}

/**
 * @brief Función principal del programa. Inicializa los semáforos, crea las hebras y gestiona la sincronización
 * @param argc Numero de argumentos de linea de comandos
 * @param argv Valores de los argumentos
 * @return 0 si finaliza correctamente
 */
int main(int argc, char *argv[]){
    //Lectura de los parámetros de entrada
    buffer_size = atoi(argv[1]);
    int num_productoras = atoi(argv[2]);//
    terminan_prod = (strcmp(argv[3], "true") == 0);//stringcompare
    int num_consumidoras = atoi(argv[4]);
    terminan_cons = (strcmp(argv[5], "true") == 0);

    //Reserva de memoria dinamica para el buffer
    buffer = new int[buffer_size];
    for(int i = 0; i < buffer_size; i++){
        buffer[i] = 0;
    }

    //Inicializar mutex y variables condicion
    pthread_mutex_init(&buffer_mutex, NULL);
    pthread_cond_init(&buffer_vacio, NULL);
    pthread_cond_init(&buffer_lleno, NULL);


    //HEBRAS    
    pthread_t productoras[num_productoras];
    pthread_t consumidoras[num_consumidoras];

    int id_productoras[num_productoras];
    int id_consumidoras[num_consumidoras];

    

    //Hebras productoras
    for(int i = 0; i < num_productoras; i++){
        id_productoras[i] = i + 1;
        pthread_create(&productoras[i], NULL, productor, &id_productoras[i]);
    }

    //Hebras consumidoras
    for(int i = 0; i < num_consumidoras; i++){
        id_consumidoras[i] = i + 1;
        pthread_create(&consumidoras[i], NULL, consumidor, &id_consumidoras[i]);
    }

    //Esperar a que las hebras terminen
    for(int i = 0; i < num_productoras; i++){
        pthread_join(productoras[i], NULL);
    }
    for(int i = 0; i < num_consumidoras; i++){
        pthread_join(consumidoras[i], NULL);
    }

    //Semáforos
    delete[] buffer;
    
    pthread_mutex_destroy(&buffer_mutex);
    pthread_cond_destroy(&buffer_lleno);
    pthread_cond_destroy(&buffer_vacio);

    return 0;
}