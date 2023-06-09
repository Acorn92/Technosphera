#include "quickSort.h"

void
quickSort(int *arr, int left, int right)
{
    int index = partition(arr, left, right);
    // coro_yield();
    if (left < index  - 1)
        quickSort(arr, left, index - 1);    
    if (index < right)
        quickSort(arr, index, right);
}


static int 
partition(int *arr, int left, int right)
{    
    int pivot = arr[(left + right) / 2];
    while (left <= right)
    {
        //ищем элемент слева, который больше центрального
        while (arr[left] < pivot) left++;

        //ищем элемент слева, который меньше центрального
        while (arr[right] > pivot) right--;

        if (left <= right)
        {
            swap(arr, left, right);
            left++;
            right--;
        }
    }

    return left;
}

static void swap(int *arr, int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}