CREATE DATABASE IF NOT EXISTS DietaApp;
USE DietaApp;

-- TABLA: Dietista
CREATE TABLE IF NOT EXISTS Dietista (
    id INT AUTO_INCREMENT PRIMARY KEY,
    dni VARCHAR(10) NOT NULL UNIQUE,
    nombre VARCHAR(100),
    contraseña VARCHAR(255)
);

-- TABLA: FichaPaciente
CREATE TABLE IF NOT EXISTS FichaPaciente (
    id INT AUTO_INCREMENT PRIMARY KEY,
    dni VARCHAR(10) NOT NULL UNIQUE,
    nombre VARCHAR(100),
    email VARCHAR(100),
    telefono VARCHAR(15),
    fecha_nacimiento DATE,
    altura_cm INT,
    peso_kg FLOAT,
    imc FLOAT,
    actividad VARCHAR(50),
    objetivo VARCHAR(100),
    patologia TEXT
);

-- RELACIÓN CREA: Dietista -> FichaPaciente
CREATE TABLE IF NOT EXISTS CREA (
    id_dietista INT,
    id_ficha INT,
    PRIMARY KEY (id_dietista, id_ficha),
    FOREIGN KEY (id_dietista) REFERENCES Dietista(id) ON DELETE CASCADE,
    FOREIGN KEY (id_ficha) REFERENCES FichaPaciente(id) ON DELETE CASCADE
);

-- TABLA: Dieta
CREATE TABLE IF NOT EXISTS Dieta (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100),
    fecha_inicio DATE,
    fecha_fin DATE,
    observaciones TEXT
);

-- RELACIÓN TIENE: FichaPaciente -> Dieta
CREATE TABLE IF NOT EXISTS TIENE (
    id_ficha INT,
    id_dieta INT,
    PRIMARY KEY (id_ficha, id_dieta),
    FOREIGN KEY (id_ficha) REFERENCES FichaPaciente(id) ON DELETE CASCADE,
    FOREIGN KEY (id_dieta) REFERENCES Dieta(id) ON DELETE CASCADE
);

-- TABLA: MomentoDia
CREATE TABLE IF NOT EXISTS MomentoDia (
    id INT AUTO_INCREMENT PRIMARY KEY,
    dia VARCHAR(20),
    momento VARCHAR(50)
);

-- TABLA: Alimento
CREATE TABLE IF NOT EXISTS Alimento (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100),
    tipo VARCHAR(50),
    kcal FLOAT,
    proteina FLOAT,
    hidratos FLOAT,
    grasas FLOAT
);

-- RELACIÓN Contiene: MomentoDia <-> Alimento (N:M con atributo cantidad)
CREATE TABLE IF NOT EXISTS Contiene (
    id_momento INT,
    id_alimento INT,
    cantidad FLOAT,
    PRIMARY KEY (id_momento, id_alimento, cantidad),
    FOREIGN KEY (id_momento) REFERENCES MomentoDia(id) ON DELETE CASCADE,
    FOREIGN KEY (id_alimento) REFERENCES Alimento(id) ON DELETE CASCADE
);

-- RELACIÓN Incluye: Dieta <-> (MomentoDia + Alimento)
CREATE TABLE IF NOT EXISTS Incluye (
    id_dieta INT,
    id_momento INT,
    id_alimento INT,
    cantidad FLOAT,
    PRIMARY KEY (id_dieta, id_momento, id_alimento, cantidad),
    FOREIGN KEY (id_dieta) REFERENCES Dieta(id) ON DELETE CASCADE,
    FOREIGN KEY (id_momento, id_alimento, cantidad) REFERENCES Contiene(id_momento, id_alimento, cantidad) ON DELETE CASCADE
);