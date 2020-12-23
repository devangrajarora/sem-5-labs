#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 1024

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

char * toChar(int number)
{
    int n = floor(log10(number)) + 1;
    int i;
    char *numberArray = (char*)calloc(n, sizeof(char));
    for (i = n-1; i >= 0; --i, number /= 10)
    {
        numberArray[i] = (number % 10) + '0';
    }
    return numberArray;
}

int i;

int linearSearch(int *a, int n, int key) {
	for(i = 0 ; i < n ; i++) {
		if(a[i] == key) {
			return i;
		}
	}
	return -1;
}

int main() {

	int mainSocket, newSocket;
	struct sockaddr_in serverAddr, clientAddr;
	mainSocket = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5000);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	
	memset(serverAddr.sin_zero, '\0',sizeof(serverAddr.sin_zero));

	int res = bind(mainSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr));
	if(res == -1) {
		printf("Error at server in binding\n");
		return 0;
	}

	res = listen(mainSocket, 5);
	if(res == 0) {
		printf("Listening at server\n");
	} else {
		printf("Error at server in listening\n");
	}

	socklen_t addr_size = sizeof(clientAddr); 
	newSocket = accept(mainSocket, (struct sockaddr*) &clientAddr, &addr_size);

	while(1) {

		int key, opt, n, i;

		recv(newSocket, &opt, sizeof(opt), 0);

		if(opt == 4) {
			break;
		}

		recv(newSocket, &n, sizeof(n), 0);
		
		int numbers[n];

		recv(newSocket, numbers, sizeof(numbers), 0);
		recv(newSocket, &key, sizeof(key), 0);

		for(i = 0 ; i < n ; i++) {
			printf("%d ",numbers[i]);
		}

		printf("\nOption recieved from client: %d", opt);
		printf("\nKey recieved from client: %d\n", key);

		char message[MAX_SIZE];
		strcpy(message,"");

		if(opt == 1) {

			int idx = linearSearch(numbers, n, key);
			if(idx == -1) {
				strcpy(message,"Value not found");
			} else {
				strcpy(message,"Value found");
			}
		
		} else if(opt == 2) {
			
			qsort(numbers, n, sizeof(int), cmpfunc);
			strcpy(message,"Sorted Array: ");

			for(i = 0 ; i < n ; i++) {
				strcat(message, toChar(numbers[i]));
				strcat(message, " ");
			}

		} else {
			char odd[MAX_SIZE], even[MAX_SIZE];
			strcpy(odd,"");
			strcpy(even,"");


			for(i = 0 ; i < n ; i++) {
				if(numbers[i]%2) {
					strcat(odd, toChar(numbers[i]));
					strcat(odd, " ");
				} else {
					strcat(even, toChar(numbers[i]));
					strcat(even, " ");
				}
			}

			strcat(message, "Odd: ");
			strcat(message, odd);
			strcat(message, "\nEven: ");
			strcat(message, even);
		}

		send(newSocket, message, sizeof(message), 0);
	}

	close(newSocket);
	close(mainSocket);
}