#include "glibme.hpp"
#include <cstddef>
#include <unistd.h>

namespace glibme {

static bool write_all(int fd, const char *s, std::size_t size)
{
  while (size > 0) {
    ssize_t amount_written = write(fd, s, size);
    if (amount_written <= 0) {
      return false;
    }

    const auto amount_written_size_t = static_cast<std::size_t>(amount_written);
    s += amount_written_size_t;
    size -= amount_written_size_t;
  }
  return true;
}

int puts(const char *s)
{
  const char *p = s;
  while (*p != '\0') {
    ++p;
  }
  const auto size = static_cast<std::size_t>(p - s);

  if (!write_all(STDOUT_FILENO, s, size)) {
    return -1;
  }

  if (!write_all(STDOUT_FILENO, "\n", 1)) {
    return -1;
  }

  return 0;
}

int putchar(int ch)
{
  char chr = static_cast<char>(ch);

  if (!write_all(STDOUT_FILENO, &chr, 1)) {
    return -1;
  }

  return static_cast<unsigned char>(chr);
}

int getchar(void)
{
  char ch;
  ssize_t amount_read = read(STDIN_FILENO, &ch, 1);
  if (amount_read <= 0) {
    return -1;
  }
  return static_cast<unsigned char>(ch);
}

} // namespace glibme
