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
               
     
     
     
     
     
     }    
  
                
  
  

return 0;
}
  

void clean_up(int cond, int *sock){
       cout<<"Exiting now";
        close(*sock);
         unlink(SOCKET_NAME);
          exit(cond);
}

