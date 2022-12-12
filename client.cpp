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

return 0;
}
  

void clean_up(int cond, int *sock){
       cout<<"Exiting now";
        close(*sock);
         unlink(SOCKET_NAME);
          exit(cond);
}

