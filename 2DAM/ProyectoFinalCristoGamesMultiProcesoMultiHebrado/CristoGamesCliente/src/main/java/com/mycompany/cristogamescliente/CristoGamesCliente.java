/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristogamescliente;

import java.io.*;
import java.net.Socket;

/**
 *
 * @author hanokme
 */
public class CristoGamesCliente {
    
    
    public static void main(String[] args){
        String host = "localhost";
        int puerto = 4444;
        ControladorCliente controlador = new ControladorCliente(host, puerto);
        controlador.mostrarLogin();
        
    }
    
}


