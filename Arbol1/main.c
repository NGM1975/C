#include <stdio.h>
#include <stdlib.h>
#include "Aebol1.h"

int menu();
void Carga(tarbol **A,int X);
void MuestraIn(tarbol *A);
//int CantNodos(tarbol *A);
int Altura(tarbol *A);
void menor(tarbol *a, int *e);
void buscar (tarbol *a, int c, int *enc);
int Alturaizq(tarbol *A);
int Alturader(tarbol *A);
//int Altura1(tarbol *A);

int main()
{
    //char car;
    int X,m,v,enc;
    int op,res,iz=0,de=0,Max=0;
    tarbol *Ar=NULL;
    printf("Programa que maneja Arboles!\n");
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("\nInvocamos a ARMAR y Cargamos un Arbol\n");
            printf("\nIngrese valor Entero\n");
            fflush(stdin);
            scanf("%d",&X);
            Carga(&Ar,X);
            break;
        case 2:
            printf("\nMostramos el Arbol\n");
            MuestraIn(Ar);
            break;
        case 3:
            printf("\nInvocamos a altura de un Arbol\n");
            printf("\nLa Altura es.....%d\n",Altura(Ar));
            break;
        case 4:
            printf("\nInvocamos a menor valor de un Arbol\n");
            menor(Ar, &m);
            printf("\nEl Menor valor es.....%d\n",m);
            break;
        case 5:
            printf("\nBuscamos un valor del Arbol\n");
            printf("\nIngrese valor a buscar..:\n");
            fflush(stdin);
            scanf("%d",&v);
            buscar (Ar,v, &enc);
            if(enc)
                printf("\nEl valor %d se encuentra en el Arbol\n",v);
            else
                printf("\nEl valor %d NO se encuentra en el Arbol\n",v);
            break;
            case 6:
            printf("\nInvocamos a altura izq y der de un Arbol\n");

            printf("\nLa Altura izquierda es.....%d\n",Alturaizq(Ar));
            printf("\nLa Altura derecha es.....%d\n",Alturader(Ar));
            break;

        }
        printf("\nContinua operando con Arboles?? 1 = SI...0 = Fin\n");
        fflush(stdin);
        scanf("%d",&res);
    }
    while (res!=0);
}
int menu()
{
    int auxi;
    do
    {
        system("cls");
        printf("\nSeleccione una opcion\n");
        printf("\n---------------------\n");
        printf("\n1. Cargar un Arbol\n");
        printf("\n2. Mostrar el Arbol\n");
        printf("\n3. Calcular altura del Arbol\n");
        printf("\n4. Calcular menor valor del Arbol\n");
        printf("\n5. Buscar dato en el Arbol\n");
        printf("\n6. Calcular altura izq y der del Arbol\n");
        printf("\n0. Fin programa\n");
        fflush(stdin);
        scanf("%d",&auxi);
    }
    while (auxi<0 || auxi>6);
    return (auxi);
}

