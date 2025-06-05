package controllers

import (
	"errors"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
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
