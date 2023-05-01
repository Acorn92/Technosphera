#include "quickSort.h"
#include "mergeSort.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>    

int 
getFileSize(const char *fileName)
{
    int _fileSize = 0;
    struct stat _fileStatbuff;
    int fd = open(fileName, O_RDONLY);
    if (fd == -1)
    {
        _fileSize = -1;        
    }
    else
    {
        if ((fstat(fd, &_fileStatbuff) != 0) || (!S_ISREG(_fileStatbuff.st_mode)))
        {
            _fileSize = -1;
        }
        else
        {
            _fileSize = _fileStatbuff.st_size;
        }
        close(fd);
    }
    return _fileSize;
}

void convertToInt(char *a, size_t lenghtA, int *b, size_t lenghtB)
{

    char * p1, *p2;
    int count = 0;
    while (count != lenghtB)
        b[count++] = strtol(a, &a, 10);
}

void convertToChar(char *a, size_t lenghtA, int *b, size_t lenghtB)
{

}

int
countNumber(char *a, size_t size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if(a[i] == ' ')
            count++;
    }
    return count + 1;
}

int*
getData(const char * path, size_t* lenghtData )
{
    int rez;
    int _sizeFile = getFileSize((path));
    char *_test;

    _test = (char *)malloc(_sizeFile*sizeof(char));
    int fd = open(path, (O_RDONLY));

    int readC = read(fd, _test, _sizeFile);

    *lenghtData= countNumber(_test, _sizeFile);
    int *data = (int*)malloc((*lenghtData)*sizeof(int));     

    convertToInt(_test, _sizeFile, data, (*lenghtData));

    free(_test);
    close(fd);

    return data;
}

void
printMas(const char* nameMas, int* data, size_t lengthMas)
{
    printf("%s: \n", nameMas);
    
    for (int i = 0; i < lengthMas; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");
}

int
main(void)
{
    // int test[10] = {12,54,4,5,9,7,1,0,5,4};
     // для хранения времени выполнения кода
    double time_spent = 0.0;
 
    clock_t begin = clock();

    //для вывода в файл
    int fw = open("test1O.txt", O_WRONLY);
    dup2(fw, 1); 
   
    int* data1;
    int* data2;
    int lengthData1, lengthData2;

    data1 = getData("../Example/sysprog/1/test1.txt", &lengthData1);
    data2 = getData("../Example/sysprog/1/test2.txt", &lengthData2);

    printf("До сортировки \n");
    printMas("data1", data1, lengthData1);
    printMas("data2", data2, lengthData1);
    
    quickSort(data1, 0, (lengthData1 - 1));
    quickSort(data2, 0, (lengthData2 - 1));

    printf("После сортировки \n");

    printMas("data1", data1, lengthData1);
    printMas("data2", data2, lengthData1);

    int* merge12;
    int lengthMerge12 = 0;
    merge12 = merge(data1, lengthData1, data2, lengthData2, &lengthMerge12);

    printf("После слияния \n");

    printMas("data1+data2", merge12, lengthMerge12);

    free(data1);
    free(data2);
    close(fw);

    clock_t end = clock();
    // рассчитать прошедшее время, найдя разницу (end - begin) и
    // деление разницы на CLOCKS_PER_SEC для перевода в секунды
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
        
 

    return 0;
}