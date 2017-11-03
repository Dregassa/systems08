#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

char * permissions(mode_t foo){
	char * tmp = (char *) malloc (9 * sizeof(char));
	strcpy(tmp, "rwxrwxrwx");
	int i = 8;
	for (;i > -1; i--){ // work through foo right to left  
		if ( ! (foo % 2) ){
				tmp[i] = '-';
			}
			foo = foo >> 1; 
	}

	//printf("\n%s\n", tmp);
	return tmp;
}


int main(){
	struct stat source;
	char file[] = "stats";
	stat("stats", &source);
	printf("File being checked: %s\n", file);
	printf("Size: %ld\n", source.st_size);
	printf("Time of last access: %s\n", ctime(&(source.st_atime)));
  	
	//printf("\n%o\n", source.st_mode);
 	char * stuffs = permissions(source.st_mode);
	printf("%s\n", stuffs);
	free (stuffs);
}

