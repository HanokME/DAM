/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristogamescliente;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import javax.swing.SwingUtilities;


/**
 *
 * @author hanokme
 */
public class ProtocoloCliente {
    
    private String serverIP;
    private int portNumber;
    private Socket socket;
    private PrintWriter out;
    private InputStream inStream; 
    private VentanaPrincipal ventanaPrincipal;
    private ControladorCliente controlador;
    private ClientListenerThread clientListener;
    
    
    public ProtocoloCliente(String serverIP, int portNumber) {
        this.serverIP = serverIP;
        this.portNumber = portNumber;
        conectar();
        iniciarEscucharServidor();
    }
    
    private void conectar() {
        try {
            socket = new Socket();
            socket.connect(new InetSocketAddress(serverIP, portNumber), 5000);
            socket.setSoTimeout(6000);
            out = new PrintWriter(socket.getOutputStream(), true);
            inStream = socket.getInputStream();
            System.out.println("📡Conectado al servidor.");

        } catch (IOException e) {
            System.err.println("❌Error al conectar con el servidor: " + e.getMessage());
        }
    }
    
    private void iniciarEscucharServidor() {
        if (clientListener == null || !clientListener.isAlive()) {
            clientListener = new ClientListenerThread(inStream, this);
            clientListener.start();
        }
    }
    
    public void processInput(String mensaje) {
        if (mensaje == null || mensaje.isEmpty()) {
            System.err.println("Mensaje vacío recibido.");
        } else if (mensaje.contains("#NEW_REVIEW_FOR#")) {
            solicitarResenia(mensaje);
        } else if (mensaje.contains("#GAME_INFO_TO#")) {
            System.out.println("Información del juego recibida.");
        } else if (mensaje.contains("#INFO_CLIENT_TO#")) {
            System.out.println("Información del usuario recibida.");
        } else if (mensaje.contains("#OK_IMAGE_FOR#")) {
            System.out.println("Confirmación de imagen de perfil recibida.");
        } else if (mensaje.contains("#ERROR#")) {
            System.err.println("Error del servidor: " + mensaje);
        } else {
            System.out.println("Mensaje no identificado: " + mensaje);
        }

    }
    

    public String enviarMensaje(String mensaje){
        try {
            if (socket == null || socket.isClosed()) {
                conectar(); // Si el socket está cerrado, se reconecta
            }
            out.println(mensaje);
            System.out.println("📩Mensaje enviado: " + mensaje);
            BufferedReader reader = new BufferedReader(new InputStreamReader(inStream));
            String respuesta = reader.readLine();
            
            if(respuesta != null){
                processInput(respuesta);
            }
            
            return respuesta;
            
        } catch (IOException e) {
            System.err.println("Error al enviar mensaje: " + e.getMessage());
            return "Error al conectar con el servidor";
        }
    }
    
    
    public void cerrarConexion(){
        try{
            if(socket != null){
                socket.close();
                System.out.println("🔌Conexión cerrada.");
            }
        } catch(IOException e){
            System.err.println("❌Error al cerrar la conexión: " + e.getMessage());
        }
    }
    

    
    public String obtenerHora() {
        return new SimpleDateFormat("HH:mm:ss").format(new Date());
    }
    
    public Map<String, Object> obtenerInfoUsuario(String currentUser, String currentToken) {
        
        String fecha = obtenerHora();
        String mensaje = "PROTOCOLCRISTOGAMES1.0#" + fecha + "#GET_INFO_CLIENT#" + currentUser + "#WITH_TOKEN#" + currentToken;

        // Enviar mensaje al servidor
        String respuesta = enviarMensaje(mensaje);

        // Verificar si la respuesta es válida
        if (respuesta == null || !respuesta.startsWith("PROTOCOLCRISTOGAMES1.0#") || !respuesta.contains("#INFO_CLIENT_TO#")) {
            return null; 
        }

        // Parsear la respuesta
        String[] partes = respuesta.split("#");
        if (partes.length < 13) {
            System.err.println("❌ Error: La respuesta del servidor no tiene todos los campos esperados.");
            return null;
        }

        Map<String, Object> datosUsuario = new HashMap<>();

        try {
            // Datos del usuario
            datosUsuario.put("username", partes[6]);
            datosUsuario.put("nombre", partes[7]);
            datosUsuario.put("apellidos", partes[8]);
            datosUsuario.put("pais", partes[9]);
            datosUsuario.put("tipo", partes[10]);
            datosUsuario.put("biografia", partes[11]);

            // Obtener los juegos jugados
            int index = 12;
            int nJugados = Integer.parseInt(partes[index++]);
            List<Map<String, String>> juegosJugados = new ArrayList<>();

            for (int i = 0; i < nJugados; i++) {

                Map<String, String> juego = new HashMap<>();
                juego.put("id", partes[index++]);
                juego.put("nombre", partes[index++]);
                juego.put("estudio", partes[index++]);
                juego.put("lanzamiento", partes[index++]);
                juego.put("calificacion", partes[index++]);
                juego.put("idgenero", partes[index++]);
                juego.put("genero", partes[index++]);

                juegosJugados.add(juego);
            }
            datosUsuario.put("juegosJugados", juegosJugados);

            
            int nDestacados = Integer.parseInt(partes[index++]);
            List<Map<String, String>> juegosDestacados = new ArrayList<>();

            for (int i = 0; i < nDestacados; i++) {

                Map<String, String> juego = new HashMap<>();
                juego.put("id", partes[index++]);
                juego.put("nombre", partes[index++]);
                juego.put("estudio", partes[index++]);
                juego.put("lanzamiento", partes[index++]);
                juego.put("calificacion", partes[index++]);
                juego.put("idgenero", partes[index++]);
                juego.put("genero", partes[index++]);

                juegosDestacados.add(juego);
            }
            datosUsuario.put("juegosDestacados", juegosDestacados);

        } catch (Exception e) {
            System.err.println("❌ Error al procesar la información del usuario: " + e.getMessage());
            return null;
        }

        return datosUsuario;
    }
    
    public Map<String, Object> obtenerInfoJuego(int idJuego, String currentUser, String currentToken){
        String mensaje = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#GET_INFO_GAME_ID#" + idJuego + "#BY#" + currentUser + "#WITH_TOKEN#" + currentToken;
        String respuesta = enviarMensaje(mensaje);
        
        if(respuesta == null || !respuesta.contains("#GAME_INFO_TO")){
            return null;
        }
        String[] partes = respuesta.split("#");
        
        if (partes.length < 14) {
            System.out.println("❌Respuesta del servidor incompleta.");
            return null;
        }
        
        Map<String, Object> datosJuego = new HashMap<>();
        datosJuego.put("idJuego", Integer.parseInt(partes[6]));
        datosJuego.put("nombre", partes[7]);
        datosJuego.put("estudio", partes[8]);
        datosJuego.put("lanzamiento", partes[9]);
        datosJuego.put("calificacion", Double.parseDouble(partes[10]));
        datosJuego.put("idGenero", partes[11]);
        datosJuego.put("genero", partes[12]);
        
        // Procesar reseñas
        List<Map<String, String>> resenias = new ArrayList<>();
        int totalResenias = Integer.parseInt(partes[13]);
        int index = 14;

        for (int i = 0; i < totalResenias; i++) {
            Map<String, String> resenia = new HashMap<>();
            resenia.put("username", partes[index++]);
            resenia.put("fecha", partes[index++]);
            resenia.put("texto", partes[index++]);
            resenia.put("calificacion", partes[index++]);
            resenias.add(resenia);
        }

        datosJuego.put("resenias", resenias);
        return datosJuego;
    }
    
    public void solicitarResenia(String mensaje){
        System.out.println("❌Procesando la reseña");
        
        String[] parts = mensaje.split("#");
        if(parts.length >= 18){
            try {
                int idJuego = Integer.parseInt(parts[3]);
                String username = parts[5];
                String texto = parts[9];
                int puntuacion = Integer.parseInt(parts[11]);
                String fecha = parts[13];
                String nombreJuego = parts[15];
                double calificacionMedia = Double.parseDouble(parts[17]);
                
                
                // Llamar al controlador para actualizar la interfaz
                SwingUtilities.invokeLater(() -> {
                    if (controlador != null) {
                        controlador.manejarBroadcastResenia(idJuego, username, texto, puntuacion, fecha, nombreJuego, calificacionMedia);
                    } else {
                        System.err.println("ControladorCliente es NULL. No se puede procesar la reseña.");
                    }
                });
            } catch (Exception e) {
                System.err.println("❌Error al procesar el broadcast de reseña: " + e.getMessage());
            }
        } else{
            System.err.println("❌Broadcast de reseña mal formado.");
        }
    }
    
    public void solicitarImagenPerfil(String correo, String username, String token, VentanaPrincipal ventana){

 
        String mensajeSolicitud = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#GET_PROFILE_IMAGE#"
                + correo + "#" + username + "#WITH_TOKEN#" + token;
        String respuesta = enviarMensaje(mensajeSolicitud);

        if (respuesta == null || !respuesta.contains("#OK_IMAGE_FOR#")) {
            System.err.println("❌Error al solicitar imagen de perfil.");
            return;
        }
        
        
        System.out.println("📩Respuesta del servidor para imagen: " + respuesta);

        //Parsear la respuesta para obtener el tamaño del archivo y el paquete
        String[] partes = respuesta.split("#");
        if (partes.length < 10) {
            System.err.println("❌Respuesta del servidor mal formada: " + respuesta);
            return;
        }

        long fileSize;
        int packageSize;
        fileSize = Long.parseLong(partes[8]); 
        packageSize = Integer.parseInt(partes[10]); 
        
        new ClientImageThread(inStream, out, correo, username, token, fileSize, ventana).start();
        
        
        String mensajeConfirmacion = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#READY_TO_RECEIVE_IMAGE_FOR#"
                + correo + "#" + username + "#WITH_TOKEN#" + token + "#FILE_SIZE#" + fileSize + "#SIZE_PACKAGE#" + packageSize;
        
        out.println(mensajeConfirmacion);
        

    }
    
    
    
    public void enviarResenia(int idJuego, String usuario, String token, String texto, int puntuacion) {
        String mensaje = "PROTOCOLCRISTOGAMES1.0#" + obtenerHora() + "#NEW_REVIEW_FOR#" + idJuego
                + "#BY#" + usuario + "#WITH_TOKEN#" + token + "#REVIEW_TEXT#" + texto + "#SCORING#" + puntuacion;

        String respuesta = enviarMensaje(mensaje);

        if (respuesta != null && respuesta.contains("ERROR#CANT_SET_REVIEW")) {
            System.err.println("❌ No se pudo registrar la reseña.");
        } else {
            System.out.println("✅ Reseña guardada con éxito en el servidor.");
        }
    }
    
    public void setControlador(ControladorCliente controlador){
        this.controlador = controlador;
    }

}