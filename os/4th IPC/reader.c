#include <sys/stat.h> 
#include <unistd.h> 
 	
#define MAX_BUF 1024 
 	
int main() 
{ 
int fd; 
char *myfifo = "/tmp/myfifo"; 
char buf[MAX_BUF]; 
 
/* open, read, and display the message from the FIFO */ 
fd = open(myfifo, O_RDONLY); 
read(fd, buf, MAX_BUF); 
printf("Received: %s", buf); 
close(fd); 	
return 0; 
} 

//  To Run the Program 
 	
//  [root@localhost /]# cc writer.c 
//  [root@localhost /]# ./a.out 
 	
//  After this Open New Terminal by pressing shift+ctrl+N or Go to File->Open Terminal 
 	
 	
// [root@localhost /]# cc reader.c 
// [root@localhost /]# ./a.out 