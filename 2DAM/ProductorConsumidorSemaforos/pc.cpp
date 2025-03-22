#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

using namespace std;

int *buffer; // Buffer dinámico
int buffer_size;
int in = 0; // Inserción
int out = 0; // Extracción

sem_t mutex; // Exclusión mutua
sem_t sem_productor; // Control de posiciones libres
sem_t sem_consumidor; // Control de elementos disponibles

bool terminan_prod = false;
bool terminan_cons = false;

// Imprime por terminal el estado actual del buffer
void imprimir_buffer() {
    printf("Estado del buffer: [ ");
    for (int i = 0; i < buffer_size; i++) {
        printf("%d ", buffer[i]);
    }
    printf("]\n");
}

// Función que se ejecuta por las hebras productoras
void *productor(void *arg) {
    int id = *(int *)arg; // Identificador de la hebra
    bool continuar = true;
    while (continuar) {
        int item = 1;

        sem_wait(&sem_productor); // Decrementa el número de posiciones libres
        sem_wait(&mutex); // Entrada a la sección crítica

        buffer[in] = item; // Simulación de la producción
        printf("HebraProductora(%d) produce en la posición %d\n", id, in);
        in = (in + 1) % buffer_size; // Actualiza la posición circular
        imprimir_buffer();

        sem_post(&mutex); // Libera la sección crítica
        sem_post(&sem_consumidor); // Incrementa el número de elementos disponibles

        if (terminan_prod) {
            continuar = false;
        }

        sleep(1); // Simula tiempo de producción
    }
    return NULL;
}

// Función que se ejecuta por las hebras consumidoras
void *consumidor(void *arg) {
    int id = *(int *)arg; // Identificador de la hebra
    bool continuar = true;
    while (continuar) {
        sem_wait(&sem_consumidor); // Decrementa el número de elementos disponibles
        sem_wait(&mutex); // Entrada a la sección crítica

        int item = buffer[out];
        buffer[out] = 0; // Consumir el elemento y marcar como vacío
        printf("HebraConsumidora(%d) consume en posición %d\n", id, out);
        out = (out + 1) % buffer_size;
        imprimir_buffer();

        sem_post(&mutex); // Libera la sección crítica
        sem_post(&sem_productor); // Incrementa el número de posiciones libres

        if (terminan_cons) {
            continuar = false;
        }
        sleep(2); // Simula tiempo de consumo
    }
    return NULL;
}

// Función principal del programa
int main(int argc, char *argv[]) {
    // Lectura de los parámetros de entrada
    buffer_size = atoi(argv[1]);
    int num_productoras = atoi(argv[2]);
    terminan_prod = (strcmp(argv[3], "true") == 0);
    int num_consumidoras = atoi(argv[4]);
    terminan_cons = (strcmp(argv[5], "true") == 0);

    // Reserva de memoria dinámica para el buffer
    buffer = new int[buffer_size];

    // Inicializar los semáforos
    sem_init(&mutex, 0, 1);
    sem_init(&sem_productor, 0, buffer_size); // Inicia con el tamaño total del buffer
    sem_init(&sem_consumidor, 0, 0); // Comienza sin elementos disponibles

    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 0; // Inicializar el buffer a ceros
    }

    // Crear hebras
    pthread_t productoras[num_productoras];
    pthread_t consumidoras[num_consumidoras];

    int id_productoras[num_productoras];
    int id_consumidoras[num_consumidoras];

    // Hebras productoras
    for (int i = 0; i < num_productoras; i++) {
        id_productoras[i] = i + 1;
        pthread_create(&productoras[i], NULL, productor, &id_productoras[i]);
    }

    // Hebras consumidoras
    for (int i = 0; i < num_consumidoras; i++) {
        id_consumidoras[i] = i + 1;
        pthread_create(&consumidoras[i], NULL, consumidor, &id_consumidoras[i]);
    }

    // Esperar a que las hebras terminen
    for (int i = 0; i < num_productoras; i++) {
        pthread_join(productoras[i], NULL);
    }
    for (int i = 0; i < num_consumidoras; i++) {
        pthread_join(consumidoras[i], NULL);
    }

    // Liberar recursos
    delete[] buffer;
    sem_destroy(&mutex);
    sem_destroy(&sem_productor);
    sem_destroy(&sem_consumidor);

    return 0;
}