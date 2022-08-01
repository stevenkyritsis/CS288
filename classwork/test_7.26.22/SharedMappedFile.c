#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#define PageSize  4096

int main(int argc, char *argv[]) {
	int fd;   void *data;

	fd = open("/tmp/ShareMappedFile", O_CREAT | O_RDWR, 0777);
	/* adjust file size */
	lseek(fd, PageSize, SEEK_SET);
	write(fd, "x", 1 );

	/* mmap the file. */
	data = mmap(NULL, PageSize, PROT_WRITE, MAP_SHARED, fd, 0);
 	/* read or modify the mapped region based on command line: */
  	if (argc == 2) {
    		printf("writing: \"%s\"\n", argv[1]);
    		strncpy(data, argv[1], strlen(argv[1])+1);
  	} else
    		printf("reading: \"%s\"\n", (char *)data);

	if (munmap(data, PageSize) == -1)
        	perror("Error un-mmapping the file");
  	close(fd);
  	return 0;
}
