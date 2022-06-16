#include "main.h"
#include <math.h>
#include <debug.h>
bool algo(int **map, t_data data)
{
    int max = 0;
    //start to 1 because we know that the edges can't be the start of a square bigger than 0 - 1
    for (int i = 1; i < data.dim; i++)
    {
        for (int j = 1; j < data.dim; j++)
        {
            if (map[i][j] != 0)
            {
                printf("i = %d, j = %d, surroundings = %d - %d - %d", i, j,map[i - 1][j], map[i][j - 1], map[i-1][j-1]);
                map[i][j] = (int)(fmin(fmin(map[i - 1][j], map[i][j - 1]), map[i-1][j-1]) + 1);
                printf("result is -> %d\n", map[i][j]);
            }
        }
    }
    printMap(map, data.dim);
}