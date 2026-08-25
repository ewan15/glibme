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
  while (*lhs != '\0' && *rhs != '\0') {
    unsigned char l = (unsigned char)*lhs;
    unsigned char r = (unsigned char)*rhs;

    if (l != r)
      return l < r ? -1 : 1;

    ++lhs;
    ++rhs;
  }
  unsigned char l = (unsigned char)*lhs;
  unsigned char r = (unsigned char)*rhs;
  return l < r ? -1 : l == r ? 0 : 1;
}

int strncmp(const char *lhs, const char *rhs, std::size_t n)
{
  while (n > 0) {
    unsigned char l = (unsigned char)*lhs;
    unsigned char r = (unsigned char)*rhs;

    if (l != r)
      return l < r ? -1 : 1;

    if (l == '\0')
      return 0;

    ++lhs;
    ++rhs;
    --n;
  }
  return 0;
}

int strcasecmp(const char *lhs, const char *rhs)
{
  while (*lhs != '\0' && *rhs != '\0') {
    unsigned char l = tolower((unsigned char)(*lhs));
    unsigned char r = tolower((unsigned char)(*rhs));

    if (l != r)
      return l < r ? -1 : 1;

    ++lhs;
    ++rhs;
  }
  unsigned char l = tolower((unsigned char)(*lhs));
  unsigned char r = tolower((unsigned char)(*rhs));
  return l < r ? -1 : l == r ? 0 : 1;
}

int strncasecmp(const char *lhs, const char *rhs, std::size_t n)
{
  while (n > 0) {
    unsigned char l = tolower((unsigned char)(*lhs));
    unsigned char r = tolower((unsigned char)(*rhs));

    if (l != r)
      return l < r ? -1 : 1;

    if (l == '\0')
      return 0;

    ++lhs;
    ++rhs;
    --n;
  }
  return 0;
}

char *strcpy(char *dest, const char *src)
{
  char *original = dest;
  while (*src != '\0') {
    *dest = *src;
    ++src;
    ++dest;
  }
  *dest = '\0';
  return original;
}

char *strncpy(char *dest, const char *src, std::size_t n)
{
  char *original = dest;
  while (*src != '\0' && n > 0) {
    *dest = *src;
    ++src;
    ++dest;
    --n;
  }

  while (n > 0) {
    *dest = '\0';
    ++dest;
    --n;
  }

  return original;
}

char *strcat(char *dest, const char *src)
{
  const auto dest_size = strlen(dest);
  strcpy(dest + dest_size, src);
  return dest;
}

char *strncat(char *dest, const char *src, std::size_t n)
{
  char *original = dest;
  const auto dest_len = strlen(dest);
  dest = dest + dest_len;
  while (*src != '\0' && n > 0) {
    *dest = *src;
    ++dest;
    ++src;
    --n;
  }
  *dest = '\0';
  return original;
}

char *strdup(const char *s)
{
  (void)s;
  return nullptr;
}

char *strndup(const char *s, std::size_t n)
{
  (void)s;
  (void)n;
  return nullptr;
}

std::size_t strcspn(const char *s, const char *reject)
{
  (void)s;
  (void)reject;
  return 0;
}

std::size_t strspn(const char *s, const char *accept)
{
  (void)s;
  (void)accept;
  return 0;
}

char *strpbrk(const char *s, const char *accept)
{
  (void)s;
  (void)accept;
  return nullptr;
}

char *strrchr(const char *s, int c)
{
  (void)s;
  (void)c;
  return nullptr;
}

char *strchr(const char *s, int c)
{
  (void)s;
  (void)c;
  return nullptr;
}

char *strcasestr(const char *haystack, const char *needle)
{
  (void)haystack;
  (void)needle;
  return nullptr;
}

char *strstr(const char *haystack, const char *needle)
{
  (void)haystack;
  (void)needle;
  return nullptr;
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
