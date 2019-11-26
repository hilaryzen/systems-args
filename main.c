#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **parse_args(char *line) {
  char **args;
  char *s;
  s = strsep(&line, " ");
  printf("%s", s);
  return args;
}

int main() {
  char path[100];
  printf("Enter a command: ");
  fgets(path, 100, stdin);
  if (strchr(path, '\n') != NULL) {
    *(strchr(path, '\n')) = '\0';
  }

  return 0;
}
