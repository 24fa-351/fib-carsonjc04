#include <stdio.h>
#include <stdlib.h>

// Recursive Fibonacci function
int fib_recursive(int n) {
   if(n == 0)
      return 0
   else if(n == 1)
      return 1;
   else
      return (fib_recursive(n-1) + fib_recursive(n-2));
}
//Ex: 8th Fibonacci: 8 == 0 NO, 8 == 1 NO, therefore ((8-1) + (8 -2)) = 13

// Iterative Fibonacci function
int fib_iterative(int n) {
   int i, term_1 = 0, term_2 = 1, nextTerm;
   for (i = 1; i <= n; ++i) {
      printf("%d, ", term_1);
      nextTerm = term_1 + term_2;
      term_1 = term_2;
      term_2 = nextTerm
      return nextTerm
   }
}
//Begins at 1 and will add the next term until it is equal to n terms.
//Ex: 8th Fibonacci: term_1 + term_2 = 1, i < n, therefore loops again.
//Will repeat loop 8 times until the correct number of sequences occurs. 
int main(int argc, char *argv[]) {
    int arg_value = atoi(argv[1]);

    FILE *file = fopen(argv[3], "r");
    int file_value;
    fscanf(file, "%d", &file_value);
    fclose(file);

    int N = arg_value + file_value - 1;
   //Takes the first argument value and adds to the file value.
   //Ex: Input 5 = arg_value + file_value = 3. 5 + 3 = 8-1 = 7.
   //Therefore n = 7. 7th Fibonacci Number = 13.
    int result;
    if (argv[2][0] == 'r') {
        result = fib_recursive(N);
    } else {
        result = fib_iterative(N);
    }
   //Checks 2nd Command argument and will use either recursive or iterative to find solution
    // Output the Nth fibonacci sequence
    printf("%d\n", result);

    return 0;
}
