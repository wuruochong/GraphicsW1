#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  int fd,r,g,b,i,c;
  char line[20];

  fd = open("image.ppm", O_CREAT|O_TRUNC|O_WRONLY, 0644);
  snprintf(line, sizeof(line), "P3 500 500 255 \n");
  write(fd,line, strlen(line));
  
  for(i=0; i<500; i++){
    for(c=0; c<500; c++){
      r=i;
      g=c;
      b = abs(i-c);
      sprintf(line, "%d %d %d ", r,g,b);
      write(fd,line,strlen(line));
    }
    write(fd, "\n",strlen("\n"));
  }
  close(fd);
}
      
