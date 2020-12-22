#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int s, r, recb, data;
	struct sockaddr_in server;
	char buff[50];
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == -1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(5000);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	r = connect(s, (struct sockaddr *)&server, sizeof(server));
	if (r == -1)
	{
		printf("\nConnection error.");
		exit(0);
	}

	printf("\n\n");
	printf("Input File Name: ");
	scanf("%s", buff);

	data = send(s, buff, sizeof(buff), 0);
	if (data == -1) {
		close(s);
		printf("\nMessage Sending Failed");
		exit(0);
	}
	recb = recv(s, buff, sizeof(buff), 0);
	if (recb == -1) {
		printf("\nMessage Recieving Failed");
		close(s);
		exit(0);
	}

	printf("\n");
	printf("%s", buff);
	printf("\n\n");
	if (strcmp(buff, "File not present!") == 0)
	{
		close(s);
		exit(0);
	}
	int ch = 0;
	printf("\n1.Search\n2.Replace\n3.Reorder\n4.Exit\nEnter your choice: ");

	while (ch != 4)
	{
		scanf("%d", &ch);
		buff[0] = ch;
		char str1[50], str2[50];
		int n, i, j;
		switch (ch)
		{
			case 1:
			printf("\nEnter string to be searched: ");
			scanf("%s", str1);
			n = strlen(str1);
			buff[1] = n;
			for (i = 0; i < n; i++)
				buff[i + 2] = str1[i];
			buff[i + 2] = '\0';
			data = send(s, buff, sizeof(buff), 0);
			if (data == -1)
			{
				close(s);
				printf("\nMessage Sending Failed");
				exit(0);
			}
			recb = recv(s, buff, sizeof(buff), 0);
			if (recb == -1)
			{
				printf("\nMessage Recieving Failed");
				close(s);
				exit(0);
			}
			n = buff[0];
			printf("\n%s found %d number of times\n", str1, n);
			break;
			case 2:
			printf("\nEnter string to be searched and replaced: ");
			scanf("%s", str1);
			n = strlen(str1);
			buff[1] = n;
			for (i = 0; i < n; i++)
				buff[i + 2] = str1[i];
			buff[i + 2] = '\0';
			data = send(s, buff, sizeof(buff), 0);
			if (data == -1)
			{
				close(s);
				printf("Message Sending Failed");
				exit(0);
			}
			printf("Enter new string: ");
			scanf("%s", str2);
			n = strlen(str2);
			buff[1] = n;
			i = 2;
			for (j = 0; j < n; j++)
			{
				buff[i] = str2[j];
				i++;
			}
			buff[i] = '\0';
			data = send(s, buff, sizeof(buff), 0);
			if (data == -1)
			{
				close(s);
				printf("\nMessage Sending Failed");
				exit(0);
			}
			recb = recv(s, buff, sizeof(buff), 0);
			if (recb == -1)
			{
				printf("\nMessage Recieving Failed");
				close(s);
				exit(0);
			}
			printf("%s\n", buff);
			break;
			case 3:
			data = send(s, buff, sizeof(buff), 0);
			if (data == -1)
			{
				close(s);
				printf("\nMessage Sending Failed");
				exit(0);
			}
			recb = recv(s, buff, sizeof(buff), 0);
			if (recb == -1)
			{
				printf("\nMessage Recieving Failed");
				close(s);
				exit(0);
			}
			printf("%s\n", buff);
			break;
			case 4:
			data = send(s, buff, sizeof(buff), 0);
			if (data == -1)
			{
				close(s);
				printf("\nMessage Sending Failed");
				exit(0);
			}
			break;
		}
	}
	close(s);
}
