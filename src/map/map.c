#include "./../../includes/so_long.h"

static char **append_line(char **tmp_array, char *line, int count)
{
    char    **new_tmp_array;
    int     i;

    i = 0;
    new_tmp_array = malloc(sizeof(char *) * (count + 2)); // char * ??
    if(!new_tmp_array)
        return(NULL);
    while(i < count)
    {
        new_tmp_array[i] = tmp_array[i];
        i++;
    }
    new_tmp_array[count] = line;
    new_tmp_array[count + 1] = NULL;
    free(tmp_array);
    return(new_tmp_array);
}

static char **read_file(int fd)
{
    char    *line;
    char    **tmp_array;
    int     count;
    int     len;

    tmp_array = NULL;
    count = 0;
    len = 0;
    line = get_next_line(fd);
    while(line)
    {
        len = ft_strlen(line);
        if( len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        tmp_array = append_line(tmp_array, line, count);
        if(!tmp_array)
            return(NULL);
        count++;
        line = get_next_line(fd);
    }
    return(tmp_array);
}

static void count_elements(t_map *map)
{
    int x;
    int y;

    y = 0;
    while( y < map->height)
    {
        x = 0;
        while(x < map->width)
        {
            if(map->grid[y][x] == PLAYER)
                map->players++;
            else if(map->grid[y][x] == EXIT)
                map->exits++;
            else if(map->grid[y][x] == COLLECTIBLE)
                map->collectibles++;
            x++;
        }
        y++;
    }
}

t_map *load_map(char *file)
{
    int     fd;
    char    **tmp_array;
    t_map   *map;
    
    tmp_array = NULL;

    fd = open(file, O_RDONLY);
    if(fd < 0)
        return(NULL);
    tmp_array = read_file(fd);
    close(fd);
    if(!tmp_array)
        return(NULL);
    
    map = malloc(sizeof(t_map));
    if(!map)
        return(free_str_array(tmp_array), NULL);
    *map = (t_map){
        .grid = tmp_array,
        .height = 0,
        .width = 0,
        .players = 0,
        .exits = 0,
        .collectibles = 0
    };
    while(tmp_array[map->height])
        map->height++;    
    map->width = ft_strlen(tmp_array[0]); // dopo in validate_map() verrà effetivamente controllato il resto
    count_elements(map);
    return(map);
}