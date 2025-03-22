package com.mycompany.cristogamescliente;

import java.io.*;
import java.util.Base64;
import java.util.Map;
import java.util.TreeMap;
import javax.swing.SwingUtilities;

/**
 * Hebra que maneja la recepción de imágenes enviadas en fragmentos
 */
public class ClientImageThread extends Thread {
    private BufferedReader in;
    private InputStream inStream;
    private PrintWriter out;
    private String correo, username, token;
    private long fileSize;
    private VentanaPrincipal ventana;

    public ClientImageThread(InputStream inStream, PrintWriter out, String correo, String username, String token, long fileSize, VentanaPrincipal ventana) {
        this.in = new BufferedReader(new InputStreamReader(inStream));
        this.out = out;
        this.correo = correo;
        this.username = username;
        this.token = token;
        this.fileSize = fileSize;
        this.ventana = ventana;
    }

    @Override
    public void run() {
        long receivedBytes = 0;
        Map<Integer, byte[]> paquetes = new TreeMap<>();
        System.out.println("📡Hilo de recepción de imagen iniciado. Esperando paquetes...");

        try {
            String mensaje;

            // Recibir paquetes de la imagen
            while (receivedBytes < fileSize) {
                mensaje = in.readLine();
                System.out.println(mensaje);
                

                String[] partes = mensaje.split("#");
                
                
                int paqueteId = Integer.parseInt(partes[8]);
                String dataBas64 = partes[10];
                byte[] bytesChunk = Base64.getDecoder().decode(dataBas64);
                paquetes.put(paqueteId, bytesChunk);
                receivedBytes += bytesChunk.length;
                
                
                System.out.println("Paquete recibido [ID: " + paqueteId + "] - " + receivedBytes + "/" + fileSize + " bytes recibidos.");
            }

            //Convertir a imagen
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            for (byte[] chunk : paquetes.values()) {
                baos.write(chunk);
            }
            byte[] imageBuffer = baos.toByteArray();
            baos.close();

            //Verificar que el tamaño recibido es correcto
            if (imageBuffer.length != fileSize) {
                System.err.println("Advertencia: Tamaño de imagen incorrecto. Recibido: " + imageBuffer.length + ", esperado: " + fileSize);
                return;
            }

            // Guardar la imagen en el disco para depuración
            FileOutputStream fos = new FileOutputStream("imagen_recibida.png");
            fos.write(imageBuffer);
            fos.close();
            System.out.println("Imagen guardada como 'imagen_recibida.png' para verificación.");

            System.out.println("Imagen recibida correctamente.");
            
            SwingUtilities.invokeLater(() -> ventana.actualizarImagenPerfil(imageBuffer));

            //Enviar confirmación al servidor
            String confirmacion = "PROTOCOLCRISTOGAMES1.0#" + System.currentTimeMillis()
                    + "#GET_PROFILE_IMAGE#" + correo + "#" + username + "#WITH_TOKEN#" + token
                    + "#RECEIVED_AND_FINISHED";

            out.println(confirmacion);
            out.flush();
            System.out.println("Confirmación de recepción enviada al servidor.");

        } catch (IOException e) {
            System.err.println("Error al recibir imagen: " + e.getMessage());
        }
    }


}