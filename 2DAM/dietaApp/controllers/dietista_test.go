package controllers

import (
	"testing"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/stretchr/testify/assert"
)

func TestBuscarDietistaPorDNI(t *testing.T) {
	database.Connect()

	// Setup
	dietista := models.Dietista{
		DNI:        "12345678Z",
		Nombre:     "Test",
		Contraseña: "pass",
	}
	database.DB.Create(&dietista)

	// Cleanup
	defer database.DB.Where("dni = ?", dietista.DNI).Delete(&models.Dietista{})

	// Test
	resultado, err := BuscarDietistaPorDNI("12345678Z")
	assert.NoError(t, err)
	assert.NotNil(t, resultado)
	assert.Equal(t, "Test", resultado.Nombre)
}

func TestGuardarDietistaDuplicado(t *testing.T) {
	database.Connect()

	dni := "99999999X"
	// Setup
	database.DB.Create(&models.Dietista{
		DNI:        dni,
		Nombre:     "Uno",
		Contraseña: "1234",
	})
	defer database.DB.Where("dni = ?", dni).Delete(&models.Dietista{})

	// Test
	err := GuardarDietista(models.Dietista{
		DNI:        dni,
		Nombre:     "Otro",
		Contraseña: "abcd",
	})
	assert.Error(t, err)
	assert.Contains(t, err.Error(), "ya existe un dietista")
}

func TestExisteDietista(t *testing.T) {
	database.Connect()

	dni := "88888888Y"
	pass := "secret"
	// Setup
	database.DB.Create(&models.Dietista{
		DNI:        dni,
		Nombre:     "Valido",
		Contraseña: pass,
	})
	defer database.DB.Where("dni = ?", dni).Delete(&models.Dietista{})

	// Test
	resultado, err := ExisteDietista(dni, pass)
	assert.NoError(t, err)
	assert.NotNil(t, resultado)
	assert.Equal(t, "Valido", resultado.Nombre)
}

func TestEditarDietista(t *testing.T) {
	database.Connect()

	// Crear uno inicial
	dietista := models.Dietista{
		DNI:        "55555555M",
		Nombre:     "Antes",
		Contraseña: "1234",
	}
	database.DB.Create(&dietista)
	defer database.DB.Where("dni = ?", dietista.DNI).Delete(&models.Dietista{})

	// Actualizar nombre y contraseña
	dietista.Nombre = "Después"
	dietista.Contraseña = "abcd"
	err := database.DB.Save(&dietista).Error

	assert.NoError(t, err)

	// Verificar cambios
	var actualizado models.Dietista
	database.DB.Where("dni = ?", dietista.DNI).First(&actualizado)

	assert.Equal(t, "Después", actualizado.Nombre)
	assert.Equal(t, "abcd", actualizado.Contraseña)
}
