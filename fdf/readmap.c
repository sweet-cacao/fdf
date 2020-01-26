#include "fdf.h"

t_map 		*get_down(t_map *map)
{
	if (map == NULL)
		return NULL;
	while (map->down)
		map = map->down;
	return map;
}

t_map 		*get_right(t_map *map)
{
	if (map == NULL)
		return NULL;
	while (map->right)
		map = map->right;
	return map;
}

t_map		*add_block(int data)
{
	t_map	*tmp;

	tmp = (t_map*) malloc(sizeof(t_map));
	tmp->data = data;
	tmp->down = NULL;
	tmp->right = NULL;
	return tmp;
}

void		push_down(t_map *map, int data)
{
	t_map	*last;
	t_map	*tmp;

	last = get_down(map);
	tmp = add_block(data);
	last->down = tmp;
}

void		push_right(t_map *map, int data)
{
	t_map	*last;
	t_map	*tmp;

	last = get_right(map);
	tmp = add_block(data);
	last->right = tmp;
}

int		get_number(char **str)
{
	int		num;

	num = atoi(*str);
	while(**str != ' ')
		**str++;
	**str++;
	return num;
}

void	fill_map(char *line, t_map *map)
{
	char	*buff;

	if (map != NULL)
		map = get_down(map);
	if (map == NULL)
		map = add_block(get_number(&line));
	while(*line != '\n')
		push_right(map, get_number(&line));
}

void	connect_map(t_map *map)
{
	t_map *head;
	t_map *tmp;

	tmp = map;
	while(tmp->down)
	{
		head = tmp;
		while (head->right->right)
		{
			head->right->down = head->down->right;
			head = head->right;
		}
		tmp = tmp->down;
	}
}

t_map *read_map(int fd)
{
	char	*line;
	char 	*massive[3];
	int i;

	i = 0;
	t_map	*map;
	map = (t_map*) malloc(sizeof(t_map));
	while (i < 4)
	{
		massive[i] = malloc(10000);
		i++;
	}
	massive[0] = "1 2 3 4\n";
	massive[1] = "5 6 7 8\n";
	massive[2] = "9 10 11 12\n";
	line = malloc(1000000);//может здесь имеет смысл посчитать ширину карты?
	i = 0;
	while(i < 4)
	{
		line = massive[i];
		printf ("%s", line);
		fill_map(line, map);
		i++;
	}
	connect_map(map);
	return map;
}

