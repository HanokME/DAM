#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include "usuario.h"
#include "colors.h"
const bool DEBUG = false;
using namespace std;

        Usuario::Usuario(){
                this->idUsuario = 0;
                this->user_name = "";
                this->password = "";
                this->nombre = "";
                this->apellido1 = "";
                this->apellido2 = "";
                this->fechaNacimiento = Fecha();
                this->activo = false;
                this->tipo = "";

                dim_v_contenido_visualizado = 1; 
                v_contenido_visualizado = new Contenido*[dim_v_contenido_visualizado];
                util_v_contenido_visualizado = 0;

                dim_v_contenido_mg = 1;
                v_contenido_mg = new Contenido*[dim_v_contenido_mg];
                util_v_contenido_mg = 0;

                dim_v_contenido_nomg = 10; 
                v_contenido_nomg = new Contenido*[dim_v_contenido_nomg];
                util_v_contenido_nomg = 0;

                dim_v_contenido_valorado = 1;
                v_contenido_valorado = new Contenido*[dim_v_contenido_valorado];
                util_v_contenido_valorado = 0;

                dim_v_contenido_buscado = 1;
                v_contenido_buscado = new Contenido*[dim_v_contenido_buscado];
                util_v_contenido_buscado = 0;

                dim_v_contenido_buscado_auxiliar = 1;
                v_contenido_buscado_auxiliar = new Contenido*[dim_v_contenido_buscado_auxiliar];
                util_v_contenido_buscado_auxiliar = 0;

                if(DEBUG){
                    cout << CYAN << "Se ha usado el constructor por defecto de Usuario" << RESET << endl;
                }


        }

        Usuario::Usuario(const Usuario &u){
                this->idUsuario = u.idUsuario;
                this->user_name = u.user_name;
                this->password =  u.password;
                this->nombre = u.nombre;
                this->apellido1 = u.apellido1;
                this->apellido2 = u.apellido2;
                this->fechaNacimiento = u.fechaNacimiento;
                this->activo = u.activo;
                this->tipo = u.tipo;
                
                asignarVector(v_contenido_visualizado, u.v_contenido_visualizado, u.util_v_contenido_visualizado, u.dim_v_contenido_visualizado);
                this->util_v_contenido_visualizado = u.util_v_contenido_visualizado;
                this->dim_v_contenido_visualizado = u.dim_v_contenido_visualizado;

                asignarVector(v_contenido_mg, u.v_contenido_mg, u.util_v_contenido_mg, u.dim_v_contenido_mg);
                this->util_v_contenido_mg = u.util_v_contenido_mg;
                this->dim_v_contenido_mg = u.dim_v_contenido_mg;

                asignarVector(v_contenido_nomg, u.v_contenido_nomg, u.util_v_contenido_nomg, u.dim_v_contenido_nomg);
                this->util_v_contenido_nomg = u.util_v_contenido_nomg;
                this->dim_v_contenido_nomg = u.dim_v_contenido_nomg;

                asignarVector(v_contenido_valorado, u.v_contenido_valorado, u.util_v_contenido_valorado, u.dim_v_contenido_valorado);
                this->util_v_contenido_valorado = u.util_v_contenido_valorado;
                this->dim_v_contenido_valorado = u.dim_v_contenido_valorado;

                asignarVector(v_contenido_buscado, u.v_contenido_buscado, u.util_v_contenido_buscado, u.dim_v_contenido_buscado);
                this->util_v_contenido_buscado = u.util_v_contenido_buscado;
                this->dim_v_contenido_buscado = u.dim_v_contenido_buscado;

                if(DEBUG){
                    cout << CYAN << "Se ha usado el constructor por copia de Usuario" << RESET << endl;
                }
        }

        Usuario::Usuario(int idUsuario, string user_name, string password, string nombre, string apellido1, string apellido2, Fecha fechaNacimiento, bool activo, string tipo){
                this->idUsuario = idUsuario;
                this->user_name = user_name;
                this->password =  password;
                this->nombre = nombre;
                this->apellido1 = apellido1;
                this->apellido2 = apellido2;
                this->fechaNacimiento = fechaNacimiento;
                this->activo = activo;
                this->tipo = tipo;

                dim_v_contenido_visualizado = 1;
                v_contenido_visualizado = new Contenido*[dim_v_contenido_visualizado];
                util_v_contenido_visualizado = 0;

                dim_v_contenido_mg = 1;
                v_contenido_mg = new Contenido*[dim_v_contenido_mg];
                util_v_contenido_mg = 0;

                dim_v_contenido_nomg = 1;
                v_contenido_nomg = new Contenido*[dim_v_contenido_nomg];
                util_v_contenido_nomg = 0;

                dim_v_contenido_valorado = 1;
                v_contenido_valorado = new Contenido*[dim_v_contenido_valorado];
                util_v_contenido_valorado = 0;

                dim_v_contenido_buscado = 1;
                v_contenido_buscado = new Contenido*[dim_v_contenido_buscado];
                util_v_contenido_buscado = 0;

                dim_v_contenido_buscado_auxiliar = 1;
                v_contenido_buscado_auxiliar = new Contenido*[dim_v_contenido_buscado_auxiliar];
                util_v_contenido_buscado_auxiliar = 0;

                if(DEBUG){
                    cout << CYAN << "Se ha usado el constructor por parametros de Usuario" << RESET << endl;
                }
        }

        Usuario::~Usuario(){
                if(v_contenido_visualizado!= NULL){

                        if(DEBUG){
                                cout << CYAN << "Destruyendo el vector de contenido visualizado" << RESET << endl;
                        }
                        delete[] v_contenido_visualizado;
                        v_contenido_visualizado = NULL;
                        if(DEBUG){
                                cout << CYAN << "Vector de contenido visualizado borrado" << RESET << endl;
                        }
                }
                if(v_contenido_mg!= NULL){
                        if(DEBUG){
                                cout << CYAN << "Destruyendo el vector de contenido mg" << RESET << endl;
                        }
                        delete[] v_contenido_mg;
                        v_contenido_mg = NULL;
                        if(DEBUG){
                                cout << CYAN << "Vector de contenido mg borrado" << RESET << endl;
                        }
                }
                if(v_contenido_nomg!= NULL){
                        if(DEBUG){
                                cout << CYAN << "Destruyendo el vector de contenido nomg" << RESET << endl;
                        }
                        delete[] v_contenido_nomg;
                        v_contenido_nomg = NULL;
                        if(DEBUG){
                                cout << CYAN << "Vector de contenido nomg borrado" << RESET << endl;
                        }
                }
                if(v_contenido_valorado!= NULL){
                        if(DEBUG){
                                cout << CYAN << "Destruyendo el vector de contenido valorado" << RESET << endl;
                        }
                        delete[] v_contenido_valorado;
                        v_contenido_valorado = NULL;
                        if(DEBUG){
                                cout << CYAN << "Vector de contenido valorado borrado" << RESET << endl;
                        }
                }
                if(v_contenido_buscado!= NULL){
                        if(DEBUG){
                                cout << CYAN << "Destruyendo el vector de contenido buscado" << RESET << endl;
                        }
                        delete[] v_contenido_buscado;
                        v_contenido_buscado = NULL;
                        if(DEBUG){
                                cout << CYAN << "Vector de contenido buscado borrado" << RESET << endl;
                        }
                }
                if(v_contenido_buscado_auxiliar!= NULL){
                        if(DEBUG){
                                cout << CYAN << "Destruyendo el vector de contenido buscado_auxiliar" << RESET << endl;
                        }
                        delete[] v_contenido_buscado_auxiliar;
                        v_contenido_buscado_auxiliar = NULL;
                        if(DEBUG){
                                cout << CYAN << "Vector de contenido buscado auxiliar borrado" << RESET << endl;
                        }
                }
        }

        void Usuario::setIdUsuario(int idUsuario){
                if(idUsuario < 0){
                        cerr << RED << "El ID de usuario no puede ser menor que 0" << RESET << endl;
                } else{
                        this->idUsuario = idUsuario;
                }
        }

        int Usuario::getIdUsuario()const{
                return this->idUsuario;
        }

        void Usuario::setUserName(string user_name){
                this->user_name = user_name;
        }

        string Usuario::getUserName()const{
                return this->user_name;
        }

        void Usuario::setPassword(string password){
                this->password =  password;
        }

        string Usuario::getPassword()const{
                return this->password;
        }

        void Usuario::setNombre(string nombre){
                this->nombre = nombre;
        }

        string Usuario::getNombre()const{
                return this->nombre;
        }

        void Usuario::setApellido1(string apellido1){
                this->apellido1 = apellido1;
        }

        string Usuario::getApellido1()const{
                return this->apellido1;
        }

        void Usuario::setApellido2(string apellido2){
                this->apellido2 = apellido2;
        }

        string Usuario::getApellido2()const{
                return this->apellido2;
        }

        Fecha Usuario::setFechaNacimiento(int dia, int mes, int anio){
                fechaNacimiento.setFecha(dia, mes, anio);
                return this->fechaNacimiento;
        }

        Fecha Usuario::getFechaNacimiento()const{
                return this->fechaNacimiento;
        }

        void Usuario::setActivo(bool activo){
                this->activo = activo;
        }

        bool Usuario::getActivo()const{
                return this->activo;
        }

        void Usuario::setTipo(string tipo){
                this->tipo = tipo;
        }
        string Usuario::getTipo()const{
                return this->tipo;
        }

        void Usuario::setDatosUsuarios(int idUsuario, string user_name, string password, string nombre, string apellido1, string apellido2, Fecha fechaNacimiento, bool activo, string tipo){
                this->setIdUsuario(idUsuario);
                this->setUserName(user_name);
                this->setPassword(password);
                this->setNombre(nombre);
                this->setApellido1(apellido1);
                this->setApellido2(apellido2);
                this->setFechaNacimiento(fechaNacimiento.getDia(), fechaNacimiento.getMes(), fechaNacimiento.getAnio());
                this->setActivo(activo); 
                this->setTipo(tipo);
        }

        void Usuario::resize(Contenido** &vector, int &util, int &dim, int nuevaCapacidad){
                if(nuevaCapacidad < 1){
                        cerr << RED << "La nueva capacidad no puede ser menor que 1" << RESET << endl;
                } else{
                        Contenido** aux = new Contenido*[nuevaCapacidad];
                        for(int i = 0; i < util; i++){
                                aux[i] = vector[i];
                        }
                        delete[] vector;
                        vector = aux;
                        dim = nuevaCapacidad;
                }
        }

        void Usuario::insertarContenidoEnVectorContenidosVisualizados(Contenido *unContenido){
                if(util_v_contenido_visualizado == dim_v_contenido_visualizado){
                        resize(v_contenido_visualizado, util_v_contenido_visualizado, dim_v_contenido_visualizado, dim_v_contenido_visualizado * 2);
                }
                v_contenido_visualizado[util_v_contenido_visualizado] = unContenido;
                util_v_contenido_visualizado++;
        }

        void Usuario::insertarContenidoEnVectorContenidoMg(Contenido *unContenido){
                if(util_v_contenido_mg == dim_v_contenido_mg){
                        resize(v_contenido_mg, util_v_contenido_mg, dim_v_contenido_mg, dim_v_contenido_mg * 2);
                }
                v_contenido_mg[util_v_contenido_mg] = unContenido;
                util_v_contenido_mg++;
        }

        void Usuario::insertarContenidoEnVectorContenidoNoMg(Contenido *unContenido){
                if(util_v_contenido_nomg == dim_v_contenido_nomg){
                        resize(v_contenido_nomg, util_v_contenido_nomg, dim_v_contenido_nomg, dim_v_contenido_nomg * 2);
                }
                v_contenido_nomg[util_v_contenido_nomg] = unContenido;
                util_v_contenido_nomg++;
        }

        void Usuario::insertarContenidoEnVectorContenidoValorado(Contenido *unContenido){
                if(util_v_contenido_valorado == dim_v_contenido_valorado){
                        resize(v_contenido_valorado, util_v_contenido_valorado, dim_v_contenido_valorado, dim_v_contenido_valorado * 2);
                }
                v_contenido_valorado[util_v_contenido_valorado] = unContenido;
                util_v_contenido_valorado++;
        }

        void Usuario::insertarContenidoEnVectorContenidoBuscado(Contenido* unContenido){
                if(util_v_contenido_buscado == dim_v_contenido_buscado){
                        resize(v_contenido_buscado, util_v_contenido_buscado, dim_v_contenido_buscado, dim_v_contenido_buscado * 2);
                }
                v_contenido_buscado[util_v_contenido_buscado] = unContenido;
                util_v_contenido_buscado++;
                
        }

        void Usuario::setUtil_v_contenido_visualizado(int util_v){
                this->util_v_contenido_visualizado = util_v;
        }

        int Usuario::getUtil_v_Contenido_visualizado(){
                return this->util_v_contenido_visualizado;
        }

        void Usuario::setDim_v_contenido_visualizado(int dim_v){
                this->dim_v_contenido_visualizado = dim_v;
        }

        int Usuario::getDim_v_Contenido_visualizado(){
                return this->dim_v_contenido_visualizado;
        }

        void Usuario::setUtil_v_contenido_mg(int util_v){
                this->util_v_contenido_mg = util_v;
        }

        int Usuario::getUtil_v_Contenido_mg(){
                return this->util_v_contenido_mg;
        }

        void Usuario::setDim_v_contenido_mg(int dim_v){
                this->dim_v_contenido_mg = dim_v;
        }

        int Usuario::getDim_v_Contenido_mg(){
                return this->dim_v_contenido_mg;
        }

        void Usuario::setUtil_v_contenido_nomg(int util_v){
                this->util_v_contenido_nomg = util_v;
        }

        int Usuario::getUtil_v_Contenido_nomg(){
                return this->util_v_contenido_nomg;
        }

        void Usuario::setDim_v_contenido_nomg(int dim_v){
                this->dim_v_contenido_nomg = dim_v;
        }

        int Usuario::getDim_v_Contenido_nomg(){
                return this->dim_v_contenido_nomg;
        }

        void Usuario::setUtil_v_contenido_valorado(int util_v){
                this->util_v_contenido_valorado = util_v;
        }

        int Usuario::getUtil_v_Contenido_valorado(){
                return this->util_v_contenido_valorado;
        }

        void Usuario::setDim_v_contenido_valorado(int dim_v){
                this->dim_v_contenido_valorado = dim_v;
        }

        int Usuario::getDim_v_Contenido_valorado(){
                return this->dim_v_contenido_valorado;
        }

        void Usuario::asignarVector(Contenido**& destino, Contenido** origen, int utilOrigen, int dimOrigen){
                if(dimOrigen < 1){
                        cerr << RED << "La capacidad no puede ser menor que 1" << RESET << endl;
                } else{
                        delete[] destino;
                        destino = new Contenido*[dimOrigen];
                        for(int i = 0; i < utilOrigen; i++){
                                destino[i] = origen[i];
                        }
                }

        }

        void Usuario::printVector(Contenido** vector, int util)const{
                for(int i = 0; i < util; i++){
                        cout << *vector[i] << endl;
                }
        }

        Usuario& Usuario::operator=(const Usuario &u){
                if(this!= &u){
                        this->idUsuario = u.idUsuario;
                        this->user_name = u.user_name;
                        this->password =  u.password;
                        this->nombre = u.nombre;
                        this->apellido1 = u.apellido1;
                        this->apellido2 = u.apellido2;
                        this->fechaNacimiento = u.fechaNacimiento;
                        this->activo = u.activo;
                        this->tipo = u.tipo;
                        
                        asignarVector(v_contenido_visualizado, v_contenido_visualizado, util_v_contenido_visualizado, dim_v_contenido_visualizado);
                        this->util_v_contenido_visualizado = u.util_v_contenido_visualizado;
                        this->dim_v_contenido_visualizado = u.dim_v_contenido_visualizado;
                        
                        asignarVector(v_contenido_mg, v_contenido_mg, util_v_contenido_mg, dim_v_contenido_mg);
                        this->util_v_contenido_mg = util_v_contenido_mg;
                        this->dim_v_contenido_mg = dim_v_contenido_mg;

                        asignarVector(v_contenido_valorado, v_contenido_valorado, util_v_contenido_valorado, dim_v_contenido_valorado);
                        this->util_v_contenido_valorado = util_v_contenido_valorado;
                        this->dim_v_contenido_valorado = u.dim_v_contenido_valorado;
                }
                return *this;
        }

        ostream& operator<<(ostream &flujo, const Usuario &p){
                flujo << "| " << ORANGE << "ID de Usuario: " << RESET << p.getIdUsuario() << endl;
                flujo << "| " << ORANGE << "Nombre de Usuario: " << RESET << p.getUserName() << endl;
                flujo << "| " << ORANGE << "Nombre: " << RESET << p.getNombre() << endl;
                flujo << "| " << ORANGE << "Apellidos: " << RESET << p.getApellido1() << " " << p.getApellido2() << endl;
                flujo << "| " << ORANGE << "Fecha de Nacimiento: " << RESET << p.getFechaNacimiento() << endl;
                flujo << "| " << ORANGE << "Usuario activo: " << RESET << p.getActivo() << endl;
                flujo << "| " << ORANGE << "Tipo de usuario: " << RESET << p.getTipo() << endl;
                
                // cout << "Contenidos visualizados: " << endl;
                // p.printVector(p.v_contenido_visualizado, p.util_v_contenido_visualizado);

                // cout << "Contenidos marcados como favoritos: " << endl;
                // p.printVector(p.v_contenido_mg, p.util_v_contenido_mg);

                // cout << "Contenidos marcados como no me gusta: " << endl;
                // p.printVector(p.v_contenido_nomg, p.util_v_contenido_nomg);

                // cout << "Contenidos valorados: " << endl;
                // p.printVector(p.v_contenido_valorado, p.util_v_contenido_valorado);

                // cout << "Contenidos buscados: " << endl;
                // p.printVector(p.v_contenido_buscado, p.util_v_contenido_buscado);

                return flujo;
        }

        void Usuario::imprimirContenidosBuscados()const{
                cout << "Contenidos buscados totales: " << endl;
                for(int i = 0; i < util_v_contenido_buscado; i++){
                        cout << *v_contenido_buscado[i] << endl;
                }
        }


        void Usuario::limpiarVectorContenidoBuscado() {

                util_v_contenido_buscado = 0;
        }


        void Usuario::imprimirContenidosVisualizados()const{
                cout << "Contenidos Visualizados: " << endl;
                for(int i = 0; i < util_v_contenido_visualizado; i++){
                        cout << *v_contenido_visualizado[i] << endl;
                }
        }

        void Usuario::imprimirContenidosValorados()const{
                cout << "Contenidos valorados: " << endl;
                for(int i = 0; i < util_v_contenido_valorado; i++){
                        cout << *v_contenido_valorado[i] << endl;
                }
        }

        Contenido* Usuario::getContenidoVisualizado(int i){
                if(i >= 0 && i < util_v_contenido_visualizado){
                        return v_contenido_visualizado[i];
                }
                return NULL;
        }

        void Usuario::setContenidoValorado(int i, Contenido* contenido){
                if(i >= 0 && i < util_v_contenido_valorado){
                        v_contenido_valorado[i] = contenido;
                }
        }

        void Usuario::setContenidoVisualizado(int i, Contenido* contenido){
                if(i >= 0 && i < util_v_contenido_visualizado){
                        v_contenido_visualizado[i] = contenido;
                }
        }

        Contenido* Usuario::getContenidoValorado(int i)const{
                if(i >= 0 && i < util_v_contenido_valorado){
                        return v_contenido_valorado[i];
                }
                return NULL;
        }


        Contenido* Usuario::getContenidoMeGusta(int i){
                if(i >= 0 && i < util_v_contenido_mg){
                        return v_contenido_mg[i];
                }
                return NULL;
        }

        void Usuario::setContenidoMeGusta(int i, Contenido* contenido){
                if(i >= 0 && i < util_v_contenido_mg){
                        v_contenido_mg[i] = contenido;
                }
        }

        Contenido* Usuario::getContenidoNoMeGusta(int i){
                if(i >= 0 && i < util_v_contenido_nomg){
                        return v_contenido_nomg[i];
                }
                return NULL;
        }

        void Usuario::setContenidoNoMeGusta(int i, Contenido* contenido){
                if(i >= 0 && i < util_v_contenido_nomg){
                        v_contenido_nomg[i] = contenido;
                }
        }

 

        

        