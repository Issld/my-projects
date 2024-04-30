#include <windows.h>

#define NUMBER_OF_THREADS 11

// threads
HANDLE threads[NUMBER_OF_THREADS];
// critical section lock.
HANDLE lock;
// semaphores for sequential threads.
HANDLE semB, semF, semH_allow, semH, semI_allow, semI_allow_2, semI_allow_3, semI, semK;

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
    return "bcdi";
}

const char* sequential_threads()
{
    return "khi";
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
DWORD WINAPI thread_m(LPVOID);

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
    ReleaseSemaphore(semB, 1, NULL);
    WaitForSingleObject(semI_allow, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[3], INFINITE);
    ReleaseSemaphore(semB, 1, NULL);
    WaitForSingleObject(semI_allow, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(semH_allow, INFINITE);
    ReleaseSemaphore(semB, 1, NULL);
    WaitForSingleObject(semI_allow, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(semH_allow, INFINITE);
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
    WaitForSingleObject(semB, INFINITE);
    ReleaseSemaphore(semI_allow, 1, NULL);
    threads[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_c, NULL, 0, &thread_id);
    if (threads[2] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    threads[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_d, NULL, 0, &thread_id);
    if (threads[3] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(semB, INFINITE);
    ReleaseSemaphore(semI_allow, 1, NULL);
    threads[4] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_e, NULL, 0, &thread_id);
    if (threads[4] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    threads[5] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_f, NULL, 0, &thread_id);
    if (threads[5] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    threads[7] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_h, NULL, 0, &thread_id);
    if (threads[7] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    ReleaseSemaphore(semI_allow, 1, NULL);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(semB, INFINITE);
    ReleaseSemaphore(semI_allow_2, 1, NULL);
    threads[6] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_g, NULL, 0, &thread_id);
    if (threads[6] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    ReleaseSemaphore(semI_allow, 1, NULL);
    ReleaseSemaphore(semI_allow_2, 1, NULL);
    ReleaseSemaphore(semI_allow_3, 1, NULL);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[1], INFINITE);
    threads[9] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_k, NULL, 0, &thread_id);
    if (threads[9] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semI, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semK, 1, NULL);
    }
    WaitForSingleObject(threads[7], INFINITE);
    threads[10] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_m, NULL, 0, &thread_id);
    if (threads[10] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    WaitForSingleObject(threads[10], INFINITE);
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
    return TRUE;
}

DWORD WINAPI thread_d(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[2], INFINITE);
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
    WaitForSingleObject(threads[4], INFINITE);
    ReleaseSemaphore(semF, 1, NULL);
    WaitForSingleObject(semI_allow_2, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "f" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[6], INFINITE);
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
    WaitForSingleObject(semF, INFINITE);
    ReleaseSemaphore(semH_allow, 1, NULL);
    WaitForSingleObject(semI_allow_3, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[5], INFINITE);
    ReleaseSemaphore(semH_allow, 1, NULL);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semH, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semI, 1, NULL);
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
        WaitForSingleObject(semK, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "k" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semH, 1, NULL);
    }
    return TRUE;
}

DWORD WINAPI thread_m(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "m" << std::flush;
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

    semB = CreateSemaphore(NULL, 0, 1, NULL);
    if (semB == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semF = CreateSemaphore(NULL, 0, 1, NULL);
    if (semF == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semH_allow = CreateSemaphore(NULL, 0, 1, NULL);
    if (semH_allow == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semH = CreateSemaphore(NULL, 0, 1, NULL);
    if (semH == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semI_allow = CreateSemaphore(NULL, 0, 1, NULL);
    if (semI_allow == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semI_allow_2 = CreateSemaphore(NULL, 0, 1, NULL);
    if (semI_allow_2 == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semI_allow_3 = CreateSemaphore(NULL, 0, 1, NULL);
    if (semI_allow_3 == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semI = CreateSemaphore(NULL, 0, 1, NULL);
    if (semI == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semK = CreateSemaphore(NULL, 1, 1, NULL);
    if (semK == NULL) {
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
    threads[8] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_i, NULL, 0, &thread_id);
    if (threads[8] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return 1;
    };

    WaitForSingleObject(threads[8], INFINITE);

    CloseHandle(lock);
    return 0;
}
