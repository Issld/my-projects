#include <windows.h>

#define NUMBER_OF_THREADS 11

// threads
HANDLE threads[NUMBER_OF_THREADS];
// critical section lock.
HANDLE lock;
// semaphores for sequential threads.
HANDLE semB, semB_allow, semC, semD, semH;

void computation()
{
    auto delay = uni_delay(rng);
    auto chance = uni_chance(rng);
    sleep_ms(delay);
    if (chance < 10) {
        sleep_ms(delay);
    }
}

const char* unsynchronized_threads()
{
    return "fhi";
}

const char* sequential_threads()
{
    return "bcd";
}

DWORD WINAPI thread_a(LPVOID);
DWORD WINAPI thread_b(LPVOID);
DWORD WINAPI thread_c(LPVOID);
DWORD WINAPI thread_d(LPVOID);
DWORD WINAPI thread_e(LPVOID);
DWORD WINAPI thread_f(LPVOID);
DWORD WINAPI thread_g(LPVOID);
DWORD WINAPI thread_h(LPVOID);
DWORD WINAPI thread_i(LPVOID);
DWORD WINAPI thread_k(LPVOID);

DWORD thread_id;


DWORD WINAPI thread_a(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "a" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return TRUE;
}

DWORD WINAPI thread_b(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[0], INFINITE);
    ReleaseSemaphore(semB_allow, 1, NULL);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semB, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semC, 1, NULL);
    }
    WaitForSingleObject(threads[3], INFINITE);
    return TRUE;
}

DWORD WINAPI thread_c(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "c" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(semB_allow, INFINITE);
    threads[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_d, NULL, 0, &thread_id);
    if (threads[3] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semC, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "c" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semD, 1, NULL);
    }
    WaitForSingleObject(threads[1], INFINITE);
    threads[4] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_e, NULL, 0, &thread_id);
    if (threads[4] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "c" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[4], INFINITE);
    threads[5] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_f, NULL, 0, &thread_id);
    if (threads[5] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    threads[6] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_h, NULL, 0, &thread_id);
    if (threads[6] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    threads[7] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_i, NULL, 0, &thread_id);
    if (threads[7] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    return TRUE;
}

DWORD WINAPI thread_d(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semD, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semB, 1, NULL);
    }
    return TRUE;
}

DWORD WINAPI thread_e(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "e" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return TRUE;
}

DWORD WINAPI thread_f(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "f" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return TRUE;
}

DWORD WINAPI thread_h(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[5], INFINITE);
    ReleaseSemaphore(semH, 1, NULL);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[8], INFINITE);
    return TRUE;
}

DWORD WINAPI thread_i(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(semH, INFINITE);
    threads[8] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_g, NULL, 0, &thread_id);
    if (threads[8] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[6], INFINITE);
    threads[9] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_k, NULL, 0, &thread_id);
    if (threads[9] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[9], INFINITE);
    return TRUE;
}

DWORD WINAPI thread_g(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "g" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return TRUE;
}

DWORD WINAPI thread_k(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "k" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return TRUE;
}

int main()
{
    lock = CreateMutex(NULL, // default security attributes
        FALSE,               // initially not owned
        NULL);               // unnamed mutex

    if (lock == NULL) {
        printf("CreateMutex error: %d\n", GetLastError());
        return 1;
    }

    std::cout << "Не синхронизированные потоки" << unsynchronized_threads << std::endl;
    std::cout << "Cинхронизированные потоки" << sequential_threads << std::endl;

    semB = CreateSemaphore(NULL, 1, 1, NULL);
    if (semB == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semB_allow = CreateSemaphore(NULL, 0, 1, NULL);
    if (semB_allow == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semC = CreateSemaphore(NULL, 0, 1, NULL);
    if (semC == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semD = CreateSemaphore(NULL, 0, 1, NULL);
    if (semD == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semH = CreateSemaphore(NULL, 0, 1, NULL);
    if (semH == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }

    threads[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_a, NULL, 0, &thread_id);
    if (threads[0] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return 1;
    };
    threads[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_b, NULL, 0, &thread_id);
    if (threads[1] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return 1;
    };
    threads[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_c, NULL, 0, &thread_id);
    if (threads[2] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return 1;
    };

    WaitForSingleObject(threads[2], INFINITE);
    WaitForSingleObject(threads[7], INFINITE);

    CloseHandle(lock);
    return 0;
}
