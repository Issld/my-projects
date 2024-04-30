#include <cstring>
#include <semaphore.h>

#define NUMBER_OF_THREADS 11

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
sem_t semA, semB_1, semB_2, semB_3, semE, semI, semK, semM;

int err;

const char* unsynchronized_threads()
{
    return "bcde";
}

const char* sequential_threads()
{
    return "ikm";
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
void *thread_i(void *ptr);
void *thread_n(void *ptr);

void *thread_a(void *ptr)
{
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "a" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_post(&semA);
    //sew_post(&semAllow_A);
    err = pthread_create(&tid[2], NULL, thread_c, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[3], NULL, thread_d, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[4], NULL, thread_e, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;  
    // wait for thread D to finish
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
    sem_wait(&semA);
    sem_post(&semB_1);
    sem_post(&semB_2);
    sem_post(&semB_3);
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
    sem_wait(&semB_1);
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "c" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[1], NULL);
    return ptr;
}


void *thread_d(void *ptr)
{
    sem_wait(&semB_2);
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "d" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[2], NULL);
    //std::cout << "allive" << std::flush;  
    return ptr;
}

void *thread_e(void *ptr)
{
    // perform computations
    sem_wait(&semB_3);
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "e" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[3], NULL);
    err = pthread_create(&tid[5], NULL, thread_f, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[6], NULL, thread_g, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[7], NULL, thread_h, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[8], NULL, thread_i, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "e" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    sem_post(&semE);
    pthread_join(tid[8], NULL);
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
    pthread_join(tid[5], NULL);
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
    pthread_join(tid[6], NULL);
    return ptr;
}

void *thread_i(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        pthread_mutex_lock(&lock);
        std::cout << "i" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }
    pthread_join(tid[7], NULL);
    err = pthread_create(&tid[9], NULL, thread_k, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[10], NULL, thread_m, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    sem_wait(&semE);
    for (int i = 0; i < 3; ++i) {
        sem_wait(&semI);
        pthread_mutex_lock(&lock);
        std::cout << "i" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semK);
    }
    pthread_join(tid[10], NULL);
    pthread_join(tid[11], NULL);
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
        sem_post(&semM);
    }
    return ptr;
}

void *thread_m(void *ptr)
{
    // perform computations
    for (int i = 0; i < 3; ++i) {
        sem_wait(&semM);
        pthread_mutex_lock(&lock);
        std::cout << "m" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semI);
    }
    pthread_join(tid[9], NULL);
    err = pthread_create(&tid[11], NULL, thread_n, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
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
    if ( sem_init(&semA, 0, 0) != 0 ) {
        std::cerr << "Semaphore #1 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semB_1, 0, 0) != 0 ) {
        std::cerr << "Semaphore #1 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semB_2, 0, 0) != 0 ) {
        std::cerr << "Semaphore #2 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semB_3, 0, 0) != 0 ) {
        std::cerr << "Semaphore #3 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semB_3, 0, 0) != 0 ) {
        std::cerr << "Semaphore #4 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semI, 0, 1) != 0 ) {
        std::cerr << "Semaphore #5 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semK, 0, 0) != 0 ) {
        std::cerr << "Semaphore #6 init failed" << std::endl;
        return 1;
    }
    if ( sem_init(&semM, 0, 0) != 0 ) {
        std::cerr << "Semaphore #7 init failed" << std::endl;
        return 1;
    }
    
    // start the first thread
    err = pthread_create(&tid[0], NULL, thread_a, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    err = pthread_create(&tid[1], NULL, thread_b, NULL);
    if (err != 0)
        std::cerr << "Can't create thread. Error: " << strerror(err) << std::endl;
    
    // ... and wait for it to finish
    pthread_join(tid[0], NULL);
    pthread_join(tid[4], NULL);
    
    // free resources
    pthread_mutex_destroy(&lock);
    sem_destroy(&semA);
    sem_destroy(&semB_1);
    sem_destroy(&semB_2);
    sem_destroy(&semB_3);
    sem_destroy(&semE);
    sem_destroy(&semI);
    sem_destroy(&semK);
    sem_destroy(&semM);
    std::cout << std::endl;
    // success
    return 0;
}
