#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

int data = 0;
bool data_ready = false;

pthread_mutex_t lock;
pthread_cond_t cond;

void* producer(void* arg) {
    for (int i = 0; i < 10; i++) {
        int produced_data = rand() % 100; // sinh dữ liệu ngẫu nhiên

        pthread_mutex_lock(&lock);
        while (data_ready) {
            // Đợi cho đến khi consumer đọc xong dữ liệu cũ
            pthread_cond_wait(&cond, &lock);
        }

        data = produced_data;
        data_ready = true;
        printf("Producer: produced data = %d\n", data);

        pthread_cond_signal(&cond); // Báo cho consumer
        pthread_mutex_unlock(&lock);

        usleep(100000); // delay nhỏ cho dễ quan sát
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&lock);
        while (!data_ready) {
            pthread_cond_wait(&cond, &lock);
        }

        printf("Consumer: consumed data = %d\n", data);
        data_ready = false;

        pthread_cond_signal(&cond); // Báo cho producer là đã tiêu thụ xong
        pthread_mutex_unlock(&lock);

        usleep(150000); // delay nhỏ cho dễ quan sát
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // Khởi tạo seed cho hàm rand() để tạo số ngẫu nhiên khác nhau mỗi lần chạy

    pthread_t prod_thread, cons_thread; // Khai báo 2 biến luồng: 1 cho Producer, 1 cho Consumer

    pthread_mutex_init(&lock, NULL);     // Khởi tạo mutex
    pthread_cond_init(&cond, NULL);      // Khởi tạo condition variable

    pthread_create(&prod_thread, NULL, producer, NULL); // Tạo luồng Producer
    pthread_create(&cons_thread, NULL, consumer, NULL); // Tạo luồng Consumer

    pthread_join(prod_thread, NULL); // Chờ luồng Producer kết thúc
    pthread_join(cons_thread, NULL); // Chờ luồng Consumer kết thúc

    pthread_mutex_destroy(&lock);    // Hủy mutex sau khi dùng xong
    pthread_cond_destroy(&cond);     // Hủy condition variable sau khi dùng xong

    return 0;
}

