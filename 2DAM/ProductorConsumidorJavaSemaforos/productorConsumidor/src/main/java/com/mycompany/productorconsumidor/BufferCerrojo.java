/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.productorconsumidor;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author Usuario
 */
public class BufferCerrojo {
    private final int[] buffer; //Seria mas conveniente que sea un arraList para que sirva para cualquier tipo
        private final int maxSize;
        private int in = 0;
        private int out = 0;
        private int count = 0;
        
        private final ReentrantLock lock = new ReentrantLock(); //Cerrojo
        private final Condition espacioDisponible = lock.newCondition(); //Condicion de espacio libre para producir
        private final Condition elementosDisponibles = lock.newCondition(); //Condicion de que hay elementos para consumir
        
        
        public BufferCerrojo(int maxSize){
            this.buffer = new int[maxSize];
            this.maxSize = maxSize;
        }
        
        public void producir() throws InterruptedException{
            lock.lock();
            try {
                while(count == maxSize){
                    espacioDisponible.await(); //Esperar si el buffer esta lleno
                }
                
                buffer[in] = 1;
                System.out.println("Hebra productora ha producido en la posición: " + in);
                in = (in + 1) % maxSize;
                count++;
  
                imprimirBuffer();
                
                elementosDisponibles.signal(); //notificar a los consumidores de que hay elementos del buffer disponibles par consumir
            } catch (InterruptedException e) {
                System.out.println("com.mycompany.productorconsumidor.Buffer.producir()");
            } finally { 
                lock.unlock();
        } 

        }
        
        public void consumir() throws InterruptedException{
            lock.lock();
                int item = buffer[out];
            try {
                while(count == 0){
                    elementosDisponibles.await();
                }
 
                System.out.println("Hebra consumidora ha consumido en la posición: " + out);
                buffer[out] = 0;
                out = (out + 1) % maxSize;
                count--;
                imprimirBuffer();
                
                espacioDisponible.signal();
                
                
                
            } catch (Exception e) {
                System.out.println("com.mycompany.productorconsumidor.Buffer.consumir()");
                
            } finally {
                lock.unlock();
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
