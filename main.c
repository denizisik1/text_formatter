#include <stdio.h>
#include <stdlib.h>
#include "trailing_whitespace.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (trailing_whitespace(argv[1]) != 0) {
        fprintf(stderr, "Error processing file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
