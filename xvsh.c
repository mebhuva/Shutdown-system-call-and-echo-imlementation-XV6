#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define BUFFER_LENGTH 1024 



void  StringManipulation(char *line, char **argv)
{
     for (;*line != '\0';) {
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';
          *argv++ = line; 
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;
     }
     *argv = '\0';
}

  
int  main(void)
{

  char  Buffer[BUFFER_LENGTH] = {0};  
     char  *argv[64] = {0};
     
     while (1) { 
       
          printf(2,"xvsh> ");
          gets(Buffer,sizeof(Buffer)); 
   StringManipulation(Buffer,argv);
    
if (strcmp(argv[0], "exit") == 0)
               exit();
int isback = 0;
     int  pid = fork();
int i =0;
    while (argv[i] != '\0') { 
i++;
if(strcmp(argv[i], "&") == 0)
{
        argv[i] = '\0';
        isback = 1;
        break;
}
    }
     if ((pid) < 0) { 
          printf(2,"ERROR: forking child process failed\n");
          exit();
     }
     else if (pid == 0) {
int pidno = getpid();
if(isback)
{
 printf(1,"[pid %d] runs as a background process",pidno);
}
          if (exec(*argv, argv)< 0) { 
char *str = '\0'; 
str = argv[0];
   if(*str!='\0')
{
 printf(2,"Cannot run this command %s\n",argv[0]); 
}
               exit();
          }
     }
     else if(isback == 0){
         wait();
     }


}
        
}