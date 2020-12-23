#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
   int welcomeSocket, desc, data, recvB, n;
  
   char charBuff[100];
   char f = getchar();
   struct sockaddr_in server;
  
  
   welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

   server.sin_family = AF_INET;
   server.sin_port = htons(5000);
   server.sin_addr.s_addr = inet_addr("127.0.0.1");

   desc = connect(welcomeSocket, (struct sockaddr*)&server, sizeof(server));

   while (1)
   {
      
       fgets(charBuff, 100, stdin);       

       data = send(welcomeSocket, charBuff, sizeof(charBuff), 0);

       if (strcmp(charBuff, "Halt\n") == 0)
       {
           printf("\nClient bids goodbye\n");
           close(welcomeSocket);
           exit(0);
       }

       int strLen, isPalin, vowelCount[5];

       recvB = recv(welcomeSocket, &isPalin, sizeof(int), 0);

       if (isPalin == 1)
           printf("\nString is a Palindrome\n");
       else
       {
           printf("\nString is not a Palindrome\n");
       }
      
       recvB = recv(welcomeSocket, &strLen, sizeof(int), 0);
       printf("\nLength of string : %d\n", strLen);

       recvB = recv(welcomeSocket, vowelCount, sizeof(vowelCount), 0);
       if (recvB == -1)
       {
           printf("\nVowel Count Message recieving failed\n");
           exit(0);
       }
       printf("Occurences of -->\na : %d\ne : %d\ni : %d\no : %d\nu : %d\n", vowelCount[0], vowelCount[1], vowelCount[2], vowelCount[3], vowelCount[4]);
   } 

   close(welcomeSocket);

}