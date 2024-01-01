#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./strings.h"

char * trim_l(char **str) {
    return trim_c(str, ' ', LEADING);
}

char * trim_t(char **str) {
    return trim_c(str, ' ', TRAILING);
}

char * trim(char **str) {
    char *leading_trimmed = trim_l(str);
    return trim_t(&leading_trimmed);
}

char * trim_c(char **str, char c, int trim_type) {
    if (str == NULL || *str == NULL) {
        return NULL;
    }
    char *inner_str = *str;
    if (trim_type & LEADING) {
        while (inner_str != NULL && *inner_str != '\0' && *inner_str == c) {
            inner_str++;
        }
        inner_str--;
        *inner_str = '\0';
        return inner_str + 1;
    }

    if (trim_type & TRAILING) {
        size_t len = strlen(inner_str);
        for (int i = len - 1; i >= 0 && inner_str[i] == c; --i) {
            inner_str[i] = '\0';
        }
        return inner_str;
    }
    return NULL;
}


char * lines(char **string) {
    char *line = strsep(string, "\n");
    if (line != NULL && line[0] == '\n') {
        return NULL;
    } else if (strlen(line) == 0) {
        return NULL;
    }
    return line;
}

void chop_by_delim(char **string, char *delim) {
    strsep(string, delim);
}

char ** tokenize_by_delims(char **string, char *delim, char **tokens) {
    char *token = NULL;
    for (size_t i = 0; (token = strsep(string, delim)) != NULL; ++i) {
        tokens[i] = token;
    }
    return tokens;
}

char * read_file_as_string(const char *filepath) {
    FILE *f = fopen(filepath, "r");
    if (f == NULL) {
        perror("ERROR");
        return NULL;
    }
    int ret = fseek(f, 0, SEEK_END);
    if (ret != 0) {
        fprintf(stderr, "ERROR: fseek failed\n");
        return NULL;
    }
    size_t filesize = ftell(f);
    rewind(f);
    char *input = malloc(filesize + 1);
    if (input == NULL) {
        fprintf(stderr, "ERROR: Unable to alloc memmory");
        return NULL;
    }
    ret = fread(input, filesize, 1, f);
    if (!feof(f) && ferror(f)) {
        perror("ERROR: ");
        return NULL;
    }
    fclose(f);
    return input;
}
