#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Copy file name or destination folder not specified!\n");
        printf("Use Process1 'filename' 'destination'\n");
        return -1;
    }

    char command[1024];
    snprintf(command, 1024, "cp %s %s", argv[1], argv[2]);
    printf("Coping with %s\n", command);
    if (!system(command))
    {
        printf("Success!\n");
        exit(0);
    }
    else
    {
        printf("Failed!\n");
        exit(-1);
    }
}
