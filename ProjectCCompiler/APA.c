#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define valMax 50000


int Insertion_Sort(int* a);
void Pegar_Aleatorios(int* array1);
void Copia_Array(int* array1, int* array2);
int Insertion_Sort(int* a);
int Selection_Sort(int* a);
int Bubble_Sort(int* a);
void Cria_Heap(int* vet, int i, int f);
int Heap_Sort(int* vet);
int Shell_Sort(int* a);
int Quick_Sort(int* a, int left, int right, int *qtdTroca);

int main(int argc, char** argv)
{

    srand(time(NULL));
    int vet[valMax];


    // arrays que serao ordenados
    int insertionSortVet[valMax];
    int selectionSortVet[valMax];
    int bubbleSortVet[valMax];
    int heapSortVet[valMax];
    int shellSortVet[valMax];
    int quickSortVet[valMax];

    // Variaveis que irao armazenar a quantidade de trocas
    int insertionSortTrocas = 0, selectionSortTrocas = 0, bubbleSortTrocas = 0, heapSortTrocas = 0, shellSortTrocas = 0, quickSortTrocas = 0;


    //Criando array com valores aleatorios ...
    Pegar_Aleatorios(vet);


    //copiando os arrays ...
    Copia_Array(vet, insertionSortVet);
    Copia_Array(vet, selectionSortVet);
    Copia_Array(vet, bubbleSortVet);
    Copia_Array(vet, heapSortVet);
    Copia_Array(vet, shellSortVet);
    Copia_Array(vet, quickSortVet);





    printf("\n ----  valores não ordenados ---- \n");
    for (int i = 0; i < valMax; i++) {
        printf("%d \n", quickSortVet[i]);
    }

    //Usando as funçoes para ordernar
    insertionSortTrocas = Insertion_Sort(insertionSortVet);
    selectionSortTrocas = Selection_Sort(selectionSortVet);
    bubbleSortTrocas = Bubble_Sort(bubbleSortVet);
    heapSortTrocas = Heap_Sort(heapSortVet);
    shellSortTrocas = Shell_Sort(shellSortVet);
    quickSortTrocas = Quick_Sort(quickSortVet, 0, valMax -1, quickSortTrocas);

    printf("\n ----  valores ordenados ---- \n");
    for (int i = 0; i < valMax; i++) {
        printf("%d \n", quickSortVet[i]);
    }


    printf("\n \n O InsertionSort realizou %d trocas.", insertionSortTrocas);
    printf("\n \n O SelectionSort realizou %d trocas.", selectionSortTrocas);
    printf("\n \n O BubbleSort realizou %d trocas.", bubbleSortTrocas);
    printf("\n \n O HeapSort realizou %d trocas.", heapSortTrocas);
    printf("\n \n O ShellSort realizou %d trocas.", shellSortTrocas);
    printf("\n \n O QuickSort realizou %d trocas.", quickSortTrocas);



    printf(" \n \n -------------- \n\n");
    return 0;
}

// Func para criar numeros aleatorios e preencher o array;
void Pegar_Aleatorios(int* array1) {
    for (int i = 0; i < valMax; i++) {
        int provisorio = rand() % 99999;

        if (provisorio >= 10000) {
            array1[i] = provisorio;
        }
        else {
            i--;
        }
    }
}

// Func para copiar o array
void Copia_Array(int* arrayOriginal, int* arrayCopia) {
    for (int i = 0; i < valMax; i++) {
        arrayCopia[i] = arrayOriginal[i];
    }
}


// Func InsertionSort
int Insertion_Sort(int* a)
{
    int i, j, tmp, trocas = 0;

    for (i = 1; i < valMax; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0 && tmp < a[j]; j--)
        {
            a[j + 1] = a[j];
            trocas++;
        }
        a[j + 1] = tmp;
    }
    return trocas;
}

// Func SelectionSort
int Selection_Sort(int* pVetor)
{
    int vMenor, vAux, vTemp, vTroca, qtdTrocas = 0;

    for (vAux = 0; vAux < valMax - 1; vAux++)
    {
        vMenor = vAux;

        for (vTemp = vAux + 1; vTemp < valMax; vTemp++)
        {
            if (pVetor[vTemp] < pVetor[vMenor])
            {
                vMenor = vTemp;
            }
        }

        if (vMenor != vAux)
        {
            vTroca = pVetor[vAux];
            pVetor[vAux] = pVetor[vMenor];
            pVetor[vMenor] = vTroca;
            qtdTrocas++;
        }
    }

    return qtdTrocas;
}


//Func BubbleSort
int Bubble_Sort(int* a)
{
    int i, j, tmp, qtdTrocas = 0;

    for (i = 0; i < valMax; i++)
    {
        for (j = i + 1; j < valMax; j++)
        {
            if (a[j] < a[i])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                qtdTrocas++;

            }
        }
    }
    return qtdTrocas;
}


// Func HeapSort
int Heap_Sort(int* vet) {
    int i, aux, qtdTrocas = 0;

    for (i = (valMax - 1) / 2; i >= 0; i--) {
        Cria_Heap(vet, i, valMax - 1);
    }
    for (i = valMax - 1; i >= 1; i--) {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        Cria_Heap(vet, 0, i - 1);
        qtdTrocas++;
    }
    return qtdTrocas;
}

//Func que cria o heap.
void Cria_Heap(int* vet, int i, int f) {
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f) {
        if (j < f) {
            if (vet[j] < vet[j + 1]) {
                j = j + 1;
            }
        }
        if (aux < vet[j]) {
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            j = f + 1;
        }
    }
    vet[i] = aux;
}

//Func ShellSort
int Shell_Sort(int* a){
    int i, j, value, qtdTroca = 0;
    int gap = 1;

    do {
        gap = 3 * gap + 1;
    } while (gap < valMax);

    do {
        gap /= 3;
        for (i = gap; i < valMax; i++) {
            value = a[i];
            j = i - gap;

            while (j >= 0 && value < a[j]) {
                a[j + gap] = a[j];
                j -= gap;
                qtdTroca++;
            }
            a[j + gap] = value;
        }
    } while (gap > 1);
    return qtdTroca;
}

//Func QuickSort
int Quick_Sort(int* a, int left, int right, int *qtdTroca) {
    int i, j, x, y, aux = 0;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < x && i < right) {
            i++;
        }
        while (a[j] > x && j > left) {
            j--;
        }
        if (i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
            aux++;
        }
    }

    qtdTroca = qtdTroca + aux;

    if (j > left) {
        Quick_Sort(a, left, j, qtdTroca);
    }
    if (i < right) {
        Quick_Sort(a, i, right, qtdTroca);
    }
    return qtdTroca;
}
