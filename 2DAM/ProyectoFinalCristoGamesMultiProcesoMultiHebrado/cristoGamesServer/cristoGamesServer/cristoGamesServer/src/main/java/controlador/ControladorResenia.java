/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controlador;

import java.time.LocalDateTime;
import modelo.Conexion;
import modelo.Juego;
import modelo.Usuario;

/**
 *
 * @author hanokme
 */
public class ControladorResenia {
    
    private final Conexion conexion;
    
    public ControladorResenia(){
        this.conexion = new Conexion();
    }
    
    
    public void agregarResenia(String userName, int idJuego, String textoResenia, int puntuacion){
        Usuario usuario = conexion.obtenerUsuarioPorCorreo(userName);
        Juego juego = conexion.obtenerJuegoPorId(idJuego);

        if (usuario == null) {
            System.err.println("❌ERROR: Usuario " + userName + " no encontrado en la BD.");
            
        }
        if (juego == null) {
            System.err.println("❌ERROR: Juego con ID " + idJuego + " no encontrado en la BD.");
            
        }

        try {
            conexion.insertarResenia(userName, idJuego, textoResenia, puntuacion);
            System.out.println("✅Reseña insertada correctamente en la BD.");
           
        } catch (Exception e) {
            System.err.println("❌ERROR: No se pudo insertar la reseña en la BD: " + e.getMessage());
            
        }

        

        
    }
    
    public double obtenerCalificacionMedia(int idJuego){
        double calificacion = 0.0;
        
        calificacion = conexion.actualizarCalificacionMedia(idJuego);
        
        return calificacion;
    }
    
}
