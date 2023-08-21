#include "conjunto.h"
#include <ctime>

namespace Pedro{

Conjunto::Conjunto(int tamanho):
    tamanho(0),
    array(0)
{
    if (tamanho <= 0)
    {
        throw QString("tamanho invalido");
    }
    try{
        array = new int[tamanho];
        this->tamanho = tamanho;
        srand(time(0));
        for (int i = 0; i < tamanho; i++)
        {
            array[i] = rand() % 1001;
        }
    }
    catch(std::bad_alloc &e){
        throw QString("Memoria nao alocada");
    }
}

QString Conjunto::getConjunto() const
{
    if (!array){
        throw QString("O vetor nao existe");
    }
    QString saida = "";
    for (int i = 0; i < tamanho; i++)
    {
        if (i == tamanho-1){
            saida += QString::number(array[i]);
        }
        else{
            saida += QString::number(array[i]);
            saida += " | ";
        }
    }
    return saida;
}

QString Conjunto::getConjuntoOrdenado() const
{
    if (!arraySelectionSort){
        throw QString("O vetor nao existe");
    }
    QString saida = "";
    for (int i = 0; i < tamanho; i++)
    {
        if (i == tamanho-1){
            saida += QString::number(arraySelectionSort[i]);
        }
        else{
            saida += QString::number(arraySelectionSort[i]);
            saida += " | ";
        }
    }
    return saida;
}




Conjunto::~Conjunto()
{
    if (array){
        delete[] array;
    }
    if (arraySelectionSort){
        delete [] arraySelectionSort;
    }
}

int Conjunto::buscarValor(int valor) const
{
    if (!arraySelectionSort){
        throw QString("Array nao criado");
    }
    for (int i = 0; i < tamanho; i++){
        if (arraySelectionSort[i] == valor){
            return i;
        }
        if (arraySelectionSort[i] > valor){
            return -1;
        }
    }
    return -1;
}

void Conjunto::selectionSort()
{
    if (!array){
        throw QString("Array nao criado");
    }
    try {
        arraySelectionSort = new int[tamanho];
        std::memcpy(arraySelectionSort, array, tamanho * sizeof(int));
        for (int indice = 0; indice < tamanho - 1; indice++){
            int min_idc = indice;
            for (int i = indice + 1; i < tamanho; i++){
                if (arraySelectionSort[i] < arraySelectionSort[min_idc]){
                    min_idc = i;
                }
            }
            int temp = arraySelectionSort[indice];
            arraySelectionSort[indice] = arraySelectionSort[min_idc];
            arraySelectionSort[min_idc] = temp;
        }
    } catch (std::bad_alloc) {
        throw QString("Nao foi possivel alocar memoria para novo array");
    }
}

}
