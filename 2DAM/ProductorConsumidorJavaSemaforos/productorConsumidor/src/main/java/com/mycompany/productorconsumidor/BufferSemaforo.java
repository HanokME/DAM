/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.productorconsumidor;

import java.util.concurrent.Semaphore;

/**
 *
 * @author Hanok
 * @version 1.0
 * @14/01/2025
 */
public class BufferSemaforo {
    
        private final int[] buffer; //Seria mas conveniente que sea un arraList para que sirva para cualquier tipo
        private final int maxSize;
        private int in = 0;
        private int out = 0;
        private int count = 0;
        private final Semaphore espacioVacio;
        private final Semaphore espacioLleno;
        private final Semaphore mutex;
        
        
        public BufferSemaforo(int maxSize){
            this.buffer = new int[maxSize];
            this.maxSize = maxSize;
            this.espacioVacio = new Semaphore(maxSize); 
            this.espacioLleno = new Semaphore(0); 
            this.mutex = new Semaphore(1);
        }
        
        public void producir() throws InterruptedException{
            try {
                espacioVacio.acquire();
                mutex.acquire();
                
                buffer[in] = 1;
                System.out.println("Hebra productora ha producido en la posición: " + in);
                in = (in + 1) % maxSize;
                count++;
  
                imprimirBuffer();
                
                mutex.release();
                espacioLleno.release();
            } catch (InterruptedException e) {
                System.out.println("com.mycompany.productorconsumidor.Buffer.producir()");
            } 

        }
        
        public int consumir() throws InterruptedException{
                int item = buffer[out];
            try {
                espacioLleno.acquire();
                mutex.acquire();
 
                System.out.println("Hebra consumidora ha consumido en la posición: " + out);
                buffer[out] = 0;
                out = (out + 1) % maxSize;
                count--;
                imprimirBuffer();
                
                mutex.release();
                espacioVacio.release();
                
                
            } catch (Exception e) {
                System.out.println("com.mycompany.productorconsumidor.Buffer.consumir()");
                
            }
            return item;

        }
        
        private void imprimirBuffer(){
            System.out.print("Estado del buffer: [ ");
            for (int i = 0; i < maxSize; i++) {

                    System.out.print(buffer[i] + " ");
            }
            System.out.println("]");
        }
        
        
    
}
