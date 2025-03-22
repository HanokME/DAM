/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.JoinTable;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.OneToMany;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Alex
 */

@Entity
@Table(name="perfil")
public class Perfil implements Serializable {
    
    //Atributos
    @Id
    @Column(name="username", nullable = false, length = 30, unique = true)
    private String username;
    
    @Column(name="avatar", length = 100, nullable = false)
    private String avatar;
    
    @Column(name="biografia", nullable = false)
    private String biografia;
    
    @ManyToMany(fetch = FetchType.EAGER)
    @JoinTable(
        name = "juega",
        joinColumns = @JoinColumn(name = "username"),
        inverseJoinColumns = @JoinColumn(name = "idJuego")
    )
    private List<Juego> listaJuegosJugados;
    
    @OneToMany(mappedBy = "perfil", fetch = FetchType.EAGER)
    private List<Resenia> listaJuegosReseniados;
    
    @OneToOne(mappedBy = "perfil")
    private Usuario usuario;
    
    //Constructor con parámetros
    public Perfil(String username, String avatar, String biografia, List<Juego> listaJuegosJugados, List<Resenia> listaJuegosReseniados, Usuario usuario) {
        this.username = username;
        this.avatar = avatar;
        this.biografia = biografia;
        this.listaJuegosJugados = listaJuegosJugados;
        this.listaJuegosReseniados = listaJuegosReseniados;
        this.usuario = usuario;
    }
    
    //Constructor con parámetros 2
    public Perfil(String username, String avatar, String biografia) {
        this.username = username;
        this.avatar = avatar;
        this.biografia = biografia;
        this.listaJuegosJugados = new ArrayList<>();
        this.listaJuegosReseniados = new ArrayList<>();
        this.usuario = new Usuario();
    }
    
    //Constructor sin parámetros
    public Perfil() {
        this.listaJuegosJugados = new ArrayList<>();
        this.listaJuegosReseniados = new ArrayList<>();
    }

    //Set's
    public void setUsername(String username) {
        this.username = username;
    }

    public void setAvatar(String avatar) {
        this.avatar = avatar;
    }

    public void setBiografia(String biografia) {
        this.biografia = biografia;
    }

    public void setListaJuegosJugados(List<Juego> listaJuegosJugados) {
        this.listaJuegosJugados = listaJuegosJugados;
    }

    public void setListaJuegosReseniados(List<Resenia> listaJuegosReseniados) {
        this.listaJuegosReseniados = listaJuegosReseniados;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }
    
    //Get's
    public String getUsername() {
        return username;
    }

    public String getAvatar() {
        return avatar;
    }

    public String getBiografia() {
        return biografia;
    }

    public List<Juego> getListaJuegosJugados() {
        return listaJuegosJugados;
    }

    public List<Resenia> getListaJuegosReseniados() {
        return listaJuegosReseniados;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    @Override
    public String toString() {
        return "Perfil{" + "username=" + username + ", avatar=" + avatar + ", biografia=" + biografia + '}';
    }
    
}
