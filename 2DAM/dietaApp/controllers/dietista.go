package controllers

import (
	"errors"
	"net/http"
	"strconv"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

// Guarda un nuevo dietista en la base de datos
func GuardarDietista(dietista models.Dietista) error {
	// Verificar si ya existe un dietista con el mismo DNI
	existe, _ := BuscarDietistaPorDNI(dietista.DNI)
	if existe != nil {
		return errors.New("ya existe un dietista con ese DNI")
	}

	result := database.DB.Create(&dietista)
	return result.Error
}

// Busca un dietista por DNI y contraseña (para login)
func ExisteDietista(dni, contraseña string) (*models.Dietista, error) {
	var dietista models.Dietista
	result := database.DB.Where("dni = ? AND contraseña = ?", dni, contraseña).First(&dietista)
	if result.Error != nil {
		return nil, errors.New("credenciales inválidas")
	}
	return &dietista, nil
}

// Busca un dietista por DNI
func BuscarDietistaPorDNI(dni string) (*models.Dietista, error) {
	var dietista models.Dietista
	result := database.DB.Where("dni = ?", dni).First(&dietista)
	if result.Error != nil {
		return nil, result.Error
	}
	return &dietista, nil
}

// MostrarEditarDietista renderiza el formulario con los datos actuales del dietista
func MostrarEditarDietista(c *gin.Context) {
	idStr, err := c.Cookie("dietista_id")
	if err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}
	dietistaID, _ := strconv.Atoi(idStr)

	var dietista models.Dietista
	if err := database.DB.First(&dietista, dietistaID).Error; err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}

	c.HTML(http.StatusOK, "editar_dietista.html", gin.H{
		"dietista": dietista,
	})
}

// ActualizarDietista guarda los cambios del perfil
func ActualizarDietista(c *gin.Context) {

	idStr, err := c.Cookie("dietista_id")
	if err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}
	dietistaID, _ := strconv.Atoi(idStr)

	var dietista models.Dietista
	if err := database.DB.First(&dietista, dietistaID).Error; err != nil {
		c.Redirect(http.StatusFound, "/login")
		return
	}

	dietista.DNI = c.PostForm("dni")
	dietista.Nombre = c.PostForm("nombre")
	dietista.Contraseña = c.PostForm("contraseña")

	database.DB.Save(&dietista)
	c.Redirect(http.StatusFound, "/panel")
}
