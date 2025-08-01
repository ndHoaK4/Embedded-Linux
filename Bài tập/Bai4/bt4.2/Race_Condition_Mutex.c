#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3
#define INCREMENTS_PER_THREAD 1000000

int counter = 0;  // Biến toàn cục
pthread_mutex_t lock;  // Biến mutex

void* thread_function(void* arg) {
    long thread_id = (long)arg;
    printf("Thread %ld started.\n", thread_id);

    for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);  // Khởi tạo mutex

    // Tạo luồng
    for (long i = 0; i < NUM_THREADS; i++) {
        int ret = pthread_create(&threads[i], NULL, thread_function, (void*)i);
        if (ret != 0) {
            perror("pthread_create thất bại");
            return 1;
        }
    }

    // Chờ các luồng hoàn tất
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);  // Giải phóng mutex

    printf("Giá trị cuối cùng của counter: %d\n", counter);
    return 0;
}
