#include "quickSort.h"
#include "mergeSort.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>    
#include "../Example/sysprog/1/libcoro.h"

struct
{
    char*name;
    int *data;
    size_t dataSize;
}typedef dataFile;

int 
getFileSize(const char *fileName)
{
    printf("entered function, getFileSize, with FileName = %s\n", fileName);
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

void 
convertToInt(char *a, size_t lenghtA, int *b, size_t lenghtB)
{
    printf("entered function, convertToInt\n");
    char * p1, *p2;
    int count = 0;    
    while (count < lenghtB)
    {
        b[count] = strtol(a, &a, 10);        
        count++;
        coro_yield();
    }
}

void 
convertToChar(char *a, size_t lenghtA, int *b, size_t lenghtB)
{

}

int
countNumber(char *a, size_t size)
{
    printf("entered function, countNumber\n");
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if(a[i] == ' ')
            count++;
        coro_yield();
    }
    return count + 1;
}

int*
getData(const char * path, size_t lenghtData )
{
    FILE *fd = fopen(path, "rt");
    int *data = (int*)malloc(lenghtData*sizeof(int));    
    int dat;
    char *v;
    int countData = 0;
    while (fscanf(fd, "%d", &data[countData]) == 1)
        countData++;      
    return data;
}

void
printMas(const char* nameMas, int* data, size_t lengthMas)
{
    printf("entered function, printMas: %s\n", nameMas);
    printf("%s: \n", nameMas);
    
    for (int i = 0; i < lengthMas; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");
}

void
printMasLong(const char* nameMas, long int* data, size_t lengthMas)
{
    printf("entered function, printMas: %s\n", nameMas);
    printf("%s: \n", nameMas);
    
    for (int i = 0; i < lengthMas; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");
}

/**
 * Coroutine body. This code is executed by all the coroutines. Here you
 * implement your solution, sort each individual file.
 */
static int
coroutine_func_f(void *context)
{
	/* IMPLEMENT SORTING OF INDIVIDUAL FILES HERE. */
    char *name = ((dataFile*)context)->name;
    ((dataFile*)context)->data = getData(((dataFile*)context)->name, &(((dataFile*)context)->dataSize));

	struct coro *this = coro_this();
	
	printf("Started coroutine %s\n", name);
	printf("%s: switch count %lld\n", name, coro_switch_count(this));
	printf("%s: yield\n", name);
    printf("До сортировки %s\n", name);
    printMas("data", ((dataFile*)context)->data , ((dataFile*)context)->dataSize);
	coro_yield();    

	printf("%s: switch count %lld\n", name, coro_switch_count(this));
	printf("%s: yield\n", name);
    quickSort(((dataFile*)context)->data , 0, (((dataFile*)context)->dataSize - 1));
	coro_yield();

	printf("%s: switch count %lld\n", name, coro_switch_count(this));
	//other_function(name, 1);
	printf("%s: switch count after other function %lld\n", name,
	       coro_switch_count(this));
    printf("После сортировки %s\n", name);
    printMas("data", ((dataFile*)context)->data, ((dataFile*)context)->dataSize);
	// free(name);
	/* This will be returned from coro_status(). */
	return 0;
}

void testStruct(void *dat)
{
    char *name = ((dataFile*)dat)->name;
    ((dataFile*)dat)->dataSize = 10000;
    ((dataFile*)dat)->data = getData(((dataFile*)dat)->name, ((dataFile*)dat)->dataSize);
    // printMas("data", ((dataFile*)dat)->data , ((dataFile*)dat)->dataSize);
    quickSort(((dataFile*)dat)->data , 0, (((dataFile*)dat)->dataSize - 1));
    printf("После сортировки %s\n", name);
    printMas("data", ((dataFile*)dat)->data, ((dataFile*)dat)->dataSize);
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
   
    
    // int* data2;
    // size_t lengthData1, lengthData2;

    
    // data2 = getData("../Example/sysprog/1/test2.txt", &lengthData2);

    
    
    // printMas("data2", data2, lengthData2);
    
   
    // quickSort(data2, 0, (lengthData2 - 1));

    

    
    // printMas("data2", data2, lengthData2);

    /* Initialize our coroutine global cooperative scheduler. */
	coro_sched_init();
    dataFile file1, file2, file3, file4, file5;
    file1.name = "../Example/sysprog/1/test1.txt";
    file2.name = "../Example/sysprog/1/test2.txt";
    file3.name = "../Example/sysprog/1/test3.txt";
    file4.name = "../Example/sysprog/1/test4.txt";
    file5.name = "../Example/sysprog/1/test5.txt";
    // coro_new(coroutine_func_f, &file1);
    // coro_new(coroutine_func_f, &file2);
    // coro_new(coroutine_func_f, &file3);
    // coro_new(coroutine_func_f, &file4);
    // coro_new(coroutine_func_f, &file5);


    // struct coro *c;
	// while ((c = coro_sched_wait()) != NULL) {
	// 	/*
	// 	 * Each 'wait' returns a finished coroutine with which you can
	// 	 * do anything you want. Like check its exit status, for
	// 	 * example. Don't forget to free the coroutine afterwards.
	// 	 */
	// 	printf("Finished %d\n", coro_status(c));
	// 	coro_delete(c);
	// }
    
    testStruct(&file1);
    testStruct(&file2);
    testStruct(&file3);
    testStruct(&file4);
    testStruct(&file5);

    size_t lengthMerge12 = file1.dataSize + file2.dataSize;
    int* merge12 = (int*)malloc(lengthMerge12 * sizeof(int));    
    merge(file1.data, file1.dataSize, file2.data, file2.dataSize, merge12, lengthMerge12);
    printf("После слияния \n");   
    printf("размер file1+file2: %d\n", lengthMerge12);
    printMas("file1+file2", merge12, lengthMerge12);

    size_t lengthMerge123 = lengthMerge12 + file3.dataSize;  
    int *merge123 = (int*)malloc(lengthMerge123 * sizeof(int));      
    merge(merge12, lengthMerge12, file3.data, file3.dataSize, merge123, lengthMerge123);     
    printf("размер file1+file2+file3: %d\n", lengthMerge123);
    printMas("file1+file2+file3", merge123, lengthMerge123);

    size_t lengthMerge45 = file4.dataSize + file5.dataSize;
    int* merge45 = (int*)malloc(lengthMerge45 * sizeof(int));    
    merge(file4.data, file4.dataSize, file5.data, file5.dataSize, merge45, lengthMerge45);
    printf("размер file4+file5: %d\n", lengthMerge45);
    printMas("file4+file5", merge45, lengthMerge45);

    size_t lengthMerge12345 = lengthMerge123 + lengthMerge45;
    int* merge12345 = (int*)malloc(lengthMerge12345 * sizeof(int));    
    merge(merge123, lengthMerge123, merge45, lengthMerge45, merge12345, lengthMerge12345);
    printf("размер file1+file2+file3+file4+file5 %d\n", lengthMerge12345);
    printMas("file1+file2+file3+file5+file5", merge12345, lengthMerge12345);


    // free(data1);
    // free(data2);
    close(fw);

    //ещё раз проверить сортировку слиянием - последние значения и поведение при сортировке фалов разного 
    //размера

    clock_t end = clock();
    // рассчитать прошедшее время, найдя разницу (end - begin) и
    // деление разницы на CLOCKS_PER_SEC для перевода в секунды
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
        
 

    return 0;
}