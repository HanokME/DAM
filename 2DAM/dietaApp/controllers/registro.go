package controllers

import (
	"net/http"
	"strings"

	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

// MostrarRegistro renderiza la página de registro del dietista.
// Inicializa el formulario sin mensaje de error o éxito.
func MostrarRegistro(c *gin.Context) {
	c.HTML(http.StatusOK, "registro.html", gin.H{
		"mensaje": "",
	})
}

// RegistrarDietista maneja la lógica para registrar un nuevo dietista.
// Recoge los datos del formulario, los limpia y guarda en la base de datos.
func RegistrarDietista(c *gin.Context) {
	// Obtener y limpiar los datos del formulario (eliminar espacios en blanco).
	dni := strings.TrimSpace(c.PostForm("dni"))
	nombre := strings.TrimSpace(c.PostForm("nombre"))
	pass := strings.TrimSpace(c.PostForm("contraseña"))

	// Crear una nueva instancia del modelo Dietista con los datos recibidos.
	dietista := models.Dietista{
		DNI:        dni,
		Nombre:     nombre,
		Contraseña: pass,
	}

	// Intentar guardar al dietista en la base de datos.
	err := GuardarDietista(dietista)
	if err != nil {
		// Si hay error, volver a mostrar el formulario con el mensaje de error.
		c.HTML(http.StatusOK, "registro.html", gin.H{
			"mensaje": "Error al registrar: " + err.Error(),
		})
		return
	}

	// Si el registro es exitoso, mostrar mensaje de confirmación.
	c.HTML(http.StatusOK, "registro.html", gin.H{
		"mensaje": "Dietista registrado con éxito.",
	})
}
