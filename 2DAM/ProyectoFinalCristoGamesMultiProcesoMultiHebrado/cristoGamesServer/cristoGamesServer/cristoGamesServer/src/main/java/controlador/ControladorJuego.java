/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controlador;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Map;
import modelo.Conexion;
import modelo.Juego;
import modelo.Resenia;
/**
 *
 * @author hanokme
 */
public class ControladorJuego {
    
    private final Conexion conexion;
    
    public ControladorJuego(){
        this.conexion = new Conexion();
    }
    
    
    public Juego obtenerJuego(int idJuego){

        Juego juego = conexion.obtenerJuegoPorId(idJuego);
        return juego;
        
    }
    
    public List<Juego> obtenerJuegosDestacados(){
        
        List<Juego> juegosDestacados = conexion.leerJuegos()
                .stream()
                .filter(Juego::getDestacado)
                .toList();

        return juegosDestacados;
    }
    
    public List<Resenia> obtenerReseniasPorJuego(int idJuego) {
        Juego juego = conexion.obtenerJuegoPorId(idJuego);
        List<Resenia> resenias = juego.getListaResenias();

        return resenias;
    }

    
    
    public String obtenerHora(){
        return new SimpleDateFormat("HH:mm:ss").format(new Date());
    }
}
