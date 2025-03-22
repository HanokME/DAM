#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include "contenido.h"
#include "colors.h"
using namespace std;

const bool DEBUG = false;

    Contenido::Contenido(){
        this->id_contenido = 0;
        this->titulo = "";
        this->fechaLanzamiento = Fecha();
        this->duracion = 0;
        this->genero = "";
        this->imdbRating = 0;
        this->imdbVotes = 0;
        this->timesLiked = 0;
        this->timesPlayed = 0;
        this->timesNotLiked = 0;
        this->activo = 0;

        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por defecto de Contenido" << RESET << endl;
        }
    }

    Contenido::Contenido(const Contenido &c){
        this->id_contenido = c.id_contenido;
        this->titulo = c.titulo;
        this->fechaLanzamiento = c.fechaLanzamiento;
        this->duracion = c.duracion;
        this->genero = c.genero;
        this->imdbRating = c.imdbRating;
        this->imdbVotes = c.imdbVotes;
        this->timesLiked = c.timesLiked;
        this->timesPlayed = c.timesPlayed;
        this->timesNotLiked = c.timesNotLiked;
        this->activo = c.activo;

        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por copia de Contenido" << RESET << endl;
        }
    }

    Contenido::Contenido(int id_contenido, string titulo, Fecha fechalanzamiento, int duracion, string genero, float rating, int votes, int timesliked, int timesnotliked, int timesplayed, bool activo){
        this->id_contenido = id_contenido;
        this->titulo = titulo;
        this->fechaLanzamiento = fechalanzamiento;
        this->duracion = duracion;
        this->genero = genero;
        this->imdbRating = rating;
        this->imdbVotes = votes;
        this->timesLiked = timesliked;
        this->timesPlayed = timesplayed;
        this->timesNotLiked = timesnotliked;
        this->activo = activo;

        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por parametros de Contenido" << RESET << endl;
        }
    }

    void Contenido::setId_contenido(int id_contenido){
        this->id_contenido = id_contenido;
    }

    int Contenido::getId_contenido()const{
        return id_contenido;
    }

    void Contenido::setTitulo(string titulo){
        this->titulo = titulo;
    }

    string Contenido::getTitulo()const{
        return titulo;
    }

    void Contenido::setFechaLanzamiento(int dia, int mes, int anio){
        fechaLanzamiento.setDia(dia);
        fechaLanzamiento.setMes(mes);
        fechaLanzamiento.setAnio(anio);
    }

    Fecha Contenido::getFechaLanzamiento()const{
        return fechaLanzamiento;
    }

    void Contenido::setDuracion(int duracion){
        this->duracion = duracion;
    }

    int Contenido::getDuracion()const{
        return duracion;
    }

    void Contenido::setGenero(string genero){
        this->genero = genero;
    }

    string Contenido::getGenero()const{
        return genero;
    }

    void Contenido::setImdbRating(float imdbRating){
        this->imdbRating = imdbRating;
    }

    float Contenido::getImdbRating()const{
        return imdbRating;
    }

    void Contenido::setImdbVotes(int imdbVotes){
        this->imdbVotes = imdbVotes;
    }

    int Contenido::getImdbVotes()const{
        return imdbVotes;
    }

    void Contenido::setTimesPlayed(int timesplayed){
        this->timesPlayed = timesplayed;
    }
    int Contenido::getTimesPlayed()const{
        return timesPlayed;
    }

    void Contenido::setTimesLiked(int timesliked){
        this->timesLiked = timesliked;
    }
    int Contenido::getTimesLiked()const{
        return timesLiked;
    }

    void Contenido::setTimesNotLiked(int timesnotliked){
        this->timesNotLiked = timesnotliked;
    }
    int Contenido::getTimesNotLiked()const{
        return timesNotLiked;
    }

    void Contenido::setCristoFlixRating(float cristoflixrating){
        this->cristoFlixRating = cristoflixrating;
    }
    float Contenido::getCristoFlixRating()const{
        return cristoFlixRating;
    }

    void Contenido::setActivo(bool activo){
        this->activo = activo;
    }
    bool Contenido::getActivo()const{
        return activo;
    }

    

    Contenido& Contenido::operator=(const Contenido &contenido){
        if(this != &contenido){ 
            this->id_contenido = contenido.id_contenido;
            this->titulo = contenido.titulo;
            this->fechaLanzamiento = contenido.fechaLanzamiento;
            this->duracion = contenido.duracion;
            this->genero = contenido.genero;
            this->imdbRating = contenido.imdbRating;
            this->imdbVotes = contenido.imdbVotes;
            this->timesLiked = contenido.timesLiked;
            this->timesNotLiked = contenido.timesNotLiked;
            this->timesPlayed = contenido.timesPlayed;
            this->activo = contenido.activo;
        }
        return *this;
    }

    void Contenido::setContenido(int id_contenido, string titulo, Fecha fechaLanzamiento, int duracion, string genero, float imdbRating, int imdbVotes, int timesLiked, int timesNotLiked, int timesPlayed, float cristoFlixRating, bool activo){
        do {
            if (id_contenido < 0) {
                cout << RED << "El ID de contenido no puede ser menor que 0" << RESET << endl;
            } else {
                this->id_contenido = id_contenido;
            }
        } while (id_contenido < 0);

        do {
            if (duracion < 1) {
                cout << RED << "La duración no puede ser menor que 1" << RESET << endl;
            } else {
                this->duracion = duracion;
            }
        } while (duracion < 1);

        do {
            if (imdbRating < 0 || imdbRating > 10) {
                cout << RED << "El rating de IMDB debe estar en el rango [0, 10]" << RESET << endl;
            } else {
                this->imdbRating = imdbRating;
            }
        } while (imdbRating < 0 || imdbRating > 10);


        do {
            if (imdbVotes < 0) {
                cout << RED << "El número de votos de IMDB no puede ser negativo" << RESET << endl;
            } else {
                this->imdbVotes = imdbVotes;
            }
        } while (imdbVotes < 0);
            
            this->titulo = titulo;
            this->fechaLanzamiento = fechaLanzamiento;
            this->genero = genero;
            this->timesLiked = timesLiked;
            this->timesNotLiked = timesNotLiked;
            this->timesPlayed = timesPlayed;
            this->cristoFlixRating = cristoFlixRating;
            this->activo = activo;
    }

    void Contenido::printContenido()const{
        cout << "| " << ORANGE << "ID: " << RESET << this->id_contenido << endl;
        cout << "| " << ORANGE << "Titulo: " << RESET << this->titulo << endl;
        cout << "| " << ORANGE << "Fecha de lanzamiento: " << RESET << this->fechaLanzamiento << endl;
        cout << "| " << ORANGE << "Duracion: " << RESET << this->duracion << endl;
        cout << "| " << ORANGE << "Genero: " << RESET << this->genero << endl;
        cout << "| " << ORANGE << "IMDB Rating: " << RESET << this->imdbRating << endl;
        cout << "| " << ORANGE << "IMDB Votes: " << RESET << this->imdbVotes << endl;
        cout << "| " << ORANGE << "Times Liked: " << RESET << this->timesLiked << endl;
        cout << "| " << ORANGE << "Times Not Liked: " << RESET << this->timesNotLiked << endl;
        cout << "| " << ORANGE << "Times Played: " << RESET << this->timesPlayed << endl;
        cout << "| " << ORANGE << "Cristo Flix Rating: " << RESET << this->cristoFlixRating << endl;
    }
    ostream& operator<<(ostream &flujo, const Contenido &contenido){
        flujo << "| " << ORANGE << "ID: " << RESET << contenido.getId_contenido() <<  endl;
        flujo << "| " << ORANGE << "Titulo: " << RESET << contenido.getTitulo() << endl;
        flujo << "| " << ORANGE << "Fecha de lanzamiento: " << RESET << contenido.getFechaLanzamiento() <<  endl;
        flujo << "| " << ORANGE << "Duracion: " << RESET << contenido.getDuracion() <<  endl;
        flujo << "| " << ORANGE << "Genero: " << RESET << contenido.getGenero() <<  endl;
        flujo << "| " << ORANGE << "IMDB Rating: " << RESET << contenido.getImdbRating() <<  endl;
        flujo << "| " << ORANGE << "IMDB Votes: " << RESET << contenido.getImdbVotes() <<  endl;
        flujo << "| " << ORANGE << "Times Liked: " << RESET << contenido.getTimesLiked() << endl;
        flujo << "| " << ORANGE << "Times Not Liked: " << RESET << contenido.getTimesNotLiked() << endl;
        flujo << "| " << ORANGE << "Times Played: " << RESET << contenido.getTimesPlayed() << endl;
        flujo << "| " << ORANGE << "Cristo Flix Rating: " << RESET << contenido.getCristoFlixRating() << endl;
        flujo << "| " << ORANGE << "Contenido activo: " << RESET << contenido.getActivo() << endl;
        return flujo;
    }

    void Serie::printContenido()const{
        this->printContenido();
        cout << "| " << ORANGE << "Episodios: " << RESET << this->numeroCapitulos <<  endl;
    }
    ostream& operator<<(ostream &flujo, const Serie &serie){
        flujo << "| " << ORANGE << "ID: " << RESET << serie.getId_contenido() <<  endl;
        flujo << "| " << ORANGE << "Titulo: " << RESET << serie.getTitulo() << endl;
        flujo << "| " << ORANGE << "Fecha de lanzamiento: " << RESET << serie.getFechaLanzamiento() <<  endl;
        flujo << "| " << ORANGE << "Duracion: " << RESET << serie.getDuracion() <<  endl;
        flujo << "| " << ORANGE << "Genero: " << RESET << serie.getGenero() <<  endl;
        flujo << "| " << ORANGE << "IMDB Rating: " << RESET << serie.getImdbRating() <<  endl;
        flujo << "| " << ORANGE << "IMDB Votes: " << RESET << serie.getImdbVotes() <<  endl;
        flujo << "| " << ORANGE << "Times Liked: " << RESET << serie.getTimesLiked() << endl;
        flujo << "| " << ORANGE << "Times Not Liked: " << RESET << serie.getTimesNotLiked() << endl;
        flujo << "| " << ORANGE << "Times Played: " << RESET << serie.getTimesPlayed() << endl;
        flujo << "| " << ORANGE << "Cristo Flix Rating: " << RESET << serie.getCristoFlixRating() << endl;
        flujo << "| " << ORANGE << "Episodios: " << RESET << serie.numeroCapitulos <<  endl;
        flujo << "| " << ORANGE << "Contenido activo: " << RESET << serie.getActivo() << endl;
        return flujo;

    }

    void Pelicula::printContenido()const{
        this->printContenido();
        cout << "| "<< ORANGE << "Director: " << RESET << this->director << endl;

    }
    ostream& operator<<(ostream &flujo, const Pelicula &pelicula){
        flujo << "| " << ORANGE << "ID: " << RESET << pelicula.getId_contenido() << endl;
        flujo << "| " << ORANGE << "Titulo: " << RESET << pelicula.getTitulo() <<  endl;
        flujo << "| " << ORANGE << "Fecha de lanzamiento: " << RESET << pelicula.getFechaLanzamiento() <<  endl;
        flujo << "| " << ORANGE << "Duracion: " << RESET << pelicula.getDuracion() <<   endl;
        flujo << "| " << ORANGE << "Genero: " << RESET << pelicula.getGenero() <<  endl;
        flujo << "| " << ORANGE << "IMDB Rating: " << RESET << pelicula.getImdbRating() <<  endl;
        flujo << "| " << ORANGE << "IMDB Votes: " << RESET << pelicula.getImdbVotes() <<  endl;
        flujo << "| " << ORANGE << "Times Liked: " << RESET << pelicula.getTimesLiked() << endl;
        flujo << "| " << ORANGE << "Times Not Liked: " << RESET << pelicula.getTimesNotLiked() << endl;
        flujo << "| " << ORANGE << "Times Played: " << RESET << pelicula.getTimesPlayed() << endl;
        flujo << "| " << ORANGE << "Cristo Flix Rating: " << RESET << pelicula.getCristoFlixRating() << endl;
        flujo << "| " << ORANGE << "Director: " << RESET << pelicula.director <<  endl;
        flujo << "| " << ORANGE << "Contenido activo: " << RESET << pelicula.getActivo() << endl;
        return flujo;
    }

    void Documental::printContenido()const{
        this->printContenido();
        cout << "| " << "Tipo: " << this->tipo << " |" << endl;
    }
    ostream& operator<<(ostream &flujo, const Documental &documental){
        flujo << "| " << ORANGE << "ID: " << RESET << documental.getId_contenido() <<  endl;
        flujo << "| " << ORANGE << "Titulo: " << RESET << documental.titulo <<  endl;
        flujo << "| " << ORANGE << "Fecha de lanzamiento: " << RESET << documental.getFechaLanzamiento() <<  endl;
        flujo << "| " << ORANGE << "Duracion: " << RESET << documental.getDuracion() <<  endl;
        flujo << "| " << ORANGE << "Genero: " << RESET << documental.getGenero() <<  endl;
        flujo << "| " << ORANGE << "IMDB Rating: " << RESET << documental.getImdbRating() << endl;
        flujo << "| " << ORANGE << "IMDB Votes: " << RESET << documental.getImdbVotes() <<  endl;
        flujo << "| " << ORANGE << "Times Liked: " << RESET << documental.getTimesLiked() << endl;
        flujo << "| " << ORANGE << "Times Not Liked: " << RESET << documental.getTimesNotLiked() << endl;
        flujo << "| " << ORANGE << "Times Played: " << RESET << documental.getTimesPlayed() << endl;
        flujo << "| " << ORANGE << "Cristo Flix Rating: " << RESET << documental.getCristoFlixRating() << endl;
        flujo << "| " << ORANGE << "Tipo: " << RESET << documental.tipo <<  endl;
        flujo << "| " << ORANGE << "Contenido activo: " << RESET << documental.getActivo() << endl;
        return flujo;
    }