#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct citasPacientes{

    char nombre[20];
    int edad;
    char fecha[20];

}paciente;


int crearNuevaCita(){

    int controlador;

    FILE *fp;
    fp = fopen("citas_agendadas.txt", "a");
    if(fp == NULL)
        return 1;

    do{
        fflush(stdin);
        printf("Ingrese el nombre del paciente: ");
        gets(paciente.nombre);

        printf("Ingrese la fecha de la cita: ");
        gets(paciente.fecha);

        printf("Ingrese la edad del paciente: ");
        scanf("%d", &paciente.edad);

        fwrite(&paciente, sizeof(paciente), 1, fp);
        printf("Desea agegar otro paciente?\nSi [1] || No [0]");
        scanf("%i", &controlador);
    }while(controlador == 1);
    
    fclose(fp);
}

int LeerCita(){
    FILE *fp;
    fp = fopen("citas_agendadas.txt", "r");
    if(fp == NULL)
        return 1;

    fread(&paciente, sizeof(paciente), 1, fp);
    printf("+----------------------------+------------+-------------+\n");
    printf("|           Nombre           |    edad    |  Fecha Cita |\n");
    while(!feof(fp)){

        printf("+----------------------------+------------+-------------+\n");
        printf("| %-26s | %-10d | %-11s |\n", paciente.nombre, paciente.edad, paciente.fecha);
        fread(&paciente, sizeof(paciente), 1, fp);
        
    }
    printf("+----------------------------+------------+-------------+\n");
    fclose(fp);
}

int buscarPaciente(){

    char nombreBuscar[20];

    FILE *fp;
    fp = fopen("citas_agendadas.txt", "a+");
    if(fp == NULL)
        return 1;

    fflush(stdin);
    printf("Ingresa el nombre que quieres buscar: ");
    gets(nombreBuscar);

    printf("+----------------------------+------------+-------------+\n");
    printf("|           Nombre           |    edad    |  Fecha Cita |\n");
    while(!feof(fp)){

        fread(&paciente, sizeof(paciente), 1, fp);

        if(strstr(nombreBuscar, paciente.nombre) != NULL){

            printf("+----------------------------+------------+-------------+\n");
            printf("| %-26s | %-10d | %-11s |\n", paciente.nombre, paciente.edad, paciente.fecha);
            break;
        }
    }
    printf("+----------------------------+------------+-------------+\n");
    fclose(fp);

}



#endif