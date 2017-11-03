#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// list all files in directory
// list all directories in directory
// show total size of all the regular files in the directory

int main() {
	
	DIR * d;
	d = opendir(".");
	struct dirent *entry;
	entry = readdir(d);
	
	printf("\nStatistics for Directory: .\n");
	
	printf("List of all files: \n");
	while (entry){
		if (entry->d_type == DT_DIR) {
			printf("\tdir: %s\n", entry->d_name);
		} 
		else if (entry->d_type == DT_REG) {
			printf("\tfile: %s\n", entry->d_name);
		} 
		else {
			printf("\tmisc: %s\n", entry->d_name);
		}
		entry = readdir(d);
	}
	closedir(d);
	
	DIR * dir;
	dir = opendir(".");
	struct dirent *info;
	info = readdir(d);
  int size_final = 0;
	
	while (info) {
		if (info->d_type == DT_REG) {
			char temp[256];
			strcpy(temp, ".");
			strcat(temp, "/");
			strcat(temp, info->d_name);
			struct stat sb;
			stat(temp, &sb);
			size_final += sb.st_size;
		}
		info = readdir(d);
	}
	printf("Total Directory Size: %d Bytes\n", size_final);
	
	closedir(d);
	return 0;
}