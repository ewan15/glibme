#include "glibme.hpp"

namespace glibme {

bool isalpha(int c)
{
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isdigit(int c)
{
  return c >= '0' && c <= '9';
}

bool isalnum(int c)
{
  return isalpha(c) || isdigit(c);
}

bool isspace(int c)
{
  return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' ||
         c == '\v';
}

bool isxdigit(int c)
{
  return isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

int tolower(int c)
{
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  }

  return c;
}

int toupper(int c)
{
  if (c >= 'a' && c <= 'z') {
    return c - ('a' - 'A');
  }

  return c;
}

} // namespace glibme
