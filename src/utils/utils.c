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

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)ptr;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}