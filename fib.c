#include <stdio.h>
#include <stdlib.h>

// Original Recursive Fibonacci function (no changes)
int fib_wrapper_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib_wrapper_recursive(n - 1) + fib_wrapper_recursive(n - 2);
}

// Original Iterative Fibonacci function (no changes)
int fib_wrapper_iterative(int n) {
    int term_1 = 0, term_2 = 1, nextTerm;
    if (n == 0) return term_1;
    if (n == 1) return term_2;

    for (int i = 1; i < n; ++i) {
        nextTerm = term_1 + term_2;
        term_1 = term_2;
        term_2 = nextTerm;
    }
    return term_2;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <integer> <method> <filename>\n", argv[0]);
        return 1;
    }

    int num_from_cli = atoi(argv[1]);
    char method = argv[2][0];
    char *filename = argv[3];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    int num_from_file;
    fscanf(file, "%d", &num_from_file);
    fclose(file);

    int N = num_from_cli + num_from_file;
    int result;

    if (method == 'r') {
        result = fib_wrapper_recursive(N);
    } else if (method == 'i') {
        result = fib_wrapper_iterative(N);
    } else {
        fprintf(stderr, "Error: Method must be 'r' (recursive) or 'i' (iterative)\n");
        return 1;
    }

    printf("Fibonacci number at position %d is %d\n", N, result);

    return 0;
}
