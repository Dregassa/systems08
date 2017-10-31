#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
int main(){
  struct stat source;
  char file[] = "stats";
  stat("stats", &source);
  printf("File being checked: %s\n", file);
  printf("Size: %ld\n", source.st_size);
  printf("Time of last access: %s\n", ctime(&(source.st_atime)));
  
}

