package controllers

import (
	"net/http"
	"strings" //Para evitar saltos de linea y espacios

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

// Mostrar formulario de registro
func MostrarRegistro(c *gin.Context) {
	c.HTML(http.StatusOK, "registro.html", gin.H{
		"mensaje": "",
	})
}

func RegistrarDietista(c *gin.Context) {
	dni := strings.TrimSpace(c.PostForm("dni"))
	nombre := strings.TrimSpace(c.PostForm("nombre"))
	pass := strings.TrimSpace(c.PostForm("contraseña"))

	dietista := models.Dietista{
		DNI:        dni,
		Nombre:     nombre,
		Contraseña: pass,
	}

	err := GuardarDietista(dietista)
	if err != nil {
		c.HTML(http.StatusOK, "registro.html", gin.H{
			"mensaje": "Error al registrar: " + err.Error(),
		})
		return
	}

	c.HTML(http.StatusOK, "registro.html", gin.H{
		"mensaje": "Dietista registrado con éxito.",
	})

}

func GuardarDietista(dietista models.Dietista) error {
	result := database.DB.Create(&dietista)
	return result.Error
}
