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

func MostrarFormularioFicha(c *gin.Context) {
	// Verificar sesión
	_, err := c.Cookie("dietista_id")
	if err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}

	c.HTML(http.StatusOK, "nueva_ficha.html", nil)
}

func RegistrarFichaPaciente(c *gin.Context) {
	// Obtener ID del dietista desde cookie
	dietistaIDStr, err := c.Cookie("dietista_id")
	if err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}
	dietistaID, _ := strconv.Atoi(dietistaIDStr)

	// Parsear fecha de nacimiento
	fechaNacimiento, err := time.Parse("2006-01-02", c.PostForm("fecha_nacimiento"))
	if err != nil {
		c.HTML(http.StatusOK, "nueva_ficha.html", gin.H{
			"mensaje": "Formato de fecha inválido. Usa AAAA-MM-DD.",
		})
		return
	}

	// Crear ficha
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

	// Guardar ficha
	if err := database.DB.Create(&ficha).Error; err != nil {
		c.HTML(http.StatusOK, "nueva_ficha.html", gin.H{
			"mensaje": "Error al guardar la ficha: " + err.Error(),
		})
		return
	}

	// Asociar en la tabla Crea
	crea := models.Crea{
		IdDietista: uint(dietistaID),
		IdFicha:    ficha.ID,
	}
	database.DB.Create(&crea)

	c.Redirect(http.StatusFound, "/panel")
}

func parseInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func parseFloat(s string) float64 {
	f, _ := strconv.ParseFloat(s, 64)
	return f
}
