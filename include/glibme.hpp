#ifndef GLIBME_HPP
#define GLIBME_HPP

#include <cstddef>
#include <cstdio>

namespace glibme {

struct div_t {
  int quot;
  int rem;
};

struct ldiv_t {
  long quot;
  long rem;
};

struct lldiv_t {
  long long quot;
  long long rem;
};

std::size_t strlen(const char *s);
std::size_t strnlen(const char *s, std::size_t maxlen);

int strcmp(const char *lhs, const char *rhs);
int strncmp(const char *lhs, const char *rhs, std::size_t n);
int strcasecmp(const char *lhs, const char *rhs);
int strncasecmp(const char *lhs, const char *rhs, std::size_t n);

char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, std::size_t n);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, std::size_t n);
char *strdup(const char *s);
char *strndup(const char *s, std::size_t n);
std::size_t strcspn(const char *s, const char *reject);
std::size_t strspn(const char *s, const char *accept);
char *strpbrk(const char *s, const char *accept);
char *strrchr(const char *s, int c);
char *strchr(const char *s, int c);
char *strcasestr(const char *haystack, const char *needle);
char *strstr(const char *haystack, const char *needle);

void *memset(void *s, int c, std::size_t n);
void *memcpy(void *dest, const void *src, std::size_t n);
void *memmove(void *dest, const void *src, std::size_t n);
void *memchr(const void *s, int c, std::size_t n);
int memcmp(const void *lhs, const void *rhs, std::size_t n);
char *strerror(int errnum);

int puts(const char *s);
int putchar(int ch);
int fputc(int ch, std::FILE *stream);
int fputs(const char *s, std::FILE *stream);
void perror(const char *s);

int getchar(void);

int rand(void);
void srand(unsigned int seed);
int atoi(const char *nptr);
long atol(const char *nptr);
long long atoll(const char *nptr);
int abs(int n);
long labs(long n);
long long llabs(long long n);
div_t div(int numer, int denom);
ldiv_t ldiv(long numer, long denom);
lldiv_t lldiv(long long numer, long long denom);

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
