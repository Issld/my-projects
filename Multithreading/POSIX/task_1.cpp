#include <cstring>
#include <semaphore.h>

#define NUMBER_OF_THREADS 14

void computation()
{
    auto delay = uni_delay(rng);
    auto chance = uni_chance(rng);
    sleep_ms(delay);
    if (chance < 10) {
        sleep_ms(delay);
    }
}

// thread identifiers
pthread_t tid[NUMBER_OF_THREADS];
// critical section lock
pthread_mutex_t lock;
// semaphores for sequential threads
sem_t semB, semK, semG, semM, semD, semH, semAllow_1, semAllow_2, semAllow_3;

int err;

const char* unsynchronized_threads()
{
    return "bcdf";
}

const char* sequential_threads()
{
    return "bkgm";
}

void *thread_b(void *ptr);
void *thread_c(void *ptr);
void *thread_d(void *ptr);
void *thread_f(void *ptr);
void *thread_e(void *ptr);
void *thread_k(void *ptr);
void *thread_g(void *ptr);
void *thread_m(void *ptr);
void *thread_h(void *ptr);
void *thread_n(void *ptr);
void *thread_p(void *ptr);

void *thread_a(void *ptr)
{
    //Отображение потока а
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "a" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    //Создание потока b
    err = pthread_create(&tid[1], NULL, thread_b, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    //Создание потока c
    err = pthread_create(&tid[2], NULL, thread_c, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    //Создание потока d
    err = pthread_create(&tid[3], NULL, thread_d, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    //Создание потока f
    err = pthread_create(&tid[4], NULL, thread_f, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;  
    //Ожидание завершения потока D
    pthread_join(tid[3], NULL);
    return  ptr;
}

void *thread_b(void *ptr)
{
    //Отображение потока b в ассинхронной части
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "b" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    //Ожидание завершения потока c
    pthread_join(tid[2], NULL);
    sem_post(&semAllow_1);
    //Отображение потока b
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "b" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_wait(&semD);
    //Отображение потока b в синхронной части
    for (int i = 0; i < 3; ++i) {
    	sem_wait(&semB);
        pthread_mutex_lock(&lock);
        std::cout << "b" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semK);
    }
    sem_wait(&semB);
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "b" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_post(&semH);
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "b" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    return ptr;
}

void *thread_c(void *ptr)
{
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "c" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    err = pthread_create(&tid[5], NULL, thread_e, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    return ptr;
}


void *thread_d(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "d" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_post(&semAllow_2);
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "d" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    //Связать с потоком C
    // wait for thread F to finish
    pthread_join(tid[4], NULL);
    sem_post(&semD);
    err = pthread_create(&tid[6], NULL, thread_k, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;   
    err = pthread_create(&tid[7], NULL, thread_g, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;   
    err = pthread_create(&tid[8], NULL, thread_m, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;  
    pthread_join(tid[8], NULL);
    return ptr;
}

void *thread_e(void *ptr)
{
    sem_wait(&semAllow_1);
    sem_wait(&semAllow_2);
    sem_wait(&semAllow_3);
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "e" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    return ptr;
}

void *thread_f(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "f" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_post(&semAllow_3);
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "f" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[5], NULL);
    return ptr;
}

void *thread_k(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        sem_wait(&semK);
        pthread_mutex_lock(&lock);
        std::cout << "k" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semG);
    }
    sem_wait(&semK);
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "k" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    return ptr;
}

void *thread_g(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        sem_wait(&semG);
        pthread_mutex_lock(&lock);
        std::cout << "g" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semM);
    }
    return ptr;
}

void *thread_m(void *ptr)
{
    // perform computations
    int k = 0;
    for (int i = 0; i < 3; ++i) {
        sem_wait(&semM);
        pthread_mutex_lock(&lock);
        std::cout << "m" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semB);
    }
    sem_post(&semK);
    err = pthread_create(&tid[9], NULL, thread_h, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "m" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[9], NULL);
    return ptr;
}

void *thread_h(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "h" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_wait(&semH);
    err = pthread_create(&tid[10], NULL, thread_n, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    pthread_join(tid[10], NULL);
    return ptr;
}


void *thread_n(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "n" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[1], NULL);
    err = pthread_create(&tid[11], NULL, thread_p, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    pthread_join(tid[11], NULL);
    return ptr;
}

void *thread_p(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "p" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[6], NULL);
    return ptr;
}

int main()
{
    // initilize mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        std::cerr << "Mutex init failed" << std::endl;
        return 1;
    }
    std::cout << "Не синхронизированные потоки" << unsynchronized_threads << std::endl;
    std::cout << "Cинхронизированные потоки" << sequential_threads << std::endl;
    // initialize semaphores
    // THIS CODE WILL NOT RUN ON MacOS!
    // MacOS doesn't support unnamed semaphores, so named semaphores should be used instead
    if ( sem_init(&semB, 0, 1) != 0 ) {
        std::cerr << "Semaphore #1 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semK, 0, 0) != 0 ) {
        std::cerr << "Semaphore #2 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semG, 0, 0) != 0 ) {
        std::cerr << "Semaphore #3 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semM, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semD, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semH, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semAllow_1, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semAllow_2, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semAllow_3, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }

    // start the first thread
    err = pthread_create(&tid[0], NULL, thread_a, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    
    // ... and wait for it to finish
    pthread_join(tid[0], NULL);
    
    // free resources
    pthread_mutex_destroy(&lock);
    sem_destroy(&semB);
    sem_destroy(&semK);
    sem_destroy(&semG);
    sem_destroy(&semM);
    sem_destroy(&semD);
    sem_destroy(&semH);
    sem_destroy(&semAllow_1);
    sem_destroy(&semAllow_2);
    sem_destroy(&semAllow_3);
    std::cout << std::endl;
    // success
    return 0;
}
