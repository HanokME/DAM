package controllers

import (
	"net/http"
	"strconv"

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
	"github.com/gin-gonic/gin"
)

func MostrarDieta(c *gin.Context) {
	// Obtener fichaID desde la URL
	fichaIDStr := c.Param("fichaID")
	fichaID, err := strconv.Atoi(fichaIDStr)
	if err != nil {
		c.String(http.StatusBadRequest, "ID inválido")
		return
	}

	// Obtener datos del paciente
	var ficha models.FichaPaciente
	if err := database.DB.First(&ficha, fichaID).Error; err != nil {
		c.String(http.StatusNotFound, "Paciente no encontrado")
		return
	}

	// Obtener momentos del día asociados a esa ficha (por día)
	var momentos []models.MomentoDia
	database.DB.Find(&momentos)

	// Obtener alimentos por momento
	type AlimentoConCantidad struct {
		models.Alimento
		Cantidad float64
	}

	// Mapa de alimentos por momento
	alimentosPorMomento := make(map[uint][]AlimentoConCantidad)

	var incluye []models.Incluye
	database.DB.Where("id_dieta IN (SELECT id FROM dietas WHERE id IN (SELECT id_dieta FROM tiene WHERE id_ficha = ?))", fichaID).Find(&incluye)

	for _, i := range incluye {
		var alimento models.Alimento
		database.DB.First(&alimento, i.IdAlimento)

		alimentosPorMomento[i.IdMomento] = append(alimentosPorMomento[i.IdMomento], AlimentoConCantidad{
			Alimento: alimento,
			Cantidad: i.Cantidad,
		})
	}

	// Renderizar plantilla
	c.HTML(http.StatusOK, "dieta.html", gin.H{
		"paciente":            ficha,
		"momentos":            momentos,
		"alimentosPorMomento": alimentosPorMomento,
	})
}
