#include "glibme.h"

size_t glibme_strlen(const char *s)
{
  const char *p = s;

  while (*p != '\0') {
    ++p;
  }

  return (size_t)(p - s);
}

size_t glibme_strnlen(const char *s, size_t maxlen)
{
  size_t len = 0;

  while (len < maxlen && s[len] != '\0') {
    ++len;
  }

  return len;
}

int glibme_strcmp(const char *lhs, const char *rhs)
{
  while (*lhs != '\0' && *lhs == *rhs) {
    ++lhs;
    ++rhs;
  }

  return (unsigned char)*lhs - (unsigned char)*rhs;
}

int glibme_strncmp(const char *lhs, const char *rhs, size_t n)
{
  size_t i = 0;

  while (i < n) {
    unsigned char left = (unsigned char)lhs[i];
    unsigned char right = (unsigned char)rhs[i];

    if (left != right || left == '\0') {
      return left - right;
    }

    ++i;
  }

  return 0;
}

char *glibme_strcpy(char *dest, const char *src)
{
  char *start = dest;

  while ((*dest++ = *src++) != '\0') {
  }

  return start;
}

char *glibme_strncpy(char *dest, const char *src, size_t n)
{
  size_t i = 0;

  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    ++i;
  }

  while (i < n) {
    dest[i] = '\0';
    ++i;
  }

  return dest;
}

char *glibme_strcat(char *dest, const char *src)
{
  glibme_strcpy(dest + glibme_strlen(dest), src);
  return dest;
}

char *glibme_strncat(char *dest, const char *src, size_t n)
{
  char *write = dest + glibme_strlen(dest);
  size_t i = 0;

  while (i < n && src[i] != '\0') {
    write[i] = src[i];
    ++i;
  }

  write[i] = '\0';
  return dest;
}

void *glibme_memset(void *s, int c, size_t n)
{
  unsigned char *bytes = s;
  size_t i = 0;

  while (i < n) {
    bytes[i] = (unsigned char)c;
    ++i;
  }

  return s;
}

void *glibme_memcpy(void *dest, const void *src, size_t n)
{
  unsigned char *out = dest;
  const unsigned char *in = src;
  size_t i = 0;

  while (i < n) {
    out[i] = in[i];
    ++i;
  }

  return dest;
}

void *glibme_memchr(const void *s, int c, size_t n)
{
  const unsigned char *bytes = s;
  unsigned char needle = (unsigned char)c;
  size_t i = 0;

  while (i < n) {
    if (bytes[i] == needle) {
      return (void *)(bytes + i);
    }
    ++i;
  }

  return 0;
}

int glibme_memcmp(const void *lhs, const void *rhs, size_t n)
{
  const unsigned char *left = lhs;
  const unsigned char *right = rhs;
  size_t i = 0;

  while (i < n) {
    if (left[i] != right[i]) {
      return left[i] - right[i];
    }
    ++i;
  }

  return 0;
}
