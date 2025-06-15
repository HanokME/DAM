package controllers

import (
	"net/http"
	"net/http/httptest"
	"net/url"
	"strings"
	"testing"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/PuerkitoBio/goquery"
	"github.com/gin-gonic/gin"
	"github.com/stretchr/testify/assert"
)

func setupRouter() *gin.Engine {
	r := gin.Default()
	r.LoadHTMLGlob("../templates/*.html")
	r.POST("/login", IniciarSesion)
	r.GET("/logout", CerrarSesion)
	return r
}

func TestLoginExitoso(t *testing.T) {
	database.Connect()

	dietista := models.Dietista{
		DNI:        "loginTest",
		Nombre:     "Logueado",
		Contraseña: "1234",
	}
	database.DB.Create(&dietista)
	defer database.DB.Where("dni = ?", dietista.DNI).Delete(&models.Dietista{})

	form := url.Values{}
	form.Add("dni", "loginTest")
	form.Add("contraseña", "1234")

	req := httptest.NewRequest("POST", "/login", strings.NewReader(form.Encode()))
	req.Header.Set("Content-Type", "application/x-www-form-urlencoded")
	w := httptest.NewRecorder()

	r := setupRouter()
	r.ServeHTTP(w, req)

	assert.Equal(t, http.StatusFound, w.Code)
	assert.Contains(t, w.Header().Get("Location"), "/panel")
}

func TestLoginContrasenaIncorrecta(t *testing.T) {
	database.Connect()

	dietista := models.Dietista{
		DNI:        "wrongpass",
		Nombre:     "Fallido",
		Contraseña: "abc123",
	}
	database.DB.Create(&dietista)
	defer database.DB.Where("dni = ?", dietista.DNI).Delete(&models.Dietista{})

	form := url.Values{}
	form.Add("dni", "wrongpass")
	form.Add("contraseña", "mala")

	req := httptest.NewRequest("POST", "/login", strings.NewReader(form.Encode()))
	req.Header.Set("Content-Type", "application/x-www-form-urlencoded")
	w := httptest.NewRecorder()

	r := setupRouter()
	r.ServeHTTP(w, req)

	assert.Equal(t, http.StatusOK, w.Code)

	doc, err := goquery.NewDocumentFromReader(w.Body)
	assert.NoError(t, err)

	errorText := doc.Find("div.error").Text()
	assert.Equal(t, "DNI o contraseña incorrectos.", strings.TrimSpace(errorText))
}

func TestLoginUsuarioInexistente(t *testing.T) {
	database.Connect()

	form := url.Values{}
	form.Add("dni", "noexiste")
	form.Add("contraseña", "loquesea")

	req := httptest.NewRequest("POST", "/login", strings.NewReader(form.Encode()))
	req.Header.Set("Content-Type", "application/x-www-form-urlencoded")
	w := httptest.NewRecorder()

	r := setupRouter()
	r.ServeHTTP(w, req)

	assert.Equal(t, http.StatusOK, w.Code)

	doc, err := goquery.NewDocumentFromReader(w.Body)
	assert.NoError(t, err)

	errorText := doc.Find("div.error").Text()
	assert.Equal(t, "DNI o contraseña incorrectos.", strings.TrimSpace(errorText))
}

func TestLogout(t *testing.T) {
	req := httptest.NewRequest("GET", "/logout", nil)
	w := httptest.NewRecorder()

	r := setupRouter()
	r.ServeHTTP(w, req)

	assert.Equal(t, http.StatusFound, w.Code)
	assert.Contains(t, w.Header().Get("Location"), "/login")
}
