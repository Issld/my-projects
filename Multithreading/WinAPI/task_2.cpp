#include <windows.h>

#define NUMBER_OF_THREADS 11

// threads
HANDLE threads[NUMBER_OF_THREADS];
// critical section lock.
HANDLE lock;
// semaphores for sequential threads.
HANDLE semB, semD, semE, semF_allow, semF, semG, semH_allow, semH_allow_2, semH, semK;

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
    return "bcd";
}

const char* sequential_threads()
{
    return "fgh";
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
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
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
    WaitForSingleObject(threads[1], INFINITE);
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
    WaitForSingleObject(semB, INFINITE);
    threads[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_c, NULL, 0, &thread_id);
    if (threads[2] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[2], INFINITE);
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
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(semD, 1, NULL);
    WaitForSingleObject(threads[4], INFINITE);
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
    WaitForSingleObject(semF_allow, INFINITE);
    WaitForSingleObject(semH_allow, INFINITE);
    threads[6] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_g, NULL, 0, &thread_id);
    if (threads[6] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    ReleaseSemaphore(semE, 1, NULL);
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
    ReleaseSemaphore(semF_allow, 1, NULL);
    WaitForSingleObject(semD, INFINITE);
    WaitForSingleObject(semE, INFINITE);
    WaitForSingleObject(semH_allow_2, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semF, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "f" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semG, 1, NULL);
    }
    return TRUE;
}

DWORD WINAPI thread_g(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semG, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "g" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semH, 1, NULL);
    }
    WaitForSingleObject(threads[5], INFINITE);
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
    ReleaseSemaphore(semH_allow, 1, NULL);
    ReleaseSemaphore(semH_allow_2, 1, NULL);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(semH, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semF, 1, NULL);
    }
    WaitForSingleObject(threads[6], INFINITE);
    threads[8] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_i, NULL, 0, &thread_id);
    if (threads[8] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    threads[9] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_k, NULL, 0, &thread_id);
    if (threads[9] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    WaitForSingleObject(threads[8], INFINITE);
    ReleaseSemaphore(semH_allow, 1, NULL);
    threads[10] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_m, NULL, 0, &thread_id);
    if (threads[10] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return FALSE;
    };
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
    WaitForSingleObject(semK, INFINITE);
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
    ReleaseSemaphore(semK, 1, NULL);
    WaitForSingleObject(semH_allow, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "k" << std::flush;
        ReleaseMutex(lock);
        computation();
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
    WaitForSingleObject(threads[9], INFINITE);
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
    semD = CreateSemaphore(NULL, 0, 1, NULL);
    if (semD == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semE = CreateSemaphore(NULL, 0, 1, NULL);
    if (semE == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semF_allow = CreateSemaphore(NULL, 0, 1, NULL);
    if (semF_allow == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semF = CreateSemaphore(NULL, 1, 1, NULL);
    if (semF == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semG = CreateSemaphore(NULL, 0, 1, NULL);
    if (semG == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semH_allow = CreateSemaphore(NULL, 0, 1, NULL);
    if (semH_allow == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semH_allow_2 = CreateSemaphore(NULL, 0, 1, NULL);
    if (semH_allow_2 == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semH = CreateSemaphore(NULL, 0, 1, NULL);
    if (semH == NULL) {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }
    semK = CreateSemaphore(NULL, 0, 1, NULL);
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
    threads[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_d, NULL, 0, &thread_id);
    if (threads[3] == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        return 1;
    };

    WaitForSingleObject(threads[3], INFINITE);
    WaitForSingleObject(threads[7], INFINITE);
    WaitForSingleObject(threads[10], INFINITE);

    CloseHandle(lock);
    return 0;
}
