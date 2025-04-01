#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int trailing_whitespace(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    char temp_filename[] = "fileXXXXXX";
    int temp_fd = mkstemp(temp_filename);
    if (temp_fd == -1) {
        perror("Error creating temporary file");
        fclose(file);
        return -1;
    }

    FILE *temp_file = fdopen(temp_fd, "w");
    if (!temp_file) {
        perror("Error opening temporary file");
        close(temp_fd);
        remove(temp_filename);
        fclose(file);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *end = line + strlen(line) - 1;
        while (end > line && (*end == ' ' || *end == '\t' || *end == '\n')) {
            *end-- = '\0';
        }
        fprintf(temp_file, "%s\n", line);
    }

    fclose(file);
    fclose(temp_file);

    if (rename(temp_filename, filename) != 0) {
        perror("Error replacing original file");
        remove(temp_filename);
        return -1;
    }

    return 0;
}

