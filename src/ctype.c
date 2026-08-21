#include "glibme.h"

int glibme_isalpha(int c)
{
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int glibme_isdigit(int c)
{
  return c >= '0' && c <= '9';
}

int glibme_isalnum(int c)
{
  return glibme_isalpha(c) || glibme_isdigit(c);
}

int glibme_isspace(int c)
{
  return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' ||
         c == '\v';
}

int glibme_isxdigit(int c)
{
  return glibme_isdigit(c) || (c >= 'A' && c <= 'F') ||
         (c >= 'a' && c <= 'f');
}

int glibme_tolower(int c)
{
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  }

  return c;
}

int glibme_toupper(int c)
{
  if (c >= 'a' && c <= 'z') {
    return c - ('a' - 'A');
  }

  return c;
}
