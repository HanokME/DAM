#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "fecha.h"
#include "colors.h"


const bool DEBUG = false; 

    Fecha::Fecha(){
        this->dia = 0;
        this->mes = 0;
        this->anio = 0;

        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por defecto de Fecha" << RESET << endl;
        }
    }

    Fecha::Fecha(const Fecha &f){
        this->dia = f.dia;
        this->mes = f.mes;
        this->anio = f.anio;
        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por copia de Fecha" << RESET << endl;
        }
    }

    Fecha::Fecha(int dia, int mes, int anio){
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor con parametros de Fecha" << RESET << endl;
        }
    }

    void Fecha::setDia(int dia){
        this->dia = dia;
    }

    void Fecha::setMes(int mes){
        this->mes = mes;
    }

    void Fecha::setAnio(int anio){
        this->anio = anio;
    }

    int Fecha::getDia()const{
        return this->dia;
    }

    int Fecha::getMes()const{
        return this->mes;
    }

    int Fecha::getAnio()const{
        return this->anio;
    }

    void Fecha::setFecha(int dia, int mes, int anio){
        do{
            if(dia < 1){
                cout << RED << "El dia no puede ser menor que 1" << RESET << endl;
            } else if(dia > 31){
                cout << RED << "El dia no puede ser mayor que 31" << RESET << endl;
            } else{
                this->dia = dia;
            }

        }while(dia < 1 || dia > 31);

        do{
            if(mes < 1){
                cout << RED << "El mes no puede ser menor que 1" << RESET << endl;
            } else if(mes > 12){
                cout << RED << "El mes no puede ser mayor que 12" << RESET << endl;
            } else{
                this->mes = mes;
            }
        }while(mes < 1 || mes > 12);

        do{
            if(anio < 1900){
                cout << RED << "El año no puede ser menor a 1900" << RESET << endl;
            } else{
                this->anio = anio;
            }
        }while(anio < 1900);

    }

    ostream& operator<<(ostream &flujo, const Fecha &fecha){
        flujo << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
        return flujo;
    }

    Fecha& Fecha::operator=(const Fecha &fecha){
        
        if(this != &fecha){
            this->dia = fecha.dia;
            this->mes = fecha.mes;
            this->anio = fecha.anio;
        }
        return *this;
    }

    bool Fecha::operator==(const Fecha &otrafecha)const{
        return (dia == otrafecha.dia && mes == otrafecha.mes && anio == otrafecha.anio);
    }


