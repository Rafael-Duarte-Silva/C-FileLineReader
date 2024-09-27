#include "../include/fileLineReader.h"

int searchLineBreak(FILE *file, const int FILE_LENGTH, const int START_LINE)
{
    const int LINE_BREAK = (int)'\n';
    int lineLengthCounter = 0;
    char currentCharacter;

    while (START_LINE + lineLengthCounter < FILE_LENGTH)
    {
        fseek(file, START_LINE + lineLengthCounter, SEEK_SET);

        currentCharacter = fgetc(file);

        if (currentCharacter == LINE_BREAK)
        {
            break;
        }

        lineLengthCounter++;
    }

    fseek(file, START_LINE, SEEK_SET);

    return lineLengthCounter;
}

int searchFileLength(FILE *file, const int START_LINE)
{
    int fileLength;

    if (START_LINE == 0)
    {
        fseek(file, START_LINE, SEEK_END);
        fileLength = ftell(file);
        fseek(file, START_LINE, SEEK_SET);
    }

    return fileLength;
}

void *fileLineReader(FILE *file)
{
    static int startLine = 0;
    static int fileLength = 0;
    fileLength = searchFileLength(file, startLine);

    if (file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }
    if (startLine >= fileLength)
    {
        return NULL;
    }

    const int LINE_LENGTH = searchLineBreak(file, fileLength, startLine);

    char *result = calloc(LINE_LENGTH + 1, sizeof(char));
    fgets(result, LINE_LENGTH + 1, file);

    startLine += LINE_LENGTH + 1;

    return (void *)result;
}