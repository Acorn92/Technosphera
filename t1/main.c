#include "quickSort.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <malloc.h>

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

int
main(void)
{
    // int test[10] = {12,54,4,5,9,7,1,0,5,4};

    int _sizeFile = getFileSize("../Example/sysprog/1/test1.txt");

    char *_test;

    _test = (char *)malloc(_sizeFile*sizeof(char));
    int fd = open("../Example/sysprog/1/test1.txt", (O_RDONLY));

    int readC = read(fd, _test, _sizeFile);

    printf("До сортировки \n");

    for (int i = 0; i < _sizeFile; i++)
        printf("%c", _test[i]);

    // quickSort(_test, 0, _sizeFile);

    // printf("После сортировки \n");
    // for (int i = 0; i < _sizeFile; i++)
    //     printf("%c", _test[i]);

    //настроить отладку
}