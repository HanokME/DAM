package database

import (
	"fmt"

	"gorm.io/driver/mysql"
	"gorm.io/gorm"
)

var DB *gorm.DB

func Connect() {
	// Cambia estos valores si usas otros datos
	dsn := "dietaUser:221199@tcp(127.0.0.1:3306)/DietaApp?charset=utf8mb4&parseTime=True&loc=Local"
	connection, err := gorm.Open(mysql.Open(dsn), &gorm.Config{})
	if err != nil {
		panic("No se pudo conectar a la base de datos: " + err.Error())
	}

	fmt.Println("Conexión a la base de datos exitosa")
	DB = connection
}
