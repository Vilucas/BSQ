#include "main.h"

bool printMap(int **map, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (j < dim - 1)
                printf("%d - ", map[i][j]);
            else
                printf("%d\n", map[i][j]);
        }
    }
}