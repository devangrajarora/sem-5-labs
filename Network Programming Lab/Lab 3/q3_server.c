#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#define PORT 8000

int main()
{
	int s, r, recb, sntb, x, ns, a = 0;

	socklen_t len;
	struct sockaddr_in server, client;
	char buff[50], buff2[50];
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == -1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nSocket created.");
//port number for communication
//socket creation
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	r = bind(s, (struct sockaddr *)&server, sizeof(server));
	if (r == -1)
	{
//socket binding
		printf("\nBinding error.");
		exit(0);
	}
	printf("\nSocket binded.");
	r = listen(s, 1);
	if (r == -1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket listening.");
	len = sizeof(client);
	ns = accept(s, (struct sockaddr *)&client, &len);
//socket accepting
	if (ns == -1)
	{
		close(s);
		exit(0);
	}
	printf("\nSocket accepting.\n");
	recb = recv(ns, buff, sizeof(buff), 0);
	if (recb == -1)
	{
		printf("\nMessage receiving failed.");
		close(s);
		close(ns);
		exit(0);
	}
	printf("\nMessage Received: ");
	printf("%s\n", buff);
	int pid = fork();
	if (pid > 0)
	{
//parent process
		char num[50] = {0}, alpha[50] = {0};
		int i, j, k;
		i = 0;
		j = 0;
		k = 0;
		int n = strlen(buff);
		for (i = 0; i < n; i++)
		{
			if ((buff[i] >= 65 && buff[i] <= 91) || (buff[i] >= 97 && buff[i] <= 123))
			{
				alpha[j] = buff[i];
				j++;
			}
			else
			{
				num[k] = buff[i];
				k++;
			}
		}
		alpha[j] = '\0';
		num[k] = '\0';
		for (i = 0; i < j - 1; i++)
		{
			for (int x = 0; x < j - i - 1; x++)
			{
				if (alpha[x] < alpha[x + 1])
				{
					char temp = alpha[x];
					alpha[x] = alpha[x + 1];
					alpha[x + 1] = temp;
				}
			}
		}
		printf("\nSorted in descending order: %s \nby parent process with PID: %d:", alpha, pid);
		printf("\n\n");
	}
	else
	{
		char num[50] = {0}, alpha[50] = {0};
		int i, j, k;
		i = 0;
		j = 0;
		k = 0;
		int n = strlen(buff);
		for (i = 0; i < n; i++)
		{
			if ((buff[i] >= 65 && buff[i] <= 91) || (buff[i] >= 97 && buff[i] <= 123))
			{
				alpha[j] = buff[i];
				j++;
			}
			else
			{
				num[k] = buff[i];
				k++;
			}
		}
		alpha[j] = '\0';
		num[k] = '\0';
		for (i = 0; i < k - 1; i++)
		{
			for (int x = 0; x < k - i - 1; x++)
			{
				if (num[x] > num[x + 1])
				{
					char temp = num[x];
					num[x] = num[x + 1];
					num[x + 1] = temp;
				}
			}
		}
		printf("\nSorted in ascending order: %s \nby child process with PID %d:", num, pid);

	}
	close(ns);
	close(s);
}
