package controllers

import (
	"net/http"
	"strconv"
	"strings"
	"time"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

// MostrarFormularioFicha renderiza el formulario HTML para crear una nueva ficha clínica.
// Si el dietista no ha iniciado sesión (cookie ausente), redirige al login.
func MostrarFormularioFicha(c *gin.Context) {
	// Comprobamos si existe la cookie "dietista_id"
	// La cookie almacena el ID del dietista para mantener su sesión entre solicitudes HTTP.
	_, err := c.Cookie("dietista_id")
	if err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}

	// Renderizamos el formulario vacío
	c.HTML(http.StatusOK, "nueva_ficha.html", nil)
}

// RegistrarFichaPaciente maneja la solicitud POST del formulario de ficha clínica.
// Recoge los datos del formulario, los valida, guarda la ficha en la base de datos
// y crea la relación entre el dietista y el paciente.
func RegistrarFichaPaciente(c *gin.Context) {
	// Obtener ID del dietista desde la cookie
	dietistaIDStr, err := c.Cookie("dietista_id")
	if err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}
	dietistaID, _ := strconv.Atoi(dietistaIDStr) // Convertir el ID a entero

	// Parsear la fecha de nacimiento enviada desde el formulario
	fechaNacimiento, err := time.Parse("2006-01-02", c.PostForm("fecha_nacimiento"))
	if err != nil {
		// Si la fecha no es válida, se muestra un mensaje de error
		c.HTML(http.StatusOK, "nueva_ficha.html", gin.H{
			"mensaje": "Formato de fecha inválido. Usa AAAA-MM-DD.",
		})
		return
	}

	// Crear una instancia de FichaPaciente con los datos del formulario
	ficha := models.FichaPaciente{
		DNI:             strings.TrimSpace(c.PostForm("dni")),
		Nombre:          strings.TrimSpace(c.PostForm("nombre")),
		Email:           strings.TrimSpace(c.PostForm("email")),
		Telefono:        strings.TrimSpace(c.PostForm("telefono")),
		FechaNacimiento: fechaNacimiento,
		AlturaCM:        parseInt(c.PostForm("altura")),
		PesoKG:          parseFloat(c.PostForm("peso")),
		IMC:             parseFloat(c.PostForm("imc")),
		Actividad:       strings.TrimSpace(c.PostForm("actividad")),
		Objetivo:        strings.TrimSpace(c.PostForm("objetivo")),
		Patologia:       strings.TrimSpace(c.PostForm("patologia")),
	}

	// Guardar la ficha en la base de datos
	if err := database.DB.Create(&ficha).Error; err != nil {
		c.HTML(http.StatusOK, "nueva_ficha.html", gin.H{
			"mensaje": "Error al guardar la ficha: " + err.Error(),
		})
		return
	}

	// Validar que el ID de la ficha se haya asignado correctamente
	if ficha.ID == 0 {
		c.HTML(http.StatusOK, "nueva_ficha.html", gin.H{
			"mensaje": "Error interno: ID de ficha no asignado.",
		})
		return
	}

	// Crear la relación entre el dietista actual y la ficha recién creada
	crea := models.Crea{
		IdDietista: uint(dietistaID),
		IdFicha:    ficha.ID,
	}

	// Guardar la relación en la tabla "crea"
	if err := database.DB.Create(&crea).Error; err != nil {
		c.HTML(http.StatusOK, "nueva_ficha.html", gin.H{
			"mensaje": "Error al asociar la ficha con el dietista: " + err.Error(),
		})
		return
	}

	// Redirigir al panel principal tras registrar la ficha correctamente
	c.Redirect(http.StatusFound, "/panel")
}

// parseInt convierte una cadena en un entero (int).
// Si hay error, devuelve 0 por defecto.
func parseInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

// parseFloat convierte una cadena en un número de coma flotante (float64).
// Si hay error, devuelve 0.0 por defecto.
func parseFloat(s string) float64 {
	f, _ := strconv.ParseFloat(s, 64)
	return f
}
