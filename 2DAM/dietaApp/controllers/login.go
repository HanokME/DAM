package controllers

import (
	"net/http"
	"strconv"
	"strings"

	"github.com/gin-gonic/gin"
)

func MostrarLogin(c *gin.Context) {
	c.HTML(http.StatusOK, "login.html", gin.H{
		"error": "",
	})
}

func IniciarSesion(c *gin.Context) {
	dni := strings.TrimSpace(c.PostForm("dni"))
	pass := strings.TrimSpace(c.PostForm("contraseña"))

	dietista, err := ExisteDietista(dni, pass)
	if err != nil {
		c.HTML(http.StatusOK, "login.html", gin.H{
			"error": "DNI o contraseña incorrectos.",
		})
		return
	}

	// Guardar ID del dietista en cookie
	c.SetCookie("dietista_id", strconv.Itoa(int(dietista.ID)), 3600, "/", "localhost", false, true)

	c.Redirect(http.StatusFound, "/panel")
}

func CerrarSesion(c *gin.Context) {
	// Eliminar la cookie dietista_id
	c.SetCookie("dietista_id", "", -1, "/", "localhost", false, true)

	// Redirigir al login
	c.Redirect(http.StatusFound, "/login")
}
