#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main() {
    float notas[100];
    int cantidad = 0;
    int opcion;
    float suma = 0, promedio = 0;
    
    bool cantidad_definida = false;
    bool notas_ingresadas = false;

    do {
        system("cls");
        cout << "========================================" << endl;
        cout << "       SISTEMA DE GESTION ESCOLAR       " << endl;
        cout << "========================================" << endl;
        cout << "1. Definir cantidad de notas" << endl;
        cout << "2. Ingresar calificaciones" << endl;
        cout << "3. Generar Planilla de Resultados" << endl;
        cout << "4. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: //Preguntar cuantas notas se van a ingresar
                cout << "\nCuantas notas va a registrar? ";
                cin >> cantidad;
                if(cantidad > 0 && cantidad <= 100) { //Confirmar que la cantidad este entre 0 y 100
                    cantidad_definida = true;
                    notas_ingresadas = false;
                    cout << ">> Cantidad establecida correctamente." << endl;
                } else {
                    cout << ">> Error: Cantidad no valida." << endl;
                }
                system("pause");
                break;

            case 2: //Ingresar las notas como tal
                if(cantidad_definida) { //confirmar que la opcion 1 ya se haya concretado
                    suma = 0;
                    cout << "\n--- REGISTRO DE CALIFICACIONES ---" << endl;
                    for(int i = 0; i < cantidad; i++) {
                        cout << "Nota #" << i + 1 << ": ";
                        cin >> notas[i];
                        suma += notas[i];
                    }
                    notas_ingresadas = true;
                    cout << ">> Todas las notas han sido guardadas." << endl;
                } else {
                    cout << ">> Debe realizar el paso 1 primero." << endl;
                }
                system("pause");
                break;

            case 3: //mostrar todas las notas solo si la opcion 2 se completo
                if(notas_ingresadas) {
                    promedio = suma / cantidad;
                    
                    cout << "\n          PLANILLA DE NOTAS          " << endl;
                    cout << "=====================================" << endl;
                    cout << "  ID        CALIFICACION    ESTADO   " << endl;
                    cout << "-------------------------------------" << endl;
                    
                    for(int i = 0; i < cantidad; i++) { //revisar nota por nota
                        // Se ponen tabulaciones \t para alinear como tabla
                        cout << "  " << i + 1 << "\t\t" << notas[i] << "\t    ";
                        if(notas[i] >= 3.0) cout << "[P]" << endl; // Verificar si la nota es mayor a 3.0 para ver si paso o no
                        else cout << "[F]" << endl;
                    }
                    
                    cout << "-------------------------------------" << endl;
                    cout << " PROMEDIO GENERAL: " << promedio << endl;
                    cout << " RESULTADO FINAL:  " << (promedio >= 3.0 ? "APROBADO" : "REPROBADO") << endl;
                    cout << "=====================================" << endl;
                    cout << " Leyenda: [P] Paso | [F] Fallo" << endl;
                } else {
                    cout << ">> No hay datos suficientes para generar la planilla." << endl;
                }
                system("pause");
                break;

            case 4:
                cout << "Cerrando planilla digital..." << endl; 
                break;

            default:
                cout << "Opcion invalida." << endl;
                system("pause");
        }
    } while(opcion != 4); 

    return 0;
}
