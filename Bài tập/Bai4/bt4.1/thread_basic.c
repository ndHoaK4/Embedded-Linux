#include <stdio.h>
#include <pthread.h>

// Hàm cho mỗi luồng con
void* thread_function(void* arg) {
    long thread_id = (long)arg; // Ép kiểu từ void* sang long
    printf("Thread với ID %ld đang chạy!\n", thread_id);
    pthread_exit(NULL); // Kết thúc luồng một cách rõ ràng (có thể bỏ cũng được)
}

int main() {
    pthread_t threads[2]; // Mảng chứa ID của 2 luồng

    // Tạo 2 luồng
    for (long i = 0; i < 2; i++) {
        int ret = pthread_create(&threads[i], NULL, thread_function, (void*)i);
        if (ret != 0) {
            perror("pthread_create thất bại");
            return 1;
        }
    }

    // Đợi các luồng kết thúc
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Luồng chính kết thúc sau khi các luồng con hoàn tất.\n");
    return 0;
}
