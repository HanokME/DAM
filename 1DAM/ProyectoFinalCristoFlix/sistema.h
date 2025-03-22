    #include <iostream>
    #include <iomanip>
    #include <string.h>
    #include "valoracion.h"
    using namespace std;

class Sistema{

    private:
        Usuario** v_usuarios_sistema;
        int util_v_usuarios_sistema;
        int dim_v_usuarios_sistema;

        Contenido** v_contenidos_sistema;
        int util_v_contenidos_sistema;
        int dim_v_contenidos_sistema;

        Valoracion* v_valoraciones_sistema;
        int util_v_valoraciones_sistema;
        int dim_v_valoraciones_sistema;

        Usuario* usuario_logado;

        int totalPlayed;
        int totalValorated;
        int totalLikes;
        int totalUnlikes;

        int last_content_id;
        int last_user_id;
        int last_assessment_id;

    public:

    /**
     * @brief Constructor por defecto de la clase Sistema.
     * Inicializa un sistema vacío.
     */
    Sistema();

    /**
     * @brief Constructor de copia de la clase Sistema.
     * @param s Objeto Sistema a copiar.
     */
    Sistema(const Sistema &s);

    /**
     * @brief Constructor de la clase Sistema.
     * @param v_usuarios_sistema Vector de usuarios del sistema.
     * @param util_v_usuarios_sistema Tamaño actual del vector de usuarios.
     * @param dim_v_usuarios_sistema Tamaño total del vector de usuarios.
     * @param v_contenidos_sistema Vector de contenidos del sistema.
     * @param util_v_contenidos_sistema Tamaño actual del vector de contenidos.
     * @param dim_v_contenidos_sistema Tamaño total del vector de contenidos.
     * @param v_valoraciones_sistema Vector de valoraciones del sistema.
     * @param util_v_valoraciones_sistema Tamaño actual del vector de valoraciones.
     * @param dim_v_valoraciones_sistema Tamaño total del vector de valoraciones.
     */
    Sistema(Usuario** v_usuarios_sistema, int util_v_usuarios_sistema, int dim_v_usuarios_sistema, Contenido** v_contenidos_sistema, int util_v_contenidos_sistema, int dim_v_contenidos_sistema, Valoracion* v_valoraciones_sistema, int util_v_valoraciones_sistema, int dim_v_valoraciones_sistema);

    /**
     * @brief Destructor de la clase Sistema.
     */
    ~Sistema();

    /**
     * @brief Carga los datos básicos del sistema.
     */
    void cargarDatosBasicosSistema();

    /**
     * @brief Establece el vector de valoraciones del sistema.
     * @param valoraciones Vector de valoraciones del sistema.
     */
    void setVValoracionesSistema(Valoracion* valoraciones);

    /**
     * @brief Obtiene el vector de valoraciones del sistema.
     * @return Vector de valoraciones del sistema.
     */
    Valoracion* getVValoracionesSistema() const;

    /**
     * @brief Establece el vector de contenidos del sistema.
     * @param contenidos Vector de contenidos del sistema.
     */
    void setVContenidosSistema(Contenido** contenidos);

    /**
     * @brief Obtiene el vector de contenidos del sistema.
     * @return Vector de contenidos del sistema.
     */
    Contenido** getVContenidosSistema() const;

    /**
     * @brief Establece el vector de usuarios del sistema.
     * @param usuarios Vector de usuarios del sistema.
     */
    void setVUsuariosSistema(Usuario** usuarios);

    /**
     * @brief Obtiene el vector de usuarios del sistema.
     * @return Vector de usuarios del sistema.
     */
    Usuario** getVUsuariosSistema() const;


    void setUsuarioLogado(Usuario* usuario);
    Usuario* getUsuarioLogado() const;

    /**
     * @brief Inicializa los datos de un vector de usuarios.
     * @param v_usuario Referencia al usuario a inicializar.
     */
    void inicializacion_datos_vector_usuarios(Usuario &v_usuario);

    /**
     * @brief Inicializa los datos de un vector de contenidos.
     * @param v_contenido Referencia al contenido a inicializar.
     */
    void inicializacion_datos_vector_contenido(Contenido &v_contenido);

    /**
     * @brief Inicializa los datos de un vector de valoraciones.
     * @param v_valoracion Referencia a la valoración a inicializar.
     */
    void inicializacion_datos_vector_valoraciones(Valoracion &v_valoracion);

    /**
     * @brief Redimensiona el vector de usuarios del sistema.
     */
    void resizeUsuarios();

    /**
     * @brief Redimensiona el vector de contenidos del sistema.
     */
    void resizeContenidos();

    /**
     * @brief Redimensiona el vector de valoraciones del sistema.
     */
    void resizeValoraciones();

    /**
     * @brief Inserta un usuario en el vector de usuarios del sistema.
     * @param unusuario Usuario a insertar.
     */
    void insertarUsuarioVectorUsuarios(Usuario *unusuario);

    /**
     * @brief Inserta un contenido en el vector de contenidos del sistema.
     * @param uncontenido Contenido a insertar.
     */
    void insertarContenidoVectorContenidos(Contenido *uncontenido);

    /**
     * @brief Inserta una valoración en el vector de valoraciones del sistema.
     * @param unvaloracion Valoración a insertar.
     */
    void insertarValoracionVectorValoraciones(Valoracion &unvaloracion);

    /**
     * @brief Establece el tamaño actual del vector de usuarios.
     * @param util_v Nuevo tamaño actual del vector de usuarios.
     */
    void set_util_v_usuarios(int util_v);

    /**
     * @brief Obtiene el tamaño actual del vector de usuarios.
     * @return Tamaño actual del vector de usuarios.
     */
    int get_util_v_usuarios();

    /**
     * @brief Establece el tamaño total del vector de usuarios.
     * @param dim_v Nuevo tamaño total del vector de usuarios.
     */
    void set_dim_v_usuarios(int dim_v);

    /**
     * @brief Obtiene el tamaño total del vector de usuarios.
     * @return Tamaño total del vector de usuarios.
     */
    int get_dim_v_usuarios();

            /**
     * @brief Establece el tamaño actual del vector de contenidos.
     * @param util_v Nuevo tamaño actual del vector de contenidos.
     */
    void set_util_v_contenidos(int util_v);

    /**
     * @brief Obtiene el tamaño actual del vector de contenidos.
     * @return Tamaño actual del vector de contenidos.
     */
    int get_util_v_contenidos();

    /**
     * @brief Establece el tamaño total del vector de contenidos.
     * @param dim_v Nuevo tamaño total del vector de contenidos.
     */
    void set_dim_v_contenidos(int dim_v);

    /**
     * @brief Obtiene el tamaño total del vector de contenidos.
     * @return Tamaño total del vector de contenidos.
     */
    int get_dim_v_contenidos();

    /**
     * @brief Establece el tamaño actual del vector de valoraciones.
     * @param util_v Nuevo tamaño actual del vector de valoraciones.
     */
    void set_util_v_valoraciones(int util_v);

    /**
     * @brief Obtiene el tamaño actual del vector de valoraciones.
     * @return Tamaño actual del vector de valoraciones.
     */
    int get_util_v_valoraciones();

    /**
     * @brief Establece el tamaño total del vector de valoraciones.
     * @param dim_v Nuevo tamaño total del vector de valoraciones.
     */
    void set_dim_v_valoraciones(int dim_v);

    /**
     * @brief Obtiene el tamaño total del vector de valoraciones.
     * @return Tamaño total del vector de valoraciones.
     */
    int get_dim_v_valoraciones();

    void setTotalPlayed(int totalPlayed);
    int getTotalPLayed();

    void setTotalValorated(int totalValorated);
    int getTotalValorated();

    void setTotalLikes(int totalLikes);
    int getTotalLikes();

    void setTotalUnLikes(int totalUnlikes);
    int getTotalUnLikes();


    /**
     * @brief Asigna un vector de usuarios a otro.
     * @param destino Vector de usuarios de destino.
     * @param origen Vector de usuarios de origen.
     * @param utilOrigen Tamaño actual del vector de usuarios de origen.
     * @param dimOrigen Tamaño total del vector de usuarios de origen.
     */
    void asignarVectorUsuarios(Usuario**& destino, Usuario** origen, int utilOrigen, int dimOrigen);

    /**
     * @brief Asigna un vector de contenidos a otro.
     * @param destino Vector de contenidos de destino.
     * @param origen Vector de contenidos de origen.
     * @param utilOrigen Tamaño actual del vector de contenidos de origen.
     * @param dimOrigen Tamaño total del vector de contenidos de origen.
     */
    void asignarVectorContenidos(Contenido**& destino, Contenido** origen, int utilOrigen, int dimOrigen);

    /**
     * @brief Asigna un vector de valoraciones a otro.
     * @param destino Vector de valoraciones de destino.
     * @param origen Vector de valoraciones de origen.
     * @param utilOrigen Tamaño actual del vector de valoraciones de origen.
     * @param dimOrigen Tamaño total del vector de valoraciones de origen.
     */
    void asignarVectorValoraciones(Valoracion*& destino, const Valoracion* origen, int utilOrigen, int dimOrigen);

    /**
     * @brief Imprime el vector de usuarios del sistema.
     */
    void printVectorUsuarios() const;

    /**
     * @brief Imprime el vector de contenidos del sistema.
     */
    void printVectorContenidos() const;

    /**
     * @brief Imprime el vector de valoraciones del sistema.
     */
    void printVectorValoraciones() const;

    void mostrarCatalogoContenido()const;

    /**
     * @brief Sobrecarga del operador de asignación para la clase Sistema.
     * @param u Objeto Sistema a asignar.
     * @return Referencia al objeto Sistema asignado.
     */
    Sistema& operator=(const Sistema &u);

    /**
     * @brief Sobrecarga del operador de inserción para la clase Sistema.
     * @param flujo Flujo de salida.
     * @param s Objeto Sistema a imprimir.
     * @return Flujo de salida modificado.
     */
    friend ostream& operator<<(ostream &flujo, const Sistema &s);

    void login(bool &encontrado, bool &esadmin);

    void mostrarMenuInicial();
    void mostrarMenuCompleto();

    int pedirOpcion();

    void menuInicio(Sistema& sistema, Usuario& usuario);

    void menuAdmin(Sistema& sistema, int opcion, char confirmacion);

    void mostrarMenuUsuario();

    void menuUsuario(Sistema& sistema, int opcion, Usuario& usuario);

    Contenido* buscarContenidoTitulo(const string& titulo);

    Contenido* buscarContenidoGenero(const string& genero);

    Contenido* buscarContenidoFecha(const Fecha& fecha);

    string introducirTitulo();
    string introducirGenero();
    Fecha IntroducirFecha();

    void visualizarContenido();

    void visualizarSistema();

    void valorarContenido(Contenido* contenido);

    void anadirMeGusta();

    void anadirNoMeGusta();

    void consultarValoraciones()const;

    float calcularCristoFlixRating(Contenido* contenido);

    void mostrarRating(Contenido* contenido);

    float calcularValoracionMediaNormalizada(Contenido* contenido);

    float calcularVisualizacionMediaNormalizada(Contenido* contenido);

    float calcularMeGustaMedioNormalizado(Contenido* contenido);

    float calcularNoMeGustaMedioNormalizado(Contenido* contenido);


    void obtenerTop3Contenido(Contenido* top3[]);

    void obtenerContenidosMasVisualizados(Contenido* masVisualizado[]);

    void obtenerContenidosMenosGustados(Contenido* menosGustados[]);

    void generarInformeRankingContenido();


    int filtrarContenidoPorTipo(Contenido* contenido[], const string& tipo);

    void obtenerTop3ContenidoPorTipo(Contenido* top3[], const string& tipo);

    void obtenerContenidosMasVisualizadosPorTipo(Contenido* masVisualizado[], const string& tipo);

    void obtenerContenidosMenosGustadosPorTipo(Contenido* menosGustados[], const string& tipo);

    void generarInformeRankingContenidoPorTipo(const string& tipo);

    Usuario* obtenerUsuarioDarkNight()const;
    Usuario* obtenerUsuarioFacilon()const;
    Usuario* obtenerUsuarioOfuscated()const;

    void generarInformeRankingUsuario()const;

    void recalcularEstadisticas();

    void agregarContenidoASistema();

    void agregarUsuarioASistema();

    Usuario* buscarUsuarioPorUserName(const string& user_name)const;
    Usuario* buscarUsuarioPorNombreCompleto(const string& nombre, const string& apellido1, const string& apellido2)const;

    void buscarUsuarioEnSistema();

    void consultarValoracionContenido();

    void modificarContenidoSistema();
    void modificarUsuarioSistema();

    void eliminarContenidoSistema();

    void eliminarUsuarioSistema();

    void eliminarValoracionSistema();


    ////TESTING
    void testingHP(Sistema& sistema);

    void testingMaria(Sistema& sistema);

    void testingNatalia(Sistema& sistema);

    void testingPablo(Sistema& sistema);


    //DIA OFICINA ORDINARIO
    void eliminarTodoContenidoSistemaPorTipo();

    string pedirTipoContenido();

    void eliminarContenido(Contenido* contenido, int it);

    void eliminarSerie();
    void eliminarPelicula();
    void eliminarDocumental();

    void eliminarValoracionesAsociadas(Contenido* contenido);

    void eliminarReferenciasUsuario(Contenido* contenido);
    

};