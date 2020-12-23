#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>
#define MAXSIZE 50

bool check(char *buff) {
	return buff[0] == 'H' && buff[1] == 'a' && buff[2] == 'l' && buff[3] == 't';
}

int main()
{
	int sockfd, retval;
	char buff[MAXSIZE];
	int recedbytes, sentbytes;
	struct sockaddr_in serveraddr, clientaddr;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
	if (sockfd == -1)
	{
		printf("\nSocket Creation Error");
		return 0;
	}
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(3388); 
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 

	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(3389);
	clientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	retval = bind(sockfd, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
	if (retval == 1)
	{
		printf("Binding error");
		close(sockfd);
	}

while (1)
{
	printf("Enter a string: ");
	scanf("%s", buff);

	sentbytes = sendto(sockfd, buff, sizeof(buff), 0,
		(struct sockaddr *)&serveraddr, sizeof(serveraddr));

	if (sentbytes == -1)
	{
		printf("sending error");
		close(sockfd);
	}

	if (check(buff))
	{
		break;
	}
	socklen_t size = sizeof(serveraddr);
	recedbytes = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&serveraddr, &size);
	puts(buff);
	printf("\n");

	if (check(buff)) {
		break;
	}
}
close(sockfd);
}
