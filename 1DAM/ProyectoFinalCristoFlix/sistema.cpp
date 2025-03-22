#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include "colors.h"
#include "sistema.h"

#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"

using namespace std;

const bool DEBUG = false;

    Sistema::Sistema(){
        if(DEBUG){
            cout << CYAN << "Se ha usado el constructor por defecto de Sistema" << RESET << endl;
        }

        totalPlayed = 0;
        totalValorated = 0;
        totalLikes = 0;
        totalUnlikes = 0;

        last_content_id = 0;
        last_user_id = 0;
        last_assessment_id = 0;

        util_v_contenidos_sistema=0;
        dim_v_contenidos_sistema=1;
        v_contenidos_sistema = new Contenido*[dim_v_contenidos_sistema];
        util_v_usuarios_sistema=0;
        dim_v_usuarios_sistema=1;
        v_usuarios_sistema = new Usuario*[dim_v_usuarios_sistema];
        util_v_valoraciones_sistema=0;
        dim_v_valoraciones_sistema=1;
        v_valoraciones_sistema = new Valoracion[dim_v_valoraciones_sistema];

        cargarDatosBasicosSistema();

 
    }
    void Sistema::cargarDatosBasicosSistema(){

        ///////CONTENIDOS
        util_v_contenidos_sistema = 0;
        last_content_id = 0;

        if(DEBUG){
            cout << CYAN << "Se ha usado cargarDatosBasicosSistema" << RESET << endl;
        }

        Fecha f;

        f.setFecha(19, 10, 2004);
        this->insertarContenidoVectorContenidos(new Pelicula(0, "El Corredor del Laberinto", f, 113, "Ciencia Ficcion", 6.8, 511000, "Wes Ball", 0, 0, 2, true));

        f.setFecha(31, 6, 1999);
        this->insertarContenidoVectorContenidos(new Pelicula(1, "The Matrix", f, 136, "Ciencia Ficcion", 8.7, 2100000, "Lana Wachowski, Lilly Wachowski", 1, 1, 4, true));

        f.setFecha(3, 10, 2008);
        this->insertarContenidoVectorContenidos(new Pelicula(2, "Star Wars: The Clone Wars", f, 23, "Ciencia Ficcion", 8.4, 121000, "Dave Filoni", 1, 2, 2, true));

        f.setFecha(13, 1, 1995);
        this->insertarContenidoVectorContenidos(new Pelicula(3, "Pulp Fiction", f, 154, "Crimen", 8.9, 2200000, "Quentin Tarantino", 1, 0, 1, true));

        f.setFecha(26, 7, 2019);
        this->insertarContenidoVectorContenidos(new Serie(4, "The boys", f, 60, "Accion", 8.7, 656000, 24, 1, 1, 1, true));

        f.setFecha(6, 9, 2003);
        this->insertarContenidoVectorContenidos(new Serie(5, "One piece", f, 24, "Animacion", 10.0, 2100000, 1105, 7, 0, 6, true));

        f.setFecha(25, 4, 2019);
        this->insertarContenidoVectorContenidos(new Pelicula(6, "Vengadores: Endgame", f, 143, "Accion", 8.4, 1300000, "Anthony Russo", 1, 0, 1, true));

        f.setFecha(8, 1, 2021);
        this->insertarContenidoVectorContenidos(new Serie(7, "Lupin", f, 45, "Crimen", 7.5, 139000, 17, 1, 5, 1, true));

        f.setFecha(2, 5, 2017);
        this->insertarContenidoVectorContenidos(new Serie(8, "La casa de Papel", f, 60, "Crimen", 8.2, 534000, 48, 0, 0, 0, true));

        f.setFecha(11, 7, 2016);
        this->insertarContenidoVectorContenidos(new Serie(9, "Stranger Things", f, 60, "Fantasia", 8.7, 1300000, 40, 2, 2, 3, true));

        f.setFecha(25, 10, 2023);
        this->insertarContenidoVectorContenidos(new Documental(10, "La vida en nuestro planeta", f, 432, "Naturaleza", 8.1, 5600, "Historia", 0, 0, 1, true));

        if(DEBUG){
            cout << "Contenidos cargados correctamente." << endl;
        }


        //////USUARIOS
        util_v_usuarios_sistema = 0;

        Fecha fu;

        fu.setFecha(14, 8, 1999);
        this->insertarUsuarioVectorUsuarios(new Usuario(0, "night-man", "jdsf", "José David", "Sánchez", "Fernández", fu, true, "estandar"));

        fu.setFecha(10, 6, 2004);
        this->insertarUsuarioVectorUsuarios(new Usuario(1, "ice-man", "gatogordo", "Pablo", "Guardia", "Castro", fu, true, "admin"));

        fu.setFecha(29, 10, 2001);
        this->insertarUsuarioVectorUsuarios(new Usuario(2, "dfpm", "halaMadrid10", "David Francesc", "Pons", "Moll", fu, true, "estandar"));
        
        fu.setFecha(24, 3, 2004);
        this->insertarUsuarioVectorUsuarios(new Usuario(3, "sergio24m", "242424", "Sergio", "Contreras", "Lucas", fu, true, "estandar"));
        
        fu.setFecha(28, 12, 2000);
        this->insertarUsuarioVectorUsuarios(new Usuario(4, "polgs", "ms10", "Henry Paul", "García", "Simbaña", fu, true, "estandar"));
        
        fu.setFecha(5, 7, 2004);
        this->insertarUsuarioVectorUsuarios(new Usuario(5, "AntMan", "aguakate9", "Antonio Manuel", "Velasco", "Rivera", fu, true, "estandar"));
        
        fu.setFecha(14, 2, 2004);
        this->insertarUsuarioVectorUsuarios(new Usuario(6, "alexmrdgz", "q7r8m5", "Alejandro", "Miranda", "Rodriguez", fu, true, "estandar"));
        
        fu.setFecha(12, 11, 2003);
        this->insertarUsuarioVectorUsuarios(new Usuario(7, "llamasl", "7654", "Luis", "Llamas", "Ramón", fu, true, "estandar"));
        
        fu.setFecha(20, 4, 2004);
        this->insertarUsuarioVectorUsuarios(new Usuario(8, "game-master", "toilette", "Carlos", "Polo", "Martin", fu, true, "estandar"));
        
        fu.setFecha(21, 9, 2004);
        this->insertarUsuarioVectorUsuarios(new Usuario(9, "AlexMrtnzz21", "q100", "Alejandro", "Martínez", "Suárez", fu, true, "estandar"));
        
        fu.setFecha(16, 3, 2004);
        this->insertarUsuarioVectorUsuarios(new Usuario(10, "AuraEqualizer", "Lupotia1600", "Maria", "Garrido", "Castellano", fu, true, "estandar"));
        
        fu.setFecha(21, 2, 1991);
        this->insertarUsuarioVectorUsuarios(new Usuario(11, "teffuka", "1234", "Natalia", "Serantes", "Cortez", fu, true, "estandar"));
        
        fu.setFecha(16, 10, 2005);
        this->insertarUsuarioVectorUsuarios(new Usuario(12, "madridistashdp", "culehastalamuerte", "Gonzalo", "Bouso", "Gómez", fu, true, "estandar"));
        
        fu.setFecha(19, 12, 2001);
        this->insertarUsuarioVectorUsuarios(new Usuario(13, "kxnxdx", "333333", "Cristina", "López", "Cabrera", fu, true, "estandar"));
        
        fu.setFecha(22, 11, 1999);
        this->insertarUsuarioVectorUsuarios(new Usuario(14, "Napoleon", "221199", "Hanok", "Martin", "Exposito", fu, true, "estandar"));
        

        if(DEBUG){
            cout << "Usuarios cargados correctamente." << endl;
        }

        


        /////VALORACIONES
        util_v_valoraciones_sistema = 0;
        Fecha fv;

        fv.setFecha(07, 06, 2021);
        Valoracion v0(0, v_contenidos_sistema[3], v_usuarios_sistema[0], 4.5, fv, 2275);
        this->insertarValoracionVectorValoraciones(v0);

        fv.setFecha(21, 03, 2023);
        Valoracion v1(1, v_contenidos_sistema[5], v_usuarios_sistema[0], 5, fv, 2341);
        this->insertarValoracionVectorValoraciones(v1);

        fv.setFecha(12, 12, 2016);
        Valoracion v2(2, v_contenidos_sistema[1], v_usuarios_sistema[0], 4, fv, 334);
        this->insertarValoracionVectorValoraciones(v2);

        fv.setFecha(21, 05, 2024);
        Valoracion v3(3, v_contenidos_sistema[10], v_usuarios_sistema[0], 3.5, fv, 1232);
        this->insertarValoracionVectorValoraciones(v3);

        fv.setFecha(02, 12, 2020);
        Valoracion v4(4, v_contenidos_sistema[6], v_usuarios_sistema[1], 4.5, fv, 500);
        this->insertarValoracionVectorValoraciones(v4);

        fv.setFecha(03, 12, 2020);
        Valoracion v5(5, v_contenidos_sistema[5], v_usuarios_sistema[2], 4.5, fv, 1200);
        this->insertarValoracionVectorValoraciones(v5);

        fv.setFecha(03, 12, 2020);
        Valoracion v6(6, v_contenidos_sistema[2], v_usuarios_sistema[3], 4.5, fv, 144000);
        this->insertarValoracionVectorValoraciones(v6);

        fv.setFecha(04, 11, 2021);
        Valoracion v7(7, v_contenidos_sistema[5], v_usuarios_sistema[4], 4, fv, 3000);
        this->insertarValoracionVectorValoraciones(v7);

        fv.setFecha(05, 02, 2024);
        Valoracion v8(8, v_contenidos_sistema[1], v_usuarios_sistema[5], 4, fv, 136);
        this->insertarValoracionVectorValoraciones(v8);

        fv.setFecha(12, 03, 2024);
        Valoracion v9(9, v_contenidos_sistema[0], v_usuarios_sistema[6], 4, fv, 3780);
        this->insertarValoracionVectorValoraciones(v9);

        fv.setFecha(04, 04, 2021);
        Valoracion v10(10, v_contenidos_sistema[5], v_usuarios_sistema[7], 4, fv, 3000);
        this->insertarValoracionVectorValoraciones(v10);

        fv.setFecha(21, 11, 2023);
        Valoracion v11(11, v_contenidos_sistema[5], v_usuarios_sistema[8], 5, fv, 2341);
        this->insertarValoracionVectorValoraciones(v11);

        fv.setFecha(8, 02, 2021);
        Valoracion v12(12, v_contenidos_sistema[1], v_usuarios_sistema[8], 4.1, fv, 334);
        this->insertarValoracionVectorValoraciones(v0);

        fv.setFecha(23, 03, 2018);
        Valoracion v13(13, v_contenidos_sistema[9], v_usuarios_sistema[8], 4.3, fv, 3600);
        this->insertarValoracionVectorValoraciones(v13);

        fv.setFecha(01, 06, 2023);
        Valoracion v14(14, v_contenidos_sistema[9], v_usuarios_sistema[9], 4.5, fv, 3600);
        this->insertarValoracionVectorValoraciones(v14);

        fv.setFecha(11, 02, 2024);
        Valoracion v15(15, v_contenidos_sistema[7], v_usuarios_sistema[9], 4.2, fv, 11600); 
        this->insertarValoracionVectorValoraciones(v15);

        fv.setFecha(11, 04, 2023);
        Valoracion v16(16, v_contenidos_sistema[2], v_usuarios_sistema[9], 3.8, fv, 8600); 
        this->insertarValoracionVectorValoraciones(v16);

        fv.setFecha(03, 11, 2023);
        Valoracion v17(17, v_contenidos_sistema[4], v_usuarios_sistema[10], 4.45, fv, 7800); 
        this->insertarValoracionVectorValoraciones(v17);

        fv.setFecha(01, 06, 2023);
        Valoracion v18(18, v_contenidos_sistema[9], v_usuarios_sistema[11], 5, fv, 3600); 
        this->insertarValoracionVectorValoraciones(v18);

        fv.setFecha(16, 10, 2020);
        Valoracion v19(19, v_contenidos_sistema[0], v_usuarios_sistema[12], 4.5, fv, 3780); 
        this->insertarValoracionVectorValoraciones(v19);

        fv.setFecha(12, 12, 2001);
        Valoracion v20(20, v_contenidos_sistema[5], v_usuarios_sistema[13], 4.8, fv, 2001); 
        this->insertarValoracionVectorValoraciones(v20);

        fv.setFecha(03, 06, 2024);
        Valoracion v21(21, v_contenidos_sistema[1], v_usuarios_sistema[14], 3, fv, 334);
        this->insertarValoracionVectorValoraciones(v21);

        if(DEBUG){
            cout << "Valoraciones cargadas correctamente." << endl;
        }
        //Usuario0
        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[3]);
        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[5]);
        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[1]);
        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[10]);

        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[3]);
        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[5]);

        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[7]);

        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[3]);
        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[5]);
        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[1]);
        v_usuarios_sistema[0]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[10]);

        //Usuario1
        v_usuarios_sistema[1]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[6]);

        v_usuarios_sistema[1]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[6]);

        v_usuarios_sistema[1]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[6]);

        //Usuario2
        v_usuarios_sistema[2]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[5]);

        v_usuarios_sistema[2]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[5]);

        v_usuarios_sistema[2]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[7]);
        v_usuarios_sistema[2]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[2]);

        v_usuarios_sistema[2]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[5]);

        //Usuario3
        v_usuarios_sistema[3]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[2]);

        v_usuarios_sistema[3]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[2]);

        v_usuarios_sistema[3]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[2]);

        //Usuario4
        v_usuarios_sistema[4]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[5]);

        v_usuarios_sistema[4]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[5]);

        v_usuarios_sistema[4]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[7]);
        v_usuarios_sistema[4]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[2]);

        v_usuarios_sistema[4]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[5]);

        //Usuario5
        v_usuarios_sistema[5]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[1]);
        v_usuarios_sistema[5]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[1]);

        //Usuario6
        v_usuarios_sistema[6]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[0]);

        v_usuarios_sistema[6]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[7]);

        v_usuarios_sistema[6]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[0]);

        //Usuario7
        v_usuarios_sistema[7]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[5]);

        v_usuarios_sistema[7]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[5]);

        v_usuarios_sistema[7]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[5]);

        //Usuario8
        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[5]);
        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[1]);
        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[9]);

        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[9]);
        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[5]);

        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[1]);

        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[9]);
        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[5]);
        v_usuarios_sistema[8]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[1]);

        //Usuario9
        v_usuarios_sistema[9]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[9]);
        v_usuarios_sistema[9]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[7]);
        v_usuarios_sistema[9]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[2]);

        v_usuarios_sistema[9]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[9]);
        v_usuarios_sistema[9]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[7]);
        v_usuarios_sistema[9]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[2]);

        //Usuario10
        v_usuarios_sistema[10]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[4]);

        v_usuarios_sistema[10]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[4]);

        v_usuarios_sistema[10]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[10]);

        v_usuarios_sistema[10]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[4]);

        //Usuario11
        v_usuarios_sistema[11]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[9]);

        v_usuarios_sistema[11]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[7]);

        v_usuarios_sistema[11]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[9]);

        //Usuario12
        v_usuarios_sistema[12]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[0]);

        v_usuarios_sistema[12]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[9]);
        v_usuarios_sistema[12]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[5]);

        v_usuarios_sistema[12]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[0]);

        //Usuario13
        v_usuarios_sistema[13]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[5]);

        v_usuarios_sistema[13]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[1]);
        v_usuarios_sistema[13]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[5]);

        v_usuarios_sistema[13]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[9]);
        v_usuarios_sistema[13]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[7]);

        v_usuarios_sistema[13]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[5]);

        //Usuario14
        v_usuarios_sistema[14]->insertarContenidoEnVectorContenidosVisualizados(v_contenidos_sistema[1]);

        v_usuarios_sistema[14]->insertarContenidoEnVectorContenidoMg(v_contenidos_sistema[1]);

        v_usuarios_sistema[14]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[9]);
        v_usuarios_sistema[14]->insertarContenidoEnVectorContenidoNoMg(v_contenidos_sistema[4]);

        v_usuarios_sistema[14]->insertarContenidoEnVectorContenidoValorado(v_contenidos_sistema[1]);

        recalcularEstadisticas();
    }

    Sistema::Sistema(const Sistema &s){
        totalPlayed = 0;
        totalValorated = 0;
        totalLikes = 0;
        totalUnlikes = 0;

        last_content_id = 0;
        last_user_id = 0;
        last_assessment_id = 0;

        v_usuarios_sistema=NULL;
        util_v_usuarios_sistema=0;
        dim_v_usuarios_sistema=1;
        v_contenidos_sistema=NULL;
        util_v_contenidos_sistema=0;
        dim_v_contenidos_sistema=1;
        v_valoraciones_sistema=NULL;
        util_v_valoraciones_sistema=0;
        dim_v_valoraciones_sistema=1;
    
        asignarVectorUsuarios(v_usuarios_sistema, v_usuarios_sistema, util_v_usuarios_sistema, dim_v_usuarios_sistema);
        util_v_usuarios_sistema = util_v_usuarios_sistema;
        dim_v_usuarios_sistema = dim_v_usuarios_sistema;

        asignarVectorContenidos(v_contenidos_sistema, v_contenidos_sistema, util_v_contenidos_sistema, dim_v_contenidos_sistema);
        util_v_contenidos_sistema = util_v_contenidos_sistema;
        dim_v_contenidos_sistema = dim_v_contenidos_sistema;

        asignarVectorValoraciones(v_valoraciones_sistema, v_valoraciones_sistema, util_v_valoraciones_sistema, dim_v_valoraciones_sistema);
        util_v_valoraciones_sistema = util_v_valoraciones_sistema;
        dim_v_valoraciones_sistema = dim_v_valoraciones_sistema;
    }

    Sistema::Sistema(Usuario** v_usuarios_sistema, int util_v_usuarios_sistema, int dim_v_usuarios_sistema, Contenido** v_contenidos_sistema, int util_v_contenidos_sistema, int dim_v_contenidos_sistema, Valoracion* v_valoraciones_sistema, int util_v_valoraciones_sistema, int dim_v_valoraciones_sistema){

        asignarVectorUsuarios(this->v_usuarios_sistema, v_usuarios_sistema, util_v_usuarios_sistema, dim_v_usuarios_sistema);
        this->util_v_usuarios_sistema = util_v_usuarios_sistema;
        this->dim_v_usuarios_sistema = dim_v_usuarios_sistema;

        asignarVectorContenidos(this->v_contenidos_sistema, v_contenidos_sistema, util_v_contenidos_sistema, dim_v_contenidos_sistema);
        this->util_v_contenidos_sistema = util_v_contenidos_sistema;
        this->dim_v_contenidos_sistema = dim_v_contenidos_sistema;

        asignarVectorValoraciones(this->v_valoraciones_sistema, v_valoraciones_sistema, util_v_valoraciones_sistema, dim_v_valoraciones_sistema);
        this->util_v_valoraciones_sistema = util_v_valoraciones_sistema;
        this->dim_v_valoraciones_sistema = dim_v_valoraciones_sistema;
    }

    Sistema::~Sistema(){

        if(DEBUG){
            cout << CYAN << "Iniciando el destructor de Sistema." << RESET << endl;
        }

        for (int i = 0; i < util_v_contenidos_sistema; ++i) {
            delete v_contenidos_sistema[i];
        }
        for (int i = 0; i < util_v_usuarios_sistema; ++i) {
            delete v_usuarios_sistema[i];
        }

        
        delete[] v_contenidos_sistema;
        delete[] v_usuarios_sistema;
        delete[] v_valoraciones_sistema;

        v_usuarios_sistema = NULL;
        v_contenidos_sistema = NULL;
        v_valoraciones_sistema = NULL;

        if(DEBUG){
            cout << CYAN << "Saliendo de destructor de Sistema." << RESET << endl;
        }

        cout << CYAN << "SISTEMA DESTRUIDO CON EXITO." << RESET << endl;

    }


    void Sistema::setVValoracionesSistema(Valoracion* valoraciones) {
        v_valoraciones_sistema = valoraciones;
    }

    Valoracion* Sistema::getVValoracionesSistema() const {
        return v_valoraciones_sistema;
    }

    void Sistema::setVContenidosSistema(Contenido** contenidos) {
        v_contenidos_sistema = contenidos;
    }

    Contenido** Sistema::getVContenidosSistema() const {
        return v_contenidos_sistema;
    }

    void Sistema::setVUsuariosSistema(Usuario** usuarios) {
        v_usuarios_sistema = usuarios;
    }

    Usuario** Sistema::getVUsuariosSistema() const {
        return v_usuarios_sistema;
    }


    void Sistema::resizeUsuarios() {

        if(DEBUG){
            cout << CYAN << "Accediendo a resize de Usuario." << RESET <<endl;
        }

        this->get_dim_v_usuarios();
        dim_v_usuarios_sistema *= 2;
        Usuario **aux = new Usuario*[dim_v_usuarios_sistema];
        for (int i = 0; i < util_v_usuarios_sistema; ++i) {
            aux[i] = this->v_usuarios_sistema[i];
        }
        delete[] v_usuarios_sistema;
        v_usuarios_sistema = aux;

        if(DEBUG){
            cout << CYAN << "Saliendo de resize de Usuario." << RESET <<endl;
        }
    }

    void Sistema::resizeContenidos() {

        if(DEBUG){
            cout << CYAN << "Accediendo a resize de Contenido." << RESET <<endl;
        }
        dim_v_contenidos_sistema *= 2;
        Contenido **v_aux = new Contenido*[dim_v_contenidos_sistema];
        for (int i = 0; i < util_v_contenidos_sistema; ++i) {
            v_aux[i] = this->v_contenidos_sistema[i];
        }

        
        delete[] v_contenidos_sistema;
        v_contenidos_sistema = v_aux;

        if(DEBUG){
            cout << CYAN << "Saliendo de resize de Contenido." << RESET <<endl;
        }
    }

    void Sistema::resizeValoraciones() {

        if(DEBUG){
            cout << CYAN << "Accediendo a resize de Valoracion." << RESET <<endl;
        }

        dim_v_valoraciones_sistema *= 2;
        Valoracion *aux = new Valoracion[dim_v_valoraciones_sistema];
        for (int i = 0; i < util_v_valoraciones_sistema; ++i) {
            aux[i] = this->v_valoraciones_sistema[i];
        }
        delete[] v_valoraciones_sistema;
        v_valoraciones_sistema = aux;

        if(DEBUG){
            cout << CYAN << "Saliendo de resize de Valoracion." << RESET <<endl;
        }
    }

    void Sistema::insertarUsuarioVectorUsuarios(Usuario *unusuario){
        if(this->get_util_v_usuarios() == this->get_dim_v_usuarios()){
            resizeUsuarios();
        }
        v_usuarios_sistema[util_v_usuarios_sistema] = unusuario;
        util_v_usuarios_sistema++;
        last_user_id++;
    }

    void Sistema::insertarContenidoVectorContenidos(Contenido *uncontenido){
        if(this->get_util_v_contenidos() == this->get_dim_v_contenidos()){
            this->resizeContenidos();
        }
        v_contenidos_sistema[util_v_contenidos_sistema] = uncontenido;
        util_v_contenidos_sistema++;
        last_content_id++;

    }

    void Sistema::insertarValoracionVectorValoraciones(Valoracion &unvaloracion){
        if(this->get_util_v_valoraciones() == this->get_dim_v_valoraciones()){
            resizeValoraciones();
        }
        v_valoraciones_sistema[util_v_valoraciones_sistema] = unvaloracion;
        util_v_valoraciones_sistema++;
        last_assessment_id++;

        totalValorated++;
    }

    void Sistema::set_util_v_usuarios(int util_v){
        util_v_usuarios_sistema = util_v;
    }

    int Sistema::get_util_v_usuarios(){
        return util_v_usuarios_sistema;
    }

    void Sistema::set_dim_v_usuarios(int dim_v){
        dim_v_usuarios_sistema = dim_v;
    }

    int Sistema::get_dim_v_usuarios(){
        return dim_v_usuarios_sistema;
    }

    void Sistema::set_util_v_contenidos(int util_v){
        util_v_contenidos_sistema = util_v;
    }

    int Sistema::get_util_v_contenidos(){
        return util_v_contenidos_sistema;
    }

    void Sistema::set_dim_v_contenidos(int dim_v){
        dim_v_contenidos_sistema = dim_v;
    }

    int Sistema::get_dim_v_contenidos(){
        return dim_v_contenidos_sistema;
    }

    void Sistema::set_util_v_valoraciones(int util_v){
        util_v_valoraciones_sistema = util_v;
    }

    int Sistema::get_util_v_valoraciones(){
        return util_v_valoraciones_sistema;
    }

    void Sistema::set_dim_v_valoraciones(int dim_v){
        dim_v_valoraciones_sistema = dim_v;
    }

    int Sistema::get_dim_v_valoraciones(){
        return dim_v_valoraciones_sistema;
    }

    void Sistema::setUsuarioLogado(Usuario* usuario){
        this->usuario_logado = usuario;
    }
    Usuario* Sistema::getUsuarioLogado() const{
        return this->usuario_logado;
    }

    void Sistema::setTotalPlayed(int totalPlayed){
        this->totalPlayed = totalPlayed;
    }
    int Sistema::getTotalPLayed(){
        return totalPlayed;
    }

    void Sistema::setTotalValorated(int totalValorated){
        this->totalValorated = totalValorated;
    }
    int Sistema::getTotalValorated(){
        return totalValorated;
    }

    void Sistema::setTotalLikes(int totalLikes){
        this->totalLikes = totalLikes;
    }
    int Sistema::getTotalLikes(){
        return totalLikes;
    }

    void Sistema::setTotalUnLikes(int totalUnLikes){
        this->totalUnlikes = totalUnLikes;
    }
    int Sistema::getTotalUnLikes(){
        return totalUnlikes;
    }

    void Sistema::asignarVectorUsuarios(Usuario**& destino, Usuario** origen, int utilOrigen, int dimOrigen){
        destino = new Usuario*[dimOrigen];
        for (int i = 0; i < utilOrigen; i++) {
            destino[i] = new Usuario(*origen[i]);
        }

    }

    void Sistema::asignarVectorContenidos(Contenido**& destino, Contenido** origen, int utilOrigen, int dimOrigen) {

        destino = new Contenido*[dimOrigen];
        for (int i = 0; i < utilOrigen; i++) {
            if(dynamic_cast<Pelicula*>(origen[i])){
                destino[i] = new Pelicula(*dynamic_cast<Pelicula*>(origen[i]));
            } else if(dynamic_cast<Serie*>(origen[i])){
                destino[i] = new Serie(*dynamic_cast<Serie*>(origen[i]));
            } else if((dynamic_cast<Documental*>(origen[i]))){
                destino[i] = new Documental(*dynamic_cast<Documental*>(origen[i]));
            } else{
                destino[i] = new Contenido(*origen[i]);
            }
        }
    }

    void Sistema::asignarVectorValoraciones(Valoracion*& destino, const Valoracion* origen, int utilOrigen, int dimOrigen) {
        if (destino) {
            delete[] destino;
        }
        destino = new Valoracion[dimOrigen];
        for (int i = 0; i < utilOrigen; i++) {
            destino[i] = origen[i];
        }
    }

    void Sistema::printVectorUsuarios() const {
        for (int i = 0; i < util_v_usuarios_sistema; ++i) {
            cout << *v_usuarios_sistema[i] << endl;
        }
    }

    void Sistema::printVectorContenidos() const {
        
        if(DEBUG){
            cout << "Tamaño del vector de contenidos: " << util_v_contenidos_sistema << endl;
        }
        
        for (int i = 0; i < util_v_contenidos_sistema; ++i) {
            if(Pelicula* pelicula = dynamic_cast<Pelicula*>(v_contenidos_sistema[i])){
                cout << GRAY << "PELICULA: " << RESET << endl;
                cout << *pelicula << endl;
            } else if(Serie* serie = dynamic_cast<Serie*>(v_contenidos_sistema[i])){
                cout << GRAY << "SERIE: " << RESET << endl;
                cout << *serie << endl;
            } else if(Documental* documental = dynamic_cast<Documental*>(v_contenidos_sistema[i])){
                cout << GRAY << "DOCUMENTAL: " << RESET << endl;
                cout << *documental << endl;
            } else {
                cout << "No se pudo determinar el tipo de contenido." << endl;
            }
        }
    }

    void Sistema::printVectorValoraciones() const {
        for (int i = 0; i < util_v_valoraciones_sistema; ++i) {
            cout << v_valoraciones_sistema[i] << endl;
        }
    }

    Sistema& Sistema::operator=(const Sistema &s){
        if (this != &s) {

            asignarVectorUsuarios(v_usuarios_sistema, v_usuarios_sistema, util_v_usuarios_sistema, dim_v_usuarios_sistema);
            util_v_usuarios_sistema = util_v_usuarios_sistema;
            dim_v_usuarios_sistema = dim_v_usuarios_sistema;

            asignarVectorContenidos(v_contenidos_sistema, v_contenidos_sistema, util_v_contenidos_sistema, dim_v_contenidos_sistema);
            util_v_contenidos_sistema = util_v_contenidos_sistema;
            dim_v_contenidos_sistema = dim_v_contenidos_sistema;

            asignarVectorValoraciones(v_valoraciones_sistema, v_valoraciones_sistema, util_v_valoraciones_sistema, dim_v_valoraciones_sistema);
            util_v_valoraciones_sistema = util_v_valoraciones_sistema;
            dim_v_valoraciones_sistema = dim_v_valoraciones_sistema;

        }
        return *this;

    }

    ostream& operator<<(ostream &flujo, const Sistema &s){
        flujo << ORANGE << "--------------------CONTENIDOS-------------------\n" << RESET;
        s.printVectorContenidos();

        flujo << ORANGE << "---------------------USUARIOS--------------------\n" << RESET;
        s.printVectorUsuarios();

        flujo << ORANGE << "-------------------VALORACIONES------------------\n" << RESET;
        s.printVectorValoraciones();

        return flujo;

    }

    void Sistema::mostrarCatalogoContenido()const{
        printVectorContenidos();
            
    }

    void Sistema::login(bool &encontrado, bool &esadmin) {
        string usuario;
        string password;
        encontrado = false;
        esadmin = false;

        cout << "Ingrese su usuario: ";
        cin >> usuario;
        cout << "Ingrese su contraseña: ";
        cin >> password;

        for (int i = 0; i < util_v_usuarios_sistema; ++i) {
            
            if(DEBUG){
                cout << "DEBUG: Iteración " << i << endl;
                cout << "DEBUG: Usuario almacenado: " << v_usuarios_sistema[i]->getUserName() << ", Password almacenado: " << v_usuarios_sistema[i]->getPassword() << endl;
                cout << "DEBUG: Usuario ingresado: " << usuario << ", Password ingresado: " << password << endl;
            }
            
            if(v_usuarios_sistema[i]->getUserName() == usuario && v_usuarios_sistema[i]->getPassword() == password){
                encontrado = true;
                usuario_logado = v_usuarios_sistema[i];
                cout << "Bienvenido " << v_usuarios_sistema[i]->getUserName() << endl;

                if(v_usuarios_sistema[i]->getTipo() == "admin"){

                    esadmin = true;

                } 
                
            }
        }

        if (!encontrado) {
            cout << "Usuario o contraseña incorrectos." << endl;
        }

    }

    void Sistema::menuInicio(Sistema& sistema, Usuario& usuario){

        int opcion;
        char confirmacion;
        bool volverlogin = false;

        do{
            if(volverlogin){
                bool encontrado = false;
                bool esadmin = false;
                login(encontrado, esadmin);

                if(encontrado){
                    if(esadmin){
                        menuAdmin(sistema, opcion, confirmacion);
                    } else{
                        menuUsuario(sistema, opcion, usuario);
                    }
                } 
                    volverlogin = false;
                
               

            } else{
                mostrarMenuInicial();
                opcion = pedirOpcion();

                switch (opcion){
                    case 1:

                        volverlogin = true;
                        break;

                    case 2:
                        this->testingHP(sistema);
                        break;

                    case 3:
                        this->testingMaria(sistema);
                        break;

                    case 4:
                        this->testingNatalia(sistema);
                        break;

                    case 5:
                        this->testingPablo(sistema);
                        break;

                    case -1:
                        cout << "Hasta pronto..." << endl;
                        volverlogin = true;
                        break;

                    default:

                        cout << "Opción invalida. Inténtalo de nuevo..." << endl;
                        break;
                }
                    
                

            }

        }while(opcion != -1);

    }

    void Sistema::mostrarMenuCompleto(){

        cout << "Menú Admin" << endl;
        cout << "--------------" << endl;
        cout << "1. Recargar datos básicos del sistema" << endl;
        cout << "2. Imprimir sistema" << endl;
        cout << "3. Buscar contenido por Titulo." << endl;
        cout << "4. Buscar contenido por Genero." << endl;
        cout << "5. Buscar contenido por Fecha." << endl;
        cout << "6. CristoFlix Rating." << endl;
        cout << "7. Informe Ranking de contenido." << endl;
        cout << "8. Informe Ranking de contenido por tipo." << endl;
        cout << "9. Informe Ranking de usuarios." << endl;
        cout << "10. Agregar Contenido a sistema. " << endl;
        cout << "11. Agregar Usuario a sistema. " << endl;
        cout << "12. Buscar usuario. " << endl;
        cout << "13. Buscar valoraciones de un contenido. " << endl;
        cout << "14. Modificar contenido del sistema. " << endl;
        cout << "15. Modificar usuario del sistema. " << endl;
        cout << "16. Eliminar contenido del sistema. " << endl;
        cout << "17. Eliminar valoracion del sistema. " << endl;
        cout << "18. Eliminar todos los contenidos de un tipo. " << endl;
        cout << "-1. Cerrar sesion." << endl;
        cout << endl;

    }

    void Sistema::menuAdmin(Sistema& sistema, int opcion, char confirmacion){
        
        string titulo, genero;
        Fecha fecha;
        Contenido* contenido;
        float rating;
        string tipo;

        do{

            mostrarMenuCompleto();
            opcion = pedirOpcion();

            switch(opcion){
                case 1:
                    cout << "Desea recargar los datos básicos del sistema? (S/N): ";
                    cin >> confirmacion;
                    if(confirmacion == 's' || confirmacion == 'S'){
                        this->cargarDatosBasicosSistema();
                        cout << "Datos cargados correctamente" << endl;
                    }else{
                        cout << "Operacion cancelada, no se recargaran los datos." << endl;
                    }
                    break;
                case 2:
                    this->visualizarSistema();
                    break;
                case 3:
                    
                        titulo = introducirTitulo();
                        contenido = this->buscarContenidoTitulo(titulo);
                        this->getUsuarioLogado()->imprimirContenidosBuscados();
                    
                    
                    break;
                case 4:
                    
                        genero = introducirGenero();
                        contenido = this->buscarContenidoGenero(genero);
                        this->getUsuarioLogado()->imprimirContenidosBuscados();
                    
                    
                    break;
                case 5:
                    
                        fecha = IntroducirFecha();
                        contenido = this->buscarContenidoFecha(fecha);
                        this->getUsuarioLogado()->imprimirContenidosBuscados();

                    
                    break;

                case 6:
                    cout << "Introduzca el titulo del contenido para calcular el cristoflixRating." << endl;
                    titulo = introducirTitulo();
                    contenido = this->buscarContenidoTitulo(titulo);
                    cout << "El Rating de CristoFlix para el contenido " << contenido->getTitulo() << " es: "  << endl;
                    this->mostrarRating(contenido);

                    break;

                case 7:
                    this->generarInformeRankingContenido();
                    break;
                case 8:
                    
                    do{
                        cout << "Introduzca el Tipo al que se le desea hacer el ranking (Serie, Pelicula, Documental): ";
                        cin >> tipo;
                        if (tipo != "Serie" && tipo != "Pelicula" && tipo != "Documental")
                        {
                            cout << "Tipo de contenido invalido, por favor intentelo de nuevo." << endl;
                        }
                    }while(tipo != "Serie" && tipo != "Pelicula" && tipo != "Documental");
                        
                    this->generarInformeRankingContenidoPorTipo(tipo);
                    break;

                case 9:

                    this->generarInformeRankingUsuario();

                    break;

                case 10:
                    this->agregarContenidoASistema();
                    break;
                case 11:
                    this->agregarUsuarioASistema();
                    break;
                case 12:
                    this->buscarUsuarioEnSistema();
                    break;

                case 13:
                    this->consultarValoracionContenido();
                    break;

                case 14:
                    this->modificarContenidoSistema();
                    break;

                case 15:
                    this->modificarUsuarioSistema();
                    break;

                case 16:
                    this->eliminarContenidoSistema();
                    break;

                case 17:
                    this->eliminarValoracionSistema();
                    break;

                case 18:
                    this->eliminarTodoContenidoSistemaPorTipo();
                    break;
                case -1:
                    cout << "Cerrando sesion..." << endl;
                    break;

                default:
                    cout << "Opción invalida. Inténtalo de nuevo..." << endl;

            }

        }while(opcion != -1);

    }

    void Sistema::menuUsuario(Sistema& sistema, int opcion, Usuario& usuario){
        char confirmacion;
        string titulo;

        do{
            mostrarMenuUsuario();
            opcion = pedirOpcion();
            switch(opcion){
                case 1:
                    sistema.mostrarCatalogoContenido();
                    break;
                case 2:

                    cout << "Quiere que mostremos todo el catalogo de contenido?(S/N): ";
                    cin >> confirmacion;

                    if(confirmacion == 's' || confirmacion == 'S'){
                        sistema.mostrarCatalogoContenido();
                        sistema.visualizarContenido();

                    } else{
                        sistema.visualizarContenido();

                    }

                    break;
                case 3:
                    cout << "Quiere que mostremos todo el catalogo de contenido?(S/N): ";
                    cin >> confirmacion;

                    if(confirmacion == 's' || confirmacion == 'S'){
                        sistema.mostrarCatalogoContenido();
                        sistema.anadirMeGusta();

                    } else{

                        sistema.anadirMeGusta();
                    }

                    break;

                case 4:
                    cout << "Quiere que mostremos todo el catalogo de contenido?(S/N): ";
                    cin >> confirmacion;

                    if(confirmacion == 's' || confirmacion == 'S'){
                        sistema.mostrarCatalogoContenido();
                        sistema.anadirNoMeGusta();
                    } else{
                        sistema.anadirNoMeGusta();

                    }

                    break;

                case 5:
                    sistema.consultarValoraciones();
                    break;
                case -1:
                    cout << "Cerrando sesion..." << endl;
                    break;

                default:
                    cout << "Opción invalida. Inténtalo de nuevo..." << endl;

            }

        }while(opcion != -1);

    }

    void Sistema::mostrarMenuUsuario(){

        cout << "Menú principal" << endl;
        cout << "--------------" << endl;
        cout << "1. Imprimir catalogo." << endl;
        cout << "2. Visualizar contenido." << endl;
        cout << "3. Añadir a me gusta un contenido. " << endl;
        cout << "4. Añadir a no me gusta un contenido. " << endl;
        cout << "5. Consultar valoraciones. " << endl;
        cout << "-1. Cerrar sesion." << endl;
        cout << endl;

    }

    void Sistema::mostrarMenuInicial(){
        cout << "Menú inicial" << endl;
        cout << "--------------" << endl;
        cout << "1. Iniciar sesión" << endl;
        cout << "2. Testing Paul" << endl;
        cout << "3. Testing Maria" << endl;
        cout << "4. Testing Natalia" << endl;
        cout << "5. Testing Pablo" << endl;
        cout << "-1. Destruir y salir" << endl;
        cout << endl;
    }

    int Sistema::pedirOpcion(){
        int opcion;
        cout << "Ingrese opción: ";
        cin >> opcion;
        return opcion;
    }

    Contenido* Sistema::buscarContenidoTitulo(const string& titulo){
        if(usuario_logado != NULL){
            usuario_logado->limpiarVectorContenidoBuscado();
            for(int i = 0; i < util_v_contenidos_sistema; i++){
                if(v_contenidos_sistema[i]->getActivo() && v_contenidos_sistema[i]->getTitulo() == titulo){
                    usuario_logado->insertarContenidoEnVectorContenidoBuscado(v_contenidos_sistema[i]);
                    return v_contenidos_sistema[i];
                }
            }
        } else{
            cout << "No se encuentra ningun contenido." << endl;
        }
        return NULL;
        
    }
    Contenido* Sistema::buscarContenidoGenero(const string& genero){

        if(usuario_logado != NULL){
            usuario_logado->limpiarVectorContenidoBuscado();
            for(int i = 0; i < util_v_contenidos_sistema; i++){
                cout << "DEBUG: Analizando contenido " << i << v_contenidos_sistema[i]->getGenero() << " del sistema." << endl;
                if(v_contenidos_sistema[i]->getActivo() && v_contenidos_sistema[i]->getGenero() == genero){
                    cout << "DEBUG: ¡Contenido con el género '" << genero << "' encontrado!" << endl;
                    usuario_logado->insertarContenidoEnVectorContenidoBuscado(v_contenidos_sistema[i]);
                    return v_contenidos_sistema[i];
                } else{
                    cout << "No se encuentra ningun contenido." << endl;
                }
            }
        }
        cout << "DEBUG: Fin de la búsqueda de contenido por género." << endl;
        return NULL;
    }
    Contenido* Sistema::buscarContenidoFecha(const Fecha& fecha){

        if(usuario_logado != NULL){
            usuario_logado->limpiarVectorContenidoBuscado();
            for(int i = 0; i < util_v_contenidos_sistema; i++){
                if(v_contenidos_sistema[i]->getActivo() && v_contenidos_sistema[i]->getFechaLanzamiento() == fecha){
                    usuario_logado->insertarContenidoEnVectorContenidoBuscado(v_contenidos_sistema[i]);
                    return v_contenidos_sistema[i];
                } else{
                    cout << "No se encuentra ningun contenido." << endl;
                }
            }
        }
        return NULL;
    }

    string Sistema::introducirTitulo(){
        string titulo;
        cout << "Introduzca el titulo deseado: ";
        cin.ignore();
        getline(cin, titulo);
        return titulo;
    }
    string Sistema::introducirGenero(){
        string genero;
        cout << "Introduzca el genero deseado: ";
        cin.ignore();
        getline(cin, genero);
        return genero;
    }
    Fecha Sistema::IntroducirFecha(){
        int dia, mes, anio;
        
        cout << "Introduzca la fecha de lanzamiento deseada: " << endl;

        do{
            cout << "Introduce el dia: ";
            cin >> dia;
            if(dia < 1 || dia > 31){
                cout << "El dia introducido no está dentro de los valores permitidos, por favor introducelo de nuevo." << endl;
            }
        }while(dia < 1 || dia > 31);

        do{
            cout << "Introduce el mes: ";
            cin >> mes;
            if(mes < 1 || mes > 12){
                cout << "El mes introducido no está dentro de los valores permitidos, por favor introducelo de nuevo." << endl;
            }
        }while(mes < 1 || mes > 12);

        do{
            cout << "Introduce el año: ";
            cin >> anio;
            if(anio < 1895 || anio > 2024){
                cout << "El año introducido no está dentro de los valores permitidos, por favor introducelo de nuevo." << endl;
            }
        }while(anio < 1895 || anio > 2024);
        

        return Fecha(dia, mes, anio);
    }

    void Sistema::visualizarContenido(){
        string titulo;
        Contenido* contenido;
        int timesPlayed;

        Usuario* u = this->getUsuarioLogado();

        titulo = introducirTitulo();
        contenido = this->buscarContenidoTitulo(titulo);
        this->getUsuarioLogado()->imprimirContenidosBuscados();

        if (contenido != NULL && contenido->getActivo()) {
            valorarContenido(contenido);
            u->insertarContenidoEnVectorContenidosVisualizados(contenido);

            timesPlayed = contenido->getTimesPlayed();
            contenido->setTimesPlayed(timesPlayed + 1);
            totalPlayed++;
        } else{
            cout << "No se encuentra el contenido." << endl;
        }


    }

    void Sistema::visualizarSistema(){
        cout << *this << endl;
    }


    void Sistema::valorarContenido(Contenido* contenido){
        int dia, mes, anio;
        float estrella;
        Fecha f;
        int segundos;
        Usuario* u = this->getUsuarioLogado();
        

        cout << "Introduce los segundos visualizados: ";
        cin >> segundos;

        cout << "Introduce la fecha actual: " << endl;

        do{

            cout << "Dia: ";
            cin >> dia;
        }while(dia < 1 || dia > 31);
        do{

            cout << "Mes: ";
            cin >> mes;
        }while(mes < 1 || mes > 12);
        do{

            cout << "Año: ";
            cin >> anio;
        }while(anio < 1900 || dia > 2024);

        do{

            cout << "Introduce la calificacion(0-5): ";
            cin >> estrella;
        }while(estrella < 0 || estrella > 5);

        f.setFecha(dia ,mes, anio);

        u = this->getUsuarioLogado();

        Valoracion v(last_assessment_id, contenido, u, estrella, f, segundos);
        this->insertarValoracionVectorValoraciones(v);
        u->insertarContenidoEnVectorContenidoValorado(contenido);
        totalValorated++;


    }

    void Sistema::anadirMeGusta(){
        string titulo;
        int timesLiked;
        Contenido* contenido;
        Usuario* u = this->getUsuarioLogado();
        bool tieneMeGusta = false;
        bool tieneNoMeGusta = false;
        bool salir = false;

        titulo = introducirTitulo();

        contenido = this->buscarContenidoTitulo(titulo);

        if (contenido != NULL && contenido->getActivo()) {

            for(int i = 0; i < u->getUtil_v_Contenido_mg() && !tieneMeGusta; i++){
                if(u->getContenidoMeGusta(i) == contenido){
                    tieneMeGusta = true;
                }
            }


            for(int i = 0; i < u->getUtil_v_Contenido_nomg() && !salir; i++){
                if(u->getContenidoNoMeGusta(i) == contenido){
                    tieneNoMeGusta = true;

                    for(int j = i; j < u->getUtil_v_Contenido_nomg() - 1; j++){
                        u->setContenidoNoMeGusta(j, u->getContenidoNoMeGusta(j + 1));
                    }

                    u->setUtil_v_contenido_nomg(u->getUtil_v_Contenido_nomg()-1);
                    contenido->setTimesNotLiked(contenido->getTimesNotLiked()-1);
                    totalUnlikes--;
                    salir = true;
                }
            }


            if(!tieneMeGusta){
                u->insertarContenidoEnVectorContenidoMg(contenido);

                timesLiked = contenido->getTimesLiked();
                contenido->setTimesLiked(timesLiked + 1);
                totalLikes++;
            } else{
                cout << "Ya ha dado me gusta a este contenido." << endl;
            }

            
        } else{
            cout << "No se encuentra el contenido." << endl;
        }


    }

    void Sistema::anadirNoMeGusta(){
        string titulo;
        int timesNoLiked;
        Contenido* contenido;
        Usuario* u = this->getUsuarioLogado();
        bool tieneMeGusta = false;
        bool tieneNoMeGusta = false;
        bool salir = false;

        titulo = introducirTitulo();

        contenido = this->buscarContenidoTitulo(titulo);

        
        if (contenido != NULL && contenido->getActivo()) {

            for(int i = 0; i < u->getUtil_v_Contenido_nomg() && !tieneNoMeGusta; i++){
                if(u->getContenidoNoMeGusta(i) == contenido){
                    tieneNoMeGusta = true;
                }
            }


            for(int i = 0; i < u->getUtil_v_Contenido_mg() && !tieneNoMeGusta; i++){
                if(u->getContenidoMeGusta(i) == contenido){
                    tieneMeGusta = true;

                    for(int j = i; j < u->getUtil_v_Contenido_mg() - 1; j++){
                        u->setContenidoMeGusta(j, u->getContenidoMeGusta(j + 1));
                    }

                    u->setUtil_v_contenido_mg(u->getUtil_v_Contenido_mg() - 1);
                    contenido->setTimesLiked(contenido->getTimesLiked() - 1);
                    totalLikes--;

                    u->insertarContenidoEnVectorContenidoNoMg(contenido);
                    timesNoLiked = contenido->getTimesNotLiked();
                    contenido->setTimesNotLiked(timesNoLiked + 1);
                    totalUnlikes++;
                    tieneNoMeGusta = true;
                    

                }
            }


            if(!tieneMeGusta && !tieneNoMeGusta){
                u->insertarContenidoEnVectorContenidoNoMg(contenido);
                timesNoLiked = contenido->getTimesNotLiked();
                contenido->setTimesNotLiked(timesNoLiked + 1);
                totalUnlikes++;
                
            } else if(tieneNoMeGusta){
                cout << "Ya ha dado no me gusta a este contenido." << endl;
            }

            
        } else{
            cout << "No se encuentra el contenido." << endl;
        }
        

    }

    void Sistema::consultarValoraciones()const{
        cout << "Valoraciones del usuario " << usuario_logado->getUserName() << ": " <<  endl;

        for (int i = 0; i < util_v_valoraciones_sistema; i++) {
            if (v_valoraciones_sistema[i].get_usuario() == usuario_logado) {
                Contenido* contenido = v_valoraciones_sistema[i].getContenido();
                cout << "| Título: " << contenido->getTitulo() << endl;
                cout << "| Fecha: " << v_valoraciones_sistema[i].get_fecha_valoracion() << endl;
                cout << "| Segundos visualizados: " << v_valoraciones_sistema[i].getSegundosVisualizados() << endl;
                cout << "| Estrellas: " << v_valoraciones_sistema[i].get_calificacion() << endl;
                cout << "----------------------------------" << endl;


            }
        }

        cout << "Contenidos que te gustan: " << endl;
        for(int i = 0; i < usuario_logado->getUtil_v_Contenido_mg(); i++){
            Contenido* contenido = usuario_logado->getContenidoMeGusta(i);
            if(contenido != NULL){
                cout << "| Título: " << contenido->getTitulo() << endl;
                cout << "----------------------------------" << endl;
            }
        }

        cout << "Contenidos que no te gustan: " << endl;
        for(int i = 0; i < usuario_logado->getUtil_v_Contenido_nomg(); i++){
            Contenido* contenido = usuario_logado->getContenidoNoMeGusta(i);
            if(contenido != NULL){
                cout << "| Título: " << contenido->getTitulo() << endl;
                cout << "----------------------------------" << endl;
            }
        }
    }

    float Sistema::calcularValoracionMediaNormalizada(Contenido* contenido){
        float sumavaloraciones = 0.0;
        int numerovaloraciones = 0;
        float valoracionmedia = 0.0;

        Valoracion* valoracion = this->getVValoracionesSistema();
        int utilValoracion  = this->get_util_v_valoraciones();

        if(contenido == NULL){
            return 0.0;
        }

        for(int i = 0; i < utilValoracion; i++){
            if(valoracion[i].getContenido() == contenido){
                sumavaloraciones += valoracion[i].get_calificacion();
                numerovaloraciones++;
            }
            if (DEBUG) {
                cout << "Valoracion #" << i << " (Contenido: " << v_valoraciones_sistema[i].get_contenido()->getTitulo() << "): " << v_valoraciones_sistema[i].get_calificacion() << endl;
            }
        }

        if(numerovaloraciones != 0){
            valoracionmedia = sumavaloraciones / numerovaloraciones;
            valoracionmedia = valoracionmedia / 5;
            valoracionmedia = valoracionmedia * 0.25;
        }

        if(DEBUG){
            cout << "Suma de valoraciones: " << sumavaloraciones << endl;
            cout << "Número de valoraciones: " << numerovaloraciones << endl;
            cout << "Valoración media normalizada: " << valoracionmedia << endl;
        }
        return valoracionmedia;

    }

    float Sistema::calcularVisualizacionMediaNormalizada(Contenido* contenido){
        float mediavisualizaciones = 0.0;
        float totalV = contenido->getTimesPlayed();

        if(contenido == NULL){
            return 0.0;
        }

        if(this->getTotalPLayed() != 0){
            mediavisualizaciones = totalV / (float)this->getTotalPLayed();

        }
        mediavisualizaciones = mediavisualizaciones * 0.25;

        if(DEBUG){
            cout << "Total de visualizaciones del contenido: " << totalV << endl;
            cout << "Total de visualizaciones en el sistema: " << this->getTotalPLayed() << endl;
            cout << "Visualizaciones normalizadas: " << mediavisualizaciones << endl;
        }
        return mediavisualizaciones;
    }

    float Sistema::calcularMeGustaMedioNormalizado(Contenido* contenido){
        float mediaMG = 0.0;;
        float totalMG = contenido->getTimesLiked();

        if(contenido == NULL){
            return 0.0;
        }

        if(this->getTotalLikes() != 0){
            mediaMG = totalMG / (float)this->getTotalLikes();
        }
        mediaMG = mediaMG * 0.25;

        if(DEBUG){
            cout << "Total de Me Gusta del contenido: " << totalMG << endl;
            cout << "Total de Me Gusta en el sistema: " << this->getTotalLikes() << endl;
            cout << "Me Gusta normalizados: " << mediaMG << endl;

        }
        return mediaMG;


    }

    float Sistema::calcularNoMeGustaMedioNormalizado(Contenido* contenido){
        float mediaNOMG = 0.0;;
        float totalNOMG = contenido->getTimesNotLiked();

        if(contenido == NULL){
            return 0.0;
        }

        if(this->getTotalUnLikes() != 0){
            mediaNOMG = totalNOMG / (float)this->getTotalUnLikes();
        }
        mediaNOMG = mediaNOMG * 0.25;

        if (DEBUG) {
            cout << "Total de No Me Gusta del contenido: " << totalNOMG << endl;
            cout << "Total de No Me Gusta en el sistema: " << this->getTotalUnLikes() << endl;
            cout << "No Me Gusta normalizados: " << mediaNOMG << endl;
        }
        return mediaNOMG;
    }

    float Sistema::calcularCristoFlixRating(Contenido* contenido){
        float rating = 0.0;
        float valoracionMedia = this->calcularValoracionMediaNormalizada(contenido);
        float visualizacionMedia = this->calcularVisualizacionMediaNormalizada(contenido);
        float megustaMedia = this->calcularMeGustaMedioNormalizado(contenido);
        float nomegustaMedia = this->calcularNoMeGustaMedioNormalizado(contenido);

        if(contenido == NULL){
            return 0.0;
        }

        rating = valoracionMedia + visualizacionMedia + megustaMedia + nomegustaMedia;
        rating = rating * 10.0;

        if(DEBUG){
            cout << "Resultado del calculo de Rating: " << rating << endl;
        }

        contenido->setCristoFlixRating(rating);


        return rating;
        
    }

    void Sistema::mostrarRating(Contenido* contenido){
        float rating = 0.0;
        rating = calcularCristoFlixRating(contenido);

        float valoracionMedia = this->calcularValoracionMediaNormalizada(contenido);
        float visualizacionMedia = this->calcularVisualizacionMediaNormalizada(contenido);
        float megustaMedia = this->calcularMeGustaMedioNormalizado(contenido);
        float nomegustaMedia = this->calcularNoMeGustaMedioNormalizado(contenido);

        cout << "| " << ORANGE << "Valoracion media: " << RESET << valoracionMedia << endl;
        cout << "| " << ORANGE << "Visualizacion media: " << RESET << visualizacionMedia << endl;
        cout << "| " << ORANGE << "Me gusta medio: " << RESET << megustaMedia << endl;
        cout << "| " << ORANGE << "No me gusta medio: " << RESET << nomegustaMedia << endl;

        cout << "| " << ORANGE << "RATING: " << RESET << rating << endl;
    }

    void Sistema::obtenerTop3Contenido(Contenido* top3[]){

        float valoraciones[util_v_contenidos_sistema];
        Contenido* contenidoaux;

        for(int i = 0; i < util_v_contenidos_sistema; i++){
            valoraciones[i] = this->calcularCristoFlixRating(v_contenidos_sistema[i]);
        }

        for(int i = 0; i < 3; i++){
            int indiceMax = i;

            for(int j = i + 1; j < util_v_contenidos_sistema; j++){
                if(valoraciones[j] > valoraciones[indiceMax]){
                    indiceMax = j;
                }
            }

            float valoracionaux = valoraciones[i];
            valoraciones[i] = valoraciones[indiceMax];
            valoraciones[indiceMax] = valoracionaux;

            contenidoaux = v_contenidos_sistema[i];
            v_contenidos_sistema[i] = v_contenidos_sistema[indiceMax];
            v_contenidos_sistema[indiceMax] = contenidoaux;

            top3[i] = v_contenidos_sistema[i];
        }

        


    }

    void Sistema::obtenerContenidosMasVisualizados(Contenido* masVisualizado[]){

        int repro[util_v_contenidos_sistema];
        Contenido* contenidoaux;

        for(int i = 0; i < util_v_contenidos_sistema; i++){
            repro[i] = v_contenidos_sistema[i]->getTimesPlayed();
        }

        for(int i = 0; i < 3; i++){
            int indiceMax = i;
            for(int j = i + 1; j < util_v_contenidos_sistema; j++){
                if(repro[j] > repro[indiceMax]){
                    indiceMax = j;
                }
            }

            int reproaux = repro[i];
            repro[i] = repro[indiceMax];
            repro[indiceMax] = reproaux;

            contenidoaux = v_contenidos_sistema[i];
            v_contenidos_sistema[i] = v_contenidos_sistema[indiceMax];
            v_contenidos_sistema[indiceMax] = contenidoaux;

            masVisualizado[i] = v_contenidos_sistema[i];
        }
    }

    void Sistema::obtenerContenidosMenosGustados(Contenido* menosGustados[]){
        int like[util_v_contenidos_sistema];
        Contenido* contenidoaux;

        for(int i = 0; i < util_v_contenidos_sistema; i++){
            like[i] = v_contenidos_sistema[i]->getTimesLiked();
        }

        for(int i = 0; i < 3; i++){
            int indiceMin = i;
            for(int j = i + 1; j < util_v_contenidos_sistema; j++){
                if(like[j] < like[indiceMin]){
                    indiceMin = j;
                }
            }

            int likeaux = like[i];
            like[i] = like[indiceMin];
            like[indiceMin] = likeaux;

            contenidoaux = v_contenidos_sistema[i];
            v_contenidos_sistema[i] = v_contenidos_sistema[indiceMin];
            v_contenidos_sistema[indiceMin] = contenidoaux;

            menosGustados[i] = v_contenidos_sistema[i];
        }
    }

    void Sistema::generarInformeRankingContenido(){
        Contenido* top3[3];
        obtenerTop3Contenido(top3);
        cout << "| " << ORANGE << "Ranking Top 3 de Contenidos: " << RESET << endl;
        for(int i = 0; i < 3; i++){
            

            if(top3[i] != NULL){
                cout << "| " << ORANGE << i + 1 << ". " << RESET << top3[i]->getTitulo() << " - Valoracion general: " << this->calcularCristoFlixRating(top3[i]) << endl;
            }
        }

        Contenido* masVisualizado[3];
        obtenerContenidosMasVisualizados(masVisualizado);
        cout << "| " << ORANGE << "Contenidos mas reproducidos: " << RESET << endl;
        for(int i = 0; i < 3; i++){
            
            if(masVisualizado[i] != NULL){

                cout << "| " << ORANGE << i + 1 << ". " << RESET << masVisualizado[i]->getTitulo() << " - Reproducciones: " << masVisualizado[i]->getTimesPlayed() << endl;
            }

        }

        Contenido* like[3];
        obtenerContenidosMenosGustados(like);
        cout << "| " << ORANGE << "Contenidos con menos gustados: " << RESET << endl;
        for(int i = 0; i < 3; i++){
            
            if(like[i] != NULL){

                cout << "| " << ORANGE << i + 1 << ". " << RESET << like[i]->getTitulo() << " - likes: " << like[i]->getTimesLiked() << endl;
            }

        }

    }

    int Sistema::filtrarContenidoPorTipo(Contenido* contenido[], const string& tipo){
        int contador = 0;

        for(int i = 0; i < util_v_contenidos_sistema; i++){
            if( (tipo == "Serie" && dynamic_cast<Serie*>(v_contenidos_sistema[i]) != NULL) || (tipo == "Pelicula" && dynamic_cast<Pelicula*>(v_contenidos_sistema[i]) != NULL) || (tipo == "Documental" && dynamic_cast<Documental*>(v_contenidos_sistema[i]) != NULL) ){
                contenido[contador] = v_contenidos_sistema[i];
                contador++;
            }
        }
        return contador;
    }


    void Sistema::generarInformeRankingContenidoPorTipo(const string& tipo){
        Contenido* top3[3] = {NULL, NULL, NULL};
        obtenerTop3ContenidoPorTipo(top3, tipo);
        cout << "| " << ORANGE << "Ranking Top 3 de " << tipo << "s: " << RESET << endl;
        for(int i = 0; i < 3; i++){

            if(top3[i] != NULL){
                cout << "| " << ORANGE << i + 1 << ". " << RESET << top3[i]->getTitulo() << " - Valoracion general: " << this->calcularCristoFlixRating(top3[i]) << endl;
            }
        }

        Contenido* masVisualizado[3] = {NULL, NULL, NULL};
        obtenerContenidosMasVisualizadosPorTipo(masVisualizado, tipo);
        
        cout << "| " << ORANGE << "Ranking Top 3 de " << tipo << "s mas visualizados: " << RESET << endl;
        for(int i = 0; i < 3; i++){
            
            if(masVisualizado[i] != NULL){

                cout << "| " << ORANGE << i + 1 << ". " << RESET << masVisualizado[i]->getTitulo() << " - Reproducciones: " << masVisualizado[i]->getTimesPlayed() << endl;
            }

        }

        Contenido* like[3] = {NULL, NULL, NULL};
        obtenerContenidosMenosGustadosPorTipo(like, tipo);
        cout << "| " << ORANGE << "Ranking Top 3 de " << tipo << "s menos gustados: " << RESET << endl;
        for(int i = 0; i < 3; i++){
            
            if(like[i] != NULL){

                cout << "| " << ORANGE << i + 1 << ". " << RESET << like[i]->getTitulo() << " - likes: " << like[i]->getTimesLiked() << endl;
            }

        }

    }

    void Sistema::obtenerTop3ContenidoPorTipo(Contenido* top3[], const string& tipo) {
        Contenido* filtrados[util_v_contenidos_sistema];
        int cantidadFiltrados = filtrarContenidoPorTipo(filtrados, tipo);

        cout << "Cantidad filtrados: " << cantidadFiltrados << endl;

        float valoracion[cantidadFiltrados];
        Contenido* contenidoaux;

        for (int i = 0; i < cantidadFiltrados; i++) {
            valoracion[i] = this->calcularCristoFlixRating(filtrados[i]);
        }

        for (int i = 0; i < 3 && i < cantidadFiltrados; i++) {
            int indiceMax = i;

            for (int j = i + 1; j < cantidadFiltrados; j++) {
                if (valoracion[j] > valoracion[indiceMax]) {
                    indiceMax = j;
                }
            }

            float valoracionaux = valoracion[i];
            valoracion[i] = valoracion[indiceMax];
            valoracion[indiceMax] = valoracionaux;

            contenidoaux = filtrados[i];
            filtrados[i] = filtrados[indiceMax];
            filtrados[indiceMax] = contenidoaux;

            top3[i] = filtrados[i];
        }

        for (int i = cantidadFiltrados; i < 3; i++) {
            top3[i] = NULL;
        }
    }

    void Sistema::obtenerContenidosMasVisualizadosPorTipo(Contenido* masVisualizado[], const string& tipo) {
        Contenido* filtrados[util_v_contenidos_sistema];
        int cantidadFiltrados = filtrarContenidoPorTipo(filtrados, tipo);

        cout << "Cantidad filtrados: " << cantidadFiltrados << endl;

        int repro[cantidadFiltrados];
        Contenido* contenidoaux;

        for (int i = 0; i < cantidadFiltrados; i++) {
            repro[i] = filtrados[i]->getTimesPlayed();
        }

        for (int i = 0; i < 3 && i < cantidadFiltrados; i++) {
            int indiceMax = i;

            for (int j = i + 1; j < cantidadFiltrados; j++) {
                if (repro[j] > repro[indiceMax]) {
                    indiceMax = j;
                }
            }

            int reproaux = repro[i];
            repro[i] = repro[indiceMax];
            repro[indiceMax] = reproaux;

            contenidoaux = filtrados[i];
            filtrados[i] = filtrados[indiceMax];
            filtrados[indiceMax] = contenidoaux;

            masVisualizado[i] = filtrados[i];
        }

        for (int i = cantidadFiltrados; i < 3; i++) {
            masVisualizado[i] = NULL;
        }
    }

    void Sistema::obtenerContenidosMenosGustadosPorTipo(Contenido* menosGustados[], const string& tipo) {
        Contenido* filtrados[util_v_contenidos_sistema];
        int cantidadFiltrados = filtrarContenidoPorTipo(filtrados, tipo);

        cout << "Cantidad filtrados: " << cantidadFiltrados << endl;

        int likes[cantidadFiltrados];
        Contenido* contenidoaux;

        for (int i = 0; i < cantidadFiltrados; i++) {
            likes[i] = filtrados[i]->getTimesLiked();
        }

        for (int i = 0; i < 3 && i < cantidadFiltrados; i++) {
            int indiceMin = i;

            for (int j = i + 1; j < cantidadFiltrados; j++) {
                if (likes[j] < likes[indiceMin]) {
                    indiceMin = j;
                }
            }

            int likesaux = likes[i];
            likes[i] = likes[indiceMin];
            likes[indiceMin] = likesaux;

            contenidoaux = filtrados[i];
            filtrados[i] = filtrados[indiceMin];
            filtrados[indiceMin] = contenidoaux;

            menosGustados[i] = filtrados[i];
        }

        for (int i = cantidadFiltrados; i < 3; i++) {
            menosGustados[i] = NULL;
        }
    }

    Usuario* Sistema::obtenerUsuarioDarkNight()const{
        Usuario* usuarioDarkNight = NULL;
        int maxVisualizaciones = 0;
        int visualizaciones = 0;

        for(int i = 0; i < util_v_usuarios_sistema; i++){
            visualizaciones = v_usuarios_sistema[i]->getUtil_v_Contenido_visualizado();
            if(visualizaciones >= maxVisualizaciones){
                maxVisualizaciones = visualizaciones;
                usuarioDarkNight = v_usuarios_sistema[i];
            }
        }
        return usuarioDarkNight;
    }
    Usuario* Sistema::obtenerUsuarioFacilon()const{
        Usuario* facilon = NULL;
        float sumaValoraciones = 0.0;
        int numerovaloraciones = 0;
        float maxValoracion = 0.0;
        float valoracionMedia = 0.0;

        for(int i = 0; i < util_v_usuarios_sistema; i++){
            sumaValoraciones = 0.0;
            numerovaloraciones = 0;

            //itero entre todas las visualizaciones del usuario actual
            for(int j = 0; j < v_usuarios_sistema[i]->getUtil_v_Contenido_visualizado(); j++){
                Contenido* contenido = v_usuarios_sistema[i]->getContenidoVisualizado(j);

                //itero por todas las valoraciones
                for(int k = 0; k < util_v_valoraciones_sistema; k++){
                    if(v_valoraciones_sistema[k].getContenido() == contenido){
                        sumaValoraciones += v_valoraciones_sistema[k].get_calificacion();
                        numerovaloraciones ++;
                    }
                }
            }

            if(numerovaloraciones > 0){
                valoracionMedia = sumaValoraciones / numerovaloraciones;
            } else{
                valoracionMedia = 0.0;
            }

            if(valoracionMedia >= maxValoracion){
                maxValoracion = valoracionMedia;
                facilon = v_usuarios_sistema[i];
            }

        }

        return facilon;
    }
    
    Usuario* Sistema::obtenerUsuarioOfuscated()const{
        Usuario* ofuscated = NULL;
        int maxNMG = 0;
        int totalNMG = 0;

        cout << CYAN << "Utiles del sistema en ofuscated: " << util_v_usuarios_sistema << RESET << endl;

        for(int i = 0; i < util_v_usuarios_sistema; i++){
            totalNMG = 0;

            for(int j = 0; j < v_usuarios_sistema[i]->getUtil_v_Contenido_visualizado(); j++){
                Contenido* contenido = v_usuarios_sistema[i]->getContenidoVisualizado(j);
                totalNMG += contenido->getTimesNotLiked();

            }

            if(totalNMG >= maxNMG){
                maxNMG = totalNMG;
                ofuscated = v_usuarios_sistema[i];
            }
        }

        return ofuscated;

    }

    void Sistema::generarInformeRankingUsuario()const{

        Usuario* darknight = obtenerUsuarioDarkNight();
        Usuario* facilon = obtenerUsuarioFacilon();
        Usuario* ofuscated = obtenerUsuarioOfuscated();

        cout << "| " << ORANGE << "Ranking Usuarios: " << RESET << endl;

        cout << "| " << ORANGE << "Usuario Dark Night: " << RESET;
        if(darknight != NULL){
            cout << darknight->getUserName() << endl;
        } else{
            cout << "No disponible." << endl;
        }

        cout << "| " << ORANGE << "Usuario Facilon: " << RESET;
        if(facilon != NULL){
            cout << facilon->getUserName() << endl;
        } else{
            cout << "No disponible." << endl;
        }

        cout << "| " << ORANGE << "Usuario Ofuscated: " << RESET;
        if(ofuscated != NULL){
            cout << ofuscated->getUserName() << endl;
        } else{
            cout << "No disponible." << endl;
        }

    }

    void Sistema::recalcularEstadisticas(){
        totalLikes = 0;
        totalUnlikes = 0;
        totalPlayed = 0;
        double rating;

        for (int i = 0; i < util_v_contenidos_sistema; ++i) {
            totalPlayed += v_contenidos_sistema[i]->getTimesPlayed();
            totalLikes += v_contenidos_sistema[i]->getTimesLiked();
            totalUnlikes += v_contenidos_sistema[i]->getTimesNotLiked();

            rating = this->calcularCristoFlixRating(v_contenidos_sistema[i]);
            v_contenidos_sistema[i]->setCristoFlixRating(rating);

        }

        this->setTotalPlayed(totalPlayed);
        this->setTotalLikes(totalLikes);
        this->setTotalUnLikes(totalUnlikes);

        if (DEBUG) {
            cout << "Total visualizaciones en el sistema: " << totalPlayed << endl;
            cout << "Total Valoraciones en el sistema: " << totalValorated << endl;
            cout << "Total Me Gusta en el sistema: " << totalLikes << endl;
            cout << "Total No Me Gusta en el sistema: " << totalUnlikes << endl;
        }

    }

    void Sistema::agregarContenidoASistema(){

        string tipo, titulo, director, genero, tipoDocu;
        int duracion, episodios, MG, NMG, vecesVisto;
        float imdbRating;
        int imdbVotes;
        Fecha fechaLanzamiento;
        int id = last_content_id;
        bool activo;

        do{
            cout << "Introduzca el tipo de contenido(Pelicula, Serie, Documental): ";
            cin >> tipo;
            if(tipo != "Pelicula" && tipo != "Serie" && tipo != "Documental"){
                cout << "El tipo introducido no es valido, por favor vuelva a introducirlo." << endl;
            }
        }while(tipo != "Pelicula" && tipo != "Serie" && tipo != "Documental");


        titulo = introducirTitulo();
        genero = introducirGenero();
        fechaLanzamiento = IntroducirFecha();

        do{
            cout << "Introduzca la duracion en segundos: ";
            cin >> duracion;
            if(duracion < 1){
                cout << "La duracion no puede ser menor que 1 segundo, por favor introducelo de nuevo." << endl;
            }
        }while(duracion < 1);

        imdbRating = 0.0;
        imdbVotes = 0;
        vecesVisto = 0;
        MG = 0;
        NMG = 0;

        cout << "EL contenido estara activo?(1 para si y 0 para no): ";
        cin>>activo;


        //SERIE
        if(tipo == "Serie"){
            do{
                cout << "Introduce el numero de episodios: ";
                cin >> episodios;
                if(episodios < 1){
                    cout << "El numero de episodios no puede ser menor a 1." << endl;
                }
            }while(episodios < 1);

            Serie* nuevaserie = new Serie(id, titulo, fechaLanzamiento, duracion ,genero, imdbRating, imdbVotes, episodios, MG, NMG, vecesVisto, activo);
            this->insertarContenidoVectorContenidos(nuevaserie);
            this->calcularCristoFlixRating(nuevaserie);
        }

        if(tipo == "Pelicula"){

                cout << "Introduce el nombre del director: ";
                cin >> director;


            Pelicula* nuevapelicula = new Pelicula(id, titulo, fechaLanzamiento, duracion ,genero, imdbRating, imdbVotes, director, MG, NMG, vecesVisto, activo);
            this->insertarContenidoVectorContenidos(nuevapelicula);
            this->calcularCristoFlixRating(nuevapelicula);
        }

        if(tipo == "Documental"){

                cout << "Introduce el tipo de documental: ";
                cin >> tipoDocu;


            Documental* nuevodocumental = new Documental(id, titulo, fechaLanzamiento, duracion ,genero, imdbRating, imdbVotes, tipoDocu, MG, NMG, vecesVisto, activo);
            this->insertarContenidoVectorContenidos(nuevodocumental);
            this->calcularCristoFlixRating(nuevodocumental);
        }


        recalcularEstadisticas();


        cout << GREEN << "Contenido agregado correctamente." << RESET << endl;
    }

    void Sistema::agregarUsuarioASistema(){
        string user_name, nombre, apellido1, apellido2, password, tipo;
        Fecha fechaNacimiento;
        bool activo;
        int id = last_user_id;

        cout << "Introduce tu nombre de usuario: ";
        cin >> user_name;

        cout << "Introduzca la contraseña: ";
        cin >> password;

        cout << "Introduzca su nombre, apellido1 y apellido2: ";
        cin >> nombre >> apellido1 >> apellido2;

        fechaNacimiento = IntroducirFecha();

        do{
            cout << "Introduce el tipo de usuario(estandar o admin): ";
            cin >> tipo;
            if(tipo != "admin" && tipo != "estandar"){
                cout << "El tipo es invalido, introduzcalo de nuevo." << endl;
            }
        }while(tipo != "admin" && tipo != "estandar");

        this->insertarUsuarioVectorUsuarios(new Usuario(last_user_id, user_name, password, nombre, apellido1, apellido2, fechaNacimiento, true, tipo));

        cout << GREEN << "Usuario agregado correctamente." << RESET << endl;

    }

    Usuario* Sistema::buscarUsuarioPorUserName(const string& user_name)const{
        for(int i = 0; i < util_v_usuarios_sistema; i++){
            if(v_usuarios_sistema[i]->getUserName() == user_name){
                return v_usuarios_sistema[i];
            }
        }
        return NULL;
    }
    Usuario* Sistema::buscarUsuarioPorNombreCompleto(const string& nombre, const string& apellido1, const string& apellido2)const{
        for(int i = 0; i < util_v_usuarios_sistema; i++){
            if(v_usuarios_sistema[i]->getNombre() == nombre && v_usuarios_sistema[i]->getApellido1() == apellido1 && v_usuarios_sistema[i]->getApellido2() == apellido2){
                return v_usuarios_sistema[i];
            }
        }
        return NULL;
    }

    void Sistema::buscarUsuarioEnSistema(){
        int opcion;

        do{
            cout << "Por que parametro quieres buscar: " << endl;
            cout << "1. UserName." << endl;
            cout << "2. Nombre completo." << endl;
            cout << "Ingrese la opcion: ";
            cin >> opcion;

            if(opcion != 1 && opcion != 2){
                cout << "Opcion invalida, introducela de nuevo." << endl;
            }
        }while(opcion != 1 && opcion != 2);

        if(opcion == 1){
            string user_name;

            cout << "Introduce su UserName: ";
            cin >> user_name;

            Usuario* usuario = buscarUsuarioPorUserName(user_name);
            if(usuario != NULL){
                cout << "Usuario encontrado: " << endl;
                cout << *usuario;
            } else{
                cout << "Usuario no encontrado." << endl;
            }
        } else if(opcion == 2){
            string nombre, apellido1, apellido2;

            cout << "Introduzca su nombre, apellido1 y apellido2: ";
            cin >> nombre >> apellido1 >> apellido2;

            Usuario* usuario = buscarUsuarioPorNombreCompleto(nombre, apellido1, apellido2);

            if(usuario){
                cout << *usuario;
            } else{
                cout << "Usuario no encontrado." << endl;
            }

        }

    }

    void Sistema::consultarValoracionContenido(){
        string titulo;
        titulo = introducirTitulo();

        Contenido* contenido = buscarContenidoTitulo(titulo);

        if(contenido != NULL && contenido->getActivo() == true){
            cout << "Valoracion encontrada para: " << contenido->getTitulo() << endl;

            for(int i = 0; i < util_v_valoraciones_sistema; i++){
                if(v_valoraciones_sistema[i].getContenido() == contenido){
                    cout << v_valoraciones_sistema[i] << endl;
                }
            }
        } else{
            cout << "Contenido no encontrado." << endl;
        }
    }

    void Sistema::modificarContenidoSistema(){
        string titulo;
        titulo = introducirTitulo();
        char opcion;

        string nuevoTitulo, nuevoGenero, nuevoDirector, nuevoTipoDocu;
        int nuevaDuracion, nuevosEpisodios;
        float nuevoImdbRating;
        int nuevoImdbVotes, nuevosMG, nuevosNMG, nuevasVecesVisto;
        int dia, mes, anio;
        bool nuevoActivo;

        Contenido* contenido = buscarContenidoTitulo(titulo);

        if(contenido != NULL){
            cout << "Contenido encontrado: " << contenido->getTitulo() << endl;

            cout << "Si desea cambiar algun contenido pulse(s o S), si no (N o n)" << endl;
            cout << "Introduzca los nuevos datos que desee: " << endl;

            cout << "Modificar titulo: ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){
                nuevoTitulo = introducirTitulo();
                contenido->setTitulo(nuevoTitulo);
            }
            cout << "Modificar genero: ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){

                nuevoGenero = introducirGenero();
                contenido->setGenero(nuevoGenero);
                
            }
            cout << "Modificar Fecha de lanzamiento: ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){
                cout << "Introduzca el día: ";
                cin >> dia;
                cout << "Introduzca el mes: ";
                cin >> mes;
                cout << "Introduzca el año: ";
                cin >> anio;
                contenido->setFechaLanzamiento(dia, mes, anio);
            }
            cout << "Modificar duracion: ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){
                do {
                    cout << "Nueva Duración en segundos: ";
                    cin >> nuevaDuracion;

                    if (nuevaDuracion < 1) {
                        cout << "La duración no puede ser menor que 1 segundo, por favor introdúcelo de nuevo." << endl;
                    }

                } while (nuevaDuracion < 1);
                contenido->setDuracion(nuevaDuracion);
            }

            cout << "Modificar estado activo: ";
            cin >> opcion;

            if(opcion == 's' || opcion == 'S'){
                cout << "El contenido esta activo? (1 para si y 0 para no): ";
                cin >> nuevoActivo;
                contenido->setActivo(nuevoActivo);

            }

            ////SERIE
            if(Serie* serie = dynamic_cast<Serie*>(contenido)){
                cout << "Modificar numero de episodios: ";
                cin >> opcion;

                if(opcion == 's' || opcion == 'S'){
                    
                do{
                    cout << "Numero de episodios: ";
                    cin >> nuevosEpisodios;
                    if(nuevosEpisodios < 1){
                        cout << "El numero de episodios no puede ser menor a 1." << endl;
                    }
                }while(nuevosEpisodios < 1);
                    serie->setNumeroCapitulos(nuevosEpisodios);
                }
            }


            ///PELICULA
            if(Pelicula* pelicula = dynamic_cast<Pelicula*>(contenido)){
                cout << "Modificar nombre del director: ";
                cin >> opcion;

                if(opcion == 's' || opcion == 'S'){
                    cout << "Nombre del director: ";
                    cin >> nuevoDirector;
                    pelicula->setDirector(nuevoDirector);
                }
            }


            ///DOCUMENTAL
            if(Documental* documental = dynamic_cast<Documental*>(contenido)){
                cout << "Modificar el tipo de documental: ";
                cin >> opcion;

                if(opcion == 's' || opcion == 'S'){
                    cout << "Tipo de documental: ";
                    cin >> nuevoTipoDocu;
                    documental->setTipo(nuevoTipoDocu);
                }
            }

            recalcularEstadisticas();

            cout << GREEN << "Contenido modificado correctamente." << RESET << endl;

        } else{
            cout << "Contenido no encontrado." << endl;
        }
    }
    void Sistema::modificarUsuarioSistema(){
       string nuevoUserName, nuevoPassword, nuevoNombre, nuevoApellido1, nuevoApellido2, nuevoTipo;
        int dia, mes, anio;
        char opcion;
        bool nuevoActivo;


        string userName;
        cout << "Introduce el user name para buscar: ";
        cin >> userName;

        Usuario* usuario = buscarUsuarioPorUserName(userName);

        if(usuario != NULL){
            cout << "Usuario encontrado: " << usuario->getUserName() << endl;

            cout << "Si desea cambiar algun contenido pulse(s o S), si no (N o n)" << endl;
            cout << "Introduzca los nuevos datos que desee: " << endl;

            cout << "Modificar user name (s/n): ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){
                cout << "User name: ";
                cin >> nuevoUserName;

                usuario->setUserName(nuevoUserName);
            }
            cout << "Modificar contraseña (s/n): ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){

                cout << "Password: ";
                cin >> nuevoPassword;
                usuario->setPassword(nuevoPassword);

            }
            cout << "Modificar nombre de usuario (s/n): ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){
                cout << "Nombre de usuario: ";
                cin >> nuevoNombre;
                usuario->setNombre(nuevoNombre);
                
            }
            cout << "Modificar Apellido1 (s/n): ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){
                cout << "Apellido 1: ";
                cin >> nuevoApellido1;
                usuario->setApellido1(nuevoApellido1);
            }
            cout << "Modificar Apellido1 (s/n): ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){
                cout << "Apellido 2: ";
                cin >> nuevoApellido2;
                usuario->setApellido2(nuevoApellido2);
            }
            cout << "Modificar fecha de nacimiento (s/n): ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){
                do{
                    cout << "Introduce el dia: ";
                    cin >> dia;
                    if(dia < 1 || dia > 31){
                        cout << "El dia introducido no está dentro de los valores permitidos, por favor introducelo de nuevo." << endl;
                    }
                }while(dia < 1 || dia > 31);

                do{
                    cout << "Introduce el mes: ";
                    cin >> mes;
                    if(mes < 1 || mes > 12){
                        cout << "El mes introducido no está dentro de los valores permitidos, por favor introducelo de nuevo." << endl;
                    }
                }while(mes < 1 || mes > 12);

                do{
                    cout << "Introduce el año: ";
                    cin >> anio;
                    if(anio < 1895 || anio > 2024){
                        cout << "El año introducido no está dentro de los valores permitidos, por favor introducelo de nuevo." << endl;
                    }
                }while(anio < 1895 || anio > 2024);
                usuario->setFechaNacimiento(dia, mes, anio);
            }

            if(usuario != usuario_logado){

                cout << "Modificar estado de actividad (s/n): ";
                cin >> opcion;
                if(opcion == 's' || opcion == 'S'){
                    
                    do{
                        cout << "Usuario activo (1. Si o 0. No): ";
                        cin >> nuevoActivo;
                        if(nuevoActivo != 1 && nuevoActivo != 0){
                            cout << "Numero incorrecto." << endl;
                        }
                    }while(nuevoActivo != 1 && nuevoActivo != 0);

                    
                    usuario->setActivo(nuevoActivo);
                    
                }

            } else{
                cout << "No se puede modificar el estado de actividad del usuario logado." << endl;
            }


            cout << "Modificar tipo de usuario(estandar o admin) (s/n): ";
            cin >> opcion;
            if(opcion == 's' || opcion == 'S'){

                do{
                    cout << "Tipo de usuario: ";
                    cin >> nuevoTipo;

                    

                }while(nuevoTipo != "estandar" && nuevoTipo != "admin");
                

                usuario->setTipo(nuevoTipo);
                
            }

            cout << GREEN << "Usuario modificado correctamente." << RESET << endl;
        } else{
            cout << "Usuario no encontrado." << endl;
        }
    }

    void Sistema::eliminarContenidoSistema(){

        string titulo;
        titulo = introducirTitulo();
        char confirmacion;


        Contenido* contenido = buscarContenidoTitulo(titulo);

        if(contenido){
            cout << "Contenido encontrado: " << contenido->getTitulo() << endl;
            cout << *contenido << endl;

            cout << "Estas seguro de que eliminar este contenido?(s/n): ";
            cin >> confirmacion;

            if(confirmacion = 's' || confirmacion == 'S'){
                int iterador = -1;
                bool encontrado = false;

                for(int i = 0; i < util_v_contenidos_sistema && !encontrado;i++){
                    if(v_contenidos_sistema[i] == contenido){
                        iterador = i;
                        encontrado = true;
                    }
                }

                if(iterador != -1){
                    //elimino el contenido y muevo el resto
                    delete v_contenidos_sistema[iterador];

                    for(int i = iterador; i < util_v_contenidos_sistema - 1; i++){
                        v_contenidos_sistema[i] = v_contenidos_sistema[i + 1];
                    }
                    v_contenidos_sistema[util_v_contenidos_sistema - 1] = NULL;
                    util_v_contenidos_sistema--;

                    //eliminar valoraciones asociadas
                    for(int i = iterador; i < util_v_valoraciones_sistema; i++){
                        if(v_valoraciones_sistema[i].getContenido() == contenido){
                            for(int j = i; j < util_v_valoraciones_sistema - 1; j++){
                                v_valoraciones_sistema[j] = v_valoraciones_sistema[j + 1];
                            }
                            util_v_valoraciones_sistema--;
                            i--;
                        }
                    }

                    //Nos vamos con los usuarios y las referencias
                    for(int i = 0; i < util_v_usuarios_sistema; i++){
                        Usuario* usuario = v_usuarios_sistema[i];

                        //actualizo los visualizados
                        for(int j = 0; j < usuario->getUtil_v_Contenido_visualizado(); j++){
                            if(usuario->getContenidoVisualizado(j) == contenido){
                                for(int k = j; k < usuario->getUtil_v_Contenido_visualizado() - 1; k++){
                                    usuario->setContenidoVisualizado(k, usuario->getContenidoVisualizado(k + 1));

                                }
                                usuario->setUtil_v_contenido_visualizado(usuario->getUtil_v_Contenido_visualizado() - 1);
                                j--;
                            }
                        }

                        //valorados
                        for(int j = 0; j < usuario->getUtil_v_Contenido_valorado(); j++){
                            if(usuario->getContenidoValorado(j) == contenido){
                                for(int k = j; k < usuario->getUtil_v_Contenido_valorado() - 1; k++){
                                    usuario->setContenidoValorado(k, usuario->getContenidoValorado(k+1));
                                }
                                usuario->setUtil_v_contenido_valorado(usuario->getUtil_v_Contenido_valorado() - 1);
                                j--;
                            }
                        }

                        //me gusta
                        for(int j = 0; j < usuario->getUtil_v_Contenido_mg(); j++){
                            if(usuario->getContenidoMeGusta(j) == contenido){
                                for(int k = j; k < usuario->getUtil_v_Contenido_mg() - 1; k++){
                                    usuario->setContenidoMeGusta(k, usuario->getContenidoMeGusta(k + 1));
                                }
                                usuario->setUtil_v_contenido_mg(usuario->getUtil_v_Contenido_mg() - 1);
                                j--;
                            }
                        }

                        //no me gusta
                        for(int j = 0; j < usuario->getUtil_v_Contenido_nomg(); j++){
                            if(usuario->getContenidoNoMeGusta(j) == contenido){
                                for(int k = j; k < usuario->getUtil_v_Contenido_nomg() - 1; k++){
                                    usuario->setContenidoNoMeGusta(k, usuario->getContenidoNoMeGusta(k + 1));
                                }
                                usuario->setUtil_v_contenido_nomg(usuario->getUtil_v_Contenido_nomg() - 1);
                                j--;
                            }
                        }
                    }

                    recalcularEstadisticas();

                    cout << GREEN << "Contenido eliminado correctamente." << RESET << endl;
                    

                } else{
                    cout << "No se encontro el contenido en el sistema." << endl;
                }

            } else{
                cout << "Operacion cancelada." << endl;
            }
        } else{
            cout << "Contenido no encontrado." << endl;
        }
    }

        void Sistema::eliminarValoracionSistema(){
        int idvaloracion = 0;
        Valoracion* valoracion = NULL;
        int iterador = -1;
        char confirmacion;
        bool encontrado = false;

        // Solicitar el ID de la valoración
        do{
            cout << "Introduzca el id de la valoracion: ";
            cin >> idvaloracion;
        } while(idvaloracion < 0);

        // Buscar la valoración en el sistema
        for(int i = 0; i < util_v_valoraciones_sistema && iterador == -1; i++){
            if(v_valoraciones_sistema[i].get_id_valoracion() == idvaloracion){
                valoracion = &v_valoraciones_sistema[i];
                iterador = i;
            }
        }

        if(valoracion){
            cout << "Valoracion encontrada: " << endl;
            cout << *valoracion << endl;

            cout << "Seguro que quieres eliminar la valoracion?(s/n): ";
            cin >> confirmacion;

            if(confirmacion == 's' || confirmacion == 'S'){
                // Eliminar la referencia a la valoración en los usuarios
                for(int i = 0; i < util_v_usuarios_sistema; i++){
                    Usuario* usuario = v_usuarios_sistema[i];
                    encontrado = false;

                    for(int j = 0; j < usuario->getUtil_v_Contenido_valorado() && !encontrado; j++){
                        if(usuario->getContenidoValorado(j) == valoracion->getContenido()){
                            // Mover elementos para eliminar la referencia
                            for(int k = j; k < usuario->getUtil_v_Contenido_valorado() - 1; k++){
                                usuario->setContenidoValorado(k, usuario->getContenidoValorado(k + 1));
                            }
                            usuario->setUtil_v_contenido_valorado(usuario->getUtil_v_Contenido_valorado() - 1);
                            encontrado = true;
                        }
                    }
                }

                for (int i = iterador; i < util_v_valoraciones_sistema - 1; ++i) {
                    v_valoraciones_sistema[i] = v_valoraciones_sistema[i + 1];
                }
                util_v_valoraciones_sistema--;

                recalcularEstadisticas();

                cout << GREEN << "Valoración eliminada correctamente." << RESET << endl;
            } else {
                cout << "Operación cancelada." << endl;
            }
        } else {
            cout << "No se encontró la valoración en el sistema." << endl;
        }
    }

    void Sistema::eliminarUsuarioSistema(){

        string username;
        cout << "Introduce el user name del suaurio a eliminar: ";
        cin >> username;
        Usuario* usuario = buscarUsuarioPorUserName(username);

        bool usuarioencontrado = false;
        bool continuarEliminacion = true;
        char confirmacion;

        if(usuario){
            if(usuario == usuario_logado){
                cerr << "No se puede eliminar el usuario que esta actualmente logado." << endl;
                continuarEliminacion = false;
            }

            if(continuarEliminacion){

                cout << "Usuario encontrado: " << usuario->getUserName() << endl;

                cout << "Seguro que quieres eliminar el usuario?(s/n): ";
                cin >> confirmacion;

                if(confirmacion == 's' || confirmacion == 'S'){
                    //eliminar valoraciones
                    
                    for(int i = 0; i < util_v_valoraciones_sistema; i++){
                        if(v_valoraciones_sistema[i].get_usuario() == usuario){
                            
                            for(int j = i; j < util_v_valoraciones_sistema - 1;j++){
                                v_valoraciones_sistema[j] = v_valoraciones_sistema[j + 1];
                            }
                            
                            util_v_valoraciones_sistema--;
                            i--;
                        }
                    }

                    //contenidos visualizados
                    for(int i = 0; i < usuario->getUtil_v_Contenido_visualizado(); i++){
                        Contenido* contenido = usuario->getContenidoVisualizado(i);

                        if(contenido != NULL){
                            contenido->setTimesPlayed(contenido->getTimesPlayed() - 1);
                        }
                    }

                    //me gusta
                    for(int i = 0; i < usuario->getUtil_v_Contenido_mg(); i++){
                        Contenido* contenido = usuario->getContenidoMeGusta(i);
                        if(contenido != NULL){
                            contenido->setTimesLiked(contenido->getTimesLiked() - 1);
                        }
                    }

                    //no me gusta
                    for(int i = 0; i < usuario->getUtil_v_Contenido_nomg(); i++){
                        Contenido* contenido = usuario->getContenidoNoMeGusta(i);
                        if(contenido != NULL){
                            contenido->setTimesNotLiked(contenido->getTimesNotLiked() - 1);
                        }
                    }

                    //eliminar usuario
                    int iterador = -1;
                    bool encontrado = false;

                    for(int i = 0; i < util_v_usuarios_sistema && !encontrado; i++){
                        if(v_usuarios_sistema[i] == usuario){
                            iterador = i;
                            encontrado = true;
                        }
                    }

                    if(iterador != -1){
                        delete v_usuarios_sistema[iterador];
                        for(int i = iterador; i < util_v_usuarios_sistema - 1; i++){
                            v_usuarios_sistema[i] = v_usuarios_sistema[i + 1];
                        }
                        v_usuarios_sistema[util_v_usuarios_sistema - 1] = NULL;
                        util_v_usuarios_sistema--;

                        cout << GREEN << "Usuario eliminado correctamente." << RESET << endl;
                    }else {
                        cout << RED << "Error al eliminar el usuario." << RESET << endl;
                    }
                }
                
            } else{
                cerr << "Operacion cancelada." << endl;
            }
        }

    }

    void Sistema::testingHP(Sistema& sistema){
        cout << "Comienza el test de Henry Paul..." << endl;

        bool encontrado = false;
        bool esadmin = false;

        this->login(encontrado, esadmin);

        for(int i = 0; i < 3; i++){
            this->visualizarContenido();
        }

        this->consultarValoraciones();

        this->login(encontrado, esadmin);

        this->visualizarSistema();

        for(int i = 0; i < 3; i++){
            this->eliminarValoracionSistema();
        }

        this->visualizarSistema();

        for(int i = 0; i< 2; i++){
            this->agregarContenidoASistema();
        }

        string tipo;


        cout << "Introduzca el Tipo al que se le desea hacer el ranking (Serie, Pelicula, Documental): ";
        cin >> tipo;
    

        this->generarInformeRankingContenidoPorTipo(tipo);

        for(int i = 0; i < 3; i++){
            this->eliminarUsuarioSistema();
        }

        this->visualizarSistema();

        for(int i = 0; i < 3; i++){
            this->eliminarContenidoSistema();
        }

        this->consultarValoracionContenido();

        this->login(encontrado, esadmin);

        this->visualizarContenido();

        this->login(encontrado, esadmin);

        this->visualizarSistema();

        this->cargarDatosBasicosSistema();

        this->visualizarSistema();

    }

    void Sistema::testingMaria(Sistema& sistema){
        cout << "Comienza el test de Maria..." << endl;

        bool encontrado = false;
        bool esadmin = false;

        cout << CYAN << "Login con admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Añadir 4 contenidos: " << RESET << endl;

        for(int i = 0; i < 4; i++){
            this->agregarContenidoASistema();
        }

        cout << CYAN << "Añadir 4 user: " << RESET << endl;

        for(int i = 0; i < 4; i++){
            this->agregarUsuarioASistema();
        }

        this->visualizarSistema();

        cout << CYAN << "Eliminar 2 contenidos antiguos y 2 recientes: " << RESET << endl;

        for(int i = 0; i < 4; i++){
            this->eliminarContenidoSistema();
        }

        this->visualizarSistema();

        cout << CYAN << "eliminar todos los usuarios: " << RESET << endl;

        for(int i = 0; i < util_v_usuarios_sistema; ++i){
            cout << CYAN << "Usuario a eliminar: " << v_usuarios_sistema[i]->getUserName() << RESET << endl;
        }

        for(int i = 0; i < 19; i++){
            
            this->eliminarUsuarioSistema();
        }

        cout << CYAN << "Buscar cualquier usuario: " << RESET << endl;

        this->buscarUsuarioEnSistema();

        cout << CYAN << "LModificar contraseña ice-man: " << RESET << endl;

        this->modificarUsuarioSistema();

        cout << CYAN << "LConsultar valoraciones de cualquier contenido: " << RESET << endl;

        this->consultarValoracionContenido();

        this->visualizarSistema();

        cout << CYAN << "Ranking de usuario: " << RESET << endl;

        this->generarInformeRankingUsuario();

        cout << CYAN << "Login con admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Regenerar datos: " << RESET << endl;

        this->cargarDatosBasicosSistema();

        this->visualizarSistema();

        cout << CYAN << "Salir: " << RESET << endl;


    }

    void Sistema::testingNatalia(Sistema& sistema){
        cout << "Comienza el test de Natalia..." << endl;

        bool encontrado = false;
        bool esadmin = false;

        cout << CYAN << "Login con admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Consultar valoracion id 0: " << RESET << endl;

        this->consultarValoracionContenido();

        cout << CYAN << "Borrar las valoraciones de antes: " << RESET << endl;

        for(int i = 0; i < 2; i++){
            this->eliminarValoracionSistema();
        }

        cout << CYAN << "Consultar el contenido sin valoraciones: " << RESET << endl;

        this->consultarValoracionContenido();

        cout << CYAN << "Agregar documental: " << RESET << endl;

        this->agregarContenidoASistema();

        cout << CYAN << "Eliminar usuario id6 y id14 e intentar el logado: " << RESET << endl;

        for(int i = 0; i < 3; i++){
            this->eliminarUsuarioSistema();
        }

        cout << CYAN << "Agregar dos usuarios admin/estandar: " << RESET << endl;

        for(int i = 0; i < 2; i++){
            this->agregarUsuarioASistema();
        }

        cout << CYAN << "Login con estandar: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Valorar documental agregado: " << RESET << endl;

        for(int i = 0; i < 2; i++){
            this->visualizarContenido();
        }

        cout << CYAN << "Añadir me gusta a documental agregado: " << RESET << endl;

        this->anadirMeGusta();

        cout << CYAN << "Añadir no me gusta a documental agregado: " << RESET << endl;

        this->anadirNoMeGusta();

        cout << CYAN << "Consultar valoraciones usuario logado: " << RESET << endl;

        this->consultarValoraciones();

        cout << CYAN << "login admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Consultar valoraciones documental agregado: " << RESET << endl;

        this->consultarValoracionContenido();

        cout << CYAN << "modificar capitulos one piece: " << RESET << endl;

        this->modificarContenidoSistema();

        cout << CYAN << "Ver podio de contenidos: " << RESET << endl;

        this->generarInformeRankingContenido();

        cout << CYAN << "Eliminar el podio: " << RESET << endl;

        for(int i = 0; i < 3; i++){
            this->eliminarContenidoSistema();
        }

        cout << CYAN << "Ver el podio de contenidos: " << RESET << endl;

        this->generarInformeRankingContenido();

        this->visualizarSistema();

        cout << CYAN << "Recargar datos basicos: " << RESET << endl;

        this->cargarDatosBasicosSistema();

        this->visualizarSistema();

        cout << CYAN << "Salir: " << RESET << endl;

    }

    void Sistema::testingPablo(Sistema& sistema){
        cout << "Comienza el test de Pablo..." << endl;

        bool encontrado = false;
        bool esadmin = false;

        cout << CYAN << "Login con admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Borrar todos los contenidos: " << RESET << endl;

        for(int i = 0; i < 11; i++){
            this->eliminarContenidoSistema();
        }

        cout << CYAN << "Ranking general contenido: " << RESET << endl;

        this->generarInformeRankingContenido();

        cout << CYAN << "Ranking general contenido por tipo: " << RESET << endl;

        string tipo;

        do{
            cout << "Introduzca el Tipo al que se le desea hacer el ranking (Serie, Pelicula, Documental): ";
            cin >> tipo;
            if (tipo != "Serie" && tipo != "Pelicula" && tipo != "Documental")
            {
                cout << "Tipo de contenido invalido, por favor intentelo de nuevo." << endl;
            }
        }while(tipo != "Serie" && tipo != "Pelicula" && tipo != "Documental");
            
        this->generarInformeRankingContenidoPorTipo(tipo);

        cout << CYAN << "Ranking general usuarios: " << RESET << endl;

        this->generarInformeRankingUsuario();

        cout << CYAN << "Intentar borrar contenido: " << RESET << endl;

        this->eliminarContenidoSistema();

        cout << CYAN << "Intentar buscar contenido: " << RESET << endl;

        string titulo;
        Contenido* contenido;
        titulo = introducirTitulo();
        contenido = this->buscarContenidoTitulo(titulo);
        if(contenido != NULL){
            this->getUsuarioLogado()->imprimirContenidosBuscados();
        } else{
            cout << "Contenido no encontrado." << endl;
        }
        

        cout << CYAN << "Intentar modificar datos de contenido: " << RESET << endl;

        this->modificarContenidoSistema();

        cout << CYAN << "Cristo rating de un contenido: " << RESET << endl;

        cout << "Introduzca el titulo del contenido para calcular el cristoflixRating." << endl;
        titulo = introducirTitulo();
        contenido = this->buscarContenidoTitulo(titulo);
        if(contenido != NULL){
            this->mostrarRating(contenido);
        } else{
            cout << "Contenido no encontrado." << endl;
        }
        

        cout << CYAN << "Consultar valoraciones contenido: " << RESET << endl;

        this->consultarValoracionContenido();

        cout << CYAN << "Intentar eliminar valoracion: " << RESET << endl;

        this->eliminarValoracionSistema();

        cout << CYAN << "Iniciar sesion con estandar: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Dar me gusta a un contenido: " << RESET << endl;

        this->anadirMeGusta();

        cout << CYAN << "Dar no me gusta a un contenido: " << RESET << endl;

        this->anadirNoMeGusta();

        cout << CYAN << "Visualizar y valorar un contenido: " << RESET << endl;

        this->visualizarContenido();


        cout << CYAN << "Consultar valoraciones usuario: " << RESET << endl;

        this->consultarValoraciones();

        cout << CYAN << "Iniciar sesion con admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Imprimir sistema: " << RESET << endl;

        this->visualizarSistema();

        cout << CYAN << "Agregar un contenido: " << RESET << endl;

        this->agregarContenidoASistema();

        cout << CYAN << "Desactivar contenido: " << RESET << endl;

        this->modificarContenidoSistema();

        cout << CYAN << "Iniciar sesion con estandar: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Dar me gusta a un contenido: " << RESET << endl;

        this->anadirMeGusta();

        cout << CYAN << "Dar no me gusta a un contenido: " << RESET << endl;

        this->anadirNoMeGusta();

        cout << CYAN << "Visualizar y valorar un contenido: " << RESET << endl;

        this->visualizarContenido();

        cout << CYAN << "Iniciar sesion con admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Top 1 de contenidos: " << RESET << endl;

        this->generarInformeRankingContenido();

        cout << CYAN << "Ranking usuarios: " << RESET << endl;

        this->generarInformeRankingUsuario();

        cout << CYAN << "Cargar datos basicos del sistema: " << RESET << endl;

        this->cargarDatosBasicosSistema();

        cout << CYAN << "Borrar todos los usuarios: " << RESET << endl;

        for(int i = 0; i < util_v_usuarios_sistema; ++i){
            cout << CYAN << "Usuario a eliminar: " << v_usuarios_sistema[i]->getUserName() << RESET << endl;
        }

        for(int i = 0; i < 14; i++){
            this->eliminarUsuarioSistema();
        }

        cout << CYAN << "Intentar desactivarte: " << RESET << endl;

        this->modificarUsuarioSistema();

        cout << CYAN << "Ranking usuarios: " << RESET << endl;

        this->generarInformeRankingUsuario();

        cout << CYAN << "Ranking contenidos: " << RESET << endl;

        this->generarInformeRankingContenido();

        cout << CYAN << "Imprimir sistema: " << RESET << endl;

        this->visualizarSistema();

        cout << CYAN << "Crear usuario estandar: " << RESET << endl;

        this->agregarUsuarioASistema();

        cout << CYAN << "Desactivar usuario estandar creado: " << RESET << endl;

        this->modificarUsuarioSistema();

        cout << CYAN << "Comprobar a hacer login con el nuevo: " << RESET << endl;
    
        this->login(encontrado, esadmin);

        cout << CYAN << "Activar usuario: " << RESET << endl;

        this->modificarUsuarioSistema();

        cout << CYAN << "Iniciar sesion con el estandar: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Visualizar mismo contenido 7 veces: " << RESET << endl;

        for(int i = 0; i < 7; i++){
            this->visualizarContenido();
        }

        cout << CYAN << "Dar mg a un contenido: " << RESET << endl;

        this->anadirMeGusta();

        cout << CYAN << "Dar no mg a ese mismo contenido: " << RESET << endl;

        this->anadirNoMeGusta();

        cout << CYAN << "Comprobar el cambio: " << RESET << endl;

        this->consultarValoraciones();

        cout << CYAN << "Iniciar sesion con admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Eliminar nuevo usuario: " << RESET << endl;

        this->eliminarUsuarioSistema();

        cin.get();

        cout << CYAN << "Visualizar sistema: " << RESET << endl;
        this->visualizarSistema();

        cout << CYAN << "Agregar usuario admin: " << RESET << endl;

        this->agregarUsuarioASistema();

        cout << CYAN << "Iniciar sesion con nuevo admin: " << RESET << endl;

        this->login(encontrado, esadmin);

        cout << CYAN << "Borrar a ice-man: " << RESET << endl;

        this->eliminarUsuarioSistema();

        cout << CYAN << "Visualizar sistema: " << RESET << endl;
        this->visualizarSistema();

        cin.get();

        cout << CYAN << "Cargar datos sistema: " << RESET << endl;
        this->cargarDatosBasicosSistema();

        cout << CYAN << "Visualizar sistema: " << RESET << endl;
        this->visualizarSistema();

        cout << CYAN << "Salir: " << RESET << endl;


    }


    void Sistema::eliminarTodoContenidoSistemaPorTipo(){
        string tipo;
        
        tipo = pedirTipoContenido();

        cout << "DEBUG: Tipo de contenido a eliminar: " << tipo << endl;

        if(tipo == "Serie"){
            eliminarSerie();

        } else if(tipo == "Pelicula"){
            eliminarPelicula();

        }else if(tipo == "Documental"){
            eliminarDocumental();

        }
        


        recalcularEstadisticas();


    }


    string Sistema::pedirTipoContenido(){

        string tipo;

        do{
            cout << "Introduzca el Tipo que desea eliminar(Serie, Pelicula, Documental): ";
            cin >> tipo;
            if (tipo != "Serie" && tipo != "Pelicula" && tipo != "Documental")
            {
                cout << "Tipo de contenido invalido, por favor intentelo de nuevo." << endl;
            }
        }while(tipo != "Serie" && tipo != "Pelicula" && tipo != "Documental");

        return tipo;

    }

    void Sistema::eliminarContenido(Contenido* contenido, int it){

        cout << "DEBUG: Eliminando contenido en índice: " << it << endl;

        //ELIMINO VALORACIONES
        eliminarValoracionesAsociadas(contenido);
        //ELIMINO REFERENCIAS DE USUARIO
        eliminarReferenciasUsuario(contenido);
        //ELIMINO CONTENIDO
        delete v_contenidos_sistema[it];

        for(int i = it; i < util_v_contenidos_sistema - 1; i++){
            v_contenidos_sistema[i] = v_contenidos_sistema[i + 1];
        }
        v_contenidos_sistema[util_v_contenidos_sistema - 1] = NULL;
        util_v_contenidos_sistema--;

        cout << "DEBUG: Contenido eliminado correctamente." << endl;

    }

    void Sistema::eliminarSerie(){

        cout << "DEBUG: Iniciando eliminación de series..." << endl;

        for(int i = 0; i < util_v_contenidos_sistema; i++){
            if(dynamic_cast<Serie*>(v_contenidos_sistema[i])){

                cout << "DEBUG: Eliminando serie: " << v_contenidos_sistema[i]->getTitulo() << endl;
                eliminarContenido(v_contenidos_sistema[i], i);

                i--;

            }
        }

        cout << "DEBUG: Series eliminadas." << endl;
    }

    void Sistema::eliminarPelicula(){

        cout << "DEBUG: Iniciando eliminación de películas..." << endl;

        for(int i = 0; i < util_v_contenidos_sistema; i++){
            if(dynamic_cast<Pelicula*>(v_contenidos_sistema[i])){
                cout << "DEBUG: Eliminando película: " << v_contenidos_sistema[i]->getTitulo() << endl;
                eliminarContenido(v_contenidos_sistema[i], i);

                i--;

            }
        }

        cout << "DEBUG: Películas eliminadas." << endl;
    }

    void Sistema::eliminarDocumental(){

        cout << "DEBUG: Iniciando eliminación de documentales..." << endl;

        for(int i = 0; i < util_v_contenidos_sistema; i++){
            if(dynamic_cast<Documental*>(v_contenidos_sistema[i])){

                cout << "DEBUG: Eliminando documental: " << v_contenidos_sistema[i]->getTitulo() << endl;
                eliminarContenido(v_contenidos_sistema[i], i);

                i--;

            }
        }

        cout << "DEBUG: Documentales eliminados." << endl;
    }

    void Sistema::eliminarValoracionesAsociadas(Contenido* contenido){

        cout << "DEBUG: Eliminando valoraciones asociadas..." << endl;

        for(int i = 0; i < util_v_valoraciones_sistema; i++){
            if(v_valoraciones_sistema[i].getContenido() == contenido){
                for(int j = i; j < util_v_valoraciones_sistema - 1; j++){
                    v_valoraciones_sistema[j] = v_valoraciones_sistema[j + 1];
                }
                util_v_valoraciones_sistema--;
                i--;
            }
        }

        cout << "DEBUG: Valoraciones asociadas eliminadas." << endl;
    }

    void Sistema::eliminarReferenciasUsuario(Contenido* contenido){
        cout << "DEBUG: Eliminando referencias de usuario..." << endl;
        for(int i = 0; i < util_v_usuarios_sistema; i++){
            Usuario* usuario = v_usuarios_sistema[i];

            // VISUALIZADO
            for(int j = 0; j < usuario->getUtil_v_Contenido_visualizado(); ){
                if(usuario->getContenidoVisualizado(j) == contenido){
                    for(int k = j; k < usuario->getUtil_v_Contenido_visualizado() - 1; k++){
                        usuario->setContenidoVisualizado(k, usuario->getContenidoVisualizado(k + 1));
                    }
                    usuario->setUtil_v_contenido_visualizado(usuario->getUtil_v_Contenido_visualizado() - 1);
                    cout << "DEBUG: Eliminada referencia en visualizado para usuario " << usuario->getUserName() << endl;
                } else {
                    j++;
                }
            }
            
            // VALORADO
            for(int j = 0; j < usuario->getUtil_v_Contenido_valorado(); ){
                if(usuario->getContenidoValorado(j) == contenido){
                    for(int k = j; k < usuario->getUtil_v_Contenido_valorado() - 1; k++){
                        usuario->setContenidoValorado(k, usuario->getContenidoValorado(k + 1));
                    }
                    usuario->setUtil_v_contenido_valorado(usuario->getUtil_v_Contenido_valorado() - 1);
                    cout << "DEBUG: Eliminada referencia en valorado para usuario " << usuario->getUserName() << endl;
                } else {
                    j++;
                }
            }
            
            // ME GUSTA
            for(int j = 0; j < usuario->getUtil_v_Contenido_mg(); ){
                if(usuario->getContenidoMeGusta(j) == contenido){
                    for(int k = j; k < usuario->getUtil_v_Contenido_mg() - 1; k++){
                        usuario->setContenidoMeGusta(k, usuario->getContenidoMeGusta(k + 1));
                    }
                    usuario->setUtil_v_contenido_mg(usuario->getUtil_v_Contenido_mg() - 1);
                    cout << "DEBUG: Eliminada referencia en me gusta para usuario " << usuario->getUserName() << endl;
                } else {
                    j++;
                }
            }
            
            // NO ME GUSTA
            for(int j = 0; j < usuario->getUtil_v_Contenido_nomg(); ){
                if(usuario->getContenidoNoMeGusta(j) == contenido){
                    for(int k = j; k < usuario->getUtil_v_Contenido_nomg() - 1; k++){
                        usuario->setContenidoNoMeGusta(k, usuario->getContenidoNoMeGusta(k + 1));
                    }
                    usuario->setUtil_v_contenido_nomg(usuario->getUtil_v_Contenido_nomg() - 1);
                    cout << "DEBUG: Eliminada referencia en no me gusta para usuario " << usuario->getUserName() << endl;
                } else {
                    j++;
                }
            }
        }
        cout << "DEBUG: Referencias de usuario eliminadas." << endl;
    }










