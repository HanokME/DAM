#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include "valoracion.h"
#include "colors.h"
using namespace std;   
bool const DEBUG = false;
   
    Valoracion::Valoracion(){
        idValoracion = 0;
        contenido = NULL;
        usuario = NULL;
        calificacion = 0;
        fecha_valoracion = Fecha();
        segundosVisualizados = 0;

        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por defecto de Valoracion" << RESET << endl;
        }
    }

    Valoracion::Valoracion(const Valoracion &v){
        this->idValoracion = v.idValoracion;
        this->contenido = v.contenido;
        this->usuario = v.usuario;
        this->calificacion = v.calificacion;
        this->fecha_valoracion = v.fecha_valoracion;
        this->segundosVisualizados = v.segundosVisualizados;

        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por copia de Valoracion" << RESET << endl;
        }
    }

    Valoracion::Valoracion(int idValoracion, Contenido* contenido, Usuario* usuario, float calificacion, Fecha fecha_valoracion, int segundosVisualizados){
        this->idValoracion = idValoracion;
        this->contenido = contenido;
        this->usuario = usuario;
        this->calificacion = calificacion;
        this->fecha_valoracion = fecha_valoracion;
        this->segundosVisualizados = segundosVisualizados;

        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por parametros de Valoracion" << RESET << endl;
        }
    }

    Valoracion::~Valoracion(){
        contenido = NULL;
        usuario = NULL;
    }

    void Valoracion::set_id_valoracion(int idValoracion){
        this->idValoracion = idValoracion;
    }

    int Valoracion::get_id_valoracion()const{
        return idValoracion;
    }

    void Valoracion::set_contenido(Contenido* contenido){
        this->contenido = contenido;
    }

    Contenido* Valoracion::get_contenido()const{
        return contenido;
    }

    void Valoracion::set_usuario(Usuario* usuario){
        this->usuario = usuario;
    }

    Usuario* Valoracion::get_usuario()const{
        return usuario;
    }

    void Valoracion::set_calificacion(float calificacion){
        
        if(calificacion < 0 || calificacion > 5){
            cerr << "La calificación debe estar entre 0 y 5" << endl;
        } else{
            this->calificacion = calificacion;
        }
        
    }

    float Valoracion::get_calificacion()const{
        return calificacion;
    }

    Fecha Valoracion::set_fecha_valoracion(int dia, int mes, int anio){
        fecha_valoracion.setFecha(dia, mes, anio);
        return this->fecha_valoracion;
    }

    Fecha Valoracion::get_fecha_valoracion()const{
        return this->fecha_valoracion;
    }

    void Valoracion::setSegundosVisualizados(int segundosVisualizados){
        this->segundosVisualizados = segundosVisualizados;
    }

    int Valoracion::getSegundosVisualizados()const{
        return segundosVisualizados;
    }

    void Valoracion::set_valoracion(int idValoracion, Contenido* contenido, Usuario* usuario, float calificacion, Fecha fecha_valoracion, int segundosVisualizados){
        this->set_id_valoracion(idValoracion);
        this->set_contenido(contenido);
        this->set_usuario(usuario);
        this->set_calificacion(calificacion);
        this->set_fecha_valoracion(fecha_valoracion.getDia(), fecha_valoracion.getMes(), fecha_valoracion.getAnio());
        this->setSegundosVisualizados(segundosVisualizados);

    }

    Valoracion& Valoracion::operator=(const Valoracion &v){
        if(this != &v){
            this->idValoracion = v.idValoracion;
            this->contenido = v.contenido;
            this->usuario = v.usuario;
            this->calificacion = v.calificacion;
            this->fecha_valoracion = v.fecha_valoracion;
            this->segundosVisualizados = v.segundosVisualizados;
        }
        return *this;
    }

    ostream& operator<<(ostream &flujo, const Valoracion &v){
        flujo << "| " << ORANGE << "ID Valoracion: " << RESET << v.get_id_valoracion() << endl;
        flujo << "| " << ORANGE << "Usuario: " << RESET << v.usuario->getUserName() << endl;
        flujo << "| " << ORANGE << "Contenido: " << RESET << v.contenido->getTitulo() << endl;
        flujo << "| " << ORANGE << "Calificacion: " << RESET << v.get_calificacion() << endl;
        flujo << "| " << ORANGE << "Fecha Valoracion: " << RESET << v.get_fecha_valoracion() << endl;
        flujo << "| " << ORANGE << "Segundos visualizados: " << RESET << v.getSegundosVisualizados() << endl;
        return flujo;
    }

    Contenido* Valoracion::getContenido()const{
        return contenido;
    }


    