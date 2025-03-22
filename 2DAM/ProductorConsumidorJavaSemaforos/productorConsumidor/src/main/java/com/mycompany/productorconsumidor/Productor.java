/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.productorconsumidor;

/**
 *
 * @author Hanok
 * @version 3.0
 * @16/01/2025
 */
public class Productor implements Runnable{
//        private final BufferSemaforo bufferSemaforo;
        private final boolean terminaProd;
        private final BufferCerrojo bufferCerrojo;

//        public Productor(BufferSemaforo buffer, boolean terminaProd) {
//            this.buffer = buffer;
//            this.terminaProd = terminaProd;
//            
//        }
        
        public Productor(BufferCerrojo bufferCerrojo, boolean terminaProd) {
            this.bufferCerrojo = bufferCerrojo;
            this.terminaProd = terminaProd;
            
        }
        
        @Override
        public void run(){
            boolean continuar = true;
            try {
                while(continuar){
                    //bufferSemaforo.producir();
                    bufferCerrojo.producir();
                    Thread.sleep(1000);
                    
                    if(terminaProd){
                        continuar = false;
                    }
                }
            } catch (Exception e) {
                System.out.println("Productor interrumpido.");
            }
            
        }
        
        
    
}
