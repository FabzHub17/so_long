#include "./../../includes/so_long.h"

t_map *load_map(char *file)
{
    int     fd;
    
    fd = open(file, O_RDONLY)
    if(fd < 0)
        return(NULL);
}