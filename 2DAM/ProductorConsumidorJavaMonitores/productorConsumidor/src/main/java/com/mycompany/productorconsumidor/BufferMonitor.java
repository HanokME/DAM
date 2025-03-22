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
public class BufferMonitor {
        private final int[] buffer; //Seria mas conveniente que sea un arraList para que sirva para cualquier tipo
        private final int maxSize;
        private int in = 0;
        private int out = 0;
        private int count = 0;

        
        
        public BufferMonitor(int maxSize){
            this.buffer = new int[maxSize];
            this.maxSize = maxSize;
        }
        
        public synchronized void producir() throws InterruptedException{
            try {
                while(count == maxSize){
                    wait(); //Esperar si el buffer esta lleno
                }
                
                buffer[in] = 1;
                System.out.println("Hebra productora ha producido en la posición: " + in);
                in = (in + 1) % maxSize;
                count++;
  
                imprimirBuffer();
                
                notifyAll();
            } catch (InterruptedException e) {
                System.out.println("com.mycompany.productorconsumidor.Buffer.producir()");
            } 

        }
        
        public synchronized void consumir() throws InterruptedException{

                int item = buffer[out];
            try {
                while(count == 0){
                    wait();
                }
 
                System.out.println("Hebra consumidora ha consumido en la posición: " + out);
                buffer[out] = 0;
                out = (out + 1) % maxSize;
                count--;
                imprimirBuffer();
                
                notifyAll();
                
                
                
            } catch (Exception e) {
                System.out.println("com.mycompany.productorconsumidor.Buffer.consumir()");
                
            } 

        }
        
        private void imprimirBuffer(){
            System.out.print("Estado del buffer: [ ");
            for (int i = 0; i < maxSize; i++) {

                    System.out.print(buffer[i] + " ");
            }
            System.out.println("]");
        }
    
}
