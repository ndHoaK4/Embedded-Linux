// filestat.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    struct stat file_stat;

    if (lstat(file_path, &file_stat) != 0) {
        perror("lstat");
        return 1;
    }

    printf("File Path: %s\n", file_path);

    printf("File Type: ");
    if (S_ISREG(file_stat.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(file_stat.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(file_stat.st_mode))
        printf("Symbolic Link\n");
    else
        printf("Other\n");

    printf("Size: %ld bytes\n", file_stat.st_size);

    char timebuf[100];
    struct tm *mod_time = localtime(&file_stat.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", mod_time);
    printf("Last Modified: %s\n", timebuf);

    return 0;
}
