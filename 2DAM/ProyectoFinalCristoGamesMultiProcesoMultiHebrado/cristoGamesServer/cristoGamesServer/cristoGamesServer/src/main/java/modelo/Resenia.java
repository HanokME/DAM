/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import jakarta.persistence.Column;
import jakarta.persistence.EmbeddedId;
import jakarta.persistence.Entity;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.MapsId;
import jakarta.persistence.Table;

/**
 *
 * @author Alex
 */

@Entity
@Table(name="resenia")
public class Resenia {
    
    @EmbeddedId
    private PKCompuestaResenia pK;
    
    @ManyToOne
    @MapsId("username") // Mapea username en PKCompuestaResenia
    @JoinColumn(name = "username")
    private Perfil perfil;
    
    @ManyToOne
    @MapsId("idJuego")
    @JoinColumn(name = "idJuego") // La FK en la tabla resenia se llama "idJuego"
    private Juego juego;
    
    @Column(name = "texto", nullable = true)
    private String  texto;
    
    @Column(name = "calificacion", nullable = false)
    private Integer calificacion;
    
    public Resenia(){
        this.perfil = new Perfil();
        this.juego = new Juego();
    }
    
    public Resenia(PKCompuestaResenia pK, Perfil perfil, Juego juego, String texto, Integer calificacion) {
        this.pK = pK;
        this.perfil = perfil;
        this.juego = juego;
        this.texto = texto;
        this.calificacion = calificacion;
    }

    public Resenia(PKCompuestaResenia pK) {
        this.pK = pK;
        this.perfil = new Perfil();
        this.juego = new Juego();
        this.texto = " ";
        this.calificacion = 0;
    }

    public Integer getCalificacion() {
        return calificacion;
    }

    public void setCalificacion(int calificacion) {
        this.calificacion = calificacion;
    }

    public PKCompuestaResenia getpK() {
        return pK;
    }

    public Perfil getPerfil() {
        return perfil;
    }

    public Juego getJuego() {
        return juego;
    }

    public String getTexto() {
        return texto;
    }

    public void setpK(PKCompuestaResenia pK) {
        this.pK = pK;
    }

    public void setPerfil(Perfil perfil) {
        this.perfil = perfil;
    }

    public void setJuego(Juego juego) {
        this.juego = juego;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public void setCalificacion(Integer calificacion) {
        this.calificacion = calificacion;
    }

    @Override
    public String toString() {
        return "Resenia{" + "pK=" + pK + ", perfil=" + perfil + ", juego=" + juego + ", texto=" + texto + ", calificacion=" + calificacion + '}';
    }
    
}
