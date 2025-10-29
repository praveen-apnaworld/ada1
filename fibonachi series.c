#include <stdio.h>
#include <time.h>

#define MAX 1000
int memo[MAX];  // for memoization

// ---------- 4a. Recursive ----------
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

// ---------- 4b. Iterative ----------
int fib_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// ---------- 4c. DP Top Down ----------
void init_memo() {
    for (int i = 0; i < MAX; i++) memo[i] = -1;
}
int fib_topdown(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_topdown(n-1) + fib_topdown(n-2);
    return memo[n];
}

// ---------- 4d. DP Bottom Up ----------
int fib_bottomup(int n) {
    if (n <= 1) return n;
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

// ---------- Main Driver ----------
int main() {
    int n;
    printf("Enter n (Fibonacci term): ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time;

    // Recursive
    start = clock();
    int rec = fib_recursive(n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Recursive: F(%d) = %d, Time = %f sec\n", n, rec, cpu_time);

    // Iterative
    start = clock();
    int it = fib_iterative(n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Iterative: F(%d) = %d, Time = %f sec\n", n, it, cpu_time);

    // Top Down DP
    init_memo();
    start = clock();
    int td = fib_topdown(n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("DP Top Down: F(%d) = %d, Time = %f sec\n", n, td, cpu_time);

    // Bottom Up DP
    start = clock();
    int bu = fib_bottomup(n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("DP Bottom Up: F(%d) = %d, Time = %f sec\n", n, bu, cpu_time);

    return 0;
}

