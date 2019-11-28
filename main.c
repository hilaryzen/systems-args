#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **parse_args(char *line);

char **parse_args(char *line) {
  char **args = malloc(5 * sizeof(char *));
  char *s = line;
  /*
  s = strsep(&line, " ");
  printf("%s\n", s);
  printf("%s\n", line);
  */
  int i = 0;
  while (*s != '\0') {
    args[i] = strsep(&s, " \t\n");
    //printf("%s\n", args[i]);
    i++;
  }
  args[i] = NULL;
  return args;
}

int main() {
  char line[100];
  printf("Enter a command: ");
  fgets(line, 100, stdin);
  /*
  if (strchr(line, '\n') != NULL) {
    *(strchr(line, '\n')) = '\0';
  }
  */
  //printf("Starting\n");
  char ** args = parse_args(line);
  //printf("Executing\n");
  execvp(args[0], args);
  //printf("Freeing\n");
  free(args);

  return 0;
}
