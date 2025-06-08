package controllers

import (
	"net/http"
	"strconv"
	"strings"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

func MostrarPanel(c *gin.Context) {
	// Obtener el ID del dietista desde la cookie
	idStr, err := c.Cookie("dietista_id")
	if err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}

	dietistaID, _ := strconv.Atoi(idStr)

	// Obtener el dietista
	var dietista models.Dietista
	if err := database.DB.First(&dietista, dietistaID).Error; err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}

	// Obtener fichas asociadas a ese dietista
	var fichas []models.FichaPaciente
	database.DB.
		Joins("JOIN crea ON crea.id_ficha = ficha_pacientes.id").
		Where("crea.id_dietista = ?", dietistaID).
		Find(&fichas)

	inicial := strings.ToUpper(string(dietista.Nombre[0]))

	c.HTML(http.StatusOK, "panel.html", gin.H{
		"fichas":  fichas,
		"inicial": inicial,
	})
}
