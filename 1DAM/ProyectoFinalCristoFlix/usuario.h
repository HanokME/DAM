#include <iostream>
#include <iomanip>
#include <string.h>
#include "contenido.h"
using namespace std;


class Usuario{

    private:
        int idUsuario;
        string user_name;
        string password;
        string nombre;
        string apellido1;
        string apellido2;
        Fecha fechaNacimiento;
        bool activo;
        string tipo;

        Contenido** v_contenido_visualizado;
        int util_v_contenido_visualizado;
        int dim_v_contenido_visualizado;

        Contenido** v_contenido_mg;
        int util_v_contenido_mg;
        int dim_v_contenido_mg;

        Contenido** v_contenido_nomg;
        int util_v_contenido_nomg;
        int dim_v_contenido_nomg;

        Contenido** v_contenido_valorado;
        int util_v_contenido_valorado;
        int dim_v_contenido_valorado;

        Contenido** v_contenido_buscado;
        int util_v_contenido_buscado;
        int dim_v_contenido_buscado;

        Contenido** v_contenido_buscado_auxiliar;
        int util_v_contenido_buscado_auxiliar;
        int dim_v_contenido_buscado_auxiliar;




    public:

        Usuario();

        Usuario(const Usuario &u);

        Usuario(int idUsuario, string user_name, string password, string nombre, string apellido1, string apellido2, Fecha fechaNacimiento, bool activo, string tipo);

        ~Usuario();

        void setIdUsuario(int idUsuario);

        int getIdUsuario()const;

        void setUserName(string user_name);

        string getUserName()const;

        void setPassword(string password);

        string getPassword()const;

        void setNombre(string nombre);

        string getNombre()const;

        void setApellido1(string apellido1);

        string getApellido1()const;

        void setApellido2(string apellido2);

        string getApellido2()const;

        Fecha setFechaNacimiento(int dia, int mes, int anio);

        Fecha getFechaNacimiento()const;

        void setActivo(bool activo);

        bool getActivo()const;

        void setTipo(string tipo);

        string getTipo()const;

        void setDatosUsuarios(int idUsuario, string user_name, string password, string nombre, string apellido1, string apellido2, Fecha fechaNacimiento, bool activo, string tipo);

        void insertarContenidoEnVectorContenidosVisualizados(Contenido *unContenido);

        void setUtil_v_contenido_visualizado(int util_v);

        int getUtil_v_Contenido_visualizado();

        void setDim_v_contenido_visualizado(int dim_v);

        int getDim_v_Contenido_visualizado();

        void insertarContenidoEnVectorContenidoMg(Contenido *unContenido);

        void setUtil_v_contenido_mg(int util_v);

        int getUtil_v_Contenido_mg();

        void setDim_v_contenido_mg(int dim_v);

        int getDim_v_Contenido_mg();

        void insertarContenidoEnVectorContenidoNoMg(Contenido *unContenido);

        void setUtil_v_contenido_nomg(int util_v);

        int getUtil_v_Contenido_nomg();

        void setDim_v_contenido_nomg(int dim_v);

        int getDim_v_Contenido_nomg();

        void insertarContenidoEnVectorContenidoValorado(Contenido *unContenido);

        void setUtil_v_contenido_valorado(int util_v);

        int getUtil_v_Contenido_valorado();

        void setDim_v_contenido_valorado(int dim_v);

        int getDim_v_Contenido_valorado();

        void insertarContenidoEnVectorContenidoBuscado(Contenido* unContenido);

        void setUtil_v_contenido_Buscado(int util_v);

        int getUtil_v_Contenido_Buscado();

        void setDim_v_contenido_Buscado(int dim_v);

        int getDim_v_Contenido_Buscado();

        void imprimirContenidosBuscados()const;

        void imprimirContenidosVisualizados()const;
        void imprimirContenidosValorados()const;

        void asignarVector(Contenido**& destino, Contenido** origen, int utilOrigen, int dimOrigen);

        void printVector(Contenido** vector, int util)const;

        void resize(Contenido** &vector, int &util, int &dim, int nuevaCapacidad);

        Usuario& operator=(const Usuario &u);

        friend ostream& operator<<(ostream &flujo, const Usuario &p);


        void limpiarVectorContenidoBuscado();

        void limpiarVectorContenidoBuscadoAuxiliar();

        Contenido* getContenidoVisualizado(int i);

        Contenido* getContenidoValorado(int i)const;

        Contenido* getContenidoMeGusta(int i);

        void setContenidoMeGusta(int i, Contenido* contenido);

        Contenido* getContenidoNoMeGusta(int i);

        void setContenidoNoMeGusta(int i, Contenido* contenido);

        void setContenidoValorado(int i, Contenido* contenido);
        void setContenidoVisualizado(int i, Contenido* contenido);


};