#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 50

int main( int argc, char* argv[] ) {
    int fdone[2];
    pid_t childid;

    char readBuff[BUFFER_SIZE];

    pipe(fdone);

    if( argc != 3 ) {
        printf("Need exactly 2 parameters.\n");
        exit(1);
    }

    int fileOpen = open(argv[1], 0);
    int targetFile = open(argv[2], O_RDWR|O_CREAT|O_APPEND, 0666);
    childid = fork();

    if (childid == 0) {
        close(fdone[1]);

        while (read(fdone[0], readBuff, sizeof(readBuff)) > 0) {
            // Writing to the target file
            write(targetFile, readBuff, strlen(readBuff) - 1);
        }

        close(fdone[0]);
        close(targetFile);
    }
    else {
        close(fdone[0]);

        // reading from the text file
        while (read(fileOpen, readBuff, sizeof(readBuff)) > 0) {
            write(fdone[1], readBuff, sizeof(readBuff));
            memset(readBuff, 0, BUFFER_SIZE);
        }

        close(fdone[1]);
        close(fileOpen);
        wait(NULL);
    }
}