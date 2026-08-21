#include "glibme.hpp"

namespace glibme {

std::size_t strlen(const char *s)
{
  const char *p = s;

  while (*p != '\0') {
    ++p;
  }

  return static_cast<std::size_t>(p - s);
}

std::size_t strnlen(const char *s, std::size_t maxlen)
{
  std::size_t len = 0;

  while (len < maxlen && s[len] != '\0') {
    ++len;
  }

  return len;
}

int strcmp(const char *lhs, const char *rhs)
{
  while (*lhs != '\0' && *lhs == *rhs) {
    ++lhs;
    ++rhs;
  }

  return static_cast<unsigned char>(*lhs) - static_cast<unsigned char>(*rhs);
}

int strncmp(const char *lhs, const char *rhs, std::size_t n)
{
  std::size_t i = 0;

  while (i < n) {
    unsigned char left = static_cast<unsigned char>(lhs[i]);
    unsigned char right = static_cast<unsigned char>(rhs[i]);

    if (left != right || left == '\0') {
      return left - right;
    }

    ++i;
  }

  return 0;
}

char *strcpy(char *dest, const char *src)
{
  char *start = dest;

  while ((*dest++ = *src++) != '\0') {
  }

  return start;
}

char *strncpy(char *dest, const char *src, std::size_t n)
{
  std::size_t i = 0;

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

char *strcat(char *dest, const char *src)
{
  strcpy(dest + strlen(dest), src);
  return dest;
}

char *strncat(char *dest, const char *src, std::size_t n)
{
  char *write = dest + strlen(dest);
  std::size_t i = 0;

  while (i < n && src[i] != '\0') {
    write[i] = src[i];
    ++i;
  }

  write[i] = '\0';
  return dest;
}

void *memset(void *s, int c, std::size_t n)
{
  auto *bytes = static_cast<unsigned char *>(s);
  std::size_t i = 0;

  while (i < n) {
    bytes[i] = static_cast<unsigned char>(c);
    ++i;
  }

  return s;
}

void *memcpy(void *dest, const void *src, std::size_t n)
{
  auto *out = static_cast<unsigned char *>(dest);
  const auto *in = static_cast<const unsigned char *>(src);
  std::size_t i = 0;

  while (i < n) {
    out[i] = in[i];
    ++i;
  }

  return dest;
}

void *memchr(const void *s, int c, std::size_t n)
{
  const auto *bytes = static_cast<const unsigned char *>(s);
  unsigned char needle = static_cast<unsigned char>(c);
  std::size_t i = 0;

  while (i < n) {
    if (bytes[i] == needle) {
      return const_cast<unsigned char *>(bytes + i);
    }
    ++i;
  }

  return nullptr;
}

int memcmp(const void *lhs, const void *rhs, std::size_t n)
{
  const auto *left = static_cast<const unsigned char *>(lhs);
  const auto *right = static_cast<const unsigned char *>(rhs);
  std::size_t i = 0;

  while (i < n) {
    if (left[i] != right[i]) {
      return left[i] - right[i];
    }
    ++i;
  }

  return 0;
}

} // namespace glibme
