/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.productorconsumidor;


/**
 *
 * @author Hanok
 * @version 2.0
 * @15/01/2025
 */
public class ProductorConsumidor {

    public static void main(String[] args) throws InterruptedException{
        
        System.out.println("Programa iniciado...");
        
        int bufferSize = Integer.parseInt(args[0]);
        int numProd = Integer.parseInt(args[1]);
        boolean terminaProd = Boolean.parseBoolean(args[2]);
        int numCons = Integer.parseInt(args[3]);
        boolean terminaCons = Boolean.parseBoolean(args[4]);
        
        
        //BufferSemaforo bufferSemaforo = new BufferSemaforo(bufferSize);
        BufferCerrojo bufferCerrojo = new BufferCerrojo(bufferSize);
        
        Thread[] productores = new Thread[numProd];
        Thread[] consumidores = new Thread[numCons];
        
        
        //Crear las hebras
//        for(int i = 0; i < numProd; i++){
//            productores[i] = new Thread(new Productor(bufferSemaforo, terminaProd));
//            productores[i].start();
//        }
//        
//        for(int i = 0; i < numCons; i++){
//            consumidores[i] = new Thread(new Consumidor(bufferSemaforo, terminaCons));
//            consumidores[i].start();
//        }
        

        //Hebras de cerrojos
        for (int i = 0; i < numProd; i++) {
            productores[i] = new Thread(new Productor(bufferCerrojo, terminaProd));
            productores[i].start();
         }
        
        for(int i = 0; i < numCons; i++){
            consumidores[i] = new Thread(new Consumidor(bufferCerrojo, terminaCons));
            consumidores[i].start();
        }

        //Si son true espero a que terminen
        if(terminaProd){
            for(Thread productor : productores){
                productor.join();
            }
        }
        
        if(terminaCons){
            for (Thread consumidor : consumidores) {
                consumidor.join();
            }
        }
        
    }
}
