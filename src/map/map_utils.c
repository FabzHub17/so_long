#include "./../../includes/so_long.h"

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