#ifndef FILE_LINE_READER_H
#define FILE_LINE_READER_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void *fileLineReader(FILE *file);

#endif