#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

int readNextLine(int fd, char **line)
{
    static char *tmp;
    char buffer[BUFF_SIZE + 1] = {0};
    char *completeBuffer = NULL;
    char *tmpBuffer = NULL;
    int a;

    if (tmp && tmp[0] && (tmpBuffer = strchr(tmp, '\n')) != NULL)
    {
        completeBuffer = malloc(sizeof(char) * strlen(tmp) - strlen(tmpBuffer + 1));
        completeBuffer = strncpy(completeBuffer, tmp, strlen(tmp) - strlen(tmpBuffer) + 1);
        completeBuffer[strlen(tmp) - strlen(tmpBuffer + 1)] = '\0';
        *line = completeBuffer;
        tmpBuffer = strdup(tmp + strlen(completeBuffer) + 1);
        if (tmp)
            free(tmp);
        tmp = NULL;
        tmp = tmpBuffer;
        return 1;
    }
    
    if (tmp && tmp[0])
    {
        completeBuffer = strdup(tmp);
        free(tmp);
        tmp = NULL;
    }
    while ((a = read(fd, buffer, BUFF_SIZE)) > 0)
    {
        char *ptr;
        buffer[a] = '\0';

        if (completeBuffer)
        {
            //printf("hre2 = %s\n", completeBuffer);

            tmpBuffer = strdup(completeBuffer);
            free(completeBuffer);
            completeBuffer = malloc(sizeof(char) * strlen(buffer) + strlen(tmpBuffer) + 1);
            //printf("%d\n", completeBuffer);
            memset(completeBuffer, '\0',strlen(buffer) + strlen(tmpBuffer) + 1);
            strcat(completeBuffer, tmpBuffer);
            strcat(completeBuffer, buffer);
          //  printf("hre33 = %s\n", completeBuffer);
            free(tmpBuffer);
        }
        else {
            completeBuffer = strdup(buffer);
        }
        if ((ptr = strchr(completeBuffer, '\n')))
        {
            char *tmpBuffer = malloc(sizeof(char) * strlen(completeBuffer) - strlen(ptr + 1) + 1);
  
            tmpBuffer = strncpy(tmpBuffer, completeBuffer, strlen(completeBuffer) - strlen(ptr + 1));
            tmpBuffer[strlen(completeBuffer) - strlen(ptr + 1)] = '\0';
            //it doens't null terminate itself 
            tmp = strdup(completeBuffer + strlen(tmpBuffer) + 1);
            free(completeBuffer);

            *line = tmpBuffer;
            return 1;
        }
    }
    if (completeBuffer)
    {
        tmpBuffer = malloc(sizeof(char) * strlen(buffer) + strlen(completeBuffer) + 1);
        strcat(tmpBuffer, completeBuffer);
        strcat(tmpBuffer, buffer);
        free(completeBuffer);
        completeBuffer = tmpBuffer;
    }
    *line = NULL;
    return (0);
}
