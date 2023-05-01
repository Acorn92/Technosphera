#include "mergeSort.h"


int* 
merge(int* a, size_t lengthA, int* b, size_t lengthB, size_t* lengthRez)
{
    int left = 0;
    //сравниваем длины массивов, если разные, то элементы наибольшего
    //добавятся в конце результирующего, т.к. массивы уже отсортированы
    int right = 0;
    char bigMas = 0;//будем хранить какой массив больше: 0 - никакой, 1 - a, 2 - b
    int lengthSort = 0;
    if (lengthA != lengthB)
    {
        if (lengthA < lengthB)  
        {
            lengthSort = lengthA;
            bigMas = 2;
        }  
        else
        {
            lengthSort = lengthB;
            bigMas = 1;
        }
    }
    else
        //если равны - пофиг
        lengthSort = lengthA;
    
    *lengthRez = lengthA + lengthB;     
    int *rez = (int *) malloc((*lengthRez) * sizeof(int));

    int current = 0;
    while ((left <= lengthSort) && (right <= lengthSort))
    {
        if (a[left] <= b[right])
        {
            rez[current] = a[left];
            left++;
        }
        else
        {
            rez[current] = b[right];
            right++;
        }
        current++;
    }

    return rez;
}