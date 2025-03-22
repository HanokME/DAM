/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristogamesserver;

import controlador.ControladorUsuario;
import java.io.IOException;
import java.io.InputStream;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import modelo.Conexion;
import modelo.Juego;
import modelo.Resenia;
import modelo.Usuario;
import controlador.ControladorJuego;
import controlador.ControladorResenia;
import java.util.concurrent.Semaphore;

/**
 *
 * @author hanokme
 */
public class CristoGamesProtocol {
    private static final int WAITING = 0;
    private static final int CONNECTED = 1;
    private ControladorUsuario controladorUsuario;
    private ControladorJuego controladorJuego;
    private ControladorResenia controladorResenia;
    private final Conexion conexion;
    private volatile boolean imagenConfirmada = false;
    private CristoGamesServer servidor;
    
    
    
    //Mapa para almacenar el usuario conectado y las ips correspondientes a ese usuario
    private static final Map<String, Set<String>> usuariosConectados = new HashMap<>();
    private static final Map<String, String> tokensUsuarios = new HashMap<>();
    
    private int state = WAITING;
    
    public CristoGamesProtocol(CristoGamesServer servidor){
        this.controladorUsuario = new ControladorUsuario();
        this.controladorJuego = new ControladorJuego();
        this.controladorResenia = new ControladorResenia();
        this.conexion = new Conexion();
        this.servidor = servidor;
        
    }
    
    /**
     * Procesa la entrada del cliente y ejecuta la acción correspondiente.
     *
     * @param input Mensaje recibido del cliente.
     * @param clientIP Dirección IP del cliente.
     * @return Respuesta que se enviará al cliente.
     */
    public String processInput(String input, String clientIP){
        String respuesta = "";
            
        String[] parts = input.split("#");
            
        String command = parts[2];
        String correo = parts[3];

        if (command.equalsIgnoreCase("LOGIN")) {
            
            respuesta = manejarLogin(correo, parts[4], clientIP);
            
        } else if (command.equalsIgnoreCase("GET_INFO_CLIENT")) {
            System.err.println("Entro en get info client");

            respuesta = manejarInfoCliente(correo, parts[5]);
            
        } else if (command.equalsIgnoreCase("NEW_REVIEW_FOR")) {
            respuesta = manejarNuevaResenia(parts);
        } else if (command.equalsIgnoreCase("GET_PROFILE_IMAGE")) {

            respuesta = manejarSolicitudImagen(correo, parts[4], parts[6]);

        } else if (command.equalsIgnoreCase("GET_INFO_GAME_ID")) {


            int idJuego = Integer.parseInt(parts[3]);
            respuesta = manejarInfoJuego(idJuego, parts[5], parts[7]);
 
            
        } else if (command.equalsIgnoreCase("BYEBYE")) {
            respuesta = manejarLogout(correo, parts[5], clientIP);
            
        }
        
        return respuesta;
        
    }
    
    /**
     * Maneja la solicitud de inicio de sesión del usuario.
     *
     * @param correo Correo del usuario.
     * @param password Contraseña del usuario.
     * @param clientIP Dirección IP del cliente.
     * @return Respuesta del servidor con éxito o error.
     */
    private synchronized String manejarLogin(String correo, String password, String clientIP){
        String respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#BAD_CREDENTIALS";
        if (controladorUsuario.validarCredencialesUsuario(correo, password)) {
            boolean isPremium = controladorUsuario.esUsuarioPremium(correo);
            int maxConexiones = isPremium ? 2 : 1;
            int conexionesActuales = controladorUsuario.getNumeroConexiones(correo);
            Set<String> ipsConectadas = usuariosConectados.getOrDefault(correo, new HashSet<>());

            if ((!isPremium && conexionesActuales < 1) || (isPremium && conexionesActuales < 2)) {
                ipsConectadas.add(clientIP);
                usuariosConectados.put(correo, ipsConectadas);
                controladorUsuario.incrementarConexiones(correo);

                String token = TokenGenerator.generateToken();
                tokensUsuarios.put(correo, token);
                respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#WELLCOME#" + correo + "#WITH_TOKEN#" + token;
            } else {
                respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#MAX_CONNECTIONS_LIMIT_REACHED";
            }
        }

        return respuesta;
    }
    
    /**
     * Maneja la solicitud de cierre de sesión del usuario.
     *
     * @param correo Correo del usuario.
     * @param token Token de autenticación.
     * @param clientIP Dirección IP del cliente.
     * @return Respuesta de confirmación o error.
     */
    private String manejarLogout(String correo, String token, String clientIP){
        String respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#BAD_CREDENTIALS";

        if (tokensUsuarios.containsKey(correo) && tokensUsuarios.get(correo).equals(token)) {
            if (usuariosConectados.containsKey(correo)) {
                Set<String> ipsConectadas = usuariosConectados.get(correo);
                ipsConectadas.remove(clientIP);
                if (ipsConectadas.isEmpty()) {
                    usuariosConectados.remove(correo);
                }
            }

            controladorUsuario.cerrarSesion(correo);

            if (!usuariosConectados.containsKey(correo)) {
                tokensUsuarios.remove(correo);
            }

            respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#SEEYOU#" + correo + "#WITH_TOKEN#" + token;
        }

        return respuesta;
    }
    
    /**
     * Cierra la conexión de un usuario y elimina su sesión activa.
     *
     * @param correo Correo del usuario a desconectar.
     * @param clientIP Dirección IP del cliente.
     */
    public synchronized void cerrarConexion(String correo, String clientIP) {
        if (usuariosConectados.containsKey(correo)) {
            Set<String> ipsConectadas = usuariosConectados.get(correo);
            ipsConectadas.remove(clientIP);
            if (ipsConectadas.isEmpty()) {
                usuariosConectados.remove(correo);
            }
        }

        tokensUsuarios.remove(correo);
        controladorUsuario.cerrarSesion(correo);
    }
    
    /**
     * Maneja la solicitud de información del usuario.
     *
     * @param correo Correo del usuario.
     * @param token Token de autenticación.
     * @return Respuesta con los datos del usuario o error.
     */
    private String manejarInfoCliente(String correo, String token){
        System.out.println("📩Procesando solicitud de información de usuario para: " + correo);
        String respuesta = "";

        if (!comprobarCredenciales(correo, token)) {
            respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#BAD_CREDENTIALS";
        } else {
            Usuario usuario = controladorUsuario.obtenerUsuario(correo);

            if (usuario != null && usuario.getPerfil() != null) {
                // Datos del usuario
                StringBuilder mensaje = new StringBuilder();
                mensaje.append("PROTOCOLCRISTOGAMES1.0#")
                        .append(obtenerHora()).append("#INFO_CLIENT_TO#")
                        .append(correo).append("#WITH_TOKEN#").append(token).append("#")
                        .append(usuario.getPerfil().getUsername()).append("#")
                        .append(usuario.getNombre()).append("#")
                        .append(usuario.getApellidos()).append("#")
                        .append(usuario.getPais()).append("#")
                        .append(usuario.getTipo()).append("#")
                        .append(usuario.getPerfil().getBiografia()).append("#");

                // Obtener juegos jugados
                List<Juego> juegosJugados = controladorUsuario.obtenerJuegosJugados(correo);
                mensaje.append(juegosJugados.size()).append("#"); // <n_jugados>

                for (Juego juego : juegosJugados) {
                    mensaje.append(juego.getIdJuego()).append("#")
                            .append(juego.getNombre()).append("#")
                            .append(juego.getEstudio()).append("#")
                            .append(juego.getLanzamiento()).append("#")
                            .append(juego.getCalificacionMedia() != null ? juego.getCalificacionMedia() : 0.0).append("#")
                            .append(juego.getGenero().getIdGenero()).append("#")
                            .append(juego.getGenero().getNombre()).append("#");
                }

                // Obtener juegos destacados
                List<Juego> juegosDestacados = controladorJuego.obtenerJuegosDestacados();
                mensaje.append(juegosDestacados.size()).append("#"); // <n_destacados>

                for (Juego juego : juegosDestacados) {
                    mensaje.append(juego.getIdJuego()).append("#")
                            .append(juego.getNombre()).append("#")
                            .append(juego.getEstudio()).append("#")
                            .append(juego.getLanzamiento()).append("#")
                            .append(juego.getCalificacionMedia() != null ? juego.getCalificacionMedia() : 0.0).append("#")
                            .append(juego.getGenero().getIdGenero()).append("#")
                            .append(juego.getGenero().getNombre()).append("#");
                }

                respuesta = mensaje.toString();
            } else {
                respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#CANT_GET_INFO";
            }
        }

        return respuesta;
        
    }
    
    /**
     * Maneja la solicitud de información de un juego.
     *
     * @param idJuego ID del juego.
     * @param correo Correo del usuario solicitante.
     * @param token Token de autenticación.
     * @return Respuesta con la información del juego o error.
     */
    private String manejarInfoJuego(int idJuego, String correo, String token){
        String respuesta = "";
        if(!comprobarCredenciales(correo, token)){
            respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#BAD_CREDENTIALS";
        } else{
            Juego juego = controladorJuego.obtenerJuego(idJuego);
            
            if (juego != null) {
                StringBuilder mensaje = new StringBuilder();
                mensaje.append("PROTOCOLCRISTOGAMES1.0#")
                        .append(obtenerHora()).append("#GAME_INFO_TO#")
                        .append(correo).append("#WITH_TOKEN#").append(token).append("#")
                        .append(juego.getIdJuego()).append("#")
                        .append(juego.getNombre()).append("#")
                        .append(juego.getEstudio()).append("#")
                        .append(juego.getLanzamiento()).append("#")
                        .append(juego.getCalificacionMedia() != null ? juego.getCalificacionMedia() : 0.0).append("#")
                        .append(juego.getGenero().getIdGenero()).append("#")
                        .append(juego.getGenero().getNombre()).append("#");

                // Obtener la lista de reseñas
                List<Resenia> resenias = controladorJuego.obtenerReseniasPorJuego(idJuego);
                mensaje.append(resenias.size()).append("#"); // n_total_reviews

                // Añadir cada reseña al mensaje
                for (Resenia resenia : resenias) {
                    mensaje.append(resenia.getPerfil().getUsername()).append("#")
                            .append(resenia.getpK().getFecha()).append("#")
                            .append(resenia.getTexto()).append("#") 
                            .append(resenia.getCalificacion()).append("#"); 
                }

                respuesta = mensaje.toString();
            } else {
                respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#GAME_NOT_FOUND";
            }
            
 
            
            
        }
        
        return respuesta;
        
    }
    
    

    
    public String obtenerHora(){
        return new SimpleDateFormat("HH:mm:ss").format(new Date());
    }
    
    /**
     * Maneja la solicitud de imagen de perfil del usuario.
     *
     * @param correo Correo del usuario.
     * @param username Nombre de usuario.
     * @param token Token de autenticación.
     * @return Respuesta con la confirmación o error.
     */
    private String manejarSolicitudImagen(String correo, String username, String token){
        String respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#BAD_CREDENTIALS";

        if (comprobarCredenciales(correo, token)) {
            byte[] imagenBytes = obtenerImagenDesdeRecursos(username);
            if (imagenBytes != null) {
                long fileSize = imagenBytes.length;
                int chunkSize = 1024;

                System.out.println("Enviando imagen - FILE_SIZE: " + fileSize + ", SIZE_PACKAGE: " + chunkSize);

                respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#OK_IMAGE_FOR#"
                        + correo + "#" + username + "#WITH_TOKEN#" + token
                        + "#FILE_SIZE#" + fileSize + "#SIZE_PACKAGE#" + chunkSize;
            } else {
                respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#CANT_GET_IMAGE";
            }
        }

        return respuesta;
    }
    
    /**
     * Obtiene la imagen de perfil del usuario desde los recursos del servidor.
     *
     * @param username Nombre de usuario.
     * @return Bytes de la imagen o null si no se encuentra.
     */
    public byte[] obtenerImagenDesdeRecursos(String username){
        String ruta = username + "/image_profile/" + username + ".png";
        byte[] imagenBytes = null;

        try (InputStream is = getClass().getClassLoader().getResourceAsStream(ruta)) {
            if (is == null) {
                System.err.println("Imagen no encontrada: " + ruta);
            } else {
                imagenBytes = is.readAllBytes();
            }
        } catch (IOException e) {
            System.err.println("Error al cargar la imagen: " + e.getMessage());
        }

        return imagenBytes;
    }
    
    /**
     * Maneja el proceso de una nueva reseña enviada por un usuario.
     *
     * @param partes Array con los parámetros del mensaje recibido.
     * @return Respuesta indicando si la reseña se registró correctamente o no.
     */
    private String manejarNuevaResenia(String[] partes){
        System.out.println("📩DEBUG: Mensaje recibido en manejarNuevaResenia: " + Arrays.toString(partes));
        String respuesta = "";
        System.out.println("📩DEBUG: Número de partes recibidas: " + partes.length);
        if (partes.length >= 12) {
            System.out.println("📩DEBUG: idJuego = " + partes[3]);
            int idJuego = Integer.parseInt(partes[3]);
            System.out.println("📩DEBUG: userLogin = " + partes[5]);
            String userLogin = partes[5];
            System.out.println("📩DEBUG: token = " + partes[7]);
            String token = partes[7];
            System.out.println("📩DEBUG: textoResenia = " + partes[9]);
            String textoResenia = partes[9];
            System.out.println("📩DEBUG: puntuacion = " + partes[11]);
            int puntuacion = Integer.parseInt(partes[11]);

            if (comprobarCredenciales(userLogin, token)) {
                Usuario usuario = controladorUsuario.obtenerUsuario(userLogin);
                Juego juego = controladorJuego.obtenerJuego(idJuego);

                if (usuario != null && juego != null) {
                    LocalDateTime fechaResenia = LocalDateTime.now();
                    controladorResenia.agregarResenia(usuario.getPerfil().getUsername(), idJuego, textoResenia, puntuacion);
                    double nuevaCalificacionMedia = controladorResenia.obtenerCalificacionMedia(idJuego);

                    String broadcastMensaje = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#NEW_REVIEW_FOR#"
                            + idJuego + "#BY#" + usuario.getPerfil().getUsername()
                            + "#WITH_TOKEN#" + token
                            + "#REVIEW_TEXT#" + textoResenia
                            + "#SCORING#" + puntuacion
                            + "#DATE#" + fechaResenia
                            + "#GAME_NAME#" + juego.getNombre()
                            + "#AVG_SCORING#" + nuevaCalificacionMedia;

                    servidor.broadcastMensaje(broadcastMensaje);
                } else {
                    respuesta = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#ERROR#CANT_SET_REVIEW";
                }
            } 
        }

        return respuesta;
    }
    
    /**
     * Verifica si las credenciales de usuario son correctas.
     *
     * @param correo Correo del usuario.
     * @param token Token de autenticación.
     * @return `true` si las credenciales son correctas, `false` de lo
     * contrario.
     */
    private boolean comprobarCredenciales(String correo, String token){
        boolean esCorrecto = false;
        if(tokensUsuarios.containsKey(correo) && tokensUsuarios.get(correo).equals(token)){
            esCorrecto = true;
        }
        return esCorrecto;
    }
}

