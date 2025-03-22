#include <iostream>
#include <iomanip>
using namespace std;
#include "polinomio.h"

#define DEFAULT "\033[1;0m"
#define ERROR "\033[1;31m"
#define OK "\033[1;32m"
#define DEBUG "\033[1;34m"

const bool DEBUGEO = false;


Polinomio::Polinomio(){
    grado_actual = 0;
    grado_max = 9;
    coef = new float[grado_max + 1];
    for(int i = 0; i <= grado_max; i++){
        coef[i] = 0.0;
    }
    
    if(DEBUGEO){
    cout << DEBUG << "Se ha creado un polinomio de grado 0" << DEFAULT << endl;
    }

}

Polinomio::Polinomio(const Polinomio& otro){
    grado_max = otro.grado_max;
    grado_actual = otro.grado_actual;
    coef = new float[grado_max + 1];
    for(int i = 0; i <= grado_max; i++){
        coef[i] = otro.coef[i];
    }
    if (DEBUGEO) {
        cout << DEBUG << "Se ha creado un polinomio (por copia) de grado " << grado_actual << DEFAULT << endl;
    }
}

Polinomio::~Polinomio(){
    delete[] coef;
    coef = nullptr;
    if (DEBUGEO) {
        cout << DEBUG << "Se ha destruido el polinomio" << DEFAULT << endl;
    }
}

void Polinomio::setGrado(int nuevo_grado){
    if(nuevo_grado > grado_max){
        cout << ERROR << "Error: el grado del polinomio no puede ser mayor que " << grado_max << DEFAULT << endl;
    }else{
       this -> grado_actual = nuevo_grado;
       if (DEBUGEO) {
            cout << DEBUG << "Se ha actualizado el grado actual a " << grado_actual << DEFAULT << endl;
        }
    }
}

int Polinomio::getGrado()const{
    return this->grado_actual;
}

void Polinomio::setGradoMax(int nuevo_grado_max){
    if (nuevo_grado_max < grado_actual) {
        cout << "ERROR: El nuevo grado máximo no puede ser menor que el grado actual (" << grado_actual << ")." << endl;
        return;
    }

    if (nuevo_grado_max != grado_max) {
        resize(nuevo_grado_max + 1);
        if (DEBUGEO) {
            cout << DEBUG << "Se ha actualizado el grado máximo a " << nuevo_grado_max << DEFAULT << endl;
        }
    }

}

int Polinomio::getMaxGrado()const{
    return this->grado_max;
}

void Polinomio::setCoeficienteV3(int i, float coeficiente){

    int nuevo_grado = 0;
    int maximo = this->getMaxGrado();
    bool encontrado = false;

    if (i < 0) {
        cout << "ERROR: No se puede insertar un coeficiente en un grado negativo." << endl;
        return;
    }

    if (coeficiente == 0 && i > this->getMaxGrado()) {
    }else{
        if(i > this->getMaxGrado()){
            this->resize(i+1);//redimensiona si el grado excede el grado maximo
            maximo = i;
        }
    }
    this->coef[i] = coeficiente;
    //actualiza el grado actual encontrando el mayor grado con coeficiente
    for(int j = this->getMaxGrado();j >= 0 && encontrado == false; j-- ){
        if(this->coef[j]!= 0){
            encontrado = true;
            nuevo_grado = j;
        }
    }
    this->setGrado(nuevo_grado);

    if(maximo > nuevo_grado){
        for(int j = maximo; j > nuevo_grado; j--){
            this->coef[j] = 0.0;
        }
        this->resize(nuevo_grado + 1);
    }

}

float Polinomio::getCoeficiente(int i)const{

    if(i > grado_actual){
        return 0.0;
    } else{
        return coef[i];
    }
}

void Polinomio::resize(int nueva_dimension){
    float* nuevo_coef = new float[nueva_dimension];
    
    if(nuevo_coef == 0){
        cerr << "ERROR: No se pudo asignar memoria para el nuevo grado máximo." << endl;
        exit(-1);
    }
    
    if(nueva_dimension >= this->getMaxGrado() + 1){
        for(int i = 0; i < this->getMaxGrado()+1; i++){
            nuevo_coef[i] = this->coef[i];
        }
        for(int i = this->getMaxGrado();i < nueva_dimension;i++){
            nuevo_coef[i] = 0.0;
        }

    }
    if(nueva_dimension < this->getMaxGrado()+1){
        for(int i = 0; i < nueva_dimension; i++){
            nuevo_coef[i] = this->coef[i];
        }
    }
    delete[] this->coef;
    this->coef = nuevo_coef;
    this->grado_max = nueva_dimension - 1;
    if (DEBUGEO) {
        cout << DEBUG << "Se ha redimensionado el polinomio a un nuevo grado máximo de " << grado_max << DEFAULT << endl;
    }
}

Polinomio* Polinomio::sumaV3(const Polinomio *p2){
    
    //Obtengo los grados maximos de los polinomios
    int max_grado_p1 = this->getGrado();
    int max_grado_p2 = p2->getGrado();
    int max_grado_resultado;

    //Determino el grado maximo entre los dos
    if(max_grado_p1 > max_grado_p2){
        max_grado_resultado = max_grado_p1;
    }else{
        max_grado_resultado = max_grado_p2;
    }
    
    //Creo un nuevo objeto polinomio para almacenar el resultado.
    Polinomio* resultado = new Polinomio();

    resultado->resize(max_grado_resultado);

    //Sumo los coeficientes de los dos polinomios y los almaceno en el nuevo polinomio.
    for(int i = 0; i <= max_grado_resultado; i++){
        float coef_p1 = 0.0;
        float coef_p2 = 0.0;
        if(i <= max_grado_p1) {
            coef_p1 = this->coef[i];
        }
        if(i <= max_grado_p2) {
            coef_p2 = p2->coef[i];
        }
        float coef_suma = coef_p1 + coef_p2;
        resultado->setCoeficienteV3(i, coef_suma);
    }

    if (DEBUGEO) {
        cout << DEBUG << "Se ha realizado una suma de polinomios con grado máximo de " << max_grado_resultado << DEFAULT << endl;
    }

    return resultado;
}

void Polinomio::print(){
    cout << "P(x) = ";
    bool primero = true;
    for(int i = grado_max; i >= 0; i--){
        if(coef[i] != 0.0){
            if(!primero) cout << " + ";
            cout << coef[i] << "x^" << i;
            primero = false;
        }
    }
    if(primero) cout << "0"; // En caso de que todos los coeficientes sean 0
    cout << endl;
}

Polinomio& Polinomio::operator=(const Polinomio &p){
    if(&p != this){
        delete[] coef;
        grado_max = p.grado_max;
        grado_actual = p.grado_actual;
        coef = new float[grado_max + 1];
        for(int i = 0; i <= grado_max; i++){
            coef[i] = p.coef[i];
        }
        if (DEBUGEO) {
            cout << DEBUG << "Se ha asignado un nuevo polinomio con grado máximo de " << grado_max << DEFAULT << endl;
        }
    }
    return *this;
}

Polinomio Polinomio::operator+(const Polinomio &p)const{
    int max_grado = max(grado_actual, p.grado_actual);
    Polinomio resultado;
    resultado.resize(max_grado + 1);

    for (int i = 0; i <= max_grado; i++) {
        resultado.setCoeficienteV3(i, getCoeficiente(i) + p.getCoeficiente(i));
    }

    // Actualizar el grado actual del polinomio resultante
    int nuevo_grado = 0;
    for (int j = max_grado; j >= 0; j--) {
        if (resultado.coef[j] != 0.0) {
            nuevo_grado = j;
            break;
        }
    }
    resultado.setGrado(nuevo_grado);
    if (DEBUGEO) {
        cout << DEBUG << "Se ha sumado un polinomio con grado máximo de " << max_grado << " y el nuevo polinomio tiene grado " << nuevo_grado << DEFAULT << endl;
    }

    return resultado;
}

ostream& operator<<(ostream& flujo, const Polinomio& p){
    bool primero = true;
    for (int i = p.grado_max; i >= 0; i--) {
        if (p.coef[i] != 0.0) {
            if (!primero) flujo << " + ";
            flujo << p.coef[i] << "x^" << i;
            primero = false;
        }
    }
    if (primero) flujo << "0"; // En caso de que todos los coeficientes sean 0
    flujo << endl;
    flujo << "Grado máximo: " << p.grado_max << endl;
    return flujo;

}

istream& operator>>(std::istream& flujo, Polinomio &p){
    
    int grado;
    float coef;

    do {
        cout << "Ingrese el grado del polinomio: ";
        flujo >> grado;
        if (grado < 0) {
            cout << "El grado del polinomio no puede ser negativo." << endl;
        }
    } while (grado < 0);

    p.resize(grado);
    
    for(int i = 0; i <= grado; i++){
        
        do{
            cout << "Ingrese el coeficiente para x^" << i << ": ";
            flujo >> coef;

            if(coef < 0){
                cout << "El coeficiente para x^" << i << " no puede ser negativo." << endl;
            }
        }while(coef < 0);

        p.setCoeficienteV3(i, coef);
    }
    p.setGrado(grado);
    return flujo;
}

void Polinomio::resetPolinomio(Polinomio &p){
    
    for(int i = 0; i <= p.getMaxGrado(); i++){
        p.setCoeficienteV3(i, 0.0);
    }

    p.setGrado(0);
    if (DEBUGEO) {
        cout << DEBUG << "Se ha reseteado el polinomio" << DEFAULT << endl;
    }
}



