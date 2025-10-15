#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("Start PID = %d; Parent PID: %d\n", getpid(), getppid());

  pid_t pid = fork();

  if (pid == 0) {
    printf("CHILD: PID = %d, Parent PID = %d\n", getpid(), getppid());
  } else {
    printf("PARENT: PID = %d, Child PID = %d\n", getpid(), pid);
  }

  return 0;
}
