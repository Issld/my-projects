#include <cstring>
#include <semaphore.h>

#define NUMBER_OF_THREADS 12

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
sem_t semC, semD, semM, semM_allow, semH, semH_allow, semI;

int err;

const char* unsynchronized_threads()
{
    return "cdef";
}

const char* sequential_threads()
{
    return "him";
}

void *thread_b(void *ptr);
void *thread_c(void *ptr);
void *thread_d(void *ptr);
void *thread_e(void *ptr);
void *thread_f(void *ptr);
void *thread_g(void *ptr);
void *thread_h(void *ptr);
void *thread_i(void *ptr);
void *thread_k(void *ptr);
void *thread_m(void *ptr);
void *thread_n(void *ptr);

void *thread_a(void *ptr)
{
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "a" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    err = pthread_create(&tid[1], NULL, thread_b, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[2], NULL, thread_c, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    return  ptr;
}

void *thread_b(void *ptr)
{
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
    pthread_join(tid[1], NULL);
    err = pthread_create(&tid[3], NULL, thread_d, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[4], NULL, thread_e, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[5], NULL, thread_f, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "c" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_post(&semC);
    sem_wait(&semD);
    err = pthread_create(&tid[9], NULL, thread_h, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    return ptr;
}

void *thread_d(void *ptr)
{
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "d" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[5], NULL);
    sem_wait(&semC);
    sem_post(&semD);
    err = pthread_create(&tid[6], NULL, thread_k, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[7], NULL, thread_m, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[8], NULL, thread_g, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "d" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[8], NULL);
    sem_wait(&semM_allow);
    sem_wait(&semH_allow);
    sem_post(&semD);
    err = pthread_create(&tid[10], NULL, thread_i, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    return ptr;
}

void *thread_e(void *ptr)
{
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
    pthread_join(tid[4], NULL);
    return ptr;
}

void *thread_g(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "g" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[6], NULL);
    return ptr;
}

void *thread_k(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "k" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    return ptr;
}

void *thread_m(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "m" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_post(&semM_allow);
    for (int i = 0; i < 3; ++i) {
        sem_wait(&semM);
        pthread_mutex_lock(&lock);
        std::cout << "m" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semH);
    }
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
    sem_post(&semH_allow);
    sem_wait(&semD);
    for (int i = 0; i < 3; ++i) {
        sem_wait(&semH);
        pthread_mutex_lock(&lock);
        std::cout << "h" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semI);
    }
    pthread_join(tid[7], NULL);
    pthread_join(tid[10], NULL);
    err = pthread_create(&tid[11], NULL, thread_n, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    return ptr;
}

void *thread_i(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        sem_wait(&semI);
        pthread_mutex_lock(&lock);
        std::cout << "i" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semM);
    }
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
    if ( sem_init(&semC, 0, 0) != 0 ) {
        std::cerr << "Semaphore #3 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semD, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semM, 0, 0) != 0 ) {
        std::cerr << "Semaphore #3 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semM_allow, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semH, 0, 1) != 0 ) {
        std::cerr << "Semaphore #3 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semH_allow, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semI, 0, 0) != 0 ) {
        std::cerr << "Semaphore #3 init failed" << std::endl;
        return 1;
    }
    
    // start the first thread
    err = pthread_create(&tid[0], NULL, thread_a, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    
    // ... and wait for it to finish
    pthread_join(tid[0], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[9], NULL);
    pthread_join(tid[11], NULL);
    
    // free resources
    pthread_mutex_destroy(&lock);
    sem_destroy(&semC);
    sem_destroy(&semD);
    sem_destroy(&semM);
    sem_destroy(&semM_allow);
    sem_destroy(&semH);
    sem_destroy(&semH_allow);
    sem_destroy(&semI);
    std::cout << std::endl;
    // success
    return 0;
}
