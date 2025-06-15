package controllers

import (
	"net/http"
	"strconv"
	"strings"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

// MostrarPanel muestra el panel principal del dietista tras iniciar sesión.
// Recupera su información y las fichas clínicas de los pacientes que tiene asociadas.
func MostrarPanel(c *gin.Context) {
	// Obtener el ID del dietista desde la cookie.
	// La cookie es un pequeño dato guardado en el navegador que permite identificar al usuario entre peticiones.
	idStr, err := c.Cookie("dietista_id")
	if err != nil {
		// Si no hay cookie, redirigir al login.
		c.Redirect(http.StatusFound, "/login")
		return
	}

	// Convertir el ID obtenido de string a entero.
	dietistaID, _ := strconv.Atoi(idStr)

	// Buscar al dietista en la base de datos por su ID.
	var dietista models.Dietista
	if err := database.DB.First(&dietista, dietistaID).Error; err != nil {
		// Si no se encuentra, redirigir al login.
		c.Redirect(http.StatusFound, "/login")
		return
	}

	// Buscar pacientes con filtro
	search := c.Query("search")

	// Obtener las fichas de pacientes asociadas a ese dietista.
	var fichas []models.FichaPaciente
	query := database.DB.Joins("JOIN crea ON crea.id_ficha = ficha_pacientes.id").
		Where("crea.id_dietista = ?", dietistaID)

	if search != "" {
		like := "%" + search + "%"
		query = query.Where("ficha_pacientes.nombre LIKE ? OR ficha_pacientes.dni LIKE ? OR ficha_pacientes.correo LIKE ?", like, like, like)
	}

	query.Find(&fichas)

	// Obtener la inicial del nombre del dietista para mostrar en el panel.
	inicial := strings.ToUpper(string(dietista.Nombre[0]))

	// Renderizar la plantilla del panel con las fichas y la inicial.
	c.HTML(http.StatusOK, "panel.html", gin.H{
		"fichas":  fichas,
		"inicial": inicial,
		"search":  search,
	})
}
