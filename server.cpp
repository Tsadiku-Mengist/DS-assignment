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
#define PORT 1227
#define SIM_LENGTH 10

int main (){
  
 int sock; 
 int connect_sock;
 struct sockaddr_in serv_name;
  size_t len; //It is the type of the result returned by sizeof operator.
  int count;
  
    sock = socket(AF_INET, SOCK_STREAM, 0); 
  
  if (sock < 0) {
         perror ("Error opening channel");
          clean_up(1, &sock); //invoke function clean up in the agrgumentd form of con and sock
    }
  
  
  bzero(&serv_name, sizeof(serv_name)); //The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros
  serv_name.sin_family = AF_INET;
  serv_name.sin_port = htons(PORT);
  
   if (bind(sock, (struct sockaddr *)&serv_name, sizeof(serv_name)) < 0)
    { perror ("Error naming channel");
      clean_up(1, &sock);
    }
  
  
   cout<<"Server is alive and waiting for socket connection from client";
    listen(sock, 1);
  
   len = sizeof(serv_name);
  connect_sock = accept(sock, (struct sockaddr *)&serv_name, &len);
  
  for (count = 1; count <= SIM_LENGTH; count++)
    { write(connect_sock, &count, 4); // //The write() function shall attempt to write nbyte bytes from the buffer pointed to by buf to the file associated with the open file descriptor, fildes
      cout<<"Server has written %d to socket.\n" + count;
  
  
  close(connect_sock);  
  clean_up(0, &sock);
  
  return 0;
}
  
//funciton to remove connction
void clean_up(int cond, int *sock){ 
  cout<<"Exiting now";
   close(*sock); 
    exit(cond);
}
