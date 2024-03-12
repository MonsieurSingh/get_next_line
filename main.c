//
//  main.c
//  get_next_line
//
//  Created by Devjyot Singh on 11/3/2024.
//

#include "get_next_line.h"

int main(int argc, const char * argv[]) {
  int fd;
  char  *line;

  fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    /* line = get_next_line(fd);
    printf("%s", line);
    free(line); */

  /* while ((line = get_next_line(fd)) != NULL)
  {
    printf("%s", line);
    free(line);
  } */
  return (0);
}
