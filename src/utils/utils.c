#include "../../includes/so_long.h"

int print_error(char *msg)
{
    write(2, "Error\n", 6);
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    return (0);
}

// Libera un NULL- terminated array di stringhe 
void free_str_array(char **arr)
{
    int i;

    if(!arr)
        return;
    i = 0;
    while(arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_map(t_map *map)
{
    if(!map)
        return;
    if(map->grid)
        free_str_array(map->grid);
    free(map);
}