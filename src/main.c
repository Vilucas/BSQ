#include "main.h"
#include "debug.h"
#define READ_PACE 1


bool get_map(char *av, int ***map, t_data *data)
{
    int         fd;
    int         byteRead;
    int         dim;
    char        *line = malloc(sizeof(char) * BUFF_SIZE);
    memset(line, '\0', sizeof(line));

    if ((fd = open(av, O_RDONLY)) < 0)
        return false;
    readNextLine(fd, &line);
    dim = atoi(line);
    *map = malloc(sizeof(int*) * dim + 1);
    data->dim = dim;
    for (int i = 0; i < dim; i++)
    {
        int ret = readNextLine(fd, &line);
        (*map)[i] = malloc(sizeof(int) *dim);
        for (int j = 0; j < dim; j++) {
            (*map)[i][j] = (line[j] == '.' ? 1 : 0);
        }
    }
    return true;
}

int main(int ac, char **av)
{
    int **map;
    t_data data;

    memset(&data, '\0', sizeof(data));


    if (ac != 2 || !av[1] || !av[1][0])
    {
        printf("Usage: ./BSQ <map>");
        return -1;
    }
    get_map(av[1], &map, &data);
    algo(map, data);
    return (0);
}