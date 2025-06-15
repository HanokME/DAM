package controllers

import (
	"fmt"
	"net/http"
	"strconv"
	"time"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

func MostrarDieta(c *gin.Context) {
	fichaIDStr := c.Param("fichaID")
	fichaID, _ := strconv.Atoi(fichaIDStr)
	dia := c.DefaultQuery("dia", "Lunes")

	var ficha models.FichaPaciente
	database.DB.First(&ficha, fichaID)

	var momentos []models.MomentoDia
	database.DB.Where("dia = ?", dia).Find(&momentos)

	// Si no existen momentos para ese día, los creamos
	if len(momentos) == 0 {
		defecto := []string{"Desayuno", "Almuerzo", "Comida", "Merienda", "Cena"}
		for _, m := range defecto {
			nuevo := models.MomentoDia{
				Dia:     dia,
				Momento: m,
			}
			database.DB.Create(&nuevo)
			momentos = append(momentos, nuevo)
		}
	}

	alimentosPorMomento := make(map[uint][]models.Alimento)
	cantidades := make(map[uint][]float64)

	// Buscar dieta existente
	var dieta models.Dieta
	result := database.DB.
		Where("nombre = ? AND observaciones = ?", dia, fichaIDStr).
		First(&dieta)

	if result.Error != nil {
		if result.Error.Error() == "record not found" {
			dieta = models.Dieta{
				Nombre:        dia,
				Observaciones: fichaIDStr,
				FechaInicio:   time.Now(),
				FechaFin:      time.Now().AddDate(0, 0, 7),
			}
			createResult := database.DB.Create(&dieta)
			if createResult.Error != nil {
				c.String(http.StatusInternalServerError, "Error creando dieta: "+createResult.Error.Error())
				return
			}
		} else {
			c.String(http.StatusInternalServerError, "Error buscando dieta: "+result.Error.Error())
			return
		}
	}

	// Debug
	fmt.Println("Dieta ID:", dieta.ID, "Día:", dia, "Paciente:", fichaIDStr)

	for _, momento := range momentos {
		var incluye []models.Incluye
		database.DB.
			Where("id_dieta = ? AND id_momento = ?", dieta.ID, momento.ID).
			Find(&incluye)

		fmt.Printf("Momento %s (%d): %d alimentos\n", momento.Momento, momento.ID, len(incluye))

		for _, inc := range incluye {
			var alimento models.Alimento
			database.DB.First(&alimento, inc.IdAlimento)
			alimentosPorMomento[momento.ID] = append(alimentosPorMomento[momento.ID], alimento)
			cantidades[momento.ID] = append(cantidades[momento.ID], inc.Cantidad)
		}
	}

	c.HTML(http.StatusOK, "dieta.html", gin.H{
		"paciente":            ficha,
		"dia":                 dia,
		"momentos":            momentos,
		"alimentosPorMomento": alimentosPorMomento,
		"cantidades":          cantidades,
	})
}

// GET: Muestra el formulario para añadir alimento
func MostrarFormularioAgregarAlimento(c *gin.Context) {
	fichaID := c.Param("fichaID")
	dia := c.Param("dia")
	momento := c.Param("momento")

	var alimentos []models.Alimento
	database.DB.Order("tipo, nombre").Find(&alimentos)
	fmt.Println("Alimentos encontrados:", len(alimentos))

	c.HTML(http.StatusOK, "agregar_alimentos.html", gin.H{
		"fichaID":   fichaID,
		"dia":       dia,
		"momento":   momento,
		"alimentos": alimentos,
	})
}

// POST: Procesa el alimento seleccionado y lo añade a la dieta
func ProcesarAgregarAlimento(c *gin.Context) {
	fichaIDStr := c.Param("fichaID")
	dia := c.Param("dia")
	momento := c.Param("momento")

	alimentoID, _ := strconv.Atoi(c.PostForm("alimento_id"))
	cantidad, _ := strconv.ParseFloat(c.PostForm("cantidad"), 64)

	// Buscar o crear momento del día
	var momentoDia models.MomentoDia
	database.DB.
		Where("dia = ? AND momento = ?", dia, momento).
		FirstOrCreate(&momentoDia)

	// Buscar o crear dieta
	var dieta models.Dieta
	result := database.DB.
		Where("nombre = ? AND observaciones = ?", dia, fichaIDStr).
		First(&dieta)

	if result.Error != nil {
		if result.Error.Error() == "record not found" {
			dieta = models.Dieta{
				Nombre:        dia,
				Observaciones: fichaIDStr,
				FechaInicio:   time.Now(),
				FechaFin:      time.Now().AddDate(0, 0, 7),
			}
			createResult := database.DB.Create(&dieta)
			if createResult.Error != nil {
				fmt.Println("Error creando dieta:", createResult.Error)
				c.String(http.StatusInternalServerError, "Error creando dieta")
				return
			}
		} else {
			fmt.Println("Error buscando dieta:", result.Error)
			c.String(http.StatusInternalServerError, "Error buscando dieta")
			return
		}
	}

	// Insertar en Incluye
	incluye := models.Incluye{
		IdDieta:    dieta.ID,
		IdMomento:  momentoDia.ID,
		IdAlimento: uint(alimentoID),
		Cantidad:   cantidad,
	}
	resultInsert := database.DB.Create(&incluye)

	if resultInsert.Error != nil {
		fmt.Println("Error al insertar alimento:", resultInsert.Error)
	} else {
		fmt.Printf("Alimento añadido correctamente: id %d cantidad %.2f (dieta %d, momento %d)\n",
			alimentoID, cantidad, dieta.ID, momentoDia.ID)
	}

	c.Redirect(http.StatusFound, "/dieta/"+fichaIDStr+"?dia="+dia)
}
