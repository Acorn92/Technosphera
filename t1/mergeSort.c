#include "mergeSort.h"
#include "../Example/sysprog/1/libcoro.h"


void 
merge(int* a, size_t lengthA, int* b, size_t lengthB, int* rez, size_t lengthRez)
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
            lengthSort = lengthB;
            bigMas = 1;
        }  
        else
        {
            lengthSort = lengthA;
            bigMas = 2;
        }
    }
    else
        //если равны - пофиг
        lengthSort = lengthA;
    
    // int sizeRez = lengthA + lengthB;
    // *lengthRez = sizeRez;
    // int *rez = (int *) malloc(sizeRez*sizeof(long int));

    int current = 0;
    while (((left < lengthSort) && (left < lengthA)) && ((right < lengthSort) && (right < lengthB)))
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

    while (current < lengthRez)
    {

        if (left != lengthA)
        {
            rez[current] = a[left];
            left++;
        }
        if (right != lengthB)
        {
            rez[current] = b[right];
            right++;
        }
        current++; 
    }

    // return rez;
}

// int* 
// mergeLI(long int* a, size_t lengthA, int* b, size_t lengthB, size_t* lengthRez)
// {
//     int left = 0;
//     //сравниваем длины массивов, если разные, то элементы наибольшего
//     //добавятся в конце результирующего, т.к. массивы уже отсортированы
//     int right = 0;
//     char bigMas = 0;//будем хранить какой массив больше: 0 - никакой, 1 - a, 2 - b
//     int lengthSort = 0;
//     if (lengthA != lengthB)
//     {
//         if (lengthA < lengthB)  
//         {
//             lengthSort = lengthB;
//             bigMas = 1;
//         }  
//         else
//         {
//             lengthSort = lengthA;
//             bigMas = 2;
//         }
//     }
//     else
//         //если равны - пофиг
//         lengthSort = lengthA;
    
//     int sizeRez = lengthA + lengthB;
//     *lengthRez = sizeRez;
//     long int *rez = (long int *) malloc(sizeRez*sizeof(long int));

//     int current = 0;
//     while (left < lengthSort && right < lengthSort)
//     {
//         if (a[left] <= b[right])
//         {
//             rez[current] = a[left];
//             left++;
//         }
//         else
//         {
//             rez[current] = b[right];
//             right++;
//         }
//         current++;
//     }

//     while (current < *lengthRez)
//     {
//         switch (bigMas)
//         {
//             case 0:
//             {
//                 if (left != lengthSort)
//                 {
//                     rez[current] = a[left];
//                     left++;
//                 }
//                 if (right != lengthSort)
//                 {
//                     rez[current] = b[right];
//                     right++;
//                 }
//                 break;
//             }
//             case 1:
//             {
//                 rez[current] = a[left];
//                 left++;
//                 break;
//             }
//             case 2:
//             {
//                 rez[current] = b[right];
//                 right++;
//                 break;
//             }
//         }
//         current++;        
//     }
  

//     return rez;
// }

// int* 
// mergeLL(long int* a, size_t lengthA, long int* b, size_t lengthB, size_t* lengthRez)
// {
//     int left = 0;
//     //сравниваем длины массивов, если разные, то элементы наибольшего
//     //добавятся в конце результирующего, т.к. массивы уже отсортированы
//     int right = 0;
//     char bigMas = 0;//будем хранить какой массив больше: 0 - никакой, 1 - a, 2 - b
//     int lengthSort = 0;
//     if (lengthA != lengthB)
//     {
//         if (lengthA < lengthB)  
//         {
//             lengthSort = lengthB;
//             // lengthSort = lengthA;
//             bigMas = 1;
//         }  
//         else
//         {
//             lengthSort = lengthA;
//             // lengthSort = lengthB;
//             bigMas = 2;
//         }
//     }
//     else
//         //если равны - пофиг
//         lengthSort = lengthA;
    
//     int sizeRez = lengthA + lengthB;
//     *lengthRez = sizeRez;
//     long int *rez = (long int *) malloc(sizeRez*sizeof(long int));

//     int current = 0;
//     while (((left < lengthSort) && (left < lengthA)) && ((right < lengthSort) && (right < lengthB)))
//     {
//         if (a[left] <= b[right])
//         {
//             rez[current] = a[left];
//             left++;
//         }
//         else
//         {
//             rez[current] = b[right];
//             right++;
//         }
//         current++;
//     }
//     sizeRez = 0;
//     while (current < *lengthRez)
//     {

//         if (left != lengthA)
//         {
//             rez[current] = a[left];
//             left++;
//         }
//         if (right != lengthB)
//         {
//             rez[current] = b[right];
//             right++;
//         }

        
//         // switch (bigMas)
//         // {
//         //     case 0:
//         //     {
//         //         if (left != lengthSort)
//         //         {
//         //             rez[current] = a[left];
//         //             left++;
//         //         }
//         //         if (right != lengthSort)
//         //         {
//         //             rez[current] = b[right];
//         //             right++;
//         //         }
//         //         break;
//         //     }
//         //     case 1:
//         //     {
//         //         rez[current] = a[left];
//         //         left++;
//         //         break;
//         //     }
//         //     case 2:
//         //     {
//         //         rez[current] = b[right];
//         //         right++;
//         //         break;
//         //     }
//         // }
//         current++;        
//     }
  

//     return rez;
// }