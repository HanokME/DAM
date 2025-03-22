/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controlador;
import java.util.List;
import modelo.HibernateUtil;
import modelo.Usuario;
import modelo.Conexion;
import modelo.Juego;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;
/**
 *
 * @author hanokme
 */
public class ControladorUsuario {
    private Conexion conexion;
    
    public ControladorUsuario(){
        conexion = new Conexion();
    }
    
    
    public Usuario obtenerUsuario(String correo){
        Usuario usuario = conexion.obtenerUsuarioPorCorreo(correo);
        return usuario;
    }
    
    
    /**
     * @brief Valida si un usuario con correo y contraseña existe en la DB
     * @param correo Correo del usuario a comprobar
     * @param password Contraseña del usuario a comprobar
     * @return True si las credenciales son validas, false si no.
     */
    public boolean validarCredencialesUsuario(String correo, String password){
        boolean esValido = false;
        Usuario usuario = conexion.obtenerUsuarioPorCorreo(correo);
        if (usuario != null){
            if(usuario.getContrasenia().equals(password)){
                esValido = true;
            }
        } 
            
        return esValido;
    }
    
    public boolean esUsuarioPremium(String correo){
        boolean esPremium = false;
        Usuario usuario = conexion.obtenerUsuarioPorCorreo(correo);
        if(usuario != null){
            if(usuario.getTipo().equalsIgnoreCase("premium")){
                esPremium = true;
            } 
        } 
        
        return esPremium;
    }
    
    public int getNumeroConexiones(String correo){
        int conexiones = 0;
        Usuario usuario = conexion.obtenerUsuarioPorCorreo(correo);
        if (usuario != null){
            conexiones = usuario.getNumeroConexiones();
        } 
        
        return conexiones;
    }
    
    public void incrementarConexiones(String correo){
        Usuario usuario = conexion.obtenerUsuarioPorCorreo(correo);
        if(usuario != null){
            usuario.setNumeroConexiones(usuario.getNumeroConexiones() + 1);
            conexion.modificarUsuario(usuario);
        }
    }
    
    /**
     * @brief Reduce el numero de conexiones activas cuando un usuario se desconecta
     * @param correo Correo del usuario que cierra sesion
     */
    public void cerrarSesion(String correo){
        Usuario usuario = conexion.obtenerUsuarioPorCorreo(correo);
        
        if(usuario != null){
            int conexionesActuales = usuario.getNumeroConexiones();
            if(conexionesActuales > 0){
                usuario.setNumeroConexiones(conexionesActuales - 1);
                conexion.modificarUsuario(usuario);
            }
        }
    }
    
    public List<Juego> obtenerJuegosJugados(String correo){
        List<Juego> juegosJugados = List.of();
        Usuario usuario = obtenerUsuario(correo);
        
        juegosJugados = usuario.getPerfil().getListaJuegosJugados();
        
        return juegosJugados;
    }
    
    
    
  
}
