#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_data 
{
    int size;
    int x; 
    int y;
    int dim;
}           t_data;
#define BUFF_SIZE 512
#define DEBUG_EXTENDED 1
bool algo(int **map, t_data data);
int readNextLine(int fd, char **line);
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#endif