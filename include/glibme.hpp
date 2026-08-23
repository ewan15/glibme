#ifndef GLIBME_HPP
#define GLIBME_HPP

#include <cstddef>

namespace glibme {

std::size_t strlen(const char *s);
std::size_t strnlen(const char *s, std::size_t maxlen);

int strcmp(const char *lhs, const char *rhs);
int strncmp(const char *lhs, const char *rhs, std::size_t n);

char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, std::size_t n);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, std::size_t n);

void *memset(void *s, int c, std::size_t n);
void *memcpy(void *dest, const void *src, std::size_t n);
void *memmove(void *dest, const void *src, std::size_t n);
void *memchr(const void *s, int c, std::size_t n);
int memcmp(const void *lhs, const void *rhs, std::size_t n);

int puts(const char *s);
int putchar(int ch);

int getchar(void);

bool isalpha(int c);
bool isdigit(int c);
bool isalnum(int c);
bool isspace(int c);
bool isxdigit(int c);
bool isprint(int c);
int tolower(int c);
int toupper(int c);

} // namespace glibme

#endif
