/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristogamesserver;

import java.io.*;
import java.net.Socket;
import modelo.Conexion;
import controlador.ControladorUsuario;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;
import modelo.Usuario;


/**
 *
 * @author hanokme
 */
public class CristoGamesServerThread extends Thread{
    private Socket socket;
    private CristoGamesProtocol protocolo;
    private VentanaServer ventana;
    private final CristoGamesServer servidor;
    private String correo;
    private PrintWriter out;
    private BufferedReader in;
    private String token;
    private Conexion conexion;
    private ControladorUsuario controladorUsuario;
    private final Semaphore semaforo;
    
    /**
     * Constructor de la hebra del servidor. Inicializa las conexiones de
     * entrada y salida con el cliente.
     *
     * @param socket Socket de comunicación con el cliente.
     * @param ventana Ventana de logs del servidor.
     * @param servidor Referencia al servidor principal.
     */
    public CristoGamesServerThread(Socket socket, VentanaServer ventana, CristoGamesServer servidor){
        this.socket = socket;
        this.ventana = ventana;
        this.protocolo = new CristoGamesProtocol(servidor);
        this.controladorUsuario = new ControladorUsuario();
        this.servidor = servidor;
        this.correo = null;
        this.conexion = new Conexion();
        this.semaforo = new Semaphore(1);
        
        try {
            this.out = new PrintWriter(socket.getOutputStream(), true);
            this.in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            System.out.println("Cliente registrado con PrintWriter.");

            
        } catch (IOException e) {
            System.err.println("Error inicializando flujos de entrada/salida: " + e.getMessage());
        }
    }
    
    /**
     * Método principal de ejecución del hilo. Procesa los mensajes del cliente
     * hasta que este se desconecte o envíe un mensaje de salida.
     */
    public void run() {
        boolean seguirProcesando = true;
        try {
            String clientIP = socket.getInetAddress().getHostAddress();
            System.out.println("🌐Cliente conectado desde: " + clientIP);
            String inputLine;

            while (seguirProcesando && (inputLine = in.readLine()) != null) {
                System.out.println("📩Mensaje recibido de " + clientIP + ": " + inputLine);
                ventana.appendMessage("📩Cliente: " + inputLine);
                
                if(!inputLine.contains("#RECEIVED_AND_FINISHED")){
                    String respuesta = protocolo.processInput(inputLine, clientIP);
                    if (respuesta != null && !respuesta.isEmpty()) {
                        try {
                            semaforo.acquire();
                            out.println(respuesta);
                            ventana.appendMessage("✅Respuesta enviada: " + respuesta);
                        } finally {
                            semaforo.release();
                        }

                    }
                }

                if (inputLine.contains("#READY_TO_RECEIVE_IMAGE_FOR#")) {
                    manejarSolicitudImagen(inputLine);
                }

                if (inputLine.contains("#LOGIN#")) {
                    procesarLogin(inputLine);
                }

                if (inputLine.contains("#BYEBYE#")) {
                    seguirProcesando = false;
                }
            }
        } catch (IOException e) {
            System.err.println("❌Error en la conexión: " + e.getMessage());
        } catch (InterruptedException ex) {
            Logger.getLogger(CristoGamesServerThread.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            cerrarConexion();
        }
    }
    
    /**
     * Maneja la solicitud de imagen de perfil del usuario creando 
     * una hebra imagen para delegar en ella todas las comunicaciones con el cliente referentes a la imagen.
     *
     * @param inputLine Mensaje recibido con la solicitud de imagen.
     * @throws InterruptedException Si ocurre una interrupción en la hebra.
     */
    private void manejarSolicitudImagen(String inputLine) throws InterruptedException {
        boolean recibido = false;
        String[] parts = inputLine.split("#");
        if (parts.length >= 7) {
            String correo = parts[3];
            String username = parts[4];
            String token = parts[6];


            System.out.println("Esperando confirmación del cliente para recibir la imagen...");
            try {

                    System.out.println("Confirmación recibida: " + inputLine);
                    CristoGamesImageThread imageThread = new CristoGamesImageThread(out, correo, username, token, servidor, semaforo);
                    servidor.agregarHebraImagen(imageThread);
                    imageThread.start();
                    socket.setSoTimeout(0);

            } catch (IOException e) {
                System.err.println("No se recibió confirmación a tiempo. Cancelando envío.");
            }

        }
    }
    
    /**
     * Procesa el mensaje de inicio de sesión y almacena el correo y token del
     * usuario autenticado.
     *
     * @param inputLine Mensaje recibido con los datos del usuario.
     */
    private void procesarLogin(String inputLine) {
        String[] parts = inputLine.split("#");
        if (parts.length >= 5) {
            this.correo = parts[3];
            this.token = parts[4];

            System.out.println("👤Usuario autenticado: " + this.correo + " | Token: " + this.token);
        } else {
            System.err.println("❌Error en el formato del login.");
        }
    }

    /**
     * Cierra la conexión del cliente y elimina su sesión del sistema.
     */
    private void cerrarConexion() {
        if (correo != null) {
            protocolo.cerrarConexion(correo, socket.getInetAddress().getHostAddress());
        }
        try {
            socket.close();
            socket = null;
            System.out.println("🔌Cliente desconectado.");
        } catch (IOException e) {
            System.err.println("❌Error al cerrar el socket: " + e.getMessage());
        }
        servidor.eliminarHebra(this);
    }

    public String getCorreo() {
        return correo;
    }

    public PrintWriter getOut() {
        if (out == null) {
            System.err.println("Intentando obtener PrintWriter pero es NULL para usuario: " + correo);
        }
        return out;
    }

    public String getToken() {
        return token;
    }
    
  
}
