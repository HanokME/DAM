/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import jakarta.persistence.Embeddable;
import java.io.Serializable;
import java.time.LocalDateTime;

/**
 *
 * @author Alex
 */

@Embeddable
public class PKCompuestaResenia implements Serializable {
    
    private String username;
    private Integer idJuego;
    private LocalDateTime fecha;
    
    //Constructor con parámetros
    public PKCompuestaResenia(String username, Integer idJuego, LocalDateTime fecha) {
        this.username = username;
        this.idJuego = idJuego;
        this.fecha = fecha;
    }
    
    //Constructor sin parámetros
    public PKCompuestaResenia() {
        
    }
    
    //Set's
    public void setUsername(String username) {
        this.username = username;
    }

    public void setIdJuego(Integer idJuego) {
        this.idJuego = idJuego;
    }

    public void setFecha(LocalDateTime fecha) {
        this.fecha = fecha;
    }
    
    //Get's
    public String getUsername() {
        return username;
    }

    public Integer getIdJuego() {
        return idJuego;
    }

    public LocalDateTime getFecha() {
        return fecha;
    }  

    @Override
    public String toString() {
        return "PKCompuestaResenia{" + "username=" + username + ", idJuego=" + idJuego + ", fecha=" + fecha + '}';
    }
}
