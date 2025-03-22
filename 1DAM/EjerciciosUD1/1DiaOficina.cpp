#include <iostream>
#include <cmath>
#include <iomanip>
#include "colors.h"

using namespace std;

/**
 * @file 1DiaOficina.cpp
 * @brief Sistema calificador de FP que calcula el resultado final de aprendizaje de un alumno
 * @version 1.0 
 * @date 31/10/2023
 * @author Hanok
 */
 
 int main(){
 
        //CONSTANTES
        //Resultados de Aprendizaje
        const double RA1 = 0.65;
        const double RA2 = 0.35;
        //Criterios de Evaluacion
        const double CE11 = 0.4;
        const double CE12 = 0.4;
        const double CE13 = 0.2;
        const double CE21 = 1.0;
        //Instrumentos de Evaluacion y CE asociados con cambio de porcentajes
        const double I1CE11 = 0.15;
        const double I2CE11 = 0.35;
        const double I3CE11 = 0.5;
        
        const double I1CE12 = 0.3;
        const double I2CE12 = 0.3;
        const double I3CE12 = 0.4;
        
        const double I1CE13 = 0.25;
        const double I2CE13 = 0.25;
        const double I3CE13 = 0.5;
        
        const double I2CE21 = 0.25;
        const double I4CE21 = 0.75;
        
        //VARIABLES
        //Resultados de Aprendizaje
        double ResultadoAprendizaje1 = 0.0;
        double ResultadoAprendizaje2 = 0.0;
        double ResultadoFinal = 0.0;
        //Criterios de Evaluacion
        double CriterioEvaluacion11 = 0.0;
        double CriterioEvaluacion12 = 0.0;
        double CriterioEvaluacion13 = 0.0;
        double CriterioEvaluacion21 = 0.0;
        //Instrumentos de Evaluacion y CE asociados
        double Instrumento1 = 0.0;
        double Instrumento2 = 0.0;
        double Instrumento3 = 0.0;
        double Instrumento4 = 0.0;
        
        double Instrumento1CE11 = 0.0;
        double Instrumento2CE11 = 0.0;
        double Instrumento3CE11 = 0.0;
        
        double Instrumento1CE12 = 0.0;
        double Instrumento2CE12 = 0.0;
        double Instrumento3CE12 = 0.0;
        
        double Instrumento1CE13 = 0.0;
        double Instrumento2CE13 = 0.0;
        double Instrumento3CE13 = 0.0;  
        
        double Instrumento2CE21 = 0.0;
        double Instrumento4CE21 = 0.0;
        
        //BIENVENIDA
        cout << "Bienvenido a un programa que calcula tu nota final de FP mediante unos criterios de evaluacion..." << endl;
        cout << "Se deben introducir en todo momento numeros positivos enteros o reales..." << endl;
        
        //ENTRADA DE DATOS
        cout << "Por favor" << endl;
        cout << "Introduce la nota del Instrumento de Evaluacion 1: ";
        cin >> Instrumento1;
        cout << "Introduce la nota del Instrumento de Evaluacion 2: ";
        cin >> Instrumento2;
        cout << "Introduce la nota del Instrumento de Evaluacion 3: ";
        cin >> Instrumento3;
        cout << "Introduce la nota del Instrumento de Evaluacion 4: ";
        cin >> Instrumento4;
        
        //CÁLCULOS INSTRUMENTOS DE EVALUACION
        Instrumento1CE11 = Instrumento1 * I1CE11;
        Instrumento2CE11 = Instrumento2 * I2CE11;
        Instrumento3CE11 = Instrumento3 * I3CE11;
        
        cout << RED << "DEBUG: Resultado Instrumento1CE1.1: " << Instrumento1CE11 << RESET << endl;
        cout << RED << "DEBUG: Resultado Instrumento2CE1.1: " << Instrumento2CE11 << RESET << endl;
        cout << RED << "DEBUG: Resultado Instrumento3CE1.1: " << Instrumento3CE11 << RESET << endl;
        
        Instrumento1CE12 = Instrumento1 * I1CE12;
        Instrumento2CE12 = Instrumento2 * I2CE12;
        Instrumento3CE12 = Instrumento3 * I3CE12;
        
        cout << RED << "DEBUG: Resultado Instrumento1CE1.2: " << Instrumento1CE12 << RESET << endl;
        cout << RED << "DEBUG: Resultado Instrumento2CE1.2: " << Instrumento2CE12 << RESET << endl;
        cout << RED << "DEBUG: Resultado Instrumento3CE1.2: " << Instrumento3CE12 << RESET << endl;
        
        Instrumento1CE13 = Instrumento1 * I1CE13;
        Instrumento2CE13 = Instrumento2 * I2CE13;
        Instrumento3CE13 = Instrumento3 * I3CE13;
        
        cout << RED << "DEBUG: Resultado Instrumento1CE1.3: " << Instrumento1CE13 << RESET << endl;
        cout << RED << "DEBUG: Resultado Instrumento2CE1.3: " << Instrumento2CE13 << RESET << endl;
        cout << RED << "DEBUG: Resultado Instrumento3CE1.3: " << Instrumento3CE13 << RESET << endl;
        
        Instrumento2CE21 = Instrumento2 * I2CE21;
        Instrumento4CE21 = Instrumento4 * I4CE21;
        
        cout << RED << "DEBUG: Resultado Instrumento2CE2.1: " << Instrumento2CE21 << RESET << endl;
        cout << RED << "DEBUG: Resultado Instrumento4CE2.1: " << Instrumento4CE21 << RESET << endl;
        
        //CÁLCULOS CRITERIOS EVALUACION
        CriterioEvaluacion11 = (Instrumento1CE11 + Instrumento2CE11 + Instrumento3CE11);
        
        CriterioEvaluacion12 = (Instrumento1CE12 + Instrumento2CE12 + Instrumento3CE12);
        
        CriterioEvaluacion13 = (Instrumento1CE13 + Instrumento2CE13 + Instrumento3CE13);
        
        CriterioEvaluacion21 = (Instrumento2CE21 + Instrumento4CE21);
        
        //CÁLCULOS RESULTADOS APRENDIZAJE
        ResultadoAprendizaje1 = ( (CriterioEvaluacion11 * CE11) + (CriterioEvaluacion12 * CE12) + (CriterioEvaluacion13 * CE13) );
        ResultadoAprendizaje2 = CriterioEvaluacion21 * CE21;
        
        //CÁLCULOS RESULTADO FINAL
        ResultadoFinal = (ResultadoAprendizaje1 * RA1) + (ResultadoAprendizaje2 * RA2);
        
        //COUT RESULTADOS
        cout << "Criterio evaluacion 1.1: " << GREEN << CriterioEvaluacion11 << RESET << endl;
        cout << "Criterio evaluacion 1.2: " << GREEN << CriterioEvaluacion12 << RESET << endl;
        cout << "Criterio evaluacion 1.3: " << GREEN << CriterioEvaluacion13 << RESET << endl;
        cout << "Criterio evaluacion 2.1: " << GREEN << CriterioEvaluacion21 << RESET << endl;
        cout << "Resultado aprendizaje 1: " << GREEN << ResultadoAprendizaje1 << RESET << endl;
        cout << "Resultado aprendizaje 2: " << GREEN << ResultadoAprendizaje2 << RESET << endl;
        cout << "Resultado final: " << GREEN << ResultadoFinal << RESET << endl;
        
        
        
        
        
        
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
 
 
 }
