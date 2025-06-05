package controllers

import (
	"net/http"
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

	c.HTML(http.StatusOK, "login.html", gin.H{
		"error": "Inicio de sesión exitoso. ¡Bienvenido " + dietista.Nombre + "!",
	})
}
