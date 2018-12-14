#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <arpa/inet.h>

void main (int argc, char* argv[]) {

	char message[20];
	int result;
	sprintf(message, "Hello, World");
	//Mkdir Test
	printf("Mkdir test started:");
	char location[255];
	char buffer[255];
	int fd;
	sprintf(location, "%s/aaaaa", argv[1]);
	result = mkdir(location, 0777);
	if (result == -1)
		printf("dir already exists\n");
	else
		printf("dir created on server\n");
	//Create Test
	printf("CREATE TEST: orange.txt\n");
	sprintf(location, "%s/orange.txt", argv[1]);
	creat(location, 0777);
	//printf("?\n");

	//Open Test
	sprintf(location, "%s/1", argv[1]);
	printf("Open Test: opening %s\n", location);
	result = open(location, O_RDONLY);
	printf("Opened %s successfully!\n", location);

	//Flush Test

	//Release Test

	//Truncate Test

	//getattr Test
	printf("getattr test started:");
	struct stat *statbuff;
	sprintf(location, "%s/test.txt", argv[1]);
	stat(location, statbuff);
	printf("st_mode is %d for file %s\n", statbuff->st_mode, location);

	//Write Test

	printf("Write Test Started: ");
	sprintf(location, "%s/1", argv[1]);
	fd = open(location, (O_WRONLY | O_CREAT | O_APPEND), 0700);
	if (fd == -1)
		printf("Created test.txt on server - writing %s:%s\n", message, strerror(errno));
	else
		printf("Appending %s to file test.txt on server\n", message);
	write(fd, message, strlen(message));

	//Read Test
	printf("Read test started:");
	sprintf(location, "./test.txt", argv[1]);
	fd = open(location, O_RDONLY);
	if (fd == -1)
		printf("File not found on server\n");
	else {
		read(fd, buffer, 12);
		printf("read %d bytes got : %s\n", 12, buffer);
	}

	//Opendir Test
	//Readdir Test
	//Releasedir Test
}
