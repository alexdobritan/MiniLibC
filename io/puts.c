#include <stdio.h>
#include <unistd.h>
#include <string.h>

int puts(const char *str) {
    int nr_chr = write(1, str, strlen(str));
    if (nr_chr < 0) {
        return -1;
    }
    if (write(1, "\n", 1) == -1) {
        return -1;
    }
    return 1;
}
