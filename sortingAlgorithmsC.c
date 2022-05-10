#include <stdio.h>

void bubbleSort(int [], int);
void insertionSort(int [], int);
void selectionSort(int [], int);
void quickSort(int [], int, int);
//--------------------------------
void impArreglo(int[]);
void recorreElementos(int [], int, int);
void obtenMinimo(int[]);

int main() {
    printf("BUBBLE SORT\n");
    int a[] = {9,8,7,6,5,4,3,2,1};
    bubbleSort(a,9);
    impArreglo(a);
    
    printf("INSERTION SORT\n");
    int b[] = {9,8,7,6,5,4,3,2,1};
    insertionSort(b,9);
    impArreglo(b);
    
    printf("SELECTION SORT\n");
    int c[] = {9,8,7,6,5,4,3,2,1};
    selectionSort(c,9);
    impArreglo(c);
    
    printf("QUICK SORT\n");
    int d[] = {9,8,7,6,5,4,3,2,1};
    quickSort(d,0,8);
    impArreglo(c);
    
    return 0;
}

void bubbleSort(int arreglo[], int tamA){
    int elemOrd = 0, puente;
    for(int _ = 1;_ < tamA;_++){
        for(int j = tamA-1;j > elemOrd;j--){
            if(arreglo[j]<arreglo[j-1]){
                puente = arreglo[j-1];
                arreglo[j-1] = arreglo[j];
                arreglo[j] = puente;
            }
        }
        elemOrd++;  
    }
}

void insertionSort(int arreglo[], int tamA){
    for(int i=1;i<tamA;i++){
        int numPosiciones = 0;
        for(int j=i-1;j>=0;j--){
            if(arreglo[i]<arreglo[j]){
                numPosiciones++;
            }
            else{
                break;
            }
        }
        recorreElementos(arreglo,i,numPosiciones);
    }
}

void selectionSort(int arreglo[], int tamA){
    int posMinimo, puente;
    for(int i=0;i < tamA;i++){
        posMinimo = i;
        for(int j=i+1;j<tamA;j++){
            if(arreglo[j]<arreglo[posMinimo]){
                posMinimo = j;
            }
        }
        puente = arreglo[i];
        arreglo[i] = arreglo[posMinimo];
        arreglo[posMinimo] = puente;
    }
}

void quickSort(int arreglo[], int izq, int der){
    if(izq!=der){
        int pivote = izq;
        for(int i=izq+1;i<der;i++){
            if(arreglo[pivote]>arreglo[i]){
                recorreElementos(arreglo,i,i-pivote);
                pivote++;
            }
        }
        quickSort(arreglo,izq,pivote-1);
        quickSort(arreglo,pivote+1,der);
    }
}

void impArreglo(int a[]){
    int i = 0;
    while(a[i]!='\0'){
        printf("%d ", a[i]); i++;
    }
    printf("\n");
}

void recorreElementos(int arreglo[], int posFinal, int numPosiciones){
    int puente = arreglo[posFinal];
    for(int i=0;i<numPosiciones;i++){
        arreglo[posFinal] = arreglo[posFinal-1];
        posFinal--;
    }
    arreglo[posFinal] = puente;
}
