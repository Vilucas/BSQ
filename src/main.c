#include "main.h"
#include "get_next_line.h"
#include "debug.h"
#define READ_PACE 1


bool get_map(char *av, int ***map)
{
    int         fd;
    int         byteRead;
    int         dim;
    char        *line;

    if ((fd = open(av, O_RDONLY)) < 0)
        return false;
    get_next_line(fd, &line);
    dim = atoi(line);
    *map = malloc(sizeof(int*) * dim + 1);

    for (int i = 0; i < dim; i++)
    {
        get_next_line(fd, &line);
        printf("%s\n", line);
        (*map)[i] = malloc(sizeof(int) *dim);
        for (int j = 0; j < dim; j++) {
            (*map)[i][j] = (line[j] == '.' ? 1 : 0);
        }
    }
    printMap(*map, dim);
    printf("%d\n%s\n", dim, line);
}

int main(int ac, char **av)
{
    int **map;
    if (ac != 2 || !av[1] || !av[1][0])
        return -1;
    get_map(av[1], &map);
    return (0);
}