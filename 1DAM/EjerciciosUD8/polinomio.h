#include <iostream>
#include <iomanip>
using namespace std;


class Polinomio{
    private:
        //Atributos
        float* coef; //vector de coeficientes del polinomio
        int grado_actual; //grado actual que tiene el polinomio
        int grado_max; //coincide con la DIM del VECTOR DE COEFICIENTES - 1
        //Polinomio* this = con la dirección de memoria del Polinomio que invoca al constructor
        //esto se declara automáticamente, no hace falta que lo declaréis vosotros...

    public:
        //Métodos
        /**
         * @brief Constructor del objeto Polinomio: reserva por defecto un vector de coeficientes de dimensión 10, de
         * tal manera que el máximo grado permitido será 9. Todos los coeficientes tendrán como valor 0.0. Y el grado_actual
         * será por lo tanto 0.
         * @post El objeto Polinomio estará construido con la memoria del vector reservada y los valores por defecto.
         */
        Polinomio();

        /**
         * @brief Constructor del objeto Polinomio que crea una copia exacta de un objeto Polinomio
         * 
         * @param otro Polinomio que se quiere copiar
         * @pre otro es un objeto Polinomio ya construido
         * @post El objeto Polinomio estará construido con la memoria del vector reservada y los valores por defecto
         */
        Polinomio(const Polinomio& otro);

        /**
         * @brief Destructor del objeto Polinomio.
         * @post La memoria asignada al objeto Polinomio es liberada correctamente.
         */
        ~Polinomio();

        /**
         * @brief Obtiene el grado actual del objeto polinomio
         * 
         * @return El grado actual del polinomio.
         */
        int getGrado() const;

        /**
         * @brief Obtiene el grado máximo del objeto polinomio
         * 
         * @return El grado máximo del polinomio.
         */
        int getMaxGrado() const;

        /**
         * @brief Establece el grado del polinomio a un nuevo valor
         * 
         * @param nuevo_grado Nuevo grado que se le quiere asignar al polinomio
         * @pre nuevo_grado debe ser un valor entero positivo y menor o igual que el grado máximo permitido
         * @post El grado del polinomio será igual a nuevo_grado
         */
        void setGrado(int nuevo_grado);

        /**
         * @brief Establece el grado máximo del polinomio.
         * 
         * @param nuevo_max_grado Nuevo grado máximo que se quiere asignar al polinomio.
         * @pre nuevo_max_grado debe ser un valor entero positivo.
         * @post El grado máximo del polinomio será igual a nuevo_max_grado.
         */
        void setGradoMax(int nuevo_max_grado);

        /**
         * @brief Establece el coeficiente de un grado i del polinomio
         * 
         * @param i Grado del polinomio al que se le quiere asignar el coeficiente
         * @param coeficiente Valor del coeficiente que se le quiere asignar al grado i
         * @pre i debe ser un valor entero positivo
         * @post El coeficiente del grado i será igual a coeficiente
         */
        void setCoeficienteV3(int i, float coeficiente);

        /**
         * @brief Obtiene el coeficiente del término de grado i.
         * 
         * @param i Grado del polinomio del que se quiere obtener el coeficiente.
         * @return El coeficiente del término de grado i.
         */
        float getCoeficiente(int i) const;

        /**
         * @brief Redimensiona el polinomio para que pueda almacenar un grado máximo nuevo
         * 
         * @param nueva_dimension Nuevo grado máximo que se le quiere asignar al polinomio
         * @pre nueva_dimension debe ser un valor entero positivo
         * @post El polinomio tendrá un nuevo grado máximo igual a nueva_dimension
         */
        void resize(int nueva_dimension);

        /**
         * @brief Suma dos polinomios y almacena el resultado en el polinomio actual
         * 
         * @param p2 Puntero al polinomio que se quiere sumar al polinomio actual
         * @pre El objeto actual y p2 son objetos Polinomio ya construidos
         * @post El polinomio actual contendrá la suma de los polinomios Polinomio actual y p2
         * @return Un puntero al polinomio que contiene la suma de los polinomios Polinomio actual y p2
         */
        Polinomio* sumaV3(const Polinomio *p2);

        /**
         * @brief Imprime por pantalla el polinomio.
         * @post Se ha impreso el polinomio actual por pantalla.
         */
        void print();

        /**
         * @brief Sobrecarga del operador de asignación.
         * 
         * @param p Polinomio que se quiere asignar al polinomio actual.
         * @return Una referencia al polinomio actual.
         */
        Polinomio& operator=(const Polinomio &p);

        /**
         * @brief Sobrecarga del operador de suma.
         * 
         * @param p Polinomio que se quiere sumar al polinomio actual.
         * @return Un polinomio que contiene la suma de los polinomios Polinomio actual y p.
         */
        Polinomio operator+(const Polinomio &p) const;

        /**
         * @brief Función amiga que sobrecarga el operador de inserción <<
         * 
         * @param flujo Flujo de salida en el que se quiere imprimir el polinomio.
         * @param p Polinomio que se quiere imprimir.
         * @return El flujo de salida actualizado.
         */
        friend ostream& operator<<(ostream& flujo, const Polinomio& p);

        friend istream& operator>>(std::istream& flujo, const Polinomio &p);

        /**
         * @brief Reinicia el polinomio, estableciendo todos los coeficientes a cero y el grado a cero.
         * 
         * @param p Polinomio que se quiere reiniciar.
         */
        void resetPolinomio(Polinomio &p);

};