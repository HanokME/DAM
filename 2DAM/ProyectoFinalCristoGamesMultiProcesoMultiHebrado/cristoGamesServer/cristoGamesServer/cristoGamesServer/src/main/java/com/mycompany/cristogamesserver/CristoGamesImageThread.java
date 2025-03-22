/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristogamesserver;
import java.io.*;
import java.net.Socket;
import java.nio.file.Files;
import java.util.Arrays;
import java.util.Base64;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;
import modelo.Conexion;
import modelo.Usuario;
/**
 *
 * @author hanokme
 */
public class CristoGamesImageThread extends Thread{
    private PrintWriter out;
    private String correo;
    private String username;
    private String token;
    private CristoGamesProtocol protocolo;
    private CristoGamesServer servidor;
    private final Semaphore semaforo;

    public CristoGamesImageThread(PrintWriter out, String correo, String username, String token, CristoGamesServer servidor, Semaphore semaforo) {
        this.out = out;
        this.correo = correo;
        this.username = username;
        this.token = token;
        this.protocolo = new CristoGamesProtocol(servidor);
        this.semaforo = semaforo;
        this.servidor = servidor;
    }
    
    @Override
    public void run() {
        try {
            enviarImagen();
        } finally {
            servidor.eliminarHebraImagen(this); // Se elimina la hebra al finalizar
        }
    }
    
    private void enviarImagen() {
        System.out.println("📩Enviando imagen de perfil a " + username);

        byte[] imagenBytes = protocolo.obtenerImagenDesdeRecursos(username);
        if (imagenBytes == null || imagenBytes.length == 0) {
            System.err.println("❌No se encontró ninguna imagen para " + username);
            return;
        }

        int chunkSize = 1024;
        int totalChunks = (int) Math.ceil((double) imagenBytes.length / chunkSize);
        System.out.println("📩Enviando imagen en " + totalChunks + " paquetes a " + username + "...");

        for (int i = 0; i < totalChunks; i++) {
            int start = i * chunkSize;
            int end = Math.min(start + chunkSize, imagenBytes.length);
            byte[] chunkBytes = Arrays.copyOfRange(imagenBytes, start, end);

            String encodedChunk = Base64.getEncoder().encodeToString(chunkBytes);
            String mensaje = "PROTOCOLCRISTOGAMES1.0#" + protocolo.obtenerHora() + "#OK_IMAGE_FOR#"
                    + correo + "#" + username + "#WITH_TOKEN#" + token
                    + "#ID_PACKAGE#" + (i + 1) + "#BYTES#" + encodedChunk;

            try {
                semaforo.acquire(); 
                out.println(mensaje);
                out.flush();
                System.out.println("Enviado paquete #" + (i + 1) + " de " + totalChunks);
            } catch (InterruptedException ex) {
                Logger.getLogger(CristoGamesImageThread.class.getName()).log(Level.SEVERE, "❌Error en el semáforo: ", ex);
                return; // Finaliza la hebra en caso de error crítico
            } finally {
                semaforo.release(); 
            }
        }

        System.out.println("✅Transferencia de imagen de " + username + " completada.");
    }
    
}
