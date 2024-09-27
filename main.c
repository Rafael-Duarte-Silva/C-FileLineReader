#include <stdlib.h>
#include <stdio.h>
#include "include/fileLineReader.h"

int main()
{
    FILE *file = fopen("test.txt", "r");

    char *line;

    while ((line = (char *)fileLineReader(file)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    fclose(file);

    return 0;
}