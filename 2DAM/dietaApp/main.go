package main

import (
	"github.com/HanokME/DAM/2DAM/dietaApp/controllers"
	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
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

	// Inicializar Gin
	r := gin.Default()

	// Cargar plantillas
	r.LoadHTMLGlob("templates/*.html")

	// Rutas
	r.GET("/registro", controllers.MostrarRegistro)
	r.POST("/registro", controllers.RegistrarDietista)

	r.GET("/login", controllers.MostrarLogin)
	r.POST("/login", controllers.IniciarSesion)

	r.GET("/logout", controllers.CerrarSesion)

	r.GET("/panel", controllers.MostrarPanel)

	// Iniciar servidor
	r.Run(":8080")

}
