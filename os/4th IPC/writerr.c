#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
 	
int main() 
{ 
int fd; 
char * myfifo = "/tmp/myfifo"; /* create the FIFO (named pipe) */ 
mkfifo(myfifo, 0666); 

fd = open(myfifo, O_WRONLY); 
write(fd,"Hi", sizeof("Hi")); /* write "Hi" to the FIFO */ 
close(fd); 
 	
unlink(myfifo); /* remove the FIFO */ 
return 0; 
} 