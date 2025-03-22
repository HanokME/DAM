/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.cristogamesserver;

import java.net.*;
import java.io.*;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Semaphore;


/**
 *
 * @author hanokme
 */
public class CristoGamesServer {
    private VentanaServer ventana;
    private final List<CristoGamesServerThread> hebraList;
    private final List<CristoGamesImageThread> imageHebraList;
    private final Semaphore semaforo;
    private final Semaphore semaforoImagen;
    private final int portNumber = 4444;
    
    public CristoGamesServer() throws InterruptedException{
        ventana = new VentanaServer();
        ventana.setVisible(true);
        this.hebraList = new ArrayList<>();
        this.imageHebraList = new ArrayList<>();
        this.semaforo = new Semaphore(1);
        this.semaforoImagen = new Semaphore(1);
        startServer();
    }
    
    public void startServer() throws InterruptedException{
        
        System.out.println("Servidor CristoGames iniciado");
        
        try (ServerSocket serverSocket = new ServerSocket()) {
            serverSocket.setReuseAddress(true);
            serverSocket.bind(new InetSocketAddress(InetAddress.getByName("0.0.0.0"), portNumber));
            System.out.println("Servidor CristoGames iniciado en 0.0.0.0:" + portNumber);

            while (true) {
                try {
                    // Aceptar conexiones entrantes
                    Socket clientSocket = serverSocket.accept();
                    System.out.println("Nuevo cliente conectado: " + clientSocket.getInetAddress());

                    // Crear hilo para el cliente
                    CristoGamesServerThread clientThread = new CristoGamesServerThread(clientSocket, ventana, this);
                    clientThread.start();

                    // Añadir cliente a la lista de conexiones activas
                    semaforo.acquire();
                    
                    hebraList.add(clientThread);

                    semaforo.release();
                    
                } catch (IOException | InterruptedException e) {
                    System.err.println("Error al aceptar cliente: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.err.println("Error al iniciar el servidor: " + e.getMessage());
        }
    }
    
    public void eliminarHebra(CristoGamesServerThread thread){
        try {
            semaforo.acquire();
            hebraList.remove(thread);
            
        } catch (Exception e) {
            System.err.println("❌Error al eliminar la hebra: " + e.getMessage());
        } finally {
            semaforo.release();
        }
    }
    
    public void eliminarHebraImagen(CristoGamesImageThread thread) {
        try {
            semaforoImagen.acquire(); 
            imageHebraList.remove(thread);
        } catch (InterruptedException e) {
            System.err.println("❌Error en el semáforo al eliminar hebra de imagen: " + e.getMessage());
        } finally {
            semaforoImagen.release(); 
        }
    }
    
    public void agregarHebraImagen(CristoGamesImageThread thread) {
        try {
            semaforoImagen.acquire(); // Bloquear acceso 
            imageHebraList.add(thread);
        } catch (InterruptedException e) {
            System.err.println("❌Error en el semáforo al agregar hebra de imagen: " + e.getMessage());
        } finally {
            semaforoImagen.release(); 
        }
    }
    
    /**
     * 
     * @param mensaje 
     */
    public void broadcastMensaje(String mensaje){
        try {
            semaforo.acquire();
            System.out.println("Enviando mensaje broadcast a " + hebraList.size() + " clientes.");
            for (CristoGamesServerThread hebra : hebraList) {
                
                if (hebra.getOut() != null) {
                    System.out.println("Enviando mensaje a cliente: " + hebra.getCorreo());
                    hebra.getOut().println(mensaje);
                    hebra.getOut().flush();
                    
                } else {
                    System.err.println("Cliente desconectado o PrintWriter es NULL para: " + hebra.getCorreo());
                    
                }
                
            }
            System.out.println("Mensaje de broadcast enviado a todos los clientes.");
        } catch (InterruptedException e) {
            System.err.println("Error al enviar broadcast: " + e.getMessage());
        } finally {
            semaforo.release();
        }
    }

    public static void main(String[] args) throws InterruptedException {
        new CristoGamesServer();
  
    }
    
}
