#ifndef FDF_FDF_H
#define FDF_FDF_H
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../gnl/get_next_line.h"
#include <stdio.h>

typedef struct      s_map
{
    int             data;
	struct s_map 	*right;
	struct s_map    *down;
}                   t_map;

t_map *read_map(int fd);

#endif
