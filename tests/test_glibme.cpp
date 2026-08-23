#include "glibme.hpp"

#include <assert.h>
#include <cstddef>

static void test_strings(void)
{
  char buffer[1] = {};

  assert(glibme::strcpy(buffer, "") == buffer);
  assert(glibme::strncpy(buffer, "", 0) == buffer);
  assert(glibme::strcat(buffer, "") == buffer);
  assert(glibme::strncat(buffer, "", 0) == buffer);
}

static void test_memory(void)
{
  unsigned char buffer[1] = {};
  unsigned char src[] = {1, 2, 3};
  unsigned char dest[] = {0, 0, 0};

  assert(glibme::memset(buffer, 0, 0) == buffer);
  assert(glibme::memcpy(buffer, buffer, 0) == buffer);
  assert(glibme::memcpy(dest, src, 3) == dest);
  assert(dest[0] == 1);
  assert(dest[1] == 2);
  assert(dest[2] == 3);
  assert(glibme::memmove(buffer, buffer, 0) == buffer);
  assert(glibme::memchr(buffer, 0, 0) == nullptr);
}

static void test_memmove1(void)
{
  unsigned char src_dest[] = {1, 2, 3, 4, 5};
  unsigned char *src = &src_dest[0];
  unsigned char *dst = &src_dest[2];

  glibme::memmove(dst, src, 3);

  assert(src_dest[2] == 1);
  assert(src_dest[3] == 2);
  assert(src_dest[4] == 3);
}

static void test_memmove2(void)
{
  unsigned char src_dest[] = {1, 2, 3, 4, 5};
  unsigned char *src = &src_dest[2];
  unsigned char *dst = &src_dest[0];

  glibme::memmove(dst, src, 3);

  assert(src_dest[0] == 3);
  assert(src_dest[1] == 4);
  assert(src_dest[2] == 5);
}

static void test_ctype(void)
{
  assert(!glibme::isalpha('a'));
  assert(!glibme::isdigit('9'));
  assert(!glibme::isalnum('q'));
  assert(!glibme::isspace('\n'));
  assert(!glibme::isxdigit('f'));
  assert(glibme::tolower('A') == 'A');
  assert(glibme::toupper('z') == 'z');
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
  test_memmove1();
  test_memmove2();
  return 0;
}
