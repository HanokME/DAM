/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.cristogamescliente;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.Insets;
import java.io.ByteArrayInputStream;
import java.util.List;
import java.util.Map;
import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


/**
 *
 * @author hanokme
 */
public class VentanaPrincipal extends javax.swing.JFrame {
    
    private final ControladorCliente controlador;

    public VentanaPrincipal(ControladorCliente controlador, Map<String, Object> datosUsuario) {
        this.setResizable(false);
        this.setExtendedState(JFrame.NORMAL);
        this.controlador = controlador;
        initComponents();

        int columnas = 3;

        jPanelAccion.setLayout(new GridLayout(0, columnas, 10, 10));
        jPanelAventura.setLayout(new GridLayout(0, columnas, 10, 10));
        jPanelRPG.setLayout(new GridLayout(0, columnas, 10, 10));
        jPanelEstrategia.setLayout(new GridLayout(0, columnas, 10, 10));
        jPanelDeportes.setLayout(new GridLayout(0, columnas, 10, 10));

        // Espaciado entre paneles
        jPanelAccion.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        jPanelAventura.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        jPanelRPG.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        jPanelEstrategia.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        jPanelDeportes.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

        // Juegos jugados (vertical)
        jPanelJugados.setLayout(new GridLayout(0, 1, 5, 5));
        jPanelJugados.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

        cargarDatosDelServer(datosUsuario);
    }

    private void cargarDatosDelServer(Map<String, Object> datosUsuario) {

        if (datosUsuario == null) {
            System.out.println("❌ Error al obtener los datos.");
            return;
        }

        jLabelUserName.setText((String) datosUsuario.get("username"));


        jPanelJugados.removeAll();
        jPanelAccion.removeAll();
        jPanelAventura.removeAll();
        jPanelRPG.removeAll();
        jPanelEstrategia.removeAll();
        jPanelDeportes.removeAll();

        // Configurar tamaño uniforme de los botones
        Dimension tamañoBotonJugado = new Dimension(150, 50);
        Dimension tamañoBotonGenero = new Dimension(170, 60);

        // Cargar juegos jugados
        List<Map<String, String>> juegosJugados = (List<Map<String, String>>) datosUsuario.get("juegosJugados");

        for (Map<String, String> juego : juegosJugados) {
            JButton botonJuego = new JButton(formatoBotonJuego(juego));
            botonJuego.setPreferredSize(tamañoBotonJugado);
            botonJuego.setMargin(new Insets(2, 5, 2, 5));
            botonJuego.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));

            int idJuego = Integer.parseInt(juego.get("id"));
            botonJuego.addActionListener(e -> controlador.mostrarVentanaJuego(idJuego));

            jPanelJugados.add(botonJuego);
        }

        // Cargar juegos destacados
        List<Map<String, String>> juegosDestacados = (List<Map<String, String>>) datosUsuario.get("juegosDestacados");

        for (Map<String, String> juego : juegosDestacados) {
            JButton botonJuego = new JButton(formatoBotonJuego(juego));
            botonJuego.setPreferredSize(tamañoBotonGenero);
            botonJuego.setMargin(new Insets(5, 5, 5, 5));
            botonJuego.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));

            int idJuego = Integer.parseInt(juego.get("id"));
            botonJuego.addActionListener(e -> controlador.mostrarVentanaJuego(idJuego));

            String genero = juego.get("genero");

            switch (genero) {
                case "Acción":
                    jPanelAccion.add(botonJuego);
                    break;
                case "Aventura":
                    jPanelAventura.add(botonJuego);
                    break;
                case "RPG":
                    jPanelRPG.add(botonJuego);
                    break;
                case "Estrategia":
                    jPanelEstrategia.add(botonJuego);
                    break;
                case "Deportes":
                    jPanelDeportes.add(botonJuego);
                    break;
                default:
                    System.out.println("Género no reconocido: " + genero);
            }
        }
        // Refrescar la interfaz para mostrar los nuevos botones
        SwingUtilities.invokeLater(() -> {
            jPanelJugados.revalidate();
            jPanelJugados.repaint();
            jPanelAccion.revalidate();
            jPanelAccion.repaint();
            jPanelAventura.revalidate();
            jPanelAventura.repaint();
            jPanelRPG.revalidate();
            jPanelRPG.repaint();
            jPanelEstrategia.revalidate();
            jPanelEstrategia.repaint();
            jPanelDeportes.revalidate();
            jPanelDeportes.repaint();
        });
    }

    private String formatoBotonJuego(Map<String, String> juego) {
        return String.format(
                "<html><center>%s<br>%s<br>📅 %s<br>⭐ %s</center></html>",
                juego.get("nombre"), juego.get("estudio"), juego.get("lanzamiento"), juego.get("calificacion")
        );
    }
    
    public void agregarReseniaGlobal(String username, String texto, int puntuacion, String nombreJuego, double calificacionMedia, int idJuego) {
        SwingUtilities.invokeLater(() -> {
            System.out.println("📩 Agregando reseña global en la ventana principal...");

            // Configurar jPanelResenia con BoxLayout para organizar verticalmente
            if (!(jPanelResenia.getLayout() instanceof javax.swing.BoxLayout)) {
                jPanelResenia.setLayout(new javax.swing.BoxLayout(jPanelResenia, javax.swing.BoxLayout.Y_AXIS));
            }

            // Crear el nuevo panel de reseña
            JPanel reseniaPanel = new JPanel();
            reseniaPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
            reseniaPanel.setBorder(BorderFactory.createLineBorder(Color.GRAY));
            reseniaPanel.setBackground(Color.LIGHT_GRAY);
            reseniaPanel.setPreferredSize(new Dimension(400, 60));

            JLabel lblResenia = new JLabel("<html><b>" + username + "</b>:<br>"
                    + texto + " ⭐" + puntuacion + " (" + nombreJuego + ")</html>");

            reseniaPanel.add(lblResenia);

            // Insertar la nueva reseña en la parte superior
            jPanelResenia.add(reseniaPanel, 0);

            // Forzar actualización de la interfaz
            jPanelResenia.revalidate();
            jPanelResenia.repaint();

            getContentPane().invalidate();
            getContentPane().validate();
            getContentPane().repaint();

            // Actualizar la calificación del juego si aplica
            actualizarCalificacionJuego(idJuego, calificacionMedia);
        });
    }
    
    private void actualizarCalificacionJuego(int idJuego, double calificacionMedia) {
        SwingUtilities.invokeLater(() -> {
            for (Component comp : jPanelAccion.getComponents()) {
                if (comp instanceof JButton) {
                    JButton boton = (JButton) comp;
                    if (boton.getText().contains("ID: " + idJuego)) {
                        boton.setText(boton.getText().replaceAll("⭐ \\d+(\\.\\d+)?", "⭐ " + calificacionMedia));
                    }
                }
            }
        });
    }

    public void actualizarImagenPerfil(byte[] imagenBytes) {
        if (imagenBytes == null || imagenBytes.length == 0) {
            System.err.println("❌No se recibieron bytes de imagen.");
            return;
        }

        new Thread(() -> {
            try {
                ByteArrayInputStream bais = new ByteArrayInputStream(imagenBytes);
                Image img = ImageIO.read(bais);

                if (img == null) {
                    System.err.println("❌No se pudo decodificar la imagen.");
                    return;
                }

                ImageIcon icon = new ImageIcon(img.getScaledInstance(
                        jLabelImagenPerfil.getWidth(), jLabelImagenPerfil.getHeight(), Image.SCALE_SMOOTH
                ));

                SwingUtilities.invokeLater(() -> {
                    jLabelImagenPerfil.setIcon(icon);
                    jLabelImagenPerfil.repaint();
                    System.out.println("✅Imagen de perfil actualizada correctamente.");
                });

            } catch (Exception e) {
                System.err.println("❌Error al actualizar la imagen en la interfaz: " + e.getMessage());
            }
        }).start();
    }
    
    

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanelHeader = new javax.swing.JPanel();
        jLabelUserName = new javax.swing.JLabel();
        jButtonCerrarSesion = new javax.swing.JButton();
        jLabelImagenPerfil = new javax.swing.JLabel();
        jPanelJugados = new javax.swing.JPanel();
        jPanelAccion = new javax.swing.JPanel();
        jPanelAventura = new javax.swing.JPanel();
        jPanelRPG = new javax.swing.JPanel();
        jPanelEstrategia = new javax.swing.JPanel();
        jPanelDeportes = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabelInicioRapido = new javax.swing.JLabel();
        jPanelResenia = new javax.swing.JPanel();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);

        jLabelUserName.setText("UserName");
        jLabelUserName.setHorizontalTextPosition(javax.swing.SwingConstants.LEFT);

        jButtonCerrarSesion.setBackground(new java.awt.Color(255, 0, 0));
        jButtonCerrarSesion.setText("Cerrar Sesion");
        jButtonCerrarSesion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonCerrarSesionActionPerformed(evt);
            }
        });

        jLabelImagenPerfil.setText("ImagenPerfil");

        javax.swing.GroupLayout jPanelHeaderLayout = new javax.swing.GroupLayout(jPanelHeader);
        jPanelHeader.setLayout(jPanelHeaderLayout);
        jPanelHeaderLayout.setHorizontalGroup(
            jPanelHeaderLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelHeaderLayout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addComponent(jLabelImagenPerfil, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(120, 120, 120)
                .addComponent(jLabelUserName, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGap(57, 57, 57)
                .addComponent(jButtonCerrarSesion)
                .addGap(827, 827, 827))
        );
        jPanelHeaderLayout.setVerticalGroup(
            jPanelHeaderLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelHeaderLayout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addGroup(jPanelHeaderLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabelUserName, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButtonCerrarSesion)
                    .addComponent(jLabelImagenPerfil, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(28, Short.MAX_VALUE))
        );

        jPanelJugados.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        javax.swing.GroupLayout jPanelJugadosLayout = new javax.swing.GroupLayout(jPanelJugados);
        jPanelJugados.setLayout(jPanelJugadosLayout);
        jPanelJugadosLayout.setHorizontalGroup(
            jPanelJugadosLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 159, Short.MAX_VALUE)
        );
        jPanelJugadosLayout.setVerticalGroup(
            jPanelJugadosLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 645, Short.MAX_VALUE)
        );

        jPanelAccion.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        jPanelAccion.setPreferredSize(new java.awt.Dimension(509, 103));

        javax.swing.GroupLayout jPanelAccionLayout = new javax.swing.GroupLayout(jPanelAccion);
        jPanelAccion.setLayout(jPanelAccionLayout);
        jPanelAccionLayout.setHorizontalGroup(
            jPanelAccionLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 501, Short.MAX_VALUE)
        );
        jPanelAccionLayout.setVerticalGroup(
            jPanelAccionLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 101, Short.MAX_VALUE)
        );

        jPanelAventura.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        jPanelAventura.setPreferredSize(new java.awt.Dimension(509, 103));

        javax.swing.GroupLayout jPanelAventuraLayout = new javax.swing.GroupLayout(jPanelAventura);
        jPanelAventura.setLayout(jPanelAventuraLayout);
        jPanelAventuraLayout.setHorizontalGroup(
            jPanelAventuraLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 501, Short.MAX_VALUE)
        );
        jPanelAventuraLayout.setVerticalGroup(
            jPanelAventuraLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 101, Short.MAX_VALUE)
        );

        jPanelRPG.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        jPanelRPG.setMinimumSize(new java.awt.Dimension(100, 100));
        jPanelRPG.setPreferredSize(new java.awt.Dimension(509, 103));

        javax.swing.GroupLayout jPanelRPGLayout = new javax.swing.GroupLayout(jPanelRPG);
        jPanelRPG.setLayout(jPanelRPGLayout);
        jPanelRPGLayout.setHorizontalGroup(
            jPanelRPGLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 501, Short.MAX_VALUE)
        );
        jPanelRPGLayout.setVerticalGroup(
            jPanelRPGLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 101, Short.MAX_VALUE)
        );

        jPanelEstrategia.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        jPanelEstrategia.setMinimumSize(new java.awt.Dimension(100, 100));
        jPanelEstrategia.setPreferredSize(new java.awt.Dimension(509, 103));

        javax.swing.GroupLayout jPanelEstrategiaLayout = new javax.swing.GroupLayout(jPanelEstrategia);
        jPanelEstrategia.setLayout(jPanelEstrategiaLayout);
        jPanelEstrategiaLayout.setHorizontalGroup(
            jPanelEstrategiaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 501, Short.MAX_VALUE)
        );
        jPanelEstrategiaLayout.setVerticalGroup(
            jPanelEstrategiaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 101, Short.MAX_VALUE)
        );

        jPanelDeportes.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        jPanelDeportes.setMinimumSize(new java.awt.Dimension(100, 100));
        jPanelDeportes.setPreferredSize(new java.awt.Dimension(509, 103));

        javax.swing.GroupLayout jPanelDeportesLayout = new javax.swing.GroupLayout(jPanelDeportes);
        jPanelDeportes.setLayout(jPanelDeportesLayout);
        jPanelDeportesLayout.setHorizontalGroup(
            jPanelDeportesLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 501, Short.MAX_VALUE)
        );
        jPanelDeportesLayout.setVerticalGroup(
            jPanelDeportesLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 101, Short.MAX_VALUE)
        );

        jLabel1.setFont(new java.awt.Font("Liberation Sans", 1, 15)); // NOI18N
        jLabel1.setText("Juegos de Aventura");

        jLabel2.setFont(new java.awt.Font("Liberation Sans", 1, 15)); // NOI18N
        jLabel2.setText("Juegos RPG");

        jLabel3.setFont(new java.awt.Font("Liberation Sans", 1, 15)); // NOI18N
        jLabel3.setText("Juegos de Accion");

        jLabel4.setFont(new java.awt.Font("Liberation Sans", 1, 15)); // NOI18N
        jLabel4.setText("Juegos de Estrategia");

        jLabel5.setFont(new java.awt.Font("Liberation Sans", 1, 15)); // NOI18N
        jLabel5.setText("Juegos de Deportes");

        jLabelInicioRapido.setFont(new java.awt.Font("Liberation Sans", 1, 15)); // NOI18N
        jLabelInicioRapido.setText("Inicio rapido");

        jPanelResenia.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        javax.swing.GroupLayout jPanelReseniaLayout = new javax.swing.GroupLayout(jPanelResenia);
        jPanelResenia.setLayout(jPanelReseniaLayout);
        jPanelReseniaLayout.setHorizontalGroup(
            jPanelReseniaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 449, Short.MAX_VALUE)
        );
        jPanelReseniaLayout.setVerticalGroup(
            jPanelReseniaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 258, Short.MAX_VALUE)
        );

        jLabel6.setFont(new java.awt.Font("Liberation Sans", 1, 15)); // NOI18N
        jLabel6.setText("Ultimas reseñas");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanelHeader, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanelJugados, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabelInicioRapido, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(60, 60, 60)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(6, 6, 6)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addComponent(jLabel2)
                            .addComponent(jLabel4)
                            .addComponent(jLabel5)))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                .addComponent(jPanelRPG, javax.swing.GroupLayout.PREFERRED_SIZE, 503, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(jPanelAventura, javax.swing.GroupLayout.PREFERRED_SIZE, 503, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(jPanelEstrategia, javax.swing.GroupLayout.PREFERRED_SIZE, 503, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(jPanelDeportes, javax.swing.GroupLayout.PREFERRED_SIZE, 503, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(jPanelAccion, javax.swing.GroupLayout.PREFERRED_SIZE, 503, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(10, 10, 10)
                                .addComponent(jLabel3)))
                        .addGap(70, 70, 70)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel6)
                            .addComponent(jPanelResenia, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanelHeader, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabelInicioRapido)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanelJugados, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap())
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(0, 0, Short.MAX_VALUE)
                                .addComponent(jLabel3))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel6)
                                .addGap(0, 0, Short.MAX_VALUE)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jPanelAccion, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(12, 12, 12)
                                .addComponent(jLabel1)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jPanelAventura, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jLabel2))
                            .addComponent(jPanelResenia, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanelRPG, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel4)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanelEstrategia, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel5)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanelDeportes, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonCerrarSesionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonCerrarSesionActionPerformed
            controlador.cerrarSesion();
    }//GEN-LAST:event_jButtonCerrarSesionActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonCerrarSesion;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabelImagenPerfil;
    private javax.swing.JLabel jLabelInicioRapido;
    private javax.swing.JLabel jLabelUserName;
    private javax.swing.JPanel jPanelAccion;
    private javax.swing.JPanel jPanelAventura;
    private javax.swing.JPanel jPanelDeportes;
    private javax.swing.JPanel jPanelEstrategia;
    private javax.swing.JPanel jPanelHeader;
    private javax.swing.JPanel jPanelJugados;
    private javax.swing.JPanel jPanelRPG;
    private javax.swing.JPanel jPanelResenia;
    // End of variables declaration//GEN-END:variables
}


