#include "quickSort.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h> 

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
    while (count != (lenghtB - 1))
        b[count++] = strtol(a, &a, 10);


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

int
main(void)
{
    // int test[10] = {12,54,4,5,9,7,1,0,5,4};

    int _sizeFile = getFileSize("../Example/sysprog/1/test1.txt");

    char *_test;

    _test = (char *)malloc(_sizeFile*sizeof(char));
    int fd = open("../Example/sysprog/1/test1.txt", (O_RDONLY));

    int readC = read(fd, _test, _sizeFile);

    int numbers = countNumber(_test, _sizeFile);
    int *_data = (int*)malloc(numbers*sizeof(int));

    convertToInt(_test, _sizeFile, _data, numbers);

   
    //измерить скорость работы программы

    // printf("До сортировки \n");
    
    // for (int i = 0; i < _sizeFile; i++)
    //     printf("%c", _test[i]);

    quickSort(_data, 0, numbers);

    // printf("После сортировки \n");
    for (int i = 0; i < numbers; i++)
        printf("%d", _data[i]);
        
    free(_test);
    free(_data);

    return 0;
}