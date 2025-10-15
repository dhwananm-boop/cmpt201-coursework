#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("Hello. This P1\n");
  fork();
  execlp("echo", "echo", "Hello", "World!", (char *)NULL);

  char *args[] = {"/bin/echo", "World", "Hello", NULL};
  execv("/bin/echo",
        args); // Does not run because of the execlp before this line

  execl("/bin/echo", "/bin/echo", "Yes!", "No!",
        (char *)NULL);                     // Does not get executed because of
                                           // the execv before this line.
  printf("This might not get executed\n"); // Does not get executed because of
                                           // the execv before this line.
}
