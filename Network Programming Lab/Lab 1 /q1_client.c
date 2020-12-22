#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define MAX_SIZE 1024

int main() {

	int clientSocket;
	struct sockaddr_in serverAddr;
	char message[MAX_SIZE];
	
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5000);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

	int res = connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
	if(res == -1) {
		printf("Error in connecting at client\n");
		return 0;
	}

	printf("\nChoose Option:\n1. Search in array\n2. Sort array\n3. Split array into odd and even\n4. Exit\n");

	while(1) {

		int opt, key = -1, i;
		
		printf("\nEnter option:");
		scanf("%d", &opt);

		send(clientSocket, &opt, sizeof(opt), 0);

		if(opt == 4) {
			break;
		}

		printf("Enter number of elements: ");
		int n;
		scanf("%d", &n);

		send(clientSocket, &n, sizeof(n), 0);

		int numbers[n];
		

		printf("Enter list of numbers: ");
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &numbers[i]);
		}
		
		if(opt == 1) {
			printf("Enter value to search: ");
			scanf("%d", &key);
		}


		send(clientSocket, numbers, sizeof(numbers), 0);
		send(clientSocket, &key, sizeof(key), 0);

		recv(clientSocket, message, sizeof(message), 0);
		printf("\n%s\n", message);
	}

	close(clientSocket);
}