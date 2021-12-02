
typedef struct Arbol
{
    int dato;
    struct Arbol *izq;
    struct Arbol *der;
} tarbol;

void Carga(tarbol **A,int X)
{
    if (*A==NULL)
    {
        *A=malloc(sizeof(tarbol));
        (*A)->dato=X;
        (*A)->izq=NULL;
        (*A)->der=NULL;
    }
    else if ((*A)->dato > X)
        Carga(&(*A)->izq,X);
    else
        Carga(&(*A)->der,X);
}

void MuestraIn(tarbol *A)
{
    if (A!=NULL)
    {
        MuestraIn(A->izq);
        printf("[ %d ]",A->dato);
        MuestraIn(A->der);
    }
}

void MuestraPre(tarbol *A)
{
    if (A!=NULL)
    {
        printf("[ %d ]",A->dato);
        MuestraIn(A->izq);
        MuestraIn(A->der);
    }
}

void MuestraPos(tarbol *A)
{
    if (A!=NULL)
    {
        MuestraIn(A->izq);
        MuestraIn(A->der);
        printf("[ %d ]",A->dato);
    }
}

int Altura(tarbol *A)
{
    if (A==NULL)
        return(0);
    else if ((Altura(A->der)) > (Altura(A->izq)))
        return(1+Altura(A->der));
    else
        return(1+Altura(A->izq));
}

void menor (tarbol *a, int *e)
{
    if (a->izq==NULL)
        (*e)= a->dato;
    else
        menor(a->izq,e);
}

void buscar (tarbol *a, int c, int *enc)
{
    if (a!=NULL)
    {
        if (a->dato==c)
            *enc=1;
        else if (a->dato>c)
            buscar(a->izq,c,enc);
        else
            buscar(a->der,c,enc);
    }
    else
        *enc=0;
}

int Alturaizq(tarbol *A)
{
    if (A!=NULL)
    {
        A = A->izq;}
  if (A==NULL)
        return(0);
    else if ((Altura(A->der)) > (Altura(A->izq)))
        return(2+Altura(A->der));
    else
        return(2+Altura(A->izq));
}

int Alturader(tarbol *A)
{
    if (A!=NULL)
    {
        A = A->der;}
  if (A==NULL)
        return(0);
    else if ((Altura(A->der)) > (Altura(A->izq)))
        return(2+Altura(A->der));
    else
        return(2+Altura(A->izq));
}
