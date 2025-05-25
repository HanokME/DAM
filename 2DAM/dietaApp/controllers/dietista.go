package controllers

import (
	"bufio" //bufio y os para leer desde la consola
	"os"

	"fmt" //Esto pa mostrar texto

	"strings" //Para evitar saltos de linea y espacios

	"github.com/HanokME/DAM/2DAM/dietaApp/database"
	"github.com/HanokME/DAM/2DAM/dietaApp/models"
)

func RegistrarDietista() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("=== Registro de nuevo dietista ===")

	fmt.Println("DNI: ")
	dni, _ := reader.ReadString('\n')

	fmt.Println("Nombre: ")
	nombre, _ := reader.ReadString('\n')

	fmt.Println("Contraseña: ")
	contraseña, _ := reader.ReadString('\n')

	dietista := models.Dietista{
		DNI:        strings.TrimSpace(dni),
		Nombre:     strings.TrimSpace(nombre),
		Contraseña: strings.TrimSpace(contraseña),
	}

	result := database.DB.Create(&dietista)

	if result.Error != nil {
		fmt.Println("Error al registrar el dietista:", result.Error)
	} else {
		fmt.Println("Dietista registrado con éxito (ID:", dietista.ID, ")")
	}

}
