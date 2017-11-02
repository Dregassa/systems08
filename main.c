#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

char * permissions(mode_t foo){
	char * tmp = (char *) malloc (9 * sizeof(char));
	strcpy(tmp, "rwxrwxrwx");
	int i = 2;
	int j = 2;
	for (;i > -1; i--){ // work through foo right to left  
		j = 2;
		for (;j > -1 ; j--){
			if ( ! (foo % 2) ){
				tmp[3*i + j] = '-';
			}
			foo = foo >> 1;
			//printf("\n%s\n", tmp);
		} 
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
	printf("\n%s\n", stuffs);
	free (stuffs);
}

