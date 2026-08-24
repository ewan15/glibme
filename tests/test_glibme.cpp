#include "glibme.hpp"

#include <assert.h>
#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
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

TEST(test_strlen)
{
  const char embedded_null[] = {'a', 'b', '\0', 'c', '\0'};

  assert(glibme::strlen("") == 0);
  assert(glibme::strlen("hello") == 5);
  assert(glibme::strlen(embedded_null) == 2);
}

TEST(test_strnlen)
{
  const char embedded_null[] = {'a', 'b', '\0', 'c', '\0'};

  assert(glibme::strnlen("", 5) == 0);
  assert(glibme::strnlen("hello", 0) == 0);
  assert(glibme::strnlen("hello", 3) == 3);
  assert(glibme::strnlen("hello", 10) == 5);
  assert(glibme::strnlen(embedded_null, 5) == 2);
}

TEST(test_string_compare)
{
  assert(glibme::strcmp("", "") == 0);
  assert(glibme::strcmp("abc", "abc") == 0);
  assert(glibme::strcmp("abc", "abd") < 0);
  assert(glibme::strcmp("abd", "abc") > 0);
  assert(glibme::strcmp("abc", "abcd") < 0);
  assert(glibme::strcmp("abcd", "abc") > 0);

  assert(glibme::strncmp("abc", "abd", 2) == 0);
  assert(glibme::strncmp("abc", "abd", 3) < 0);
  assert(glibme::strncmp("abc", "xyz", 0) == 0);
  assert(glibme::strncmp("abc", "abcd", 4) < 0);
}

TEST(test_string_case_compare)
{
  assert(glibme::strcasecmp("Hello", "hello") == 0);
  assert(glibme::strcasecmp("abc", "ABD") < 0);
  assert(glibme::strcasecmp("ABD", "abc") > 0);
  assert(glibme::strcasecmp("abc", "ABCD") < 0);

  assert(glibme::strncasecmp("Hello", "heLLo", 5) == 0);
  assert(glibme::strncasecmp("Hello", "heLLo!", 5) == 0);
  assert(glibme::strncasecmp("abc", "ABD", 3) < 0);
  assert(glibme::strncasecmp("abc", "xyz", 0) == 0);
}

TEST(test_string_copy)
{
  char strcpy_dest[8] = {};
  assert(glibme::strcpy(strcpy_dest, "hello!") == strcpy_dest);
  assert(std::strcmp(strcpy_dest, "hello!") == 0);

  char strncpy_short[8] = {};
  assert(glibme::strncpy(strncpy_short, "hello", 3) == strncpy_short);
  assert(strncpy_short[0] == 'h');
  assert(strncpy_short[1] == 'e');
  assert(strncpy_short[2] == 'l');
  assert(strncpy_short[3] == '\0');

  char strncpy_padded[8] = {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'};
  assert(glibme::strncpy(strncpy_padded, "hi", 5) == strncpy_padded);
  assert(strncpy_padded[0] == 'h');
  assert(strncpy_padded[1] == 'i');
  assert(strncpy_padded[2] == '\0');
  assert(strncpy_padded[3] == '\0');
  assert(strncpy_padded[4] == '\0');
  assert(strncpy_padded[5] == 'x');

  char unchanged[] = {'x'};
  assert(glibme::strncpy(unchanged, "hi", 0) == unchanged);
  assert(unchanged[0] == 'x');
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
  assert(glibme::isalpha('a'));
  assert(glibme::isalpha('Z'));
  assert(!glibme::isalpha('0'));
  assert(!glibme::isalpha('_'));

  assert(glibme::isdigit('0'));
  assert(glibme::isdigit('9'));
  assert(!glibme::isdigit('/'));
  assert(!glibme::isdigit(':'));
  assert(!glibme::isdigit('a'));

  assert(glibme::isalnum('a'));
  assert(glibme::isalnum('Z'));
  assert(glibme::isalnum('0'));
  assert(!glibme::isalnum('_'));

  assert(glibme::isspace(' '));
  assert(glibme::isspace('\f'));
  assert(glibme::isspace('\n'));
  assert(glibme::isspace('\r'));
  assert(glibme::isspace('\t'));
  assert(glibme::isspace('\v'));
  assert(!glibme::isspace('a'));

  assert(glibme::isxdigit('0'));
  assert(glibme::isxdigit('9'));
  assert(glibme::isxdigit('a'));
  assert(glibme::isxdigit('f'));
  assert(glibme::isxdigit('A'));
  assert(glibme::isxdigit('F'));
  assert(!glibme::isxdigit('g'));
  assert(!glibme::isxdigit('G'));

  assert(glibme::isprint(' '));
  assert(glibme::isprint('~'));
  assert(glibme::isprint('A'));
  assert(!glibme::isprint('\n'));
  assert(!glibme::isprint(0x7f));

  assert(glibme::tolower('A') == 'a');
  assert(glibme::tolower('Z') == 'z');
  assert(glibme::tolower('a') == 'a');
  assert(glibme::tolower('0') == '0');

  assert(glibme::toupper('a') == 'A');
  assert(glibme::toupper('z') == 'Z');
  assert(glibme::toupper('Z') == 'Z');
  assert(glibme::toupper('0') == '0');
}

TEST(test_stdio)
{
  assert(glibme::puts("placeholder") == 0);
  assert(glibme::putchar('x') == 'x');
  assert(glibme::putchar('\n') == '\n');
}

TEST(test_file_stdio)
{
  std::FILE *file = std::tmpfile();
  assert(file != nullptr);

  assert(glibme::fputc('A', file) == 'A');
  assert(glibme::fputs("bc", file) == 0);

  std::rewind(file);
  assert(std::fgetc(file) == 'A');
  assert(std::fgetc(file) == 'b');
  assert(std::fgetc(file) == 'c');
  assert(std::fgetc(file) == EOF);

  std::fclose(file);
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

TEST(test_rand)
{
  glibme::srand(123);
  int first = glibme::rand();
  int second = glibme::rand();

  assert(first >= 0);
  assert(second >= 0);
  assert(first != second);

  glibme::srand(123);
  assert(glibme::rand() == first);
  assert(glibme::rand() == second);
}

TEST(test_div)
{
  glibme::div_t positive = glibme::div(17, 5);
  assert(positive.quot == 3);
  assert(positive.rem == 2);

  glibme::div_t negative = glibme::div(-17, 5);
  assert(negative.quot == -3);
  assert(negative.rem == -2);

  glibme::ldiv_t long_result = glibme::ldiv(17L, -5L);
  assert(long_result.quot == -3L);
  assert(long_result.rem == 2L);

  glibme::lldiv_t long_long_result = glibme::lldiv(-17LL, -5LL);
  assert(long_long_result.quot == 3LL);
  assert(long_long_result.rem == -2LL);
}

TEST(test_abs)
{
  assert(glibme::abs(-5) == 5);
  assert(glibme::abs(0) == 0);
  assert(glibme::abs(5) == 5);

  assert(glibme::labs(-123456789L) == 123456789L);
  assert(glibme::labs(0L) == 0L);
  assert(glibme::labs(123456789L) == 123456789L);

  assert(glibme::llabs(-1234567890123LL) == 1234567890123LL);
  assert(glibme::llabs(0LL) == 0LL);
  assert(glibme::llabs(1234567890123LL) == 1234567890123LL);
}

TEST(test_strerror)
{
  assert(std::strcmp(glibme::strerror(EINVAL), "Invalid argument") == 0);
  assert(std::strcmp(glibme::strerror(ENOENT), "No such file or directory") == 0);
  assert(std::strcmp(glibme::strerror(EACCES), "Permission denied") == 0);
  assert(std::strcmp(glibme::strerror(-1), "Unknown error") == 0);
}

TEST(test_perror)
{
  std::FILE *file = std::tmpfile();
  assert(file != nullptr);

  int saved_stderr = dup(STDERR_FILENO);
  assert(saved_stderr != -1);
  assert(dup2(fileno(file), STDERR_FILENO) != -1);

  errno = ENOENT;
  glibme::perror("open");

  assert(dup2(saved_stderr, STDERR_FILENO) != -1);
  close(saved_stderr);

  char buffer[64] = {};
  std::rewind(file);
  assert(std::fgets(buffer, sizeof(buffer), file) != nullptr);
  assert(std::strcmp(buffer, "open: No such file or directory\n") == 0);

  std::fclose(file);
}

TEST(test_atoi)
{
  assert(glibme::atoi("-13213") == -13213);
  assert(glibme::atoi(" \t\n\r\v\f+42") == 42);
  assert(glibme::atoi("123abc") == 123);
  assert(glibme::atoi("abc") == 0);
}

TEST(test_atol)
{
  assert(glibme::atol("-123456789") == -123456789L);
  assert(glibme::atol(" \t\n\r\v\f+42") == 42L);
  assert(glibme::atol("123abc") == 123L);
  assert(glibme::atol("abc") == 0L);
}

TEST(test_atoll)
{
  assert(glibme::atoll("-1234567890123") == -1234567890123LL);
  assert(glibme::atoll(" \t\n\r\v\f+42") == 42LL);
  assert(glibme::atoll("123abc") == 123LL);
  assert(glibme::atoll("abc") == 0LL);
}

// TEST(test_strcpy)
//{
//   const char *src = "hello!";
//   char dest[8];
//   glibme::strcpy(dest, src);
//   assert(dest[0] == 'h');
//   assert(dest[1] == 'e');
//   assert(dest[2] == 'l');
//   assert(dest[3] == 'l');
//   assert(dest[4] == 'o');
//   assert(dest[5] == '!');
//   assert(dest[6] == '\0');
// }

int main(void)
{
  for (const TestCase &test : tests()) {
    test.fn();
  }

  return 0;
}
