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
public class Consumidor implements Runnable{
        //private final BufferSemaforo bufferSemaforo;
        private final boolean terminaCons;
        private final BufferCerrojo bufferCerrojo;

//    public Consumidor(BufferSemaforo bufferSemaforo, boolean terminaCons) {
//        this.bufferSemaforo = bufferSemaforo;
//        this.terminaCons = terminaCons;
//        
//    }
    public Consumidor(BufferCerrojo bufferCerrojo, boolean terminaCons){
        this.bufferCerrojo = bufferCerrojo;
        this.terminaCons = terminaCons;
    }
        
    
    @Override
        public void run(){
            boolean continuar = true;
            try {
                while(continuar){
                    //bufferSemaforo.consumir();
                    bufferCerrojo.consumir();
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
