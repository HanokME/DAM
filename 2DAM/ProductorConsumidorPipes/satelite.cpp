#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <vector>
#include <cstdlib>

using namespace std;
pid_t pid_nieto, pid_hijo;


// Manejadores de señales
void manejador_hijo(int sig) {
    cout << "Padre: Recibí la señal del Hijo (SIGUSR1)." << endl;
}

void manejador_padre(int sig) {
    cout << "Hijo: Recibí la señal del Nieto (SIGUSR2)." << endl;
}

void manejador_nieto(int sig) {
    cout << "Nieto: Recibí la señal del Padre (SIGUSR1)." << endl;
}

int main() {
    int pipe_n_h[2], pipe_h_p[2], pipe_pid[2];

    if (pipe(pipe_n_h) == -1 || pipe(pipe_h_p) == -1 || pipe(pipe_pid) == -1) {
        cerr << "Error al crear los pipes." << endl;
        exit(1);
    }

    pid_hijo = fork();


    if (pid_hijo < 0) {
        cerr << "Error al crear el Proceso Hijo." << endl;
        exit(1);
    }

    if (pid_hijo == 0) {
        // Proceso Hijo
        pid_nieto = fork();

        if (pid_nieto < 0) {
            cerr << "Error al crear el Proceso Nieto." << endl;
            exit(1);
        }

        if (pid_nieto == 0) {
            // Proceso Nieto
            cout << "Nieto: Proceso iniciado." << endl;
            close(pipe_n_h[0]);
            close(pipe_h_p[0]);
            close(pipe_h_p[1]);
            close(pipe_pid[0]);
            close(pipe_pid[1]);

            signal(SIGUSR1, manejador_nieto);

            while (true) {
                pause(); // Esperar señal del Padre
                cout << "Nieto: Iniciando captura de datos." << endl;

                vector<int> paquete;
                int num;
                bool fin_paquete = false;

                cout << "Nieto: Ingrese una lista de números enteros positivos (-1 para terminar):" << endl;
                while (!fin_paquete) {
                    cin >> num;
                    write(pipe_n_h[1], &num, sizeof(num));
                    fin_paquete = (num == -1);
                }

                cout << "Nieto: Paquete enviado al Hijo." << endl;
                kill(getppid(), SIGUSR2); // Señal al Hijo los datos estan listos
            }

            close(pipe_n_h[1]);
            exit(0);
        } else {
            // Proceso Hijo
            cout << "Hijo: Proceso iniciado." << endl;
            close(pipe_n_h[1]); // Cerrar escritura
            close(pipe_h_p[0]); // Cerrar lectura
            close(pipe_pid[0]); // Cerrar lectura

            // Enviar PID del Nieto al Padre
            write(pipe_pid[1], &pid_nieto, sizeof(pid_nieto));
            close(pipe_pid[1]); // Cerrar escritura

            signal(SIGUSR2, manejador_hijo);

            while (true) {
                pause(); // Esperar señal del Nieto
                cout << "Hijo: Procesando datos del Nieto." << endl;

                vector<int> paquete;
                int num;
                bool fin_paquete = false;
                bool valido = true;

                while (!fin_paquete && read(pipe_n_h[0], &num, sizeof(num)) > 0) {
                    if (num == -1) {
                        fin_paquete = true;
                    } else {
                        paquete.push_back(num);
                        if (num < 0) {
                            valido = false;
                        }
                    }
                }

                cout << "Hijo: Datos procesados, enviando resultado al Padre." << endl;

                //Enviar datos al padre
                for (int n : paquete) {
                    write(pipe_h_p[1], &n, sizeof(n));
                }
                num = -1;
                write(pipe_h_p[1], &num, sizeof(num));//Fin de paquete
                write(pipe_h_p[1], &valido, sizeof(valido));//Enviar validez
                kill(getppid(), SIGUSR1); // Señal al Padre
            }

            close(pipe_n_h[0]);
            close(pipe_h_p[1]);
            exit(0);
        }
    } else {
        // Proceso Padre
        cout << "Padre: Proceso iniciado." << endl;
        close(pipe_n_h[0]); // Cerrar lectura
        close(pipe_n_h[1]); // Cerrar escritura
        close(pipe_h_p[1]); // Cerrar escritura
        close(pipe_pid[1]); // Cerrar escritura 

        // Leer el PID del Nieto
        read(pipe_pid[0], &pid_nieto, sizeof(pid_nieto));
        close(pipe_pid[0]); // Cerrar lectura 
        cout << "Padre: Recibido PID del Nieto: " << pid_nieto << endl;

        signal(SIGUSR1, manejador_padre);

        while (true) {
            cout << "Padre: Enviando señal al Nieto (PID: " << pid_nieto << ")." << endl;
            kill(pid_nieto, SIGUSR1); // Señal al Nieto para iniciar la captura de datos
            pause(); // Esperar señal del Hijo

            cout << "Padre: Recibiendo datos del Hijo." << endl;
            vector<int> paquete;
            int num;
            bool valido;
            bool fin_paquete = false;

            cout << "Padre: Números recibidos: ";
            while (!fin_paquete && read(pipe_h_p[0], &num, sizeof(num)) > 0) {
                if (num == -1) {
                    fin_paquete = true;
                } else {
                    paquete.push_back(num);
                    if (num < 0) {
                        cout << "\033[1;31m" << num << " \033[0m"; // Números negativos en rojo
                    } else {
                        cout << "\033[1;32m" << num << " \033[0m"; // Números válidos en verde
                    }
                }
            }

            read(pipe_h_p[0], &valido, sizeof(valido));

            if (valido) {
                cout << "\033[1;32mPaquete válido:\033[0m ";
                int suma = 0;
                for (int n : paquete) {
                    suma += n;
                }
                cout << "\033[1;32mSuma: " << suma << "\033[0m\n";
            } else {
                cout << "\033[1;31mPaquete inválido.\033[0m ";
                
                cout << "\033[1;31m\nNo se realiza la suma.\033[0m\n";
            }
            cout << "\n---- Nuevo paquete ----\n";
        }

        close(pipe_h_p[0]);
        wait(NULL);
        wait(NULL);
    }

    return 0;
}
