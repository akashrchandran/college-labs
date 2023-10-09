#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdlib.h>
main(int argc, char *argv[])
{
    int i, j, n;
    int sock_fd, max_fd, nready, fd[2];
    char buffer[100], line[100];
    struct sockaddr_in servaddr;
    fd_set rset;
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./client IPaddress_of_server port\n");
        exit(1);
    }
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Cannot create socket\n");
        exit(1);
    }
    bzero((char *)&servaddr, sizeof(servaddr));
    bzero(line, sizeof(line));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    if (connect(sock_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Connection failed:");
        exit(1);
    }
    fd[0] = 0;
    fd[1] = sock_fd;
    for (;;)
    {
        FD_ZERO(&rset);
        FD_SET(0, &rset);
        FD_SET(sock_fd, &rset);
        bzero(line, sizeof(line));
        max_fd = sock_fd;
        nready = select(max_fd + 1, &rset, NULL, NULL, NULL);
        for (j = 0; j < 2; j++)
        {
            if (FD_ISSET(fd[j], &rset))
            {
                n = read(fd[j], line, sizeof(line));
                if (j == 0)
                {
                    n = write(fd[j + 1], line, strlen(line));
                }
                else
                {
                    printf("%s \n", line);
                }
                if (--nready == 0)
                    break;
            }
        }
    }
}
