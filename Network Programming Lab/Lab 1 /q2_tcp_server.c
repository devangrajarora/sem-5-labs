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
   int welcomeSocket, newSocket,  desc, data, recvB, n;
   int i, strLen, vowelCount[5], isPalin;
   char charBuff[100];   

   socklen_t len;
   struct sockaddr_in server, client;   
  

   welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
   if (welcomeSocket == -1)
   {
       printf("\nSocket Creation Error\n");
       exit(0);
   }
   printf("\nSocket Creation Successful\n");
   server.sin_family = AF_INET;
   server.sin_port = htons(5000);
   server.sin_addr.s_addr = htonl(INADDR_ANY);

   desc = bind(welcomeSocket, (struct sockaddr*)&server, sizeof(server));


   desc = listen(welcomeSocket, 1);

   len = sizeof(client);
   newSocket = accept(welcomeSocket, (struct sockaddr*)&client, &len);
    while (1)
   {
       recvB = recv(newSocket, charBuff, sizeof(charBuff), 0);

       if (strcmp(charBuff, "Halt\n") == 0)
       {
           break;
       }

       strLen = 0;
       for (i = 0; charBuff[i] != '\0'; i++);
       strLen = i - 1;

       isPalin = 1;
       for (i = 0; i < strLen / 2; i++) {
           if (charBuff[i] != charBuff[strLen - i - 1])
           {
               isPalin = 0;
               break;
           }
       }

       for (i = 0; i < 5; i++)
           vowelCount[i] = 0;

       for (i = 0; i < strLen; i++)
       {
           if (charBuff[i] == 'a' || charBuff[i] == 'A')
               vowelCount[0]++;

           else if (charBuff[i] == 'e' || charBuff[i] == 'E')
               vowelCount[1]++;

           if (charBuff[i] == 'i' || charBuff[i] == 'I')
               vowelCount[2]++;
          
           if (charBuff[i] == 'o' || charBuff[i] == 'O')
               vowelCount[3]++;

           if (charBuff[i] == 'u' || charBuff[i] == 'U')
               vowelCount[4]++;
       }

       data = send(newSocket, &isPalin, sizeof(int), 0);
       data = send(newSocket, &strLen, sizeof(int), 0);
       data = send(newSocket, vowelCount, sizeof(vowelCount), 0);
   }

   close(newSocket);
   close(welcomeSocket);
}
