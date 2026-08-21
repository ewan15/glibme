#include "glibme.hpp"

#include <assert.h>
#include <cstddef>

static void test_strings(void)
{
  char buffer[32];
  char padded[8];

  assert(glibme::strlen("glibme") == 6);
  assert(glibme::strnlen("glibme", 3) == 3);
  assert(glibme::strnlen("glibme", 10) == 6);

  assert(glibme::strcmp("abc", "abc") == 0);
  assert(glibme::strcmp("abc", "abd") < 0);
  assert(glibme::strncmp("abcdef", "abcxyz", 3) == 0);
  assert(glibme::strncmp("abcdef", "abcxyz", 4) < 0);

  assert(glibme::strcpy(buffer, "glib") == buffer);
  assert(glibme::strcmp(buffer, "glib") == 0);

  assert(glibme::strcat(buffer, "me") == buffer);
  assert(glibme::strcmp(buffer, "glibme") == 0);

  assert(glibme::strncpy(padded, "hi", sizeof(padded)) == padded);
  assert(padded[0] == 'h');
  assert(padded[1] == 'i');
  assert(padded[2] == '\0');

  buffer[0] = '\0';
  assert(glibme::strncat(buffer, "abcdef", 3) == buffer);
  assert(glibme::strcmp(buffer, "abc") == 0);
}

static void test_memory(void)
{
  unsigned char buffer[8];
  unsigned char copy[8];

  assert(glibme::memset(buffer, 0xab, sizeof(buffer)) == buffer);
  assert(buffer[0] == 0xab);
  assert(buffer[7] == 0xab);

  assert(glibme::memcpy(copy, buffer, sizeof(buffer)) == copy);
  assert(glibme::memcmp(copy, buffer, sizeof(buffer)) == 0);

  copy[3] = 0xcd;
  assert(glibme::memchr(copy, 0xcd, sizeof(copy)) == copy + 3);
  assert(glibme::memchr(copy, 0xef, sizeof(copy)) == nullptr);
  assert(glibme::memcmp(copy, buffer, sizeof(buffer)) > 0);
}

static void test_ctype(void)
{
  assert(glibme::isalpha('a'));
  assert(glibme::isalpha('Z'));
  assert(!glibme::isalpha('4'));

  assert(glibme::isdigit('9'));
  assert(!glibme::isdigit('x'));

  assert(glibme::isalnum('q'));
  assert(glibme::isalnum('7'));
  assert(!glibme::isalnum('_'));

  assert(glibme::isspace('\n'));
  assert(glibme::isspace(' '));
  assert(!glibme::isspace('a'));

  assert(glibme::isxdigit('f'));
  assert(glibme::isxdigit('F'));
  assert(!glibme::isxdigit('g'));

  assert(glibme::tolower('A') == 'a');
  assert(glibme::tolower('a') == 'a');
  assert(glibme::toupper('z') == 'Z');
  assert(glibme::toupper('Z') == 'Z');
}

static void test_stdio(void)
{
  assert(glibme::puts("placeholder") == 0);
  assert(glibme::putchar('x') == 'x');
}

int main(void)
{
  test_strings();
  test_memory();
  test_ctype();
  test_stdio();
  return 0;
}
