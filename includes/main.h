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

bool algo(int **map, t_data data);

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#endif