package main

import (
	"github.com/HanokME/DAM/2DAM/dietaApp/controllers"
	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

func main() {
	// Conectar con la base de datos
	database.Connect()

	// Realizar migraciones automáticas de las tablas definidas en los modelos
	database.DB.AutoMigrate(
		&models.Dietista{},      // Tabla para los usuarios dietistas
		&models.FichaPaciente{}, // Tabla de fichas clínicas de pacientes
		&models.Dieta{},         // Tabla de dietas
		&models.Crea{},          // Relación Dietista ↔ FichaPaciente
		&models.MomentoDia{},    // Tabla de momentos del día (desayuno, comida, etc.)
		&models.Alimento{},      // Tabla de alimentos
		&models.Contiene{},      // Relación MomentoDia ↔ Alimento
		&models.Incluye{},       // Relación Dieta ↔ Alimento en un momento específico
		&models.Tiene{},         // Relación FichaPaciente ↔ Dieta
	)

	println("Migración de la base de datos completada")

	// Inicializar router de Gin con middleware por defecto (logger y recovery)
	r := gin.Default()

	// Servir archivos estáticos desde la carpeta ./static
	r.Static("/static", "./static")

	// Cargar todas las plantillas HTML desde la carpeta /templates
	r.LoadHTMLGlob("templates/*.html")

	// Definir rutas y asociar controladores

	// Registro de dietista
	r.GET("/registro", controllers.MostrarRegistro)
	r.POST("/registro", controllers.RegistrarDietista)

	// Login y logout
	r.GET("/login", controllers.MostrarLogin)
	r.POST("/login", controllers.IniciarSesion)
	r.GET("/logout", controllers.CerrarSesion)

	// Panel principal del dietista
	r.GET("/panel", controllers.MostrarPanel)

	// Formularios para crear fichas de pacientes
	r.GET("/nueva_ficha", controllers.MostrarFormularioFicha)
	r.POST("/nueva_ficha", controllers.RegistrarFichaPaciente)

	// Formularior para editar fichas de pacientes
	r.GET("/editar_ficha/:id", controllers.MostrarFormularioEdicion)
	r.POST("/editar_ficha/:id", controllers.ActualizarFichaPaciente)

	// Formulario para dietas
	r.GET("/dieta/:fichaID", controllers.MostrarDieta)
	r.GET("/dieta/:fichaID/:dia/:momento/add", controllers.MostrarFormularioAgregarAlimento)
	r.POST("/dieta/:fichaID/:dia/:momento/add", controllers.ProcesarAgregarAlimento)

	// Editar alimento
	r.GET("/dieta/:fichaID/:dia/:momento/:alimentoID/edit", controllers.MostrarFormularioEditarAlimento)

	// Iniciar el servidor en el puerto 8080
	r.Run(":8080")
}
