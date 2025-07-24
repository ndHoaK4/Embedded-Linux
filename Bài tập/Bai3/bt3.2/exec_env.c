#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // ✅ 1. Thiết lập biến môi trường MY_COMMAND = ls
    setenv("MY_COMMAND", "ls", 1); // 1: ghi đè nếu đã tồn tại

    pid = fork();  // ✅ 2. Tạo tiến trình con

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // 👶 Tiến trình con
        char *cmd = getenv("MY_COMMAND");  // ✅ 3. Lấy giá trị biến môi trường
        if (cmd == NULL) {
            fprintf(stderr, "MY_COMMAND not set\n");
            exit(1);
        }

        printf("Child: executing command '%s'\n", cmd);

        // ✅ 4. Gọi exec để chạy lệnh (vd: ls, date, etc.)
        execlp(cmd, cmd, NULL);

        // ❌ Nếu exec thất bại
        perror("execlp failed");
        exit(1);
    } else {
        // 👨 Cha chờ con kết thúc
        int status;
        wait(&status);
        printf("status: %d\n", status);
        printf("Parent: Child finished.\n");
    }

    return 0;
}
