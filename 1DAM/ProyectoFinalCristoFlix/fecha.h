#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class Fecha{

    private:
        int dia;
        int mes;
        int anio;

    public:

        Fecha();
        
        Fecha(const Fecha &f);

        Fecha(int dia, int mes, int anio);

        void setDia(int dia);

        void setMes(int mes);

        void setAnio(int anio);

        int getDia()const;

        int getMes()const;

        int getAnio()const;

        void setFecha(int dia, int mes, int anio);

        friend ostream& operator<<(ostream &flujo, const Fecha &fecha);

        Fecha& operator=(const Fecha &fecha);

        bool operator==(const Fecha &fecha)const;

 


};