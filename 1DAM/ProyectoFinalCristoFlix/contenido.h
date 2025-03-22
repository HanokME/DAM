#include <iostream>
#include <iomanip>
#include <string.h>
#include "fecha.h"
using namespace std;


class Contenido{

    protected:
        int id_contenido;
        string titulo;
        Fecha fechaLanzamiento;
        int duracion;
        string genero;
        float imdbRating;
        int imdbVotes;

        int timesPlayed;
        int timesLiked;
        int timesNotLiked;

        float cristoFlixRating;

        bool activo;


    public:
        /**
         * @brief Constructor por defecto de la clase Contenido
         * 
         */
        Contenido();

        /**
         * @brief Constructor de copia de la clase Contenido.
         * @param c Referencia constante al objeto Contenido que se va a copiar.
         */
        Contenido(const Contenido &c);

        /**
         * @brief Constructor de la clase Contenido.
         * @param id_contenido Identificador del contenido.
         * @param titulo Título del contenido.
         * @param fechalanzamiento Fecha de lanzamiento del contenido.
         * @param duracion Duración del contenido en minutos.
         * @param genero Género del contenido.
         * @param rating Calificación IMDb del contenido.
         * @param votes Votos IMDb del contenido.
         */
        Contenido(int id_contenido, string titulo, Fecha fechalanzamiento, int duracion, string genero, float rating, int votes, int timesliked, int timesnotliked, int timesplayed, bool activo);

        /**
         * @brief Establece el identificador del contenido.
         * @param id_contenido Nuevo identificador del contenido.
         */
        void setId_contenido(int id_contenido);

        /**
         * @brief Obtiene el identificador del contenido.
         * @return Identificador del contenido.
         */
        int getId_contenido() const;

        /**
         * @brief Establece el título del contenido.
         * @param titulo Nuevo título del contenido.
         */
        void setTitulo(string titulo);

        /**
         * @brief Obtiene el título del contenido.
         * @return Título del contenido.
         */
        string getTitulo()const;

        /**
         * @brief Establece la fecha de lanzamiento del contenido.
         * @param dia Día de la fecha de lanzamiento.
         * @param mes Mes de la fecha de lanzamiento.
         * @param anio Año de la fecha de lanzamiento.
         */
        void setFechaLanzamiento(int dia, int mes, int anio);

        /**
         * @brief Obtiene la fecha de lanzamiento del contenido.
         * @return Objeto Fecha que representa la fecha de lanzamiento del contenido.
         */
        Fecha getFechaLanzamiento()const;

        /**
         * @brief Establece la duración del contenido.
         * @param duracion Nueva duración del contenido en minutos.
         */
        void setDuracion(int duracion);

        /**
         * @brief Obtiene la duración del contenido.
         * @return Duración del contenido en minutos.
         */
        int getDuracion()const;

        /**
         * @brief Establece el género del contenido.
         * @param genero Nuevo género del contenido.
         */
        void setGenero(string genero);

        /**
         * @brief Obtiene el género del contenido.
         * @return Género del contenido.
         */
        string getGenero()const;

        /**
         * @brief Establece la calificación IMDb del contenido.
         * @param imdbRating Nueva calificación IMDb del contenido.
         */
        void setImdbRating(float imdbRating);

        /**
         * @brief Obtiene la calificación IMDb del contenido.
         * @return Calificación IMDb del contenido.
         */
        float getImdbRating()const;

        /**
         * @brief Establece el número de votos IMDb del contenido.
         * @param imdbVotes Número de votos IMDb del contenido.
         */
        void setImdbVotes(int imdbVotes);

        /**
         * @brief Obtiene el número de votos IMDb del contenido.
         * @return Número de votos IMDb del contenido.
         */
        int getImdbVotes()const;

        void setTimesPlayed(int timesplayed);
        int getTimesPlayed()const;

        void setTimesLiked(int timesliked);
        int getTimesLiked()const;

        void setTimesNotLiked(int timesnotliked);
        int getTimesNotLiked()const;

        void setCristoFlixRating(float cristoflixrating);
        float getCristoFlixRating()const;

        void setActivo(bool activo);
        bool getActivo()const;

        /**
         * @brief Establece la información del contenido.
         * @param id_contenido Identificador del contenido.
         * @param titulo Título del contenido.
         * @param fechaLanzamiento Fecha de lanzamiento del contenido.
         * @param duracion Duración del contenido en minutos.
         * @param genero Género del contenido
         * @param imdbRating Calificación IMDb del contenido.
         * @param imdbVotes Votos IMDb del contenido.
         */
        void setContenido(int id_contenido, string titulo, Fecha fechaLanzamiento, int duracion, string genero, float imdbRating, int imdbVotes, int timesLiked, int timesNotLiked, int timesPlayed, float cristoFlixRating, bool activo);

        /**
         * @brief Obtiene el número de votos IMDb del contenido.
         * @return Número de votos IMDb del contenido.
         */
        virtual void printContenido()const ;

        /**
         * @brief Sobrecarga del operador de inserción para imprimir la información del contenido.
         * @param flujo Flujo de salida donde se imprimirá la información.
         * @param contenido Objeto de tipo Contenido que se imprimirá.
         * @return Referencia al flujo de salida para permitir encadenamiento.
         */
        friend ostream& operator<<(ostream &flujo, const Contenido &contenido);

        /**
         * @brief Sobrecarga del operador de asignación para copiar un contenido.
         * @param contenido Objeto de tipo Contenido que se copiará.
         * @return Referencia al objeto de tipo Contenido.
         */
        Contenido& operator=(const Contenido &contenido);

        


};

class Serie : public Contenido{

    protected:
        int numeroCapitulos;

    public:

        /**
         * @brief Constructor por defecto de la clase Serie.
         * 
         */
        Serie() : Contenido(){
            this->numeroCapitulos = 0;
        }

        /**
         * @brief Constructor po parametros de la clase Serie.
         * @param id_contenido Identificador del contenido.
         * @param titulo Título del contenido.
         * @param fechaLanzamiento Fecha de lanzamiento del contenido.
         * @param duracion Duración del contenido en minutos.
         * @param genero Género del contenido.
         * @param imdbRating Calificación IMDb del contenido.
         * @param imdbVotes Votos IMDb del contenido.
         * @param numeroCapitulos Número de capítulos de la serie.
         */
        Serie(int id_contenido, string titulo, Fecha fechaLanzamiento, int duracion, string genero, float imdbRating, int imdbVotes, int numeroCapitulos, int timesLiked, int timesNotLiked, int timesPlayed, bool activo) : Contenido(id_contenido, titulo, fechaLanzamiento, duracion, genero, imdbRating, imdbVotes, timesLiked, timesNotLiked, timesPlayed, activo){
            this->numeroCapitulos = numeroCapitulos;
        }

        /**
         * @brief Establece el número de capítulos de la serie.
         * @param numeroCapitulos Nuevo número de capítulos de la serie.
         */
        inline void setNumeroCapitulos(int numeroCapitulos) {this->numeroCapitulos = numeroCapitulos;};

        /**
         * @brief Obtiene el número de capítulos de la serie.
         * @return Número de capítulos de la serie.
         */
        inline int getNumeroCapitulos() {return this->numeroCapitulos;};

        /**
         * @brief Imprime la información de la serie sobrecargando el método print contenido de la clase contenido
         * 
         */
        void printContenido()const;
        friend ostream& operator<<(ostream &flujo, const Serie &serie);
};

class Pelicula : public Contenido{
    protected:
        string director;
    public:

            /**
         * @brief Constructor por defecto de la clase Pelicula.
         * 
         */
        Pelicula() : Contenido(){
            this->director = "";
        }

        /**
         * @brief Constructor por parametros de la clase Pelicula.
         * @param id_contenido Identificador del contenido.
         * @param titulo Título del contenido.
         * @param fechaLanzamiento Fecha de lanzamiento del contenido.
         * @param duracion Duración del contenido en minutos.
         * @param genero Género del contenido.
         * @param imdbRating Calificación IMDb del contenido.
         * @param imdbVotes Votos IMDb del contenido.
         * @param director Director de la película.
         */
        Pelicula(int id_contenido, string titulo, Fecha fechaLanzamiento, int duracion, string genero, float imdbRating, int imdbVotes, string director, int timesLiked, int timesNotLiked, int timesPlayed, bool activo) : Contenido(id_contenido, titulo, fechaLanzamiento, duracion, genero, imdbRating, imdbVotes, timesLiked, timesNotLiked, timesPlayed, activo){
            this->director = director;
        }

        /**
         * @brief Establece el director de la película.
         * @param director Nuevo director de la película.
         */
        inline void setDirector(string director) {this->director = director;};

        /**
         * @brief Obtiene el director de la película.
         * @return Director de la película.
         */
        inline string getDirector() {return this->director;};

        /**
         * @brief Imprime la información de la película sobrecargando el método print contenido de la clase contenido
         * 
         */
        void printContenido()const;
        friend ostream& operator<<(ostream &flujo, const Pelicula &pelicula);
};

class Documental : public Contenido{
    protected:
        string tipo;
    public:

        /**
         * @brief Constructor por defecto de Documental
         * 
         */
        Documental() : Contenido(){
            this->tipo = "";
        }

        /**
         * @brief Constructor por parametros de la clase Documental.
         * @param id_contenido Identificador del contenido.
         * @param titulo Título del contenido.
         * @param fechaLanzamiento Fecha de lanzamiento del contenido.
         * @param duracion Duración del contenido en minutos.
         * @param genero Género del contenido.
         * @param imdbRating Calificación IMDb del contenido.
         * @param imdbVotes Votos IMDb del contenido.
         * @param tipo Tipo de documental.
         */
        Documental(int id_contenido, string titulo, Fecha fechaLanzamiento, int duracion, string genero, float imdbRating, int imdbVotes, string tipo, int timesLiked, int timesNotLiked, int timesPlayed, bool activo) : Contenido(id_contenido, titulo, fechaLanzamiento, duracion, genero, imdbRating, imdbVotes, timesLiked, timesNotLiked, timesPlayed, activo){
            this->tipo = tipo;
        }

        /**
         * @brief Establece el tipo de documental.
         * @param tipo Nuevo tipo de documental.
         */
        inline void setTipo(string tipo) {this->tipo = tipo;};

        /**
         * @brief Obtiene el tipo de documental.
         * @return Tipo de documental.
         */
        inline string getTipo() {return this->tipo;};

        /**
         * @brief Imprime la información del documental sobrecargando el método print contenido de la clase contenido
         * 
         */
        void printContenido()const;
        friend ostream& operator<<(ostream &flujo, const Documental &documental);
};