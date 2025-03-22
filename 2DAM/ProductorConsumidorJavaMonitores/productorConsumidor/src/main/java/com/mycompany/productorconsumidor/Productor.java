/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.productorconsumidor;

/**
 *
 * @author Hanok
 * @version 4.0
 * @17/01/2025
 */
public class Productor implements Runnable{
        private final boolean terminaProd;
        private final BufferMonitor bufferMonitor;


        
        public Productor(BufferMonitor bufferMonitor, boolean terminaProd) {
            this.bufferMonitor = bufferMonitor;
            this.terminaProd = terminaProd;
            
        }
        
        @Override
        public void run(){
            boolean continuar = true;
            try {
                while(continuar){
                    bufferMonitor.producir();
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
