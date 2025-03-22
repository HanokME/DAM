/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Alex
 */

@Entity
@Table(name="genero")
public class Genero implements Serializable {
    
    //Atributos
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name="idGenero", nullable = false, unique = true)
    private Integer idGenero;
    
    @Column(name="nombre", length = 45, nullable = false)
    private String nombre;
    
    @OneToMany(mappedBy = "genero", fetch = FetchType.EAGER)
    private List<Juego> listaJuegos;
   
    
    //Constructor con parámetros
    public Genero(String nombre, List<Juego> listaJuegos) {
        this.nombre = nombre;
        this.listaJuegos = listaJuegos;
    }
    
    //Constructor con parámetros 2
    public Genero(String nombre) {
        this.nombre = nombre;
        this.listaJuegos = new ArrayList<>();
    }
    
    //Constructor sin parámetros
    public Genero() {
        this.listaJuegos = new ArrayList<>();
    }
    
    //Set's
    public void setIdGenero(Integer idGenero) {
        this.idGenero = idGenero;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    public void setListaJuegos(List<Juego> listaJuegos) {
        this.listaJuegos = listaJuegos;
    }
    
    //Get's
    public Integer getIdGenero() {
        return idGenero;
    }

    public String getNombre() {
        return nombre;
    }
    
    public List<Juego> getListaJuegos() {
        return listaJuegos;
    }

    @Override
    public String toString() {
        return "Genero{" + "idGenero=" + idGenero + ", nombre=" + nombre + '}';
    }
    
}
