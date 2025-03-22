/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import jakarta.persistence.Query;
import java.time.LocalDateTime;
import java.util.List;
import org.hibernate.Session;

/**
 *
 * @author natal
 */
public class Conexion {
    //constructores
    public Conexion(){
    }
    
    public List<Genero> leerGeneros() {
        List<Genero> listaGeneros = null; 
        Session sesion = null;
        try {
            sesion = HibernateUtil.getCurrentSession();
            Query query = sesion.createQuery("FROM Genero", Genero.class);            
            listaGeneros = query.getResultList();            
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        } finally {
            if (sesion != null && sesion.isOpen()) {
                sesion.close();
            }
        }
        return listaGeneros;
    }
    
    public Genero obtenerGeneroPorId( Integer id ) {
        Genero genero = null;
            
        try {
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            genero = sesion.get(Genero.class, id);
            sesion.getTransaction().commit();
            sesion.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }        
        return genero;
    }
    
    public List<Juego> leerJuegos(){
        List<Juego> listaJuegos = null; 
        Session sesion = null;
        try {
            sesion = HibernateUtil.getCurrentSession();
            Query query = sesion.createQuery("FROM Juego", Juego.class);            
            listaJuegos = query.getResultList();            
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        } finally {
            if (sesion != null && sesion.isOpen()) {
                sesion.close();
            }
        }
        return listaJuegos;
    }
    
    public Juego obtenerJuegoPorId( Integer id ){
        Juego juego = null;
            
        try {
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            juego = sesion.get(Juego.class, id);
            sesion.getTransaction().commit();
            sesion.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }        
        return juego;
    }
    
    public List<Perfil> leerPerfiles() {
        List<Perfil> listaPerfiles = null; 
        Session sesion = null;
        try {
            sesion = HibernateUtil.getCurrentSession();
            Query query = sesion.createQuery("FROM Perfil", Perfil.class);            
            listaPerfiles = query.getResultList();            
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        } finally {
            if (sesion != null && sesion.isOpen()) {
                sesion.close();
            }
        }
        return listaPerfiles;
    }
    
    public Perfil obtenerPerfilPorUsername( String username ){
        Perfil perfil = null;
            
        try {
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            perfil = sesion.get(Perfil.class, username);
            sesion.getTransaction().commit();
            sesion.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }        
        return perfil;
    }
    
    public List<Usuario> leerUsuarios(){
        List<Usuario> listaUsuarios = null; 
        Session sesion = null;
        try {
            sesion = HibernateUtil.getCurrentSession();
            Query query = sesion.createQuery("FROM Usuario", Usuario.class);            
            listaUsuarios = query.getResultList();            
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        } finally {
            if (sesion != null && sesion.isOpen()) {
                sesion.close();
            }
        }
        return listaUsuarios;
    }
    
    public Usuario obtenerUsuarioPorCorreo( String correo ){
        Usuario usuario = null;
            
        try {
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            usuario = sesion.get(Usuario.class, correo);
            sesion.getTransaction().commit();
            sesion.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }        
        return usuario;
    }
    
    public List<Resenia> leerResenias() throws Exception{
        List<Resenia> listaResenias = null; 
        Session sesion = null;
        try {
            sesion = HibernateUtil.getCurrentSession();
            Query query = sesion.createQuery("FROM Resenia", Resenia.class);            
            listaResenias = query.getResultList();            
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        } finally {
            if (sesion != null && sesion.isOpen()) {
                sesion.close();
            }
        }
        return listaResenias;
    }
    
    public Resenia obtenerReseniaPorPK( PKCompuestaResenia pk ) {
        Resenia resenia = null;
            
        try {
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            resenia = sesion.get(Resenia.class, pk);
            sesion.getTransaction().commit();
            sesion.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }        
        return resenia;
    }
    
    public void insertarGenero( Genero genero ){
        try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            sesion.persist(genero);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void insertarJuego( Juego juego ){
        try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            sesion.persist(juego);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void insertarPerfil( Perfil perfil ){
         try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            sesion.persist(perfil);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void insertarUsuario( Usuario usuario ) {
         try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            sesion.persist(usuario);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void insertarResenia( String username, Integer idJuego, String texto, Integer calificacion ) {
         try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            Juego juego = sesion.get(Juego.class, idJuego);
            Perfil perfil = sesion.get(Perfil.class, username);
            LocalDateTime fechaConHora = LocalDateTime.now();
            PKCompuestaResenia pk = new PKCompuestaResenia(username, idJuego, fechaConHora);
            Resenia resenia = new Resenia(pk,perfil,juego,texto,calificacion);
            sesion.persist(resenia);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void insertarJugada( Integer idJuego, String username ) {
         try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            Juego juego = sesion.get(Juego.class, idJuego);
            Perfil perfil = sesion.get(Perfil.class, username);
            juego.getListaPerfilesJugadores().add(perfil);
            perfil.getListaJuegosJugados().add(juego);
            sesion.update(juego);
            sesion.update(perfil);
            
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void eliminarGenero( Integer idGenero ){
        try {
            Session sesion = HibernateUtil.getCurrentSession();
            Genero genero = sesion.get(Genero.class, idGenero);
            sesion.beginTransaction();            
            sesion.delete(genero);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }      
    }
    
    public void eliminarJuego( Integer idJuego ) {
         try {
            Session sesion = HibernateUtil.getCurrentSession();   
            sesion.beginTransaction();             
            Juego juego = sesion.get(Juego.class, idJuego); 
            sesion.delete(juego);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }     
    }
    
    public void eliminarPerfil( String username ){
         try {
            Session sesion = HibernateUtil.getCurrentSession();
            Perfil perfil = sesion.get(Perfil.class, username);
            sesion.beginTransaction();            
            sesion.delete(perfil);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }     
    }
    
    public void eliminarUsuario( String correo ) {
         try {
            Session sesion = HibernateUtil.getCurrentSession();
            Usuario usuario = sesion.get(Usuario.class, correo);
            sesion.beginTransaction();            
            sesion.delete(usuario);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }     
    }
    
    public void eliminarResenia( PKCompuestaResenia pk ) {
         try {
            Session sesion = HibernateUtil.getCurrentSession();
            Resenia resenia = sesion.get(Resenia.class, pk);
            sesion.beginTransaction();            
            sesion.delete(resenia);
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }     
    }
    
    public void eliminarJugada( Integer idJuego, String username ) {
         try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            Juego juego = sesion.get(Juego.class, idJuego);
            Perfil perfil = sesion.get(Perfil.class, username);
            juego.getListaPerfilesJugadores().remove(perfil);
            perfil.getListaJuegosJugados().remove(juego);
            sesion.update(juego);
            sesion.update(perfil);
            
            sesion.getTransaction().commit();
            sesion.close();
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void modificarGenero( Genero genero ) {
        try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            sesion.update(genero);
            
            sesion.getTransaction().commit();
            sesion.close();     
        } catch ( Exception e ){
            System.out.println(e.getMessage());
            throw e;
        }
    }
    
    public void modificarJuego( Juego juego ) {
         try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            sesion.update(juego);
            
            sesion.getTransaction().commit();
            sesion.close();     
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void modificarPerfil( Perfil perfil ){
         try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            sesion.update(perfil);
            
            sesion.getTransaction().commit();
            sesion.close();     
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void modificarUsuario( Usuario usuario ) {
         try{
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();
            
            sesion.update(usuario);
            
            sesion.getTransaction().commit();
            sesion.close();     
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void modificarResenia( Resenia resenia ) {
         try{
            eliminarResenia(resenia.getpK());            
            insertarResenia(resenia.getpK().getUsername(), resenia.getpK().getIdJuego(), resenia.getTexto(), resenia.getCalificacion());

        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void modificarJugada( Integer idJuego, String username, Integer idJuegoNuevo, String usernameNuevo ){
         try{
            //eliminar actual
            eliminarJugada(idJuego, username);
         
            //insertar nuevo
            insertarJugada(idJuegoNuevo, usernameNuevo);
            
        
        } catch ( Exception e ){
            System.out.println(e.getMessage());
        }
    }
    
    public void cerrarBaseDeDatos() {
        HibernateUtil.closeSessionFactory();
    }
    
    public double actualizarCalificacionMedia(Integer idJuego){
        double nuevaCalificacionMedia = 0.0;

        try {
            Session sesion = HibernateUtil.getCurrentSession();
            sesion.beginTransaction();

            Juego juego = sesion.get(Juego.class, idJuego);
            if (juego != null) {
                Query query = sesion.createQuery("SELECT COALESCE(AVG(r.calificacion), 0.0) FROM Resenia r WHERE r.juego.idJuego = :idJuego");
                query.setParameter("idJuego", idJuego);
                Double resultado = (Double) query.getSingleResult();

                if (resultado != null) {
                    nuevaCalificacionMedia = resultado;
                    juego.setCalificacionMedia(nuevaCalificacionMedia);
                    sesion.update(juego);
                }
            }

            sesion.getTransaction().commit();
            sesion.close();
        } catch (Exception e) {
            System.out.println("❌Error al actualizar la calificación media: " + e.getMessage());
        }

        return nuevaCalificacionMedia;
    }
}
