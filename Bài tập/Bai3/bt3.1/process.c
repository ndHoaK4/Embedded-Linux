#include <stdio.h>      // printf
#include <stdlib.h>     // exit
#include <unistd.h>     // fork, getpid
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // wait, WIFEXITED, WEXITSTATUS

int main() {
    pid_t pid;      // Biến lưu PID của tiến trình con
    int status;     // Biến lưu trạng thái trả về từ tiến trình con

    pid = fork();   // Tạo tiến trình con

    if (pid < 0) {
        // ❌ fork thất bại
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // 👶 Đây là tiến trình con
        printf("Child: My PID is %d\n", getpid());
        exit(10);  // Kết thúc với mã 10
    } else {
        // 👨 Đây là tiến trình cha
        printf("Parent: My PID is %d, Child PID is %d\n", getpid(), pid);

        // Chờ tiến trình con kết thúc
        wait(&status);

        // Kiểm tra xem con có kết thúc bình thường không
        if (WIFEXITED(status)) {
            printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: Child did not terminate normally\n");
        }
    }

    return 0;
}
