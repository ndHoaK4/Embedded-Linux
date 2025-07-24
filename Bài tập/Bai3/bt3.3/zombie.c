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
        printf("Child process (PID=%d) thoát ngay\n", getpid());
        exit(0); // Con thoát ngay
    } else {
        // Tiến trình cha
        printf("Parent process (PID=%d) sleep 30s mà không gọi wait()\n", getpid());
        sleep(30); // Không gọi wait(), con sẽ thành Zombie
        printf("Parent process kết thúc\n");
    }

    return 0;
}
