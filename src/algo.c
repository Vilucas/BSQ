#include "main.h"
#include <math.h>
#include <debug.h>

bool printSquare(int **map, t_data data)
{
    int x = data.x - data.size + 1;
    int y = data.y - data.size + 1;
    
    if (DEBUG)
        printf("Original x- y = %d, %d\nfinal x - y = %d, %d\n", data.x, data.y, x, y);
    for (int i = 0; i < data.dim; i++)
    {
        for (int j = 0; j < data.dim; j++)
        {
            if (i >= x && i < x + data.size && j >= y && j < y + data.size)
                printf("x");
            else if (map[i][j] > 0)
                printf(".");
            else
                printf("o");
            if (j == data.dim - 1)
                printf("\n");
        }
    }
}

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
                if (DEBUG)
                    printf("i = %d, j = %d, surroundings = %d - %d - %d", i, j,map[i - 1][j], map[i][j - 1], map[i-1][j-1]);
                map[i][j] = (int)(fmin(fmin(map[i - 1][j], map[i][j - 1]), map[i-1][j-1]) + 1);
                if (DEBUG)
                    printf("result is -> %d\n", map[i][j]);
                if (map[i][j] > max)
                {
                    max = map[i][j];
                    data.x = i;
                    data.y = j;
                }
            }
        }
    }
    if (DEBUG_EXTENDED)
    {
        printf("%d - %d - %d", data.y - data.size + 1, data.x - data.size + 1);
    }
    data.size = max;
    printSquare(map, data);
}