#include "funciones.h"

FILE *fp;

int main(void){

    int selector;


    do{

        printf("\t\t---SISTEMA DE AGENDAS DE CITAS---\n\n");
        printf("1. Listar citas agendadas\n2. Agendar nueva cita\n3. Modificar cita\n4. Buscar cita\n5. Filtrar citas por fechas\n");
        scanf("%i", &selector);
        system("clear");

        switch(selector){

        case 1: LeerCita();
            system("pause");
            break;
        case 2: crearNuevaCita();
            system("pause");
            break;
        case 3: //modificarCita();
            system("pause");
            break;
        case 4: buscarPaciente();
            system("pause");
            break;
        case 5: //filtrarCitasPorFecha();
            system("pause");
            break;
        default:
            printf("Opcion no validad\n");
            system("pause");
            break;
        }
        system("clear");

    }while(selector != 3);

    


    return 0;
}


