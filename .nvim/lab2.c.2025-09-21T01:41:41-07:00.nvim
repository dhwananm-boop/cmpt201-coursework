#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  char *line_buffer = NULL;
  size_t buffer_size = 0;
  ssize_t line_length;

  printf("Enter programs to run.\n");

  for (;;) {
    printf("> ");
    fflush(stdout);

    line_length = getline(&line_buffer, &buffer_size, stdin);

    if (line_length == -1) {
      printf("Exiting\n");
      break;
    }

    if (line_length > 0 && line_buffer[line_length - 1] == '\n') {
      line_buffer[line_length - 1] = '\0';
    }

    if (strlen(line_buffer) == 0) {
      continue;
    }

    pid_t pid = fork();

    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    }

    else if (pid == 0) {
      execl(line_buffer, line_buffer, (char *)NULL);

      perror("Exec failure");
      exit(EXIT_FAILURE);
    }

    else {
      int status;

      waitpid(pid, &status, 0);
    }
  }
  free(line_buffer);
  return 0;
}
