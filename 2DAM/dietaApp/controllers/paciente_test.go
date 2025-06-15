package controllers

import (
	"testing"
	"time"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/stretchr/testify/assert"
)

// Función auxiliar para generar un paciente completo
func crearPacienteDePrueba(dni, nombre string) models.FichaPaciente {
	return models.FichaPaciente{
		DNI:             dni,
		Nombre:          nombre,
		Email:           nombre + "@correo.com",
		Telefono:        "123456789",
		FechaNacimiento: time.Date(1990, 1, 1, 0, 0, 0, 0, time.UTC),
		AlturaCM:        175,
		PesoKG:          70,
		IMC:             22.9,
		Actividad:       "Moderada",
		Objetivo:        "Perder peso",
		Patologia:       "Ninguna",
	}
}

func TestCrearFichaPaciente(t *testing.T) {
	database.Connect()

	paciente := crearPacienteDePrueba("P1234567Z", "Paciente Prueba")
	err := database.DB.Create(&paciente).Error

	defer database.DB.Where("dni = ?", paciente.DNI).Delete(&models.FichaPaciente{})

	assert.NoError(t, err)
	assert.NotZero(t, paciente.ID)
}

func TestFichaPacienteDuplicada(t *testing.T) {
	database.Connect()

	paciente := crearPacienteDePrueba("DUPLI123", "Duplicado Uno")
	database.DB.Create(&paciente)
	defer database.DB.Where("dni = ?", paciente.DNI).Delete(&models.FichaPaciente{})

	duplicado := crearPacienteDePrueba("DUPLI123", "Duplicado Dos")
	err := database.DB.Create(&duplicado).Error

	assert.Error(t, err) // Esperamos error por DNI duplicado (si hay restricción)
}

func TestBuscarPacientePorDNI(t *testing.T) {
	database.Connect()

	paciente := crearPacienteDePrueba("BUS123", "Paciente Busqueda")
	database.DB.Create(&paciente)
	defer database.DB.Where("dni = ?", paciente.DNI).Delete(&models.FichaPaciente{})

	var encontrado models.FichaPaciente
	err := database.DB.Where("dni = ?", "BUS123").First(&encontrado).Error

	assert.NoError(t, err)
	assert.Equal(t, "Paciente Busqueda", encontrado.Nombre)
}

func TestActualizarPaciente(t *testing.T) {
	database.Connect()

	paciente := crearPacienteDePrueba("UPD123", "Nombre Original")
	database.DB.Create(&paciente)
	defer database.DB.Where("dni = ?", paciente.DNI).Delete(&models.FichaPaciente{})

	// Actualización
	database.DB.Model(&models.FichaPaciente{}).Where("dni = ?", "UPD123").Updates(models.FichaPaciente{
		Nombre: "Nombre Actualizado",
	})

	var actualizado models.FichaPaciente
	err := database.DB.Where("dni = ?", "UPD123").First(&actualizado).Error

	assert.NoError(t, err)
	assert.Equal(t, "Nombre Actualizado", actualizado.Nombre)
}
