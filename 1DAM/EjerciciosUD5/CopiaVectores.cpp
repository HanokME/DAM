#include <iostream>
using namespace std;

/**
 * @brief Programa que copia los valores de un vector introducidos por el usuario a otro vector.
 * @version 1.0
 * @author Hanok
*/

int main(){

    //VECTOR DONDE SE GUARDA LOS VALORES INGRESADOS POR EL USUARIO.
    const int V_INICIAL = 100;
    double v_inicial[V_INICIAL] = {0.0};
    int util_v_inicial = 0;

    //VECTOR DONDE SE GUARDA LOS VALORES COPIADOS.
    const int V_FINAL = 100;
    double v_final[V_FINAL] = {0.0};
    int util_v_final = 0;

    cout << "Bienvenido al programa que copia los valores de un vector introducidos por el usuario a otro." << endl;

    do{
        cout << "Ingrese el tamaño del vector inicial: ";
        cin >> util_v_inicial;
        
        if ( util_v_inicial <= 0 || util_v_inicial > V_INICIAL ){

            cout << "El tamaño del vector inicial debe ser un entero entre 1 y " << V_INICIAL << "." << endl;

        }
    } while ( util_v_inicial <= 0 || util_v_inicial > V_INICIAL );

    //BUCLE PARA INTRODUCIR VALORES EN EL VECTOR INICIAL
    for ( int i = 0; i < util_v_inicial; i++ ){
        
        do{
            
            cout << "Ingrese el valor " << i + 1 << " del vector inicial: ";
            cin >> v_inicial[i];

            if ( v_inicial[i] <= 0 ){
                cout << "El valor debe ser mayor que 0." << endl;
            }
            

        } while (v_inicial[i] <= 0);

        
    }

    //BUCLE QUE COPIA LOS VALORES DEL VECTOR INICIAL EN EL VECTOR FINAL
    for (int i = 0; i < util_v_inicial; i++){

        v_final[i] = v_inicial[i];
        util_v_final++;

    }

    //MOSTRAR LOS VALORES QUE ESTÁN EN LOS DOS VECTORES

    cout << "Los valores del vector inicial son: " << endl;
    for ( int i = 0; i < util_v_inicial; i++ ){

        cout << v_inicial[i] << " | ";

        
    }
    cout << endl;

    cout << "Los valores del vector final son: " << endl;
    for ( int i = 0; i < util_v_final; i++ ){
        cout << v_final[i] << " | ";
    }
    cout << endl;
    cout << "Util del vector inicial: " << util_v_inicial << endl;
    cout << "Util del vector final: " << util_v_final << endl;
    

}