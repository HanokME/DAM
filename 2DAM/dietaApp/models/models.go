package models

import "time"

//Dietista

type Dietista struct {
	ID         uint   `gorm:"primaryKey"`
	DNI        string `gorm:"unique;not null"`
	Nombre     string
	Contraseña string
}

// FichaPaciente
type FichaPaciente struct {
	ID              uint   `gorm:"primaryKey"`
	DNI             string `gorm:"unique;not null"`
	Nombre          string
	Email           string
	Telefono        string
	FechaNacimiento time.Time
	AlturaCM        int
	PesoKG          float64
	IMC             float64
	Actividad       string
	Objetivo        string
	Patologia       string
}

// Dieta
type Dieta struct {
	ID            uint `gorm:"primaryKey"`
	Nombre        string
	FechaInicio   time.Time
	FechaFin      time.Time
	Observaciones string
}

// Relación CREA entre Dietista y FichaPaciente
type Crea struct {
	IdDietista uint `gorm:"primaryKey"`
	IdFicha    uint `gorm:"primaryKey"`
}

// Fijar el nombre de la tabla
func (Crea) TableName() string {
	return "crea"
}

// Relación TIENE entre FichaPaciente y Dieta
type Tiene struct {
	IdFicha uint `gorm:"primaryKey"`
	IdDieta uint `gorm:"primaryKey"`
}

// MomentoDia
type MomentoDia struct {
	ID      uint `gorm:"primaryKey"`
	Dia     string
	Momento string
}

// Alimento
type Alimento struct {
	ID       uint `gorm:"primaryKey"`
	Nombre   string
	Tipo     string
	Kcal     float64
	Proteina float64
	Hidratos float64
	Grasas   float64
}

func (Alimento) TableName() string {
	return "Alimento" //Esto hace que GORM use FROM Alimento en la consulta y no alimentos
}

// Contiene: relación N:M entre MomentoDia y Alimento con atributo cantidad
type Contiene struct {
	IdMomento  uint    `gorm:"primaryKey"`
	IdAlimento uint    `gorm:"primaryKey"`
	Cantidad   float64 `gorm:"primaryKey"`
}

// Incluye: relación entre Dieta y combinación de MomentoDia + Alimento + Cantidad
type Incluye struct {
	IdDieta    uint    `gorm:"primaryKey"`
	IdMomento  uint    `gorm:"primaryKey"`
	IdAlimento uint    `gorm:"primaryKey"`
	Cantidad   float64 `gorm:"primaryKey"`
}
