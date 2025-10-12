#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HISTORY_SIZE 5

void add_to_history(char *history[], int *next_entry_index, char *new_line) {
  if (history[*next_entry_index] != NULL) {
    free(history[*next_entry_index]);
  }

  history[*next_entry_index] = new_line;

  *next_entry_index = (*next_entry_index + 1) % HISTORY_SIZE;
}

void print_history(const char *history[], int next_entry_index) {
  for (int i = 0; i < HISTORY_SIZE; i++) {
    int print_index = (next_entry_index + i) % HISTORY_SIZE;

    if (history[print_index] != NULL) {
      printf("%s\n", history[print_index]);
    }
  }
}

void free_all_history(char *history[]) {
  for (int i = 0; i < HISTORY_SIZE; i++) {
    if (history[i] != NULL) {
      free(history[i]);
      history[i] = NULL;
    }
  }
}

int main() {
  char *history[HISTORY_SIZE] = {NULL};

  int next_entry_index = 0;

  char *line_buffer = NULL;
  size_t buffer_size = 0;
  ssize_t chars_read;

  while (1) {
    printf("Enter input: ");

    chars_read = getline(&line_buffer, &buffer_size, stdin);

    if (chars_read == -1) {
      break;
    }

    char *current_input = line_buffer;
    line_buffer = NULL;
    buffer_size = 0;

    if (chars_read > 0 && current_input[chars_read - 1] == '\n') {
      current_input[chars_read - 1] = '\0';
    }

    add_to_history(history, &next_entry_index, current_input);

    if (strcmp(current_input, "print") == 0) {
      print_history((const char **)history, next_entry_index);
    }
  }

  printf("\nExiting program. \n");

  free(line_buffer);
  free_all_history(history);

  return 0;
}
