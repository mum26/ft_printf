#include <stdio.h>
#include <stdarg.h>

void print_numbers(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int number = va_arg(args, int);
        printf("%d\n", number);
    }

    va_end(args);
}

int main() {
    print_numbers(8, 10, 20, 30, 8, 9, 10, 114, 514);
    return 0;
}
