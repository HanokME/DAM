/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;
import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Alex
 */

@Entity
@Table(name="juego")
public class Juego implements Serializable {
    
    //Atributos
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name="idJuego", nullable = false, unique = true)
    private Integer idJuego;
    
    @Column(name="nombre", length = 45, nullable = false)
    private String nombre;
    
    @Column(name="estudio", length = 45, nullable = false)
    private String estudio;
    
    @Column(name="caratula", length = 100, nullable = true)
    private String caratula;
    
    @Column(name="lanzamiento", nullable = false)
    private LocalDate lanzamiento;
    
    @Column(name="calificacionMedia", nullable = false)
    private Double calificacionMedia;
    
    @Column(name="destacado", nullable = false)
    private Boolean destacado;
    
    @ManyToOne
    @JoinColumn(name = "idGenero")
    private Genero genero;
    
    @ManyToMany(mappedBy = "listaJuegosJugados", fetch = FetchType.EAGER)
    private List<Perfil> listaPerfilesJugadores;
    
    @OneToMany(mappedBy = "juego", fetch = FetchType.EAGER)
    private List<Resenia> listaResenias;
    
    //Constructor con parámetros
    public Juego(String nombre, String estudio, String caratula, LocalDate lanzamiento, Double calificacionMedia, Boolean destacado, Genero genero, List<Perfil> listaPerfilesJugadores, List<Resenia> listaResenias) {
        this.nombre = nombre;
        this.estudio = estudio;
        this.caratula = caratula;
        this.lanzamiento = lanzamiento;
        this.genero = genero;
        this.calificacionMedia = calificacionMedia;
        this.destacado = destacado;
        this.listaPerfilesJugadores = listaPerfilesJugadores;
        this.listaResenias = listaResenias;
    }
    
    //Constructor con parámetros 2
    public Juego(String nombre, String estudio, String caratula, LocalDate lanzamiento, Double calificacionMedia, Boolean destacado, Genero genero) {
        this.nombre = nombre;
        this.estudio = estudio;
        this.caratula = caratula;
        this.lanzamiento = lanzamiento;
        this.genero = genero;
        this.calificacionMedia = calificacionMedia;
        this.destacado = destacado;
        this.listaPerfilesJugadores = new ArrayList<>();
        this.listaResenias = new ArrayList<>();
    }
    
    //Constructor sin parámetros
    public Juego() {
        this.genero = new Genero();
        this.listaPerfilesJugadores = new ArrayList<>();
        this.listaResenias = new ArrayList<>();
    }
    
    //Set's
    public void setIdJuego(Integer idJuego) {
        this.idJuego = idJuego;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setEstudio(String estudio) {
        this.estudio = estudio;
    }

    public void setCaratula(String caratula) {
        this.caratula = caratula;
    }

    public void setLanzamiento(LocalDate lanzamiento) {
        this.lanzamiento = lanzamiento;
    }

    public void setGenero(Genero genero) {
        this.genero = genero;
    }

    public void setListaPerfilesJugadores(List<Perfil> listaPerfilesJugadores) {
        this.listaPerfilesJugadores = listaPerfilesJugadores;
    }

    public void setListaResenias(List<Resenia> listaResenias) {
        this.listaResenias = listaResenias;
    }

    public void setCalificacionMedia(Double calificacionMedia) {
        this.calificacionMedia = calificacionMedia;
    }

    public void setDestacado(Boolean destacado) {
        this.destacado = destacado;
    }
    
    //Get's
    public Integer getIdJuego() {
        return idJuego;
    }

    public String getNombre() {
        return nombre;
    }

    public String getEstudio() {
        return estudio;
    }

    public String getCaratula() {
        return caratula;
    }

    public LocalDate getLanzamiento() {
        return lanzamiento;
    }

    public Genero getGenero() {
        return genero;
    }

    public List<Perfil> getListaPerfilesJugadores() {
        return listaPerfilesJugadores;
    }

    public List<Resenia> getListaResenias() {
        return listaResenias;
    }

    public Double getCalificacionMedia() {
        return calificacionMedia;
    }

    public Boolean getDestacado() {
        return destacado;
    }

    @Override
    public String toString() {
        return "Juego{" + "idJuego=" + idJuego + ", nombre=" + nombre + ", estudio=" + estudio + ", caratula=" + caratula + ", lanzamiento=" + lanzamiento + ", genero=" + genero + ", destacado=" + destacado+ '}';
    }    
    
}