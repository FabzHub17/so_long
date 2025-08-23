#include "../includes/so_long.h"

int print_error(char *msg)
{
    write(2, "Error\n", 6);
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    return (0);
}