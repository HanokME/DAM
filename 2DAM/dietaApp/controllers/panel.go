package controllers

import (
	"net/http"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

func MostrarPanel(c *gin.Context) {
	// (futuro)usar ID del dietista logueado, para mostrar solo sus fichas.
	var fichas []models.FichaPaciente

	err := database.DB.Find(&fichas).Error
	if err != nil {
		c.HTML(http.StatusInternalServerError, "panel.html", gin.H{
			"error":  "No se pudieron cargar las fichas clínicas.",
			"fichas": nil,
		})
		return
	}

	c.HTML(http.StatusOK, "panel.html", gin.H{
		"fichas": fichas,
	})
}
