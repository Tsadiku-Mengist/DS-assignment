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
    #define SOCKET_NAME "com1"
    #define SIM_LENGTH

int main (){
   pid_t pid;   // pid_t data type represents process IDs
  pid = fork(); //creating a new process by using fork and put the processes id on the pid
        
           if (pid == -1){
               cout<<"error in the fork";
               exit(1);
               }      //if the pid == -1 this  means that the processes is not created and their is an error on the fork
  
 if (pid == 0){
              int sock;
              struct sockaddr_un cli_name;
              int count;
              int value;
     sleep(3); //server process time 
      cout<<"client is alive and establishing socket connection";
         sock = socket(AF_UNIX, SOCK_STREM, 0);
            if (sock < 0)
              {
               perror("Error opening channel");
               clean_up(1, $sock); //functon call for clean up as an aregument of cond and sock
               }
        
     
     bzero(&cli_name, sizeof(cli_name)); //The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros
     cli_name.sun_family = AF_UNIX;
     strcpy(cli_name.sun_path, SOCKET_NAME)
     }
    
    if (connect(sock,(struct sockaddr *)cli_name, sizeof(cli_name)) < 0) {
        perror("Error establishing communication");
          clean_up(1, &sock);
    }
  
                
  for(count = 1; count <= SIM_LENGTH; count++){
      read(sock, &value, 4); // function shall attempt to read nbyte bytes from the file associated with the open file descriptor, fildes,
       cout<<"clinet has received from socket", value);
     }
    
        close(sock);
        exit(0); //end the connection to the socket
}



else
{
int sock;
int connect_sock;
struct sockaddr_un serv_name;
int count;
 size_t len:
 
    sock = socket (AF_UNIX, SOCKET_NAME);
         if (sock < 0)
         {
           perror("Error opening channel");
           clean_up(1, &sock);
          }
    listen(sock, 1);
    cout<<"server is alive and waiting for socket connection from clinet";
    len = sizeof(serv_name);
    connect_sock = accept(sock, (struct sockaddr *)&serv_name, &len);
     
    for (count = 1; count<= SIM-LENGTH; count++)
    {
        write(pid, NULL, 0); //The write() function shall attempt to write nbyte bytes from the buffer pointed to by buf to the file associated with the open file descriptor, fildes
        clean_up(0, &sock);
    }
 }

return 0;
}
  

void clean_up(int cond, int *sock){
       cout<<"Exiting now";
        close(*sock);
         unlink(SOCKET_NAME);
          exit(cond);
}

