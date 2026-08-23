#include "glibme.hpp"

#include <assert.h>
#include <cstddef>
#include <iostream>
#include <vector>

using TestFn = void (*)();

struct TestCase {
  const char *name;
  TestFn fn;
};

static std::vector<TestCase> &tests()
{
  static std::vector<TestCase> all_tests;
  return all_tests;
}

struct TestRegister {
  TestRegister(const char *name, TestFn fn)
  {
    tests().push_back({name, fn});
  }
};

#define TEST(name)                                                                                 \
  static void name();                                                                              \
  static TestRegister name##_register(#name, name);                                                \
  static void name()

TEST(test_strings)
{
  char buffer[1] = {};

  assert(glibme::strcpy(buffer, "") == buffer);
  assert(glibme::strncpy(buffer, "", 0) == buffer);
  assert(glibme::strcat(buffer, "") == buffer);
  assert(glibme::strncat(buffer, "", 0) == buffer);
}

TEST(test_memory)
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

TEST(test_memmove1)
{
  unsigned char src_dest[] = {1, 2, 3, 4, 5};
  unsigned char *src = &src_dest[0];
  unsigned char *dst = &src_dest[2];

  glibme::memmove(dst, src, 3);

  assert(src_dest[2] == 1);
  assert(src_dest[3] == 2);
  assert(src_dest[4] == 3);
}

TEST(test_memmove2)
{
  unsigned char src_dest[] = {1, 2, 3, 4, 5};
  unsigned char *src = &src_dest[2];
  unsigned char *dst = &src_dest[0];

  glibme::memmove(dst, src, 3);

  assert(src_dest[0] == 3);
  assert(src_dest[1] == 4);
  assert(src_dest[2] == 5);
}

TEST(test_ctype)
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

TEST(test_stdio)
{
  assert(glibme::puts("placeholder\n") == 0);
  assert(glibme::putchar('x') == 'x');
  assert(glibme::putchar('\n') == '\n');
}

TEST(test_memchr)
{
  unsigned char src[] = {1, 2, 3, 4, 5, 6};
  int target = 5;
  void *res = glibme::memchr(src, target, 6);
  assert(res == src + 4);
  assert(glibme::memchr(src, 9, 6) == nullptr);
  assert(glibme::memchr(src, 1, 0) == nullptr);
  std::cout << "memchr passed!" << std::endl;
}

TEST(test_memset)
{
  unsigned char src[] = {1, 2, 3, 4, 5, 6};
  void *res = glibme::memset(src, 0, 6);
  for (std::size_t i = 0; i < 6; ++i) {
    assert(src[i] == 0);
  }
  std::cout << "memset passed!" << std::endl;
}

int main(void)
{
  for (const TestCase &test : tests()) {
    test.fn();
  }

  return 0;
}
