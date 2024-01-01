#ifndef STRINGS
#define STRINGS

#include <stdio.h>

#define LEADING 1
#define TRAILING 2
#define LT_TRIM (LEADING | TRAILING)

extern char * trim_l(char **str);
extern char * trim(char **str);
extern char * trim_t(char **str);
extern char * trim_c(char **str, char c, int );
extern char ** tokenize(char **str, char c);

extern char * lines(char **string);
extern void chop_by_delim(char **string, char *delim);
extern char * read_file_as_string(const char *filepath);
extern char ** tokenize_by_delims(char **string, char *delim, char **tokens);

#endif // !STRINGS
