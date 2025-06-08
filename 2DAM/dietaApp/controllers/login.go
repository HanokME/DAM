package controllers

import (
	"net/http"
	"strconv"
	"strings"

	"github.com/gin-gonic/gin"
)

// MostrarLogin renderiza la página de inicio de sesión del dietista.
// Se muestra un formulario vacío con un campo opcional para errores.
func MostrarLogin(c *gin.Context) {
	c.HTML(http.StatusOK, "login.html", gin.H{
		"error": "",
	})
}

// IniciarSesion procesa el formulario de login.
// Verifica las credenciales del dietista y guarda su ID en una cookie si son válidas.
func IniciarSesion(c *gin.Context) {
	// Obtener y limpiar las credenciales del formulario.
	dni := strings.TrimSpace(c.PostForm("dni"))
	pass := strings.TrimSpace(c.PostForm("contraseña"))

	// Verificar si el dietista existe en la base de datos.
	dietista, err := ExisteDietista(dni, pass)
	if err != nil {
		// Si no existe, mostrar mensaje de error.
		c.HTML(http.StatusOK, "login.html", gin.H{
			"error": "DNI o contraseña incorrectos.",
		})
		return
	}

	// Crear una cookie con el ID del dietista (válida por 1 hora).
	// Las cookies permiten mantener la sesión del usuario entre peticiones.
	c.SetCookie("dietista_id", strconv.Itoa(int(dietista.ID)), 3600, "/", "localhost", false, true)

	// Redirigir al panel principal del dietista.
	c.Redirect(http.StatusFound, "/panel")
}

// CerrarSesion elimina la cookie de sesión y redirige al login.
// Esto cierra la sesión del usuario.
func CerrarSesion(c *gin.Context) {
	// Eliminar la cookie asignándole un tiempo de vida negativo.
	c.SetCookie("dietista_id", "", -1, "/", "localhost", false, true)

	// Redirigir al formulario de inicio de sesión.
	c.Redirect(http.StatusFound, "/login")
}
