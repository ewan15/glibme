#include "glibme.h"

#include <assert.h>
#include <stddef.h>

static void test_strings(void)
{
  char buffer[32];
  char padded[8];

  assert(glibme_strlen("glibme") == 6);
  assert(glibme_strnlen("glibme", 3) == 3);
  assert(glibme_strnlen("glibme", 10) == 6);

  assert(glibme_strcmp("abc", "abc") == 0);
  assert(glibme_strcmp("abc", "abd") < 0);
  assert(glibme_strncmp("abcdef", "abcxyz", 3) == 0);
  assert(glibme_strncmp("abcdef", "abcxyz", 4) < 0);

  assert(glibme_strcpy(buffer, "glib") == buffer);
  assert(glibme_strcmp(buffer, "glib") == 0);

  assert(glibme_strcat(buffer, "me") == buffer);
  assert(glibme_strcmp(buffer, "glibme") == 0);

  assert(glibme_strncpy(padded, "hi", sizeof(padded)) == padded);
  assert(padded[0] == 'h');
  assert(padded[1] == 'i');
  assert(padded[2] == '\0');

  buffer[0] = '\0';
  assert(glibme_strncat(buffer, "abcdef", 3) == buffer);
  assert(glibme_strcmp(buffer, "abc") == 0);
}

static void test_memory(void)
{
  unsigned char buffer[8];
  unsigned char copy[8];

  assert(glibme_memset(buffer, 0xab, sizeof(buffer)) == buffer);
  assert(buffer[0] == 0xab);
  assert(buffer[7] == 0xab);

  assert(glibme_memcpy(copy, buffer, sizeof(buffer)) == copy);
  assert(glibme_memcmp(copy, buffer, sizeof(buffer)) == 0);

  copy[3] = 0xcd;
  assert(glibme_memchr(copy, 0xcd, sizeof(copy)) == copy + 3);
  assert(glibme_memchr(copy, 0xef, sizeof(copy)) == 0);
  assert(glibme_memcmp(copy, buffer, sizeof(buffer)) > 0);
}

static void test_ctype(void)
{
  assert(glibme_isalpha('a'));
  assert(glibme_isalpha('Z'));
  assert(!glibme_isalpha('4'));

  assert(glibme_isdigit('9'));
  assert(!glibme_isdigit('x'));

  assert(glibme_isalnum('q'));
  assert(glibme_isalnum('7'));
  assert(!glibme_isalnum('_'));

  assert(glibme_isspace('\n'));
  assert(glibme_isspace(' '));
  assert(!glibme_isspace('a'));

  assert(glibme_isxdigit('f'));
  assert(glibme_isxdigit('F'));
  assert(!glibme_isxdigit('g'));

  assert(glibme_tolower('A') == 'a');
  assert(glibme_tolower('a') == 'a');
  assert(glibme_toupper('z') == 'Z');
  assert(glibme_toupper('Z') == 'Z');
}

int main(void)
{
  test_strings();
  test_memory();
  test_ctype();
  return 0;
}
