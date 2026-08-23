#include "glibme.hpp"
#include <cerrno>
#include <functional>

namespace glibme {

std::size_t strlen(const char *s)
{
  std::size_t len = 0;
  while (*s != '\0') {
    ++len;
    ++s;
  }
  return len;
}

std::size_t strnlen(const char *s, std::size_t maxlen)
{
  std::size_t len = 0;
  while (*s != '\0' && len < maxlen) {
    ++len;
    ++s;
  }
  return len;
}

int strcmp(const char *lhs, const char *rhs)
{
  (void)lhs;
  (void)rhs;
  return 0;
}

int strncmp(const char *lhs, const char *rhs, std::size_t n)
{
  (void)lhs;
  (void)rhs;
  (void)n;
  return 0;
}

char *strcpy(char *dest, const char *src)
{
  (void)src;
  return dest;
}

char *strncpy(char *dest, const char *src, std::size_t n)
{
  (void)src;
  (void)n;
  return dest;
}

char *strcat(char *dest, const char *src)
{
  (void)src;
  return dest;
}

char *strncat(char *dest, const char *src, std::size_t n)
{
  (void)src;
  (void)n;
  return dest;
}

void *memset(void *s, int c, std::size_t n)
{
  unsigned char *ss = static_cast<unsigned char *>(s);
  for (std::size_t i = 0; i < n; ++i) {
    ss[i] = static_cast<unsigned char>(c);
  }
  return s;
}

void *memcpy(void *dest, const void *src, std::size_t n)
{
  unsigned char *dest_ptr = static_cast<unsigned char *>(dest);
  const unsigned char *src_ptr = static_cast<const unsigned char *>(src);

  for (std::size_t i = 0; i < n; ++i) {
    dest_ptr[i] = src_ptr[i];
  }
  return dest;
}

void *memmove(void *dest, const void *src, std::size_t n)
{
  auto *dest_ptr = static_cast<unsigned char *>(dest);
  auto *src_ptr = static_cast<const unsigned char *>(src);

  if (std::less<const void *>{}(src, dest)) {
    // [0,1,2,3] src
    //   [0,1,2,3] dest
    for (std::size_t i = n; i > 0; --i) {
      dest_ptr[i - 1] = src_ptr[i - 1];
    }
  } else {
    //     [0,1,2,3] src
    //   [0,1,2,3] dest
    for (std::size_t i = 0; i < n; ++i) {
      dest_ptr[i] = src_ptr[i];
    }
  }

  return dest;
}

void *memchr(const void *s, int c, std::size_t n)
{
  unsigned char v = static_cast<unsigned char>(c);

  const unsigned char *vs = static_cast<const unsigned char *>(s);
  for (std::size_t i = 0; i < n; ++i) {
    if (vs[i] == v) {
      return const_cast<void *>(static_cast<const void *>(vs + i));
    }
  }
  return nullptr;
}

int memcmp(const void *lhs, const void *rhs, std::size_t n)
{
  (void)lhs;
  (void)rhs;
  (void)n;
  return 0;
}

char *strerror(int errnum)
{
  switch (errnum) {
  case EINVAL:
    return const_cast<char *>("Invalid argument");
  case ENOENT:
    return const_cast<char *>("No such file or directory");
  case EACCES:
    return const_cast<char *>("Permission denied");
  default:
    return const_cast<char *>("Unknown error");
  }
}

} // namespace glibme
