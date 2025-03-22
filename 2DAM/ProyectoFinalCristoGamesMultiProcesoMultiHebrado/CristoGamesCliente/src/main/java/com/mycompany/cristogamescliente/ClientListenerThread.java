/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristogamescliente;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.SocketException;

/**
 *
 * @author hanokme
 */
public class ClientListenerThread extends Thread {
    
    private InputStream inputStream;
    private ProtocoloCliente protocolo;
    private boolean seguir = true;
    
    public ClientListenerThread(InputStream inputStream, ProtocoloCliente protocolo){
        this.inputStream = inputStream;
        this.protocolo = protocolo;
    }
    
    @Override
    public void run(){
        System.out.println("Se inicia el hilo de escucha del servidor.");
        
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream))) {
            String mensaje;
            while (seguir && (mensaje = reader.readLine()) != null) {
                System.out.println("📩Mensaje recibido del servidor: " + mensaje);
                protocolo.processInput(mensaje);
            }
        } catch (IOException e) {
            if (seguir) {
                System.err.println("❌Error en la hebra de escucha: " + e.getMessage());
            }
        }
    }
    
    public void detener() {
        seguir = false;
        try {
            inputStream.close();
        } catch (IOException e) {
            System.err.println("❌Error al cerrar el stream de entrada: " + e.getMessage());
        }
    }
    
}
