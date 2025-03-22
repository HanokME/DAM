/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cristogamescliente;


import java.util.Map;
import javax.swing.SwingUtilities;

/**
 *
 * @author hanokme
 */
public class ControladorCliente {
    
    private ProtocoloCliente protocolo;
    private VentanaLogin ventanaLogin;
    private VentanaPrincipal ventanaPrincipal;
    private VentanaJuego ventanaJuego;
    private VentanaResenia ventanaResenia;
    
    private String currentUser;
    private String currentToken;
    private String currentUsername;
    
    public ControladorCliente(String serverIP, int portNumber){
        this.protocolo = new ProtocoloCliente(serverIP, portNumber);
        this.protocolo.setControlador(this);
    }
    
    public void mostrarLogin(){
        ventanaLogin = new VentanaLogin(this);
        ventanaLogin.setVisible(true);
    }
    
    public void mostrarVentanaPrincipal(Map<String, Object> datosUsuario){
        SwingUtilities.invokeLater(() -> {
            if (ventanaPrincipal != null) {
                ventanaPrincipal.dispose(); // Cierra la anterior si existe
            }
                 
            ventanaPrincipal = new VentanaPrincipal(this, datosUsuario);
            ventanaPrincipal.setVisible(true);
            
            protocolo.solicitarImagenPerfil(currentUser, currentUsername, currentToken, ventanaPrincipal);
            
        });
        
        
    }
    
    public void mostrarVentanaResenia(int idJuego){
        SwingUtilities.invokeLater(() -> {
            if (ventanaResenia != null) {
                ventanaResenia.dispose();
            }
            ventanaResenia = new VentanaResenia(this, idJuego);
            ventanaResenia.setVisible(true);
        });
    }
    
    public void mostrarVentanaJuego(int idJuego){
        SwingUtilities.invokeLater(() -> {
            if (ventanaJuego != null) {
                ventanaJuego.dispose();
            }
            Map<String, Object> datosJuego = solicitarInfoJuego(idJuego);

            if (datosJuego != null) {
                ventanaJuego = new VentanaJuego(this, datosJuego);
                ventanaJuego.setVisible(true);
            } else {
                System.err.println("❌ Error al obtener la información del juego.");
            }
        });
    }
    
    public String iniciarSesion(String correo, String pass){
        String mensaje = "PROTOCOLCRISTOGAMES1.0#" + protocolo.obtenerHora() + "#LOGIN#" + correo + "#" + pass;
        System.out.println("📩Enviando mensaje de login: " + mensaje);

        String respuesta = protocolo.enviarMensaje(mensaje);
        System.out.println("📩Respuesta recibida del servidor: " + respuesta);

        if (respuesta != null && respuesta.contains("WELLCOME")) {
            String[] partes = respuesta.split("#");

            if (partes.length >= 6) {
                this.currentUser = partes[3];
                this.currentToken = partes[5];
                System.out.println("✅Login exitoso. Usuario: " + currentUser + " | Token: " + currentToken);

                Map<String, Object> datosUsuario = solicitarInfoUsuario();
                if (datosUsuario != null) {
                    this.currentUsername = (String) datosUsuario.get("username");

                    SwingUtilities.invokeLater(() -> {
                        mostrarVentanaPrincipal(datosUsuario);
                        ventanaLogin.limpiarCampos();
                    });
                } else {
                    System.err.println("❌No se pudo obtener la información del usuario.");
                    return "❌Error al obtener datos del usuario.";
                }
            } else {
                System.err.println("❌ Respuesta del servidor mal formada.");
                return "❌Respuesta inválida del servidor.";
            }
        } else {
            System.err.println("❌Fallo en la autenticación. Respuesta: " + respuesta);
            return "❌Error de autenticación.";
        }

        return "✅Sesión iniciada correctamente.";
    

    }
    
    public void cerrarSesion(){
        if (currentUser == null || currentToken == null) {
            System.out.println("No hay usuario logueado para cerrar sesión.");
            return;
        }

        String mensaje = "PROTOCOLCRISTOGAMES1.0#" + protocolo.obtenerHora() + "#BYEBYE#" + currentUser + "#WITH_TOKEN#" + currentToken;
        System.out.println("📩Enviando mensaje de logout: " + mensaje);

        protocolo.enviarMensaje(mensaje);
        protocolo.cerrarConexion();

        SwingUtilities.invokeLater(() -> {
            if (ventanaPrincipal != null) {
                ventanaPrincipal.dispose();
                ventanaPrincipal = null;
            }
            ventanaLogin.setVisible(true);
        });

        System.out.println("✅Sesión cerrada correctamente.");
    }
    
    public Map<String, Object> solicitarInfoUsuario() {
        System.out.println("📩Enviando solicitud de información del usuario...");
        if (currentUser == null || currentToken == null) {
            System.err.println("❌No hay usuario autenticado.");
            return null;
        }
        Map<String, Object> datosUsuario = protocolo.obtenerInfoUsuario(currentUser, currentToken);
        if (datosUsuario != null) {
            this.currentUsername = (String) datosUsuario.get("username");
            System.out.println("✅Información del usuario recibida correctamente.");
        }
        return datosUsuario;
    }
    
    public Map<String, Object> solicitarInfoJuego(int idJuego) {
        if (currentUser == null || currentToken == null) {
            System.err.println("❌No hay usuario autenticado.");
            return null;
        }
        return protocolo.obtenerInfoJuego(idJuego, currentUser, currentToken);
    }
    

    public void enviarResenia(int idJuego, String texto, int puntuacion) {
        protocolo.enviarResenia(idJuego, currentUser, currentToken, texto, puntuacion);
        
        
    }
    

    
    public void manejarBroadcastResenia(int idJuego,String username,String texto,int puntuacion,String fecha,String nombreJuego,Double calificacionMedia) {
        System.out.println("📩 Procesando reseña en la interfaz...");

        // Si la ventana del juego está abierta, recargar datos
        if (ventanaJuego != null && ventanaJuego.idJuego == idJuego) {
            System.out.println("🔄Recargando datos en VentanaJuego");
            SwingUtilities.invokeLater(() -> ventanaJuego.recargarDatosJuego());
        } else {
            System.out.println("VentanaJuego no abierta o diferente al juego actualizado.");
        }

        // Si la ventana principal está abierta, actualizar las reseñas globales
        if (ventanaPrincipal != null) {
            System.out.println("📩Añadiendo reseña global a la ventana principal...");

            SwingUtilities.invokeLater(() -> {
                ventanaPrincipal.agregarReseniaGlobal(username, texto, puntuacion, nombreJuego, calificacionMedia, idJuego);
            });

        } else {
            System.out.println("VentanaPrincipal no está abierta, la reseña no se mostrará.");
        }
    }
}