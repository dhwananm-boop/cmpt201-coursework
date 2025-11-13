/*
Questions to answer at top of client.c:
(You should not need to change the code in client.c)
1. What is the address of the server it is trying to connect to (IP address and
port number).
Ans) Address: 127.0.0.1(defined by ADDR); Port: 8000(defined by PORT)

2. Is it UDP or TCP? How do you know?
Ans) It is TCP because of the sfd = socket(AF_INET, SOCK_STREAM, 0); line which
uses SOCK_STREAM, which specifies a TCP socket.

3. The client is going to send some data to the server. Where does it get this
data from? How can you tell in the code?
Ans) It gets data frin standard input meaning whatever the user types in the
terminal. The code while((num_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 1)
reads frin STDIN_FILENO which is the file descriptor for standard input.

4. How does the client program end? How can you tell that in the code?
Ans) The programs ends when the 'read' call from standard input returns 0 or 1.
It happends when the user signals EOF by pressing CTRL+D on a new line. When it
occurs, the while loop terminates, the code calls close(sfd) and then
exit(EXIT_SUCCESS).
*/
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8000
#define BUF_SIZE 64
#define ADDR "127.0.0.1"

#define handle_error(msg)                                                      \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

int main() {
  struct sockaddr_in addr;
  int sfd;
  ssize_t num_read;
  char buf[BUF_SIZE];

  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd == -1) {
    handle_error("socket");
  }

  memset(&addr, 0, sizeof(struct sockaddr_in));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, ADDR, &addr.sin_addr) <= 0) {
    handle_error("inet_pton");
  }

  int res = connect(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
  if (res == -1) {
    handle_error("connect");
  }

  while ((num_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 1) {
    if (write(sfd, buf, num_read) != num_read) {
      handle_error("write");
    }
    printf("Just sent %zd bytes.\n", num_read);
  }

  if (num_read == -1) {
    handle_error("read");
  }

  close(sfd);
  exit(EXIT_SUCCESS);
}
