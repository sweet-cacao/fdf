
#include "fdf.h"

int main() {
	t_map  *map;

  //  printf("Hello, World!\n");
//   int fd = open("map", O_RDONLY);
 //	printf("%d", fd);

   map = read_map(1);
   printf("data = %d, down = %d, right = %d", map->data, map->down->data, map->right->data);
    return 0;
}
