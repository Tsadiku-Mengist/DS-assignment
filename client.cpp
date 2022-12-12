#include<sys/type> //header file defines a collection of typedef symbols and structures
#include<unistd>  //header defines miscellaneous symbolic constants and types, and declares miscellaneous functions
#include<stdio>  //header file which has the necessary information to include the input/output related functions in our program
#include<string>
#include<stdlib>
#include<signal>
#include<sys/socket>
#include<sys/un>
#include <iostream>

using namespace std;
    #define SIM_LENGTH 10
    #define IP_ADDRESS "132.161.33.175"
    #define PORT 1227

int main (){
int sock;
struct sockaddr_in cli_name;
int count;
int value;
  cout<<"Client is alive and establishing socket connection.";
     
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0){
        perror ("Error opening channel");
         close(sock);
          exit(1);
    }
    bzero(&cli_name, sizeof(cli_name));
    cli_name.sin_family = AF_INET;
    cli_name.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    cli_name.sin_port = htons(PORT);
    
     if (connect(sock, (struct sockaddr *)&cli_name, sizeof(cli_name)) < 0)
    { perror ("Error establishing communications");
      close(sock);
      exit(1);
    }
     for (count = 1; count <= SIM_LENGTH; count++) {
         read(sock, &value, 4);
      cout<<"Client has received from socket" + value;
         
           cout<<"Exiting now";

  close(sock);
  exit(0);
    }
return 0;
}
  




