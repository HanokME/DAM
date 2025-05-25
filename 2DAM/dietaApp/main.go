package main

import (
	"github.com/HanokME/DAM/2DAM/dietaApp/controllers"
	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
)

func main() {
	database.Connect()

	database.DB.AutoMigrate(
		&models.Dietista{},
		&models.FichaPaciente{},
		&models.Dieta{},
		&models.Crea{},
		&models.MomentoDia{},
		&models.Alimento{},
		&models.Contiene{},
		&models.Incluye{},
		&models.Tiene{},
	)

	println("Migración de la base de datos completada")

	controllers.RegistrarDietista()

}
