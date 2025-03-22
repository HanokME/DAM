#include <iostream>
#include <iomanip>
#include <string.h>
#include "usuario.h"
using namespace std;

class Valoracion{

    private:
        int idValoracion;
        Contenido* contenido;
        Usuario* usuario;
        float calificacion;
        Fecha fecha_valoracion;

        int segundosVisualizados;

    public:

        /**
         * @brief Constructor por defecto del objeto Valoracion
         * @post El objeto valoracion se ha creado
         * @version 1.0
         */
        Valoracion();

        /**
         * @brief Constructor por copia del objeto Valoracion
         * @param Valoracion v objeto en el que se va a crear el objeto valoracion por copia
         * @post El objeto valoracion se ha creados
         * @version 1.0
         */
        Valoracion(const Valoracion &v);


        /**
         * @brief Constructor por defecto del objeto Valoracion
         * @param idValoracion Id del objeto valoracion
         * @param contenido Contenido que se va a valorar
         * @param usuario Usuario que esta valorando en el contenido
         * @param calificacion Calificacion del contenido
         * @param fecha_valoracion Fecha en la que se realiza la valoracion
         * @post El objeto valoracion se ha creado
         * @version 1.0
         */
        Valoracion(int idValoracion, Contenido* contenido, Usuario* usuario, float calificacion, Fecha fecha_valoracion, int segundosVisualizados);

        /**
         * @brief Destructor del objeto valoracion
         * 
         * @post El objeto valoracion se ha destruido
         * @version 1.0
         */
        ~Valoracion();

        /**
         * @brief Establece el id de la valoracion
         * @param idValoracion Entero en el que se establece el id
         * @post Se ha establecido el id de la valoracion
         * @version 1.0
         */
        void set_id_valoracion(int idValoracion);

        int get_id_valoracion()const;

        /**
         * @brief Establece en la valoracion el contenido a valorar
         * @param Contenido contenido puntero al contenido al que se le establece la valoracion
         * @post Se ha establecido el contenido en la valoracion
         * @version 1.0
         */
        void set_contenido(Contenido* contenido);

        Contenido* get_contenido()const;

        /**
         * @brief Establece en la valoracion el usuario que va a valorar
         * @param Usuario usuario puntero al usuario que va a establecer la valoracion
         * @post Se ha establecido el usuario en la valoracion
         * @version 1.0
         */
        void set_usuario(Usuario* usuario);

        Usuario* get_usuario()const;

        /**
         * @brief Establece la calificacion de la valoracion
         * @param calificacion entero en el que se guarda la calificacion establecida
         * @post Se ha establecido la calificacion de la valoracion
         * @version 1.0
         */
        void set_calificacion(float calificacion);

        float get_calificacion()const;

        /**
         * @brief Establece la fecha de la valoracion
         * @param dia entero en el que se va a establecer el dia de valoracion
         * @param mes entero en el que se va a establecer el dia de valoracion
         * @param dia entero en el que se va a establecer el dia de valoracion
         * @post Se ha establecido el id de la valoracion
         * @version 1.0
         */
        Fecha set_fecha_valoracion(int dia, int mes, int anio);

        Fecha get_fecha_valoracion()const;

        /**
         * @brief Establece el id de la valoracion
         * @param idValoracion Entero en el que se establece el id
         * @post Se ha establecido el id de la valoracion
         * @version 1.0
         */
        void setSegundosVisualizados(int segundosVisualizados);

        int getSegundosVisualizados()const;

        /**
         * @brief Establece el id de la valoracion
         * @param idValoracion Entero en el que se establece el id
         * @post Se ha establecido el id de la valoracion
         * @version 1.0
         */
        void set_valoracion(int idValoracion, Contenido* contenido, Usuario* usuario, float calificacion, Fecha fecha_valoracion, int segundosVisualizados);

        Valoracion& operator=(const Valoracion &v);

        friend ostream& operator<<(ostream &flujo, const Valoracion &v);


        Contenido* getContenido()const;


        


};