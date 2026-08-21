#ifndef GLIBME_H
#define GLIBME_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t glibme_strlen(const char *s);
size_t glibme_strnlen(const char *s, size_t maxlen);

int glibme_strcmp(const char *lhs, const char *rhs);
int glibme_strncmp(const char *lhs, const char *rhs, size_t n);

char *glibme_strcpy(char *dest, const char *src);
char *glibme_strncpy(char *dest, const char *src, size_t n);
char *glibme_strcat(char *dest, const char *src);
char *glibme_strncat(char *dest, const char *src, size_t n);

void *glibme_memset(void *s, int c, size_t n);
void *glibme_memcpy(void *dest, const void *src, size_t n);
void *glibme_memchr(const void *s, int c, size_t n);
int glibme_memcmp(const void *lhs, const void *rhs, size_t n);

int glibme_isalpha(int c);
int glibme_isdigit(int c);
int glibme_isalnum(int c);
int glibme_isspace(int c);
int glibme_isxdigit(int c);
int glibme_tolower(int c);
int glibme_toupper(int c);

#ifdef __cplusplus
}
#endif

#endif
