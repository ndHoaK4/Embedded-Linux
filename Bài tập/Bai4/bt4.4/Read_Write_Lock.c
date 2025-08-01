#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

int data = 0;  // Tài nguyên được chia sẻ

pthread_rwlock_t rwlock;  // Read-Write lock

void* reader(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_rdlock(&rwlock);  // Xin quyền đọc
        printf("Reader %d: đọc giá trị = %d\n", id, data);
        pthread_rwlock_unlock(&rwlock);  // Giải phóng quyền đọc
        usleep(100000 + rand() % 300000); // Ngủ ngẫu nhiên 100ms-400ms
    }
    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_wrlock(&rwlock);  // Xin quyền ghi (độc quyền)
        data++;
        printf("Writer %d: ghi giá trị mới = %d\n", id, data);
        pthread_rwlock_unlock(&rwlock);  // Giải phóng quyền ghi
        usleep(300000 + rand() % 500000); // Ngủ ngẫu nhiên 300ms-800ms
    }
    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];
    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];

    pthread_rwlock_init(&rwlock, NULL);  // Khởi tạo Read-Write lock

    // Tạo luồng Reader
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Tạo luồng Writer
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Chờ tất cả luồng kết thúc (thực tế là vòng lặp vô hạn, có thể Ctrl+C dừng)
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    pthread_rwlock_destroy(&rwlock);  // Giải phóng RW lock

    return 0;
}
