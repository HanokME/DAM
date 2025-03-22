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
public class Consumidor implements Runnable{
        private final boolean terminaCons;
        private final BufferMonitor bufferMonitor;


    public Consumidor(BufferMonitor bufferMonitor, boolean terminaCons){
        this.bufferMonitor = bufferMonitor;
        this.terminaCons = terminaCons;
    }
        
    
    @Override
        public void run(){
            boolean continuar = true;
            try {
                while(continuar){
                    bufferMonitor.consumir();
                    Thread.sleep(1500);
                    
                    if(terminaCons){
                        continuar = false;
                    }
                }
            } catch (Exception e) {
                System.out.println("Consumidor interrumpido.");
            }
            
        }
    
}
