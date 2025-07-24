#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork thất bại");
        exit(1);
    }

    if (pid == 0) {
        // Tiến trình con
        for (int i = 0; i < 5; i++) {
            printf("Child PID=%d, PPID=%d\n", getpid(), getppid());
            sleep(5);
        }
        printf("Child kết thúc\n");
    } else {
        // Tiến trình cha thoát ngay
        printf("Parent PID=%d thoát ngay\n", getpid());
        exit(0);
    }

    return 0;
}
